//
//  Timer.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISLogger.h"
#import "CISTimerProtocol.h"
#import "CISExceptionCatcher.h"
#import "CISCancelProtocol.h"

@interface CISTimer : NSObject

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithLogger:(CISLogger *)logger timerProtocol:(id<CISTimerProtocol>)timerProtocol exceptionCatcher:(CISExceptionCatcher *)exceptionCatcher NS_DESIGNATED_INITIALIZER;
-(void)createOneShotTimer:(id)callBack timeOut:(NSTimeInterval)timeOutSeconds timeOutMessage:(NSString *)message;
-(void)cleanUp;
-(id<CISCancelProtocol>)createRecurringTimer:(NSTimeInterval)intervalSeconds queue:(dispatch_queue_t)queue handler:(dispatch_block_t)handler;
@end
