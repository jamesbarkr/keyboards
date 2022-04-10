#include "connorbarkr.h"

const custom_shift_key_t custom_shift_keys[] = {
	{GUI_COMM, KC_EXLM},
	{CTL_DOT, KC_MINS},
	{CTL_COMM, KC_EXLM},
	{ALT_DOT, KC_MINS},
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record)
{
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{

	if (!process_caps_word(keycode, record))
	{
		return false;
	}
	if (!process_layer_lock(keycode, record, LLOCK))
	{
		return false;
	}
	if (!process_custom_shift_keys(keycode, record))
	{
		return false;
	}

	switch (keycode)
	{
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

	case WIN_MODE:
		if (record->event.pressed)
		{
			SEND_STRING("WIN");
		}
		break;

	case MAC_MODE:
		if (record->event.pressed)
		{
			SEND_STRING("MAC");
		}
		break;
	}

	return process_record_keymap(keycode, record);
}

#define THUMB_EXTRA 50
#define DIGIT_EXTRA 75

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode)
	{
	case GUI_Z:
	case ALT_X:
	case CTL_C:
	case GUI_SLSH:
	case ALT_DOT:
	case CTL_COMM:
	case ALT_Z:
	case CTL_X:
	case GUI_C:
	case ALT_SLSH:
	case CTL_DOT:
	case GUI_COMM:
		return TAPPING_TERM + DIGIT_EXTRA;
	case DAC_BSPC:
	case DAC_TAB:
	case DAC_SPC:
	case WIN_BSPC:
	case WIN_TAB:
	case WIN_SPC:
	case WIN_ENT:
	case MAC_BSPC:
	case MAC_TAB:
	case MAC_SPC:
	case MAC_ENT:
		return TAPPING_TERM + THUMB_EXTRA;
	default:
		return TAPPING_TERM;
	}
}

void matrix_scan_user(void)
{
	caps_word_task();
}

td_state_t cur_dance(qk_tap_dance_state_t *state)
{
	if (state->count == 1)
	{
		if (state->interrupted || !state->pressed)
			return TD_SINGLE_TAP;
		else
			return TD_SINGLE_HOLD;
	}
	else if (state->count == 2)
	{
		if (state->pressed)
			return TD_DOUBLE_HOLD;
		else
			return TD_DOUBLE_TAP;
	}
	else if (state->count == 3)
	{
		if (!state->pressed)
			return TD_TRIPLE_TAP;
	}

	return TD_UNKNOWN;
}

static td_tap_t sftap_state = {
	.is_press_action = true,
	.state = TD_NONE};

static td_tap_t win_tap_state = {
	.is_press_action = true,
	.state = TD_NONE};

static td_tap_t mac_tap_state = {
	.is_press_action = true,
	.state = TD_NONE};

void sft_finished(qk_tap_dance_state_t *state, void *user_data)
{
	sftap_state.state = cur_dance(state);
	switch (sftap_state.state)
	{
	case TD_SINGLE_TAP:
		if (caps_word_get())
		{
			caps_word_set(false);
			clear_oneshot_mods();
		}
		else
		{
			set_oneshot_mods(MOD_LSFT);
		}
		break;
	case TD_SINGLE_HOLD:
		register_code(KC_LSFT);
		break;
	case TD_DOUBLE_TAP:
		caps_word_set(true);
		break;
	case TD_TRIPLE_TAP:
		tap_code(KC_CAPS);
		break;
	default:
		break;
	}
}

void sft_reset(qk_tap_dance_state_t *state, void *user_data)
{
	switch (sftap_state.state)
	{
	case TD_SINGLE_TAP:
		break;
	case TD_SINGLE_HOLD:
		unregister_code(KC_LSFT);
		break;
	case TD_DOUBLE_TAP:
	case TD_TRIPLE_TAP:
	default:
		break;
	}
	sftap_state.state = TD_NONE;
}

void win_finished(qk_tap_dance_state_t *state, void *user_data)
{
	win_tap_state.state = cur_dance(state);
	switch (win_tap_state.state)
	{
	case TD_SINGLE_TAP:
		tap_code16(LALT(KC_TAB));
		break;
	case TD_SINGLE_HOLD:
		register_code(KC_LALT);
		tap_code(KC_TAB);
		break;
	case TD_DOUBLE_TAP:
		tap_code16(LALT(KC_SPC));
		break;
	default:
		break;
	}
}

void win_reset(qk_tap_dance_state_t *state, void *user_data)
{
	switch (win_tap_state.state)
	{
	case TD_SINGLE_TAP:
		break;
	case TD_SINGLE_HOLD:
		unregister_code(KC_LALT);
		break;
	case TD_DOUBLE_TAP:
	default:
		break;
	}
	win_tap_state.state = TD_NONE;
}

void mac_finished(qk_tap_dance_state_t *state, void *user_data)
{
	mac_tap_state.state = cur_dance(state);
	switch (mac_tap_state.state)
	{
	case TD_SINGLE_TAP:
		tap_code16(LGUI(KC_TAB));
		break;
	case TD_SINGLE_HOLD:
		register_code(KC_LGUI);
		tap_code(KC_TAB);
		break;
	case TD_DOUBLE_TAP:
		tap_code16(LGUI(KC_SPC));
		break;
	default:
		break;
	}
}

void mac_reset(qk_tap_dance_state_t *state, void *user_data)
{
	switch (mac_tap_state.state)
	{
	case TD_SINGLE_TAP:
		break;
	case TD_SINGLE_HOLD:
		unregister_code(KC_LGUI);
		break;
	case TD_DOUBLE_TAP:
	default:
		break;
	}
	mac_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[OSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset),
	[PWIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, win_finished, win_reset),
	[PMAC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mac_finished, mac_reset)};