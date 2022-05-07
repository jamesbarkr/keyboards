# Build Options
#   change yes to no to disable
#
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes		# Split keyboard
AUDIO_SUPPORTED = no		# Keyboard speaker
TAP_DANCE_ENABLE = yes		# Tap dance
LTO_ENABLE = yes			# Link time optimization
SPACE_CADET_ENABLE = no		# Shift key mods
GRAVE_ESC_ENABLE = no 		# Escape key mods
MAGIC_ENABLE = no			# Magic keycodes
MUSIC_ENABLE = no			# Keyboard audio music
COMBO_ENABLE = no			# Key combos

SRC += ./connorbarkr.c \
	   ./features/caps_word.c \
	   ./features/custom_shift_keys.c \
	   ./features/os_mode.c \
	#    ./features/layer_lock.c 