//
//  CISSessionFactory.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 29/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISClient.h"
#import "CISClientSetting.h"
#import "CISConfig.h"
#import "CISContentMetadata.h"
#import "CISNetworkUtil.h"

@class CISSystemFactory,CISSession;

@interface CISSessionFactory : NSObject

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithCISClient:(CISClient *)client cisClientSetting:(CISClientSetting *)clientSetting CISConfig:(CISConfig *)config CISSystemFactory :(CISSystemFactory *)systemFactory networkUtil:(CISNetworkUtil *)networkUtil NS_DESIGNATED_INITIALIZER;
-(void)cleanUp;
-(int)makeVideoSession:(CISContentMetadata *)cisContentMetadata;
-(void)cleanUpSessionWithID:(int)sessionID  removeFromArray:(BOOL)remove;
-(CISSession *)getSession:(int) sessionKey;
-(CISSession *)getVideoSession:(int) sessionKey;
-(int)makeGlobalSession:(CISContentMetadata *)cisContentMetadata;
-(int)makeAdSession:(CISContentMetadata *)cisContentMetadata contentSessionKey:(int)contentSessionKey;
@end
