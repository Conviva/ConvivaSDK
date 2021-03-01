//
//  IOSHttpInterface.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISHTTPProtocol.h"

/**
 * Conviva provided helper class which implements CISHTTPProtocol required methods.<br>
 * The application can implement its own CISHTTPProtocol conforming class for creating CISSystemInterfaceCreator while creating a client.
 */
@interface IOSHttpInterface : NSObject<CISHTTPProtocol>

@end
