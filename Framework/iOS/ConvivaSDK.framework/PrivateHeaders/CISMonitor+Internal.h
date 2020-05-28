//
//  CISMonitor+Internal.h
//  Pods
//
//  Created by Butchi peddi on 09/03/20.
//

#import "CISMonitor.h"

NS_ASSUME_NONNULL_BEGIN

@interface CISMonitor (){
    BOOL _isPlayerSeeking;
}

@property(nonatomic, assign) int sessionID;
@property(nonatomic, strong) CISEventQueue *cisEventQueue;
@property(nonatomic, strong) CISContentMetadata *cisContentMetadata;
@property(nonatomic, weak) CISSystemFactory *cisSystemFactory;

@property(nonatomic, strong) CISTime *cisTime;
@property(nonatomic, strong) CISLogger *cisLogger;

@property(nonatomic, assign) NSTimeInterval startTimeMs;
@property(nonatomic, assign) BOOL hasJoined;
@property(nonatomic, assign) BOOL pauseJoin;
@property(nonatomic, assign) BOOL preloading;
@property(nonatomic, assign) BOOL ignorePlayerState;
@property(nonatomic) PlayerState pooledPlayerState;
@property(nonatomic, assign) BOOL ignoreBitrateAndResource;
@property(nonatomic, assign) BOOL ignoreFrameRateAndDuration;
@property(nonatomic, assign) BOOL ignoreError;

@property(nonatomic, assign) BOOL adPlaying;
@property(nonatomic) AdStream adStream;
@property(nonatomic) AdPlayer adPlayer;

// Proxy state
@property(nonatomic) PlayerState contentPlayerState;
@property(nonatomic, assign) NSInteger playerBitrateKbps;
@property(nonatomic, assign) NSInteger averageBitrateKbps;

@property(nonatomic, assign) int sessionFlags;

@property(nonatomic, assign) NSInteger contentLenSec;

@property(nonatomic,strong) CISPlayerStateManager *playerStateManager;

@property(nonatomic, assign) int64_t contentPlayheadTimeMs;
@property(nonatomic, assign) int64_t contentBufferLengthMs;

@property(nonatomic, assign) NSUInteger videoWidth;

@property(nonatomic, assign) NSUInteger videoHeight;
//  DE-2572 Remove SSID Support since this is a PII
//@property(nonatomic, copy) NSString *ssidString;

@property(nonatomic, assign) double signalStrength;

@property(nonatomic, copy) NSString *linkEncyptionType;

@property(nonatomic, copy) NSString *connectionType,*connectionTypeExternal;

@property(nonatomic,weak) CISNetworkUtil *cisNetworkUtility;

@property(nonatomic, strong) CISTimer *cisTimer;

@property(nonatomic,strong) id<CISCancelProtocol> cisCancelTimerFramerateFetch;

// Changed totalPlayingFps from int64_t to NSInteger;
@property(nonatomic, assign) NSInteger totalPlayingFps;

// Changed playingFpsSamples from int64_t to NSInteger;
@property(nonatomic, assign) NSInteger playingFpsSamples;

 //Changed encodedFps from int64_t to NSInteger;
 //Commented to Avoid Autodetection from Player state manager
@property(nonatomic, assign) NSInteger encodedFps;

@property(nonatomic, assign) SessionType sessionType;

@end

NS_ASSUME_NONNULL_END
