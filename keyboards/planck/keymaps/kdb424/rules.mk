BOOTLOADER        = qmk-dfu # caterina is bad and it should feel bad. I don't use anything but DFU
BACKLIGHT_ENABLE  = no      # Enable keyboard backlight functionality
TAP_DANCE_ENABLE  = no     # Enable tap dance.
UNICODE_ENABLE    = no
UNICODEMAP_ENABLE = no
UCIS_ENABLE       = no
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
LEADER_ENABLE = yes

ifeq ($(strip $(KEYBOARD)), planck/rev6)
  AUDIO_ENABLE    = yes
  RGBLIGHT_ENABLE = no
else
  USE_IC2         = no
  AUDIO_ENABLE    = no
  RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
endif

# Enable N-Key Rollover, except in cases of VUSB:
# Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
#ifeq ($(strip $(PROTOCOL)), VUSB)
#  NKRO_ENABLE = no
##else
#  NKRO_ENABLE = yes
#endif

#EXTRAFLAGS        += -flto
