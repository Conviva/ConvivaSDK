//
//  CISBaseAnalytics.m
//  Pods
//
//  Created by Butchi peddi on 20/02/20.
//

#import <Foundation/Foundation.h>
#import "CISConstants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol CISBaseAnalyticsProtocol <NSObject>

/**
*  Reports player state. Please refer PlayerState for possible values.
*  @param playerState Player state.
*/
- (void) reportPlayerState:(PlayerState)playerState;

/**
* Returns session id.
* @return session id.
*/
- (int) getSessionId;

/**
* Reports playback metric.
* @param key Metric key.Please refer CSSConstants.h for all possible keys.
* @param value Metric value.
*/
- (void) reportPlaybackMetric:(NSString*)key value:(nullable id)value;

/**
* Update Handler callback function.
*/
typedef void (^UpdateHandler)(void);

/**
* Sets update handler callback function.
* @param updateHandler UpdateHandler callback function.
*/
- (void) setUpdateHandler:(UpdateHandler)updateHandler;

/**
* Tells whether this is ad analytics interface or not.
* @return TRUE or FALSE.
*/
- (BOOL) isAdAnalytics;

/**
* Tells whether this is video analytics interface or not.
* @return TRUE or FALSE.
*/
- (BOOL) isVideoAnalytics;

/**
* Performs required cleanup.
*/
- (void) cleanup;

@end

typedef id<CISBaseAnalyticsProtocol> CISBaseAnalytics;
NS_ASSUME_NONNULL_END
