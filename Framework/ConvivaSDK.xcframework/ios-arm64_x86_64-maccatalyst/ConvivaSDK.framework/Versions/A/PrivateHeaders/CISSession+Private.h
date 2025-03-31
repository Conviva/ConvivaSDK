//
//  CISSession+Private.h
//  Pods
//
//  Created by Butchi Peddi on 12/03/25.
//

#import "CISSession.h"

NS_ASSUME_NONNULL_BEGIN

@interface CISSession (Private)

- (void)sendUrgentHBForTest:(NSNotification *)notification;

- (void)sendHeartBeatWithDelay;

-(void)createUrgentHB:(double)delay;

- (void)sendPeriodicHb;

- (void)restartHBTimer;

- (void) cancelHBTimer;

- (void) cleanUpUrgentHBTimer;

- (void) logMessage:(NSString*)msg;

- (BOOL) isSessionCleanedUp;

- (BOOL) handleAdSessionModeResponse:(NSDictionary*)cfgDictionary;

- (NSTimeInterval) getHBIntervalFromSettings;

- (CISAdSessionMode) getAdSessionMode;

- (void) logAdSessionMode;

- (CISConfig*) getClientConfig;

@end

NS_ASSUME_NONNULL_END
