/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#define GML COLEMAKDH_NO_HOLD_L
#define GMR COLEMAKDH_NO_HOLD_R
#define QML QWERTY_NO_HOLD_L
#define QMR QWERTY_NO_HOLD_R

#if defined OLED_DRIVER_ENABLE
#    define OLED_DISPLAY_128X64
#endif

#if defined RGBLIGHT_ENABLE
#    define RGBLIGHT_LIMIT_VAL 175
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8

#    define RGB_DISABLE_WHEN_USB_SUSPENDED true
#endif

// generated from users/manna-harbour_miryoku/miryoku.org  -*- buffer-read-only: t -*-
#define XXX KC_NO

#define TGL TG(GML)
#define TGR TG(GMR)
#define TQL TG(QML)
#define TQR TG(QMR)

// clang-format off
#define LAYOUT_miryoku( \
     K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39 \
) \
LAYOUT( \
KC_GRV,  K00, K01, K02, K03, K04,                     K05, K06, K07, K08, K09, XXX, \
KC_LSFT, K10, K11, K12, K13, K14,                     K15, K16, K17, K18, K19, KC_RSFT, \
KC_LCTL, K20, K21, K22, K23, K24, TQL, TGL, TGR, TQR, K25, K26, K27, K28, K29, KC_RCTL, \
               KC_LGUI, K32, K33, K34, XXX, XXX, K35, K36, K37, KC_RGUI \
)
