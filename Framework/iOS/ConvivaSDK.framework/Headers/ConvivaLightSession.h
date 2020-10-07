//
//  Copyright (c) 2012 Conviva. All rights reserved.
//  Created by Saiguang Che (saiguang@conviva.com).
//
//  Refer to http://developer.conviva.com/integration/ios for integration help.
//

#import "ConvivaContentInfo.h"
#import <AVFoundation/AVFoundation.h>
#import "CISConstants.h"

// Capabilities
#define CAP_SET_INI_BITRATE 1
#define CAP_SET_INI_RESOURCE 2
#define CAP_SET_BITRATE_RANGE 4
#define CAP_SET_MULTI_BITRATE_RANGE 8
#define CAP_SET_MIDSTREAM_BITRATE 16
#define CAP_SET_MIDSTREAM_RESOURCE 32

@interface ConvivaLightSession : NSObject

/// @brief Cleanup session. Should be called when a video session is over.
///
/// Releases the reference to monitored streamer. Session can be safely released
/// after this call
- (void)cleanup;

/// Send an custom event pertaining to the session
- (void)sendEvent:(NSString *)name withAttributes:(NSDictionary *)attributes;

/// This API is depecated
/// use the API updateContentMetadata:(ConvivaContentInfo *)newcontentInfo
- (void)setContentLength:(NSInteger)contentLength DEPRECATED_ATTRIBUTE;

/// Notify that ad has started
- (void)adStart;

/// Notify that ad has started with type of ad stream and player type etc.
- (void)adStart:(AdStream)adStream adPlayer:(AdPlayer)adPlayer adPosition:(AdPosition)adPosition;

/// Notify that ad has ended
- (void)adEnd;

/// This API is depecated
/// use the API updateContentMetadata:(ConvivaContentInfo *)newcontentInfo
- (void)setCdnNameOrResource:(NSString *)cdnNameOrResource DEPRECATED_ATTRIBUTE;

/// Report a fatal error and use specified error message
- (void)reportError:(NSString *)errorMsg DEPRECATED_ATTRIBUTE;

/// Report a fatal and non fatal error and use specified error message
- (void)reportError:(NSString *)errorMessage errorType:(ErrorSeverity)severity;

/// Attach streamer to specified streamer */
- (void)attachStreamer:(id)streamer;

/// @brief Pause session monitoring such that it can be resumed later
/// @note The existing streamer is detached from the session.
/// @see attachStreamer()
- (void)pauseMonitor;

/// @brief Set the current bitrate
- (void)setBitrate:(int)bitrateKbps;

/// @brief Set the CDN Server IP
- (void)setCDNServerIP:(NSString *)cdnServerIP;

/// @brief Set the Link Encryption
- (void)setLinkEncryption:(NSString*)newLinkEncryption;

/// @brief Set the Signal Strength
- (void)setSignalStrength:(double)newSignalStrength;

/// @brief Set the Connection Type
- (void)setConnectionType:(NSString *)newConnectionType;

/// @brief Set Player seek Start
- (void)setSeekStart:(NSInteger)seekToPosition;

/// @brief Set Player seek End
- (void)setSeekEnd:(NSInteger)seekPosition;

/// This API is depecated
/// use the API updateContentMetadata:(ConvivaContentInfo *)newcontentInfo
- (void)updateStreamUrl:(NSString *)newStreamUrl DEPRECATED_ATTRIBUTE;

/// @brief update content metadata
- (void)updateContentMetadata:(ConvivaContentInfo *)newcontentInfo;

/** Reserved method. Do not use. */
- (int) currentSessionType;

- (int)sessionID;

@end
