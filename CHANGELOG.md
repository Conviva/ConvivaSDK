# Changelog

## 4.0.47 (02/10/2024)
* Clearing the cached values of audio Language, subtitles/closed captions language on the start of new session.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.45 (01/31/2024)
* Supports VisionOS 1.0.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.43 (01/11/2024)
* Privacy manifest file support is added.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.41 (10/09/2023)
* Supports iOS 17.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.40 (10/09/2023)
* Supports iOS 17.
* Supports Advertising identifier collection.

## 4.0.39 (06/02/2023)
* Changed pod position constant values to Pre-roll, Mid-roll & Post-roll.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.38 (06/02/2023)
* Changed pod position constant values to Pre-roll, Mid-roll & Post-roll.
* Supports Advertising identifier collection.

## 4.0.37 (04/04/2023)
* Introduces new keys CIS_SSDK_PLAYBACK_METRIC_AUDIO_LANGUAGE, CIS_SSDK_PLAYBACK_METRIC_SUBTITLES_LANGUAGE, CIS_SSDK_PLAYBACK_METRIC_CLOSED_CAPTIONS_LANGUAGE within reportPlaybackMetric() API for setting audio track changes, subtitle track changes and closed caption track changes respectively.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.36 (04/04/2023)
* Introduces new keys CIS_SSDK_PLAYBACK_METRIC_AUDIO_LANGUAGE, CIS_SSDK_PLAYBACK_METRIC_SUBTITLES_LANGUAGE, CIS_SSDK_PLAYBACK_METRIC_CLOSED_CAPTIONS_LANGUAGE within reportPlaybackMetric() API for setting audio track changes, subtitle track changes and closed caption track changes respectively.
* Supports Advertising identifier collection.

## 4.0.35 (01/02/2023)
* Fixed an issue where connection type is not reported properly for mobile netwoek.
* Changes to support latest video events schema(1-0-4) for App Analytics. Use 0.2.6 version of app analytics library for compatability. For non AppAnalytics customers, there is not impact.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.34 (01/02/2023)
* Fixed an issue where connection type is not reported properly for mobile netwoek.
* Changes to support latest video events schema(1-0-4) for App Analytics. Use 0.2.6 version of app analytics library for compatability. For non AppAnalytics customers, there is not impact.
* Supports Advertising identifier collection.

## 4.0.33 (11/18/2022)
* Fixed an issue for metrics collection when setPlayer is called before having a valid playerItem on AVPlayer.
* Fixed an issue for bitrate reporting on switching from one content to another using AVQueuePlayer.
* Support to collect playback events from AppAnalytics SDK provided by conviva. For non AppAnalytics customers, there is not impact.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.32 (11/18/2022)
* Fixed an issue for metrics collection when setPlayer is called before having a valid playerItem on AVPlayer.
* Fixed an issue for bitrate reporting on switching from one content to another using AVQueuePlayer.
* Support to collect playback events from AppAnalytics SDK provided by conviva. For non AppAnalytics customers, there is not impact.
* Supports Advertising identifier collection.

## 4.0.31 (09/21/2022)
* Supports iOS 16.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.30 (09/21/2022)
* Supports iOS 16.
* Supports Advertising identifier collection.

## 4.0.29 (07/29/2022)
* Supports auto detection of AirPlay start & end events.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.28 (07/29/2022)
* Supports auto detection of AirPlay start & end events.
* Supports Advertising identifier collection.

## 4.0.27 (03/15/2022)
* Internal Improvements
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.26 (03/15/2022)
* Internal Improvements
* Supports Advertising identifier collection.

## 4.0.25 (02/14/2022)
* Internal Improvements
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.24 (02/14/2022)
* Internal Improvements
* Supports Advertising identifier collection.

## 4.0.23 (08/12/2021)
* Marked Legacy integration (2.x) API’s as deprecated.
* Removed support of Legacy integration (3.x) API’s.
* Supports iOS 15.1
* Does not collect Advertising Identifier to comply with Apple guide lines.


## 4.0.22 (08/12/2021)
* Marked Legacy integration (2.x) API’s as deprecated.
* Removed support of Legacy integration (3.x) API’s.
* Supports iOS 15.1
* Supports Advertising identifier collection.

## 4.0.20 (27/10/2021)
* Fixed an inconsistent crash in network layer.
* Supports Advertising identifier collection.

## 4.0.19 (30/09/2021)
* Support iOS 15.x.
* Auto collect App version.
* Marked Legacy integration API’s as deprecated.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.18 (30/09/2021)
* Support iOS 15.x.
* Auto collect App version.
* Marked Legacy integration API’s as deprecated.
* Supports Advertising identifier collection.

## 4.0.17 (02/07/2021)
* Supports iOS 14.5
* Supports Mac Catalyst
* Supports detailed error logging
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.16 (02/07/2021)
* Supports iOS 14.5
* Supports Mac Catalyst
* Supports detailed error logging
* Supports Advertising identifier collection.

## 4.0.15 (23/06/2021)

## 4.0.14 (23/06/2021)

## 4.0.13 (26/04/2021)
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.12 (26/04/2021)
* Supports Advertising identifier collection.

## 4.0.11 (01/03/2021)
* Supports iOS 14.4
* Added XCFramework Support.
* Added Swift Package Manager Support.
* Does not collect Advertising Identifier to comply with Apple guide lines.

## 4.0.10 (01/03/2021)
*  Supports iOS 14.4
* Added XCFramework Support.
* Added Swift Package Manager Support.
* Supports Advertising identifier collection.

## 4.0.9 (15/01/2021)
* Fixes an inconsistent crash on network switch(Wifi to Cellular and viceversa)
* Reports sdk version as 4.0.9L if legacy api used. If simplified api is used, it is reported as 4.0.9
* Does not collect Advertising Identifier to comply with Apple guide lines

## 4.0.8 (15/01/2021)
* Fixes an inconsistent crash on network switch(Wifi to Cellular and viceversa)
* Reports sdk version as 4.0.8L if legacy api used. If simplified api is used, it is reported as 4.0.8
* Supports Advertising identifier collection

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
