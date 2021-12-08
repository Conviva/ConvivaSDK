//
//  SystemSettings.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISConstants.h"

/**
 * Encapsulates all Conviva system settings.<br>
 * This is required while creating a client instance and helpful in setting logLevel, storageTimeout & httpTimeout.
 */
DEPRECATED_MSG_ATTRIBUTE("This class will be removed soon, please migrate to Simplified SDK APIs. Refer to https://community.conviva.com/site/one-sensor/sensors/ios/index_one_sensor.gsp")
@interface CISSystemSettings : NSObject
/**
 * The level of log messages to print in the console log.<br>
 * We recommend using log level warning during development and lowering to debug when more information is required to troubleshoot specific issues.
 */
@property(nonatomic) LogLevel logLevel DEPRECATED_ATTRIBUTE;

/**
 * Enable/Disable console logs.
 * Set true to enable console logs else false.  
 */
@property(nonatomic) BOOL enableConsoleLogs DEPRECATED_ATTRIBUTE;

/**
 * Whether to allow or catch runtime exceptions.<br>
 * The default value of false is highly recommended in a production environment.
 * The default value of true is recommended during development for easier troubleshooting.
 */
@property(nonatomic,assign) BOOL allowUncaughtExceptions DEPRECATED_ATTRIBUTE;

/**
 * How long the Conviva client will wait for a response when attempting to access device storage before considering that attempt a failure in seconds, the default value will work for the overwhelming majority of devices.
 */
@property(nonatomic,assign) NSTimeInterval storageTimeout DEPRECATED_ATTRIBUTE;

/**
 * How long the Conviva client will wait for a response when attempting to access device storage before considering that attempt a failure in seconds,<br>
 * the default value will work for the overwhelming majority of devices.
 */
@property(nonatomic,assign) NSTimeInterval httpTimeout DEPRECATED_ATTRIBUTE;



@end
