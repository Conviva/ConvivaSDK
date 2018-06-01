//
//  Client.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISClientSetting.h"
#import "CISContentMetadata.h"
#import "CISClientProtocol.h"
#import "CISConstants.h"

@class CISSystemFactory,CISPlayerStateManager;

@interface CISClient : NSObject<CISClientProtocol>

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithClientSettings:(CISClientSetting *)settings factory:(CISSystemFactory *)factory error:(NSError**)error NS_DESIGNATED_INITIALIZER;
+(NSString *)getDeviceType:(DeviceType)deviceType;
-(int)getID;

@end
