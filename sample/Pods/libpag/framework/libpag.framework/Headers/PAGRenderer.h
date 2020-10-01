#import <Foundation/Foundation.h>
#import "PAGSurface.h"
#import "PAGFile.h"
#import "PAGImage.h"
#import "PAGScaleMode.h"
#import "PAGComposition.h"

/**
 * [Deprecated](Please use PAGPlayer class instead)
 */
@interface PAGRenderer : NSObject
/**
 * [Deprecated](Please use PAGPlayer class instead) Returns the current PAGFile object.
 */
- (PAGFile *)getFile;

/**
 * [Deprecated](Please use PAGPlayer class instead) Set the PAGFile object for PAGRenderer to render.
 */
- (void)setFile:(PAGFile *)file;

/**
 * [Deprecated](Please use PAGPlayer class instead) Returns the current PAGSurface object.
 */
- (PAGSurface *)getSurface;

/**
 * [Deprecated](Please use PAGPlayer class instead) Set the PAGSurface object for PAGRenderer to render onto.
 */
- (void)setSurface:(PAGSurface *)surface;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * If set to true, PAG renderer caches an internal bitmap representation of the static content for each layer.
 * This caching can increase performance for layers that contain complex vector content. The execution speed can
 * be significantly faster depending on the complexity of the content, but it requires extra graphics memory.
 * The default value is true.
 */
- (BOOL)cacheEnabled;

/**
 * [Deprecated](Please use PAGPlayer class instead) Set the value of cacheEnabled property.
 */
- (void)setCacheEnabled:(BOOL)value;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * This value defines the scale factor for internal graphics caches, ranges from 0.0 to 1.0. The scale factors less than
 * 1.0 may result in blurred output, but it can reduce the usage of graphics memory which leads to better performance.
 * The default value is 1.0.
 */
- (float)cacheScale;

/**
 * [Deprecated](Please use PAGPlayer class instead) Set the value of cacheScale property.
 */
- (void)setCacheScale:(float)value;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * The maximum frame rate for rendering. If set to a value less than the actual frame rate from PAGFile, it drops
 * frames but increases performance. Otherwise, it has no effect. The default value is 60.
 */
- (float)maxFrameRate;

/**
 * [Deprecated](Please use PAGPlayer class instead) Set the maximum frame rate for rendering.
 */
- (void)setMaxFrameRate:(float)value;

/**
 * [Deprecated](Please use PAGPlayer class instead) Returns the current scale mode.
 */
- (PAGScaleMode)scaleMode;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Specifies the rule of how to scale the pag content to fit the surface size. The matrix
 * changes when this method is called.
 */
- (void)setScaleMode:(PAGScaleMode)value;

/**
 * [Deprecated](Please use PAGPlayer class instead) Returns a copy of current matrix.
 */
- (CGAffineTransform)matrix;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Set the transformation which will be applied to the composition. The method is valid only
 * when the scaleMode is PAGScaleMode.None.
 */
- (void)setMatrix:(CGAffineTransform)value;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Update the text data of the specified index. The index ranges from 0 to PAGFile.numTexts - 1. Passing in null
 * for the data parameter will reset it to the default text data.
 */
- (void)setTextData:(int)index data:(PAGText *)value;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Replace the image data of the specified index. The index ranges from 0 to PAGFile.numImages - 1. Passing in null
 * for the image parameter will reset it to the default image data.
 */
- (void)replaceImage:(int)index data:(PAGImage *)value;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Returns the current progress of play position, the value is from 0.0 to 1.0.
 */
- (double)getProgress;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Set the progress of play position, the value is from 0.0 to 1.0.
 */
- (void)setProgress:(double)value;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Draw current frame to the target surface. You need to call call surface.present() after the drawing manually.
 */
- (void)draw;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Apply all pending changes to the target surface. This method will automatically call call surface.present() after the
 * drawing. Returns true if the content has changed.
 * @param force Indicates whether the renderer should redraw all content by force.
 */
- (BOOL)flush:(BOOL)force;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Apply all pending changes to the target surface. This method will automatically call call surface.present() after the
 * drawing. Returns true if the content has changed.
 */
- (BOOL)flush;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Reset the renderer to its initial state, all the properties set to it will be lost.
 */
- (void)reset;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Returns get the root PAGComposition object.
 */
- (PAGComposition *)getRootComposition;

/**
 * [Deprecated](Please use PAGPlayer class instead)
 * Returns an array of layers that lie under the specified point.
 * The point is in pixels, convert dp to pixel by multiply [UIScreen mainScreen].scale, eg: point.x * scale,point.y* scale.
 */
- (NSArray<PAGLayer *> *)getLayersUnderPoint:(CGPoint)point;
@end
