#import <Foundation/Foundation.h>

#define CDN_NAME_AKAMAI @"AKAMAI"

/**
 * All possible player states reported to Conviva.
 */
typedef NS_ENUM(NSUInteger,PlayerState) {
    /** Report this state when you can confirm that the player is currently inactive/idle. */
    CONVIVA_STOPPED = 1,
    /** Report this state when you can confirm that the player is actively rendering video content for the viewer.<br>
     This should never be reported for unavailable/blocked content. */
    CONVIVA_PLAYING  = 3,
    /** Report this state when you can confirm that the player is stalled due to lack of video data in the buffer.<br>
     It may show a spinner or it may simply present a freeze frame. */
    CONVIVA_BUFFERING  = 6,
    /** Report this state when you can confirm that the player is paused, generally upon viewer request. */
    CONVIVA_PAUSED = 12,
    /** Report this state when no other recognized Conviva player states apply. */
    CONVIVA_NOT_MONITORED = 98,
    /** Reserved state. Do not use. */
    CONVIVA_UNKNOWN = 100
};

/**
 * All possible device types reported to Conviva.
 */
typedef NS_ENUM(NSInteger, DeviceType) {
    /**
     * DEVICE TYPE DESKTOP
     */
    DESKTOP = 0,
    /**
     * DEVICE TYPE SETTOP
     */
    SETTOP,
    /**
     * DEVICE TYPE MOBILE
     */
    MOBILE,
    /**
     * DEVICE TYPE TABLET
     */
    TABLET,
    /**
     * DEVICE TYPE SMARTTV
     */
    SMARTTV,
    /**
     * DEVICE TYPE UNKNOWN
     */
    UNKNOWN
};

/**
 *  All possible stream type that contains video advertisement.
 */
typedef NS_ENUM(NSInteger,AdStream){
    /** The ad is embedded inside the video content stream. */
    ADSTREAM_CONTENT = 0,
    /** The ad is played from a separate video stream. */
    ADSTREAM_SEPARATE,
    /** The ad stream is unknown. */
    ADSTREAM_UNKNOWN = 99
};

/**
 *  All possible video player in charge of rendering video advertisement.
 */
typedef NS_ENUM(NSInteger,AdPlayer){
    /** Ads and content are played using the same video player instance. */
    ADPLAYER_CONTENT = 0,
    /** Ads and content  are played using separate video player instances. */
    ADPLAYER_SEPARATE,
    /** The ad player is unknown. */
    ADPLAYER_UNKNOWN = 99
};

/**
 *  All possible position of video advertisement relative to content.
 */
typedef NS_ENUM(NSInteger,AdPosition){
    /** The ad is a bumper */
    ADPOSITION_BUMPER = 0,
    /** The ad is a preroll, kicking in before content. */
    ADPOSITION_PREROLL,
    /** The ad is a midroll, kicking in during content. */
    ADPOSITION_MIDROLL,
    /** The ad is a postroll, kicking in after content. */
    ADPOSITION_POSTROLL
};

/**
 *  All possible severity of errors reported to Conviva.
 */
typedef NS_ENUM(NSInteger,ErrorSeverity){
    /** The error could prevent playback altogether. */
    ERROR_FATAL = 0,
    /** The error should not affect playback. */
    ERROR_WARNING
};

/**
 * Possible types of ad technologies.
 */
typedef NS_ENUM(NSInteger,AdTechnology){
    /**Client Side. */
    CLIENT_SIDE = 0,
    /** Server Side. */
    SERVER_SIDE
};

/**
 * Possible types of ad type.
 */
typedef NS_ENUM(NSInteger,AdType) {
    /**Blackout slate. */
    BLACKOUT_SLATE = 0,
    /** Technical Difficulties slate. */
    TECHNICAL_DIFFICULTIES_SLATE,
    /** Commerical Break slate. */
    COMMERCIAL_SLATE,
    /** Other slate. */
    OTHER_SLATE,
    /** Commerical Break slate. */
    VPAID,
    /** Regular Ad. */
    REGULAR
};

/**
 * Possible types of ad serving type.
 */
typedef NS_ENUM(NSInteger,AdServingType){
    /** Inline. */
    INLINE = 0,
    /** Wrapper. */
    WRAPPER
};

/**
 * Possible types of ad error type.
 */
typedef NS_ENUM(NSInteger,ErrorType){
    /** Unknown Error */
    ERROR_UNKNOWN = 0,
    /** Input output error. */
    ERROR_IO,
    /** Timeout error. */
    ERROR_TIMEOUT,
    /** Null asset error. */
    ERROR_NULL_ASSET,
    /** Missing Parameter error. */
    ERROR_MISSING_PARAMETER,
    /** No ad available error. */
    ERROR_NO_AD_AVAILABLE,
    /** Parse error. */
    ERROR_PARSE,
    /** Invalid value error. */
    ERROR_INVALID_VALUE,
    /** Invalid slot error. */
    ERROR_INVALID_SLOT,
    /** 3P component error. */
    ERROR_3P_COMPONENT,
    /** Unsupported 3p feature error. */
    ERROR_UNSUPPORTED_3P_FEATURE,
    /** Device limit error. */
    ERROR_DEVICE_LIMIT,
    /** Unmatched slot size error. */
    ERROR_UNMATCHED_SLOT_SIZE
};

/**
 * Possible types of ad events.
 */
typedef NS_ENUM(NSInteger,Events){
    /** Ad requested. */
    AD_REQUESTED = 0,
    /** Ad response. */
    AD_RESPONSE,
    /** Ad slot started. */
    AD_SLOT_STARTED,
    /** Ad attempted. */
    AD_ATTEMPTED,
    /** Ad slot ended. */
    AD_SLOT_ENDED,
    /** Ad impression start. */
    AD_IMPRESSION_START,
    /** Ad start. */
    AD_START,
    /** Ad first quartile. */
    AD_FIRST_QUARTILE,
    /** Ad mid quartile. */
    AD_MID_QUARTILE,
    /** Ad third quartile. */
    AD_THIRD_QUARTILE,
    /** Ad completed. */
    AD_COMPLETE,
    /** Ad ended. */
    AD_END,
    /** Ad impression end. */
    AD_IMPRESSION_END,
    /** Ad skipped. */
    AD_SKIPPED,
    /** Ad error. */
    AD_ERROR,
    /** Ad progress. */
    AD_PROGRESS,
    /** Ad close. */
    AD_CLOSE,
    /** Ad paused. */
    CONTENT_PAUSED,
    /** Ad resumed. */
    CONTENT_RESUMED,
    /** Ad start. */
    POD_START,
    /** Ad end. */
    POD_END
};


/**
 * Internal do not use
 */
FOUNDATION_EXPORT NSString *const CWS_TRUE;

/**
 * Internal do not use
 */
FOUNDATION_EXPORT NSString *const CWS_FALSE;

/**
 * A default sessionKey to use for the Client.sendCustomEvent API if you do not yet have a Conviva session.
 */
FOUNDATION_EXPORT int const NO_SESSION_KEY;

/**
 * Declares Conviva constants required for a client and video sessions for Conviva SDK.
 */
@interface CISConstants : NSObject 
+(NSString *)getAdTechnologyStringValue:(AdTechnology)adTechnology;
+(NSString *)getAdTypeStringValue:(AdType)adType;
+(NSString *)getAdServingTypeStringValue:(AdServingType)adServingType;
+(NSString *)getErrorTypeStringValue:(ErrorType)errorType;
+(NSString *)getEventsStringValue:(Events)events;
+(NSString *)getAdPositionStringValue:(AdPosition)adPosition;
@end
