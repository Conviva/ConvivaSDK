#import <Foundation/Foundation.h>


@protocol ConvivaRequestDelegate <NSObject>

- (void)handleRequest:(NSURLRequest *)request
    completionHandler:(void(^)(NSData *responseData, NSURLResponse *response, NSError *error))completionHandler;

@end
