#import "CISRunnableProtocol.h"
#import "CISCallbackProtocol.h"
/**
 * Includes CISCallbackProtocol & CISRunnableProtocol
 * platform classes where its instance is passed may need to call Run or Done methods of CISCallbackProtocol or CISRunnableProtocol
 */
@protocol CISCallback_RunnableProtocol <CISCallbackProtocol,CISRunnableProtocol>

@end
