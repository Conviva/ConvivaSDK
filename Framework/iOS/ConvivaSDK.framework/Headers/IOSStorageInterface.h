//
//  IOSStorageInterface.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISStorageProtocol.h"

/**
 * Conviva provided helper class which implements CISStorageProtocol required methods.<br>
 * The application can implement its own CISStorageProtocol conforming class for creating CISSystemInterfaceCreator while creating a client.
 */
@interface IOSStorageInterface : NSObject<CISStorageProtocol>

@end
