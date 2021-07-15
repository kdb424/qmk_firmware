#pragma once

#ifdef COMBO_ENABLE
enum combo_events {
  MB_SCRATCH,
  NS_PASTE,
  CD_HAPPY,
  QD_LOOK,
  VZ_UNDO,
  L_BACK
};

const uint16_t PROGMEM copy_combo[] = {KC_M, KC_B, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_N, KC_S, COMBO_END};
const uint16_t PROGMEM happy_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM look_combo[] = {KC_QUOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM undo_combo[] = {KC_V, KC_Z, COMBO_END};
const uint16_t PROGMEM back_combo[] = {KC_L, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [MB_SCRATCH] = COMBO_ACTION(copy_combo),
  [NS_PASTE] = COMBO_ACTION(paste_combo),
  [CD_HAPPY] = COMBO_ACTION(happy_combo),
  [QD_LOOK] = COMBO_ACTION(look_combo),
  [VZ_UNDO] = COMBO_ACTION(undo_combo),
  [L_BACK] = COMBO_ACTION(back_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case MB_SCRATCH:
      if (pressed) {
        tap_code16(LGUI(KC_D));
      }
      break;
    case NS_PASTE:
      if (pressed) {
        tap_code16(LSFT(KC_INS));
      }
      break;
    case CD_HAPPY:
      if (pressed) {
        tap_code16(LSFT(KC_DOT));
        tap_code16(LSFT(KC_COMM));
      }
      break;
    case QD_LOOK:
      if (pressed) {
        tap_code16(LSFT(KC_DOT));
        tap_code16(LSFT(KC_MINS));
        tap_code16(LSFT(KC_DOT));
      }
      break;
    case VZ_UNDO:
      if (pressed) {
        tap_code16(LCTL(KC_Z));
      }
      break;
    case L_BACK:
      if (pressed) {
        tap_code16(LCTL(KC_BSPC));
      }
      break;
  }
}

#endif
