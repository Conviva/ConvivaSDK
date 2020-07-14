//
//  CISAnalyticsImpl.m
//  Pods
//
//  Created by Butchi peddi on 07/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISMonitor.h"
#import "CISConstants.h"
#import "CISIClientMeasureInterface.h"
#import "CISStreamerError.h"
#import "CISStreamAnalytics.h"

@interface CISPlayerMonitor : NSObject <CISIClientMeasureInterface>

@property (strong,readonly) CISContentMetadata *contentMetadata;
@property (strong,readonly) CISClient *client;
@property (strong) CISPlayerStateManager *playerStateManager;
@property (assign) NSInteger bitrate;
@property (assign) NSInteger averageBitrate;
@property (assign) int sessionID;
@property (strong,readonly) CISLogger *cisLogger;

@property (strong,nonatomic) NSDictionary* adBreakInfo;

@property (copy) NSString* lastEventType;
@property (strong) NSDictionary* lastEventDetail;
@property (strong) CISStreamerError *lastError;
@property (assign) BOOL affectsUser;
@property (strong) NSDictionary* metaData;
@property (strong) NSMutableDictionary* contentTags;
@property (strong) NSMutableDictionary* playerTags;
@property (assign) NSInteger seekToPos;
@property (assign) BOOL seeking;
@property (strong) UpdateHandler updateHandler;
@property (assign) BOOL updationInProgress;
@property(nonatomic,strong) id<CISCancelProtocol>  updateTimer;

@property (assign) PlayerState playState;
@property (copy) NSString* cdnServerIPAddress;
@property (copy) NSString* cdnResource;

@property (copy) NSString* linkEncryption;
@property (copy) NSString* connType;

@property (assign) double signalStrength;

@property (assign) int videoWidth;
@property (assign) int videoHeight;
@property (assign) NSInteger playHeadTime;
@property (assign) NSInteger bufferHeadTime;

@property (assign) AdStream adStream;
@property(nonatomic, strong) CISTimer *cisTimer;
@property (strong, readwrite) CISSystemFactory* systemFactory;

@property (assign,nonatomic) NSInteger frameRate;

@property (assign,nonatomic) CISPlayerMonitor* videoPlayerMonitor;

//@property (assign) NSInteger frameRate;

-(instancetype) initWithClient:(CISClient*)client
                 systemFactory:(id<CISSystemFactoryProtocol>)systemFactory
                        logger:(CISLogger*)logger;

- (void) setContentPlayerMonitor:(CISPlayerMonitor*)playerMonitor;

- (CISPlayerMonitor*) getContentPlayerMonitor ;

- (PlayerState) getConvivaPlayerState;

- (void) setPlayerState:(PlayerState)playerState;

- (BOOL) isSeeking;

- (NSInteger) getSeekToPos;

- (void) onSeekingChanged;

- (void) setSeeking:(BOOL)seeking seekToPos:(NSInteger)seekToPos;

- (int64_t) getPlayHeadTime;

- (void) updatePlayheadTime:(NSInteger)playheadTime;

- (int64_t) getBufferHeadTime;

- (void) updateBufferheadTime:(NSInteger)bufferheadTime;

- (NSInteger) getBitrate;

- (NSInteger) getAverageBitrate;

- (void) updatePlayerStateManagerState;

- (void) updateBitrate:(NSInteger)bitrate;

- (void) updateAverageBitrate:(NSInteger)averageBitrate;

- (void) updateCDNIpAddress:(NSString*)ipAdderess resource:(NSString*)resource;

- (NSString*) getCdnip;

- (double) getSignalStrength;

- (void) updateSignalStrength:(double)signalStrength;

- (NSString*) getLinkEncryption;

- (void) updateLinkEncryption:(NSString*)linkEncryption;

- (NSString*) getConnType;

- (void) updateConnType:(NSString*)connType;
    
- (NSInteger) getVideoFrameRate;

- (void) updateVideoFrameRate:(NSInteger)frameRate;

- (int) getSessionId;

- (void) setSessionId:(int)sessionId;

- (int) getInternalSessionId;

- (NSInteger) getVideoWidth;

- (NSInteger) getVideoHeight;

- (void) updateVideoSize:(CGSize)size;

- (NSDictionary*) getMetadataInfo;

- (void) onMetadataInfoChanged;

- (void) onMetadataInfoSet;

- (void) setMetadataInfo:(NSDictionary*)contentInfo;

- (void) setOrUpdateMetadataInfo:(NSDictionary*)contentInfo;

- (void) attach;

- (void) detach:(AdPlayer)adPlayer adType:(AdStream)adType;

- (void) attachPlayer;

- (void) attachPlayer:(BOOL)metricRequired;

- (void) detachPlayer:(NSInteger)sessionKey;

- (UpdateHandler) getCallback ;

- (void) setCallback:(UpdateHandler)callback;

- (void) update;

- (void) setRenderedFramerate;

- (BOOL) getIsAffectingUser;

- (void) setAffectingUser:(BOOL)affectingUser;

- (void) createSession;

- (void) endSession;

- (void) updateCustomMetric:(NSString*)key value:(id)value;

- (NSString*) getLastEventType;

- (NSDictionary*) getLastEventDetail;

- (CISStreamerError*) getLastError;

- (void) onError;

- (void) setError:(CISStreamerError*)error;

- (void) onEvent;

- (void) setEvent:(NSString*) eventType  eventDetail:(NSDictionary*)eventDetail;

- (NSDictionary*) getAdBreakInfo;

- (void) onAdBreakStartInfoSet;

- (void) setAdBreakStartInfo:(AdPlayer)adPlayer adType:(AdStream)adType adBreakInfo:(NSDictionary*)adBreakInfo;

- (void) onAdBreakEndInfoSet;

- (void) setAdBreakEndInfo;

- (void) startTimer;

- (void) cleanUpTimer;

- (void) cleanupPlayerMonitor;

- (void) onAdPlayerMonitorCleanUp;

- (void) onPlayerMonitorCleanUp;

#pragma mark - CISIClientMeasureInterface methods

- (NSInteger) getPHT;

- (NSInteger) getBufferLength;

- (NSInteger) getAverageFrames;

#pragma mark - End of CISIClientMeasureInterface methods

- (NSDictionary*)merge:(NSDictionary*)list1 with:(NSDictionary*)list2 changed:(BOOL *)changed;

@end
