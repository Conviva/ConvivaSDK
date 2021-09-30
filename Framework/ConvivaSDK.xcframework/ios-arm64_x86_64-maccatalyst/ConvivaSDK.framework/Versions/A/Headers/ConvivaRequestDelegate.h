#import <Foundation/Foundation.h>

DEPRECATED_MSG_ATTRIBUTE("This class will be removed soon, please migrate to Simplified SDK APIs. Refer to https://community.conviva.com/site/one-sensor/sensors/ios/index_one_sensor.gsp")
@protocol ConvivaRequestDelegate <NSObject>

- (void)handleRequest:(NSURLRequest *)request
    completionHandler:(void(^)(NSData *responseData, NSURLResponse *response, NSError *error))completionHandler DEPRECATED_ATTRIBUTE;

@end
