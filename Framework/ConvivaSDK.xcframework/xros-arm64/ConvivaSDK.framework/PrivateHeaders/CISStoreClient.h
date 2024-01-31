//
//  CISStoreClient.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 15/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISSession.h"

@interface CISStoreClient : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithSession:(CISSession *)client sessionID:(int)externalSessionID NS_DESIGNATED_INITIALIZER;
-(CISSession *)getStoredCISClient;
-(int)getStoredExternalSessionID;
-(void)cleanUp;
@end
