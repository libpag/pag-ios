#import <Foundation/Foundation.h>

/**
 * [Deprecated](Please use PAGMovie class instead)
 */
@interface PAGVideoRange : NSObject

/**
 * The start time of the source video, in microseconds.
 */
@property(nonatomic) int64_t startTime;
/**
 * The end time of the source video (not included), in microseconds.
 */
@property(nonatomic) int64_t endTime;
/**
 * The duration for playing after applying speed.
 */
@property(nonatomic) int64_t playDuration;
/**
 * Indicates whether the video should play backward.
 */
@property(nonatomic) int64_t reversed;

@end
