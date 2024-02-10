# ConvivaSDK Framework

The ConvivaSDK Framework supports cocoapods and manual installation. The library is delivered as Static Framework and deployment is supported on iOS 12 and above.
**Supports iOS/tvOS 15 as well.**

## Migrating from Pre 2.141.0 version
For customers who have already integrated pre 2.141.0 version of Conviva library, we recommend them to migrate to the latest 
release 2.141.0. Please follow these steps to migrate to 2.141.0 version
  1. Remove libiOSSdkCore.a from “Link Binary with Libraries” of xcode
  2. Remove the following header file from your application and follow either cocoapods or manual way of installation.
        * #import "CISSystemInterfaceProtocol.h"
        * #import "CISSystemFactoryProtocol.h"
        * #import "CISSystemSettings.h"
        * #import "CISClientSettingProtocol.h"
        * #import "CISClientProtocol.h"
        * #import "IOSSystemInterfaceFactory.h"
        * #import "CISSystemFactoryCreator.h"
        * #import "CISClientSettingCreator.h"
        * #import "CISClientCreator.h"
        * #import "CISConstants.h"
        * #import "CISPlayerStateManagerProtocol.h"

## Cocoapods Installation
    Add the following line to your pod file and run 'pod install'
    
    // Without Advertising Identifier(IDFA) support
    pod 'ConvivaSDK','4.0.47'
    
    OR 
    
    // With Advertising Identifier(IDFA) support
    // Application must be built with XCode 12 or above.
    // Application's plist file must have an entry for NSUserTrackingUsageDescription key with appropriate message.
    // Example message:
    // <key>NSUserTrackingUsageDescription</key>
    // <string>App would like to access IDFA to uniquely identify the user.</string>
    
    pod 'ConvivaSDK','4.0.40'
    
## Swift Package Manager Installation
1. Add the Package Dependency repository URL as https://github.com/Conviva/conviva-ios-sdk-spm
2. Select version as:
    * 4.0.40 if it's with Advertising Identifier Support.
    * 4.0.47 if it's without Advertising Identifier Support.


## Manual Installation
To add the ConvivaSDK library to your project manually:

1.	Download the latest ConvivaSDK from below path.
      * [Without Advertising Identifier(IDFA) support](https://github.com/Conviva/ConvivaSDK/archive/4.0.47.zip)
      OR
     *  [With Advertising Identifier(IDFA) support](https://github.com/Conviva/ConvivaSDK/archive/4.0.40.zip)

2.	Unzip the package and add ConvivaSDK.xcframework to “Link Binary with Libraries” under build phase.

3.	Add the following system frameworks to “Link Binary with Libraries” section in xcode.

    * CoreMedia
    * SystemConfiguration
    * MobileCoreServices
    * CoreTelephony (iOS only)
    * Network (weak)
    * AVFoundation
    * AppTrackingTransparency(weak) - Required only for Advertising Identifier supported library (Application must be built with XCode 12 or above).
    

4.	Add “-ObjC” to “Other Linker Flags” of Xcode.

    
## Import Statements

  Add the following import statements to your source code to refer Conviva classes.

    * @import ConvivaSDK; (Objective-C)
    * import ConvivaSDK (Swift)

## Note:  

* Refer https://pulse.conviva.com/learning-center/content/sensor_developer_center/sensor_integration/ios/ios_stream_sensor.html for integration guidelines.               
* Refer https://pulse.conviva.com/learning-center/content/sensor_developer_center/sensor_api/ios_api/index.html for API documentation.
