//
//  CISStreamerError.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 12/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
@interface CISStreamerError : NSObject

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithErrorMsg:(NSString *)msg isFatal:(NSString *)isErrorFatal NS_DESIGNATED_INITIALIZER;
- (NSString *)getErrorMessageString;
- (NSString *)getIsErrorFatal;
@end
