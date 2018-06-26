#include QMK_KEYBOARD_H

#include "debug.h"
#include "action_layer.h"
#include "version.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   COLEMAK,
//   DVORAK,
//   LOWER,
//   RAISE,
//   ADJUST,
// };

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | TAB  |Backsp|------|       |------| Enter  | Tab  |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_QWERTY] = LAYOUT(
  /*
  // left hand
  KC_EQL, KC_DELT, KC_BSPC, KC_LSFT, LT(SYMB, KC_GRV),
  KC_1, KC_Q, KC_A, CTL_T(KC_Z), KC_QUOT, KC_END,
  KC_2, KC_W, KC_S, KC_X, LALT(KC_LSFT), KC_BSPC,
  KC_3, KC_E, KC_D, KC_C, KC_LEFT, KC_TAB,
  KC_4, KC_R, KC_F, KC_V, KC_RGHT, KC_HOME,
  KC_5, KC_T, KC_G, KC_B, ALT_T(KC_APP),
  KC_LEFT, TG(SYMB), ALL_T(KC_NO), KC_LGUI,

  // right hand
  KC_RIGHT, TG(SYMB), MEH_T(KC_NO), KC_LALT,
  KC_6, KC_Y, KC_H, KC_N, CTL_T(KC_ESC),
  KC_7, KC_U, KC_J, KC_M, KC_UP, KC_PGUP,
  KC_8, KC_I, KC_K, KC_COMM, KC_DOWN, KC_TAB,
  KC_9, KC_O, KC_L, KC_DOT, KC_LBRC, KC_ENT,
  KC_0, KC_P, LT(MDIA, KC_SCLN), CTL_T(KC_SLSH), KC_RBRC, KC_PGDN,
  KC_MINS, KC_BSLS, GUI_T(KC_QUOT), KC_RSFT, KC_FN1
  */

  
   // left hand                                                                   // right hand
  KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,          KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
  KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_NO,            KC_NO,    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
  KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,                               KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
  KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),     MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
  LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,                                       KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
                                        ALT_T(KC_APP),  KC_LGUI,                       KC_LALT,        CTL_T(KC_ESC),
                                                        KC_HOME,                       KC_PGUP,
                                         KC_TAB,KC_BSPC,KC_END,                        KC_PGDN,KC_ENT, KC_SPC
  
),


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // switch (keycode) {
  //   case QWERTY:
  //     if (record->event.pressed) {
  //       #ifdef AUDIO_ENABLE
  //         PLAY_SONG(tone_qwerty);
  //       #endif
  //       persistent_default_layer_set(1UL<<_QWERTY);
  //     }
  //     return false;
  //     break;
  //   case COLEMAK:
  //     if (record->event.pressed) {
  //       #ifdef AUDIO_ENABLE
  //         PLAY_SONG(tone_colemak);
  //       #endif
  //       persistent_default_layer_set(1UL<<_COLEMAK);
  //     }
  //     return false;
  //     break;
  //   case DVORAK:
  //     if (record->event.pressed) {
  //       #ifdef AUDIO_ENABLE
  //         PLAY_SONG(tone_dvorak);
  //       #endif
  //       persistent_default_layer_set(1UL<<_DVORAK);
  //     }
  //     return false;
  //     break;
  //   case LOWER:
  //     if (record->event.pressed) {
  //       layer_on(_LOWER);
  //       update_tri_layer(_LOWER, _RAISE, _ADJUST);
  //     } else {
  //       layer_off(_LOWER);
  //       update_tri_layer(_LOWER, _RAISE, _ADJUST);
  //     }
  //     return false;
  //     break;
  //   case RAISE:
  //     if (record->event.pressed) {
  //       layer_on(_RAISE);
  //       update_tri_layer(_LOWER, _RAISE, _ADJUST);
  //     } else {
  //       layer_off(_RAISE);
  //       update_tri_layer(_LOWER, _RAISE, _ADJUST);
  //     }
  //     return false;
  //     break;
  //   case ADJUST:
  //     if (record->event.pressed) {
  //       layer_on(_ADJUST);
  //     } else {
  //       layer_off(_ADJUST);
  //     }
  //     return false;
  //     break;
  // }
  return true;
}
