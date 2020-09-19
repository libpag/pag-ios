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
