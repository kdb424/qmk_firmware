#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;
#define _DVORAK 0
#define _GAMING 1
#define _RAISE1 2
#define _RAISE2 3
#define _GUI 4
#define _SYMBOLS 5
#define REPROGR REPROGRAM_MACRO

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  GAMING,
  RAISE1,
  RAISE2,
  GUI,
  SYMBOLS,
  REPROGRAM_MACRO,
};

#define LT1_SP LT(_RAISE1, KC_SPC)
#define LT2_SP LT(_RAISE2, KC_SPC)
#define TAB_SB LT(_SYMBOLS, KC_TAB)
#define SUPER_L LM(_GUI, MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  | BKSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |_______.    ,_______|   D  |   H  |   T  |   N  |   S  |  ENT |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Shft |   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |   /  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LALT | LGUI | /LT1_SP /       \LT2_SP\  |  Ctl |  Up  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_DVORAK] = LAYOUT( \
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_GRV,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  TAB_SB,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, XXXXXXX,    XXXXXXX, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH, \
                            XXXXXXX,  KC_LALT, SUPER_L, LT1_SP,   LT2_SP,  KC_LCTL, KC_UP,   XXXXXXX \
),

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  | BKSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctl  |   A  |   O  |   E  |   U  |   I  |_______.    ,_______|   D  |   H  |   T  |   N  |   S  |  ENT |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Shft |   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |   /  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LALT | LGUI | / Space /       \LT2_SP\  |  Ctl |  Up  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_GAMING] = LAYOUT( \
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_ESC,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_LCTL,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, _______,  _______,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH, \
                           XXXXXXX, KC_LALT, KC_SPC,  KC_SPC,   LT2_SP,   KC_LCTL, KC_UP,   XXXXXXX \
),
/* RAISE1
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Reprog|      |      |      |      |      |                    |      |      |   7  |  8   |  9   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |_______.    ,_______|      |      |   4  |  5   |  6   |   \  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |   1  |  2   |  3   |   -  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LALT | LGUI | /LT1_SP /       \LT2_SP\  |   =  |  0   |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE1] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  REPROGR, _______, _______, _______, _______, _______,                   XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_DEL,  \
  _______, _______, _______, _______, _______, _______,                   XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_MINS, \
                             _______, _______, _______, _______, _______, KC_EQL,  KC_0,    KC_0  \
),
/* RAISE2
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |                    |      |      |      |      |      | SIns |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |_______.    ,_______|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |-------|    |-------|      |      |      |      |      |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LALT | LGUI | /LT1_SP /       \LT2_SP\  |Dvorak|Gaming|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE2] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                     _______, _______, _______, KC_LBRC, KC_RBRC, LSFT(KC_INS), \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                     KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,  _______, _______,  _______, _______, _______, _______, _______, KC_BSLS, \
                             _______, _______, _______,  _______, _______,  DF(0),   DF(1),   _______ \
),
/* GUI
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  1   |   2  |   3  |   4  |  5   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  6   |   7  |   8  |   9  |  0   |_______.    ,_______|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LALT | LGUI | /LT1_SP /       \LT2_SP\  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_GUI] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        _______, _______, _______, _______, _______, _______, \
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                        _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |   @  |   #  |   $  |  %   |                    |   ^  |   &  |   *  |   (  |  )   | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |_______.    ,_______|      |      |      |   [  |  ]   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LALT | LGUI | /LT1_SP /       \LT2_SP\  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMBOLS] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
)
};


//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
//void set_keylog(uint16_t keycode, keyrecord_t *record);
//const char *read_keylog(void);
//const char *read_keylogs(void);

char wpm_str[10];

void oled_task_user(void) {
  if (is_keyboard_master()) {
    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_scroll_left();  // Turns on scrolling
    switch (biton32(layer_state)){
      case _DVORAK:
          oled_write_ln_P(PSTR("       DVRK"), false);
          break;
      case _GAMING:
          oled_write_ln_P(PSTR("       GAMING"), false);
          break;
      case _RAISE1:
          oled_write_ln_P(PSTR("       LOWER"), false);
          break;
      case _RAISE2:
          oled_write_ln_P(PSTR("       RAISE"), false);
          break;
      default:
          oled_write_ln_P(PSTR("       ?????"), false);
  }
  oled_write(read_logo(), false);

  } else {
    sprintf(wpm_str, "       WPM: %03d", get_current_wpm());
    oled_write_ln(wpm_str, false);
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    //set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  switch (keycode) {
    case REPROGRAM_MACRO:
      if (record->event.pressed) {
        #ifdef OLED_DRIVER_ENABLE
          oled_write(read_logo(), false);
        #endif
        SEND_STRING(SS_LGUI(SS_TAP(X_ENTER)));
        wait_ms(500);
        SEND_STRING("cd ~/src/qmk-firmware" SS_TAP(X_ENTER));
        wait_ms(100);
        SEND_STRING("sleep 1 && make "QMK_KEYBOARD":"QMK_KEYMAP":dfu && exit" SS_TAP(X_ENTER));
        reset_keyboard();
        return false;
        break;
     }
  }
  return true;
}
