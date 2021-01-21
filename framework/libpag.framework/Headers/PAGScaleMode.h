typedef enum {
    // The content is not scaled.
    PAGScaleModeNone = 0,
    // The content is stretched to fit.
    PAGScaleModeStretch = 1,
    // The content is scaled with respect to the original unscaled image's aspect ratio. This is the default value.
    PAGScaleModeLetterBox = 2,
    // The content is scaled to fit with respect to the original unscaled image's aspect ratio. This results in cropping
    // on one axis.
    PAGScaleModeZoom = 3,
} PAGScaleMode;
