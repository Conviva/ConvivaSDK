//
//  IOSTimerInterface.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISTimerProtocol.h"

/**
 * Conviva provided helper class which implements CISTimerProtocol required methods.<br>
 * The application can implement its own CISTimerProtocol conforming class for creating CISSystemInterfaceCreator while creating a client.
 */

@interface IOSTimerInterface : NSObject<CISTimerProtocol>

@end
