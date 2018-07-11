# Changelog

## 2.141.1 (07/11/2018)
* Fixes issue of logBuffer access by multiple threads
* Fixes x-code warnings

## 2.141.0 (05/31/2018)
* Supports Cocoapods deployment method
* Enhances tag handling: ignores non-string tag value and sets tag value to "null" if application provides empty string
* Deprecates updateContentMetadata API from CISPlayerStateManagerProtocol and moves it to CISClientProtocol
