//
//  Storage.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISLogger.h"
#import "CISSystemSettings.h"
#import "CISStorageProtocol.h"
#import "CISCallbackWithTimeout.h"

@interface CISStorage : NSObject

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithLogger:(CISLogger *) cislogger  storage:(id<CISStorageProtocol>)cisStorage timeOut:(CISCallbackWithTimeout *)callBackTimeOut setting:(CISSystemSettings *)cisSystemSettings NS_DESIGNATED_INITIALIZER;
-(void)load:(NSString *)keyToLoad completion:(void(^)(BOOL responseStatus,NSString* responseString))callback;
-(void)save:(NSString *)keyToSave data:(NSString *)storeValue completion:(void(^)(BOOL responseStatus,NSString* responseString))callback;
-(void)cleanUp;
@end
