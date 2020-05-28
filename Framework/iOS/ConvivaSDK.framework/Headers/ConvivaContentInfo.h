//
//  Copyright (c) 2012 Conviva. All rights reserved.
//  Created by Saiguang Che (saiguang@conviva.com).
//
//  Refer to http://developer.conviva.com/integration/ios for integration help.
//
#import <Foundation/Foundation.h>
#import "CISContentMetadata.h"

/// @name cdnNames
/// Names of content delivery networks typically stored in cdnName field
///@{
#define CDN_NAME_AKAMAI @"AKAMAI"
#define CDN_NAME_AMAZON @"AMAZON"
#define CDN_NAME_ATT @"ATT"
#define CDN_NAME_BITGRAVITY @"BITGRAVITY"
#define CDN_NAME_BT @"BT"
#define CDN_NAME_CDNETWORKS @"CDNETWORKS"
#define CDN_NAME_CHINACACHE @"CHINACACHE"
#define CDN_NAME_EDGECAST @"EDGECAST"
#define CDN_NAME_HIGHWINDS @"HIGHWINDS"
#define CDN_NAME_INTERNAP @"INTERNAP"
#define CDN_NAME_LEVEL3 @"LEVEL3"
#define CDN_NAME_LIMELIGHT @"LIMELIGHT"
#define CDN_NAME_OCTOSHAPE @"OCTOSHAPE"
#define CDN_NAME_SWARMCAST @"SWARMCAST"
#define CDN_NAME_VELOCIX @"VELOCIX"
#define CDN_NAME_TELEFONICA @"TELEFONICA"
#define CDN_NAME_MICROSOFT @"MICROSOFT"
#define CDN_NAME_CDNVIDEO @"CDNVIDEO"
#define CDN_NAME_QBRICK @"QBRICK"
#define CDN_NAME_NGENIX @"NGENIX"
#define CDN_NAME_IPONLY @"IPONLY"
#define CDN_NAME_INHOUSE @"INHOUSE"
#define CDN_NAME_COMCAST @"COMCAST"
#define CDN_NAME_NICE @"NICE"
#define CDN_NAME_TELENOR @"TELENOR"
#define CDN_NAME_TALKTALK @"TALKTALK"
#define CDN_NAME_FASTLY @"FASTLY"
#define CDN_NAME_TELIA @"TELIA"
#define CDN_NAME_CHINANETCENTER @"CHINANETCENTER"
#define CDN_NAME_MIRRORIMAGE @"MIRRORIMAGE"
#define CDN_NAME_SONIC @"SONIC"
#define CDN_NAME_ATLAS @"ATLAS"
#define CDN_NAME_OOYALA @"OOYALA"
#define CDN_NAME_TATA @"TATA"
#define CDN_NAME_GOOGLE @"GOOGLE"
#define CDN_NAME_INSTARTLOGIC @"INSTARTLOGIC"
#define CDN_NAME_TELSTRA @"TELSTRA"
#define CDN_NAME_OPTUS @"OPTUS"
#define CDN_NAME_ALIBABA @"ALIBABA"
#define CDN_NAME_HGC @"HGC"
#define CDN_NAME_QUANTIL @"QUANTIL"
#define CDN_NAME_CLOUDFRONT @"CLOUDFRONT"
#define CDN_NAME_OTHER @"OTHER"
///@}

@interface ConvivaContentInfo : NSObject<NSCopying>

/// A unique identifier for the content, preferably human-readable.
@property(copy, nonatomic) NSString *assetName;

/// A string identifying the CDN used to stream video.
@property(copy, nonatomic) NSString *cdnName;

/// A set of key-value pairs used in resource selection and policy evaluation
@property(strong, nonatomic) NSMutableDictionary *tags;

/// Set to true if the session includes live content, and false otherwise.
@property(assign, nonatomic) BOOL isLive;

/// The URL from which the video is loaded.
@property(copy, nonatomic) NSString *streamUrl;

/// A string identifying the viewer and is optional.
@property(copy, nonatomic) NSString *viewerId;

/// A string identifying the player in use, preferably human-readable.
@property(copy, nonatomic) NSString *playerName;

/// @brief The resource name used when the streamer does not itself know the
/// resource being played.
/// @note If this is null, then the value of cdnName is used for reporting.
@property(copy, nonatomic) NSString *resource;

/// An integer identifying the content length
@property(assign, nonatomic) NSInteger contentLength;

/// An integer identifying the encodedframe rate
@property(assign, nonatomic) NSInteger encodedFramerate;

/// @brief Timestamp when ConvivaContentInfo was instantiated
/// @deprecated Not used
@property(readonly, nonatomic) NSTimeInterval timestamp DEPRECATED_ATTRIBUTE;

/// Set to true if the session Offline video, and false otherwise.
@property(assign, nonatomic) BOOL isOfflinePlayback;

/// @brief Create a new ConvivaContentInfo with specified assetName.
/// @note Missing tags parameter
+ (id)createInfoForLightSessionWithAssetName:(NSString *)assetName;

- (CISContentMetadata*) toCISContentMetadata;

@end
