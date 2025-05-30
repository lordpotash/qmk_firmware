/* Copyright 2024 ~ 2025 @ Keychron (https://www.keychron.com)
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
#include "math.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    COL_BASE,
    WIN_FN,
//    NUMP,
};

enum {
    TD_MPLY_MNXT,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     TD(TD_MPLY_MNXT),    G(S(KC_S)),  C(S(A(KC_M))), RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN),  KC_RWIN, KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [COL_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     TD(TD_MPLY_MNXT),    G(S(KC_S)),  C(S(A(KC_M))), RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_X,     KC_C,     KC_D,     KC_V,     KC_Z,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN),  KC_RWIN, KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),
    
    [WIN_FN] = LAYOUT_tkl_ansi(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  C(S(A(KC_D))),  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  TO(WIN_BASE),  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  TO(COL_BASE),  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),
/*
    [NUMP] = LAYOUT_tkl_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  KC_1,     KC_2,     KC_3,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  KC_4,     KC_5,     KC_6,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        KC_0,               KC_7,     KC_8,     KC_9,     _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),
*/
/*
    [TRNS] = LAYOUT_tkl_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),
*/
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [COL_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
//    [NUMP] = {ENCODER_CCW_CW(_______, _______)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_MPLY_MNXT] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
};

const key_override_t cole_undo_XZ = ko_make_with_layers(KC_LCTL, KC_X, C(KC_Z), COL_BASE);
const key_override_t cole_cut_CX  = ko_make_with_layers(KC_LCTL, KC_C, C(KC_X), COL_BASE);
const key_override_t cole_copy_DC = ko_make_with_layers(KC_LCTL, KC_D, C(KC_C), COL_BASE);
const key_override_t cole_redo_RY = ko_make_with_layers(KC_LCTL, KC_R, C(KC_Y), COL_BASE);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&cole_undo_XZ,
  &cole_cut_CX,
  &cole_copy_DC,
  &cole_redo_RY,
};

// caps lock wave

// All these numbers match up with the indexed positions in the keymap above.
const uint8_t CAPS_LOCK_KEY_INDEX = 50;
const uint8_t MAIN_KEYS[] = { 
  16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
   33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
   50,  51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,   62,
    63,  64, 65, 66, 67, 68, 69, 70, 71, 72, 73,     74,
  76, 77, 78,            79,               80, 81, 82, 83,
};

int clamp(int x, int lower, int upper) {
  if(x > upper) {
    return upper;
  }
  if(x < lower) {
    return lower;
  }
  return x;
}

// vars for tracking the animation state
double caps_flood_position = 0;
uint32_t last_frame_time;

/*
 * This is basically the amount of mills to wait between frames
 * Bigger number, slower the animation. 16 == 60fps
 */
 const int FLOOD_SPEED_DIVISOR = 16;

/*
 * This sets the order that the keys turn on, plus 2 variables to hold the array sizes
 * -1 is used as null because C doesn't like variable sized 2D arrays
 * The first grouping is intentionally empty as that is where the lock key itself turns off/on
*/
const int CAPS_FLOOD_STEPS = 15;
const int CAPS_FLOOD_HEIGHT = 5;
const uint8_t MAIN_KEY_GROUPS[15][5] = {
  { -1, -1, -1, -1, -1 },
  { 16, 33, 50, 63, 76 },
  { 17, 34, 51, 64, 77 },
  { 18, 35, 52, 65, 78 },
  { 19, 36, 53, 66, -1 },
  { 20, 37, 54, 67, -1 },
  { 21, 38, 55, 68, 79 },
  { 22, 39, 56, 69, -1 },
  { 23, 40, 57, 70, -1 },
  { 24, 41, 58, 71, -1 },
  { 25, 42, 59, 72, 80 },
  { 26, 43, 60, 73, 81 },
  { 27, 44, 61, -1, 82 },
  { 28, 45, -1, -1, -1 },
  { 29, 46, 64, 74, 83 },
};

// flood_color = ;

/*
 * A helper function that can be called while capslock is on or animating to progress
 * or maintain the state of the LEDs
 */

 void update_cap_flood(void) {
  int flood_index = clamp(floor(caps_flood_position), 0, CAPS_FLOOD_STEPS);

  rgb_matrix_set_color(CAPS_LOCK_KEY_INDEX, RGB_RED);

  for (int i = 0; i < flood_index; i++) {
    for (int ii = 0; ii < CAPS_FLOOD_HEIGHT; ii++) {
      uint8_t key = MAIN_KEY_GROUPS[i][ii];
      if (g_led_config.flags[key]) {
        if( key > -1 ){
          rgb_matrix_set_color(key, RGB_RED);
        }
      }
    }
  }
}

// Abstracted the increment logic so it can be reused between keys 
double updateFloodPosition(double flood_position, double flood_amount, bool lock_state, int max_flood){
  double next_position = flood_position;
  if (lock_state) {
    if(next_position < 0){
      next_position = 0;
    }
    if(next_position <= max_flood){
      next_position = next_position + flood_amount;
    }
  } else {
    if(next_position > max_flood){
      next_position = max_flood;
    }
    if( next_position >= 0 ){
      next_position = next_position - flood_amount;
    }
  }
  return next_position;
}


// This is invoked once every cycle by the firmware and is used to set the Caps/Num/Scroll lock indicators
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

  // Use the time difference between invokes to set how far to advance the animation
  uint32_t delta = timer_elapsed32(last_frame_time);
  double flood_amount = (double) delta / (double) FLOOD_SPEED_DIVISOR;
  
  // Deal with CapsLock
  caps_flood_position = updateFloodPosition(
    caps_flood_position,
    flood_amount,
    host_keyboard_led_state().caps_lock,
    CAPS_FLOOD_STEPS
  );
  if (host_keyboard_led_state().caps_lock || caps_flood_position > 0) {
    update_cap_flood();
  }
  
  last_frame_time = timer_read32();
  return false;
}