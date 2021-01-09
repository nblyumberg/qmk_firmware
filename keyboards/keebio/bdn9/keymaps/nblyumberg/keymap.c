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
#include "keymap.h"

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


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F7_CLIPSCREEN] = ACTION_TAP_DANCE_DOUBLE(KC_F7, C(S(G(KC_4)))),
    [TD_F8_CLIPSELECT] = ACTION_TAP_DANCE_DOUBLE(KC_F8, S(G(KC_5))),
    [TD_F9_TERMINAL]   = ACTION_TAP_DANCE_DOUBLE(KC_F9, C(A(KC_T))),
    [TD_F10_PASTE]     = ACTION_TAP_DANCE_DOUBLE(KC_F10, C(KC_V)),
    [TD_F11_HUESYNC]   = ACTION_TAP_DANCE_DOUBLE(KC_F11, S(G(KC_1))),
    [TD_ESC_LAYER1]    = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ESC, 1),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        Layer: Base
        ┌───────────┐  ┌───────────┐
        │   LEnc    │  │    REnc   │
        │  Prev Nxt │  │ Vol- Vol+ │
        ├────────┬──┴──┴──┬────────┤
        │Ply/Pau │ ESC/L1 │  Mute  │  //Top Row
        ├────────┼────────┼────────┤
        │ ?????? │ ?????? │  ????? │  //Mid Row
        ├────────┼────────┼────────┤
        │ ???????│ ?????? │  ????? │  //Bottom Row
        └────────┴────────┴────────┘
     */
    [BASE] = LAYOUT(
        KC_MPLY, TD(TD_ESC_LAYER1),   KC_MUTE,
        TD(TD_F7_CLIPSCREEN), TD(TD_F8_CLIPSELECT), TD(TD_F9_TERMINAL),
        TD(TD_F10_PASTE),   TD(TD_F11_HUESYNC),   KC_F12
    ),

    /*
        Layer: One (First half of upper Function Keys)
        ┌───────────┐  ┌───────────┐
        │   LEnc    │  │    REnc   │
        │  Prev Nxt │  │ Vol- Vol+ │
        ├────────┬──┴──┴──┬────────┤
        │Ply/Pau │ Layer1 │  Mute  │  //Top Row
        ├────────┼────────┼────────┤
        │  F13   │  F14   │  F15   │  //Mid Row
        ├────────┼────────┼────────┤
        │  F16   │  F17   │  F18   │  //Bottom Row
        └────────┴────────┴────────┘
     */
    [ONE] = LAYOUT(
        TO(BASE), TO(BASE), TG(TWO),
        KC_F13,    KC_F14,    KC_F15,
        KC_F16,    KC_F17,    KC_F18
    ),

    /*
        Layer: Two (Second half of upper Function Keys)
        ┌───────────┐  ┌───────────┐
        │   LEnc    │  │    REnc   │
        │  Prev Nxt │  │ Vol- Vol+ │
        ├────────┬──┴──┴──┬────────┤
        │Ply/Pau │ Base   │  //Top Row
        ├────────┼────────┼────────┤
        │  F19   │  F20   │  F21   │  //Mid Row
        ├────────┼────────┼────────┤
        │  F22   │  F23   │  F24   │  //Bottom Row
        └────────┴────────┴────────┘
     */
    [TWO] = LAYOUT(
        TG(TWO), TO(BASE), TG(THREE),
        KC_F19, KC_F20, KC_F21,
        KC_F22, KC_F23, KC_F24
    ),

    /*
        Layer: Three (GMail)
        ┌───────────┐  ┌───────────┐
        │   LEnc    │  │    REnc   │
        │  Prev Nxt │  │ Vol- Vol+ │
        ├────────┬──┴──┴──┬────────┤
        │Ply/Pau │ Layer1 │  Mute  │  //Top Row
        ├────────┼────────┼────────┤
        │  F19   │  F20   │  F21   │  //Mid Row
        ├────────┼────────┼────────┤
        │  F22   │  F23   │  F24   │  //Bottom Row
        └────────┴────────┴────────┘
     */
    [THREE] = LAYOUT(
        TG(THREE), TO(BASE), TG(FOUR),
        S(KC_3), KC_X, KC_K,
        TG(THREE), KC_U, KC_J
    ),

    /*
        Layer: Four
        ┌───────────┐  ┌───────────┐
        │   LEnc    │  │    REnc   │
        │  Prev Nxt │  │ Vol- Vol+ │
        ├────────┬──┴──┴──┬────────┤
        │Ply/Pau │ Layer1 │  Mute  │  //Top Row
        ├────────┼────────┼────────┤
        │  F19   │  F20   │  F21   │  //Mid Row
        ├────────┼────────┼────────┤
        │  F22   │  F23   │  F24   │  //Bottom Row
        └────────┴────────┴────────┘
     */
    [FOUR] = LAYOUT(
        TG(FOUR), TO(BASE), TG(FIVE),
        KC_4, KC_B, KC_C,
        TG(FOUR), TO(BASE), TG(FIVE)
    ),

    /*
        Layer: Five
        ┌───────────┐  ┌───────────┐
        │   LEnc    │  │    REnc   │
        │  Prev Nxt │  │ Vol- Vol+ │
        ├────────┬──┴──┴──┬────────┤
        │Ply/Pau │ Layer1 │  Mute  │  //Top Row
        ├────────┼────────┼────────┤
        │  F19   │  F20   │  F21   │  //Mid Row
        ├────────┼────────┼────────┤
        │  F22   │  F23   │  F24   │  //Bottom Row
        └────────┴────────┴────────┘
     */
    [FIVE] = LAYOUT(
        TG(FIVE), TO(BASE), TG(SIX),
        KC_5, KC_B, KC_C,
        TG(FIVE), TO(BASE), TG(SIX)
    ),

    /*
        Layer: Six
        ┌───────────┐  ┌───────────┐
        │   LEnc    │  │    REnc   │
        │  Prev Nxt │  │ Vol- Vol+ │
        ├────────┬──┴──┴──┬────────┤
        │Ply/Pau │ Layer1 │  Mute  │  //Top Row
        ├────────┼────────┼────────┤
        │  F19   │  F20   │  F21   │  //Mid Row
        ├────────┼────────┼────────┤
        │  F22   │  F23   │  F24   │  //Bottom Row
        └────────┴────────┴────────┘
     */
    [SIX] = LAYOUT(
        TG(SIX), TO(BASE), TG(SEVEN),
        KC_6, KC_B, KC_C,
        TG(SIX), TO(BASE), TG(SEVEN)
    ),

    /*
        Layer: Seven
        ┌───────────┐  ┌───────────┐
        │   LEnc    │  │    REnc   │
        │  Prev Nxt │  │ Vol- Vol+ │
        ├────────┬──┴──┴──┬────────┤
        │Ply/Pau │ Layer1 │  Mute  │  //Top Row
        ├────────┼────────┼────────┤
        │  F19   │  F20   │  F21   │  //Mid Row
        ├────────┼────────┼────────┤
        │  F22   │  F23   │  F24   │  //Bottom Row
        └────────┴────────┴────────┘
     */
    [SEVEN] = LAYOUT(
        TG(SEVEN), TO(BASE), TG(ADJUST),
        KC_7, KC_B, KC_C,
        TG(SEVEN), TO(BASE), TO(BASE)
    ),

    /*
        Layer: Adjustment
        ┌───────────┐  ┌───────────┐
        │    Vol    │  │   Track   │
        │  Prv  Nxt │  │  Prv  Nxt │
        ├────────┬──┴──┴──┬────────┤
        │EPRESET │Layer 0 │ Reset  │
        ├────────┼────────┼────────┤
        │ Bright+│  Sat+  │ Hue+   │
        ├────────┼────────┼────────┤
        │ Bright-│  Sat-  │ Hue-   │
        └────────┴────────┴────────┘
     */
    [ADJUST] = LAYOUT(
        EEPROM_RESET, TO(BASE), RESET,
        RGB_VAI, RGB_SAI, RGB_HUI,
        RGB_VAD, RGB_SAD, RGB_HUD
    ),
};

/**
 * Encoder
 */

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (get_highest_layer(layer_state) == 0) {  // Base layer left encoder
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        }
        if (get_highest_layer(layer_state) == 1) {  // First layer left encoder
            if (clockwise) {
                tap_code(KC_A);
            } else {
                tap_code(KC_B);
            }
        }
    } else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_X);
        } else {
            tap_code(KC_Y);
        }
    } else if (index == _RIGHT) {
        if (get_highest_layer(layer_state) == 0) {  // Base layer right encoder
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
        if (get_highest_layer(layer_state) == 1) {  // First layer right encoder
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state){
    xprintf("Layer State: 0b%032lb (%u)\n", state, get_highest_layer(state));
    return state;
}


void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case BASE:
            break;
        case ONE:
            rgb_matrix_set_color_all(0,0,0);
            rgb_matrix_set_color(6, 0, 255, 0);
            break;
        case TWO:
            rgb_matrix_set_color_all(0,0,0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            break;
        case THREE: //GMAIL Layer
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 255, 0, 0);
            rgb_matrix_set_color(7, 255, 0, 0);
            rgb_matrix_set_color(8, 255, 0, 0);
            break;
        case FOUR:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            rgb_matrix_set_color(8, 0, 255, 0);
            rgb_matrix_set_color(3, 0, 255, 0);
            break;
        case FIVE:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            rgb_matrix_set_color(8, 0, 255, 0);
            rgb_matrix_set_color(3, 0, 255, 0);
            rgb_matrix_set_color(4, 0, 255, 0);
            break;
        case SIX:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            rgb_matrix_set_color(8, 0, 255, 0);
            rgb_matrix_set_color(3, 0, 255, 0);
            rgb_matrix_set_color(4, 0, 255, 0);
            rgb_matrix_set_color(5, 0, 255, 0);
            break;
        case SEVEN:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(6, 0, 255, 0);
            rgb_matrix_set_color(7, 0, 255, 0);
            rgb_matrix_set_color(8, 0, 255, 0);
            rgb_matrix_set_color(3, 0, 255, 0);
            rgb_matrix_set_color(4, 0, 255, 0);
            rgb_matrix_set_color(5, 0, 255, 0);
            rgb_matrix_set_color(1, 0, 255, 0);
            break;
        case ADJUST:
            // Allows for a preview of RGB adjustments
            rgb_matrix_set_color(1, 255, 255, 255);
            break;
        default:
            break;
    }
}
