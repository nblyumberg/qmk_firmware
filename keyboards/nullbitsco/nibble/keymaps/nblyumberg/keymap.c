/* Copyright 2020 Jay Greco
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

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
static uint32_t rgb_preview_timer = 0;
#endif

extern rgblight_config_t rgblight_config;

enum nibble_layers {
    _BASE,
    _MAC,
    _WIN,
    _FN,
    _MACROS,
    _ADJUST,
};

enum custom_keycodes {
  KC_CUST = SAFE_RANGE,
};

// Tap Dance declarations
enum tapdance_codes{
    TD_C_COPYWIN,
    TD_C_COPYMAC,
    TD_V_PASTE,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_C_COPYMAC] = ACTION_TAP_DANCE_DOUBLE(KC_C, G(KC_C)),
    [TD_C_COPYWIN] = ACTION_TAP_DANCE_DOUBLE(KC_C, C(KC_C)),
    [TD_V_PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_V,C(KC_V)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ansi(
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
    KC_MPLY, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    TG(_MACROS), MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
    TG(_FN), KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_HOME,
    TG(_ADJUST), KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                    MO(_FN), KC_RALT, KC_RCTL, KC_LEFT,          KC_DOWN, KC_RGHT
  ),

  [_MAC] = LAYOUT_ansi(
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
    KC_MPLY, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    TG(_MACROS), MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
    TG(_FN), KC_LSFT, KC_Z,    KC_X,    TD(TD_C_COPYMAC),    TD(TD_V_PASTE),    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_HOME,
    TG(_ADJUST), KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                    MO(_FN), KC_RALT, KC_RCTL, KC_LEFT,          KC_DOWN, KC_RGHT
  ),

  [_WIN] = LAYOUT_ansi(
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
    KC_MPLY, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    TG(_MACROS), MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
    TG(_FN), KC_LSFT, KC_Z,    KC_X,    TD(TD_C_COPYWIN),    TD(TD_V_PASTE),    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_HOME,
    TG(_ADJUST), KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                    MO(_FN), KC_RALT, KC_RCTL, KC_LEFT,          KC_DOWN, KC_RGHT
  ),


  [_FN] = LAYOUT_ansi(
             RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_DEL,  KC_INS,
    _______, EEPROM_RESET, _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, KC_F13, KC_F14, KC_F15, KC_F15, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,                   MO(2),                   _______, _______, _______, _______,          _______, _______
  ),

  [_MACROS] = LAYOUT_ansi(
             RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_HOME,  KC_INS,
    _______, EEPROM_RESET, _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, KC_F13, KC_F14, KC_F15, KC_F15, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,                   _______,                   _______, _______, _______, _______,          _______, _______
  ),

  [_ADJUST] = LAYOUT_ansi(
               RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  RGB_RMOD,  RGB_MOD, KC_HOME,  KC_INS,
    RGB_TOG, EEPROM_RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,                   _______,                   _______, _______, _______, _______,          _______, _______
  ),
};

const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,16,HSV_ORANGE}
	);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,16,HSV_GREEN}
	);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,16,HSV_RED}
	);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,16,HSV_BLUE}
	);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,16,HSV_WHITE}
	);
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,16,HSV_TEAL}
	);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        my_layer0_layer,
		my_layer1_layer,
		my_layer2_layer,
		my_layer3_layer,
		my_layer4_layer,
        my_layer5_layer
	);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Allow for a preview of changes when modifying RGB
# if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
  switch (keycode) {
    case RGB_TOG ... VLK_TOG:
      for (uint8_t i = 0; i < RGBLIGHT_MAX_LAYERS; i++) {
        rgblight_set_layer_state(i, false);
      }
      rgb_preview_timer = timer_read32();
      break;
  }
# endif
  return;
}

//Set the appropriate layer color
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    return state;
}

void keyboard_post_init_user(void) {
	//Enable the LED layers
	rgblight_layers = my_rgb_layers;
	layer_state_set_user(layer_state);
}

void matrix_scan_user(void) {

# if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
    // Allow preview for
    if (rgb_preview_timer && TIMER_DIFF_32(timer_read32(), rgb_preview_timer) > PREVIEW_TIMEOUT) {
        rgb_preview_timer = 0;
        default_layer_state_set_user(default_layer_state);
        layer_state_set_user(layer_state);
        led_update_user((led_t) host_keyboard_leds());
    }
# endif
}

// RGB config, for changing RGB settings on non-VIA firmwares
void change_RGB(bool clockwise) {
    bool shift = get_mods() & MOD_MASK_SHIFT;
    bool alt = get_mods() & MOD_MASK_ALT;
    bool ctrl = get_mods() & MOD_MASK_CTRL;

    if (clockwise) {
        if (alt) {
            rgblight_increase_hue();
        } else if (ctrl) {
            rgblight_increase_val();
        } else if (shift) {
            rgblight_increase_sat();
        } else {
            rgblight_step();
        }

  } else {
      if (alt) {
            rgblight_decrease_hue();
        } else if (ctrl) {
            rgblight_decrease_val();
        } else if (shift) {
            rgblight_decrease_sat();
        } else {
            rgblight_step_reverse();
        }
    }
}

void matrix_init_user(void) {
  // Initialize remote keyboard, if connected (see readme)
  matrix_init_remote_kb();
}
