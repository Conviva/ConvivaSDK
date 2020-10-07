//
//  CISEventQueue.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 04/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>

@interface CISEventQueue : NSObject

/* enqueue an event of type NSMutableDictionary */
- (void)enqueueCwsEvent:(NSMutableDictionary *)event;

/* return an event list and then reset the queue */
- (NSArray *)flushCwsEvents;

-(void)cleanup;
@end
