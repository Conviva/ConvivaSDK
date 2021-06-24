//
//  CISConfig.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 15/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISStorage.h"
#import "CISLogger.h"
#import "CISJSONOperator.h"
#import "CISInternalConstant.h"

FOUNDATION_EXPORT NSString *const SEND_LOG; //  sendLogs
//FOUNDATION_EXPORT NSString *const CLIENT_ID; //  clientId

@interface CISConfig : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithLogger:(CISLogger *)cisLogger storage:(CISStorage *)cisStorage json:(CISJSONOperator *)cisJsonOperator NS_DESIGNATED_INITIALIZER;
-(void)cleanUp;
-(void)load;
-(BOOL)isReady;
-(void)registerCallback:(void (^)(void))callback;
-(id)getConfigValue:(NSString *) key;
-(void)setConfigValue:(NSString *)key value:(id)value;

-(id)getClientIdFromKeyChain;
-(void)setClientIdInKeyChain:(NSString *)newClientId;

-(void)save;
@end
