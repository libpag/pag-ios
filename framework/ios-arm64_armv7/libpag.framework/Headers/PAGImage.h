///////////////////////////////////////////////////////////////////////////////////////////////////
//
//  The MIT License (MIT)
//
//  Copyright (c) 2016-present, Tencent. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
//  and associated documentation files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use, copy, modify, merge, publish,
//  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//      The above copyright notice and this permission notice shall be included in all copies or
//      substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreVideo/CoreVideo.h>
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
