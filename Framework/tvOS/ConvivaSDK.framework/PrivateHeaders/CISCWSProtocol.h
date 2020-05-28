//
//  CISCWSProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 13/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

/**
 * The current version of the Conviva library.
 */
// the next line will be modified by set_versions.pl
#define BUILD_SVN_REVISION @"2.140.0.35590"


FOUNDATION_EXPORT NSString *const CIS_VERSION;
//FOUNDATION_EXPORT NSString *const DEFAULT_CLIENT_ID;
FOUNDATION_EXPORT NSString *const PRODUCTION_SERVICE_PATH;

FOUNDATION_EXPORT NSString *const CIS_PLATFORM_METADTA_KEY;
FOUNDATION_EXPORT NSString *const CIS_FRAMEWORK_NAME_KEY;
FOUNDATION_EXPORT NSString *const CIS_FRAMEWORK_VERSION_KEY;

/**
 * Types of data reported by the session.
 */
/** The session will not report any video playback data. */
FOUNDATION_EXPORT int const CAPABILITY_GLOBAL;
/** The session will report video playback data. */
FOUNDATION_EXPORT int const CAPABILITY_VIDEO;
/** The session will report video quality data. */
FOUNDATION_EXPORT int const CAPABILITY_QUALITY_METRICS;
/** The session will report video bitrate data. */
FOUNDATION_EXPORT int const CAPABILITY_BITRATE_METRICS;

FOUNDATION_EXPORT int const CAPABILITY_PRECISION;// Deprecated, was used for Precision Lite.
//tbd:butchi:Check this in legacy
FOUNDATION_EXPORT int const CAPABILITY_BITRATE_EXTERNAL;
FOUNDATION_EXPORT int const CAPABILITY_PRECISION_VIDEO;
FOUNDATION_EXPORT int const CAPABILITY_OFFLINE_VIDEO ;

@protocol CISCWSProtocol <NSObject>

@required

-(NSDictionary *)buildPlatformSystemMetadata:(NSDictionary *)systemMetadata;
-(void)setType:(NSString *)type  hbdict:(NSDictionary **)hbDict;
-(void)setEvents:(NSArray *)event hbdict:(NSDictionary **)hbDict;
-(void)setCustomerKey:(NSString *)customerKey hbdict:(NSDictionary **)hbDict;
-(void)setClientId:(NSString *)clientID hbdict:(NSDictionary **)hbDict;
-(void)setSessionID:(int)sessionID hbdict:(NSDictionary **)hbDict;
-(void)setheartbeatSequenceNumber:(int32_t)heartBeatSequenceNumber hbdict:(NSDictionary **)hbDict;
-(void)setProtocolVersion:(NSString *)protocolVersion hbdict:(NSDictionary **)hbDict;
-(void)setClientVersion:(NSString *)clientVersion hbdict:(NSDictionary **)hbDict;
-(void)setInstanceID:(int)instanceID hbdict:(NSDictionary **)hbDict;
-(void)setIsSDK:(NSString *)isSDK hbdict:(NSDictionary **)hbDict;
-(void)setTags:(NSDictionary *)tags hbdict:(NSDictionary **)hbDict;
-(void)setViewerID:(NSString *)viewerID hbdict:(NSDictionary **)hbDict;

-(void)setAssestName:(NSString *)assestName hbdict:(NSDictionary **)hbDict;
-(void)setContentIsLive:(NSString *)isLive hbdict:(NSDictionary **)hbDict;
-(void)setGlobalCapablity:(int)globalCapablity hbdict:(NSDictionary **)hbDict;
-(void)setApplicationName:(NSString *)applicationName hbdict:(NSDictionary **)hbDict;
-(void)setLogBuffer:(NSArray *)logBufferArray hbdict:(NSDictionary **)hbDict;
-(void)setSessionTime:(NSNumber *)sessionTime hbdict:(NSDictionary **)hbDict;
-(void)setClientTime:(NSTimeInterval)clientTime hbdict:(NSDictionary **)hbDict;

-(void)setPlayerState:(int)playerStateValue hbdict:(NSDictionary **)hbDict;
-(void)setPauseJoin:(NSString *)pauseJoinState hbdict:(NSDictionary **)hbDict;
-(void)setSessionFlag:(int)sessionFlagValue  hbdict:(NSDictionary **)hbDict;
-(void)setPlatformMetadata:(NSDictionary *)metaDictionary hbdict:(NSDictionary **)hbDict;
-(void)setFrameworkName :(NSString *)frameworkName  hbdict:(NSDictionary **)hbDict;
-(void)setFrameWorkVersion:(NSString *)frameworkVersion hbdict:(NSDictionary **)hbDict;
-(void)setStreamUrl:(NSString *)streamUrl hbdict:(NSDictionary **)hbDict;
-(void)setResource:(NSString *)resource hbdict:(NSDictionary **)hbDict;
-(void)setContentLength:(NSInteger)contentLength hbdict:(NSDictionary **)hbDict;
-(void)setEncodedFrameRate:(NSInteger)encodedFrameRate hbdict:(NSDictionary **)hbDict;
-(void)setAverageFPS:(NSInteger)averageFPS  hbdict:(NSDictionary **)hbDict;
-(void)setEnhancedFPS:(NSInteger)rfps sample:(NSInteger)samples hbdict:(NSDictionary **)hbDict;
-(void)setBitrate:(NSInteger)bitrate  hbdict:(NSDictionary **)hbDict;
-(void)setAvgBitrate:(NSInteger)bitrate  hbdict:(NSDictionary **)hbDict;

-(void)setCDN:(NSString *)cdnName hbdict:(NSDictionary **)hbDict;

// CWS 2.2 ADDED

-(void)setRenderedFramerate:(NSInteger)renderedFrameRate hbdict:(NSDictionary **)hbDict;
-(void)setDroppedFramerate:(NSInteger)droppedFrameRate hbdict:(NSDictionary **)hbDict;
-(void)setVideoPHT:(int64_t)pht hbdict:(NSDictionary **)hbDict;
-(void)setBufferLength:(int64_t)bufferLength hbdict:(NSDictionary **)hbDict;
-(void)setVideoResolutionWidth:(NSInteger)width hbdict:(NSDictionary **)hbDict;
-(void)setVideoResolutionHeight:(NSInteger)height hbdict:(NSDictionary **)hbDict;
-(void)setCDNIPAddress:(NSString *)cdnIPAddress hbdict:(NSDictionary **)hbDict;
//  DE-2572 Remove SSID Support since this is a PII
//-(void)setSSID:(NSString *)ssid hbdict:(NSDictionary **)hbDict;
-(void)setSignalStrength:(double)signalStrength hbdict:(NSDictionary **)hbDict;
-(void)setLinkEncryption:(NSString *)linkEncryptionValue hbdict:(NSDictionary **)hbDict;
-(void)setConnectionType:(NSString *)connectionType hbdict:(NSDictionary **)hbDict;
-(void)setComponentConfigration:(NSDictionary *)componentConfigDictionary hbdict:(NSDictionary **)hbDict;

-(void)setAdSession:(NSString *)isAdSession hbdict:(NSDictionary **)hbDict;
// DE-2912
-(void)setPlatformName:(NSDictionary *)systemMetadata hbdict:(NSDictionary **)hbDict;

@end
