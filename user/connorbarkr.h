#pragma once

#include QMK_KEYBOARD_H
#include "features/caps_word.h"
#include "features/custom_shift_keys.h"
#include "features/layer_lock.h"

enum custom_keycodes {
	PHONE = SAFE_RANGE,
	EMAIL,
	KC_UDIR,
	KC_TEQ,
	WIN_MODE,
	MAC_MODE,
	LLOCK,
};

enum layer_names {
	WIN,
	WIN_NAV,
	WIN_NUM,
	WIN_SYM,
	WIN_MEDIA,
	MAC,
	MAC_NAV,
	MAC_NUM,
	MAC_SYM,
	MAC_MEDIA,
	QWERTY,
	GAME,
};

enum tap_dances {
	OSFT,
	PWIN,
	PMAC,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
	TD_TRIPLE_TAP,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// universal
#define GO_QWERT DF(QWERTY)
#define GO_GAME DF(GAME)
#define LINE_UP LALT(KC_UP)
#define LINE_DN LALT(KC_DOWN)
#define NEXT_TAB LCTL(KC_TAB)

// windows
#define GUI_Z LGUI_T(KC_Z)
#define ALT_X LALT_T(KC_X)
#define CTL_C LCTL_T(KC_C)
#define GUI_SLSH RGUI_T(KC_SLSH)
#define ALT_DOT RALT_T(KC_DOT)
#define CTL_COMM RCTL_T(KC_COMM)
#define WIN_BSPC LT(WIN_NUM, KC_BSPC)
#define WIN_TAB LT(WIN_MEDIA, KC_TAB)
#define WIN_SPC LT(WIN_NAV, KC_SPC)
#define WIN_ENT LT(WIN_SYM, KC_ENT)

#define WIN_CPY LCTL(KC_C)
#define WIN_PAS LCTL(KC_V)
#define WIN_CUT LCTL(KC_X)
#define WIN_SAVE LCTL(KC_S)
#define WIN_LWRD LCTL(KC_LEFT)
#define WIN_RWRD LCTL(KC_RIGHT)
#define WIN_WBSP LCTL(KC_BSPC)
#define WIN_UNDO LCTL(KC_Z)
#define WIN_REDO RCS(KC_Z)
#define WIN_PRNT LGUI(LSFT(KC_S))
#define WIN_LINE LCTL(KC_L)
#define WIN_DLIN RCS(KC_K)
#define WIN_CPAL RCS(KC_P)
#define WIN_UCRS LCTL(KC_U)
#define WIN_ACU LCA(KC_UP)
#define WIN_ACD LCA(KC_DOWN)
#define WIN_ACWD LCTL(KC_D)

#define GO_MAC DF(MAC)

// mac
#define ALT_Z LALT_T(KC_Z)
#define CTL_X LCTL_T(KC_X)
#define GUI_C LGUI_T(KC_C)
#define ALT_SLSH RALT_T(KC_SLSH)
#define CTL_DOT RCTL_T(KC_DOT)
#define GUI_COMM RGUI_T(KC_COMM)
#define MAC_BSPC LT(MAC_NUM, KC_BSPC)
#define MAC_TAB LT(MAC_MEDIA, KC_TAB)
#define MAC_SPC LT(MAC_NAV, KC_SPC)
#define MAC_ENT LT(MAC_SYM, KC_ENT)

#define MAC_CPY LGUI(KC_C)
#define MAC_PAS LGUI(KC_V)
#define MAC_CUT LGUI(KC_X)
#define MAC_SAVE LGUI(KC_S)
#define MAC_LWRD LALT(KC_LEFT)
#define MAC_RWRD LALT(KC_RIGHT)
#define MAC_WBSP LALT(KC_BSPC)
#define MAC_UNDO LGUI(KC_Z)
#define MAC_REDO RSG(KC_Z)
#define MAC_PRNT SCMD(KC_4)
#define MAC_LINE LGUI(KC_L)
#define MAC_DLIN RSG(KC_K)
#define MAC_CPAL RSG(KC_P)
#define MAC_UCRS LGUI(KC_U)
#define MAC_ACU LAG(KC_UP)
#define MAC_ACD LAG(KC_DOWN)
#define MAC_ACWD LGUI(KC_D)

#define GO_WIN DF(WIN)
#define MAC_SLEP LCTL(LGUI(KC_Q))

// dactyl-specific
#define DAC_BSPC LT(4, KC_BSPC)
#define DAC_TAB LT(5, KC_TAB)
#define DAC_SPC LT(2, KC_SPC)
#define DAC_ENT LT(3, KC_ENT)

td_state_t cur_dance(qk_tap_dance_state_t *state);
void sft_finished(qk_tap_dance_state_t *state, void *user_data);
void sft_reset(qk_tap_dance_state_t *state, void *user_data);
