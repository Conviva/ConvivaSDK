//
//  IOSLoggingInterface.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISLoggingProtocol.h"

/**
 * Conviva provided helper class which implements CISLoggingProtocol required methods.<br>
 * The application can implement its own CISLoggingProtocol conforming class for creating CISSystemInterfaceCreator while creating a client.
 */

@interface IOSLoggingInterface : NSObject<CISLoggingProtocol>

@end
