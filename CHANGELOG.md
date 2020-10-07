# Changelog

## 4.0.7 (10/07/2020)
* Supports iOS 14 
* Support for auto collection of screen resolution
* Support for collection of dropped frame count
* Using Network.framework to detect connection type for iOS/tvOS 12 and above
* Using latest api "serviceCurrentRadioAccessTechnology" from CoreTelephony framework to detect cellular connection type for iOS 13 and above
* Does not collect Advertising Identifier to comply with Apple guide lines

## 4.0.6 (10/07/2020)
* Supports iOS 14 
* Support for auto collection of screen resolution
* Support for collection of dropped frame count
* Using Network.framework to detect connection type for iOS/tvOS 12 and above
* Using latest api "serviceCurrentRadioAccessTechnology" from CoreTelephony framework to detect cellular connection type for iOS 13 and above
* Using "AppTrackingTransparency" to collect Advertising Identifier from iOS/tvOS 14 and above
* Supports Advertising identifier collection

## 4.0.5 (07/15/2020)
* Fixes attachplayer issue when detachplayer and attachplayer methods are called back to back for legacy integration
* Does not collect Advertising Identifier to comply with Apple guide lines

## 4.0.4 (07/15/2020)
* Fixes attachplayer issue when detachplayer and attachplayer methods are called back to back for legacy integration
* Supports Advertising identifier collection


## 4.0.3 (06/25/2020)
* Support for auto detection of connection type (Ethernet) in tvOS.
* Uses 2.143.xx series versioning for older integrations that uses Core SDK version 4.x.x+.
* Bug Fixes.

## 4.0.2 (06/25/2020)
* Support for auto detection of connection type (Ethernet) in tvOS.
* Uses 2.143.xx series versioning for older integrations that uses Core SDK version 4.x.x+.
* Bug Fixes.

## 4.0.1 (05/29/2020)
* Simplified SDK with simple and fewer api's and less integration steps. Does not collect AD Identifier to comply with Apple guide lines.

## 4.0.0 (05/29/2020)
* Simplified SDK with simple and fewer api's and less integration steps. 

## 2.142.6 (04/22/2020)
* Fixes an issue where same version is reported in heart beat for both Advertising Identifier enabled and disabled frameworks.

## 2.142.5 (12/13/2019)
* Supports Data collection and Data compliance as per GDPR and CCPA. Does not collect AD Identifier to comply with Apple guide lines.
* Introduces new API setUserPreferenceForDataCollection() for setting user preferences to opt-out of user data collection.
* Introduces new API setUserPreferenceForDataDeletion() for setting user preferences to delete previously collected user data.

## 2.141.4 (08/17/2019)
* Supports iOS 12.3.
* Introduces a new API for customers to set CDN Edge Server IP Address.

## 2.141.3 (06/28/2019)
* Fixes an issue which was preventing proper session closing.
* There are metadata values which need to be updated before first video frame appears (Viewer ID, Stream Type, Player Name, Content Length, Custom Tags).
* If any/all of these metadata values are not reported at the time of session creation, we log a warning for the same metadata value(s) from this release.

## 2.141.2 (11/29/2018)
* Supports iOS/tvOS 12
* Fixes an issue where video monitoring session was not seen on Experience Insights when gatewayURL was not provided.

## 2.141.1 (07/11/2018)
* Fixes issue of logBuffer access by multiple threads
* Fixes x-code warnings

## 2.141.0 (05/31/2018)
* Supports Cocoapods deployment method
* Enhances tag handling: ignores non-string tag value and sets tag value to "null" if application provides empty string
* Deprecates updateContentMetadata API from CISPlayerStateManagerProtocol and moves it to CISClientProtocol
