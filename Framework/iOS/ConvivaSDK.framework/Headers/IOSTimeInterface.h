//
//  IOSTimeInterface.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISTimeProtocol.h"

/**
 * Conviva provided helper class which implements CISTimeProtocol required methods.<br>
 * The application can implement its own CISTimeProtocol conforming class for creating CISSystemInterfaceCreator while creating a client.
 */
@interface IOSTimeInterface : NSObject<CISTimeProtocol>

@end
