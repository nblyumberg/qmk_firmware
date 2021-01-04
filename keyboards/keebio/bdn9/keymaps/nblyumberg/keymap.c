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
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
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
        KC_MPLY, TG(ONE),   KC_MUTE,
        KC_A,    KC_B,    KC_C,
        KC_X,    KC_Y,    KC_Z
    ),

    // Extra layers
    [ONE] = LAYOUT(
        TO(BASE), TO(BASE), TG(TWO),
        KC_F13,    KC_F14,    KC_F15,
        KC_F16,    KC_F17,    KC_F18
    ),

    [TWO] = LAYOUT(
        TG(TWO), TO(BASE), TG(THREE),
        KC_F19, KC_F20, KC_F21,
        KC_F22, KC_F23, KC_F24
    ),
    [THREE] = LAYOUT(
        TG(THREE), TO(BASE), TG(FOUR),
        KC_3, KC_B, KC_C,
        TG(THREE), TO(BASE), TG(FOUR)
    ),
    [FOUR] = LAYOUT(
        TG(FOUR), TO(BASE), TG(FIVE),
        KC_4, KC_B, KC_C,
        TG(FOUR), TO(BASE), TG(FIVE)
    ),
    [FIVE] = LAYOUT(
        TG(FIVE), TO(BASE), TG(SIX),
        KC_5, KC_B, KC_C,
        TG(FIVE), TO(BASE), TG(SIX)
    ),
    [SIX] = LAYOUT(
        TG(SIX), TO(BASE), TG(SEVEN),
        KC_6, KC_B, KC_C,
        TG(SIX), TO(BASE), TG(SEVEN)
    ),
    [SEVEN] = LAYOUT(
        TG(SEVEN), TO(BASE), TG(ADJUST),
        KC_7, KC_B, KC_C,
        TG(SEVEN), TO(BASE), TO(BASE)
    ),



    // End Extra layers
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
        RGB_TOG, TO(BASE), RESET,
        RGB_VAI, RGB_SAI, RGB_HUI,
        RGB_VAD, RGB_SAD, RGB_HUD
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

layer_state_t layer_state_set_user(layer_state_t state){
    xprintf("Layer State: 0b%032lb\n", state);
    return state;
}

void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            break;
        case 1:
            rgb_matrix_set_color_all(0,0,0);
            rgb_matrix_set_color(6, 0, 255, 0);
            break;
        case 2:
            rgb_matrix_set_color_all(0,0,0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            break;
        case 3:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            rgb_matrix_set_color(8, 0, 255, 0);
            break;
        case 4:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            rgb_matrix_set_color(8, 0, 255, 0);
            rgb_matrix_set_color(3, 0, 255, 0);
            break;
        case 5:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            rgb_matrix_set_color(8, 0, 255, 0);
            rgb_matrix_set_color(3, 0, 255, 0);
            rgb_matrix_set_color(4, 0, 255, 0);
            break;
        case 6:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            rgb_matrix_set_color(8, 0, 255, 0);
            rgb_matrix_set_color(3, 0, 255, 0);
            rgb_matrix_set_color(4, 0, 255, 0);
            rgb_matrix_set_color(5, 0, 255, 0);
            break;
        case 7:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            rgb_matrix_set_color(8, 0, 255, 0);
            rgb_matrix_set_color(3, 0, 255, 0);
            rgb_matrix_set_color(4, 0, 255, 0);
            rgb_matrix_set_color(5, 0, 255, 0);
            rgb_matrix_set_color(1, 0, 255, 0);
        case 8:
            // All White
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 255, 255, 255);
            rgb_matrix_set_color(7, 255, 255, 255);
            rgb_matrix_set_color(8, 255, 255, 255);
            rgb_matrix_set_color(3, 255, 255, 255);
            rgb_matrix_set_color(4, 255, 255, 255);
            rgb_matrix_set_color(5, 255, 255, 255);
            rgb_matrix_set_color(1, 255, 255, 255);
            break;
        default:
            break;
    }
}
