#import <Foundation/Foundation.h>

@class PAGFile;

@interface PAGFilter : NSObject

/**
* Create a PAGFilter from the specified PAGFile object and it's corresponding editableImageIndex. If the PAGFile
* object has a PAGComposition object as a parent, the object is removed from it's parent. The startTime and
* duration of PAGFilter object are in the timeline of PAGLayer's content  (0 means layer's startTime).
*/
+ (PAGFilter *)FromPAGFile:(PAGFile *)pagFile editableImageIndex:(int)editableImageIndex;

/**
* Whether or not the filter is visible.
*/
- (BOOL)visible;

/**
* Set the visible of the filter.
*/
- (void)setVisible:(BOOL)visible;

/**
* The start time of the filter in microseconds, indicates the start position of the visible range in the
* timeline of layer's content. It could be negative value.
*/
- (int64_t)startTime;

/**
* Set the start time of the filter, in microseconds.
*/
- (void)setStartTime:(int64_t)startTime;

/**
* The duration of the filter in microseconds, indicates the length of the visible range.
*/
- (int64_t)duration;

/**
* Set the duration of this filter.
*/
- (void)setDuration:(int64_t)duration;

/**
* The current time of the filter in microseconds, the layer is invisible if currentTime is not in the visible
* range (startTime <= currentTime < startTime + duration).
*/
- (int64_t)currentTime;


/**
* Set the current time of the filter, in microseconds.
*/
- (void)setCurrentTime:(int64_t)currentTime;

/**
* Indicate whether this filter is excluded from layer's timeline. If set to true, this filter's currentTime
* will not change when layer's current time changes.
*/
- (BOOL)excludedFromTimeline;

/**
* Set the excludedFromTimeline flag of this filter.
 */
- (void)setExcludedFromTimeline:(BOOL)value;

@end
