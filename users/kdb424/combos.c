#pragma once

enum combo_events {
  MB_SCRATCH,
  LR_PASTE
};

const uint16_t PROGMEM copy_combo[] = {KC_M, KC_B, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_L, KC_R, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [MB_SCRATCH] = COMBO_ACTION(copy_combo),
  [LR_PASTE] = COMBO_ACTION(paste_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case MB_SCRATCH:
      if (pressed) {
        tap_code16(LGUI(KC_D));
      }
      break;
    case LR_PASTE:
      if (pressed) {
        tap_code16(LSFT(KC_INS));
      }
      break;
  }
}
