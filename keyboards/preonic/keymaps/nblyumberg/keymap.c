/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _BASE,     //  layer 0 (perm)
  _RAISE,    //  layer 1 (temp)
  _LOWER,    //  layer 2 (temp)
  _TRI,      //  layer 3 (temp)
  _ADJUST    //  layer 4 (temp)
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

// Light LEDs in green when keyboard base layer is active. (Note: This is never called, just used to adjust the )
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_CYAN}
);
// Light LEDs in green when keyboard raise layer is active
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_GREEN}
);
// Light LEDs in blue when keyboard lower layer is active
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_BLUE}
);
// Light LEDs in white when keyboard trilayer is active
const rgblight_segment_t PROGMEM tri_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_ORANGE}
);
// Light LEDs in purple when keyboard layer 4 is active
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    raise_layer,
    lower_layer,
    tri_layer,
    adjust_layer
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4    |   5  |   6  |   7       |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+--------+------+------+-----------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R    |   T  |   Y  |   U       |   I  |   O  |   P  | Del  |
 * |------+------+------+------+--------+-------------+-----------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F    |   G  |   H  |   J       |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+--------+------|------+-----------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V    |   B  |   N  |   M       |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+--------+------+------+-----------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lwr,Ent |    Space    |Raise,Bspc | Left | Down |  Up  |Right |
 * `------------------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,                   KC_5,    KC_6,    KC_7,                 KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                   KC_T,    KC_Y,    KC_U,                 KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,                   KC_G,    KC_H,    KC_J,                 KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,                   KC_B,    KC_N,    KC_M,                 KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, LT(_LOWER, KC_ENTER),   KC_SPC,  KC_SPC,  LT(_RAISE, KC_BSPC),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  _______,    KC_F1  ,   KC_F2,   KC_F3,    KC_F4,   KC_F5,      KC_F6,         KC_F7,      KC_F8,      KC_F9,   KC_F10,   KC_BSPC, \
  _______,    _______,   KC_UP,   _______,  _______, _______,    LSFT(KC_SLSH), _______,    _______,    _______, _______,  KC_INS,  \
  KC_CAPS,    KC_LEFT,   KC_DOWN, KC_RIGHT, _______, LSFT(KC_9), LSFT(KC_0),    KC_UNDS,    KC_PLUS,    _______, _______,  KC_PIPE, \
  KC_LSFT,    KC_F13,    KC_F14,  KC_F15,   KC_F16,  KC_BSLS,    KC_SLSH,       S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,   _______, \
  _______,    _______,   _______, _______,  _______, _______,    _______,       _______,    KC_BSPC,    KC_VOLD, KC_VOLU,  KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______,  KC_F11,    KC_F12,     KC_F13,     KC_F14,     KC_F15,     KC_F16,     KC_F17,     KC_F18,     KC_F19,    KC_F20,     KC_BSPC, \
  _______,  _______,   KC_UP  ,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,    _______, \
  _______,  KC_LEFT,   KC_DOWN,    KC_RIGHT,   _______,    KC_LBRC,    KC_RBRC,    KC_MINS,    KC_EQL,     _______,   _______,    KC_BSLS, \
  _______,  _______,   _______,    _______,    _______,    _______,    _______,    KC_NUHS,    KC_NUBS,    KC_PGUP,   KC_PGDN,    _______, \
  RGB_TOG,  RGB_MOD,   BL_INC,     BL_DEC,     _______,    _______,    _______,    _______,    KC_MNXT,    KC_VOLD,   KC_VOLU,    KC_MPLY  \
),

/* Tri
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_TRI] = LAYOUT_preonic_grid(
  RESET,    TG(_ADJUST),    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______,  _______, _______, _______, _______, TG(_ADJUST), _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  RGB_MOD,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  TO(0),
  RGB_RMOD, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _TRI);
    rgblight_set_layer_state(_RAISE, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(_LOWER, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(_TRI, layer_state_cmp(state, _TRI));
    rgblight_set_layer_state(_ADJUST, layer_state_cmp(state, _ADJUST));
    return state;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
      return false;
    case LOWER:
      return false;
    default:
      return true;
  }
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    layer_state_set_user(layer_state);
}
