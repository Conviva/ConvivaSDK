//
//  CISIClientMeasureInterface.h
//
//
//
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Reports player related metrics required by Conviva SDK.<br>
 * Class conforming to this protocol needs to implement required methods for SDK to fetch information.<br>
 * Generally, the player interface class will conform to this protocol.
 */
@protocol CISIClientMeasureInterface <NSObject>
@optional
/**
 * Return the pht of a player instance in milliseconds.<br>
 * Implemented by player interface, if player does not support pht return -1.
 * @return Returns current playhead time  for the related video player.
 */
-(NSInteger)getPHT;

/**
 * Return the buffer length of a player instance in milliseconds.<br>
 * Implemented by player interface, if player does not support buffer length return -1.
 * @return Returns the current buffer length for the related video player.
 */
-(NSInteger)getBufferLength;

/**
 * Return the encoded frames per second of a player instance in seconds.<br>
 * Implemented by player interface, if player does not support encoded frame rate return 0.
 * Use PlayerState Manager's updateContentMetadata API
 * DO NOT USE DEPRECATED
 * @return Returns encoded frames for the related video player.
 */
-(NSInteger)getEncodedFrames DEPRECATED_ATTRIBUTE;

/**
 * Return the average frames per second of a player instance in seconds.<br>
 * Implemented by player interface, if player does not support average frame rate return 0.
 * @return Returns average frames for the related video player.
 */
-(NSInteger)getAverageFrames;

/**
 * Return the rendered frames per second of a player instance in seconds.<br>
 * Implemented by player interface, if player does not support average frame rate return 0.
 * DO NOT USE DEPRECATED
 * @return Returns average frames for the related video player.
 */
-(NSInteger)getRenderedFrames DEPRECATED_ATTRIBUTE;

/**
 * Return the average frames per second of a player instance in seconds.<br>
 * Implemented by player interface, if player does not support average frame rate return 0.
 * DO NOT USE DEPRECATED
 * @return Returns average frames for the related video player.
 */
-(NSInteger)getDroppedFrames DEPRECATED_ATTRIBUTE;


@end
