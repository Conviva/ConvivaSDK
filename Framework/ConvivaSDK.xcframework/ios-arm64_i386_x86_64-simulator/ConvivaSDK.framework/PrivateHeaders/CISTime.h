//
//  Time.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISTimeProtocol.h"

@interface CISTime : NSObject

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithTimeProtocol:(id<CISTimeProtocol>)timeProtocol NS_DESIGNATED_INITIALIZER;
-(NSTimeInterval)current;
@end
