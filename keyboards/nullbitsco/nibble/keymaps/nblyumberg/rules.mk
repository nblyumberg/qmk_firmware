# Enable bootmagic to allow EEPROM reset with
BOOTMAGIC_ENABLE = lite

# Enable the VIA Integration
VIA_ENABLE = yes
LTO_ENABLE = yes

# Include additional source files
SRC += keymaps/via/nibble_encoder.c
SRC += keymaps/via/via_extras.c

# Enable Tap Dance
TAP_DANCE = yes
IGNORE_MOD_TAP_INTERRUPT = yes
150TAPPING_TERM = 200
