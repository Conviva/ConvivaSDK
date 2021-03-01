//
//  CISRandom.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 15/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISClient.h"
#import "CISContentMetadata.h"

@interface CISRandom : NSObject
+(int) genrateClientID;
+(int) genrateSessionID;
@end
