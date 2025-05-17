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
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};


// Aliases for readability
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define KC_LCA LCA(KC_NO)

#define CTL_S    MT(MOD_LCTL, KC_S)
#define CTL_L    MT(MOD_RCTL, KC_L)
#define ALT_D    MT(MOD_LALT, KC_D)
#define ALT_K    MT(MOD_RALT, KC_K)
#define SFT_F    MT(MOD_LSFT, KC_F)
#define SFT_J    MT(MOD_RSFT, KC_J)
#define KC_EURO  RSA(KC_2)
#define SCRNSHT  SCMD(KC_4)
#define ONEPWD   LCMD(KC_BSLS)
#define CLIPBD   LAG(KC_C)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 */
    [_QWERTY] = LAYOUT(
//  ,-----------------------------------------------------.                                           ,-----------------------------------------------------.
      KC_TAB ,   KC_Q ,   KC_W ,   KC_E ,   KC_R ,   KC_T ,                                               KC_Y ,   KC_U ,   KC_I ,   KC_O ,   KC_P ,  KC_DEL,
//  |--------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_A ,  CTL_S ,  ALT_D ,  SFT_F ,   KC_G ,                                               KC_H ,  SFT_J ,  ALT_K ,  CTL_L , KC_SCLN,KC_QUOTE,
//  |--------+--------+--------+--------+--------+--------+--------+--------.       ,--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LALT,   KC_Z ,   KC_X ,   KC_C ,   KC_V ,   KC_B ,  CLIPBD,  ONEPWD,          KC_MEH, CW_TOGG,   KC_N ,   KC_M , KC_COMM, KC_DOT , KC_SLSH, SCRNSHT,
//  `--------------------------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------------------------'
                                 XXXXXXX, KC_LGUI,   NAV  ,  KC_SPC,  KC_ESC,          KC_LCA,  KC_ENT,   SYM  , KC_BSPC, XXXXXXX
//                             `--------------------------------------------'       `--------------------------------------------'
    ),


/*
 * Nav Layer: numbers, navigation
 */
    [_NAV] = LAYOUT(
//  ,-----------------------------------------------------.                                           ,-----------------------------------------------------.
      _______, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,                                             KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
//  |--------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,                                             KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------+--------+--------.       ,--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    KC_0,    KC_1,    KC_2,    KC_3,    KC_0, _______, _______,         _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  `--------------------------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------------------------'
                                 _______, _______, _______, _______, _______,         _______, _______,  ADJUST, _______, _______
//                             `--------------------------------------------'       `--------------------------------------------'
    ),

/*
 * Sym Layer: symbols
 */
    [_SYM] = LAYOUT(
//  ,-----------------------------------------------------.                                           ,-----------------------------------------------------.
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                             KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, _______,
//  |--------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_EURO, XXXXXXX, XXXXXXX, XXXXXXX,                                             KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
//  |--------+--------+--------+--------+--------+--------+--------+--------.       ,--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,         _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
//  `--------------------------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------------------------'
                                 _______, _______,  ADJUST, _______, _______,         _______, _______, _______, _______, _______
//                             `--------------------------------------------'       `--------------------------------------------'
    ),

/*
 * Function Layer: Function keys
 */
    [_FUNCTION] = LAYOUT(
//  ,-----------------------------------------------------.                                           ,-----------------------------------------------------.
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                             _______, _______, _______, _______, _______, _______,
//  |--------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+--------+--------|
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                             _______, _______, _______, _______, _______, _______,
//  |--------+--------+--------+--------+--------+--------+--------+--------.       ,--------+--------+--------+--------+--------+--------+--------+--------|
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
//  `--------------------------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------------------------'
                                 _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______
//                             `--------------------------------------------'       `--------------------------------------------'
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 */
    [_ADJUST] = LAYOUT(
//  ,-----------------------------------------------------.                                           ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______,
//  |--------+--------+--------+--------+--------+--------|                                           |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                                             RGB_TOG, RGB_MOD, RGB_SAI, RGB_HUI, RGB_VAI, _______,
//  |--------+--------+--------+--------+--------+--------+--------+--------.       ,--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,RGB_RMOD, RGB_SAD, RGB_HUD, RGB_VAD, _______,
//  `--------------------------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------------------------'
                                 _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______
//                             `--------------------------------------------'       `--------------------------------------------'
    ),
};


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        if (IS_LAYER_ON(_SYM)) {
            if (clockwise) {
                tap_code(KC_RBRC);
                tap_code(KC_Y);
            } else {
                tap_code(KC_LBRC);
                tap_code(KC_Y);
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    } else if (index == 1) {
        if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                tap_code16(C(KC_I));
            } else {
                tap_code16(C(KC_O));
            }
        } else {
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        }
    }
    return false;
}
#endif
