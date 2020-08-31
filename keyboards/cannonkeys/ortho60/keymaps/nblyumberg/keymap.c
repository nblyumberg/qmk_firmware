/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _TRI 3
#define _FUN 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
static uint32_t rgb_preview_timer = 0;
#endif
extern rgblight_config_t rgblight_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_5x12( \
  KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,       KC_5,      KC_6,    KC_7,    KC_8,                 KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,      KC_Y,    KC_U,    KC_I,                 KC_O,    KC_P,    KC_DEL,  \
  KC_ESC,     KC_A,    KC_S,    KC_D,    KC_F,       KC_G,      KC_H,    KC_J,    KC_K,                 KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,      KC_N,    KC_M,    KC_COMM,              KC_DOT,  KC_SLSH, KC_SFTENT,  \
  KC_LCTL,    MO(_FUN), KC_LALT, KC_LGUI, LT(_LOWER,  KC_ENT),   KC_SPC,  KC_SPC,  LT(_RAISE,KC_BSPC),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

[_LOWER] = LAYOUT_ortho_5x12( \
  _______,    _______,   _______,       _______,   _______,    _______,     _______,      _______,      _______,     _______,    _______,   KC_BSPC, \
  _______,    _______,   _______,       _______,   _______,    _______,     _______,      _______,      _______,     _______,    _______,   KC_INS,  \
  _______,    KC_LEFT,   KC_UP  ,       KC_DOWN,   KC_RIGHT,   LSFT(KC_9),  LSFT(KC_0),   KC_UNDS,      KC_PLUS,     _______,    _______,   KC_PIPE, \
  KC_LSFT,    KC_F13,    KC_F14,        KC_F15,    KC_F16,     _______,     _______,      S(KC_NUHS),   S(KC_NUBS),  KC_HOME,    KC_END,    _______, \
  _______,    _______,   _______,       _______,   _______,    _______,     _______,      _______,      KC_BSPC,     KC_VOLD,    KC_VOLU,   KC_MPLY \
),

[_RAISE] = LAYOUT_ortho_5x12( \
  _______,  KC_F1,     KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,     KC_F10,     KC_F11, \
  _______,  _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,    _______,  \
  _______,  KC_LEFT,   KC_UP,      KC_DOWN,    KC_RIGHT,   KC_LBRC,    KC_RBRC,    KC_MINS,    KC_EQL,     _______,   _______,    KC_BSLS, \
  _______,  _______,   _______,    _______,    _______,    _______,    _______,    KC_NUHS,    KC_NUBS,    KC_PGUP,   KC_PGDN,    _______, \
  RGB_TOG,  RGB_MOD,   BL_INC,     BL_DEC,     _______,    _______,    _______,    _______,    KC_MNXT,    KC_VOLD,   KC_VOLU,    KC_MPLY  \
),

[_TRI] = LAYOUT_ortho_5x12( \
  RESET,          KC_F1,     KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     EEPROM_RESET, \
  KC_GRV,         _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  \
  KC_DEL,         KC_LEFT,   KC_UP,      KC_DOWN,    KC_RIGHT,   KC_LCBR,    KC_RCBR,    KC_MINS,    KC_EQL,     _______,    _______,    KC_BSLS, \
  _______,        _______,   _______,    _______,    _______,    _______,    _______,    KC_NUHS,    KC_NUBS,    KC_PGUP,    KC_PGDN,    _______, \
  RGB_HUI,        RGB_HUD,   RGB_SAI,    RGB_SAD,     _______,    _______,    _______,    _______,     RGB_RMOD,   RGB_VAD,    RGB_VAI,   RGB_MOD  \
),

[_FUN] = LAYOUT_ortho_5x12( \
  _______,     _______,     _______,      _______,      _______,      _______,    _______,      _______,      _______,      _______,      _______,     _______, \
  _______,     _______,     _______,      _______,      _______,      _______,    _______,      _______,      _______,      _______,      _______,     _______,  \
  _______,     _______,     _______,      _______,      _______,      _______,    _______,      _______,      _______,      _______,      _______,     _______, \
  _______,     _______,     _______,      _______,      _______,      _______,    _______,      _______,      _______,      _______,      _______,     _______, \
  _______,     _______,     _______,      _______,      _______,      _______,    _______,      _______,      _______,      _______,      _______,     _______  \
)
};

const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,16,HSV_ORANGE}
	);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,16,HSV_GREEN}
	);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,16,HSV_BLUE}
	);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,16,HSV_YELLOW}
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
    state = update_tri_layer_state(state, _LOWER, _RAISE, _TRI);
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
