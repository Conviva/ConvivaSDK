//
//  CSSConstants.h
//
//  Created by Butchi peddi on 20/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>

/*------------------------ PLAYBACK METRIC KEYS -----------------------------------*/

/*
 Key for Stream bitrate.
 Expected value: [NSNumber integerValue]
 */
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_BITRATE;

/*
 Key for Stream Average bitrate.
 Expected value: [NSNumber integerValue]
 */
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_AVERAGE_BITRATE;

/*
Key for Stream buffer length.
Expected value: [NSNumber intValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_BUFFER_LENGTH;

/*
Key for IP of cdn server serving stream.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_CDN_IP;

/*
Key for IP of cdn server serving stream.
Expected value: [NSNumber intValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_ENCODED_FRAMERATE;

/*
Key for Player state. Possible value are listed in PlayerState.
Expected value: [NSNumber unsignedIntValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_PLAYER_STATE;

/*
Key for Current play head time
Expected value: [NSNumber longValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_PLAY_HEAD_TIME;

/*
Key for Current render frame rate.
Expected value: [NSNumber intValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_RENDERED_FRAMERATE;

/*
Key for Stream Resolution.
Expected value: [NSValue CGSizeValue];
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_RESOLUTION;

/*
Key for Seek start event.
Expected value: [NSNumber unsignedLongLongValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_SEEK_STARTED;

/*
Key for Seek end event.
Expected value: [NSNumber unsignedLongLongValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_SEEK_ENDED;

/*
Key for Device Signal strength.
Expected value: [NSNumber doubleValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_SIGNAL_STRENGTH;

/*
Key for Link Encryption type.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_LINK_ENCRYPTION;

/*
Key for Connection Type.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYBACK_METRIC_CONN_TYPE;

/*------------------------ END OF PLAYBACK METRIC KEYS ----------------------------*/

/*------------------------- METADATA CONSTANTS -------------------------*/

/*
Key for Asset name currently being played.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_METADATA_ASSET_NAME ;

/*
Key for Name of the Player currently used for playback.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_METADATA_PLAYER_NAME ;

/*
Key for Content is live or not.
Expected value: [NSNumber boolValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_METADATA_IS_LIVE ;

/*
Key for Framework version for AVPlayer,Brightcove or custom for playback.
Expected value: [NSNumber integerValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_METADATA_ENCODED_FRAMERATE;

/*
key for CDN Resource like AKAMAI,AMAZON etc.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_METADATA_DEFAULT_RESOURCE ;

/*
Key for Stream url.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_METADATA_STREAM_URL ;

/*
Key for Uniquely identifiable user id.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_METADATA_VIEWER_ID ;

/*
Key for Framework version for AVPlayer,Brightcove or custom for playback.
Expected value: [NSNumber integerValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_METADATA_DURATION ;

/*
Key to enable/disable offline playback.If it is enabled and network is not reachable over wifi,data will be cached and sent when network is reachable.Default value is false.
Expected value: [NSNumber boolValue]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_METADATA_IS_OFFLINE_PLAYBACK;

/*------------------------- PLAYER INFO CONSTANTS -------------------------*/

/*
Key for Module name like AVPlayer,Brightcove provided by conviva or custom.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYER_MODULE_NAME;

/*
Key for Module version for AVPlayer,Brightcove provided by conviva or custom.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYER_MODULE_VERSION;

/*
Key for Framework name like AVPlayer,Brightcove or custom for playback.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYER_FRAMEWORK_NAME;

/*
Key for Framework version for AVPlayer,Brightcove or custom for playback.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_PLAYER_FRAMEWORK_VERSION;

/*------------------------- END OF PLAYER INFO CONSTANTS-------------------------*/

 /*------------------------- END OF METADATA CONSTANTS -------------------------*/

/*------------------------- AD BREAK CONSTANTS -------------------------*/

/*
POD index Key.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_AD_BREAK_POD_INDEX ;

/*
POD position Key.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_AD_BREAK_POD_POSITION ;

/*
POD duration key.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_AD_BREAK_POD_DURATION ;

/*
Key for Player name used for ad playback .
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_AD_BREAK_AD_PLAYER ;

/*------------------------- END OF AD BREAK CONSTANTS -------------------------*/

/*--------------------------------- APP EVENTS --------------------------------*/

/* App foreground event */
FOUNDATION_EXPORT NSString *const CIS_SSDK_APP_FOREGROUND_EVENT;

/* App background event*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_APP_BACKGROUND_EVENT;

/*------------------------------ END OF APP EVENTS ----------------------------*/

/*---------------------------------- SETTINGS ---------------------------------*/

/**
The URL of the Conviva platform to report data to. The default value is highly recommended in production environments.
Expected value: NSString
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_SETTINGS_GATEWAY_URL;

/**
 The level of log messages to print in the console log and report to conviva backend.
 We recommend using log level warning during development and lowering to debug when more information is required to troubleshoot specific issues.
 Expected value: [NSNumber numberWithUnsignedInteger]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_SETTINGS_LOG_LEVEL;

/**
 Enable/Disable console logs.Useful during development.
 Set true to enable console logs else false.
 Expected value: [NSNumber numberWithBool]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_SETTINGS_ENABLE_CONSOLE_LOGS;

/**
 How long the Conviva client will wait for a response when attempting to send/receive data over network before considering that attempt a failure in seconds.The default value will work for the overwhelming majority of devices.
 Expected value: [NSNumber numberWithDouble]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_SETTINGS_HTTP_TIMEOUT;

/**
 How long the Conviva client will wait for a response when attempting to access device storage before considering that attempt a failure in seconds.
 The default value will work for the overwhelming majority of devices.
 Expected value: [NSNumber numberWithDouble]
*/
FOUNDATION_EXPORT NSString *const CIS_SSDK_SETTINGS_STORAGE_TIMEOUT;

/*------------------------------ END OF SETTINGS ------------------------------*/

/*---------------------------------- USER OPTIONS ---------------------------------*/
/* User options to control auto detection applicable incase of conviva provided avplayer module.*/

/**
 Pass true to disable auto detection.
 Expected value: [NSNumber numberWithBool]
*/
FOUNDATION_EXPORT NSString *const CIS_SDK_OPTION_EXTERNAL_BITRATE_REPORTING;

/**
 Pass true to disable auto detection.
 Expected value: [NSNumber numberWithBool]
*/
FOUNDATION_EXPORT NSString *const CIS_SDK_OPTION_EXTERNAL_STREAMURL_REPORTING;

/*---------------------------------- END OF USER OPTIONS -----------------------------*/
