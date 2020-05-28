//
//  CISInternalConstant.h
//  iOSConvivaSDK
//
//  Copyright © 2017 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Internal do not use
 */
FOUNDATION_EXPORT NSString *const CIS_NETWORK_UPDATE_NOTIFICATION_CONNECTION_TYPE;

/**
 * Internal do not use
 */
FOUNDATION_EXPORT NSString *const CIS_NETWORK_UPDATE_NOTIFICATION_SIGNAL_STRENGTH;

/**
 * Internal do not use
 */
FOUNDATION_EXPORT NSString *const CIS_NETWORK_UPDATE_NOTIFICATION_LINK_ENCRYPTION;

/**
 * Internal do not use
 */
FOUNDATION_EXPORT NSString *const CIS_NETWORK_UPDATE_NOTIFICATION_SSID;

/**
 * Internal do not use
 */
FOUNDATION_EXPORT NSString *const CIS_CLID_AVILABLE;


FOUNDATION_EXPORT NSString *const DEFAULT_CLIENT_ID;

FOUNDATION_EXPORT NSString *const CLIENT_ID;

/**
 * Possible types of sessions.
 */
typedef NS_ENUM(NSInteger,SessionType){
    /** Video Session. */
    VIDEO = 0,
    /** Global Session. */
    GLOBAL,
    /** Ad Session. */
    AD
};

@interface CISInternalConstant : NSObject

@end
