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

#import "PAGFile.h"
#import "PAGImage.h"
#import "PAGLayer.h"

@class PAGView;
@protocol PAGViewListener <NSObject>

@optional
/**
 * Notifies the start of the animation.
 */
- (void)onAnimationStart:(PAGView *)pagView;

/**
 * Notifies the end of the animation.
 */
- (void)onAnimationEnd:(PAGView *)pagView;

/**
 * Notifies the cancellation of the animation.
 */
- (void)onAnimationCancel:(PAGView *)pagView;

/**
 * Notifies the repetition of the animation.
 */
- (void)onAnimationRepeat:(PAGView *)pagView;

/**
 * Notifies the start of the animation.
 */
- (void)onAnimationStart DEPRECATED_MSG_ATTRIBUTE("Please use onAnimationStart:pagView instead");

/**
 * Notifies the end of the animation.
 */
- (void)onAnimationEnd DEPRECATED_MSG_ATTRIBUTE("Please use onAnimationEnd:pagView instead");

/**
 * Notifies the cancellation of the animation.
 */
- (void)onAnimationCancel DEPRECATED_MSG_ATTRIBUTE("Please use onAnimationCancel:pagView instead");

/**
 * Notifies the repetition of the animation.
 */
- (void)onAnimationRepeat DEPRECATED_MSG_ATTRIBUTE("Please use onAnimationRepeat:pagView instead");

@end

@interface PAGView : UIView

/**
 * Default is NO.
 */
@property (nonatomic) BOOL sync;

/**
 * Adds a listener to the set of listeners that are sent events through the life of an animation, such as start, repeat, and end.
 */
- (void)addListener:(id <PAGViewListener>)listener;

/**
 * Removes a listener from the set listening to this animation.
 */
- (void)removeListener:(id <PAGViewListener>)listener;

/**
 * Indicates whether or not this pag view is playing.
 */
- (BOOL)isPlaying;

/**
 * Start the animation.
 */
- (void)play;

/**
 * Stop the animation.
 */
- (void)stop;

/**
 * Set the number of times the animation will repeat. The default is 1, which means the animation will play only once.
 * 0 means the animation will play infinity times.
 */
- (void)setRepeatCount:(int)repeatCount;

/**
 * The path string of a pag file set by setPath.
 */
- (NSString*)getPath;

/**
 * Load a pag file from the specified path, returns false if the file does not exist or the data is not a pag file.
 * Note: All PAGFiles loaded by the same path share the same internal cache. The internal cache is alive until all
 * PAGFiles are released. Use '[PAGFile Load:size:]' instead if you don't want to load a PAGFile from the internal caches.
 */
- (BOOL)setPath:(NSString*)filePath;

/**
 * Returns the current PAGComposition for PAGView to render as content.
 */
- (PAGComposition*)getComposition;

/**
 * Sets a new PAGComposition for PAGView to render as content.
 * Note: If the composition is already added to another PAGView, it will be removed from the previous PAGView.
 */
- (void)setComposition:(PAGComposition*)newComposition;

/**
 * Return the value of videoEnabled property.
 */
- (BOOL)videoEnabled;

/**
 * If set false, will skip video layer drawing.
 */
- (void)setVideoEnabled:(BOOL)enable;

/**
 * If set to true, PAG renderer caches an internal bitmap representation of the static content for each layer.
 * This caching can increase performance for layers that contain complex vector content. The execution speed can
 * be significantly faster depending on the complexity of the content, but it requires extra graphics memory.
 * The default value is true.
 */
- (BOOL)cacheEnabled;

/**
 * Set the value of cacheEnabled property.
 */
- (void)setCacheEnabled:(BOOL)value;

/**
 * This value defines the scale factor for internal graphics caches, ranges from 0.0 to 1.0. The scale factors less than
 * 1.0 may result in blurred output, but it can reduce the usage of graphics memory which leads to better performance.
 * The default value is 1.0.
 */
- (float)cacheScale;

/**
 * Set the value of cacheScale property.
 */
- (void)setCacheScale:(float)value;

/**
 * The maximum frame rate for rendering. If set to a value less than the actual frame rate from PAGFile, it drops
 * frames but increases performance. Otherwise, it has no effect. The default value is 60.
 */
- (float)maxFrameRate;

/**
 * Set the maximum frame rate for rendering.
 */
- (void)setMaxFrameRate:(float)value;

/**
 * Returns the current scale mode.
 */
- (PAGScaleMode)scaleMode;

/**
 * Specifies the rule of how to scale the pag content to fit the surface size. The matrix
 * changes when this method is called.
 */
- (void)setScaleMode:(PAGScaleMode)value;

/**
 * Returns a copy of current matrix.
 */
- (CGAffineTransform)matrix;

/**
 * Set the transformation which will be applied to the composition. The method is valid only
 * when the scaleMode is PAGScaleMode.None.
 */
- (void)setMatrix:(CGAffineTransform)value;

/**
 * The duration of current composition in microseconds.
 */
- (int64_t)duration;

/**
 * Returns the current progress of play position, the value is from 0.0 to 1.0. It is applied only when the composition
 * is not null.
 */
- (double)getProgress;

/**
 * Set the progress of play position, the value is from 0.0 to 1.0.
 */
- (void)setProgress:(double)value;

/**
 * Call this method to render current position immediately. If the play() method is already
 * called, there is no need to call it. Returns true if the content has changed.
 */
- (BOOL)flush;

/**
 * Returns an array of layers that lie under the specified point.
 * The point is in pixels, convert dp to pixel by multiply [UIScreen mainScreen].scale, eg: point.x * scale,point.y* scale.
 */
- (NSArray<PAGLayer*>*)getLayersUnderPoint:(CGPoint)point;

/**
 * Free the cache created by the pag view immediately. Can be called to reduce memory pressure.
 */
- (void)freeCache;

/**
 * [Deprecated](Please use 'getComposition' instead) Returns the current PAGFile object.
 */
- (PAGFile*)getFile DEPRECATED_MSG_ATTRIBUTE("Please use 'getComposition' instead");

/**
 * [Deprecated](Please use 'setPath' or 'setComposition' instead) Set the PAGFile object for PAGView to render.
 */
- (void)setFile:(PAGFile*)newFile DEPRECATED_MSG_ATTRIBUTE("Please use 'setComposition' instead");

/**
 * [Deprecated](Please use 'getComposition' instead) Returns get the root PAGComposition object.
 */
- (PAGComposition*)getRootComposition DEPRECATED_MSG_ATTRIBUTE("Please use 'getComposition' instead");

/**
 * [Deprecated](Please use 'flush' instead)
 * Call this method to render current position immediately. If the play() method is already
 * called, there is no need to call it. Returns true if the content has changed.
 * @param force Indicates whether the PAGView should redraw all content by force.
 */
- (BOOL)flush:(BOOL)force DEPRECATED_MSG_ATTRIBUTE("Please use 'flush' instead");

/**
 * [Deprecated](Please use '[PAGFile replaceText]'instead)
 * Update the text data of the specified index. The index ranges from 0 to PAGFile.numTexts - 1. Passing in null
 * for the data parameter will reset it to the default text data.
 */
- (void)setTextData:(int)index data:(PAGText*)value DEPRECATED_MSG_ATTRIBUTE("Please use '[PAGFile replaceText]'instead");

/**
 * [Deprecated](Please use '[PAGFile replaceImage]'instead)
 * Replace the image data of the specified index. The index ranges from 0 to PAGFile.numImages - 1. Passing in null
 * for the image parameter will reset it to the default image data.
 */
- (void)replaceImage:(int)index data:(PAGImage*)value DEPRECATED_MSG_ATTRIBUTE("Please use '[PAGFile replaceImage]'instead");

@end

