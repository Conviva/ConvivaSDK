//
//  PlayerState.h
//  iOSClient
//
//  Created by Saiguang Che on 8/14/12.
//  Copyright (c) 2012 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>

extern const int CIS_STOPPED;
extern const int CIS_PLAYING;
extern const int CIS_BUFFERING;
extern const int CIS_PAUSED;
extern const int CIS_NOTMONITORED;
extern const int CIS_UNKNOWN;

@interface ConvivaPlayerState : NSObject

+ (NSString *)stateString:(int)state;

@end
