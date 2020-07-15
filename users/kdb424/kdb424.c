#include "kdb424.h"

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if(IS_LAYER_ON(_RAISE1)) { // on Raise layer control volume
        if (index == 0) {
            if (clockwise) {
                #if defined(RGBLIGHT_ENABLE)
                rgblight_increase_hue_noeeprom();
                #endif
            } else {
                #if defined(RGBLIGHT_ENABLE)
                rgblight_decrease_hue_noeeprom();
                #endif
            }
        } else if (index == 1) {
            if (clockwise) {
                #if defined(RGBLIGHT_ENABLE)
                rgblight_increase_val_noeeprom();
                #endif
            } else {
                #if defined(RGBLIGHT_ENABLE)
                rgblight_decrease_val_noeeprom();
                #endif
            }
        }
    } else {
        if (index == 0) {
            if (clockwise) {
                tap_code16(C(KC_R));
            } else {
                tap_code(KC_U);
            }
        } else if (index == 1) {
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
        }
    }
}

#endif

