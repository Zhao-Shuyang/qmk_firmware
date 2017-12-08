/* Copyright 2017 Zhao Shuyang
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
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_swedish.h"

#define BASE 0 // default layer
#define FN 1 // Funtion and movement

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  !   |  "   |  #   |  #   |  %   | &    |           | Back |  /   |  (   |  )   |  =   |  ?     |  ^   |
 * |        |  1   |  2 @ |  3 £ |  4 $ |  5 € | 6    |           | space|  7 { |  8 [ |  9 ] |  0 } |  + \   |  ¨ ~ |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    | Q    | W    | E    | R    | T    |  F4  |           |  F5  | Y    | U    | I    | O    | P    | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Hyper  | A    | S    | D    | F    | G    |------|           |------| H    | J    | K    | L    | *    | Enter  |
 * |        |      |      |      |      |      |      |           |      |      |      |      |      | ,    |        |
 * |--------+------+------+------+------+------| Del  |           |      |------+------+------+------+------+--------|
 * | LShft  | Z    | X    | C    | V    | B    |      |           |      | N    | M    | ;    | :    | Up   |   _    |
 * |        |      |      |      |      |      |      |           |      |      |      | ,    | .    |      |   -    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl | Hyper| LAlt | Space| Space|                                       | AltGr|TG(L1)| Left | Down | Right|
 *   |      | (<)  |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | LGUI |  F1  |       | Home |  End  |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |  F2  |       | PgUp |       |      |
 *                                 |      | Meh  |------|       |------|  Tab  |Enter |
 *                                 |      |      |  F3  |       | PgDn |       |      |
 *                                 `--------------------'       `---------------------'
 */

[BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESC,          KC_1,     KC_2,     KC_3,    KC_4,    KC_5,   KC_6,
    KC_TAB,          KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,   KC_F4,
    KC_HYPR,         KC_A,     KC_S,     KC_D,    KC_F,    KC_G,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,   KC_DELT,
    KC_LCTRL,        HYPR(NO_LESS), KC_LALT,  KC_SPC, KC_SPC,
    KC_LGUI,  KC_F1,
    KC_F2,
    KC_SPC, KC_MEH, KC_F3,

    // right hand
    KC_BSPC, KC_7,   KC_8,    KC_9,    KC_0,    NO_PLUS,  NO_QUOT,
    KC_F5,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_ENT,
             KC_H,   KC_J,    KC_K,    KC_L,    NO_ASTR,  KC_ENT,
    KC_DELT, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_UP,    NO_MINS,
                     NO_ALGR, TG(FN),  KC_LEFT, KC_DOWN,  KC_RGHT,
    KC_HOME,   KC_END,
    KC_PGUP,
    KC_PGDN,   KC_TAB, KC_ENT
),

/* Keymap 2: Funtion and movement
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | Up   | PgUp |      |      |           |      |      | LClk | MsUp | RClk |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Left | Down | Rght | End  |------|           |------|      | MsLf | MsDn | MsRt |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      | PgDn |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | INS  |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[FN] = LAYOUT_ergodox(
       KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_PGUP, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_PGDN, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_INSERT,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_F7,  KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_BTN1, KC_MS_UP, KC_BTN2, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

};


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    if (keyboard_report->mods & (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))) {
      ergodox_right_led_1_on();
    }
    if (keyboard_report->mods & (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))) {
      ergodox_right_led_2_on();
    }
};
