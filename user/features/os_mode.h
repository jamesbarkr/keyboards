#pragma once

#include QMK_KEYBOARD_H

enum os_modes {
	WINDOWS,
	MACOS,
};

typedef struct {
  uint16_t keycode;
  uint16_t win_keycode;
  uint16_t mac_keycode;
} os_key_t;

extern const os_key_t os_keys[];
extern const os_key_t os_mods[];
extern uint8_t NUM_OS_KEYS;
extern uint8_t NUM_OS_MODS;

bool process_os_mode(uint16_t keycode, keyrecord_t* record, uint16_t os_mode_keycode);

uint8_t get_os_mode(void);

void set_os_mode(uint8_t mode);

void cycle_os_mode(void);