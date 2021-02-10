#include QMK_KEYBOARD_H

#define L_DEFAULT 0
#define L_QUICK 1
#define L_KEYPAD 2
#define L_LIGHTS 3
uint8_t startMode = 0; 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [L_DEFAULT] = LAYOUT_directional(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, TG(2), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_SFTENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_RCTL, KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_SPC, KC_NO, KC_RALT, MO(1), KC_LEFT, KC_DOWN, KC_RGHT),
        [L_QUICK] = LAYOUT_directional(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_DEL, KC_ESC, KC_PSCR, KC_SLCK, KC_PAUS, KC_SLEP, KC_NO, KC_BRID, KC_BRIU, KC_MRWD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MFFD, KC_NO, KC_CAPS, KC_INS, KC_HOME, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_DEL, KC_END, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT),
        [L_KEYPAD] = LAYOUT_directional(KC_ESC, KC_NO, KC_BTN3, KC_BTN4, KC_BTN5, KC_NO, KC_NO, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_ACL0, KC_ACL1, KC_NO, KC_BSPC, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NO, KC_ACL2, KC_NO, TG(2), KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PCMM, KC_PEQL, KC_PENT, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_R, KC_P0, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_NO, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_SPC, KC_NO, KC_NO, LT(3,KC_TRNS), KC_LEFT, KC_DOWN, KC_RGHT),
        [L_LIGHTS] = LAYOUT_directional(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, KC_NO, RESET, KC_NO, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};



// uint32_t layer_state_set_user(uint32_t state) {
//     uint8_t current = rgblight_get_mode();
//     if(startMode == 0 && current == RGBLIGHT_MODE_STATIC_LIGHT){
//         startMode = rgblight_get_mode();
//     }
//     switch (biton32(state)) {
//     case L_DEFAULT:
//     rgblight_mode_noeeprom(startMode);
//         break;
//     case L_QUICK:
//         rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
//         break;
//     case L_KEYPAD:
//         rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 2);
//         break;
//     case L_LIGHTS:
//         rgblight_mode_noeeprom(RGBLIGHT_MODE_ALTERNATING);
//         break;
//     default: //  for any other layers, or the default layer
//         break;
//     }
//   return state;
// };

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {15,1, HSV_RED}
);

const rgblight_segment_t PROGMEM my_default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_ORANGE}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_quick_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 1, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 2, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_lights_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_MAGENTA}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_default_layer,    // Overrides caps lock layer
    my_quick_layer,    // Overrides other layers
    my_numpad_layer,
    my_lights_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, L_DEFAULT));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, L_DEFAULT));
    rgblight_set_layer_state(2, layer_state_cmp(state, L_QUICK));
    rgblight_set_layer_state(3, layer_state_cmp(state, L_KEYPAD));
    rgblight_set_layer_state(4, layer_state_cmp(state, L_LIGHTS));
    return state;
}
