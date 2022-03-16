/*
Copyright 2020 Ryan Castillo <castillo.ryanmiguel@gmail.com>

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


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_alice(
    KC_ESC,  	KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
    KC_PGUP, 	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_PGDN, 	KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
				KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_LGUI,
				KC_LCTL,          KC_LALT, KC_SPC,  MO(1),                          KC_UNDS,           KC_RALT,          KC_RCTL
  ),
  [1] = LAYOUT_alice(
    KC_TRNS,  	KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,   KC_F12,      KC_DEL,
    KC_TRNS,  	KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, 	  KC_TRNS,  KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
				KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,          KC_TRNS,          RESET
  )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  // debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
};

bool led_update_user(led_t led_state) {
    uprintf("%s", readPin(INDICATOR_PIN_0));
    uprintf("%s", readPin(INDICATOR_PIN_1));
    uprintf("%s", readPin(INDICATOR_PIN_2));

    writePin(INDICATOR_PIN_0, !led_state.num_lock);
    writePin(INDICATOR_PIN_1, !led_state.caps_lock);
    writePin(INDICATOR_PIN_2, !led_state.scroll_lock);

    uprintf("%s", readPin(INDICATOR_PIN_0));
    uprintf("%s", readPin(INDICATOR_PIN_1));
    uprintf("%s", readPin(INDICATOR_PIN_2));

    // bool runDefault = led_update_user(led_state);
    // if (runDefault) {
      // writePin(INDICATOR_PIN_0, !led_state.num_lock);
      // writePin(INDICATOR_PIN_1, !led_state.caps_lock);
      // writePin(INDICATOR_PIN_2, !led_state.scroll_lock);
    // }
    return false;
};
