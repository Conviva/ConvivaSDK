//
//  ClientSetting.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISClientSettingProtocol.h"

FOUNDATION_EXPORT NSString *const CONVIVA_FINGER_PRINT_PREFIX;
FOUNDATION_EXPORT NSString *const CONVIVA_AD_IDENTIFIER;
FOUNDATION_EXPORT NSString *const CONVIVA_VENDOR_IDENTIFIER;
FOUNDATION_EXPORT NSString *const DEFAULT_IPV4_PROD_GATEWAY_HOST;
FOUNDATION_EXPORT NSString *const DEFAULT_IPV6_PROD_GATEWAY_HOST;
FOUNDATION_EXPORT NSString *const DEFAULT_IPV4_DEV_GATEWAY_HOST;
FOUNDATION_EXPORT NSString *const DEFAULT_IPV6_DEV_GATEWAY_HOST;

@interface CISClientSetting : NSObject<CISClientSettingProtocol>

@property(nonatomic, assign, readonly) NSUInteger cismaxHeartbeatInfos; // maximum length of the hbinfos array
@property(nonatomic, assign, readonly) BOOL cdnIpSetManually; // Whether CDN IP set manually (or) not

/**
 * The IPV4 URL of the Conviva platform to report data to.
 * Default value is highly recommended in production environments.
 */
@property(copy, nonatomic) NSString *ipv4GatewayUrl;

/**
 * The IPV6 URL of the Conviva platform to report data to.
 * Default value is highly recommended in production environments.
 */
@property(copy, nonatomic) NSString *ipv6GatewayUrl;

@property(nonatomic, assign) BOOL enableConsoleLogs;

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithCustomerKey:(NSString *)CustomerKey error:(NSError **)error NS_DESIGNATED_INITIALIZER;
-(void)sanitize;
- (NSString *)updateGatewayURLError;
-(void)updateMaxHeartbeatInfos:(NSNumber *)newValue;


- (NSArray *)getSupportedUniqueIdentifiers;
- (NSDictionary *)getFingerPrintUserPreferenceForDataCollection;
- (NSDictionary *)getFingerPrintUserPreferenceForDataDeletion;

- (BOOL)canReportCdn;
- (void)setReportCdn:(BOOL)reportCdn;
- (void)updateCdnIpSetManually:(BOOL)newValue;

@end
