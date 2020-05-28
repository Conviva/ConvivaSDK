//
//  CISStreamAnalyticsImpl.m
//  Pods
//
//  Created by Butchi peddi on 20/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISClientProtocol.h"
#import "CISSystemFactoryProtocol.h"

#import "CISStreamAnalyticsImpl.h"

NS_ASSUME_NONNULL_BEGIN

@interface CISStreamAnalyticsImpl (Private)

//- (void) reportPlayerState:(PlayerState)playerState;

- (void) reportSeekStarted:(int64_t)startPosition;

- (void) reportSeekEnd:(int64_t)endPosition;

- (void) reportPlayerPlayHeadTime:(int64_t)playHeadTime;

- (void) reportPlayerBufferLength:(int64_t)bufferLength;

- (void) reportPlayerBitrate:(NSInteger)bitrate;

- (void) reportPlayerAverageBitrate:(NSInteger)averageBitrate;

- (void) reportPlaybackResolution:(NSInteger)width height:(NSInteger)height;

- (void) reportCustomMetric:(NSString*)key value:(NSDictionary*)attributes;

- (void) reportPlayerDropFrameCount:(int)droppedFrameCount;

- (void) reportPlayerRenderedFrameRate:(int)renderedFrameRate;

- (void) reportPlayerEncodedFrameRate:(int)encodedFrameRate;

- (void) reportCDNinfo:(NSString*)cdnInfo resource:(NSString*)resource;

- (void) reportSignalStrength:(double)signalStrength;

- (void) reportLinkEncryption:(NSString *)linkEncryptionType;

- (void) reportConnType:(NSString *)connType;

@end

NS_ASSUME_NONNULL_END
