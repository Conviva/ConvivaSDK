//
//  CISPlayerStateManagerProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 25/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import "CISConstants.h"
#import "CISIClientMeasureInterface.h"
#import "CISContentMetadata.h"

/**
 * Helper class to store and relay pertinent video player data to Conviva.
 * Lifecycle is tied to an instance of the video player.<br>
 * Collects/Reports player's data to SDK.<br>
 * The lifecycle of the class conforming to this protocol is managed by application client instance.
 */
DEPRECATED_MSG_ATTRIBUTE("This class will be removed soon, please migrate to Simplified SDK APIs. Refer to https://community.conviva.com/site/one-sensor/sensors/ios/index_one_sensor.gsp")
@protocol CISPlayerStateManagerProtocol <NSObject>
@optional
/**
 * Returns the latest duration collected by this PlayerStateManager instance.
 * @return Latest duration collected. -1 if not available.
 */
- (NSInteger)getDuration DEPRECATED_ATTRIBUTE;

/**
 * Reports the duration of the video stream played by the related video player.
 * If you know the duration of the video stream in advance, consider setting ContentMetadata.duration instead.
 * DO NOT USE DEPRECATED
 * @param duration Stream duration.
 */
- (void)setDuration:(NSInteger)duration DEPRECATED_ATTRIBUTE;

/**
 * Returns the last player type collected by this PlayerStateManager instance.
 * @return Last player type collected. Nil if not available.
 */
- (NSString *)getPlayerType DEPRECATED_ATTRIBUTE;

/**
 * Reports the type of player monitored via the PlayerInterface instance.
 * @param plType Type of the player.
 */
- (void)setPlayerType:(NSString *)plType DEPRECATED_ATTRIBUTE;

/**
 * Returns the last player framework version collected by this PlayerStateManager instance.
 * @return Last player framework version collected. Nil if not available.
 */
- (NSString *)getPlayerVersion DEPRECATED_ATTRIBUTE;

/**
 * Reports the version of the related video player.
 * @param plVer A version of the player.
 */
- (void)setPlayerVersion:(NSString *)plVer DEPRECATED_ATTRIBUTE;


/**
 * Returns the current state of the video player monitored by the PlayerInterface instance.
 * @return The current state of the video player under monitoring.
 */
- (PlayerState)getPlayerState DEPRECATED_ATTRIBUTE;

/**
 * Reports the new player state of the related video player.
 * @param newState New player state for the video player under monitoring.
 */
- (void)setPlayerState:(PlayerState)newState DEPRECATED_ATTRIBUTE;

/**
 * Returns the last bitrate collected from the related video player.
 * @return The current known bitrate of the video player under monitoring. -1 if not available.
 */
-(NSInteger) getBitrateKbps DEPRECATED_ATTRIBUTE;

/**
 * Reports the Edge Server CDN IP Address for the video stream played.
 * @param cdnServerIP CDN server IP address.
 */
- (void)setCDNServerIP:(NSString *)cdnServerIP DEPRECATED_ATTRIBUTE;

/**
 * Reports the new bitrate of the video stream played by the related video player.
 * We recommend reporting manifest/nominal bitrates.
 * For protocols like Smooth Streaming, you may have to sum audio and video bitrates to get the total bitrate.
 * @param newBitrateKbps New player state for the video player under monitoring.
 */
-(void) setBitrateKbps:(NSInteger)newBitrateKbps DEPRECATED_ATTRIBUTE;

/**
 * Reports the new average bitrate of the video stream played by the related video player.
 * We recommend reporting manifest/average bitrates.
 * For protocols like Smooth Streaming, you may have to sum audio and video bitrates to get the total bitrate.
 * @param newAvgBitrateKbps New player state for the video player under monitoring.
 */
-(void) setAvgBitrateKbps:(NSInteger)newAvgBitrateKbps DEPRECATED_ATTRIBUTE;

/**
 * Reports an error while playing a video stream in the related video player.
 * These include networking errors, download errors, parsing errors, decoding/decrypting errors, DRM errors.
 * For best use, the error message should not include variables like user IDs and memory addresses.
 * @param errMessage The error message or error code for this error.
 * @param severity The severity of this error. See enum in CISConstant.
 */
-(void) sendError:(NSString* )errMessage errorSeverity:(ErrorSeverity)severity DEPRECATED_ATTRIBUTE;

/**
 * Setter for CISIClientMeasureInterface.
 * @param clientMeasureInterface Instance of clientMeasureInterface protocol implementing class, the player proxy classes will implement CISIClientMeasureInterface.
 */
-(void)setCISIClientMeasureInterface:(id<CISIClientMeasureInterface>)clientMeasureInterface DEPRECATED_ATTRIBUTE;

/**
 * Reports the video resolution width of video stream played by the related video player.
 * @param videoWidth Video resolution width.
*/

-(void)setVideoResolutionWidth:(NSUInteger)videoWidth DEPRECATED_ATTRIBUTE;

/**
 * Reports the video resolution height of video stream played by the related video player.
 * @param videoHeight Video resolution height.
*/

-(void)setVideoResolutionHeight:(NSUInteger)videoHeight DEPRECATED_ATTRIBUTE;

/**
 * Reports the Edge Server CDN IP Address for the video stream played.
 * DO NOT USE DEPRECATED
 * @param cdnServerIP CDN server IP address.
*/

-(void)setCDNServerIPAddress:(NSString *)cdnServerIP DEPRECATED_ATTRIBUTE ;

/**
 * Reports the signal strength of the connected network.
 * @param signalStrength Signal strength of the connected network device.
*/

-(void)setSignalStrength:(double)signalStrength DEPRECATED_ATTRIBUTE;

/**
 * Reports the link encryption type of the connected network.
 * @param linkEncryptionType Link encryption type of the network.
*/

-(void)setLinkEncryption:(NSString *)linkEncryptionType DEPRECATED_ATTRIBUTE;

/**
 * Reports the connection type of the connected network.
 * @param connectionType Connection type of the network.
 */

-(void)setConnectionType:(NSString *)connectionType DEPRECATED_ATTRIBUTE;

/**
 * Reports the player seek start.
 * @param seekToPosition Position to seek in milliseconds.
 */
- (void)setSeekStart:(int64_t)seekToPosition DEPRECATED_ATTRIBUTE;

/**
 * Reports the player seek end.
 * @param seekPosition Position at end of seek in milliseconds.
 */
- (void)setSeekEnd:(int64_t)seekPosition DEPRECATED_ATTRIBUTE;

/**
 * Reports YES only when setSeekStart() was called.Default Value is NO.
 */
- (BOOL)isPlayerSeeking DEPRECATED_ATTRIBUTE;

/**
 * Notify Conviva that the stream Url has changed for the monitoring session.
 * DO NOT USE DEPRECATED
 * @param newStreamUrl StreamUrl to be updated.
 */
-(void)updateStreamUrl:(NSString *)newStreamUrl DEPRECATED_ATTRIBUTE ;

/**
 * Notify Conviva that the CDN Name has changed for the monitoring session.
 * DO NOT USE DEPRECATED
 * @param newCDNName New CDN to be updated.
 */
-(void)updateCDNName:(NSString *)newCDNName DEPRECATED_ATTRIBUTE;

/**
 * Notify Conviva that the Resource has changed for the monitoring session.
 * DO NOT USE DEPRECATED
 * @param newResource New Resource to be updated.
 */
-(void)updateResource:(NSString *)newResource DEPRECATED_ATTRIBUTE;

/**
 * Updates ContentMetadata.
 * DO NOT USE DEPRECATED.
 * @param newcontentInfo the new metadata info to be updated.
 */
- (void)updateContentMetadata:(CISContentMetadata *)newcontentInfo DEPRECATED_ATTRIBUTE;

/**
 * Discard the video quality data contained in this PlayerStateManager instance.
 */
-(void)reset;
@end

