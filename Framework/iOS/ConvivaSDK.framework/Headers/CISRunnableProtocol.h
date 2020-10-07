//
//  CISRunnableProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 28/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

/**
 * Used by the Conviva library to run timer action.
 */
@protocol CISRunnableProtocol <NSObject>
@required
/**
 * Used to run timer action.
 */
-(void)run;
@end
