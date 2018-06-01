//
//  CISClientSettingProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 25/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
/** 
 * Settings for the client instance.
 * This class handles setting for client required parameters Customer Key, Heartbeat Interval & Gateway URL.<br>
 * The instance of this class is created while creating an instance of class conforming to CISClientSettingProtocol.
 */
@protocol CISClientSettingProtocol <NSObject>
/**
 * Required setter for the Conviva account data will be reported to.
 * @param customerKey The Conviva customer key for the Conviva account data should be transferred to.
 */
-(void)setCustomerKey:(NSString *)customerKey;

/**
 * Setter for the time interval at which the Conviva will send available data to the Conviva platform. In seconds,
 * the default value is highly recommended in production environments.
 * @param heartbeatInterval The time interval for reporting Conviva heartbeat.
 */
-(void)setHeartbeatInterval:(NSTimeInterval)heartbeatInterval;

/**
 * Setter for the URL of the Conviva platform to report data to.
 * The default value is highly recommended in production environments.
 * @param gatewayUrl The URL of the Conviva platform to report data to.
 */
-(void)setGatewayUrl:(NSString *)gatewayUrl;

/**
 * Getter for Conviva account customer key.
 * @return Customer Key.
 */
-(NSString *)getCustomerKey;

/**
 * Getter for heartbeat interval.
 * @return The time interval for reporting Conviva heartbeat.
 */
-(NSTimeInterval)getHeartbeatInterval;

/**
 * Getter for gateway URL.
 * @return The URL of the Conviva platform to report data to.
 */
-(NSString *)getGatewayUrl;

@end