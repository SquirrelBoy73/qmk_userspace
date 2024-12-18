/*
Copyright 2024 @SquirrelBoy73
Copyright 2024 Kevin Nyhoff <@SquirrelBoy73>

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

#pragma once
#include QMK_KEYBOARD_H

//#define LAYOUT_34key_w(...) LAYOUT_3_5_2(__VA_ARGS__)

/* Normal layer stuff */
enum layers {
    QWRTY,
    JPN,
    NAV,
    NUM,
    SYM,
    JSYM,
    FUN,
    KEBF,
    SAFE_LAYER, // start of usable layers in keymap!
};


/* My keycodes */
enum my_keycodes {
    KEEB,
    JPN_TG,
};

#define L_DESK LCTL(LGUI(KC_LEFT))
#define R_DESK LCTL(LGUI(KC_RIGHT))

/* General stuff for keys */
#define __TRANS_ROW__ _______, _______, _______, _______, _______,
#define __TRANS_TH__ _______, _______,

/* QWERTY Layer */
#define __QWERTY_LR1__ KC_Q, KC_W, KC_E, KC_R, KC_T,

#define __QWERTY_LR2__ MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F, KC_G,

#define __QWERTY_LR3__ MT(MOD_LGUI, KC_Z), KC_X, KC_C, KC_V, KC_B,

#define __QWERTY_LT__  LT(SYM, KC_BSPC), LT(NUM,KC_TAB),

#define __QWERTY_RR1__ KC_Y, KC_U, KC_I, KC_O, KC_P,

#define __QWERTY_RR2__ KC_H, KC_J, KC_K, KC_L, MT(MOD_RCTL, KC_ENT),

#define __QWERTY_RR3__ KC_N, KC_M, KC_ESC, KC_RALT, MT(MOD_RGUI, KC_APP),

#define __QWERTY_RT__  OSM(MOD_RSFT), LT(NAV, KC_SPC),
/* QWERTY Layer */

/* Japanese Layer (Currently only change thumb keys) */
#define __JAPAN_LT__ LT(JSYM, KC_BSPC), _______,
/* Japanese Layer (Currently only change thumb keys) */

/* Navigaton Layer */
#define __NAV_LR1__ _______, _______, _______, _______, L_DESK,

#define __NAV_LR2__ KC_VOLU, XXXXXXX, KC_LCTL, KC_LSFT, KC_HOME,

#define __NAV_LR3__ KC_VOLD, KC_MPLY, XXXXXXX, CW_TOGG, KC_MUTE,

#define __NAV_RR1__ R_DESK, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT,

#define __NAV_RR2__  KC_END,    KC_LEFT,    KC_DOWN,    KC_UP,     KC_RGHT,

#define __NAV_RR3__ _______,    KC_WH_L,    KC_WH_D,  KC_WH_U,     KC_WH_R,
/* Navigaton Layer */

/* Gaming Function Keys */
#define __GFUN_LR1__ LALT(KC_F1), LALT(KC_F2), LALT(KC_F3), LALT(KC_F4), LALT(KC_F5),

#define __GFUN_LR2__ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,

#define __GFUN_LR3__ LCTL(KC_F1), LCTL(KC_F2), LCTL(KC_F3), LCTL(KC_F4), LCTL(KC_F5),

#define __GFUN_RR1__ LALT(KC_F6), LALT(KC_F7), LALT(KC_F8), LALT(KC_F9), LALT(KC_F10),

#define __GFUN_RR2__ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,

#define __GFUN_RR3__ LCTL(KC_F6), LCTL(KC_F7), LCTL(KC_F8), LCTL(KC_F9), LCTL(KC_F10),
/* Gaming Function Keys */

/* Number Layer */
#define __NUM_RR1__ KC_ASTR, KC_7, KC_8, KC_9, KC_BSPC,

#define __NUM_RR2__ KC_PLUS, KC_4, KC_5, KC_6, KC_F1,

#define __NUM_RR3__ KC_SLSH, KC_1, KC_2, KC_3, KC_DOT,

#define __NUM_THR__ KC_PMNS, _______,
/* Number Layer */

/* Symbol Layer */
#define __SYM_LR1__ KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,

#define __SYM_LR2__ KC_COLN, KC_LBRC, KC_LCBR, KC_LPRN, KC_DQUO,

#define __SYM_LR3__ KC_QUES,   KC_LT,   KC_GT, KC_UNDS,  KC_EQL,

#define __SYM_RR1__ KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE,

#define __SYM_RR2__ KC_QUOT, KC_RPRN, KC_RCBR, KC_RBRC, KC_SCLN,

#define __SYM_RR3__ KC_TILD, KC_MINS, KC_COMM,  KC_DOT, KC_SLSH,
/* Symbol Layer */

/* Japan Symbol Layer (For making sure symbols don't move on Japanese keyboard computer's) */
#define __JSYM_LR1__ JP_EXLM,   JP_AT, JP_HASH,  JP_DLR, JP_PERC,

#define __JSYM_LR2__ JP_COLN, JP_LBRC, JP_LCBR, JP_LPRN, JP_DQUO,

#define __JSYM_LR3__ JP_QUES, JP_LABK, JP_RABK, JP_UNDS,  JP_EQL,

#define __JSYM_RR1__ JP_CIRC, JP_AMPR, JP_ASTR, JP_BSLS, JP_PIPE,

#define __JSYM_RR2__ JP_QUOT, JP_RPRN, JP_RCBR, JP_RBRC, JP_SCLN,

#define __JSYM_RR3__ JP_TILD, JP_MINS, JP_COMM,  JP_DOT, JP_SLSH,
/* Japan Symbol Layer (For making sure symbols don't move on Japanese keyboard computer's) */

/* Keyboard Layer */
#define __KEEB_RGB1__ RGB_VAI, RGB_SAI, RGB_HUI,  JPN_TG,  RGB_TOG,

#define __KEEB_RGB2__ RGB_VAD, RGB_SAD, RGB_HUD, XXXXXXX,  RGB_MOD,

#define __KEEB_RGB3__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

#define __KEEB_BOOT__ XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT,

#define __KEEB_BIOS__ KC_F11, KC_F12, KC_DEL, XXXXXXX, XXXXXXX,
/* Keyboard Layer */
