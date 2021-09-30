//
//  PlayerState.h
//  iOSClient
//
//  Created by Saiguang Che on 8/14/12.
//  Copyright (c) 2012 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>

extern const int CIS_STOPPED DEPRECATED_ATTRIBUTE;
extern const int CIS_PLAYING DEPRECATED_ATTRIBUTE;
extern const int CIS_BUFFERING DEPRECATED_ATTRIBUTE;
extern const int CIS_PAUSED DEPRECATED_ATTRIBUTE;
extern const int CIS_NOTMONITORED DEPRECATED_ATTRIBUTE;
extern const int CIS_UNKNOWN DEPRECATED_ATTRIBUTE;

DEPRECATED_MSG_ATTRIBUTE("This class will be removed soon, please migrate to Simplified SDK APIs. Refer to https://community.conviva.com/site/one-sensor/sensors/ios/index_one_sensor.gsp")
@interface ConvivaPlayerState : NSObject

+ (NSString *)stateString:(int)state DEPRECATED_ATTRIBUTE;

@end
