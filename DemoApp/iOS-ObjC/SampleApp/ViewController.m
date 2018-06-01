//
//  ViewController.m
//  SampleTestApp
//
//  Created by Nirvaid Rathore on 10/03/16.
//  Copyright © 2016 Nirvaid Rathore. All rights reserved.
//

#import "ViewController.h"
#import "XYZPlayerInterface.h"
#import "XYZPlayer.h"

@interface ViewController ()

@property(nonatomic,strong)id<CISClientProtocol> client;
@property(nonatomic,strong)id<CISPlayerStateManagerProtocol> psmVideoInstance,psmAdInstance;
@property(nonatomic,assign) int videoSessionID,adSessionID;
@property(nonatomic,strong) XYZPlayerInterface *xyzVideoPlayerInterface,*xyzAdPlayerInterface;
@property(nonatomic,strong)  XYZPlayer *xyzVideoPlayer,*xyzAdPlayer;
@property(nonatomic,strong) NSTimer *adTimer;
@property(atomic) UIBackgroundTaskIdentifier backgroundUpdateTask;
@property(nonatomic,assign) BOOL adPlayingBeforeBackground;
@property(nonatomic,strong) CISContentMetadata *contentMetaData;
@property(nonatomic,strong) CISContentMetadata *adMetaData;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.videoSessionID = NO_SESSION_KEY;
    self.adSessionID = NO_SESSION_KEY;
    self.adPlayingBeforeBackground = FALSE;
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)createSessionClicked:(id)sender {
    [self adSessionTask:false];
}

-(void)adSessionTask:(BOOL)adPlayingBeforeBG{
    if (self.client != nil ){
        [self createVideoSession];
        [self endBackgroundTask];
        [self registerBackgroundTask];
        [self registerBackGroundForeGroundHandler];
        switch (self.adSegment.selectedSegmentIndex) {
            case 0:
                // PREROLL;
                [self adStarted];
                [self.client sendCustomEvent:self.videoSessionID eventname:@"Sample Event Video" withAttributes:@{@"podDuration" : @"60"}];
                
                // Create Ad session
                [self createAdSession];
                
                // Send Event Video Session
                [self.client sendCustomEvent:self.adSessionID eventname:@"Sample Event Ad" withAttributes:@{@"AdDuration" : @"60"}];
                
                // Attach Ad session
                [self attachAdPlayer];
                
                // Send Ad Video Session
                
                [self setAdStates];
                
                // Create timer to be fired for preroll done
                SEL prerollDone = NSSelectorFromString(@"preRollDone");
                [self createTimer:prerollDone ti:30];
                break;
                
            case 1:
                // MIDROLL
                
                if(adPlayingBeforeBG){
                    [self midrollStarted];
                }else{
                    [self attachVideoPlayer];
                    [self setVideoStates];
                    // Create timer to be fired for midroll start
                    SEL midrollStarted = NSSelectorFromString(@"midrollStarted");
                    [self createTimer:midrollStarted ti:15];
                }
                break;
                
            case 2:
                // POSTROLL
                if(adPlayingBeforeBG){
                    [self postrollStarted];
                }else{
                    [self attachVideoPlayer];
                    [self setVideoStates];
                    // Create timer to be fired for postroll start
                    SEL postrollStarted = NSSelectorFromString(@"postrollStarted");
                    [self createTimer:postrollStarted ti:40];
                }
                break;
                
            case 3:
                // NOROLL;
                [self attachVideoPlayer];
                [self setVideoStates];
                break;
                
            default:
                break;
        }
        
    }
}

-(void)midrollStarted{
    // Create Timer for midroll done
    [self cancelAdTimer];
    [self detachVideoPlayer];
    [self adStarted];
    [self createAdSession];
    [self attachAdPlayer];
    [self setAdStates];
    
    SEL midrollDone = NSSelectorFromString(@"midrollDone");
    [self createTimer:midrollDone ti:20];
}

-(void)midrollDone{
    [self cancelAdTimer];
    [self cleanupAd];
    [self adEnded];
    [self attachVideoPlayer];
    [self setVideoStates];
}

-(void)preRollDone{
    [self cancelAdTimer];
    [self cleanupAd];
    [self adEnded];
    [self attachVideoPlayer];
    [self setVideoStates];
}

-(void)postrollStarted{
    // Create Timer for postRoll done
    [self cancelAdTimer];
    [self detachVideoPlayer];
    [self adStarted];
    [self createAdSession];
    [self attachAdPlayer];
    [self setAdStates];
    
    SEL postrollDone = NSSelectorFromString(@"postrollDone");
    [self createTimer:postrollDone ti:20];
}

-(void)postrollDone{
     [self cancelAdTimer];
     [self adEnded];
     [self cleanupAd];
     [self cleanupSessionClicked:nil];
}

-(void)setVideoStates{
    if (self.xyzVideoPlayerInterface){
        [self.xyzVideoPlayerInterface reportPlayerState:CONVIVA_BUFFERING];
        [self.xyzVideoPlayerInterface reportPlayerState:CONVIVA_PLAYING];
        [self.xyzVideoPlayerInterface reportPlayerBitrate:100];
    }
}

-(void)setAdStates{
    if (self.xyzAdPlayerInterface){
        [self.xyzAdPlayerInterface reportPlayerState:CONVIVA_BUFFERING];
        [self.xyzAdPlayerInterface reportPlayerState:CONVIVA_PLAYING];
        [self.xyzAdPlayerInterface reportPlayerBitrate:500];
    }
}


-(void)createTimer:(SEL)selector ti:(NSTimeInterval)ti{
    if(_adTimer){
        [_adTimer invalidate];
        _adTimer = nil;
    }
    
    _adTimer = [NSTimer scheduledTimerWithTimeInterval:ti
                                                target:self
                                              selector:selector
                                              userInfo:nil
                                               repeats:NO];
    
}


-(void)registerBackGroundForeGroundHandler{
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(appStateChangeHandler:)
                                                 name:UIApplicationDidEnterBackgroundNotification
                                               object:[UIApplication sharedApplication]];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(appStateChangeHandler:)
                                                 name:UIApplicationWillEnterForegroundNotification
                                               object:[UIApplication sharedApplication]];
}

- (void)appStateChangeHandler:(NSNotification *)notification {
    
    if (notification.name != nil && [notification.name isEqualToString:UIApplicationDidEnterBackgroundNotification])
    {
        if(self.adSessionID != NO_SESSION_KEY){
            self.adPlayingBeforeBackground = true;
            [self cleanupAd];
            [self cancelAdTimer];
        }
        
        if(self.videoSessionID != NO_SESSION_KEY){
            [self cleanupSessionClicked:nil];
        }
        
    }else{
        // Add check to recreate ad sesion only if Ad playing
        [self adSessionTask:true];
        self.adPlayingBeforeBackground = false;
    }
}

-(void)cancelAdTimer{
    if(_adTimer){
        [_adTimer invalidate];
        _adTimer = nil;
    }
}

- (IBAction)reportErrorClicked:(id)sender {
    
    if (self.client && self.videoSessionID != NO_SESSION_KEY)
        [self.client reportError:self.videoSessionID errorMessage:@"Video start error" errorSeverity:ERROR_FATAL];

}

- (IBAction)initSDKClicked:(id)sender {
  
    id<CISSystemInterfaceProtocol> systemInterFactory = [IOSSystemInterfaceFactory initializeWithSystemInterface];
  
    CISSystemSettings *setting = [[CISSystemSettings alloc] init];
    
    setting.logLevel = LOGLEVEL_NONE;
    
    id<CISSystemFactoryProtocol> factory = [CISSystemFactoryCreator createWithCISSystemInterface:systemInterFactory setting:setting];
    
    NSError *settingError,*clientError;
    
    
    id<CISClientSettingProtocol> clientSetting = [CISClientSettingCreator createWithCustomerKey:@"CUSTOMER_KEY" error:&settingError];
    
    [clientSetting setGatewayUrl:@"TOUCHSTONE_URL"];
    
    self.client = [CISClientCreator createWithClientSettings:clientSetting factory:factory error:&clientError];
    
    if (clientError) {
        NSLog(@"[SAMPLE APP] [clientError] [ %@ ]",clientError);
    }else if (settingError){
        NSLog(@"[SAMPLE APP] [settingError] [ %@ ]",settingError);
    }else{
        NSLog(@"[SAMPLE APP] [SUCCESS] [INIT SUCCESS]");
    }
}

- (IBAction)cleanupSDKClicked:(id)sender {
    
    [self cleanupSessionClicked:nil];
    
    if (self.client) {
        [self.client cleanUp];
        self.client = nil;
    }

    self.videoSessionID = NO_SESSION_KEY;
    self.adSessionID = NO_SESSION_KEY;
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationWillEnterForegroundNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationDidEnterBackgroundNotification object:nil];
}

-(BOOL)textFieldShouldReturn:(UITextField *)textField{
    return YES;
}

- (void)adStarted {
    if (self.videoSessionID != NO_SESSION_KEY && self.client != nil){
        
        AdPosition adPos;
        
        switch (self.adSegment.selectedSegmentIndex) {
            case 0:
                adPos = ADPOSITION_PREROLL;
                break;

            case 1:
                adPos = ADPOSITION_MIDROLL;
                break;

            case 2:
                adPos = ADPOSITION_POSTROLL;
                break;
            default:
                adPos = 0;
                break;
        }
        
        if (self.adSegment.selectedSegmentIndex != 3)
            [self.client adStart:self.videoSessionID adStream:ADSTREAM_SEPARATE adPlayer:ADPLAYER_SEPARATE adPosition:adPos];
    }
}

- (void)adEnded {
    if (self.videoSessionID != NO_SESSION_KEY && self.client != nil){
        [self.client adEnd:self.videoSessionID];
    }
}

- (IBAction)updateMetaDataClicked:(id)sender {
    self.contentMetaData.defaultResource = @"LEVEL3";
    self.contentMetaData.streamType = CONVIVA_STREAM_LIVE;
    self.contentMetaData.applicationName = @"New playerName";
    self.contentMetaData.viewerId = @"Supplied new viewer ID";
    self.contentMetaData.duration = 100; //in seconds
    self.contentMetaData.encodedFramerate = 60; //in fps
    self.contentMetaData.streamUrl = @"http://newstreamurl.conviva.com/";
    self.contentMetaData.custom[@"tag1"] = @"new_value1";
    self.contentMetaData.custom[@"tag2"] = @"new_value2";
    if (self.videoSessionID != NO_SESSION_KEY && self.client != nil){
        [self.client updateContentMetadata:self.videoSessionID metadata:self.contentMetaData];
    }
    self.contentMetaData = nil;
}

- (IBAction)sendEventClicked:(id)sender {
    if (self.client != nil){
       if(self.videoSessionID != NO_SESSION_KEY) {
           [self.client sendCustomEvent:self.videoSessionID eventname:@"Sample Event Video 1" withAttributes:@{@"Duration" : @"10"}];
           // Send Event Video Session
       }
        
        if(self.adSessionID != NO_SESSION_KEY) {
            [self.client sendCustomEvent:self.adSessionID eventname:@"Sample Event Ad 1" withAttributes:@{@"Ad-Duration" : @"20"}];
        }
    }
}

#pragma Video Methods



-(void)createVideoSession{
    self.videoSessionID = [self.client createSessionWithMetadata:[self createVideoMetadataObject]];
    NSLog(@"%d",self.videoSessionID);
}

- (IBAction)cleanupSessionClicked:(id)sender {
    
    if (self.videoSessionID != NO_SESSION_KEY) {
        
        [self.client cleanupSession:self.videoSessionID];
        
        [self cleanupAd];
        
        [self.xyzVideoPlayerInterface cleanupXYZPLayerInterface];
        
        self.xyzVideoPlayerInterface = nil;
        
        [self cleanupVideoPsm];
        
        [self.xyzVideoPlayer stop];
        
        self.xyzVideoPlayer = nil;
        
        self.videoSessionID = NO_SESSION_KEY;
        
    }
}


- (void)attachVideoPlayer{
    if (self.client){
        
        // CREATE PLAYER INSTANCE HERE OR BEFORE
        if (!self.xyzVideoPlayer) {
            self.xyzVideoPlayer = [[XYZPlayer alloc] initWithVideoUrl:@"SAMPLE_VIDEO_URL"];
        }
        
        if (self.psmVideoInstance == nil){
            self.psmVideoInstance = [self.client getPlayerStateManager];
        }
        
        // IF XYZPROXY IS NIL CREATE NEW
        // PASS PLAYER INSTANCE HERE TO XYZPROXY
        // ASSIGN PSM ICLIENT TO XYZ PROXY HERE
        if (!self.xyzVideoPlayerInterface)
            self.xyzVideoPlayerInterface = [[XYZPlayerInterface alloc] initWithPlayerStateManager:self.psmVideoInstance xyzPlayer:self.xyzVideoPlayer];
        
        [self.psmVideoInstance setCISIClientMeasureInterface:(id<CISIClientMeasureInterface>)self.xyzVideoPlayerInterface];
        
        if (self.psmVideoInstance && self.videoSessionID != NO_SESSION_KEY)
            [self.client attachPlayer:self.videoSessionID playerStateManager:self.psmVideoInstance];
        
    }
}

- (void)detachVideoPlayer{
    
    if (self.psmVideoInstance && self.videoSessionID != NO_SESSION_KEY)
        [self.client detachPlayer:self.videoSessionID];
    
}

-(CISContentMetadata *)createVideoMetadataObject{
    self.contentMetaData = [[CISContentMetadata alloc] init];
    self.contentMetaData.assetName = @"iOS_SDK_INTEGRATION";
    self.contentMetaData.applicationName = @"Conviva_Orange_Player";
    self.contentMetaData.custom[@"tag1"] = @"value1";
    self.contentMetaData.custom[@"tag2"] = @"value2";
    self.contentMetaData.viewerId = @"Conviva-QE";
    self.contentMetaData.defaultResource = @"LEVEL3";
    self.contentMetaData.streamType = CONVIVA_STREAM_VOD;
    self.contentMetaData.streamUrl = @"SAMPLE_VIDEO_URL";
    
    return self.contentMetaData;
}

- (void)cleanupVideoPsm {
    if (self.psmVideoInstance) {
        [self.client releasePlayerStateManager:self.psmVideoInstance];
        self.psmVideoInstance = nil;
    }
}

#pragma AD Methods

-(void)createAdSession{
    self.adSessionID = [self.client createAdSession:self.videoSessionID adMetadata:[self createAdMetadataObject]];
    NSLog(@"%d",self.adSessionID);
}

- (void)cleanupAd {
    
    if (self.adSessionID != NO_SESSION_KEY) {
        
        [self.client cleanupSession:self.adSessionID];
        
        self.adSessionID = NO_SESSION_KEY;
        
        [self.xyzAdPlayerInterface cleanupXYZPLayerInterface];
        
        self.xyzAdPlayerInterface = nil;
        
        [self cleanupAdPsm];
        
        [self.xyzAdPlayer stop];
        
        self.xyzAdPlayer = nil;
    
    }
}

- (void)attachAdPlayer{
    if (self.client){
        
        // CREATE PLAYER INSTANCE HERE OR BEFORE
        if (!self.xyzAdPlayer) {
            self.xyzAdPlayer = [[XYZPlayer alloc] initWithVideoUrl:@"SAMPLE_VIDEO_URL"];
        }
        
        if (self.psmAdInstance == nil)
            self.psmAdInstance = [self.client getPlayerStateManager];
        
        // IF XYZPROXY IS NIL CREATE NEW
        // PASS PLAYER INSTANCE HERE TO XYZPROXY
        // ASSIGN PSM ICLIENT TO XYZ PROXY HERE
        if (!self.xyzAdPlayerInterface)
            self.xyzAdPlayerInterface = [[XYZPlayerInterface alloc] initWithPlayerStateManager:self.psmAdInstance xyzPlayer:self.xyzAdPlayer];
        
        [self.psmAdInstance setCISIClientMeasureInterface:(id<CISIClientMeasureInterface>)self.xyzAdPlayerInterface];
        
        if (self.psmAdInstance && self.adSessionID != NO_SESSION_KEY)
            [self.client attachPlayer:self.adSessionID playerStateManager:self.psmAdInstance];
        
    }
}

- (void)detachAdPlayer{
    if (self.psmAdInstance && self.adSessionID != NO_SESSION_KEY)
        [self.client detachPlayer:self.adSessionID];
}

-(CISContentMetadata *)createAdMetadataObject{
    self.adMetaData = [[CISContentMetadata alloc] init];
    self.adMetaData.assetName = @"iOS_AD_SDK_ADS_INTEGRATION";
    self.adMetaData.custom[@"tag1"] = @"value1";
    self.adMetaData.custom[@"tag2"] = @"value2";
    self.adMetaData.defaultResource = @"LEVEL3";
    self.adMetaData.streamType = CONVIVA_STREAM_VOD;
    self.adMetaData.streamUrl = @"SAMPLE_AD_URL";
    return self.adMetaData;
}

- (void)cleanupAdPsm {
    if (self.psmAdInstance) {
        [self.client releasePlayerStateManager:self.psmAdInstance];
        self.psmAdInstance = nil;
    }
}

-(void)registerBackgroundTask{
    self.backgroundUpdateTask = [[UIApplication sharedApplication] beginBackgroundTaskWithExpirationHandler:^{
        [self endBackgroundTask];
    }];
}

- (void) endBackgroundTask {
    [[UIApplication sharedApplication] endBackgroundTask: self.backgroundUpdateTask];
    self.backgroundUpdateTask = UIBackgroundTaskInvalid;
}

@end
