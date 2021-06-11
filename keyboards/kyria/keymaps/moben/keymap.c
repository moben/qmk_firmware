// generated from users/manna-harbour_miryoku/miryoku.org  -*- buffer-read-only: t -*-

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"

enum rgb_layers {
    RGB_BASE,
    RGB_GAME_LEFT,
    RGB_GAME_RIGHT,
};

const rgblight_segment_t PROGMEM my_ledlayer_base[]       = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_PURPLE});
const rgblight_segment_t PROGMEM my_ledlayer_game_left[]  = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_CHARTREUSE});
const rgblight_segment_t PROGMEM my_ledlayer_game_right[] = RGBLIGHT_LAYER_SEGMENTS({10, 10, HSV_CHARTREUSE});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = {
    [RGB_BASE]       = my_ledlayer_base,
    [RGB_GAME_LEFT]  = my_ledlayer_game_left,
    [RGB_GAME_RIGHT] = my_ledlayer_game_right,
    NULL
    // comment to force clang-tidy to wrap this
};

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_set_layer_state(RGB_BASE, true);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(RGB_GAME_LEFT, layer_state_cmp(state, GML));
    rgblight_set_layer_state(RGB_GAME_RIGHT, layer_state_cmp(state, GMR));

    return state;
}

void suspend_power_down_user() { rgblight_disable_noeeprom(); }
void suspend_wakeup_init_user() { rgblight_enable_noeeprom(); }
