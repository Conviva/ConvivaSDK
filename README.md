# ConvivaSDK Framework

The ConvivaSDK Framework supports cocoapods and manual installation. The library is delivered as Static Framework and deployment is supported on iOS 8 and above.

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

    pod 'ConvivaSDK','2.141.4'
    

## Manual Installation
To add the ConvivaSDK library to your project manually:

1.	Download the latest ConvivaSDK [here](https://github.com/Conviva/ConvivaSDK/archive/2.141.4.zip)

2.	Unzip the package and add ConvivaSDK.framework to “Link Binary with Libraries” under build phase.
    The package contains framework for both iOS and tvOS. Please make sure to include right framework for your platform.

3.	Add the following system frameworks to “Link Binary with Libraries” section in xcode.

    * CoreMedia
    * SystemConfiguration
    * MobileCoreServices
    * CoreTelephony (iOS only)

4.	Add “-ObjC” to “Other Linker Flags” of Xcode.

    
## Import Statements

  Add the following import statements to your source code to refer Conviva classes.

    * @import ConvivaSDK; ( Objective-C)
    * import ConvivaSDK (Swift)

## Note:  

* Refer https://community.conviva.com/ for integration guidelines.               
* Refer https://convivasdk.github.io/Doc/ for API documentation.
