//
//  CISAnalyticsCreator.h
//
//  Created by Butchi peddi on 13/02/20.
//  Copyright 2020 Conviva Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISAnalytics.h"

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


@end
