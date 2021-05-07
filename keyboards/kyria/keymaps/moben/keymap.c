// generated from users/manna-harbour_miryoku/miryoku.org  -*- buffer-read-only: t -*-

#include QMK_KEYBOARD_H

void suspend_power_down_user() { rgblight_disable_noeeprom(); }
void suspend_wakeup_init_user() { rgblight_enable_noeeprom(); }
