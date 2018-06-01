//
//  CISSystemInterfaceProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 02/05/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import "CISHTTPProtocol.h"
#import "CISTimeProtocol.h"
#import "CISTimerProtocol.h"
#import "CISLoggingProtocol.h"
#import "CISMetadataProtocol.h"
#import "CISStorageProtocol.h"
/**
 * Used by the Conviva library to access system information and utilities.<br>
 * This class contains instance of classes implementing CISHTTPProtocol, CISTimeProtocol, CISTimerProtocol, CISLoggingProtocol,<br>
 * CISMetadataProtocol, CISStorageProtocol protocols required by the Conviva iOS SDK.
 */
@protocol CISSystemInterfaceProtocol <NSObject>

@end
