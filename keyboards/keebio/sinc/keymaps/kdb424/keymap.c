#include QMK_KEYBOARD_H
#include "kdb424.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_80_with_macro(
    RGB_TOG,          KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_MUTE,
    XXXXXXX, REPROGR, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_DEL,  KC_BSPC, KC_HOME,
    RGB_HUD, RGB_HUI, KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS, KC_PGUP,
    RGB_SAD, RGB_SAI, KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,  KC_PGDN,
    RGB_VAD, RGB_VAI, KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, KC_INS,   KC_END,
    RGB_M_P, RGB_M_K, KC_LCTL, KC_LGUI, KC_LALT, MO(_RAISE1),      XXXXXXX, KC_SPC,  XXXXXXX, LT(_RAISE1, KC_SPC),  KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
  [_GAMING] = LAYOUT_80_with_macro(
    RGB_TOG,          KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_MUTE,
    XXXXXXX, XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_DEL,  KC_BSPC, KC_HOME,
    XXXXXXX, XXXXXXX, KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS, KC_PGUP,
    XXXXXXX, XXXXXXX, KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,  KC_PGDN,
    XXXXXXX, XXXXXXX, KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, KC_INS,   KC_END,
    XXXXXXX, XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, MO(_RAISE1),      XXXXXXX, KC_WH_D, XXXXXXX, LT(_RAISE1, KC_SPC),  KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
  [_RAISE1] = LAYOUT_80_with_macro(
    RGB_MOD,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,
    _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    DF(0),   DF(1),  _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),
};

