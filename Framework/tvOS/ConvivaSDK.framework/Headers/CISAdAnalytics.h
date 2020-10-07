//
//  CISAdAnalytics.h
//
//  Created by Butchi peddi on 07/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISConstants.h"
#import "CISStreamAnalytics.h"

NS_ASSUME_NONNULL_BEGIN

@protocol CISAdAnalyticsProtocol <CISStreamAnalyticsProtocol>

/**
* Sets ad info.
* @param adInfo ad related info.
*/
- (void) setAdInfo:(NSDictionary*)adInfo;

/**
* Sets Ad PlayerInfo.
* @param adPlayerInfo ad player info.
*/
- (void) setAdPlayerInfo:(NSDictionary*)adPlayerInfo;

/**
* Reports ad failure.
* @param errorMessage error message.
* @param adInfo ad related info.
*/
- (void) reportAdFailed:(NSString*)errorMessage adInfo:(nullable NSDictionary*)adInfo;

/**
* Reports ad load event.
* @param adInfo ad related info.
*/
- (void) reportAdLoaded:(nullable NSDictionary*)adInfo;

/**
* Reports ad start event.
* @param adInfo ad related info.
*/
- (void) reportAdStarted:(nullable NSDictionary*)adInfo;

/**
* Reports ad end event.
*/
- (void) reportAdEnded;

/**
* Reports ad error event.
* @param errorMessage Error message.
* @param severity Severity of the error.
*/
- (void) reportAdError:(NSString*)errorMessage severity:(ErrorSeverity)severity;

/**
* Reports ad skip event.
*/
- (void) reportAdSkipped;

/**
* Reports ad player event.
* @param eventType Event type.
* @param details Event details.
*/
- (void) reportAdPlayerEvent:(NSString*)eventType details:(nullable NSDictionary*)details;

/**
* Reports ad metirc.
* @param key Metric key.
* @param value Metric value.
*/
- (void) reportAdMetric:(NSString*)key value:(id)value;

/**
* Used to set content session id.If already customer integrated EI using legacy api and wanted to integrate AI or other products using this sdk shall use this.
* @param sessionID Video playback session id.
*/
- (void) setContentSessionID:(int)sessionID;

@end

typedef id<CISAdAnalyticsProtocol> CISAdAnalytics;

NS_ASSUME_NONNULL_END
