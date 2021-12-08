//
//  IOSSystemInterfaceFactory.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISSystemInterfaceProtocol.h"

/**
 * Default IOSSystemInterfaceFactory provided by Conviva.<br>
 * Use this to get an instance of SystemInterface.<br>
 * Alternatively, you can develop your own SystemInterface.
 */
DEPRECATED_MSG_ATTRIBUTE("This class will be removed soon, please migrate to Simplified SDK APIs. Refer to https://community.conviva.com/site/one-sensor/sensors/ios/index_one_sensor.gsp")
@interface IOSSystemInterfaceFactory : NSObject
/**
 * Builds a system interface factory for iOS/tvOS.
 * @return CISSystemInterfaceProtocol instance for iOS/tvOS.
 */
+(id<CISSystemInterfaceProtocol>)initializeWithSystemInterface DEPRECATED_ATTRIBUTE;
@end
