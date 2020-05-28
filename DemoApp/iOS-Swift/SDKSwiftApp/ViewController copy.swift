//
//  ViewController.swift
//  SDKSwiftApp
//
//  Created by Gaurav on 28/11/17.
//  Copyright © 2017 Gaurav. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITextFieldDelegate {
    var client : CISClientProtocol!
    var psmVideoInstance : CISPlayerStateManagerProtocol!
    var psmAdInstance : CISPlayerStateManagerProtocol!
    var videoSessionID : Int32!
    var adSessionID : Int32!
    var xyzVideoPlayerInterface : XYZPlayerInterface!
    var xyzAdPlayerInterface : XYZPlayerInterface!
    var xyzVideoPlayer : XYZPlayer!
    var xyzAdPlayer: XYZPlayer!
    var contentMetaData: CISContentMetadata!
    var adMetaData: CISContentMetadata!

    @IBOutlet weak var adSegment: UISegmentedControl!
    @IBOutlet weak var customerKeyTF: UITextField!
    
    var adPlayingBeforeBackground : Bool = false
    
    var adTimer: Timer?
    var isRecreateAdSession = false
    var backgroundUpdateTask = UIBackgroundTaskIdentifier()

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        videoSessionID = NO_SESSION_KEY
        adSessionID = NO_SESSION_KEY
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func createSessionClicked (_ sender: Any){
        adSessionTasks(false)
    }

    func adSessionTasks(_ adPlayingBeforeBG: Bool)  {
        if(client != nil){
            createVideoSession()
            endBackgroundTask()
            registerBackgroundTask()
            registerBackGroundForeGroundHandler()
            
            switch (adSegment.selectedSegmentIndex) {
            case 0:
                // PREROLL;
                adStarted()
                let keys = ["g test key 1", "g test key 2", "g test key 3"]
                let values = ["test value1", "test value2", "test value3"]
                let attributes : NSDictionary = [keys : values]
                client.sendCustomEvent(videoSessionID, eventname: "Sample Event Video", withAttributes: attributes as Any as! [AnyHashable : Any])
                
                // Create Ad session
                createAdSession()
                let key = ["AdDuration"]
                let value = ["60"]
                let attribute : NSDictionary = [key : value]
                client.sendCustomEvent(adSessionID, eventname: "Sample Event Ad", withAttributes: attribute as Any as! [AnyHashable : Any])
                
                attachAdPlayer()
                setAdStates()
                
                // Create timer to be fired for preroll done
                //let prerollDone : Selector = NSSelectorFromString("preRollDone")
                
                createTimer(#selector(ViewController.preRollDone),15)
                break
                
            case 1:
                
                // MIDROLL
                
                if (adPlayingBeforeBG){
                    midrollStarted()
                }else{
                    attachVideoPlayer()
                    setVideoStates()
                    // Create timer to be fired for midroll start
                    //let midrollStarted : Selector = NSSelectorFromString("midrollStarted")
                    createTimer(#selector(ViewController.midrollStarted),15)
                }
                
                break
                
            case 2:
                
                // POSTROLL
                
                if (adPlayingBeforeBG){
                    postrollStarted()
                }else{
                attachVideoPlayer()
                setVideoStates()
                // Create timer to be fired for postroll start
                //let postrollStarted : Selector = NSSelectorFromString("postrollStarted")
                createTimer(#selector(ViewController.postrollStarted),40)
                }
                break
                
            case 3:
                // NOROLL;
                attachVideoPlayer()
                setVideoStates()
                break
                
            default:
                print("default")
            }
        }
    }
    
    @IBAction func sendEventClicked() {
    
    if (client != nil){
    
    if(videoSessionID != NO_SESSION_KEY) {
     client.sendCustomEvent(videoSessionID, eventname: "Sample Event Video 1", withAttributes: ["Duration" : "10"])
    }
    
    if(self.adSessionID != NO_SESSION_KEY) {
        client.sendCustomEvent(videoSessionID, eventname: "Sample Event Ad 1", withAttributes: ["Ad-Duration" : "20"])
        }
      }
    }
    
  @objc func midrollStarted(){
    // Create Timer for midroll done
    print("midrollStarted")
    cancelAdTimer()
    adStarted()
    detachVideoPlayer()
    createAdSession()
    attachAdPlayer()
    setAdStates()
    //let midrollDone : Selector = NSSelectorFromString("midrollDone")
    createTimer(#selector(ViewController.midrollDone),20)
    }
    
  @objc  func midrollDone (){
        cancelAdTimer()
        cleanupAd()
        adEnded()
        attachVideoPlayer()
        setVideoStates()
    }
    
  @objc func preRollDone(){
        cancelAdTimer()
        cleanupAd()
        adEnded()
        attachVideoPlayer()
        setVideoStates()
    }
    
  @objc func postrollStarted(){
        // Create Timer for postRoll done
        cancelAdTimer()
        detachVideoPlayer()
        adStarted()
        createAdSession()
        attachAdPlayer()
        setAdStates()
        //let postrollDone : Selector = NSSelectorFromString("postrollDone")
        createTimer(#selector(ViewController.postrollDone),20)
    }
    
  @objc  func postrollDone(){
        cancelAdTimer()
        adEnded()
        cleanupAd()
        cleanupSessionClicked((Any).self)
    }
    
    func setAdStates()  {
        if(xyzAdPlayerInterface != nil){
            xyzAdPlayerInterface.report(.CONVIVA_BUFFERING)
            xyzAdPlayerInterface.report(.CONVIVA_PLAYING)
            xyzAdPlayerInterface.reportPlayerBitrate(200)
        }
    }
    
    func  setVideoStates()  {
        if(xyzVideoPlayerInterface != nil){
            xyzVideoPlayerInterface.report(.CONVIVA_BUFFERING)
            xyzVideoPlayerInterface.report(.CONVIVA_PLAYING)
            xyzVideoPlayerInterface.reportPlayerBitrate(100)
        }
    }
    
    func createTimer(_ selector : Selector , _ ti : TimeInterval)  {
        cancelAdTimer()
        adTimer =  Timer.scheduledTimer(timeInterval:ti, target: self, selector:selector, userInfo: nil, repeats: false)
    }
    
    func registerBackGroundForeGroundHandler()  {
        NotificationCenter.default.addObserver(self,
                                               selector:#selector(appStateChangeHandler(_:)),
                                               name:NSNotification.Name.UIApplicationWillEnterForeground,
                                               object: nil)
        NotificationCenter.default.addObserver(self,
                                               selector:#selector(appStateChangeHandler(_:)),
                                               name:NSNotification.Name.UIApplicationDidEnterBackground,
                                               object: nil)
    }
    
    @objc func appStateChangeHandler(_ notification : NSNotification)  {
        if(notification.name == NSNotification.Name.UIApplicationDidEnterBackground){
            if(adSessionID != NO_SESSION_KEY){
                adPlayingBeforeBackground = true
                cleanupAd()
                cancelAdTimer()
            }
            if(videoSessionID != NO_SESSION_KEY){
                cleanupSessionClicked((Any).self)
            }
        }else{
 
            adSessionTasks(adPlayingBeforeBackground)
            adPlayingBeforeBackground = false
            
        }
    }
    
    func cancelAdTimer()  {
        if(adTimer != nil){
            adTimer?.invalidate()
            adTimer = nil
        }
        
    }
    
    @IBAction func reportErrorClicked(_ sender: Any) {
        if (client != nil && videoSessionID != NO_SESSION_KEY){
            client.reportError(videoSessionID, errorMessage: "Video start error", errorSeverity: .ERROR_FATAL)
        }
    }
    
    @IBAction func initSDKClicked(_ sender: Any) {
        let systemInterFactory : CISSystemInterfaceProtocol = IOSSystemInterfaceFactory.initializeWithSystemInterface()
        let setting = CISSystemSettings.init()
        setting.logLevel = .LOGLEVEL_NONE
        let factory : CISSystemFactoryProtocol = CISSystemFactoryCreator.create(withCISSystemInterface: systemInterFactory, setting: setting)
        
        let settingError : Error? = nil
        let clientError : Error? = nil
        
        
        var clientSetting : CISClientSettingProtocol
        do {
            clientSetting = try CISClientSettingCreator.create(withCustomerKey: "CUSTOMER_KEY")
            clientSetting.setGatewayUrl("TOUCHSTONE_URL")
            
            do {
                client = try CISClientCreator.create(withClientSettings: clientSetting, factory: factory)
            }
                
            catch {
                print(clientError!)
            }
        }
            
        catch {
            print(settingError!)
        }
        
        if (clientError != nil) {
            print("[SAMPLE APP] [clientError] [ \(clientError!) ]")
        }
        else if (settingError != nil){
            NSLog("[SAMPLE APP] [settingError] [ \(settingError!) ]")
        }
        else{
            print("[SAMPLE APP] [SUCCESS] [INIT SUCCESS]")
        }
    }
    
    @IBAction func cleanupSDKClicked(_ sender: Any) {
        cleanupSessionClicked(self)
        if (client != nil){
            client.cleanUp()
            client = nil
        }
        adSessionID = NO_SESSION_KEY
        videoSessionID = NO_SESSION_KEY
        
        NotificationCenter.default.removeObserver(self)
    }
    
    public func textFieldShouldReturn(_ textField: UITextField) -> Bool{
        textField.resignFirstResponder()
        return true
    }
    
    @IBAction func adStarted() {
        if (videoSessionID != NO_SESSION_KEY && client != nil){
            var adPos : AdPosition!
            
            switch (adSegment.selectedSegmentIndex) {
            case 0:
                adPos = .ADPOSITION_PREROLL
                break
                
            case 1:
                adPos = .ADPOSITION_MIDROLL
                break
                
            case 2:
                adPos = .ADPOSITION_POSTROLL
                break
            default:
                print("default")
            }
            
            if (adSegment.selectedSegmentIndex != 3){
                client.adStart(videoSessionID, adStream: .ADSTREAM_SEPARATE, adPlayer: .ADPLAYER_SEPARATE, adPosition: adPos)
            }
        }
    }
    
    @IBAction func adEnded() {
        if (videoSessionID != NO_SESSION_KEY && client != nil){
            client.adEnd(videoSessionID)
        }
        
    }
    
    @IBAction func updateMetaDataClicked(_ sender: Any) {
        contentMetaData.defaultResource = "LEVEL3";
        contentMetaData.streamType = .CONVIVA_STREAM_LIVE;
        contentMetaData.applicationName = "New playerName";
        contentMetaData.viewerId = "Supplied new viewer ID";
        contentMetaData.duration = 100; //in seconds
        contentMetaData.encodedFramerate = 60; //in fps
        contentMetaData.streamUrl = "http://newstreamurl.conviva.com/";
        contentMetaData.custom["tag1"] = "new_value1"
        contentMetaData.custom["tag2"] = "new_value2"
        
        if (videoSessionID != NO_SESSION_KEY && client != nil){
            client.updateContentMetadata(videoSessionID, metadata: contentMetaData)
        }
        contentMetaData = nil
    }


// MAIN CONTENT VIDEO METHODS
    
    func createVideoSession() {
        if (client != nil ){
            videoSessionID = client.createSession(with: createVideoMetadataObject())
            print(videoSessionID)
        }
    }

    @IBAction func cleanupSessionClicked(_ sender: Any){
    
        if(videoSessionID != NO_SESSION_KEY){
            
            client.cleanupSession(videoSessionID)
            
            videoSessionID = NO_SESSION_KEY
            
            if(xyzVideoPlayerInterface != nil){
                
            xyzVideoPlayerInterface.cleanupXYZPLayerInterface()
            
            xyzVideoPlayerInterface = nil
            }
            
            cleanupVideoPsm()
            
            if(xyzVideoPlayer != nil){
                xyzVideoPlayer.stop()
                
                xyzVideoPlayer = nil
            }
            
        }
        
        cleanupAd()
        
    }
    
    
    func attachVideoPlayer() {
        if (client != nil){
            // CREATE PLAYER INSTANCE HERE OR BEFORE
            if (xyzVideoPlayer == nil){
                xyzVideoPlayer = XYZPlayer.init(videoUrl: "SAMPLE_VIDEO_URL")
            }
            
            if (psmVideoInstance == nil){
                psmVideoInstance = client.getPlayerStateManager()
            }
            
            // IF XYZPROXY IS NIL CREATE NEW
            // PASS PLAYER INSTANCE HERE TO XYZPROXY
            // ASSIGN PSM ICLIENT TO XYZ PROXY HERE
            if (xyzVideoPlayerInterface == nil){
                xyzVideoPlayerInterface = XYZPlayerInterface.init(playerStateManager: psmVideoInstance, xyzPlayer: xyzVideoPlayer)
            }
            
            psmVideoInstance.setCISIClientMeasureInterface!(xyzVideoPlayerInterface)
            
            if (psmVideoInstance != nil && videoSessionID != NO_SESSION_KEY){
                client.attachPlayer(videoSessionID, playerStateManager: psmVideoInstance)
            }
        }
    }
    
    func detachVideoPlayer()  {
        if videoSessionID != NO_SESSION_KEY {
            client.detachPlayer(videoSessionID)
        }
    }
    
    func createVideoMetadataObject() -> CISContentMetadata {
        contentMetaData = CISContentMetadata()
        contentMetaData.assetName = "iOS_SDK_INTEGRATION_SWIFT"
        contentMetaData.applicationName = "Conviva_Orange_Player"
        contentMetaData.custom["tag1"] = "value1"
        contentMetaData.custom["tag2"] = "value2"
        contentMetaData.viewerId = "Conviva-QE"
        contentMetaData.defaultResource = "LEVEL3"
        contentMetaData.streamType = .CONVIVA_STREAM_VOD
        contentMetaData.streamUrl = "SAMPLE_URL"
        return contentMetaData
    }
    
    func cleanupVideoPsm() {
        if (psmVideoInstance != nil) {
            client.releasePlayerStateManager(psmVideoInstance)
            psmVideoInstance = nil
        }
    }
    
 // AD METHODS
    
    func createAdSession() {
        if (client != nil ){
            adSessionID = client.createAdSession(videoSessionID, adMetadata: createAdMetadataObject())
            print(adSessionID)
        }
    }
    
    func cleanupAd(){
        if(adSessionID != NO_SESSION_KEY){
            
            client.cleanupSession(adSessionID)
            
            adSessionID = NO_SESSION_KEY
            
            if(xyzAdPlayerInterface != nil){
            xyzAdPlayerInterface.cleanupXYZPLayerInterface()
            
            xyzAdPlayerInterface = nil
            }
            
            cleanupAdPsm()
            
            if(xyzAdPlayer != nil){
            xyzAdPlayer.stop()
            
            xyzAdPlayer = nil
                
            }
        }
    }
    
    func attachAdPlayer() {
        if (client != nil){
            // CREATE PLAYER INSTANCE HERE OR BEFORE
            if (xyzAdPlayer == nil){
                xyzAdPlayer = XYZPlayer.init(videoUrl: "SAMPLE_VIDEO_URL")
            }
            
            if (psmAdInstance == nil){
                psmAdInstance = client.getPlayerStateManager()
            }
            
            // IF XYZPROXY IS NIL CREATE NEW
            // PASS PLAYER INSTANCE HERE TO XYZPROXY
            // ASSIGN PSM ICLIENT TO XYZ PROXY HERE
            if (xyzAdPlayerInterface == nil){
                xyzAdPlayerInterface = XYZPlayerInterface.init(playerStateManager: psmAdInstance, xyzPlayer: xyzAdPlayer)
            }
            
            psmAdInstance.setCISIClientMeasureInterface!(xyzAdPlayerInterface)
            
            if (psmAdInstance != nil && adSessionID != NO_SESSION_KEY){
                client.attachPlayer(adSessionID, playerStateManager: psmAdInstance)
            }
        }
    }

    func detachAdPlayer() {
        if adSessionID != NO_SESSION_KEY {
            client.detachPlayer(adSessionID)
        }
    }
    
   func createAdMetadataObject ()-> CISContentMetadata{
        adMetaData = CISContentMetadata()
        adMetaData.assetName = "iOS_AD_SDK_ADS_INTEGRATION"
        adMetaData.custom["tag1"] = "value1"
        adMetaData.custom["tag2"] = "value2"
        adMetaData.defaultResource = "LEVEL3"
        adMetaData.streamType = .CONVIVA_STREAM_VOD
        adMetaData.streamUrl = "SAMPLE_AD_URL"
        return adMetaData
    }
    
    func cleanupAdPsm() {
        if (psmAdInstance != nil) {
            client.releasePlayerStateManager(psmAdInstance)
            psmAdInstance = nil
        }
    }
    
    func registerBackgroundTask()  {
        backgroundUpdateTask = UIApplication.shared.beginBackgroundTask(expirationHandler: {
            
        })
    }
    
    func endBackgroundTask()   {
        UIApplication.shared.endBackgroundTask(backgroundUpdateTask)
        backgroundUpdateTask = UIBackgroundTaskInvalid
    }
}

