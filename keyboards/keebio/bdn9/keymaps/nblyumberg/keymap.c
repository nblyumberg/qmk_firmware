/* Copyright 2020 Nick Blyumberg
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H


/**
 * Layer Names
 */
enum bdn9_layers {
    BASE = 0,
    ADJUST
};

/**
 * Encoder Names
 */
enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        Layer: Base
        ┌───────────┐  ┌───────────┐
        │   LEnc    │  │    REnc   │
        │  Prev Nxt │  │ Vol- Vol+ │
        ├────────┬──┴──┴──┬────────┤
        │Ply/Pau │ Layer1 │  Mute  │  //Top Row
        ├────────┼────────┼────────┤
        │ ?????? │ ?????? │  ????? │  //Mid Row
        ├────────┼────────┼────────┤
        │ ???????│ ?????? │  ????? │  //Bottom Row
        └────────┴────────┴────────┘
     */
    [BASE] = LAYOUT(
        KC_MPLY, TG(1), KC_MUTE,
        KC_A, KC_B, KC_C,
        KC_D, KC_E, KC_F
    ),
    /*
        Layer: Media
        ┌───────────┐  ┌───────────┐
        │    Vol    │  │   Track   │
        │  Prv  Nxt │  │  Prv  Nxt │
        ├────────┬──┴──┴──┬────────┤
        │  Mute  │ Player │  Sync  │
        ├────────┼────────┼────────┤
        │ YT<10s │ YT Ply │ YT>10s │
        ├────────┼────────┼────────┤
        │  Left  │  Spce  │  Rght  │
        └────────┴────────┴────────┘
     */
    [ADJUST] = LAYOUT(
        KC_MPLY, _______, KC_MUTE,
        KC_U, RESET, KC_W,
        KC_X, KC_Y, KC_Z
    ),
};

/**
 * Encoder
 */

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_X);
        } else {
            tap_code(KC_Y);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

void rgb_matrix_indicators_kb(void) {
    //rgblight_sethsv_noeeprom(HSV_BLUE);
    switch (get_highest_layer(layer_state)) {
        case 0:
            break;
        case 1:
            // Red
            rgb_matrix_set_color_all(0,0,0);
            rgb_matrix_set_color(5, 255, 0, 0);
            break;
        case 2:
            // Blue
            rgb_matrix_set_color(4, 0, 255, 0);
            break;
        default:
            break;
    }
}
