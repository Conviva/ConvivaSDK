//
//  CISVideoAnalyticsImpl+Private.h
//  ConvivaSDK
//
//  Created by Sandeep Madineni on 29/10/20.
//

#import "CISVideoAnalyticsImpl.h"

NS_ASSUME_NONNULL_BEGIN

@interface CISVideoAnalyticsImpl (Private)

- (BOOL) isExternalBitrateReportingEnabled;
- (BOOL) isExternalStreamUrlReportingEnabled;

@end

NS_ASSUME_NONNULL_END
