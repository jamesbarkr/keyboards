#include "os_mode.h"

#if DEFAULT_OS == MACOS
	static uint8_t os_mode = MACOS;
#else
	static uint8_t os_mode = WINDOWS;
#endif

bool process_os_mode(uint16_t keycode, keyrecord_t* record, uint16_t os_mode_keycode) {
	if (keycode == os_mode_keycode) {
		if (record->event.pressed) {
			cycle_os_mode();
		}
		return false;
	}

	for (int i = 0; i < NUM_OS_KEYS; ++i) {
		if (keycode == os_keys[i].keycode) {
			uint16_t os_keycode = os_mode == WINDOWS ? 
							os_keys[i].win_keycode : 
							os_keys[i].mac_keycode;

			if (record->event.pressed) {
				register_code16(os_keycode);
			} else {
				unregister_code16(os_keycode);
			}
			return false;
		}
	}

	if (os_mode == MACOS) {
		for (int i = 0; i < NUM_OS_MODS; ++i) {
			if (keycode == os_mods[i].keycode && !record->tap.count) {
				if (record->event.pressed) {
					register_code16(os_mods[i].mac_keycode);
				} else {
					unregister_code16(os_mods[i].mac_keycode);
				}
				return false;
			}
		}
	}
	return true;
}

bool process_os_print(uint16_t keycode, keyrecord_t* record, uint16_t os_print_keycode) {
	if (keycode == os_print_keycode) {
		if (record->event.pressed) {
			print_os_mode();
		}
		return false;
	}
	return true;
}

uint8_t get_os_mode() {
	return os_mode;
}

void print_os_mode() {
	if (os_mode == WINDOWS) {
		SEND_STRING("Windows");
	} else {
		SEND_STRING("MacOS");
	}
}

void set_os_mode(uint8_t mode) {
	if (os_mode >= WINDOWS && os_mode <= MACOS) {
		os_mode = mode;
	}
}

void cycle_os_mode() {
	if (os_mode == WINDOWS) {
		set_os_mode(MACOS);
	} else {
		set_os_mode(WINDOWS);
	}
}