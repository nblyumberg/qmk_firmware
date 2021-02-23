#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
// Define my own sounds
#define NICK_SOUND HD_NOTE(_C8), HD_NOTE(_D3), HD_NOTE(_C6)


float layer0_song[][2] = SONG(NICK_SOUND);
float layer1_song[][2] = SONG(COLEMAK_SOUND);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default Layer
  [0] = LAYOUT(
    TG(1) , KC_A,
    TG(2) , KC_B
  ),
  //2nd layer
  [1] = LAYOUT(
    _______ , RESET,
    _______ , EEPROM_RESET
  ),
    //2nd layer
  [2] = LAYOUT(
    _______ , RESET,
    _______ , EEPROM_RESET
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

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}


#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
        render_logo();
        oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n\nLayer1   A\nLayer2   B"), false);

            break;
        case 1:
            oled_write_P(PSTR("FN\n\nBack    Reset\nBack    EEPROM Reset"), false);
            break;
        case 2:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif

