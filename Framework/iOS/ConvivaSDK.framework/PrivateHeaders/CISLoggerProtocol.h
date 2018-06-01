//
//  CISLoggerProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 15/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import "CISSystemSettings.h"
/*
 * Used by the Conviva library to log messages to debug console.
 */
@protocol CISLoggerProtocol <NSObject>
@required
/**
 * Associates a module name with this Logger.
 * @param moduleName The module name to use for this logger.
 */
-(void)setModuleName:(NSString *)moduleName;

/**
 * Associates a session ID with this Logger.
 * @param sessionId The session ID to use for this logger.
 */
-(void)setSessionId:(int)sessionId;

/**
 * Logs a message to the console at DEBUG level.
 * @param message The message to log at DEBUG level.
 */
-(void)debug:(NSString *)message;

/**
 * Logs a message to the console at INFO level.
 * @param message The message to log at INFO level.
 */
-(void)info:(NSString *)message;

/**
 * Logs a message to the console at WARNING level.
 * @param message The message to log at WARNING level.
 */
-(void)warning:(NSString *)message;

/**
 * Logs a message to the console at ERROR level.
 * @param message The message to log at ERROR level.
 */
-(void)error:(NSString *)message;

@optional
/*
 * Used only for for debugging when we want to log to console
 * but not log to buffer
 * @praram  NSString logger message
 * @param LogLevel Log level
 */
-(void)consoleLog:(NSString *)message logLevel:(LogLevel)LogLevel;

@end
