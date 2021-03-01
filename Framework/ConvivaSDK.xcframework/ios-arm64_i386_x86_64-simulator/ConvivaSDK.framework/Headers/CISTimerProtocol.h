//
//  CISTimerProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 10/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Class conforming to this will be responsible for implementing required methods for initiating timers,
 * this is used by the Conviva library access system timers.
 */

@protocol CISTimerProtocol <NSObject>
@required
/**
 * Start a periodic timer.
 * Will be called frequently.
 * @param intervalSeconds The interval at which to run the function, in milliseconds.
 * @param queue Queue on which timer action will be performed.
 * @param handler The type of blocks submitted to dispatch queue.
 * @return An instance of a class implementing CISTimerProtocol that can be used to cancel the timer.
 */
-(id)createTimer:(NSTimeInterval)intervalSeconds queue:(dispatch_queue_t)queue handler:(dispatch_block_t)handler;


/**
 * Notification that Conviva no longer needs this TimerProtocol.
 */
-(void)cleanUp;

@end
