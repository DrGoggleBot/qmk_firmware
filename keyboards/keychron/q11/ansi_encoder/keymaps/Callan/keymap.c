/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "features/achordion.h"
#include "features/caps_word.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }            
  if (!process_caps_word(keycode, record)) { return false; }



  return true;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

    switch (tap_hold_keycode) {
        case LGUI_T(KC_D):  // one handed copy pasting for qwerty for now
          if (other_keycode == KC_C || other_keycode == KC_X || other_keycode == KC_V|| other_keycode == KC_W) { return true; }
          break;

        case LCTL_T(KC_A):  // windows copy and pt
          if (other_keycode == KC_C || other_keycode == KC_X || other_keycode == KC_V|| other_keycode == KC_W) { return true; }
          break;
  }
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 500;
}


void matrix_scan_user(void) {
  achordion_task();
}


enum layers{
    BASE,
    NAV,
    COLEMAK,
    SYM,
    GAMING,
    NUM,ds
};

#define KC_TASK LGUI(KC_TAB)       
#define KC_FLXP LGUI(KC_E)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,     KC_BRID,       KC_BRIU,       KC_MCTL,       KC_LPAD,       RGB_VAD,   RGB_VAI,  KC_MPRV,       KC_MPLY,       KC_MNXT,       KC_MUTE,          KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        TG(GAMING),  KC_GRV,     KC_1,          KC_2,          KC_3,          KC_4,          KC_5,      KC_6,     KC_7,          KC_8,          KC_9,          KC_0,             KC_MINS,    KC_EQL,   _______,            KC_PGUP,
        _______,  KC_TAB,     KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,      KC_Y,     KC_U,          KC_I,          KC_O,          KC_P,             KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_ENT,     LCTL_T(KC_A),  LALT_T(KC_S),  LGUI_T(KC_D),  LSFT_T(KC_F),  KC_G,      KC_H,     RSFT_T(KC_J),  RGUI_T(KC_K),  LALT_T(KC_L),  RCTL_T(KC_SCLN),  KC_QUOT,              _______,            KC_HOME,
        _______,  _______,    KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,      KC_N,     KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,          _______,              _______,
        _______,  _______,    _______,       _______,       _______,       LT(NAV, KC_SPC),           LT(SYM, KC_BSPC),    _______,       _______,          _______,    _______,  _______,  _______),
    

    [NAV] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,     KC_F12,   _______,  _______,  NK_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,   _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  KC_UP,    _______,   _______,  _______,    _______,  _______,            _______,
        _______,  _______,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  _______,   _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  KC_LBRC,  _______,  _______,   _______,  KC_RBRC,  _______,  _______,   _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,             _______,  _______,    _______,  _______,  _______,  _______),


    [COLEMAK] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,     KC_BRID,       KC_BRIU,       KC_MCTL,       KC_LPAD,       RGB_VAD,   RGB_VAI,  KC_MPRV,       KC_MPLY,       KC_MNXT,       KC_MUTE,          KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_GRV,     KC_1,          KC_2,          KC_3,          KC_4,          KC_5,      KC_6,     KC_7,          KC_8,          KC_9,          KC_0,             KC_MINS,    KC_EQL,   _______,            KC_PGUP,
        _______,  KC_TAB,     KC_Q,          KC_W,          KC_F,          KC_P,          KC_B,      KC_J,     KC_L,          KC_U,          KC_Y,          KC_SCLN,          KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_ENT,     LCTL_T(KC_A),  LALT_T(KC_R),  LGUI_T(KC_S),  LSFT_T(KC_T),  KC_G,      KC_M,     RSFT_T(KC_N),  RGUI_T(KC_E),  LALT_T(KC_I),  RCTL_T(KC_O),     KC_QUOT,              _______,            KC_HOME,
        _______,  _______,    KC_Z,          KC_X,          KC_C,          KC_D,          KC_V,      KC_K,     KC_H,          KC_COMM,       KC_DOT,        KC_SLSH,          _______,              _______,
        _______,  _______,    _______,       _______,       _______,       LT(NAV, KC_SPC),           LT(SYM, KC_BSPC),    _______,       _______,          _______,    _______,  _______,  _______),

    
    [SYM] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),
    
    
    [NUM] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),
    
    [GAMING] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        TG(BASE),  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,  KC_LALT,  MO(SYM),         KC_SPC,                        KC_SPC,             KC_RALT,  MO(SYM), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [NAV]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [COLEMAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [GAMING] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [SYM]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
    [NUM]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE
