# Changelog

## 2.141.4 (08/23/2019)
* Supports iOS 12.3.
* Introduces new API to report CDN server IP.

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
