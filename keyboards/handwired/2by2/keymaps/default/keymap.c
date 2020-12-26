#include QMK_KEYBOARD_H

float layer0_song[][2] = SONG(QWERTY_SOUND);
float layer1_song[][2] = SONG(COLEMAK_SOUND);
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default Layer
  LAYOUT(
    KC_A , KC_B,
    MO(1) , KC_ENT
  ),
  //2nd layer
    LAYOUT(
    KC_Z , KC_Y,
    _______ , KC_ENT
  )
};

/*
layer_state_t layer_state_set_user(layer_state_t state) {
    static bool play_sound = true;
    if (layer_state_cmp(state, 0)) {
        if (play_sound) {
            PLAY_SONG(layer0_song);
            play_sound = false;
        } else {
            play_sound = true;
        }
    }
    if (layer_state_cmp(state, 1)) {
        if (!play_sound) {
            PLAY_SONG(layer1_song);
            play_sound = false;
        } else {
            play_sound = true;
        }
    }
    return state;
}
*/

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, 0)) {
        PLAY_SONG(layer0_song);
    }
    if (layer_state_cmp(state, 1)) {
        PLAY_SONG(layer1_song);
    }
    return state;
}
