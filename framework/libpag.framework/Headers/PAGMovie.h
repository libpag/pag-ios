#import "PAGImage.h"
#import "PAGComposition.h"

@interface PAGMovie : PAGImage

/**
 *  Creates a PAGMovie object from a PAGComposition object, returns null if the composition is null.
 */
+ (PAGMovie *)FromComposition:(PAGComposition *)composition;

/**
 * Creates a PAGMovie object from a path of a video file, return null if the file does not exist or it's not a
 * valid video file.
 */
+ (PAGMovie *)FromVideoPath:(NSString *)filePath;

/**
 * Creates a PAGMovie object from a specified range of a video file, return null if the file does not exist or
 * it's not a valid video file.
 *
 * @param startTime start time of the movie in microseconds.
 * @param duration duration of the movie in microseconds. 
 */
+ (PAGMovie *)FromVideoPath:(NSString *)filePath startTime:(int64_t)startTime duration:(int64_t)duration;

/**
 * Returns the duration of this movie in microseconds.
 */
- (int64_t)duration;

@end
