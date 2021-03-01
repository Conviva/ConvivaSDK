//
//  CISTimeUtil.h
//  Pods
//
//  Created by Sandeep Madineni on 28/05/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
//DE-5261
@interface CISTimeUtil : NSObject

+ (NSTimeInterval)getEpochTimeMs;

+ (NSTimeInterval)getEpochTimeSec;

+ (NSTimeInterval)timeBetweenTimeEarlier:(NSTimeInterval)timeEarlier andTimeLater:(NSTimeInterval)timeLater;

+ (void)TESTAPI_setNextEpochTimeMs:(NSTimeInterval)epochTimeMs;

@end

NS_ASSUME_NONNULL_END
