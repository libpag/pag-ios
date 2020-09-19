#ifndef CocoaUtils_h
#define CocoaUtils_h

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>

#define CocoaColor UIColor
#define CocoaImage UIImage

#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>

#define CocoaColor NSColor
#define CocoaImage NSImage

#endif

#endif
