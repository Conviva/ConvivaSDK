//
//  CISStreamAnalyticsImpl.m
//  Pods
//
//  Created by Butchi peddi on 20/02/20.
//

#import <Foundation/Foundation.h>
#import "CISClientProtocol.h"
#import "CISSystemFactoryProtocol.h"
#import "CISBaseAnalytics.h"
#import "CISPlayerMonitor.h"

NS_ASSUME_NONNULL_BEGIN

@interface CISStreamAnalyticsImpl : NSObject <CISBaseAnalyticsProtocol>

@property (strong,readonly) id<CISClientProtocol> client;

@property (strong,readonly) CISSystemFactory* systemFactory;

@property (strong,readonly) CISPlayerMonitor* playerMonitor;

@property( strong,readonly) CISLogger *cisLogger;

- (instancetype) initWithClient:(id<CISClientProtocol>)client
                  systemFactory:(id<CISSystemFactoryProtocol>)systemFactory
                  isAdAnalytics:(BOOL)isAdAnalytics;

#pragma mark - CISBaseAnalyticsProtocol methods

- (void) reportPlayerState:(PlayerState)playerState;

//- (void) reportPlayerEncodedFrameRate:(int) framerate;

- (int) getSessionId;

- (void) reportPlaybackMetric:(NSString*)key value:(nullable id)value;

- (void) setUpdateHandler:(UpdateHandler)updateHandler;

- (BOOL) isAdAnalytics;

- (BOOL) isVideoAnalytics;

/**
 * Terminates a monitoring session.
 * Use when playback for video content ends, fails or is cancelled by the viewer.
 */
-(void) cleanup;

@end

NS_ASSUME_NONNULL_END
