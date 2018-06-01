#import "XYZPlayerInterface.h"



@interface XYZPlayerInterface()

// CAN BE STRONG / WEEK DEPENDING ON IMPLEMENTATION
@property(nonatomic,weak)id<CISPlayerStateManagerProtocol> psmInstance;

@property(nonatomic,weak) XYZPlayer *xyzPlayerInstance;

@property(nonatomic) NSInteger encodedFPS;

@property(nonatomic) NSInteger renderedFPS;

@end

@implementation XYZPlayerInterface

-(instancetype)initWithPlayerStateManager:(id<CISPlayerStateManagerProtocol>)psm xyzPlayer:(XYZPlayer *)xyzPlayer{

    self = [super init];
    
    if(self){
        self.psmInstance = psm;
        self.encodedFPS = 0;
        self.renderedFPS = 0;
    }
    
    return self;

}


// FOR SAMPLE APP THIS IS CALLED FROM VIEWCONTROLLER
// THIS MUST BE CALLED WHEN PLAYER REPORT A STATE CHANGE EVENT / INSIDE STATE CHANGE INFER LOGIC
-(void)reportPlayerState:(PlayerState) playerState{

    if (self.psmInstance != nil) {
        [self.psmInstance setPlayerState:playerState];
    }
    
}

// FOR SAMPLE APP THIS IS CALLED FROM VIEWCONTROLLER
// THIS MUST BE CALLED WHEN PLAYER REPORT A BITRATE CHANGE EVENT / INSIDE BITRATE CHANGE INFER LOGIC
-(void)reportPlayerBitrate:(int)bitrate{

    if (self.psmInstance != nil &&  bitrate > 0) {
        [self.psmInstance setBitrateKbps:bitrate];
    }
    
}

// FOR SAMPLE APP THIS IS CALLED FROM VIEWCONTROLLER
// THIS MUST BE CALLED WHEN PLAYER REPORTS AN ERROR FROM ERROR EVENT OR ANY OTHER WAY
-(void)reportError{

    if (self.psmInstance != nil) {
        [self.psmInstance sendError:@"Sample Fatal Error" errorSeverity:ERROR_FATAL];
    }

}

// SET PLAYER NAME
-(void)setPlayerVersion{
    
    if (self.psmInstance)
        [self.psmInstance setPlayerVersion:@"1.2.3.4"];
    
}

// SET PLAYER TYPE
-(void)setPlayerType{

    if (self.psmInstance)
        [self.psmInstance setPlayerType:@"XYZPlayer"];
    
}

// SET RENDERED
-(void)setRenderedFrame:(int)frames{
    self.encodedFPS = frames;
}

// SET ENCODED
-(void)setEncodedFrame:(int)frames{
    self.encodedFPS = frames;
}




#pragma REQUIRED METHOD FOR CISIClientMeasureInterface PROTOCOL

-(NSInteger)getPHT{
    // RETURN -1 IF PHT IS UNAVAILABLE
    
    return -1;
}

-(NSInteger)getBufferLength{
    // RETURN -1 IF BUFFER LENGTH IS UNAVAILABLE

    return -1;
}

-(NSInteger)getRenderedFrames{
    // RETURN 0 Rendered Frames IS UNAVAILABLE

    if (self.renderedFPS > 0)
        return self.renderedFPS;
    
    return 0;
}

-(NSInteger)getEncodedFrames{
    // RETURN 0 IF Encoded Frames IS UNAVAILABLE
    
    if (self.encodedFPS > 0)
        return self.encodedFPS;

    return 0;
}

-(NSInteger)getDroppedFrames{
    // RETURN 0 IF Dropped Frames IS UNAVAILABLE
    return 0;
}

-(void)cleanupXYZPLayerInterface{

    // CLEAN UP XYZPlayer IF REQUIRED
    // DEREGISTER NOTIFICATIONS

}

@end
