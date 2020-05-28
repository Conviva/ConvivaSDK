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

@interface CISClientSetting : NSObject<CISClientSettingProtocol>

@property(nonatomic, assign, readonly) NSUInteger cismaxHeartbeatInfos; // maximum length of the hbinfos array
@property(nonatomic, assign, readonly) BOOL cdnIpSetManually; // Whether CDN IP set manually (or) not

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
