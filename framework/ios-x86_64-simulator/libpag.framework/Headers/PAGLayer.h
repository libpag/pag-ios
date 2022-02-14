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
#import "PAGMarker.h"

typedef NS_ENUM(NSInteger, PAGLayerType) {
    PAGLayerTypeUnknown,
    PAGLayerTypeNull,
    PAGLayerTypeSolid,
    PAGLayerTypeText,
    PAGLayerTypeShape,
    PAGLayerTypeImage,
    PAGLayerTypePreCompose,
};

@class PAGComposition;
@class PAGFile;

@interface PAGLayer : NSObject

/**
 * Returns the type of layer.
 */
- (PAGLayerType)layerType;

/**
 * Returns the name of the layer.
 */
- (NSString *)layerName;

/**
 * A matrix object containing values that alter the scaling, rotation, and translation of the layer.
 * Altering it does not change the animation matrix, and it will be concatenated to current animation matrix for
 * displaying.
 */
- (CGAffineTransform)matrix;

- (void)setMatrix:(CGAffineTransform)matrix;

/**
 * Resets the matrix to its default value.
 */
- (void)resetMatrix;

/**
 * The final matrix for displaying, it is the combination of the matrix property and current matrix from animation.
 */
- (CGAffineTransform)getTotalMatrix;

/**
 * Whether or not the layer is visible.
 */
- (BOOL)visible;

- (void)setVisible:(BOOL)visible;

/**
 * Ranges from 0 to PAGFile.numTexts - 1 if the layer type is text, or from 0 to PAGFile.numImages -1 if the
 * layer type is image, otherwise returns -1.
 */
- (NSInteger)editableIndex;

/**
 * Indicates the PAGComposition instance that contains this PAGLayer instance.
 */
- (PAGComposition *)parent;

/**
 * Returns the markers of current PAGLayer.
 */
- (NSArray<PAGMarker *> *)markers;

/**
 * Converts the time from the PAGLayer's (local) timeline to the PAGSurface (global) timeline. The time is in
 * microseconds.
 */
- (int64_t)localTimeToGlobal:(int64_t)localTime;

/**
 * Converts the time from the PAGSurface (global) to the PAGLayer's (local) timeline timeline. The time is in
 * microseconds.
 */
- (int64_t)globalToLocalTime:(int64_t)globalTime;

/**
 * The duration of the layer in microseconds, indicates the length of the visible range.
 */
- (int64_t)duration;

/**
 * Returns the frame rate of this layer.
 */
- (float)frameRate;

/**
 * The start time of the layer in microseconds, indicates the start position of the visible range. It could be a negative value.
 */
- (int64_t)startTime;

/**
 * Set the start time of the layer, in microseconds.
 */
- (void)setStartTime:(int64_t)time;

/**
 * The current time of the layer in microseconds, the layer is invisible if currentTime is not in the visible range
 * (startTime <= currentTime < startTime + duration).
 */
- (int64_t)currentTime;

/**
 * Set the current time of the layer in microseconds.
 */
- (void)setCurrentTime:(int64_t)time;

/**
 * Returns the current progress of play position, the value is from 0.0 to 1.0.
 */
- (double)getProgress;

/**
 * Set the progress of play position, the value ranges from 0.0 to 1.0. A value of 0.0 represents the
 * frame at startTime. A value of 1.0 represents the frame at the end of duration.
 */
- (void)setProgress:(double)value;

/**
 * Returns trackMatte layer of this layer.
 */
- (PAGLayer *)trackMatteLayer;

/**
 * Returns a rectangle that defines the original area of the layer, which is not transformed by the matrix.
 */
- (CGRect)getBounds;

/**
 * Indicate whether this layer is excluded from parent's timeline. If set to true, this layer's current time
 * will not change when parent's current time changes.
 */
- (BOOL)excludedFromTimeline;

/**
 * Set the excludedFromTimeline flag of this layer.
 */
- (void)setExcludedFromTimeline:(BOOL)value;


@end
