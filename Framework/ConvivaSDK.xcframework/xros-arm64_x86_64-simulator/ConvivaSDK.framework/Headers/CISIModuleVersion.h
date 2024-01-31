//
//  CISIModuleVersion.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 27/07/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Required to set the name and version of a client module.
 */
@protocol CISIModuleVersion <NSObject>
/**
 * Return the name of a  client module.
 * @return Module name nil if not available.
 */
-(NSString *)getModuleName;

/**
 * Return the version of a  client module.
 * @return Module version nil if not available.
 */
-(NSString *)getModuleVersion;


/**
 * Set the name and version of a client module implementation.
 * @param name Module name.
 * @param version Client version.
 */
-(void)setModuleNameAndVersion:(NSString*)name clientVersion:(NSString*)version;

@end
