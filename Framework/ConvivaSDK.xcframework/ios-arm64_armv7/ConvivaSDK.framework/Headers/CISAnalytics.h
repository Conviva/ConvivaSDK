//
//  CISAnalytics.h
//
//  Created by Butchi peddi on 07/02/20.
//  Copyright © 2020 Conviva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CISVideoAnalytics.h"
#import "CISAdAnalytics.h"
#import "CISClientSettingProtocol.h"
#import "CISSystemInterfaceProtocol.h"
#import "CISClientProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol CISAnalyticsProtocol <NSObject>

/**
* Returns client id.
* @return clientid.
*/
- (NSString*) getClientId;

/**
* Creates video analytics objects.
* @return CISVideoAnalytics instance.
*/
- (CISVideoAnalytics) createVideoAnalytics;

/**
* Applicable only incase of  Conviva Module case. Creates video analytics objects.
* @param options Refer USER OPTIONS section defined in CSSConstants.h
* @return CISVideoAnalytics instance.
*/
- (CISVideoAnalytics) createVideoAnalytics:(NSDictionary*)options;

/**
* Creates ad analytics objects.
* @return CISAdAnalytics instance.
*/
- (CISAdAnalytics) createAdAnalytics;

/**
* Creates ad analytics object by linking already created video analytics object.
* @param videoAnalytics Video analytcis object.
* @return CISAdAnalytics instance.
*/
- (CISAdAnalytics) createAdAnalyticsWithVideoAnalytics:(CISVideoAnalytics) videoAnalytics;

/**
* Reports app level event.
* @param event Event name.
* @param details Event details.
*/
- (void) reportAppEvent:(NSString*)event details:(NSDictionary*)details;

/**
* Reports app background event useful to initiate cleanup.
*/
- (void) reportAppBackgrounded;

/**
* Reports app forground event useful to resume the analytics session.
*/
- (void) reportAppForegrounded;

/**
* @brief Set user preferences for data collection.
* @param userPrefs pass key value pair as user preferences.
* Currently Supported keys: "idfa", "idfv".
* Expected Values:
* YES - Will collect id for mentioned key.
* NO - Will stop collecting id for mentioned key.
* Sample Usage:
* [clientSettings setUserPreferenceForDataCollection:[NSDictionary dictionaryWithObjectsAndKeys: @YES, @"idfa", @NO, @"idfv", nil]];
*/
- (void) setUserPrefsForDataCollection:(NSDictionary *)userPrefs;

/**
 * @brief Set user preferences for data collection.
 * @param userPrefs pass key value pair as user preferences.
 * Currently Supported keys: "idfa", "idfv".
 * Expected Values:
 * YES - Will stop collecting id for mentioned key and delete previously collected data.
 * NO - Will not have any effect.
 * Sample Usage:
 * [clientSettings setUserPreferenceForDataDeletion:[NSDictionary dictionaryWithObjectsAndKeys: @NO, @"idfa", @YES, @"idfv", nil]];
*/
- (void) setUserPrefsForDataDeletion:(NSDictionary *)userPrefs;

/**
* Performs required cleanup.
*/
- (void) cleanup;

@end

typedef id<CISAnalyticsProtocol> CISAnalytics;

NS_ASSUME_NONNULL_END
