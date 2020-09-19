typedef enum {
    // Keep the original playing speed, and display the last frame if the content's duration is less than target duration.
    PAGTimeStretchModeNone = 0,
    // Change the playing speed of the content to fit target duration.
    PAGTimeStretchModeScale = 1,
    // Keep the original playing speed, but repeat the content if the content's duration is less than target duration.
    // This is the default mode.
    PAGTimeStretchModeRepeat = 2,
    // Keep the original playing speed, but repeat the content in reversed if the content's duration is less than
    // target duration.
    PAGTimeStretchModeRepeatInverted = 3,
} PAGTimeStretchMode;
