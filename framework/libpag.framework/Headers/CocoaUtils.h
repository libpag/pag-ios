#ifndef CocoaUtils_h
#define CocoaUtils_h

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>

#define CocoaColor UIColor
#define CocoaImage UIImage
#define CocoaTextureCacheRef CVOpenGLESTextureCacheRef
#define CocoaTextureRef CVOpenGLESTextureRef

#elif TARGET_OS_MAC

#import <AppKit/AppKit.h>

#define CocoaColor NSColor
#define CocoaImage NSImage
#define CocoaTextureCacheRef CVOpenGLTextureCacheRef
#define CocoaTextureRef CVOpenGLTextureRef

#endif

#endif
