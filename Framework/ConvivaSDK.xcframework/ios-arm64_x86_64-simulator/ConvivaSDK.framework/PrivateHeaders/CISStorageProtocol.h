//
//  CISStorageProtocol.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 10/03/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import "CISCallback_RunnableProtocol.h"

/**
 * Class conforming to this will be responsible for implementing required methods for storing data,
 * this is used by the Conviva library to store required data.The underlying storage technology must be reliable and data must be persisted for as long as possible.
 */

@protocol CISStorageProtocol <NSObject>
@required
/**
 * Save data on local storage.
 * Will be called when first calling Client.createSession on a new device.
 * @param storageSpace Namespace to store local data into.
 * @param storageKey Key to store local data into.
 * @param data Data to be saved.
 * @param callbackDelegate Callback to call when done.
 * If the query was successful, it must be true even if the returned data was null/empty.
 * If storage data is not persisted or persistence is flaky for your device, please contact Conviva for more information.
 */
-(void) saveData:(NSString *)storageSpace storageKey:(NSString *)storageKey data:(NSString *)data callback:(id<CISCallback_RunnableProtocol>)callbackDelegate;

/**
 * Load data from local storage.
 * Will be called when creating a client.
 * @param storageSpace Namespace to load local data from.
 * @param storageKey Key to load local data from.
 * @param callbackDelegate Callback to call when done.
 * If the query was successful, it must be true even if the returned data was null/empty.
 * Returned data can be still null if Conviva data was never saved before.
 */
-(void)loadData:(NSString *)storageSpace storageKey:(NSString *)storageKey callback:(id<CISCallback_RunnableProtocol>)callbackDelegate;

/**
 * Delete data from local storage.
 * @param storageSpace Namespace to delete local data from.
 * @param storageKey Key to delete local data from.
 * @param callbackDelegate Callback to call when done.
 */
-(void) deleteData:(NSString *)storageSpace storageKey:(NSString *)storageKey callback:(id<CISCallback_RunnableProtocol>)callbackDelegate;



/**
 * Notification that Conviva no longer needs this StorageProtocol.
 */
-(void)cleanUp;
@end
