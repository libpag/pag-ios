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

@end
