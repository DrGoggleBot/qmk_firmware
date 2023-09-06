/* Copyright 2020 Alex Daigre
 * Modified from layout provided by Jack Humbert
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
#include "muse.h"
#include "features/achordion.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  SYM,
  NAV,
  MOUSE,  
  _ADJUST,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ~Esc`|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |  ⌃A  |  ⌥S  |  ⌘D  |  ⇧F  |   G  |   H  |  ⇧J  |  ⌘K  |  ⌥L  |  ⌃;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MOUSE |  NAV |  ENT |    SPACE    |   ⌫  |  SYM |      | QWTY | CLMK |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  KC_TAB,  LCTL_T(KC_A),  LALT_T(KC_S),  LGUI_T(KC_D),  LSFT_T(KC_F),  KC_G,      KC_H,     RSFT_T(KC_J),  RGUI_T(KC_K),  LALT_T(KC_L),  RCTL_T(KC_SCLN), KC_QUOT,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  _______, _______, MO(MOUSE), MO(NAV),  KC_ENT,   KC_SPC,  KC_SPC,  KC_BSPC,  MO(SYM), _______, COLEMAK,QWERTY
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ~Esc`|   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |  ⌃A  |  ⌥R  |  ⌘S  |  ⇧T  |   G  |   M  |  ⇧N  |  ⌘E  |  ⌥I  |  ⌃O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MOUSE |  NAV |  ENT |    SPACE    |   ⌫  |  SYM |      | QWTY | CLMK |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  QK_GESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
  KC_TAB,   LCTL_T(KC_A),  LALT_T(KC_R),  LGUI_T(KC_S),  LSFT_T(KC_T),  KC_G,      KC_M,     RSFT_T(KC_N),  RGUI_T(KC_E),  LALT_T(KC_I),  RCTL_T(KC_O),    KC_QUOT,
  _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  _______, _______, MO(MOUSE), MO(NAV),  KC_ENT,   KC_SPC,  KC_SPC,  KC_BSPC,  MO(SYM), _______, COLEMAK, QWERTY
),



/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[NAV] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,    KC_F3,      KC_F4,      KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______, _______, _______,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Mouse control
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[MOUSE] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,    KC_F3,      KC_F4,      KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
  _______, _______, _______, _______, _______, _______, _______, KC_MS_WH_DOWN, KC_MS_UP, KC_MS_WH_UP, _______, _______,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN1, KC_MS_BTN2, _______, _______, _______, _______
),


/* Symbol & Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   *  |   -  |   +  |   =  |   {  |   }  |   (  |   )  |   _  |   :  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ^  |   !  |   #  |   $  |   %  |   @  |   [  |   ]  |   &  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[SYM] = LAYOUT_preonic_grid(
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
   _______, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_UNDS, KC_COLN, KC_PIPE,
   _______, KC_CIRC, KC_EXLM, KC_HASH, KC_DLR,  KC_PERC, KC_AT,   KC_LBRC, KC_RBRC, KC_AMPR, KC_BSLS, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

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



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }            


  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(NAV);
            update_tri_layer(NAV, SYM, _ADJUST);
          } else {
            layer_off(NAV);
            update_tri_layer(NAV, SYM, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(SYM);
            update_tri_layer(NAV, SYM, _ADJUST);
          } else {
            layer_off(SYM);
            update_tri_layer(NAV, SYM, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_LSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_LSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(SYM)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
achordion_task();
  #ifdef AUDIO_ENABLE
      if (muse_mode) {
          if (muse_counter == 0) {
              uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
              if (muse_note != last_muse_note) {
                  stop_note(compute_freq_for_midi_note(last_muse_note));
                  play_note(compute_freq_for_midi_note(muse_note), 0xF);
                  last_muse_note = muse_note;
              }
          }
          muse_counter = (muse_counter + 1) % muse_tempo;
      } else {
          if (muse_counter) {
              stop_all_notes();
              muse_counter = 0;
          }
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}


