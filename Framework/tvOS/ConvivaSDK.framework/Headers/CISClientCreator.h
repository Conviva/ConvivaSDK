//
//  CISClientCreator.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 25/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISClientProtocol.h"
#import "CISClientSettingProtocol.h"
#import "CISSystemFactoryProtocol.h"

/**
 * Helper class required for creating a class instance conforming to protocol CISClientProtocol.<br>
 * Generally, every application will have a class instance conforming to protocol CISClientProtocol, which can manage multiple sessions.
 */

@interface CISClientCreator : NSObject
/**
 * Most applications will only need one client, created during application initialization and released during application shutdown.
 * @param settings An instance of settings representing Conviva settings to be used.
 * @param factory Factory to use for all system information and utility needs.
 * @param error The error that can be used to check error if creating client encountered any error.
 * @return Client instance.
 */
+(id<CISClientProtocol>)createWithClientSettings:(id<CISClientSettingProtocol>)settings factory:(id<CISSystemFactoryProtocol>)factory error:(NSError**)error;
@end
