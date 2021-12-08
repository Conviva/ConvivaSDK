//
//  CISSystemFactoryCreator.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 24/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISSystemFactoryProtocol.h"
#import "CISSystemInterfaceProtocol.h"
#import "CISSystemSettings.h"

/**
 * Provides access to system information and utilities according to chosen settings.<br>
 * Returns the CISSystemFactoryProtocol conforming class instance, required while creating a client instance.
 */
DEPRECATED_MSG_ATTRIBUTE("This class will be removed soon, please migrate to Simplified SDK APIs. Refer to https://community.conviva.com/site/one-sensor/sensors/ios/index_one_sensor.gsp")
@interface CISSystemFactoryCreator : NSObject

/**
 * Constructs systemFactory instance, provides access to system information and utilities according to chosen settings.
 * @param systemInterface The SystemInterface to use for this factory.
 * @param systemSetting The SystemSettingsProtocol to use for this factory.
 * @return Returns CISSystemFactoryProtocol instance.
 */

+(id<CISSystemFactoryProtocol>)createWithCISSystemInterface:(id<CISSystemInterfaceProtocol>)systemInterface setting:(CISSystemSettings *)systemSetting DEPRECATED_ATTRIBUTE;

@end
