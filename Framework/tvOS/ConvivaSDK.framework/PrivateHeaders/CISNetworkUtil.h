//
//  CISNetworkUtil.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 25/07/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISLogger.h"
#import "CISInternalConstant.h"

FOUNDATION_EXPORT NSString *const NETWORK_TYPEWIFI;

@interface CISNetworkUtil : NSObject
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithlogger:(CISLogger *)logger NS_DESIGNATED_INITIALIZER;
- (void)cleanup;

- (void)setNetworkConnectionType:(NSString *)networkConnectionType;
- (void)setNetworkLinkEncryptionType:(NSString *)networkLinkEncryptionType;
- (void)setNetworkSignalStrength:(double)networkSignalStrength;
//  DE-2572 Remove SSID Support since this is a PII
//- (void)setWifiSSID:(NSString *)ssidValue;

- (NSString *)getNetworkConnectionType;
- (NSString *)getNetworkLinkEncryptionType;
- (double)getNetworkSignalStrength;
//  DE-2572 Remove SSID Support since this is a PII
//- (NSString *)getWifiSSID;

- (BOOL)isWifiConnAvailable;

@end
