//
//  CISMonitor.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 29/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISEventQueue.h"
#import "CISContentMetadata.h"
#import "CISSystemFactory.h"
#import "CISStreamerError.h"
#import "CISConstants.h"
#import "CISNetworkUtil.h"

FOUNDATION_EXPORT NSString *const METADATA_DURATION;
FOUNDATION_EXPORT NSString *const METADATA_ENCODED_FRAMERATE;


@interface CISMonitor : NSObject

//@property(nonatomic, copy) NSString *contentResource;
@property(nonatomic, assign) BOOL cdnEdgeServerIPReportingDisabled;
@property(nonatomic, copy) NSString *cdnServerIPAddress;

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithSessionID:(int)sessionId  cisEventQueue:(CISEventQueue *)eventQueue  cisContentMetadata:(CISContentMetadata *)contentMetadata cisSystemFactory:(CISSystemFactory *)systemFactory networkUtil:(CISNetworkUtil *)networkUtil sessionType:(SessionType)sessionType NS_DESIGNATED_INITIALIZER;

-(void)start:(NSTimeInterval)timeNow;

//-(void)updateHb:(NSMutableDictionary **)heartbeat;

-(void)updateHb:(NSMutableDictionary **)heartbeat cisprotocol:(CISCWSProtocolHelper *)proto;

-(void) attachPlayer:(CISPlayerStateManager *) psm;

-(void) detachPlayer;

-(void)updateEvent:(NSMutableDictionary *)ev;

-(void)setPlayerState:(PlayerState)newState;

- (void)setCDNServerIP:(NSString *)cdnServerIP;

/// @brief Signal a change in the bitrate
-(void)setBitrateKbps:(NSInteger)bitrateKbps;

/// @brief Signal an error
-(void)onError:(CISStreamerError *)error;

/// @brief Signal new metadata
-(void)onMetadata:(NSDictionary *)metadata;

-(void)releasePlayerStateManager;

-(void)adStart:(AdStream)adStream adPlayer:(AdPlayer)adPlayer adPosition:(AdPosition)adPosition;

-(void)adEnd;

-(void)cleanUp;

-(void)contentPreload;

-(void) contentStart;

-(void)updateNetworkUtilData;

// CWS 2.2 METHODS

-(void)setStreamResolutionWidth:(NSInteger)newWidth;

-(void)setStreamResolutionHeight:(NSInteger)newHeight;

// NETWORK 2.2
//  DE-2572 Remove SSID Support since this is a PII
//-(void)setSSIDValue:(NSNotification *)newSSIDNotification;

-(void)setSignalStrengthValue:(NSNotification *)newSignalStrengthNotification;

-(void)setLinkEncryptionValue:(NSNotification *)newLinkEncyptionTypeNotification;

-(void)setConnectionTypeValue:(NSNotification *)newConnectionTypeNotification;

- (void)setSeekStart:(int64_t)seekToPosition;

- (void)setSeekEnd:(int64_t)seekPosition;

-(BOOL)isPlayerSeeking;

-(void)updateStreamUrl:(NSString *)newStreamUrl;

-(void)updateCDNName:(NSString *)newCDNName;

-(void)updateResource:(NSString *)newResource;

-(void)enqueueDataSamplesEvent;

-(void)updateMetadata:(CISContentMetadata*)newcontentInfo;

-(void) setAvgBitrateKbps:(NSInteger)newAvgBitrateKbps;

-(void)setConnectionTypeExternal:(NSString *)newConnectionType;
 
-(CISPlayerStateManager*) getAttachedPlayer;


@end
