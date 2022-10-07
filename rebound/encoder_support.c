// Paste below at bottom of generated .c file.
// This enables encoder

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
