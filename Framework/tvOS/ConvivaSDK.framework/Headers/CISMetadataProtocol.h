//
//  CISMetadataProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 10/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//

#import "CISConstants.h"


/**
 * Class conforming to this will be responsible for implementing required methods for system information,
 * this is used by the Conviva library to gather system information.
 */

@protocol CISMetadataProtocol <NSObject>
@required
/**
 * Required the build model of iOS/tvOS.
 * @return DeviceType iOS/tvOS build model.
 */
-(NSString *)getAppleOSBuildModel;

/**
 * A version of the operating system used by the device.
 * Ex: "9.1"
 * @return Operating System Version, a version of the operating system used by the device.
 */
-(NSString *)getOperatingSystemVersion;

/**
 * Required the type of the device. One of Console, Settop, Mobile and PC.
 * @return DeviceType, type of the device; should be fetched by passing value from DeviceType enum to [CISClient getDeviceType:];
 */
-(DeviceType) getDeviceType;

/**
 * A model of the device.
 * @return Device Model, a model of the device.
 */
-(NSString *)getDeviceModel;

@optional

/**
 * A version of the device. Usually, low-level information pertaining to the hardware.
 * Ex: "DTP-BP-0869-34".
 * @return DeviceVersion, a version of the device.
 */
-(NSString *)getDeviceVersion;

/**
 * The manufacturer of the device.
 * Ex: "Samsung", "Apple".
 * @return DeviceManufacturer, the manufacturer of the device.
 */
-(NSString *)getDeviceManufacturer;

/**
 * The brand of the device.
 * Ex: "iPhone", "Samsung SmartTV".
 * @return DeviceBrand, the Brand of the device.
 */
-(NSString *)getDeviceBrand;

/**
 * The name of the framework used by your application, if applicable.
 * It can be the name of application framework itself, or the name of the player framework used for video playback.<br>
 * Ex: "AVFoundation", "NexPlayer", "HTML5", "OSMF"
 * @return FrameworkName, the name of the framework used by your application.
 */
-(NSString *)getFrameworkName;

/**
 * A version of the framework used by your application, if applicable.
 * Ex: "alpha12", "4.28.4433".
 * @return FrameworkVersion, a version of the framework used by your application.
 */
-(NSString *)getFrameworkVersion;

/**
 * A version of the platform used by the device.
 * Ex: "9.2.1".
 * @return PlatformVersion, a version of the platform used by your device.
 */
-(NSString *)getPlatformVersion;

/**
 * A version of the platform name used by the device.
 * Ex: "iOS", "tvOS","watchOS".
 * @return A platform name used by the device.
 */
-(NSString *)getPlatformName;

/**
 * Notification that Conviva no longer needs this MetadataProtocol.
 */
-(void)cleanUp;
@end
