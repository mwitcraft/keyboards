#include QMK_KEYBOARD_H

/*
Notes
    - Debug layer (1) is exact same as base layer, except for encoder
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base
    [0] = LAYOUT_all(
        KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC, 
        LSA_T(KC_CAPS), KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_F2,      KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT, 
        KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       TG(1),      KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_QUOT, 
        KC_LCTL,        MO(5),      KC_LGUI,    MO(4),      MO(2),      KC_ESC,     KC_MUTE,    KC_SPC,     MO(3),      KC_RCTL,    KC_RGUI,    _______,    KC_RALT),

    // Debug
    [1] = LAYOUT_all(
        KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC, 
        LSA_T(KC_CAPS), KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_F2,      KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT, 
        KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       _______,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_QUOT, 
        KC_LCTL,        MO(5),      KC_LGUI,    MO(4),      MO(2),      KC_ESC,     KC_F5,      KC_SPC,     MO(3),      KC_RCTL,    KC_RGUI,    _______,    KC_RALT),

    // Symbols
    [2] = LAYOUT_all(
        _______,        KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_PLUS,    KC_EQL,     KC_DEL, 
        _______,        KC_TILD,    KC_GRV,     KC_LCBR,    KC_LPRN,    KC_LBRC,    _______,    KC_RBRC,    KC_RPRN,    KC_RCBR,    KC_MINS,    KC_UNDS,    KC_ENT, 
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LT,      KC_GT,      KC_BSLS,    KC_PIPE, 
        _______,        _______,    _______,    _______,    _______,    KC_ESC,     _______,    KC_SPC,     _______,    KC_RCTL,    _______,    _______,    _______),

    // Arrows
    [3] = LAYOUT_all(
        _______,        _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    KC_BSPC, 
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,    KC_ENT, 
        KC_LSFT,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, 
        _______,        _______,    _______,    _______,    _______,    KC_ESC,     _______,    KC_SPC,     _______,    _______,    _______,    _______,    _______),

    // Numpad
    [4] = LAYOUT_all(
        _______,        _______,    _______,    _______,    _______,    _______,                KC_7,       KC_8,       KC_9,       _______,    _______,    KC_BSPC, 
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_4,       KC_5,       KC_6,       _______,    _______,    KC_ENT, 
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_1,       KC_2,       KC_3,       _______,    _______,    _______, 
        _______,        _______,    _______,    _______,    _______,    KC_ESC,     _______,    KC_SPC,     KC_0,       KC_DOT,     _______,    _______,    _______),

    // Function Keys
    [5] = LAYOUT_all(
        _______,        _______,    _______,    _______,    _______,    _______,                KC_F7,      KC_F8,      KC_F9,      _______,    _______,    _______, 
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_F4,      KC_F5,      KC_F6,      _______,    _______,    _______, 
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_F1,      KC_F2,      KC_F3,      _______,    _______,    _______, 
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_F10,     KC_F11,     KC_F12,     _______,    _______,    _______)
};

// Encoder is backwards
void encoder_update_user(uint8_t index, bool clockwise) {
  switch (get_highest_layer(layer_state)){
    case 0: // Base
      if (clockwise) {
        tap_code16(KC_VOLD);
      }
      else {
        tap_code16(KC_VOLU);
      }
      break;
    case 1: // Debug
      if (clockwise) {
        tap_code16(S(KC_F11));
      }
      else {
        tap_code16(KC_F10);
      }
      break;
    default:
      break;
  }
}
