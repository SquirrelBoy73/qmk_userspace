/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>
#include "keymap_japanese.h"

#include "../../layouts/3_5_2/layout.h"


//my globals
bool bJpn = 0;

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t delete_keyoverride = ko_make_basic(MOD_MASK_SHIFT, LT(SYM, KC_BSPC), KC_DEL);
const key_override_t del_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(JSYM, KC_BSPC), KC_DEL);

const key_override_t *key_overrides[] = {
	&delete_keyoverride,
    &del_key_override,
};
#endif

#define LAYOUT_wrapper(...)       LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWRTY] = LAYOUT_wrapper(
  //|-----------------|        |-----------------|
      XXXXXXX, __QWERTY_LR1__            __QWERTY_RR1__ XXXXXXX,
  //|-----------------|        |-----------------|
      XXXXXXX, __QWERTY_LR2__            __QWERTY_RR2__ XXXXXXX,
  //|-----------------|        |-----------------|
      XXXXXXX, __QWERTY_LR3__            __QWERTY_RR3__ XXXXXXX,
  //|-----------------|        |-----------------|
             XXXXXXX, __QWERTY_LT__  __QWERTY_RT__ XXXXXXX

         //`-------------'  `--------------'
  ),

  [JPN] = LAYOUT_wrapper(
  //|----------------|      |-----------------|
      XXXXXXX, __TRANS_ROW__          __TRANS_ROW__ XXXXXXX,
  //|----------------|      |-----------------|
      XXXXXXX, __TRANS_ROW__          __TRANS_ROW__ XXXXXXX,
  //|----------------|      |-----------------|
      XXXXXXX, __TRANS_ROW__          __TRANS_ROW__ XXXXXXX,
  //|----------------|      |-----------------|
         XXXXXXX, __JAPAN_LT__    __TRANS_TH__ XXXXXXX
       //`------------'  `-------------'
  ),

  [NAV] = LAYOUT_wrapper(
  //|-------------|      |-------------|
      XXXXXXX, __NAV_LR1__         __NAV_RR1__ XXXXXXX,
  //|-------------|      |-------------|
      XXXXXXX, __NAV_LR2__         __NAV_RR2__ XXXXXXX,
  //|-------------|      |-------------|
      XXXXXXX, __NAV_LR3__         __NAV_RR3__ XXXXXXX,
  //|-------------|      |-------------|
       XXXXXXX, __TRANS_TH__    __TRANS_TH__ XXXXXXX
    //`-------------'  `-------------'
  ),
  [FUN] = LAYOUT_wrapper(
  //|---------------|      |---------------|
      XXXXXXX, __GFUN_LR1__          __GFUN_RR1__ XXXXXXX,
  //|---------------|      |---------------|
      XXXXXXX, __GFUN_LR2__          __GFUN_RR2__ XXXXXXX,
  //|---------------|      |---------------|
      XXXXXXX, __GFUN_LR3__          __GFUN_RR3__ XXXXXXX,
  //|---------------|      |---------------|
          XXXXXXX, __TRANS_TH__    __TRANS_TH__ XXXXXXX
     //`--------------'  `------------'
  ),
  [NUM] = LAYOUT_wrapper(
  //|----------------|     |------------|
      XXXXXXX, __TRANS_ROW__        __NUM_RR1__ XXXXXXX,
  //|----------------|     |------------|
      XXXXXXX, __TRANS_ROW__        __NUM_RR2__ XXXXXXX,
  //|----------------|     |------------|
      XXXXXXX, __TRANS_ROW__        __NUM_RR3__ XXXXXXX,
  //|----------------|     |------------|
          XXXXXXX, __TRANS_TH__   __NUM_THR__ XXXXXXX
      //`--------------' `-----------'
  ),
  [SYM] = LAYOUT_wrapper(
  //|---------------|       |--------------|
      XXXXXXX, __SYM_LR1__            __SYM_RR1__ XXXXXXX,
  //|---------------|       |--------------|
      XXXXXXX, __SYM_LR2__            __SYM_RR2__ XXXXXXX,
  //|---------------|       |--------------|
      XXXXXXX, __SYM_LR3__            __SYM_RR3__ XXXXXXX,
  //|---------------|       |--------------|
          XXXXXXX, __TRANS_TH__    __TRANS_TH__ XXXXXXX
       //`------------'  `-------------'
    ),
  [JSYM] = LAYOUT_wrapper(
  //|---------------|    |--------------|
      XXXXXXX, __JSYM_LR1__        __JSYM_RR1__ XXXXXXX,
  //|---------------|    |--------------|
      XXXXXXX, __JSYM_LR2__        __JSYM_RR2__ XXXXXXX,
  //|---------------|    |--------------|
      XXXXXXX, __JSYM_LR3__        __JSYM_RR3__ XXXXXXX,
  //|---------------|    |--------------|
         XXXXXXX, __TRANS_TH__     __TRANS_TH__ XXXXXXX
    //`---------------'  `-------------'
    ),
  [KEBF] = LAYOUT_wrapper(
  //|---------------|      |---------------|
      XXXXXXX, __KEEB_RGB1__         __KEEB_BOOT__ XXXXXXX,
  //|---------------|      |---------------|
      XXXXXXX, __KEEB_RGB2__         __KEEB_BIOS__ XXXXXXX,
  //|---------------|      |---------------|
      XXXXXXX, __KEEB_RGB3__         __TRANS_ROW__ XXXXXXX,
  //|---------------|      |---------------|
         XXXXXXX, __TRANS_TH__    __TRANS_TH__ XXXXXXX
      //`-------------'  `------------'
    )

};
// clang-format on

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
// Only OLED on right side for now don't need to change things
//  if (is_keyboard_right()) {
	//return OLED_ROTATION_90;
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
//  }
/*  else {
	  return OLED_ROTATION_270;
  }
*/
//  return rotation;
}

void oled_render_layer_state(void) {

	oled_set_cursor(0, 0);

/*    oled_write_P(PSTR("Layer"), false);

	oled_set_cursor(0, 1);
*/
	switch (get_highest_layer(layer_state)) {
      case NAV:
            oled_write_ln_P(PSTR("Navi"), false);
            break;
		case NUM:
			oled_write_ln_P(PSTR("Num"),	false);
			break;
		case SYM:
			oled_write_ln_P(PSTR("Sym"),	false);
			break;
		case JSYM:
			oled_write_ln_P(PSTR("J-Sym"),  false);
			break;
		case FUN:
			oled_write_ln_P(PSTR("Funct"), false);
			break;
		case KEBF:
			oled_write_ln_P(PSTR("K-Fun"), false);
			break;
		default:
			oled_write_ln_P(PSTR("     "), false);
			break;
	}

    if(layer_state_is(KEEB))
    {
        oled_set_cursor(0,0);
        oled_write_ln_P(PSTR("Keeb"), false);
    }
	//Japanese mode display
 	oled_set_cursor(0,1);
	if(layer_state_is(JPN)) {
		oled_write_ln_P(PSTR("Japan"), false);
 	} else {
		oled_write_ln_P(PSTR("     "), false);
	}

	//Caps word status display (only works on master side, slave OLED needs different way of getting info!)
	oled_set_cursor(0, 2);
	if(is_caps_word_on()) {
		oled_write_ln_P(PSTR("CapWd"),	false);
	}
	else {
		oled_write_ln_P(PSTR("     "),	false);
	}

}

/*void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}
*/
bool oled_task_user(void) {

// Only right side OLED now so no change display
//    if (is_keyboard_right()) {
        oled_render_layer_state();
//    }
/*    else {
       oled_render_logo();
    }
*/    return false;
}
#endif // OLED Enable

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

	for(uint8_t i = led_min; i < led_max; i++) {
		if(g_led_config.flags[i] & LED_FLAG_INDICATOR) {
			if(i != 6 && i != 13 && i != 33 && i != 39) {
				rgb_matrix_set_color(i, RGB_OFF);
			}
		}
	}

	for(uint8_t i = led_min; i < led_max; i++) {
		if(g_led_config.flags[i] & LED_FLAG_INDICATOR) {
			if(i != 6 && i != 13 && i != 33 && i != 40) {
				rgb_matrix_set_color(i, RGB_OFF);
			}
		}
	}

	#ifdef UNDERGLOW_OFF
		for(uint8_t i = led_min; i < led_max; i++) {
			if(g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
				rgb_matrix_set_color(i, RGB_OFF);
			}
		}
	#endif
	return true;
}

#endif //RGB_MATRIX_ENABLE

#ifdef CAPS_WORD_ENABLE
void caps_word_set_user(bool active)
{
	#ifdef OLED_ENABLE
	oled_render_layer_state();
	#endif
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	switch (keycode) {
		case JPN_TG:
			if(!record->event.pressed) {
				if(bJpn) {
					layer_off(JPN);
				} else {
					layer_on(JPN);
				}
				bJpn = !bJpn;
                #ifdef OLED_ENABLE
				oled_task_user();
                #endif
				return false;
			}
			break;
		default:
			return true;
	}

	return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	//update the tri layer state, hoping this will fix the timing problems
//	state = update_tri_layer_state(state, L_NAV, L_NUM, L_KEEB);
    if(IS_LAYER_ON(SYM))
    {
        state = update_tri_layer_state(state, SYM, NAV, KEBF);
    }
    else if(IS_LAYER_ON(JSYM))
    {
        state = update_tri_layer_state(state, JSYM, NAV, KEBF);
    }
    else
    {
        state = update_tri_layer_state(state, NUM, NAV, FUN);
        state = update_tri_layer_state(state, SYM, NAV, KEBF);
        state = update_tri_layer_state(state, JSYM, NAV, KEBF);
    }
    return state;
}
