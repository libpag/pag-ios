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

@interface PAGComposition : PAGLayer

/**
 * Make a empty PAGComposition with specified size.
 */
+ (PAGComposition *)Make:(CGSize)size;

/**
 * Returns the width of the Composition.
 */
- (NSInteger)width;

/**
 * Returns the height of the Composition.
 */
- (NSInteger)height;

/**
 * Set the size of the Composition.
 */
- (void)setContentSize:(CGSize)size;

/**
 * [Deprecated](Please use 'numChildren' instead) Returns the number of child layers of this composition.
 */
- (NSInteger)numLayers DEPRECATED_MSG_ATTRIBUTE("Please use 'numChildren' instead");

/**
 * Returns the number of child layers of this composition.
 */
- (NSInteger)numChildren;

/**
 * Returns the child layer that exists at the specified index.
 * @param index The index position of the child layer.
 * @returns The child layer at the specified index position.
 */
- (PAGLayer *)getLayerAt:(int)index;

/**
 * Returns the index position of a child layer.
 * @param child The layer instance to identify.
 * @returns The index position of the child layer to identify.
 */
- (NSInteger)getLayerIndex:(PAGLayer *)child;

/**
 * Changes the position of an existing child in the container. This affects the layering of child layers.
 * @param child The child layer for which you want to change the index number.
 * @param index The resulting index number for the child layer.
 */
- (void)setLayerIndex:(NSInteger)index layer:(PAGLayer *)child;

/**
 Add PAGLayer to current PAGComposition at the top.
 @param pagLayer specified PAGLayer to add
 @return return YES if operation succeed, otherwise NO.
 */
- (BOOL)addLayer:(PAGLayer *)pagLayer;

/**
 Add PAGLayer to current PAGComposition at the specified index.
 @param pagLayer specified PAGLayer to add
 @param index specified index where to add
 @return return YES if operation succeed,else NO.
 */
- (BOOL)addLayer:(PAGLayer *)pagLayer atIndex:(int)index;

/**
 Check whether current PAGComposition cotains the specified pagLayer.
 @param pagLayer specified layer to check
 @return return YES if the current PAGComposition contains the paglayer,else NO.
 */
- (BOOL)contains:(PAGLayer *)pagLayer;

/**
 Remove the specified PAGLayer from current PAGComposition.
 @param pagLayer specified PAGLayer to remove
 @return return the PAGLayer if remove successfully,else nil.
 */
- (PAGLayer *)removeLayer:(PAGLayer *)pagLayer;

/**
 Remove the PAGLayer at specified index from current PAGComposition.

 @param index specified index to remove
 @return return the PAGLayer if remove successfully,else nil.
 */
- (PAGLayer *)removeLayerAt:(int)index;

/**
 Remove all PAGLayers from current PAGComposition.
 */
- (void)removeAllLayers;

/**
 Swap the layers.
 @param pagLayer1 specified PAGLayer 1 to swap
 @param pagLayer2 specified PAGLayer 2 to swap
 */
- (void)swapLayer:(PAGLayer *)pagLayer1 withLayer:(PAGLayer *)pagLayer2;

/**
 Swap the layers at the specified index.
 @param index1 specified index 1 to swap
 @param index2 specified index 2 to swap
 */
- (void)swapLayerAt:(int)index1 withIndex:(int)index2;

/**
 * Returns the audio data of this composition.
 */
- (NSData *)audioBytes;

/**
 * Returns when the first frame of the audio plays in the composition's timeline.
 */
- (int64_t)audioStartTime;

/**
 * Returns the audio Markers of the composition.
 */
- (NSArray<PAGMarker *> *)audioMarkers;

/**
 * Returns an array of layers that match the specified layer name.
 */
- (NSArray<PAGLayer *> *)getLayersByName:(NSString *)layerName;

/**
 * Returns an array of layers that lie under the specified point. The point is in pixels and from this
 * PAGComposition's local coordinates.
 */
- (NSArray<PAGLayer *> *)getLayersUnderPoint:(CGPoint)point;


@end
