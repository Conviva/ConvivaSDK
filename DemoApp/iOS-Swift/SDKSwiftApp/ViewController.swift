//
//  ViewController.swift
//  SDKSwiftApp
//
//  Created by Gaurav on 28/11/17.
//  Copyright © 2017 Gaurav. All rights reserved.
//

import UIKit
import ConvivaSDK

class ViewController: UIViewController, UITextFieldDelegate {
    
    var analytics:CISAnalytics?
    var videoAnalytics:CISVideoAnalytics?
    var adAnalytics:CISAdAnalytics?
   
    var xyzVideoPlayer : XYZPlayer!
    var xyzAdPlayer: XYZPlayer!
    
    @IBOutlet weak var adSegment: UISegmentedControl!
    @IBOutlet weak var customerKeyTF: UITextField!
    
    var adPlayingBeforeBackground : Bool = false
    
    var adTimer: Timer?
    
    var backgroundUpdateTask = UIBackgroundTaskIdentifier()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func createSessionClicked (_ sender: Any){
        adSessionTasks(false)
    }
    
    func adSessionTasks(_ adPlayingBeforeBG: Bool)  {
        if let _ = self.analytics {
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
                
                self.videoAnalytics?.reportPlaybackEvent("Sample Event Video", withAttributes: attributes as Any as? [AnyHashable : Any])
                
                // Create Ad session
                createAdSession()
                let key = ["AdDuration"]
                let value = ["60"]
                let attribute : NSDictionary = [key : value]
                
                
                self.adAnalytics?.reportAdPlayerEvent("Sample Event Video", details: attribute as Any as? [AnyHashable : Any])
                
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
        
        self.videoAnalytics?.reportPlaybackEvent("Sample Event Video", withAttributes: ["Duration" : "10"])
        self.adAnalytics?.reportAdPlayerEvent("Sample Event Video", details: ["Ad-Duration" : "20"])
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
    
        self.adAnalytics?.reportAdMetric(CIS_SSDK_PLAYBACK_METRIC_PLAYER_STATE, value: NSNumber(integerLiteral: Int(PlayerState.CONVIVA_BUFFERING.rawValue)));
        
        self.adAnalytics?.reportAdMetric(CIS_SSDK_PLAYBACK_METRIC_PLAYER_STATE, value: NSNumber(integerLiteral: Int(PlayerState.CONVIVA_PLAYING.rawValue)));
        
        self.adAnalytics?.reportAdMetric(CIS_SSDK_PLAYBACK_METRIC_BITRATE, value: NSNumber(integerLiteral: 200));

    }
    
    func  setVideoStates()  {
        
        self.videoAnalytics?.reportPlaybackMetric(CIS_SSDK_PLAYBACK_METRIC_PLAYER_STATE, value: NSNumber(integerLiteral: Int(PlayerState.CONVIVA_BUFFERING.rawValue)));
        
        self.videoAnalytics?.reportPlaybackMetric(CIS_SSDK_PLAYBACK_METRIC_PLAYER_STATE, value: NSNumber(integerLiteral: Int(PlayerState.CONVIVA_PLAYING.rawValue)));
        
        self.videoAnalytics?.reportPlaybackMetric(CIS_SSDK_PLAYBACK_METRIC_BITRATE, value: NSNumber(integerLiteral: 100));
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
            self.analytics?.reportAppBackgrounded();
        }else{
            
            adSessionTasks(adPlayingBeforeBackground)
            adPlayingBeforeBackground = false
            
            self.analytics?.reportAppForegrounded();
            
        }
    }
    
    func cancelAdTimer()  {
        if(adTimer != nil){
            adTimer?.invalidate()
            adTimer = nil
        }
        
    }
    
    @IBAction func reportErrorClicked(_ sender: Any) {

        if let _ = self.videoAnalytics {
            self.videoAnalytics?.reportPlaybackError("Video start error", errorSeverity: .ERROR_FATAL);
        }
    }
    
    @IBAction func initSDKClicked(_ sender: Any) {
        
        let settings = [CIS_SSDK_SETTINGS_GATEWAY_URL:"GATEWAYURL",CIS_SSDK_SETTINGS_LOG_LEVEL:NSNumber(value: LogLevel.LOGLEVEL_WARNING.rawValue)] as [String : Any];

        self.analytics = CISAnalyticsCreator.create(withCustomerKey: "KEY",settings:settings);

    }
    
    @IBAction func cleanupSDKClicked(_ sender: Any) {
        cleanupSessionClicked(self)

        self.analytics?.cleanup();
        self.analytics = nil
        
        NotificationCenter.default.removeObserver(self)
    }
    
    public func textFieldShouldReturn(_ textField: UITextField) -> Bool{
        textField.resignFirstResponder()
        return true
    }
    
    @IBAction func adStarted() {
        if let _ = self.videoAnalytics {
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
                
                var adAttributes = [AnyHashable:Any]();
                adAttributes["podIndex"] = "1";
                adAttributes["podDuration"] = "10";
                adAttributes["podPosition"] = CISConstants.getAdPositionStringValue(adPos);
                
                self.videoAnalytics?.reportAdBreakStarted(.ADPLAYER_SEPARATE, adType: .CLIENT_SIDE, adBreakInfo: adAttributes)
            }
        }
    }
    
    @IBAction func adEnded() {
        
        if nil != videoAnalytics {
            self.videoAnalytics!.reportAdBreakEnded();
        }
    }
    
    func buildContentInfo() ->  [AnyHashable : Any]{
        
        var contentInfo = [AnyHashable : Any]();
        
        contentInfo[CIS_SSDK_METADATA_ASSET_NAME] = "asset";
        contentInfo[CIS_SSDK_METADATA_IS_LIVE] = NSNumber(booleanLiteral: true);
        contentInfo[CIS_SSDK_METADATA_PLAYER_NAME] = "playername";
        contentInfo[CIS_SSDK_METADATA_VIEWER_ID] = "viewerid";
        contentInfo[CIS_SSDK_METADATA_DEFAULT_RESOURCE] = "resource";
        contentInfo[CIS_SSDK_METADATA_DURATION] = NSNumber(integerLiteral: 100);
        contentInfo[CIS_SSDK_METADATA_STREAM_URL] = "http://test.m3u8";
        contentInfo[CIS_SSDK_PLAYER_FRAMEWORK_NAME] = "frameworkname";
        contentInfo[CIS_SSDK_PLAYER_FRAMEWORK_VERSION] = "frameworkversion";
        
        let tags = NSMutableDictionary();
        tags["key1"] = "val1";
        tags["key2"] = "val2";
        contentInfo["tags"] = tags;
    
        return contentInfo;
    }
        
    func buildAdInfo() ->  [AnyHashable : Any] {
        
        var adInfo = [AnyHashable : Any]();
        
        adInfo[CIS_SSDK_METADATA_ASSET_NAME] = "adasset";
        adInfo[CIS_SSDK_METADATA_IS_LIVE] = NSNumber(booleanLiteral: true);
        adInfo[CIS_SSDK_METADATA_PLAYER_NAME] = "adplayername";
        adInfo[CIS_SSDK_METADATA_VIEWER_ID] = "viewerid";
        adInfo[CIS_SSDK_METADATA_DEFAULT_RESOURCE] = "resource";
        adInfo[CIS_SSDK_METADATA_DURATION] = NSNumber(integerLiteral: 100);
        adInfo[CIS_SSDK_METADATA_STREAM_URL] = "http://test.m3u8";
        adInfo[CIS_SSDK_PLAYER_FRAMEWORK_NAME] = "frameworkname";
        adInfo[CIS_SSDK_PLAYER_FRAMEWORK_VERSION] = "frameworkversion";
        
        
        let tags = NSMutableDictionary();
        tags["key1"] = "val1";
        tags["key2"] = "val2";
        adInfo["tags"] = tags;
    
        return adInfo;
    }
    
    @IBAction func updateMetaDataClicked(_ sender: Any) {
        
        var contentInfo = [AnyHashable : Any]();
        
        contentInfo[CIS_SSDK_METADATA_IS_LIVE] = NSNumber(booleanLiteral: false);
        contentInfo[CIS_SSDK_METADATA_PLAYER_NAME] = "playername";
        contentInfo[CIS_SSDK_METADATA_VIEWER_ID] = "viewerid";
        contentInfo[CIS_SSDK_METADATA_DEFAULT_RESOURCE] = "LEVEL3";
        contentInfo[CIS_SSDK_METADATA_DURATION] = NSNumber(integerLiteral: 100);
        contentInfo[CIS_SSDK_METADATA_STREAM_URL] = "http://test.m3u8";
        
        if nil != self.videoAnalytics {
            self.videoAnalytics!.setContentInfo(contentInfo);
        }
    }
    
    
    // MAIN CONTENT VIDEO METHODS
    
    func createVideoSession() {
        
        if nil != self.analytics  {
            self.videoAnalytics = self.analytics?.createVideoAnalytics();
            self.videoAnalytics?.reportPlaybackRequested(self.buildContentInfo())
        }
    }
    
    @IBAction func cleanupSessionClicked(_ sender: Any){
        
        cleanupAd()
        
        if nil != self.videoAnalytics {
            self.videoAnalytics!.reportPlaybackEnded();
            self.videoAnalytics!.cleanup();
            self.videoAnalytics = nil;
        }
    }
    
    
    func attachVideoPlayer() {
        if let _ = self.analytics {
            // CREATE PLAYER INSTANCE HERE OR BEFORE
            if (xyzVideoPlayer == nil){
                xyzVideoPlayer = XYZPlayer.init(videoUrl: "SAMPLE_VIDEO_URL")
            }
            
            let event = CISConstants.getEventsStringValue(.USER_WAIT_ENDED)!;
            self.videoAnalytics?.reportPlaybackEvent(event,withAttributes: nil);
        }
    }
    
    func detachVideoPlayer()  {
        let event = CISConstants.getEventsStringValue(.USER_WAIT_STARTED);
        self.videoAnalytics?.reportPlaybackEvent(event!,withAttributes: nil);
    }

    
    // AD METHODS
    
    func createAdSession() {
        if nil != self.analytics && nil != self.videoAnalytics {
            self.adAnalytics = self.analytics?.createAdAnalytics(withVideoAnalytics: self.videoAnalytics!);
            self.adAnalytics?.reportAdLoaded(self.buildAdInfo());
        }
    }
    
    func cleanupAd(){
        if nil != self.adAnalytics {
            
            self.adAnalytics?.cleanup();
            
            if(xyzAdPlayer != nil){
                xyzAdPlayer.stop()
                
                xyzAdPlayer = nil
                
            }
        }
    }
    
    func attachAdPlayer() {
        
        if let _ = self.analytics {
            // CREATE PLAYER INSTANCE HERE OR BEFORE
            if (xyzAdPlayer == nil){
                xyzAdPlayer = XYZPlayer.init(videoUrl: "SAMPLE_VIDEO_URL")
                self.adAnalytics?.reportAdStarted(self.buildAdInfo())
            }else {
                let event = CISConstants.getEventsStringValue(.USER_WAIT_STARTED)!;
                self.adAnalytics?.reportAdPlayerEvent(event,details: nil);
            }
            
        }
        
    }
    
    func detachAdPlayer() {
        let event = CISConstants.getEventsStringValue(.USER_WAIT_ENDED)!;
        self.adAnalytics?.reportAdPlayerEvent(event,details: nil);
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

