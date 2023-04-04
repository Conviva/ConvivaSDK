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
@class CISConfig;

@class CISSystemFactory,CISPlayerStateManager;

@interface CISClient : NSObject<CISClientProtocol>

@property(nonatomic, strong,readonly) CISClientSetting *cisClientSettings;
@property(nonatomic, strong,readonly) CISSystemFactory *cisSystemFactory;
@property(nonatomic, readonly) CISConfig *cisConfig;

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithClientSettings:(CISClientSetting *)settings factory:(CISSystemFactory *)factory error:(NSError**)error NS_DESIGNATED_INITIALIZER;
+(NSString *)getDeviceType:(DeviceType)deviceType;
-(int)getID;

/**
 * Returns unique client id
 */
-(NSString*)getClientId;

- (int) getSessionId:(int)sessionKey;

- (void) setLibraryVersion:(NSString*)libVersion onSession:(int)sessionKey;

-(BOOL)canAccessDeviceUniqueIdentifiers;


- (void)createIPV4IPV6GlobalSessions;

- (void)updateConnectionType:(NSString*)newConnectionType;

-(void) attachPlayer:(int) sessionKey;

-(void)detachPlayer:(int)sessionKey monitorMetrics:(BOOL) monitorMetrics;

- (int) getGlobalSessionId;
- (int) getipv4SessionId;
- (int) getipv6SessionId;

@end
