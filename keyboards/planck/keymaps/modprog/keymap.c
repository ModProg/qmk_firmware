/* Copyright 2015-2021 Jack Humbert
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

// 
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_leader_key.md

#include QMK_KEYBOARD_H
#include "muse.h"

#include "keymap_german.h"


enum planck_layers {
  _QWERTZ_BASE,
  _QWERTZ_M1,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

/* #define LOWER MO(_LOWER) */
/* #define RAISE MO(_RAISE) */

const key_override_t **key_overrides = (const key_override_t *[]){
    // BASE
	&ko_make_basic(MOD_MASK_SHIFT, DE_QUES, DE_EXLM),
	&ko_make_basic(MOD_MASK_ALT  , DE_Q   , DE_AT  ),
	&ko_make_basic(MOD_MASK_ALT  , DE_E   , DE_EURO),
    // Layer -1
	&ko_make_basic(MOD_MASK_SHIFT, DE_CIRC, DE_DEG),
	// &ko_make_basic(MOD_MASK_SHIFT, DE_COMM, DE_LABK),
	// &ko_make_basic(MOD_MASK_SHIFT, DE_DOT , DE_RABK),
	// &ko_make_basic(MOD_MASK_SHIFT, DE_SCLN, DE_COLN),
	// &ko_make_basic(MOD_MASK_SHIFT, DE_DQUO, DE_QUOT),
	// &ko_make_basic(MOD_MASK_SA   , DE_Q   , DE_EXLM),
	// &ko_make_basic(MOD_MASK_ALT  , DE_W   , DE_SECT),
	// &ko_make_basic(MOD_MASK_ALT  , DE_E   , DE_EURO),
	NULL // Null terminate the array of overrides!
};

#define Z_M1 MO(_QWERTZ_M1)
#define Z_M1_OS LM(_QWERTZ_M1, MOD_LGUI)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwertz Base
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  Q@  |   W  |  E€  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ?!  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |  ,;  |  .:  |  -_  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Lyr -2|  OS  | ALT  |Lyr -1|    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTZ_BASE] = LAYOUT_planck_grid(
    KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
    KC_ESC,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_QUES, OSL(_QWERTZ_M1),
    KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_ENT ,
    KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, Z_M1   , KC_SPC,  KC_SPC,  Z_M1_OS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwertz -1
 */
[_QWERTZ_M1] = LAYOUT_planck_grid(
    DE_CIRC, DE_1   , DE_2   , DE_3   , DE_4   , DE_5   , DE_6   , DE_7   , DE_8   , DE_9   , DE_0   , KC_DEL, 
    DE_LPRN, DE_RPRN, DE_LBRC, DE_RBRC, DE_QUOT, DE_DQUO, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, DE_ASTR, DE_TILD, 
    _______, DE_DLR,  DE_PERC, DE_AMPR, DE_SLSH, DE_PIPE, DE_LCBR, DE_RCBR, DE_LABK, DE_RABK, DE_PLUS, DE_HASH, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_EQL , _______ 
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
