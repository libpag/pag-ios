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
