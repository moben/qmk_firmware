/* Copyright 2020 Benedikt Morbach
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
#include "manna-harbour_miryoku.h"

enum rgb_layers {
    RGB_BASE,
    RGB_GAME_LEFT,
    RGB_GAME_RIGHT,
    RGB_QWME_LEFT,
    RGB_QWME_RIGHT,
};

const rgblight_segment_t PROGMEM my_ledlayer_base[]       = RGBLIGHT_LAYER_SEGMENTS({0, 16, HSV_PURPLE});
const rgblight_segment_t PROGMEM my_ledlayer_game_left[]  = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_CHARTREUSE}, {12, 4, HSV_CHARTREUSE});
const rgblight_segment_t PROGMEM my_ledlayer_game_right[] = RGBLIGHT_LAYER_SEGMENTS({4, 8, HSV_CHARTREUSE});
const rgblight_segment_t PROGMEM my_ledlayer_qwme_left[]  = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_GOLDENROD}, {12, 4, HSV_GOLDENROD});
const rgblight_segment_t PROGMEM my_ledlayer_qwme_right[] = RGBLIGHT_LAYER_SEGMENTS({4, 8, HSV_GOLDENROD});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = {
    [RGB_BASE]       = my_ledlayer_base,
    [RGB_GAME_LEFT]  = my_ledlayer_game_left,
    [RGB_GAME_RIGHT] = my_ledlayer_game_right,
    [RGB_QWME_LEFT]  = my_ledlayer_qwme_left,
    [RGB_QWME_RIGHT] = my_ledlayer_qwme_right,
    NULL
    // comment to force clang-tidy to wrap this
};

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_set_layer_state(RGB_BASE, true);
}

static layer_state_t exclusive_states(layer_state_t state, uint8_t layer1, uint8_t layer2) {
    if (!layer_state_is(layer1) && layer_state_cmp(state, layer1)) {
        state &= ~(1UL << layer2);
    } else if (!layer_state_is(layer2) && layer_state_cmp(state, layer2)) {
        state &= ~(1UL << layer1);
    }

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = exclusive_states(state, GML, QML);
    state = exclusive_states(state, GMR, QMR);

    rgblight_set_layer_state(RGB_GAME_LEFT, layer_state_cmp(state, GML));
    rgblight_set_layer_state(RGB_GAME_RIGHT, layer_state_cmp(state, GMR));
    rgblight_set_layer_state(RGB_QWME_LEFT, layer_state_cmp(state, QML));
    rgblight_set_layer_state(RGB_QWME_RIGHT, layer_state_cmp(state, QMR));

    return state;
}

void suspend_power_down_user() { rgblight_disable_noeeprom(); }
void suspend_wakeup_init_user() { rgblight_enable_noeeprom(); }
