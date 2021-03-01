//
//  CISTimeProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 10/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * Class conforming to this will be responsible for implementing required methods for a fetching time,<br>
 * this is used by the Conviva library to query time.
 */

@protocol CISTimeProtocol <NSObject>
@required
/**
 * Get the current time in milliseconds since UNIX epoch.
 * Will be called frequently.
 * @return timeSinceEpochMs Current time in milliseconds since UNIX epoch.
 */
-(NSTimeInterval) getEpochTimeMs;

/**
 * Notification that Conviva no longer needs this TimeProtocol.
 */
-(void)cleanUp;
@end
