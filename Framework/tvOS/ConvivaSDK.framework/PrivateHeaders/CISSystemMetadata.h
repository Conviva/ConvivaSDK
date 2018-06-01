//
//  CISSystemMetadata.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 05/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISLogger.h"
#import "CISMetadataProtocol.h"
#import "CISExceptionCatcher.h"

FOUNDATION_EXPORT NSString *const OS_TYPE;
FOUNDATION_EXPORT NSString *const OPERATING_SYSTEM_VERSION ;
FOUNDATION_EXPORT NSString *const DEVICE_BRAND;
FOUNDATION_EXPORT NSString *const DEVICE_MANUFACTURER;
FOUNDATION_EXPORT NSString *const DEVICE_MODEL;
FOUNDATION_EXPORT NSString *const DEVICE_TYPE;
FOUNDATION_EXPORT NSString *const FRAMEWORK_NAME;
FOUNDATION_EXPORT NSString *const FRAMEWORK_VERSION;
FOUNDATION_EXPORT NSString *const PLATFORM_NAME;
FOUNDATION_EXPORT NSString *const PLATFORM_VERSION;

@interface CISSystemMetadata : NSObject

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithMetadataProtocol:(id<CISMetadataProtocol>)metadataProtocol cisLogger:(CISLogger *)logger exceptionCatcher:(CISExceptionCatcher *)exceptionCatcher NS_DESIGNATED_INITIALIZER;
-(void)cleanUp;
- (NSMutableDictionary *)retrive;

@end
