//
//  ConvivaSettingsUtils.m
//  Pods
//
//  Created by Butchi peddi on 29/04/20.
//

#import <Foundation/Foundation.h>
#import "CISClientSetting.h"

@interface ConvivaSettingsUtils : NSObject

+ (CISClientSetting *)createClientSettings:(NSDictionary *)settings customerKey:(NSString*)customerKey;
+(NSString*)getDefaultGatewayUrlUsingCustomerKey:(NSString *)customerKey;

@end
