//
//  CISSession.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 29/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISEventQueue.h"
#import "CISContentMetadata.h"
#import "CISMonitor.h"
#import "CISClient.h"
#import "CISClientSetting.h"
#import "CISConfig.h"
#import "CISInternalConstant.h"

@class CISSystemFactory;

@interface CISSession : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithSessionID:(int)sessionId cisEventQueue:(CISEventQueue *)eventQueue cisContentMetaData:(CISContentMetadata *)contentMetadata cisMonitor:(CISMonitor *)monitor cisClient:(CISClient *)client  clientSetting:(CISClientSetting *)clientSettings  cisConfig:(CISConfig *)config  cisSystemFactory:(CISSystemFactory *)systemFactory networkUtil:(CISNetworkUtil *)networkUtil sessionType:(SessionType)sessionType NS_DESIGNATED_INITIALIZER;
-(void)start;
// Fix for DE-2425
-(void)assignStartTime;
-(void)cleanUp;
-(BOOL)isVideoSession;
-(BOOL)isHintedGlobalSession;
-(BOOL)isGlobalSession;
// Fix for DE-2425
-(void)registerCLIDUpdateNotification;
-(BOOL)isAdSession;
-(void)attachPlayer:(CISPlayerStateManager *)playerStateManager;
-(void)attachPlayer;
-(void)detachPlayer:(BOOL)monitorMetrics;

-(void)adStart:(AdStream)adStream adPlayer:(AdPlayer)adPlayer adPosition:(AdPosition)adPosition;
-(void)adStart;
-(void)adEnd;
-(void)detachPlayer;

-(void)contentPreload;
-(void)contentStart;
-(void)reportError:(CISStreamerError *)error;
-(void)updateContentMetadata:(CISContentMetadata *) contentMetadata;
-(void)sendEvent:(NSString *)name  withAttributes:(NSDictionary *)attributes;
-(NSString *)getViewerID;
-(NSString *)getApplicationName;
-(StreamType)getStreamType;
-(int)getSID;
-(CISPlayerStateManager*)getAttachedPlayer;

- (void) setLibraryVersion:(NSString*)libVersion;

-(void)updateConnectionType:(NSString *)newConnectionType;

- (NSNumber*) getSessionStartTime;

- (CISContentMetadata*) getMetadata;

@end
