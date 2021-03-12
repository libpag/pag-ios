#import <Foundation/Foundation.h>

@interface PAGMarker : NSObject

@property(nonatomic) long long startTime;
@property(nonatomic) long long duration;
@property(nonatomic, copy) NSString *comment;

@end
