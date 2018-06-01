#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "CISCallbackProtocol.h"
#import "CISCallback_RunnableProtocol.h"
#import "CISCancelProtocol.h"
#import "CISClientCreator.h"
#import "CISClientProtocol.h"
#import "CISClientSettingCreator.h"
#import "CISClientSettingProtocol.h"
#import "CISConstants.h"
#import "CISContentMetadata.h"
#import "CISHTTPProtocol.h"
#import "CISIClientMeasureInterface.h"
#import "CISIModuleVersion.h"
#import "CISLoggingProtocol.h"
#import "CISMetadataProtocol.h"
#import "CISPlayerStateManagerProtocol.h"
#import "CISRunnableProtocol.h"
#import "CISStorageProtocol.h"
#import "CISSystemFactoryCreator.h"
#import "CISSystemFactoryProtocol.h"
#import "CISSystemInterfaceCreator.h"
#import "CISSystemInterfaceProtocol.h"
#import "CISSystemSettings.h"
#import "CISTimeProtocol.h"
#import "CISTimerProtocol.h"
#import "IOSHttpInterface.h"
#import "IOSLoggingInterface.h"
#import "IOSMetadataInterface.h"
#import "IOSStorageInterface.h"
#import "IOSSystemInterfaceFactory.h"
#import "IOSSystemTimer.h"
#import "IOSTimeInterface.h"
#import "IOSTimerInterface.h"

FOUNDATION_EXPORT double ConvivaSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char ConvivaSDKVersionString[];

