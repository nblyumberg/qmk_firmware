#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0003
#define MANUFACTURER    nxb
#define PRODUCT         2
#define DESCRIPTION     BT

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 2

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_COL_PINS { F4, F6 }
#define MATRIX_ROW_PINS { F5, F7 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW
//#define DIODE_DIRECTION ROW2COL
/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5


#define TAPPING_TERM 200

/* RGB Setup */
#define DRIVER_LED_TOTAL 1
#define RGB_DI_PIN C6
#define RGBLED_NUM 1
#define B6_AUDIO

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
#endif
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 0
