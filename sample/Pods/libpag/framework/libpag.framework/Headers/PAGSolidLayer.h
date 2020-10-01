#import <Foundation/Foundation.h>
#import "PAGLayer.h"
#import "CocoaUtils.h"

@interface PAGSolidLayer : PAGLayer

/**
 * Returns the layer's solid color.
 */
- (CocoaColor *)solidColor;

/**
 * Set the the layer's solid color.
 */
- (void)setSolidColor:(CocoaColor *)color;

@end
