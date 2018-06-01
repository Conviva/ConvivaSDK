//
//  HttpClient.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISLogger.h"
#import "CISHTTPProtocol.h"
#import "CISSystemSettings.h"

@interface CISHttpClient : NSObject

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithLogger:(CISLogger *)logger cishttpProtocol:(id<CISHTTPProtocol>)cisHTTPProtocol cisSystemSetting:(CISSystemSettings *)systemSetting NS_DESIGNATED_INITIALIZER;
//-(void)assignCallbackDelegate:(id)callbackDelegate;
//-(void)assignCallbackSelector:(SEL)callbackSelector;
//- (void)postData:(NSString *)content toUrl:(NSString *)url httpMethod:(NSString *)httpMethod  contentType:(NSString *)contentType;
//- (void)getData:(NSString *)content toUrl:(NSString *)url httpMethod:(NSString *)httpMethod  contentType:(NSString *)contentType;
- (void)postString:(NSString *)postString
             toURL:(NSString *)URL
 completionHandler:(void (^)(NSString *responseString, NSString *errorMsg))completionHandler;

-(void)cleanUp;
@end

