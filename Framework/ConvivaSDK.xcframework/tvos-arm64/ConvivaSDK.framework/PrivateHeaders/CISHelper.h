//
//  CISHelper.m
//  ConvivaSDK
//
//  Created by Butchi peddi on 17/03/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>

/* For debug messages */

#if FALSE

#define LOG_FUNC_ENTRY(logger) \
[logger func:[NSString stringWithFormat:@"%s ++",__PRETTY_FUNCTION__]];

#define LOG_FUNC_EXIT(logger) \
[logger func:[NSString stringWithFormat:@"%s --",__PRETTY_FUNCTION__]];

#define LOG_FUNC_ENTRY_ARGS(logger,fmt,...) \
[logger func:[NSString stringWithFormat:@"%s" fmt @"++",__PRETTY_FUNCTION__,##__VA_ARGS__]];

#define LOG_FUNC_EXIT_ARGS(logger,fmt,...) \
[logger func:[NSString stringWithFormat:@"%s" fmt @"--",__PRETTY_FUNCTION__,##__VA_ARGS__]];

/* For info messages */
#define LOG_DEBUG(logger,fmt,...) \
[logger debug:[NSString stringWithFormat:@"%s Ln:%d " fmt,__PRETTY_FUNCTION__,__LINE__,##__VA_ARGS__]];

#else

#define LOG_FUNC_ENTRY(logger)  ((void*)0);
#define LOG_FUNC_EXIT(logger)  ((void*)0);
#define LOG_FUNC_ENTRY_ARGS(logger,fmt,...)  ((void*)0);
#define LOG_FUNC_EXIT_ARGS(logger,fmt,...)  ((void*)0);
#define LOG_DEBUG(logger,fmt,...) ((void*)0);
#endif



#define LOG_INFO(logger,fmt,...) \
[logger info:[NSString stringWithFormat:fmt,##__VA_ARGS__]];

/* For warning messages */
#define LOG_WARN(logger,fmt,...) \
[logger warning:[NSString stringWithFormat:@"%s Ln:%d " fmt,__PRETTY_FUNCTION__,__LINE__,##__VA_ARGS__]];

/* For error messages */
#define LOG_ERROR(logger,fmt,...) \
[logger error:[NSString stringWithFormat:@"%s Ln:%d " fmt,__PRETTY_FUNCTION__,__LINE__,##__VA_ARGS__]];

@interface CISHelper : NSObject

@end
