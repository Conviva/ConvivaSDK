#import <Foundation/Foundation.h>

/*
 * DUMMY PLAYER CLASS
 */

@interface XYZPlayer : NSObject

-(instancetype)init NS_UNAVAILABLE;

-(instancetype)initWithVideoUrl:(NSString *)urlString NS_DESIGNATED_INITIALIZER;

-(void)stop;

@end
