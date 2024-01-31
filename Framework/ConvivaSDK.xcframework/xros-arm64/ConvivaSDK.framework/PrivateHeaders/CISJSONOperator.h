//
//  CISJSONOperator.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 16/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISJsonProtocol.h"
#import "CISLogger.h"

@interface CISJSONOperator : NSObject<CISJsonProtocol>

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithLogger:(CISLogger *)logger NS_DESIGNATED_INITIALIZER;
-(void)cleanUp;
@end
