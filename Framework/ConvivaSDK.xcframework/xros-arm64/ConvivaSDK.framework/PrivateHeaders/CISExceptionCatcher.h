//
//  CISExceptionCatcher.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 28/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISLogger.h"
#import "CISSystemSettings.h"

@interface CISExceptionCatcher : NSObject
- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithLogger:(CISLogger *)logger systemSetting:(CISSystemSettings *)setting NS_DESIGNATED_INITIALIZER;
-(void)cleanUp;
@end
