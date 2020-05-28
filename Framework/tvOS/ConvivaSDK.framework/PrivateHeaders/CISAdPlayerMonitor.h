//
//  CISAnalyticsImpl.m
//  Pods
//
//  Created by Butchi peddi on 07/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISPlayerMonitor.h"
#import "CISBasePlayerMonitor.h"

@interface CISAdPlayerMonitor : CISBasePlayerMonitor

-(instancetype) initWithClient:(CISClient*)client
                 systemFactory:(id<CISSystemFactoryProtocol>)systemFactory
                        logger:(CISLogger*)logger;

- (void) createSession;

- (void) cleanupPlayerMonitor;

- (void) setContentSessionID:(int)sessionID;

@end
