/**
 * A protocol that can  be used to cancel the actions.
 */
@protocol CISCancelProtocol <NSObject>
/**
 * Cancels request actions.
 */
@required
-(void)cancel;

@end
