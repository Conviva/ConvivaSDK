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
@interface IOSSystemInterfaceFactory : NSObject
/**
 * Builds a system interface factory for iOS/tvOS.
 * @return CISSystemInterfaceProtocol instance for iOS/tvOS.
 */
+(id<CISSystemInterfaceProtocol>)initializeWithSystemInterface;
@end
