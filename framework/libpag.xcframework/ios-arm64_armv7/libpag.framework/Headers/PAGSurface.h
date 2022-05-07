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
#import <QuartzCore/QuartzCore.h>
#import <CoreVideo/CoreVideo.h>
#import "PAGImageLayer.h"

@interface PAGSurface : NSObject

/**
 * Creates a new PAGSurface from specified CAEAGLLayer. The GPU context will be created internally
 * by PAGSurface.
 */
+ (PAGSurface*)FromLayer:(CAEAGLLayer*)layer;

/**
 * Creates a new PAGSurface from specified CVPixelBuffer. The GPU context will be created internally
 * by PAGSurface.
 */
+ (PAGSurface*)FromCVPixelBuffer:(CVPixelBufferRef)pixelBuffer;

/**
 * Creates a new PAGSurface from specified CVPixelBuffer and EAGLContext. Multiple PAGSurfaces with
 * the same context share the same GPU caches. The caches are not destroyed when resetting a
 * PAGPlayer's surface to another PAGSurface with the same context.
 */
+ (PAGSurface*)FromCVPixelBuffer:(CVPixelBufferRef)pixelBuffer context:(EAGLContext*)eaglContext;

/**
 * Creates a offscreen PAGSurface of specified size. PAGSurface internally creates a CVPixelBuffer
 * which can be accessed by [PAGSurface getCVPixelBuffer] after the first [PAGPLayer flush].
 */
+ (PAGSurface*)MakeFromGPU:(CGSize)size;

/**
 * The width of surface in pixels.
 */
- (int)width;

/**
 * The height of surface in pixels.
 */
- (int)height;

/**
 * Update the size of surface, and reset the internal surface.
 */
- (void)updateSize;

/**
 * [Deprecated](Please use '[PAGPlayer flush]' instead)
 * Apply all changes to the surface. Returns true if the content has changed.
 */
- (BOOL)present DEPRECATED_MSG_ATTRIBUTE("Please use '[PAGPlayer flush]' instead");

/**
 * Erases all pixels of this surface with transparent color. Returns true if the content has changed.
 */
- (BOOL)clearAll;

/**
 * Free the cache created by the surface immediately. Can be called to reduce memory pressure.
 */
- (void)freeCache;

/**
 * Returns the CVPixelBuffer object created by MakeFromGPU.
 */
- (CVPixelBufferRef)getCVPixelBuffer;

@end
