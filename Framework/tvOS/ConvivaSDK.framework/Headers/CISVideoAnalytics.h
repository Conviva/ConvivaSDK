//
//  CISVideoAnalytics.h
//
//  Created by Butchi peddi on 07/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISConstants.h"
#import "CISStreamAnalytics.h"
#import "CISAdAnalytics.h"

NS_ASSUME_NONNULL_BEGIN

@protocol CISVideoAnalyticsProtocol <CISStreamAnalyticsProtocol>

/**
 * Set content metadata for an existing monitoring session.
 * @param contentInfo Content meta data. Please refer "METADATA CONSTANTS" section defined in CSSConstants.h for possible keys.
 */
- (void) setContentInfo:(NSDictionary*)contentInfo;

/**
* Set player metadata for an existing monitoring session.
* @param playerInfo Content meta data.Please refer "PLAYER INFO CONSTANTS" section defined in CSSConstants.h for possible keys.
*/
- (void) setPlayerInfo:(NSDictionary*)playerInfo;

/**
* Reports playback start.
* @param contentInfo Content meta data.Please refer "METADATA CONSTANTS" section defined in CSSConstants.h for possible keys.
*/
- (void) reportPlaybackRequested:(nullable NSDictionary*)contentInfo;

/**
* Reports playback end.
*/
- (void) reportPlaybackEnded;

/**
* Reports playback faiulure.
* @param errorMessage Error message.
* @param contentInfo Content meta data.Please refer "METADATA CONSTANTS" section defined in CSSConstants.h for possible keys.
*/
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
 * @param adBreakInfo Ad Break info.Please refer "AD BREAK CONSTANTS"  section defined in CSSConstants.h for possible keys.
 */
- (void) reportAdBreakStarted:(AdPlayer)adPlayer adType:(AdTechnology)adType adBreakInfo:(NSDictionary*)adBreakInfo;

/**
 * Notify Conviva that an ad has ended for the monitoring session.
 */
- (void) reportAdBreakEnded;

/**
* If customer uses modules developed conviva for AVPlayer,AVQueuePlayer and Brightcove, shall use this method to pass player instance to enable auto
* detecction of required metrics.
* @param player Player object(Support AVPlayer,AVQueuePlayer and Brightcove).
*/
- (void) setPlayer:(id)player;

/**
* Reports playback metric.
* @param key Metric key.Please refer "PLAYBACK METRIC KEYS" section defined in CSSConstants.h for all possible keys.
* @param value Metric value.
*/
- (void) reportPlaybackMetric:(NSString*)key value:(id)value;

/**
* Set ad analytics object on video analytics to enable seamlessly passing common data from video analytics to ad analytcis.
* @param adAnalytics  Ad analytics.
*/
- (void) setAdAnalytics:(CISAdAnalytics)adAnalytics;

@end

typedef id<CISVideoAnalyticsProtocol> CISVideoAnalytics;

NS_ASSUME_NONNULL_END
