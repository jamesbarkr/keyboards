#include "connorbarkr.h"

const custom_shift_key_t custom_shift_keys[] = {
	{QC_COMM, KC_EXLM},
	{QC_DOT, KC_MINS},
};

const os_key_t os_keys[] = {
	{QC_CPY, LCTL(KC_C), LGUI(KC_C)},
	{QC_PAS, LCTL(KC_V), LGUI(KC_V)},
	{QC_CUT, LCTL(KC_X), LGUI(KC_X)},
	{QC_SAVE, LCTL(KC_S), LGUI(KC_S)},
	{QC_LWRD, LCTL(KC_LEFT), LALT(KC_LEFT)},
	{QC_RWRD, LCTL(KC_RIGHT), LALT(KC_RIGHT)},
	{QC_WBSP, LCTL(KC_BSPC), LALT(KC_BSPC)},
	{QC_UNDO, LCTL(KC_Z), LGUI(KC_Z)},
	{QC_REDO, RCS(KC_Z), RSG(KC_Z)},
	{QC_PRNT, LGUI(LSFT(KC_S)), SCMD(KC_4)},
	{QC_LOCK, LGUI(KC_L), LCTL(LGUI(KC_Q))},
	{QC_MTAB, KC_TAB, LGUI(KC_GRV)},
	{QC_MOD1, KC_LCTL, KC_LGUI},
	{QC_MOD2, KC_LALT, KC_LCTL},
	{QC_MOD3, KC_LGUI, KC_LALT},
	{QC_LINE, LCTL(KC_L), LGUI(KC_L)},
	{QC_DLIN, RCS(KC_K), RSG(KC_K)},
	{QC_CPAL, RCS(KC_P), RSG(KC_P)},
	{QC_UCRS, LCTL(KC_U), LGUI(KC_U)},
	{QC_ACU, LCA(KC_UP), LAG(KC_UP)},
	{QC_ACD, LCA(KC_DOWN), LAG(KC_DOWN)},
	{QC_BACK, LALT(KC_LEFT), LGUI(KC_LEFT)},
	{QC_FOR, LALT(KC_RIGHT), LGUI(KC_RIGHT)},
};

const os_key_t os_mods[] = {
	{QC_Z, KC_LGUI, KC_LALT},
	{QC_X, KC_LALT, KC_LCTL},
	{QC_C, KC_LCTL, KC_LGUI},
	{QC_SLSH, KC_RGUI, KC_RALT},
	{QC_DOT, KC_RALT, KC_RCTL},
	{QC_COMM, KC_RCTL, KC_RGUI},
};

uint8_t NUM_OS_KEYS = sizeof(os_keys) / sizeof(os_key_t);
uint8_t NUM_OS_MODS = sizeof(os_mods) / sizeof(os_key_t);

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!process_os_mode(keycode, record, QC_OS)) { return false; }

	switch (keycode) {
		case KC_TEQ:
			if (record->event.pressed)
			{
				SEND_STRING("===");
			}
			break;

		case KC_UDIR:
			if (record->event.pressed)
			{
				SEND_STRING("../");
			}
			break;

		case PHONE:
			if (record->event.pressed)
			{
				SEND_STRING("+1 (226) 338-7794");
			}
			break;

		case EMAIL:
			if (record->event.pressed)
			{
				SEND_STRING("connorbarkr@gmail.com");
			}
			break;
	}

	return process_record_keymap(keycode, record);
}

td_state_t cur_dance(tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) {
			return TD_SINGLE_TAP;
		} else {
			return TD_SINGLE_HOLD;
		}
	} else if (state->count == 2) {
		if (state->pressed) {
			return TD_DOUBLE_HOLD;
		} else {
			return TD_DOUBLE_TAP;
		}
	} else if (state->count == 3) {
		if (!state->pressed) {
			return TD_TRIPLE_TAP;
		}
	}

	return TD_UNKNOWN;
}

static td_tap_t swap_tap_state = {
	.is_press_action = true,
	.state = TD_NONE
};

void swap_finished(tap_dance_state_t *state, void *user_data) {
	swap_tap_state.state = cur_dance(state);
	switch (swap_tap_state.state) {
		case TD_SINGLE_TAP:
			if (get_os_mode() == WINDOWS) {
				tap_code16(LALT(KC_TAB));
			} else {
				tap_code16(LGUI(KC_TAB));
			}
			break;
		case TD_SINGLE_HOLD:
			if (get_os_mode() == WINDOWS) {
				register_code(KC_LALT);
				tap_code(KC_TAB);
			} else {
				register_code(KC_LGUI);
				tap_code(KC_TAB);
			}
			break;
		case TD_DOUBLE_TAP:
			if (get_os_mode() == WINDOWS) {
				tap_code16(LALT(KC_SPC));
			} else {
				tap_code16(LGUI(KC_SPC));
			}
			break;
		default:
			break;
	}
}

void swap_reset(tap_dance_state_t *state, void *user_data) {
	switch (swap_tap_state.state) {
		case TD_SINGLE_TAP:
			break;
		case TD_SINGLE_HOLD:
			if (get_os_mode() == WINDOWS) {
				unregister_code(KC_LALT);
			} else {
				unregister_code(KC_LGUI);
			}
			break;
		case TD_DOUBLE_TAP:
		default:
			break;
	}
	swap_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
	[SWAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, swap_finished, swap_reset)
};

// this is here to disable the underglow layer indicator on the dilemma
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	return false;
}