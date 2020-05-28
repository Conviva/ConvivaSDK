//
//  CISUtility.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 14/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT int const CIS_SIGNAL_STRENGTH_INVALID_VALUE;

@interface CISUtility : NSObject

+(int) NumberToUnsignedInt:(NSNumber *)number result:(int)defaultResult;
+(BOOL) isValidString:(NSString *)string;
+(double)timeBetweenTimeEarlier:(double)timeEarlier andTimeLater:(double)timeLater;
+ (dispatch_queue_t)cisSharedQueue;
+ (BOOL)isCISSharedQueue;
+ (void)dispatchAsyncToCISSharedQueue:(dispatch_block_t)block;
+ (void)optionalDispatchAsyncToCISSharedQueue:(dispatch_block_t)block;
+ (void)sanitiseTag:(NSMutableDictionary *)custom;
+ (NSString *)describeError:(NSError *)error;

+ (id)getClientId;
+ (void)setClientId:(NSString *)newClientId;
@end

