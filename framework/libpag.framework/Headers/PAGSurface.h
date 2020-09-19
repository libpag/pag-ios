#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreVideo/CoreVideo.h>
#import "PAGImageLayer.h"

@interface PAGSurface : NSObject

+ (PAGSurface*)FromLayer:(CAEAGLLayer*)layer;

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
- (BOOL)present;

/**
 * Free the cache created by the surface immediately. Can be called to reduce memory pressure.
 */
- (void)freeCache;

/**
 * Returns the CVPixelBuffer object created by MakeFromGPU.
 */
- (CVPixelBufferRef)getCVPixelBuffer;

@end
