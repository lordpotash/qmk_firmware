/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers {
    BASE,
    FN,
    MAT,
    UNIT,
    HOTK,
//    TRNS,
};

enum custom_keycodes {
    TXT_MM = SAFE_RANGE,
    TXT_CM,
    TXT_IN,
    TXT_FT,
};

enum {
    TD_SAUD_MNXT,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_tenkey_27(
        TD(TD_SAUD_MNXT),  KC_ESC,   KC_BSPC,  KC_DEL,   G(S(KC_S)),
        TG(FN),   KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        MO(UNIT), KC_P7,    KC_P8,	  KC_P9,    KC_PPLS,
        KC_TAB,   KC_P4,    KC_P5,	  KC_P6,
        MO(MAT),  KC_P1,    KC_P2,	  KC_P3,	LALT_T(KC_PENT),
        MO(HOTK), KC_P0,              LSFT_T(KC_PDOT)    ),

    [FN] = LAYOUT_tenkey_27(
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,
        _______,  RGB_MOD,  RGB_VAI,  RGB_HUI,  KC_MPRV,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  KC_MNXT,
        _______,  RGB_SAI,  RGB_SPI,  _______,
        _______,  RGB_SAD,  RGB_SPD,  _______,  KC_MPLY,
        _______,  RGB_TOG,            _______           ),

    [MAT] = LAYOUT_tenkey_27(
        _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  KC_EQL,
        _______,  KC_LPRN,  KC_X,     KC_RPRN,  _______,
        _______,  KC_LCBR,  KC_Y,     KC_RCBR,
        _______,  KC_LBRC,  KC_Z,     KC_RBRC,  KC_PENT,
        _______,  _______,            KC_COMM           ),

    [UNIT] = LAYOUT_tenkey_27(
        _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,
        _______,  TXT_MM,   TXT_CM,   TXT_IN,   TXT_FT,
        _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,
        _______,  _______,            _______           ),
    
    [HOTK] = LAYOUT_tenkey_27(
        _______,  _______,  _______,  _______,  _______,
        _______,  _______,  C(KC_S),  _______,  _______,
        _______,  _______,  C(KC_W),  C(KC_R),  C(KC_T),
        _______,  C(KC_A),  C(KC_E),  C(KC_F),
        _______,  C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),
        _______,  _______,            C(KC_Y)           ),

/*
    [TRNS] = LAYOUT_tenkey_27(
        _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,
        _______,  _______,            _______          ),
*/
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [MAT]  = {ENCODER_CCW_CW(_______,  _______)},
    [UNIT] = {ENCODER_CCW_CW(_______,  _______)},
    [HOTK] = {ENCODER_CCW_CW(_______,  _______)},
//    [TRNS] = {ENCODER_CCW_CW(_______,  _______)},
};
#endif // ENCODER_MAP_ENABLE

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for MPLY, tap twice for MNXT
    [TD_SAUD_MNXT] = ACTION_TAP_DANCE_DOUBLE(HYPR(KC_Q), KC_MNXT),
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    for (uint8_t i = 22; i < 26; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 1:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            default:
                break;
        }
    }
    if (!host_keyboard_led_state().num_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_matrix_set_color(i, RGB_RED);
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    switch (keycode) {
    case TXT_MM:
        if (record->event.pressed) {
            // when keycode TXT_MM is pressed
            SEND_STRING("mm");
        }
        break;
    
    case TXT_CM:
        if (record->event.pressed) {
            // when keycode TXT_CM is pressed
            SEND_STRING("cm");
        }
        break;

    case TXT_IN:
        if (record->event.pressed) {
            // when keycode TXT_IN is pressed
            SEND_STRING("in");
        }
        break;    
    
    case TXT_FT:
        if (record->event.pressed) {
            // when keycode TXT_FT is pressed
            SEND_STRING("ft");
        }
        break;
    }
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}