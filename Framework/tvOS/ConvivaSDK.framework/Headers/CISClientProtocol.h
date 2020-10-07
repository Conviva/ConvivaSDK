//
//  CISClientProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 25/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import "CISContentMetadata.h"
#import "CISPlayerStateManagerProtocol.h"

/** 
 * An instance of a client.
 * The class conforming to this protocol manages the SDK lifecycle and video sessions.<br>
 * Generally, in an application, a single instance of class conforming to this protocol is required.<br>
 * The class instance conforming to this protocol can be used to manage, create PlayerStateManager sessions and perform other important tasks.
 */
@protocol CISClientProtocol <NSObject>

/**
 * Creates a Conviva monitoring session.
 * Use when the viewer requests playback for video content.
 * Unless your application can display multiple videos concurrently, you should only ever have one active monitoring session.
 * @param cisContentMetadata contentMetadata An instance of ContentMetadata containing the content metadata for this session.
 * @return Opaque identifier for the newly created session. Will be NO_SESSION_KEY if session creation failed.
*/
-(int)createSessionWithMetadata:(CISContentMetadata *)cisContentMetadata;

/**
 * Creates a Conviva Ad monitoring session.
 * Use when an ad playback starts for a particular content session.
 * Unless your application can display multiple videos concurrently, you should only ever have one active monitoring session.
 * @param contentSessionKey The identifier for the monitoring session in which advertisement playback is requested
 * @param adMetadata An instance of CISContentMetadata containing the ad metadata for this session.
 * @return Opaque identifier for the newly created ad session. Will be NO_SESSION_KEY if session creation failed.
 */
-(int)createAdSession:(int)contentSessionKey adMetadata:(CISContentMetadata *)adMetadata;

/**
 * Terminates a monitoring session.
 * Use when playback for video content ends, fails or is cancelled by the viewer.
 */
-(void)cleanUp;

/**
 * Provides a PlayerStateManager instance.
 * @return An instance of PlayerStateManager.
 */
-(id<CISPlayerStateManagerProtocol>) getPlayerStateManager;

/**
 * Attach a video player to the monitoring session.
 * Use when a video player becomes relevant for the current session.
 * @param sessionKey The identifier for the monitoring session.
 * @param playerStateManager An instance of PlayerStateManager currently gathering data from a video player.
 */
-(void)attachPlayer:(int) sessionKey playerStateManager:(id<CISPlayerStateManagerProtocol>) playerStateManager;

/**
 * Reports an error for this monitoring session.
 * @param sessionKey The identifier for the monitoring session.
 * @param errorMessage The error message to be reported.
 * @param severity The severity of the error.
 */
-(void)reportError:(int)sessionKey errorMessage:(NSString *)errorMessage errorSeverity:(ErrorSeverity)severity;

/**
 * Update missing content metadata for an existing monitoring session.
 * Metadata that was previously set will not be updated.
 * This method will not update streamUrl,defaultResource and cdnName,for mentioned attributes a seperate update api is provided.
 * @param sessionKey The identifier for the monitoring session.
 * @param contentMetadata New content metadata for the monitoring session.
 */
-(void)updateContentMetadata:(int) sessionKey metadata:(CISContentMetadata *)contentMetadata;

/**
 * Detach the video player from the monitoring session.
 * Use when video player currently attached is no longer relevant for the current session.
 * @param sessionKey The identifier for the monitoring session.
 */
-(void)detachPlayer:(int)sessionKey;

/**
 * Notification that we will be preloading content with the video player.
 * Use when a video player is loading content but is not yet displaying video for the viewer.
 * @param sessionKey The identifier for the monitoring session.
 */
-(void)contentPreload:(int)sessionKey;

/**
 * Notification that the attached video player is no longer preloading, and has started displaying video for the viewer.
 * Only usable if preceded by contentPreload.
 * @param sessionKey The identifier for the monitoring session.
 */
-(void)contentStart:(int)sessionKey;

/**
 * Send a custom event to Conviva.
 * @param sessionKey The identifier for the monitoring session. Use NO_SESSION_KEY if you do not yet have a monitoring session.
 * @param eventName Name of the custom event.
 * @param attributes A dictionary of key-value pairs associated with the event.
 */
-(void)sendCustomEvent:(int)sessionKey eventname:(NSString *)eventName withAttributes:(NSDictionary *)attributes;

/**
 * Terminates a monitoring session.
 * Use when playback for video content ends, fails or is cancelled by the viewer.
 * @param sessionKey The identifier for the monitoring session.
 */
-(void)cleanupSession:(int)sessionKey;

/**
 * Properly frees a PlayerStateManager instance.
 * @param playerStateManager An instance of PlayerStateManager to be free up.
 */
-(void)releasePlayerStateManager:(id<CISPlayerStateManagerProtocol>)playerStateManager;

/**
 * Notify Conviva that an ad is about to start for the monitoring session.
 * @param sessionKey The identifier for the monitoring session.
 * @param adStream Whether the ad is embedded in the content stream.
 * @param adPlayer Whether the ad is played by the same player as the original video content.
 * @param adPosition Whether the ad is a preroll, midroll or postroll.
 */
-(void)adStart:(int)sessionKey adStream:(AdStream)adStream adPlayer:(AdPlayer)adPlayer adPosition:(AdPosition)adPosition;

/**
 * Notify Conviva that an ad is about to start for the monitoring session.
 * @param sessionKey The identifier for the monitoring session.
 */
-(void)adStart:(int)sessionKey;

/**
 * Notify Conviva that an ad has ended for the monitoring session.
 * @param sessionKey The identifier for the monitoring session.
 */
-(void)adEnd:(int)sessionKey;

/**
 * Return a PlayerStateManager instance.
  * @param sessionKey The identifier for the monitoring session.
 */
-(id<CISPlayerStateManagerProtocol>)getAttachedPlayer:(int)sessionKey;

/**
 * Check if any PlayerStateManager is already attached to a session.
 * Return true if a PlayerStateManager is currently attached to that session, false otherwise.
 * @param sessionKey The identifier for the monitoring session.
 */
-(BOOL)isPlayerAttached:(int)sessionKey;

/**
 * Returns unique client id
 */
-(NSString*)getClientId;


@end
