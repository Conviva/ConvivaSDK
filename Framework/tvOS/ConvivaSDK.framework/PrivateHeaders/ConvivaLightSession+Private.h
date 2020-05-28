//
// Copyright (c) 2015 Conviva. All rights reserved.
//

#import "ConvivaLightSession.h"
#import "CISClient.h"
#import "CISLogger.h"

@interface ConvivaLightSession (Private)

+ (ConvivaLightSession *)sessionWithStreamer:(id)streamer
                                      client:(CISClient*)client
                                 contentInfo:(ConvivaContentInfo *)contentInfo
                                     options:(NSDictionary *)options
                              contentSession:(ConvivaLightSession *)contentSession
                                        isAd:(BOOL)isAd
                                      holdHB: (BOOL) holdHB
                                      logger:(CISLogger*)logger;
    
@end
