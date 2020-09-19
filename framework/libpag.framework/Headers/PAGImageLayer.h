#import <Foundation/Foundation.h>
#import "PAGLayer.h"
#import "PAGScaleMode.h"

@class PAGImage;
@class PAGVideoRange;

@interface PAGImageLayer : PAGLayer
/**
 * Make a PAGImageLayer with size and duration(in microseconds).
 */
+ (instancetype)Make:(CGSize)size duration:(int64_t)duration;

/**
 * [Deprecated](Please use PAGMovie class instead) Returns the time ranges of the source video for replacement.
 */
- (NSArray<PAGVideoRange *> *)getVideoRanges;

/**
 * Replace the original image content with the specified PAGImage object. Passing in null for the image parameter
 * resets the layer to its default image content. This method walks through the whole layer tree, and replaces
 * every PAGImageLayer which has the same content to this layer.
 * @param image The PAGImage object to replace with.
 */
- (void)replaceImage:(PAGImage *)image;

/**
 * Returns the preferred duration of a PAGMovie object which is used as a image replacement for this layer.
 */
- (int64_t)contentDuration;

@end
