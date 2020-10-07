//
//  Copyright (c) 2012 Conviva. All rights reserved.
//  Created by Saiguang Che (saiguang@conviva.com).
//
//  Refer to http://developer.conviva.com/integration/ios for integration help.
//
//  LivePass version 2.135.0.34990
//

#import "ConvivaContentInfo.h"
#import "ConvivaLightSession.h"
#import "ConvivaRequestDelegate.h"
#import <Foundation/Foundation.h>
#import "CISClientProtocol.h"

#define OPTION_EXTERNAL_BITRATE_REPORTING @"externalBitrateReporting"
#define OPTION_EXTERNAL_STREAMURL_REPORTING @"externalStreamURLReporting"

/// @mainpage
/// @author Saiguang Che
///
/// The top level class for customer interaction is LivePass. Additional api
/// is available in ConvivaLightSession.

@interface LivePass : NSObject

/// @brief Initialize the LivePass module
///
/// See Conviva integration guide for details of how to use this method.
/// \param customerKey a key assigned by Conviva to uniquely identify a
///   Conviva customer
+ (void)initWithCustomerKey:(NSString *)customerKey;

/// @brief Initialize LivePass with advanced settings parameters
///
/// \param customerKey a key assigned by Conviva to uniquely identify a
///   Conviva customer
/// \param settings a dictionary with string keys and object values
+ (void)initWithCustomerKey:(NSString *)customerKey andSettings:(NSDictionary *)settings;

/// @brief Cleanup all the sessions owned by LivePass
+ (void)cleanup;

/// @brief Create a session for LivePass
///
/// \param streamer can be a subclass of ConvivaStreamerProxy, AVPlayer,
///   MPMoviePlayerController, or a null object
/// \param contentInfo Info related to the content (url, etc)
+ (ConvivaLightSession *)createSessionWithStreamer:(id)streamer andConvivaContentInfo:(ConvivaContentInfo *)contentInfo;

/// @brief Create a session for LivePass
///
/// \param streamer can be a subclass of ConvivaStreamerProxy, AVPlayer,
///   MPMoviePlayerController or a null object
/// \param contentInfo Info related to the content (url, etc)
/// \param options Options that modify session behavior
+ (ConvivaLightSession *)createSessionWithStreamer:(id)streamer
                             andConvivaContentInfo:(ConvivaContentInfo *)contentInfo
                                        andOptions:(NSDictionary *)options;

/// @brief Create an ad session for LivePass
///
/// \param adStreamer can be a subclass of AVPlayer or of type id
/// \param contentSession main video content's session
/// \param adContentInfo Info related to the content (url, etc)
/// \param options Options that modify session behavior
+ (ConvivaLightSession *) createAdSession:(id)adStreamer
                           contentSession:(ConvivaLightSession *)contentSession
                       convivaContentInfo:(ConvivaContentInfo *)adContentInfo
                                  options:(NSDictionary *)options;

/// @brief Cleanup session. Should be called when a video session is over.
///
/// \param session The session to be cleaned
+ (void)cleanupSession:(ConvivaLightSession *)session;

/// @brief Toggle on/off console traces.
///
/// \param on pass true to enable console trace, false otherwise
+ (void)toggleTraces:(BOOL)on;

/// @brief This function is used to send Conviva Player Insights Event,
/// not associated with a video session. Events have a name and a list of
/// key value pairs as event attributes
///
/// \param name A name for the event
/// \param attributes A dictionary of key value pair associated with the
///   event
+ (void)sendEvent:(NSString *)name withAttributes:(NSDictionary *)attributes;

/// Notify that ad has started
+ (void)adStart:(ConvivaLightSession *)session;
/// Notify that ad has ended
+ (void)adEnd:(ConvivaLightSession *)session;

/// @brief The delegate object to use when handling network requests.
+ (id <ConvivaRequestDelegate>)requestDelegate;
/// @brief Sets the delegate object to use when handling network requests.
/// Conviva does not store a strong reference to the delegate object.
+ (void)setRequestDelegate:(id <ConvivaRequestDelegate>)delegate;

/// @brief True if library has been initialized
///
/// \deprecated Not used and to be phased out
+ (BOOL)ready DEPRECATED_ATTRIBUTE;

/// @brief Set user preferences for data collection.
/// \param userPrefs pass key-value pair as user preferences.

/// Currently Supported keys: "idfa", "idfv".

/// Expected Values:
/// YES - Will collect id for mentioned key.
/// NO - Will stop collecting id for mentioned key.
/// If not been set, by default its considered as YES.
///
/// Sample usage:
/// [LivePass  setUserPreferenceForDataCollection: [NSDictionary dictionaryWithObjectsAndKeys: @YES, @"idfa", @NO, @"idfv", nil]];

+ (void)setUserPreferenceForDataCollection:(NSDictionary *)userPrefs;

/// @brief Set user preferences for data deletion.
/// \param userPrefs pass key-value pair as user preferences.

/// Currently Supported keys: "idfa", "idfv".

/// Expected Values:
/// YES - Will stop collecting id for mentioned key and delete previously collected data.
/// NO - Will not have any effect.

/// Sample usage:
/// [LivePass  setUserPreferenceForDataDeletion: [NSDictionary dictionaryWithObjectsAndKeys: @NO, @"idfa", @YES, @"idfv", nil]];
+ (void)setUserPreferenceForDataDeletion:(NSDictionary *)userPrefs;

/// @brief Useful for cross integration when customers want to use simplified sdk api's for ad integration.
+ (id<CISClientProtocol>) getClient;

@end
