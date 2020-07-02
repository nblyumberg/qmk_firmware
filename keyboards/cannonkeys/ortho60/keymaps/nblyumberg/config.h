#pragma once

// Time out one shot layers after 3 seconds
#define ONESHOT_TIMEOUT 3000

#undef RGBLED_NUM
#define RGBLED_NUM 8

// Undef and redefine default brightness to half of 255
#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 255

//Define a preview timeout for RGB reviews
#define PREVIEW_TIMEOUT 5000
#define TAPPING_TERM 300

// Enable Light Layers implementation
#define RGBLIGHT_LAYERS
// Allow Light Layers to override RGB off configuration
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
