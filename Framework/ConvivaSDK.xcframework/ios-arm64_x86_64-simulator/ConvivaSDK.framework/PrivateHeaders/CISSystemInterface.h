//
//  SystemInterface.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 23/02/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISSystemInterfaceProtocol.h"

#import "CISHTTPProtocol.h"
#import "CISTimeProtocol.h"
#import "CISTimerProtocol.h"
#import "CISLoggingProtocol.h"
#import "CISMetadataProtocol.h"
#import "CISStorageProtocol.h"

@interface CISSystemInterface : NSObject<CISSystemInterfaceProtocol>

@property(nonatomic,strong) id<CISHTTPProtocol> httpProtocol;
@property(nonatomic,strong) id<CISLoggingProtocol> loggingProtocol;
@property(nonatomic,strong) id<CISMetadataProtocol> metadataProtocol;
@property(nonatomic,strong) id<CISTimeProtocol> timeProtocol;
@property(nonatomic,strong) id<CISTimerProtocol> timerProtocol;
@property(nonatomic,strong) id<CISStorageProtocol> storageProtocol;


-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithProtocols:(id<CISHTTPProtocol>)HttpProtocol timeProtocol:(id<CISTimeProtocol>)TimeProtocol timerProtocol:(id<CISTimerProtocol>)TimerProtocol loggingProtocol:(id<CISLoggingProtocol>)LoggingProtocol metadataProtocol:(id<CISMetadataProtocol>)MetadataProtocol storageProtocol:(id<CISStorageProtocol>)StorageProtocol NS_DESIGNATED_INITIALIZER;

-(void)cleanUp;

@end
