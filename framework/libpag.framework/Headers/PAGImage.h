#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "PAGScaleMode.h"


@interface PAGImage : NSObject
/**
 * Creates a PAGImage object from a CGImage object, return null if it's not valid CGImage object.
 */
+ (PAGImage *)FromCGImage:(CGImageRef)cgImage;

/**
 * Creates a PAGImage object from a path of a image file, return null if the file does not exist or it's not a valid
 * image file.
 */
+ (PAGImage *)FromPath:(NSString *)path;

/**
 * Creates a PAGImage object from the specified byte data, return null if the bytes is empty or it's not a valid
 * image file.
 */
+ (PAGImage *)FromBytes:(const void *)bytes size:(size_t)length;

/**
 * Creates a PAGImage object from the specified CVPixelBuffer, return null if the CVPixelBuffer is invalid.
 */
+ (PAGImage *)FromPixelBuffer:(CVPixelBufferRef)pixelBuffer;

/**
 * Returns the width in pixels of the image.
 */
- (NSInteger)width;

/**
 * Returns the height in pixels of the image.
 */
- (NSInteger)height;

/**
 * Returns the current scale mode.
 */
- (PAGScaleMode)scaleMode;

/**
 * Specifies the rule of how to scale the image content to fit the original image size. The matrix
 * changes when this method is called.
 */
- (void)setScaleMode:(PAGScaleMode)value;

/**
 * Returns a copy of current matrix.
 */
- (CGAffineTransform)matrix;

/**
 * Set the transformation which will be applied to the image content. The scaleMode property
 * will be set to PAGScaleMode::None when this method is called.
 */
- (void)setMatrix:(CGAffineTransform)value;

@end
