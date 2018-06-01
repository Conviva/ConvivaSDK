//
//  SystemSettings.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Log level setting for the SDK client.
 */
typedef NS_ENUM(NSUInteger,LogLevel) {
    /** Will display all log messages. */
    LOGLEVEL_DEBUG = 0,
    /** Will only display warning and error log messages. */
    LOGLEVEL_INFO,
    /** Will only display error log messages. */
    LOGLEVEL_WARNING,
    /** Will display all log messages except debugging messages. */
    LOGLEVEL_ERROR,
    /** Will not display any log messages. */
    LOGLEVEL_NONE
};

/**
 * Encapsulates all Conviva system settings.<br>
 * This is required while creating a client instance and helpful in setting logLevel, storageTimeout & httpTimeout.
 */
@interface CISSystemSettings : NSObject
/**
 * The level of log messages to print in the console log.<br>
 * We recommend using log level warning during development and lowering to debug when more information is required to troubleshoot specific issues.
 */
@property(nonatomic) LogLevel logLevel;

/**
 * Whether to allow or catch runtime exceptions.<br>
 * The default value of false is highly recommended in a production environment.
 * The default value of true is recommended during development for easier troubleshooting.
 */
@property(nonatomic,assign) BOOL allowUncaughtExceptions;

/**
 * How long the Conviva client will wait for a response when attempting to access device storage before considering that attempt a failure in seconds, the default value will work for the overwhelming majority of devices.
 */
@property(nonatomic,assign) NSTimeInterval storageTimeout;

/**
 * How long the Conviva client will wait for a response when attempting to access device storage before considering that attempt a failure in seconds,<br>
 * the default value will work for the overwhelming majority of devices.
 */
@property(nonatomic,assign) NSTimeInterval httpTimeout;



@end
