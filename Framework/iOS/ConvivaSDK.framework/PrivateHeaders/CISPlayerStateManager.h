//
//  CISPlayerStateManager.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 06/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
//  iOS Sdk Core version 2.128.0.34024
//

#import <Foundation/Foundation.h>
#import "CISSystemFactory.h"
#import "CISStreamerError.h"
#import "CISPlayerStateManagerProtocol.h"
#import "CISNetworkUtil.h"
#import "CISContentMetadata.h"

@class CISMonitor;


@interface CISPlayerStateManager : NSObject <CISPlayerStateManagerProtocol>

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithSystemFactory:(CISSystemFactory *)systemFactory networkUtil:(CISNetworkUtil *)networkUtil NS_DESIGNATED_INITIALIZER;

/**
 * Internal: Do not use
 */
- (void)pushCurrentState;

/**
 * Internal: Do not use
 */
-(CISStreamerError *)getError;

/**
 * Internal: Do not use
 */
- (BOOL)setMonitoringNotifier:(CISMonitor *)monitor sessionID:(int)sessionId;

/**
 * Internal: Do not use
 */
- (void)removeMonitoringNotifier;

/**
 * Release this PlayerStateManager instance.<br>
 * Call when you no longer need to collect data from the related video player.
 */
-(void)cleanUp;

/**
 * Return the buffer length in milli second of player instance in seconds.
 * Internal: Do not use
 */
-(int64_t)getBufferLengthMs;

/**
 * Return the Playhead time in milli second of player instance in seconds.
 * Internal: Do not use
 */
-(int64_t)getPlayheadTimeMs;

/**
 * Return the encoded frames per second of player instance in seconds.
 * Internal: Do not use
 */
-(NSInteger)getEncodedFramesPerSecond;

/**
 * Return the average frames per second of player instance in seconds.
 * Internal: Do not use
 */
-(NSInteger)getAverageFramesPerSecond;

/**
 * Return the encoded frames per second of player instance in seconds.
 * Internal: Do not use
 */
-(NSInteger)getDroppedFramesPerSecond;

/**
 * Return the encoded frames per second of player instance in seconds.
 * Internal: Do not use
 */
-(NSInteger)getRenderedFramesPerSecond;

@end
