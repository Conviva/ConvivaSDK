//
//  CISHTTPProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 10/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>

/** 
 * Class conforming to this will be responsible for implementing required methods for HTTP(s) tasks,
 * this is used by the Conviva library to make HTTP(S) requests.
 */
@protocol CISHTTPProtocol <NSObject>
@required
/**
 * Send an HTTP request. HTTPS should be handled as well.<br>
 * Will be called regularly when Conviva monitoring sessions are active.<br>
 * The class implementing needs to notify response back with callbackSelector on callbackDelegate with parameters.<br>
 * Parameter 1 : (NSString *)responseString.<br>
 * Parameter 2 : error:(NSString *)error.<br>
 * Parameter 3 : delegate:(id< CISCancelProtocol >)requestDelegate. This will be used by SDK to cancel current HTTP tasks so class implementing CISHTTPProtocol must implement CISCancelProtocol required method.<br>
 * Parameter 4 : context:(id)context not required can be set nil.<br>
 * @param httpMethod "POST" or "GET".
 * @param urlToPost Where to make the HTTP request to.
 * @param postData Data to send along for post requests.
 * @param contentType Content type to be used in HTTP headers.
 * @param seconds Timeout to apply to the request, in milliseconds. The Request must be cancelled after that amount of time has passed.
 * @param headerFieldType Fields to be added in HTTP header request.
 * @param completionHandler completion handler to be implemented for HTTP responce,error.
 * @param headerFieldValue Value for fields to be added in HTTP header request.
 */
- (void)makeRequestWithurl:(NSURL *)urlToPost data:(NSString*)postData timeoutSeconds:(NSTimeInterval)seconds httpMethod:(NSString *)httpMethod  contentType:(NSString *)contentType httpHeaderValue:(NSString *)headerFieldValue httpHeaderField:(NSString *)headerFieldType completionHandler:(void (^)(NSData *responseData, NSURLResponse *response, NSError *error))completionHandler;

/**
 * Notification that Conviva no longer needs this HttpProtocol object.
 */
-(void)cleanUp;

@end
