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
#include "features/achordion.h"

enum crkbd_layers {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _NAV,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define MOUSE MO(_MOUSE)
#define NAV MO(_NAV)

#define Q_HR_A LCTL_T(KC_A)
#define Q_HR_S LALT_T(KC_S)
#define Q_HR_D LGUI_T(KC_D)
#define Q_HR_F LSFT_T(KC_F)
#define Q_HR_J RSFT_T(KC_J)
#define Q_HR_K RGUI_T(KC_K)
#define Q_HR_L LALT_T(KC_L)
#define Q_HR_SCLN RCTL_T(KC_SCLN)

#define C_HR_A LCTL_T(KC_A)
#define C_HR_R LALT_T(KC_R)
#define C_HR_S LGUI_T(KC_S)
#define C_HR_T LSFT_T(KC_T)
#define C_HR_N RSFT_T(KC_N)
#define C_HR_E RGUI_T(KC_E)
#define C_HR_I LALT_T(KC_I)
#define C_HR_O RCTL_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  DF(_COLEMAK),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    Q_HR_A,    Q_HR_S,    Q_HR_D,    Q_HR_F,    KC_G,                         KC_H,    Q_HR_J,    Q_HR_K,    Q_HR_L, Q_HR_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ENT,   LOWER,  KC_SPC,      KC_BSPC,   RAISE,  NAV
                                      //`--------------------------'  `--------------------------'

  ),

[_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     QK_GESC,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,  C_HR_A,  C_HR_R,  C_HR_S,  C_HR_T,   KC_G,                         KC_M,    C_HR_N, C_HR_E,  C_HR_I, C_HR_O,   KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                       KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH, DF(_QWERTY),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ENT,   LOWER,  KC_SPC,      KC_BSPC,   RAISE,  NAV
                                      //`--------------------------'  `--------------------------'

  ),

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______,_______, _______, _______,                       _______, _______,  KC_UP,  _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______,_______, _______, _______,                      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______,_______, _______, _______,                      _______, _______, _______,_______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  KC_LCBR,                      KC_RCBR, KC_LPRN, KC_RPRN, KC_UNDS, KC_COLN, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CIRC, KC_EXLM, KC_HASH, KC_DLR,  KC_PERC,                      KC_AT,   KC_LBRC, KC_RBRC, KC_AMPR, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                      _______, _______, _______,_______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_BOOT, _______, _______,_______, _______, _______,                        _______, _______, _______,_______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
    
};


bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

    switch (tap_hold_keycode) {
        case Q_HR_D:  // one handed copy pasting for qwerty for now
          if (other_keycode == KC_C || other_keycode == KC_X || other_keycode == KC_V|| other_keycode == KC_W) { return true; }
          break;

        case Q_HR_A:  // windows copy and pt
          if (other_keycode == KC_C || other_keycode == KC_X || other_keycode == KC_V|| other_keycode == KC_W) { return true; }
          break;
  }
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 500;
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
    return true;
};

