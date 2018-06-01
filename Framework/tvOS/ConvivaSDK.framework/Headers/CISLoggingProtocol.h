//
//  CISLoggingProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 10/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import "CISSystemSettings.h"

/**
 * Class conforming to this will be responsible for implementing required methods for logging,
 * this is used by the Conviva library to log.
 */
@protocol CISLoggingProtocol <NSObject>
@required
/**
 * Console logging.
 * Will be called frequently if logging is enabled.
 * @param message The message to be logged to the console.
 * @param logLevel The log level for that message.
 */
-(void)consoleLog:(NSString *)message logLevel:(LogLevel)logLevel;

/**
 * Notification that Conviva no longer needs this LoggingProtocol.
 */
-(void)cleanUp;
@end
