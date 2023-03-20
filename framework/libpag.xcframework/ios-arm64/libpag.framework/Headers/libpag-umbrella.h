#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "PAGDecoder.h"
#import "PAGImageView.h"
#import "PAGSurface.h"
#import "PAGView.h"
#import "CocoaUtils.h"
#import "PAG.h"
#import "PAGComposition.h"
#import "PAGFile.h"
#import "PAGFont.h"
#import "PAGImage.h"
#import "PAGImageLayer.h"
#import "PAGLayer.h"
#import "PAGMarker.h"
#import "PAGPlayer.h"
#import "PAGScaleMode.h"
#import "PAGShapeLayer.h"
#import "PAGSolidLayer.h"
#import "PAGText.h"
#import "PAGTextLayer.h"
#import "PAGTimeStretchMode.h"
#import "PAGVideoDecoder.h"
#import "PAGVideoRange.h"

FOUNDATION_EXPORT double libpagVersionNumber;
FOUNDATION_EXPORT const unsigned char libpagVersionString[];

