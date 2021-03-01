//
//  IOSSystemTimer.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 29/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "CISCancelProtocol.h"

/**
 * Conviva provided helper class which manages timers required by Conviva SDK.<br>
 * This class is used by Conviva provided iOSTimerInterface to create this class instance for each timer activity.<br>
 * As this is conforming to CISCancelProtocol, the timer cancellation activity are also handled here.
 */

@interface IOSSystemTimer : NSObject<CISCancelProtocol>
- (instancetype)init NS_UNAVAILABLE;
/**
 * A helper method for creating system timer used by IOSSystemTimer.
 * @param intervalSeconds The time interval for the timer to fire.
 * @param queue Queue on which timer action will be performed.
 * @param handler The type of blocks submitted to dispatch queue.
 * @return Returns self-object with CISCancelProtocol methods implemented.
 */
-(instancetype)initWithSelector:(NSTimeInterval)intervalSeconds queue:(dispatch_queue_t)queue handler:(dispatch_block_t)handler NS_DESIGNATED_INITIALIZER;
@end
