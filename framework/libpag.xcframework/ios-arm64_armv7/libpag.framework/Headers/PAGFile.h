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
#import "PAGComposition.h"
#import "PAGText.h"
#import "PAGFont.h"
#import "PAGImage.h"
#import "PAGTimeStretchMode.h"

@interface PAGFile : PAGComposition
/**
 * The maximum tag level current SDK supports.
 */
+ (uint16_t)MaxSupportedTagLevel;

/***
 * Load a pag file from the specified path, return null if the file does not exist or the data is not a pag file.
 * Note: All PAGFiles loaded by the same path share the same internal cache. The internal cache is alive until all PAGFiles are released. Use '[PAGFile Load:size:]' instead if you don't want to load a PAGFile from the intenal caches.
 */
+ (PAGFile *)Load:(NSString *)path;

/**
 *  Load a pag file from byte data, return null if the bytes is empty or it's not a valid pag file.
 */
+ (PAGFile *)Load:(const void *)bytes size:(size_t)length;

/**
 * The tag level this pag file requires.
 */
- (uint16_t)tagLevel;

/**
 * The number of editable texts.
 */
- (int)numTexts;

/**
 * The number of replaceable images.
 */
- (int)numImages;

/**
 * The number of video compositions.
 */
- (int)numVideos;

/**
 * The path string of this file, returns empty string if the file is loaded from byte stream.
 */
- (NSString *)path;

/**
 * Get a text data of the specified index. The index ranges from 0 to numTexts - 1.
 * Note: It always returns the default text data.
 */
- (PAGText *)getTextData:(int)editableTextIndex;

/**
 * Replace the text data of the specified index. The index ranges from 0 to PAGFile.numTexts - 1. Passing in null
 * for the textData parameter will reset it to default text data.
 */
- (void)replaceText:(int)editableTextIndex data:(PAGText *)value;

/**
 * Replace the image data of the specified index. The index ranges from 0 to PAGFile.numImages - 1. Passing in null
 * for the image parameter will reset it to default image data.
 */
- (void)replaceImage:(int)editableImageIndex data:(PAGImage *)value;

/**
 * Return an array of layers by specified editable index and layer type.
 */
- (NSArray<PAGLayer *> *)getLayersByEditableIndex:(int)index layerType:(PAGLayerType)type;

/**
 * Indicate how to stretch the original duration to fit target duration when file's duration is changed.
 * The default value is PAGTimeStretchMode::Repeat.
*/
- (PAGTimeStretchMode)timeStretchMode;

/**
 * Set the timeStretchMode of this file.
 */
- (void)seTimeStretchMode:(PAGTimeStretchMode)value;

/**
 * Set the duration of this PAGFile. Passing a value less than or equal to 0 resets the duration to its default value.
 */
- (void)setDuration:(int64_t)duration;

/**
 * Make a copy of the original file, any modification to current file has no effect on the result file.
 */
- (PAGFile *)copyOriginal;

@end
