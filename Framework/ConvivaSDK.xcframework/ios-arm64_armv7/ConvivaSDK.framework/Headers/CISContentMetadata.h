//
//  CISContentMetadata.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 04/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>

/**
 * Stream type which will be played by the player for the video session.
 */
typedef NS_ENUM(NSUInteger,StreamType) {
    /** It is not yet known what the type of streaming is. */
    CONVIVA_STREAM_UNKNOWN = 0,
    /** Content for this session is streamed live. */
    CONVIVA_STREAM_LIVE,
    /** Content for this session is streamed on demand. */
    CONVIVA_STREAM_VOD,
};

/**
 * Encapsulates all content metadata for a particular video asset.
 * This class instance is required while creating a video session.<br>
 * The instance of CISContentMetadata will be used while updating content metadata for a video session.
 */
@interface CISContentMetadata : NSObject<NSCopying>
/**
 * A unique identifier for the content, preferably human-readable.
 */
@property(nonatomic,copy) NSString *assetName;

/**
 * A string-to-string dictionary of custom metadata.
 */
@property(nonatomic,strong) NSMutableDictionary<NSString* ,NSString*> *custom;

/**
 * Default bitrate to report for this content.<br>
 * Use for single-bitrate content when you know the bitrate ahead of time.
 * DO NOT USE DEPRECATED
 */
@property(nonatomic,assign) NSInteger defaultBitrateKbps DEPRECATED_ATTRIBUTE;

/**
 * Default video server resource to report for this content.<br>
 * Examples: EDGECAST, AKAMAI-FREE, LEVEL3-PREMIUM...
 */
@property(nonatomic,copy) NSString *defaultResource;

/**
 * A string identifying the viewer.
 */
@property(nonatomic,copy) NSString *viewerId;

/**
 * A string identifying the current application.
 */
@property(nonatomic,copy) NSString *applicationName;

/**
 * Required 
 * the URL from where the video content will be downloaded.
 */
@property(nonatomic,copy) NSString *streamUrl;

/**
 * Required
 * the mode of streaming for this session.
 */
@property(nonatomic) StreamType streamType;

/**
 * Duration of the video content, in seconds.
 */
@property(nonatomic,assign) NSInteger duration;

/**
 * Video server cdn to report for the content.<br>
 * Use when the video server resource cannot be directly inferred from ContentMetadata.streamUrl
 * Examples: AKAMAI, LEVEL3...
 * DO NOT USE DEPRECATED
 */
@property(nonatomic,copy) NSString *cdnName;

/**
 * Duration of the video content, in seconds.
 */
@property(nonatomic,assign) NSInteger encodedFramerate;

/**
 * Duration of the video content, in seconds.
 */
@property(nonatomic,assign) BOOL isOfflinePlayback;

@end
