//
//  CISVideoAnalyticsImpl.m
//  Pods
//
//  Created by Butchi peddi on 07/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISVideoAnalytics.h"
#import "CISClientProtocol.h"
#import "CISSystemFactoryProtocol.h"
#import "CISStreamAnalyticsImpl.h"

NS_ASSUME_NONNULL_BEGIN

@interface CISVideoAnalyticsImpl : CISStreamAnalyticsImpl <CISVideoAnalyticsProtocol>

@property (assign,readonly) AdTechnology adType;

- (void) setContentInfo:(NSDictionary*)contentInfo;

- (void) setPlayerInfo:(NSDictionary*)playerInfo;

- (void) reportPlaybackRequested:(nullable NSDictionary*)contentInfo;

- (void) reportPlaybackEnded;

- (void) reportPlaybackFailed:(NSString*)errorMessage contentInfo:(nullable NSDictionary*)contentInfo;

/**
 * Reports an error for this monitoring session.
 * @param errorMessage The error message to be reported.
 * @param severity The severity of the error.
 */
- (void) reportPlaybackError:(NSString*)errorMessage errorSeverity:(ErrorSeverity)severity;

/**
 * Send a playback event to Conviva.
 * @param eventName Name of the custom event.
 * @param attributes A dictionary of key-value pairs associated with the event.
 */
- (void) reportPlaybackEvent:(NSString*)eventName withAttributes:(nullable NSDictionary*)attributes;

/**
* Notify Conviva that an ad is about to start for the monitoring session.
* @param adPlayer Whether the ad is played by the same player as the original video content.
* @param adType Whether the ad is embedded in the content stream.
* @param adBreakInfo Ad Break info.
*/
- (void) reportAdBreakStarted:(AdPlayer)adPlayer adType:(AdTechnology)adType adBreakInfo:(NSDictionary*)adBreakInfo;

/**
 * Notify Conviva that an ad has ended for the monitoring session.
 */
- (void) reportAdBreakEnded;

- (void) setPlayer:(id)player;

- (void) reportPlaybackMetric:(NSString*)key value:(nullable id)value;

- (void) reportPlaybackMetric:(NSString*)key value:(nullable id)value  internal:(BOOL)internal;

- (void) reportPlaybackMetrics:(NSDictionary*)metrics;
/**
 * Terminates a monitoring session.
 * Use when playback for video content ends, fails or is cancelled by the viewer.
 */
- (void) cleanup;

- (void) configureExistingSession:(int)sessionId;

- (void) setAdAnalytics:(CISAdAnalytics)adAnalytics;

- (void) setUserOptions:(NSDictionary*)options;


#pragma mark Private Methods

- (instancetype) initWithClient:(id<CISClientProtocol>)client
                  systemFactory:(id<CISSystemFactoryProtocol>)systemFactory;


- (BOOL) isVideoAnalytics;

- (void) setContentPauseMonitoring;

- (void) setContentResumeMonitoring;


@end

NS_ASSUME_NONNULL_END
