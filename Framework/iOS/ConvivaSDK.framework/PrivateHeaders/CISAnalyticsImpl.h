//
//  CISAnalyticsImpl.m
//  Pods
//
//  Created by Butchi peddi on 07/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISAnalytics.h"

@class CISSystemFactory;
@interface CISAnalyticsImpl : NSObject<CISAnalyticsProtocol>

@property (copy,readonly) NSString *customerKey;

@property (strong,readonly) id<CISClientSettingProtocol> clientSettings;

@property (strong,readonly) CISSystemFactory* systemFactory;

//@property (strong,readonly) id<CISClientProtocol> client;


#pragma mark CISAnalyticsProtocol Methods

- (instancetype)init NS_UNAVAILABLE;

- (instancetype) initWithCustomerKey:(NSString *)customerKey;

- (instancetype) initWithCustomerKey:(NSString *)customerKey
                              settings:(NSDictionary*)settings;

- (instancetype) initWithCustomerKey:(NSString *)customerKey
                         systemInterface:(id<CISSystemInterfaceProtocol>)systemInterface;

- (instancetype) initWithCustomerKey:(NSString *)customerKey
                              settings:(NSDictionary*)settings
                         systemInterface:(id<CISSystemInterfaceProtocol>)systemInterface;

- (instancetype) initWithExistingClient:(id<CISClientProtocol>)client;

- (NSString*) getClientId;

- (CISVideoAnalytics) createVideoAnalytics;

- (CISVideoAnalytics) createVideoAnalytics:(NSDictionary*)options;

- (CISAdAnalytics) createAdAnalytics;

- (CISAdAnalytics) createAdAnalyticsWithVideoAnalytics:(CISVideoAnalytics) videoAnalytics;

- (void) reportAppEvent:(NSString*)event details:(NSDictionary*)details;

- (void) reportAppBackgrounded;

- (void) reportAppForegrounded;

- (void) setUserPrefsForDataCollection:(NSDictionary *)userPrefs;

- (void) setUserPrefsForDataDeletion:(NSDictionary *)userPrefs;

- (void) cleanup;


#pragma mark Private Methods

- (BOOL) initializeWithCustomerKey:(NSString*)customerKey
                          settings:(NSDictionary*)settings
                     systemInterface:(id<CISSystemInterfaceProtocol>)systemFactory;

@end
