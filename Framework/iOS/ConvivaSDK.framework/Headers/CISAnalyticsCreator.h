//
//  CISAnalyticsCreator.h
//
//  Created by Butchi peddi on 13/02/20.
//  Copyright 2020 Conviva Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISClientSettingProtocol.h"
#import "CISSystemFactoryProtocol.h"
#import "CISAnalytics.h"
#import "CISClientProtocol.h"

@interface CISAnalyticsCreator : NSObject

/**
* Initialize Conviva Analytics SDK with the required settings.
* @param customerKey Customer Key.
* @return CISAnalytics instance.
*/
+ (CISAnalytics) createWithCustomerKey:(NSString *)customerKey;

/**
* Initialize Conviva Analytics SDK with the required settings.
* @param customerKey Customer Key.
* @param settings dictionary. Please refer "Settings" section decfined in CSSConstants.h for possible values.
* @return CISAnalytics instance.
*/
+ (CISAnalytics) createWithCustomerKey:(NSString *)customerKey
                              settings:(NSDictionary*)settings;

/**
* Initialize Conviva Analytics SDK with the required settings.
* @param customerKey Customer Key.
* @param systemInterface Object complies to CISSystemInterfaceProtocol .
* @return CISAnalytics instance.
*/
+ (CISAnalytics) createWithCustomerKey:(NSString *)customerKey
                         systemInterface:(id<CISSystemInterfaceProtocol>)systemInterface;

/**
* Initialize Conviva Analytics SDK with the required settings.
* @param customerKey Customer Key.
* @param settings dictionary. Please refer "Settings" section decfined in CSSConstants.h for possible values.
* @param systemInterface Object complies to CISSystemInterfaceProtocol.
* @return CISAnalytics instance.
*/
+ (CISAnalytics) createWithCustomerKey:(NSString *)customerKey
                              settings:(NSDictionary*)settings
                         systemInterface:(id<CISSystemInterfaceProtocol>)systemInterface;

/**
* Initialize Conviva Analytics SDK with the client object. This method is useful for backward compatability. Customer who already integrated EI and wanted to
* integrate AI using this new api, shall use this api.
* @param client Object conforms to CISClientProtocol.
* @return CISAnalytics instance.
*/
+ (CISAnalytics) createWithExistingClient:(id<CISClientProtocol>)client;

@end
