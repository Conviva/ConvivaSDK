#import <Foundation/Foundation.h>
#import "XYZPlayer.h"
@import ConvivaSDK;

/*
 * PLAYER INTERFACE FOR XYZ PLAYER
 */
@interface XYZPlayerInterface : NSObject<CISIClientMeasureInterface>

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithPlayerStateManager:(id<CISPlayerStateManagerProtocol>)psm xyzPlayer:(XYZPlayer *)xyzPlayer NS_DESIGNATED_INITIALIZER;

-(void)reportPlayerState:(PlayerState) playerState;
-(void)reportPlayerBitrate:(int)bitrate;
-(void)reportError;
-(void)cleanupXYZPLayerInterface;
-(void)setPlayerVersion;
-(void)setPlayerType;
-(void)setRenderedFrame:(int)frames;
-(void)setEncodedFrame:(int)frames;
@end
