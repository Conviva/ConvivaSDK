//
//  CISSystemInterfaceCreator.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 02/05/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISSystemInterfaceProtocol.h"
/**
 * Used by the Conviva library to access system information and utilities.<br>
 * This class helps in creating a CISSystemInterfaceProtocol conforming class instance.<br>
 * This class contains instance of classes implementing CISHTTPProtocol, CISTimeProtocol, CISTimerProtocol, CISLoggingProtocol,
 *  CISMetadataProtocol, CISStorageProtocol protocols required by the Conviva iOS SDK.
 *
 */
@interface CISSystemInterfaceCreator : NSObject
/**
 * CISSystemInterfaceProtocol Initializer
 * used by the Conviva library to access system information and utilities.
 * @param TimeProtocol The CISTimeProtocol to use in this factory.
 * @param TimerProtocol The CISTimerProtocol to use in this factory.
 * @param HttpProtocol The CISHTTPProtocol to use in this factory.
 * @param StorageProtocol The CISStorageProtocol to use in this factory.
 * @param MetadataProtocol The CISMetadataProtocol to use in this factory.
 * @param LoggingProtocol The CISLoggingProtocol to use in this factory.
 */

+(id<CISSystemInterfaceProtocol>)createWithHttpProtocol:(id<CISHTTPProtocol>)HttpProtocol timeProtocol:(id<CISTimeProtocol>)TimeProtocol timerProtocol:(id<CISTimerProtocol>)TimerProtocol loggingProtocol:(id<CISLoggingProtocol>)LoggingProtocol metadataProtocol:(id<CISMetadataProtocol>)MetadataProtocol storageProtocol:(id<CISStorageProtocol>)StorageProtocol;
@end
