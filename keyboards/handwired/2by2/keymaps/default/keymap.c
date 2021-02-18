#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
// Define my own sounds
#define NICK_SOUND HD_NOTE(_C8), HD_NOTE(_D3), HD_NOTE(_C6)


float layer0_song[][2] = SONG(NICK_SOUND);
float layer1_song[][2] = SONG(COLEMAK_SOUND);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default Layer
  LAYOUT(
    KC_A , KC_B,
    TG(1) , TG(2)
  ),
  //2nd layer
    LAYOUT(
    RGB_MOD , RGB_TOG,
    RESET , EEPROM_RESET
  ),
   LAYOUT(
    KC_X, KC_Y,
    KC_Z, KC_0

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
