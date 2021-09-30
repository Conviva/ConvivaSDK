//
//  ConvivaLightSession+Ad.h
//
//  Copyright © 2018 Conviva. All rights reserved.
//
#import "ConvivaPlayerState.h"
#import "ConvivaLightSession.h"

DEPRECATED_MSG_ATTRIBUTE("This class will be removed soon, please migrate to Simplified SDK APIs. Refer to https://community.conviva.com/site/one-sensor/sensors/ios/index_one_sensor.gsp")
@interface ConvivaLightSession ()

typedef NS_ENUM(NSUInteger, ConvivaAdPlayerState) {
    /** Report this state when you can confirm that the player is currently inactive/idle. */
    CONVIVA_AD_STOPPED = 1,
    /** Report this state when you can confirm that the player is actively rendering video content for the viewer.<br>
     This should never be reported for unavailable/blocked content. */
    CONVIVA_AD_PLAYING  = 3,
    /** Report this state when you can confirm that the player is stalled due to lack of video data in the buffer.<br>
     It may show a spinner or it may simply present a freeze frame. */
    CONVIVA_AD_BUFFERING  = 6,
    /** Report this state when you can confirm that the player is paused, generally upon viewer request. */
    CONVIVA_AD_PAUSED = 12,
    /** Report this state when no other recognized Conviva player states apply. */
    CONVIVA_AD_NOT_MONITORED = 98,
    /** Reserved state. Do not use. */
    CONVIVA_AD_UNKNOWN = 100
} DEPRECATED_ATTRIBUTE;

/// @brief Set the ad player state
- (void) setAdPlayerState: (ConvivaAdPlayerState) playerState DEPRECATED_ATTRIBUTE;

/// @brief Set the ad player name
- (void) setAdPlayerName: (NSString *) playerName DEPRECATED_ATTRIBUTE;

/// @brief Set the ad player version
- (void) setAdPlayerVersion: (NSString *) playerVersion DEPRECATED_ATTRIBUTE;

/// @brief Set the ad player width & height
- (void) setAdVideoResolutionWidth: (NSInteger) width andHeight: (NSInteger) height DEPRECATED_ATTRIBUTE;

/// @brief Set the current ad player instance buffer length  in milliseconds
- (void) setAdPlayHeadTime: (NSInteger) pht DEPRECATED_ATTRIBUTE;

/// @brief Set the current ad player instance buffer length  in milliseconds
- (void) setAdBufferLength: (NSInteger) bufferLength DEPRECATED_ATTRIBUTE;

@end
