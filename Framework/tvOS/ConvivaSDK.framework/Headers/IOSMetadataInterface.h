//
//  IOSMetadataInterface.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISMetadataProtocol.h"

/**
 * Conviva provided helper class which implements CISMetadataProtocol required methods.<br>
 * The application can implement its own CISMetadataProtocol conforming class for creating CISSystemInterfaceCreator while creating a client.
 */
@interface IOSMetadataInterface : NSObject<CISMetadataProtocol>


@end
