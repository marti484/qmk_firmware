#include QMK_KEYBOARD_H

#define L_DEFAULT 0
#define L_MOUSE 1
#define L_KEYPAD 2
#define L_LIGHTS 3
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_DEFAULT] = LAYOUT_directional(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL, KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_SPC, KC_NO, KC_RALT, MO(1), KC_LEFT, KC_DOWN, KC_RGHT),
	[L_MOUSE] = LAYOUT_directional(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_DEL, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MFFD, RESET, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN4, KC_BTN5, KC_WH_D, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_NO, MO(3), KC_PGUP, TG(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END),
	[L_KEYPAD] = LAYOUT_directional(KC_ESC, KC_CALC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_PAST, KC_PMNS, KC_PPLS, KC_NO, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_A, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_NO, KC_NO, KC_PENT, TG(2), KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_P0, KC_P0, KC_PDOT, KC_PSLS, KC_NO, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_SPC, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT),
	[L_LIGHTS] = LAYOUT_directional(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, KC_NO, RESET, KC_NO, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t current = rgblight_get_mode();
    if(startMode == 0 && current == RGBLIGHT_MODE_STATIC_LIGHT){
        startMode = rgblight_get_mode();
    }
    switch (biton32(state)) {
    case L_DEFAULT:
    rgblight_mode_noeeprom(startMode);
        break;
    case L_MOUSE:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
        break;
    case L_KEYPAD:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 2);
        break;
    case L_LIGHTS:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_ALTERNATING);
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
}