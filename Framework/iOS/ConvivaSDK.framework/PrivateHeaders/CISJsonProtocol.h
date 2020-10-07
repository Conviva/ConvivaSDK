/**
 * Used by the Conviva library to handle JSON encoding/decoding.
 */
@protocol CISJsonProtocol <NSObject>
/**
 * Encode an object into a JSON string.
 * @param dict NSDictionary An object to be encoded to JSON.
 * @returns json The resulting JSON string.
 */
-(NSString *)encode:(NSDictionary *)dict;

/**
 * Decode a JSON string into an object.
 * @param json The JSON string.
 * @returns NSDictionary The resulting decoded NSDictionary.
 */
-(NSDictionary *)decode:(NSString *)json;

@end
