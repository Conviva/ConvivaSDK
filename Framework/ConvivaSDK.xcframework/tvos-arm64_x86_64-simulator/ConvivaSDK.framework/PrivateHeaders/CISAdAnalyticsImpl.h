//
//  CISAdAnalyticsImpl.h
//  Pods
//
//  Created by Butchi peddi on 07/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISAdAnalytics.h"
#import "CISClientProtocol.h"
#import "CISSystemFactoryProtocol.h"
#import "CISVideoAnalyticsImpl.h"
#import "CISStreamAnalyticsImpl.h"

NS_ASSUME_NONNULL_BEGIN

@interface CISAdAnalyticsImpl : CISStreamAnalyticsImpl <CISAdAnalyticsProtocol>

- (void) setAdInfo:(NSDictionary*)adInfo;

- (void) setAdPlayerInfo:(NSDictionary*)adPlayerInfo;

- (void) reportAdFailed:(NSString*)errorMessage adInfo:(nullable NSDictionary*)adInfo;

- (void) reportAdLoaded:(nullable NSDictionary*)adInfo;

- (void) reportAdStarted:(nullable NSDictionary*)adInfo;

- (void) reportAdEnded;

- (void) reportAdError:(NSString*)errorMessage severity:(ErrorSeverity)severity;

- (void) reportAdSkipped;

- (void) reportAdPlayerEvent:(NSString*)eventType details:(nullable NSDictionary*)details;

- (void) reportAdMetric:(NSString*)key value:(id)value;

- (void) setContentSessionID:(int)sessionID;

#pragma mark Private Methods
- (instancetype) initWithClient:(id<CISClientProtocol>)client
                  systemFactory:(id<CISSystemFactoryProtocol>)systemFactory;

- (instancetype) initWithClient:(id<CISClientProtocol>)client
                  systemFactory:(id<CISSystemFactoryProtocol>)systemFactory
                 videoAnalytics:(CISVideoAnalyticsImpl*)videoAnalytics;

- (BOOL) isAdAnalytics;

- (BOOL) isVideoAnalytics;

@end

NS_ASSUME_NONNULL_END
