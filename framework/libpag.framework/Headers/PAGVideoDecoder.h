#import <Foundation/Foundation.h>


@interface PAGVideoDecoder : NSObject

/**
 * Register a software decoder factory to implement the decoder fallback mechanism.
 * For further info please visit : https://pag.io/docs/plugin-decoder.html
 */
+ (void)RegisterSoftwareDecoderFactory:(void *)decoderFactory;

/**
 * Set the maximum number of hardware video decoders that can be create.
 */
+ (void)SetMaxHardwareDecoderCount:(int)maxCount;

@end


