//
//  CISStreamerProxyProtocol.h
//
//  Created by Butchi peddi on 07/04/20.
//  Copyright © 2020 Conviva. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CISStreamerProxyProtocol <NSObject>

- (void) cleanup;

@end

typedef  id<CISStreamerProxyProtocol> CISStreamerProxy;
NS_ASSUME_NONNULL_END
