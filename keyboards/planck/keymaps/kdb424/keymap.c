#include QMK_KEYBOARD_H
#include "kdb424.c"

extern keymap_config_t keymap_config;


// Short codes to make reading easier
#define LT2_SP LT(_RAISE2, KC_SPC)
#define U_ARROW LT(_ARROWS, KC_U)
#define SWAY LM(_NUMBERS, MOD_LGUI)
#define CTLPGUP LCTL(KC_PGUP)
#define CTLPGDN LCTL(KC_PGDN)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  |      | MO(1)|Space2|Space3| Ctrl | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_GESC, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_F,   KC_G,   KC_C,    KC_R,    KC_L,  KC_BSPC, \
  KC_TAB,  KC_A,    KC_O,    KC_E,    U_ARROW, KC_I,   KC_D,   KC_H,   KC_T,    KC_N,    KC_S,  KC_ENT,  \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_B,   KC_M,   KC_W,    KC_V,    KC_Z,  KC_SLASH,  \
  KC_LCTL, KC_LGUI, KC_LALT, SWAY,    MO(2),   LT2_SP, LT2_SP, MO(4),  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT  \
),

/* Gaming - Only changes to left half to add more keys for mapping
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  |  F1  |  F2  |Space |Space3| Ctrl | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_F,   KC_G,   KC_C,    KC_R,    KC_L,  KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   KC_D,   KC_H,   KC_T,    KC_N,    KC_S,  KC_ENT,  \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_B,   KC_M,   KC_W,    KC_V,    KC_Z,  KC_SLASH,  \
  KC_LCTL, KC_LGUI, KC_LALT, KC_F1,   KC_F2,   KC_SPC, KC_SPC, MO(4),  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT  \
),

/* RAISE1
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Ins  |      |      |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RESET |      |      |      |      |      |      |      | Home | RGDN | PGUP | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE1] = LAYOUT_ortho_4x12( \
	KC_LEAD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_LEAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, \
  ______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  _______, _______, KC_MINS, \
  REPROGR, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_EQL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END \
),

/* RAISE2
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  7   |  8   |  9   | BKSP |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  4   |  5   |  6   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  1   |  2   |  3   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  0   |  0   |  P.  |ENTER |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE2] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9,    KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_4, KC_5, KC_6,    XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3,    XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_0, KC_PDOT, KC_ENT \

),

/* RAISE3
 * ,-----------------------------------------------------------------------------------.
 * |RESET |PROGRA|      |      |Static| BRI+ |SGRAD |      | F10  | F11  | F12  |Paste |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |Rainbo| BRI- |K RIDR|      |  F7  |  F8  |  F9  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |RMODE | RGB T|SWIRL |      |  F4  |  F5  |  F6  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |DVORAK|GAMING|      |      |      |      |      |      |  F1  |  F2  |  F3  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE3] =  LAYOUT_ortho_4x12( \
  REPROGR, RESET,   _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, LSFT(KC_INSERT), \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_F7,  KC_F8,  KC_F9,  CTLPGUP, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_F4,  KC_F5,  KC_F6,  CTLPGDN, \
  DF(0),   DF(1),   _______, _______, _______, _______, _______, _______, KC_F1,  KC_F2,  KC_F3,  _______ \
  ),

/* Arrows
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | MOD4 |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROWS] = LAYOUT_ortho_4x12( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
),
/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |  4   |   5  |  6   |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT_ortho_4x12( \
  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
),

};


void matrix_init_user(void) {
#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  PLAY_SONG(plover_song);
#endif
};

