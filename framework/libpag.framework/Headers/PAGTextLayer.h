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
#include "CocoaUtils.h"

@class PAGFont;

@interface PAGTextLayer : PAGLayer

/**
 * Returns the TextLayer’s fill color.
 */
- (CocoaColor *)fillColor;

/**
 * Sets the TextLayer’s fill color.
 */
- (void)setFillColor:(CocoaColor *)color;

/**
 * Returns the TextLayer's font.
 */
- (PAGFont *)font;

/**
 * Sets the TextLayer's font.
 */
- (void)setFont:(PAGFont *)font;

/**
 * Returns the TextLayer's font size.
 */
- (CGFloat)fontSize;

/**
 * Sets the TextLayer's font size.
 */
- (void)setFontSize:(CGFloat)size;

/**
 * Returns the TextLayer's stroke color.
 */
- (CocoaColor *)strokeColor;

/**
 * Sets the TextLayer's stroke color.
 */
- (void)setStrokeColor:(CocoaColor *)color;

/**
 * Returns the TextLayer's text.
 */
- (NSString *)text;

/**
 * Set the TextLayer's text.
 */
- (void)setText:(NSString *)text;

@end
