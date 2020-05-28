//
//  CISPlayerEventsProtocol.h
//
//  Created by Butchi peddi on 29/03/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ConvivaStreamerError;

@protocol CISPlayerEventsListenerProtocol <NSObject>

/// @brief Signal a change in the bitrate, resource or CDN
///
/// \param bitrateKbps New bitrate
/// \param cdn New CDN
/// \param resource New resource
/// \note Use -1 or null to keep previous value
- (void)setStream:(int)bitrateKbps cdn:(nullable NSString *)cdn resource:(nullable NSString *)resource;

/// @brief Signal change in average bitrate
///
/// \param avgbitrateKbps New bitrate
- (void)setAverageBitrate:(int)avgbitrateKbps;


/// @brief Signal change in playing state
///
/// \param newState the new playing state (one of the constants in PlayerStates)
- (void)setPlayingState:(int)newState;

/// @brief Signal an error
///
/// \param err Error Message
//- (void)onError:(ConvivaStreamerError *)err;

- (void)onError:(NSString *)errMsg fatal:(BOOL)fatal;

/// @brief Signal an error
///
/// \param videoWidth Video Width
/// \param videoHeight Video Height
- (void)setVideoDimensionChages:(NSInteger)videoWidth videoHeight:(NSInteger)videoHeight;

/// @brief Signal an player seeking
-(BOOL)isPlayerSeeking;

//-(void)setSeekEvent:(SeekActionType)type seekPosition:(NSInteger)seekToPosition;

-(void)setSeekStart:(NSInteger)seekToPosition;

-(void)setSeekStop:(NSInteger)seekToPosition;

/// @brief sets the module version
///
/// \param moduleVersion module version
-(void)setModuleVersion:(NSString*)moduleVersion;

/// @brief sets the module name
///
/// \param moduleName module version
-(void)setModuleName:(NSString*)moduleName;

/// @brief sets the framework name
///
/// \param fwName module version
-(void)setFrameworkName:(NSString*)fwName;

/// @brief  sets the framework version
///
/// \param fwVersion module version
-(void)setFrameworkVersion:(NSString*)fwVersion;

/// @brief  sets the streamUrl
///
/// \param streamUrl Stream url
-(void)setStreamUrl:(NSString*)streamUrl;

/// @brief  sets the content length
///
/// \param contentLength length
-(void)setContentLength:(NSInteger)contentLength;

/// @brief  sets the cdn ip
///
/// \param cdnIp cdn ip address
-(void)setCdnIp:(NSString*)cdnIp;

/// @brief Sets play head time
///
/// \param pht Play head time
- (void)setPHT:(int64_t)pht;

/// @brief Sets buffer length
///
/// \param bl Buffer length
- (void)setBufferLength:(int64_t)bl;

/// @brief Sets average frame rate
///
/// \param fps Average frame rate.
- (void)setAverageFrameRate:(int)fps;

/// @brief Sets encoded frame rate
///
/// \param fps Encoded frame rate.
- (void)setEncodedFrameRate:(int)fps;


@end

typedef id<CISPlayerEventsListenerProtocol> CISPlayerEventsListener;

NS_ASSUME_NONNULL_END
