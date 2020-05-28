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

FOUNDATION_EXPORT NSString *const CIS_OS_TYPE;
FOUNDATION_EXPORT NSString *const CIS_OPERATING_SYSTEM_VERSION ;
FOUNDATION_EXPORT NSString *const CIS_DEVICE_BRAND;
FOUNDATION_EXPORT NSString *const CIS_DEVICE_MANUFACTURER;
FOUNDATION_EXPORT NSString *const CIS_DEVICE_MODEL;
FOUNDATION_EXPORT NSString *const CIS_DEVICE_TYPE;
FOUNDATION_EXPORT NSString *const CIS_FRAMEWORK_NAME;
FOUNDATION_EXPORT NSString *const CIS_FRAMEWORK_VERSION;
FOUNDATION_EXPORT NSString *const CIS_PLATFORM_NAME;
FOUNDATION_EXPORT NSString *const CIS_PLATFORM_VERSION;

@interface CISSystemMetadata : NSObject

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithMetadataProtocol:(id<CISMetadataProtocol>)metadataProtocol cisLogger:(CISLogger *)logger exceptionCatcher:(CISExceptionCatcher *)exceptionCatcher NS_DESIGNATED_INITIALIZER;
-(void)cleanUp;
- (NSMutableDictionary *)retrive;

@end
