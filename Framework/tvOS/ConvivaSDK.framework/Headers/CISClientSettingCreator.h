//
//  CISSystemSettingCreator.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 25/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISClientSettingProtocol.h"

/**  
 * Helper class required for creating a class instance conforming to protocol CISClientSettingProtocol.<br>
 * This is required while creating a client instance.
 */

@interface CISClientSettingCreator : NSObject
/**
 * Initializer for Client Setting.
 * @param CustomerKey The Conviva customer key for the Conviva account data should be transferred to.
 * @param error The error that can be used to check error if creating client setting encountered any error.
 * @return CISClientSettingProtocol instance.
 */
+(id<CISClientSettingProtocol>)createWithCustomerKey:(NSString *)CustomerKey error:(NSError **)error;

@end
