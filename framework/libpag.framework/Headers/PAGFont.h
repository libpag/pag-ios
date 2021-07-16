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


@interface PAGFont : NSObject

/**
 * A string with the name of the font family.
 **/
@property(nonatomic, copy) NSString *fontFamily;

/**
 * A string with the style information — e.g., “bold”, “italic”.
 **/
@property(nonatomic, copy) NSString *fontStyle;

+ (PAGFont *)RegisterFont:(NSString *)fontPath;

+ (PAGFont *)RegisterFont:(NSString *)fontPath
                   family:(NSString *)fontFamily style:(NSString *)fontStyle;

+ (PAGFont *)RegisterFont:(void *)data size:(size_t)length;

+ (PAGFont *)RegisterFont:(void *)data size:(size_t)length
                   family:(NSString *)fontFamily style:(NSString *)fontStyle;

+ (void)UnregisterFont:(PAGFont *)font;

@end
