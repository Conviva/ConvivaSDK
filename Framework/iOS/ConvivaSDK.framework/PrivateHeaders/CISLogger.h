#import <Foundation/Foundation.h>
#import "CISLoggingProtocol.h"
#import "CISTimeProtocol.h"
#import "CISSystemSettings.h"
#import "CISLoggerProtocol.h"

@interface CISLogger : NSObject<CISLoggerProtocol>
- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithLogger:(id<CISLoggingProtocol>)logger time:(id<CISTimeProtocol>)time logBuffer:(NSMutableArray *)logBuffer packageName:(NSString *)package systemSetting:(CISSystemSettings *)settings NS_DESIGNATED_INITIALIZER;
//-(NSString*) prependPackageName:(NSString*) message;

@end
