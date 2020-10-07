/**
 * Callback interface used by SystemInterface implementation to notify Conviva.
 */
@protocol CISCallbackProtocol <NSObject>


@required

/**
 * Required when needed to implement an action with.
 * @param responseStatus Indicates the action response is success or failure (Indicated with BOOL)
 * @param responseMessage Success or failure response message.
 */
-(void)done:(BOOL)responseStatus responseString:(NSString *)responseMessage;

@end
