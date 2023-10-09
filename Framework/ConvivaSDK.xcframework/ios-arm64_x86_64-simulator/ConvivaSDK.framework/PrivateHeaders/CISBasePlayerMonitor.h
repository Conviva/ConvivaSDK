//
//  CISAnalyticsImpl.m
//  Pods
//
//  Created by Butchi peddi on 07/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISPlayerMonitor.h"
#import "CISIClientMeasureInterface.h"
#import "CISStreamerError.h"

@interface CISBasePlayerMonitor : CISPlayerMonitor


-(instancetype) initWithClient:(CISClient*) client
                 systemFactory:(id<CISSystemFactoryProtocol>)systemFactory
                        logger:(CISLogger*) logger;

- (void) updatePlayerStateManagerState;

- (void) onPlayerInfoChanged;

- (void) updateContentMetadata;
   
- (void) onMetadataInfoChanged ;

- (void) onSeekingChanged;

- (void) createSession;

- (void) updateCustomMetric:(NSString*)key value:(id)value;

- (void) endSession;

- (void) attachPlayer;

- (void) detachPlayer:(int)sessionKey metricRequired:(BOOL)metricRequired;

- (void) detach:(AdPlayer)adPlayer adType:(AdStream)adType;

- (void) attach;

- (int) getSessionId;

- (void) setSessionId:(int) sessionId;

- (void) onError;

- (void) onEvent;

#pragma mark - CISIClientMeasureInterface methods

- (NSInteger) getPHT;

- (NSInteger) getBufferLength;

- (NSInteger) getAverageFrames;

#pragma mark - End of CISIClientMeasureInterface methods

- (double) getSignalStrength;

- (void) contentAdStart:(AdPlayer)adPlayer adType:(AdStream) adType;

- (void) contentAdEnd;

- (void) contentAdBreakStart:(AdStream)adType;

- (void) contentAdBreakEnd;

- (void) onAdBreakStartInfoSet:(AdStream)adType;

- (void) onAdBreakEndInfoSet;

- (void) setRenderedFramerate;

- (void) cleanupPlayerMonitor;

@end
