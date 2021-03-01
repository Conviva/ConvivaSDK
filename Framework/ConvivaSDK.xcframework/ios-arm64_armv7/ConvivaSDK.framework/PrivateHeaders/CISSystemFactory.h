//
//  SystemFactory.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISSystemInterface.h"
#import "CISSystemSettings.h"
#import "CISClientSetting.h"
#import "CISLogger.h"
#import "CISConfig.h"
#import "CISSessionFactory.h"
#import "CISSystemMetadata.h"
#import "CISTimer.h"
#import "CISTime.h"
#import "CISHttpClient.h"
#import "CISCWSProtocolHelper.h"
#import "CISSystemFactoryProtocol.h"
#import "CISNetworkUtil.h"


@class CISClient;

@interface CISSystemFactory : NSObject<CISSystemFactoryProtocol>

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithSystemInterface:(CISSystemInterface *)systemInterface setting:(CISSystemSettings *)systemSetting NS_DESIGNATED_INITIALIZER;
-(void) configure:(NSString*)packagename  clientSettings:(CISClientSetting *)settings;
-(CISLogger *)buildLogger;
-(CISConfig *)buildConfig;
-(CISSessionFactory *)buildSessionFactoryWithCISClient:(CISClient *)client cisClientSetting:(CISClientSetting *)clientSetting cisConfig:(CISConfig *)config networkUtil:(CISNetworkUtil *)networkUtil;
-(CISSystemMetadata *)buildSystemMetadata;
-(CISTimer *)buildTimer;
-(CISTime *)buildTime;
-(CISJSONOperator *)buildJsonOperaton;
-(CISHttpClient *)buildHttpClient;
-(CISCWSProtocolHelper *)buildProtocolHelper;
-(CISExceptionCatcher *)buildExceptionCatcher;
-(CISNetworkUtil *)buildNetworkUtil;
-(NSArray *)getLogBuffer;
- (void)cleanUp;
@end
