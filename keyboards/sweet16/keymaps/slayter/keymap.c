#include "sweet16.h"
#include "unicode_funcs.c"

#define BASE   0
#define NUMPAD 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ortho_4x4(
        KC_ESC,  KC_MUTE, KC_VOLD, KC_VOLU, 
        DISFACE, SHRUG,   TFLIP,   TPUT, 
        UNDO,    REDO,    FACE,    KC_DEL, 
        COPY,    PASTE,   CUT,     TG(NUMPAD)
    ),

    [NUMPAD] = LAYOUT_ortho_4x4(
        KC_7,   KC_8,   KC_9, KC_PLUS, 
        KC_4,   KC_5,   KC_6, KC_MINS, 
        KC_1,   KC_2,   KC_3, KC_ASTR, 
        KC_ENT, KC_DOT, KC_0, KC_TRNS
    )
};

void led_set_user(uint8_t usb_led) {

  /* Map RXLED to USB_LED_NUM_LOCK */
	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		DDRB |= (1 << 0); PORTB &= ~(1 << 0);
	} else {
		DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
	}

  /* Map TXLED to USB_LED_CAPS_LOCK */
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRD |= (1 << 5); PORTD &= ~(1 << 5);
	} else {
		DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
	}
}
