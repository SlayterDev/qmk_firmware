#ifndef SLAYTER_UNICODE
#define SLAYTER_UNICODE

#include "eeconfig.h"
#include "action_layer.h"
extern keymap_config_t keymap_config;

#define ____ KC_TRNS
#define XXXX KC_NO

uint16_t hex_map[] = {KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_A, KC_B, KC_C, KC_D, KC_E, KC_F};

void tap(uint16_t keycode) {
	register_code(keycode);
	unregister_code(keycode);
};

enum my_keycodes {
	FACE = SAFE_RANGE,
	DISFACE,
	TFLIP,
	TPUT,
	SHRUG,
	COPY,
	PASTE,
	CUT,
	FIND,
	UNDO,
	REDO
};

void toggle_hex_sequence(void) {
	register_code(KC_LCTL);
	tap(KC_SPC);
	unregister_code(KC_LCTL);
};

void mac_input_hex(uint16_t keycode) {
	register_code(KC_LALT);
	for (int i = 12; i >= 0; i -= 4) {
		uint16_t keyIndex = (keycode & (0xF << i)) >> i;
		tap(hex_map[keyIndex]);
	}
	unregister_code(KC_LALT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		#ifdef UNICODE_ENABLE
		case DISFACE:
			if (record->event.pressed) { // ಠ_ಠ
				toggle_hex_sequence();
				mac_input_hex(0x0CA0); // Eye
				register_code(KC_RSFT);
				tap(KC_MINS);
				unregister_code(KC_RSFT);
				mac_input_hex(0x0CA0); // Eye
				toggle_hex_sequence();
			}
			return false;
			break;
		case TFLIP:
			if (record->event.pressed) { // (╯°□°)╯ ͡ ┻━┻
				toggle_hex_sequence();
				register_code(KC_RSFT);
				tap(KC_9);
				unregister_code(KC_RSFT);
				mac_input_hex(0x256F); // Arm
				mac_input_hex(0x00B0); // Eye
				mac_input_hex(0x25A1); // Mouth
				mac_input_hex(0x00B0); // Eye
				register_code(KC_RSFT);
				tap(KC_0);
				unregister_code(KC_RSFT);
				mac_input_hex(0x256F); // Arm
				tap(KC_SPC);
				mac_input_hex(0x0361); // Flippy
				tap(KC_SPC);
				mac_input_hex(0x253B); // Table
				mac_input_hex(0x2501); // Table
				mac_input_hex(0x253B); // Table
				toggle_hex_sequence();
			}
			return false;
		case TPUT:
			if (record->event.pressed) { // ┬──┬ ノ( ゜-゜ノ)
				toggle_hex_sequence();
				mac_input_hex(0x252C); // Table
				mac_input_hex(0x2500); // Table
				mac_input_hex(0x2500); // Table
				mac_input_hex(0x252C); // Table
				tap(KC_SPC);
				mac_input_hex(0x30CE); // Arm
				register_code(KC_RSFT);
				tap(KC_9);
				unregister_code(KC_RSFT);
				tap(KC_SPC);
				mac_input_hex(0x309C); // Eye
				tap(KC_MINS);
				mac_input_hex(0x309C); // Eye
				mac_input_hex(0x30CE); // Arm
				register_code(KC_RSFT);
				tap(KC_0);
				unregister_code(KC_RSFT);
				toggle_hex_sequence();
			}
			return false;
			break;
		case SHRUG:
			if (record->event.pressed) { // ¯\_(ツ)_/¯
				toggle_hex_sequence();
				mac_input_hex(0x00AF); // Hand
				tap(KC_BSLS);
				register_code(KC_RSFT);
				tap(KC_UNDS);
				tap(KC_LPRN);
				unregister_code(KC_RSFT);
				mac_input_hex(0x30C4); // Face
				register_code(KC_RSFT);
				tap(KC_RPRN);
				tap(KC_UNDS);
				unregister_code(KC_RSFT);
				tap(KC_SLSH);
				mac_input_hex(0x00AF); // Hand
				toggle_hex_sequence();
			}
			return false;
			break;
		#endif
		case FACE:
			if (record->event.pressed) {
				register_code(KC_RSFT);
				tap(KC_LPRN);
				unregister_code(KC_RSFT);
				tap(KC_0);
				register_code(KC_RSFT);
				tap(KC_UNDS);
				unregister_code(KC_RSFT);
				tap(KC_0);
				register_code(KC_RSFT);
				tap(KC_RPRN);
				unregister_code(KC_RSFT);
			}
			return false;
			break;
		case COPY:
			if (record->event.pressed) {
				register_code(KC_LGUI);
				tap(KC_C);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case PASTE:
			if (record->event.pressed) {
				register_code(KC_LGUI);
				tap(KC_V);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case CUT:
			if (record->event.pressed) {
				register_code(KC_LGUI);
				tap(KC_X);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case UNDO:
			if (record->event.pressed) {
				register_code(KC_LGUI);
				tap(KC_Z);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case FIND:
			if (record->event.pressed) {
				register_code(KC_LGUI);
				tap(KC_F);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		case REDO:
			if (record->event.pressed) {
				register_code(KC_LGUI);
				register_code(KC_RSFT);
				tap(KC_Z);
				unregister_code(KC_RSFT);
				unregister_code(KC_LGUI);
			}
			return false;
			break;
		default:
			return true;
			break;
	}

	return true;
}

#endif
