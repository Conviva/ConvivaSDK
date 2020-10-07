//
//  CISCallbackWithTimeout.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 28/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISTimer.h"

typedef void (^ CallBackBlock)(BOOL, NSString *);

@interface CISCallbackWithTimeout : NSObject

- (instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithTimer:(CISTimer *)timer NS_DESIGNATED_INITIALIZER;
-(id)getWrapperCallback:(id)callBack timeOut:(NSTimeInterval)timeOutSeconds timeOutMessage:(NSString *)message;
-(void)cleanUp;
@end
