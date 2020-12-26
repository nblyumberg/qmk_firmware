#include "2by2.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 0 }
}, {
  // LED Index to Physical Position
  { 0,  0 }

}, {
  // LED Index to Flag
  4
} };
#endif
