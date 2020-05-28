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

@property(nonatomic,strong) CISAnalytics analytics;
@property(nonatomic,strong) CISVideoAnalytics videoAnalytics;
@property(nonatomic,strong) CISAdAnalytics adAnalytics;


@property(nonatomic,strong) XYZPlayerInterface *xyzVideoPlayerInterface,*xyzAdPlayerInterface;
@property(nonatomic,strong)  XYZPlayer *xyzVideoPlayer,*xyzAdPlayer;
@property(nonatomic,strong) NSTimer *adTimer;
@property(atomic) UIBackgroundTaskIdentifier backgroundUpdateTask;
@property(nonatomic,assign) BOOL adPlayingBeforeBackground;


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
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
    if (self.analytics != nil ){
        [self createVideoSession];
        [self endBackgroundTask];
        [self registerBackgroundTask];
        [self registerBackGroundForeGroundHandler];
        switch (self.adSegment.selectedSegmentIndex) {
            case 0:
                // PREROLL;
                [self adStarted];
                
                [self.videoAnalytics reportPlaybackEvent:@"Sample Event Video" withAttributes:@{@"podDuration" : @"60"}];
                
                // Create Ad session
                [self createAdSession];
                
                // Send Event Video Session
                
                [self.adAnalytics reportAdPlayerEvent:@"Sample Event Ad" details:@{@"AdDuration" : @"60"}];
                
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
    
    [self.videoAnalytics reportPlaybackMetric:CIS_SSDK_PLAYBACK_METRIC_PLAYER_STATE value:[NSNumber numberWithUnsignedInt:CONVIVA_BUFFERING]];

    [self.videoAnalytics reportPlaybackMetric:CIS_SSDK_PLAYBACK_METRIC_PLAYER_STATE value:[NSNumber numberWithUnsignedInt:CONVIVA_PLAYING]];

    [self.videoAnalytics reportPlaybackMetric:CIS_SSDK_PLAYBACK_METRIC_BITRATE value:[NSNumber numberWithInt:100]];
}

-(void)setAdStates{

    [self.adAnalytics reportAdMetric:CIS_SSDK_PLAYBACK_METRIC_PLAYER_STATE value:[NSNumber numberWithUnsignedInt:CONVIVA_BUFFERING]];

    [self.adAnalytics reportAdMetric:CIS_SSDK_PLAYBACK_METRIC_PLAYER_STATE value:[NSNumber numberWithUnsignedInt:CONVIVA_PLAYING]];

    [self.adAnalytics reportAdMetric:CIS_SSDK_PLAYBACK_METRIC_BITRATE value:[NSNumber numberWithInt:200]];

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

        [self.analytics reportAppBackgrounded];
        
        [self cancelAdTimer];
        
        
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
    
    [self.videoAnalytics reportPlaybackError:@"Video start error" errorSeverity:ERROR_FATAL ];

}

- (IBAction)initSDKClicked:(id)sender {
    
    NSDictionary *settings = @{CIS_SSDK_SETTINGS_GATEWAY_URL:@"GATEWAYURL",CIS_SSDK_SETTINGS_LOG_LEVEL:@(LOGLEVEL_WARNING)};

    self.analytics =  [CISAnalyticsCreator createWithCustomerKey:@"KEY" settings:settings];
    
}

- (IBAction)cleanupSDKClicked:(id)sender {
    
    [self cleanupSessionClicked:nil];
    
    [self.videoAnalytics cleanup];
    self.videoAnalytics = nil;
    
    [self.adAnalytics cleanup];
    self.adAnalytics = nil;
    
    [self.analytics cleanup];
    self.analytics = nil;
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationWillEnterForegroundNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationDidEnterBackgroundNotification object:nil];
}

-(BOOL)textFieldShouldReturn:(UITextField *)textField{
    return YES;
}

- (void)adStarted {
    if (self.videoAnalytics){
        
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
        
        if (self.adSegment.selectedSegmentIndex != 3){
        
            NSDictionary *adAttributes = @{@"podIndex":@"1",@"podDuration":@"10",@"podPosition":[CISConstants getAdPositionStringValue:adPos]};

            [self.videoAnalytics reportAdBreakStarted:ADPLAYER_SEPARATE adType:CLIENT_SIDE adBreakInfo:adAttributes];

        }
    }
}

- (void)adEnded {
    [self.videoAnalytics reportAdBreakEnded];
}

-(NSDictionary*) buildContentInfo{
    
    NSDictionary *contentInfo = @{  CIS_SSDK_METADATA_ASSET_NAME:@"asset",
                                    CIS_SSDK_METADATA_IS_LIVE:@(true),
                                    CIS_SSDK_METADATA_PLAYER_NAME:@"playername",
                                    CIS_SSDK_METADATA_VIEWER_ID:@"viewerid",
                                    CIS_SSDK_METADATA_DEFAULT_RESOURCE:@"resource",
                                    CIS_SSDK_METADATA_DURATION:@(100),
                                    CIS_SSDK_METADATA_STREAM_URL:@"http://test.m3u8",
                                    CIS_SSDK_PLAYER_FRAMEWORK_NAME:@"frameworkname",
                                    CIS_SSDK_PLAYER_FRAMEWORK_VERSION:@"frameworkversion",
                                    @"tags":@{@"key1":@"val1",@"key2":@"val2"}
                                    };

    return contentInfo;
}
    
-(NSDictionary*) buildAdInfo {
    
    NSDictionary *adInfo =      @{  CIS_SSDK_METADATA_ASSET_NAME:@"adasset",
                                    CIS_SSDK_METADATA_IS_LIVE:@(true),
                                    CIS_SSDK_METADATA_PLAYER_NAME:@"adplayername",
                                    CIS_SSDK_METADATA_VIEWER_ID:@"viewerid",
                                    CIS_SSDK_METADATA_DEFAULT_RESOURCE:@"resource",
                                    CIS_SSDK_METADATA_DURATION:@(100),
                                    CIS_SSDK_METADATA_STREAM_URL:@"http://test.m3u8",
                                    CIS_SSDK_PLAYER_FRAMEWORK_NAME:@"frameworkname",
                                    CIS_SSDK_PLAYER_FRAMEWORK_VERSION:@"frameworkversion",
                                    @"tags":@{@"adkey1":@"adval1",@"adkey2":@"adval2"}
                                    };
    
    return adInfo;
}

- (IBAction)updateMetaDataClicked:(id)sender {
    
    NSDictionary *contentInfo = @{
                                       CIS_SSDK_METADATA_IS_LIVE:@(true),
                                       CIS_SSDK_METADATA_PLAYER_NAME:@"playername",
                                       CIS_SSDK_METADATA_VIEWER_ID:@"viewerid",
                                       CIS_SSDK_METADATA_DEFAULT_RESOURCE:@"LEVEL3",
                                       CIS_SSDK_METADATA_DURATION:@(100),
                                       CIS_SSDK_METADATA_STREAM_URL:@"http://test.m3u8"
                                       };
 
    [self.videoAnalytics setContentInfo:contentInfo];
}

- (IBAction)sendEventClicked:(id)sender {
    
    [self.videoAnalytics reportPlaybackEvent:@"Sample Event Video" withAttributes:@{@"Duration" : @"10"}];
    
    [self.adAnalytics reportAdPlayerEvent:@"Sample Event Ad" details:@{@"Duration" : @"20"}];
}

#pragma Video Methods

-(void)createVideoSession{
    
    if (self.analytics)  {
       self.videoAnalytics = [self.analytics createVideoAnalytics];
        [self.videoAnalytics reportPlaybackRequested:[self buildContentInfo]];
    }
}

- (IBAction)cleanupSessionClicked:(id)sender {
    
    [self cleanupAd];

    [self.videoAnalytics reportPlaybackEnded];
    [self.videoAnalytics cleanup];
    self.videoAnalytics = nil;
}


- (void)attachVideoPlayer{
    
    if (self.analytics) {
        
        // CREATE PLAYER INSTANCE HERE OR BEFORE
        if (self.xyzVideoPlayer == nil){
            self.xyzVideoPlayer = [[XYZPlayer alloc] initWithVideoUrl:@"Sample URL"];
        }
        
        NSString *event = [CISConstants getEventsStringValue:USER_WAIT_ENDED];
        [self.videoAnalytics reportPlaybackEvent:event withAttributes:nil];
    }
}

- (void)detachVideoPlayer{
    
    NSString *event = [CISConstants getEventsStringValue:USER_WAIT_STARTED];
    [self.videoAnalytics reportPlaybackEvent:event withAttributes:nil];
    
}

#pragma AD Methods

-(void)createAdSession{
    self.adAnalytics = [self.analytics createAdAnalyticsWithVideoAnalytics:self.videoAnalytics];
    [self.adAnalytics reportAdLoaded:[self buildAdInfo]];
}

- (void)cleanupAd {
    
    [self.adAnalytics reportAdEnded];
    [self.adAnalytics cleanup];
    
    if(self.xyzAdPlayer != nil){
        [self.xyzAdPlayer stop];
        self.xyzAdPlayer = nil;
    }
}

- (void)attachAdPlayer{
    
    if( self.analytics ){
        
        // CREATE PLAYER INSTANCE HERE OR BEFORE
        if (self.xyzAdPlayer == nil){
            self.xyzAdPlayer = [[XYZPlayer alloc] initWithVideoUrl:@"Sample Video Url"];
            [self.adAnalytics reportAdStarted:[self buildAdInfo]];
        }else {
            NSString *event = [CISConstants getEventsStringValue:USER_WAIT_STARTED];
            [self.videoAnalytics reportPlaybackEvent:event withAttributes:nil];
        }
        
    }
}

- (void)detachAdPlayer{
    NSString *event = [CISConstants getEventsStringValue:USER_WAIT_ENDED];
    [self.videoAnalytics reportPlaybackEvent:event withAttributes:nil];
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
