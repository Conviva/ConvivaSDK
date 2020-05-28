//
//  CISStreamerProxyFactoryProtocol.h
//
//  Created by Butchi peddi on 07/04/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISPlayerEventsListenerProtocol.h"
#import "CISStreamerProxyProtocol.h"
#import "CISLoggingProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol CISStreamerProxyFactoryProtocol <NSObject>

@optional
- (CISStreamerProxy)createStreamerProxy:(id)streamer
                   playerEventsListener:(CISPlayerEventsListener)playerEventsListener
                                 logger:(id<CISLoggingProtocol>)logger;

@end

typedef id<CISStreamerProxyFactoryProtocol> CISStreamerProxyFactory;
NS_ASSUME_NONNULL_END
