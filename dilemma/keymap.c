/**
 * Copyright 2024 Connor Barker <connorbarkr@gmail.com> (@connorbarkr)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "connorbarkr.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAK] = LAYOUT_split_3x5_3(
//	  		-------------------------------------------------			-------------------------------------------------
        	KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,               KC_J,     KC_L,     KC_U,     KC_Y,    KC_QUOT,
//	  		-------------------------------------------------			-------------------------------------------------
            KC_A,     KC_R,     KC_S,     KC_T,     KC_G,               KC_M,     KC_N,     KC_E,     KC_I,    KC_O,
//	  		-------------------------------------------------			-------------------------------------------------
            QC_Z,     QC_X,     QC_C,     KC_D,     KC_V,               KC_K,     KC_H,     QC_COMM,  QC_DOT,  QC_SLSH,
//	  		-------------------------------------------------			-------------------------------------------------
            			   OSM(MOD_LSFT), QC_BSPC,  TD(SWAP),           QC_TAB,   QC_SPC,   QC_ENT					
//	  							-----------------------------			-----------------------------
	),
	[_QWERTY] = LAYOUT_split_3x5_3(
//			-------------------------------------------------			-------------------------------------------------
        	KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,
//	  		-------------------------------------------------			-------------------------------------------------
			KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,
//	  		-------------------------------------------------			-------------------------------------------------
            QC_Z,     QC_X,     QC_C,     KC_V,     KC_B,               KC_N,     KC_M,     QC_COMM,  QC_DOT,  QC_SLSH,
//	  		-------------------------------------------------			-------------------------------------------------
            					______,   ______,   ______,             ______,   ______,   ______					
//	  							-----------------------------			-----------------------------
	),
	[_GAME] = LAYOUT_split_3x5_3(
//			-------------------------------------------------			-------------------------------------------------
        	KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,               XXXXXX,   XXXXXX,   KC_UP,    XXXXXX,   XXXXXX,
//	  		-------------------------------------------------			-------------------------------------------------
			KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,               XXXXXX,   KC_LEFT,  KC_DOWN,  KC_RIGHT, XXXXXX,
//	  		-------------------------------------------------			-------------------------------------------------
            KC_LCTL,  QC_Z,     QC_X,     KC_C,     KC_V,               XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,
//	  		-------------------------------------------------			-------------------------------------------------
            					KC_LSFT,  KC_SPC,   KC_TAB,             QC_TAB,   XXXXXX,   XXXXXX					
//	  							-----------------------------			-----------------------------
	),
	[_NAV] = LAYOUT_split_3x5_3(
//	  		-------------------------------------------------			-------------------------------------------------
			QC_DLIN,  QC_UCRS,  LINE_UP,  QC_CPAL,  QC_ACU,             QC_CUT,   QC_CPY,   KC_UP,    QC_PAS,   KC_PGUP,
//	  		-------------------------------------------------			-------------------------------------------------
			KC_HOME,  QC_BACK,  LINE_DN,  QC_FOR,   KC_END,             QC_LWRD,  KC_LEFT,  KC_DOWN,  KC_RIGHT, QC_RWRD,
//	  		-------------------------------------------------			-------------------------------------------------
			QC_MOD3,  QC_MOD2,  QC_MOD1,  QC_LINE,  QC_ACD,             QC_PRNT,  QC_UNDO,  KC_DOWN,  QC_REDO,  KC_PGDN,
//	  		-------------------------------------------------			-------------------------------------------------
								KC_LSFT,  QC_WBSP,  KC_TAB,             XXXXXX,   ______,   XXXXXX					
//	  							-----------------------------			-----------------------------
	),
	[_SYM] = LAYOUT_split_3x5_3(
//	  		-------------------------------------------------			-------------------------------------------------
            KC_ESC,   KC_LBRC,  KC_RBRC,  KC_TILD,  KC_AT,              KC_CIRC,  KC_UDIR,  KC_LABK,  KC_RABK,  KC_GRV,
//	  		-------------------------------------------------			-------------------------------------------------
            KC_COLN,  KC_LPRN,  KC_RPRN,  KC_EXLM,  KC_SCLN,            KC_TEQ,   KC_EQL,   KC_LCBR,  KC_RCBR,  KC_ASTR,
//	  		-------------------------------------------------			-------------------------------------------------
            KC_DLR,   KC_PERC,  KC_HASH,  KC_QUES,  KC_AMPR,            KC_PIPE,  KC_UNDS,  KC_PLUS,  KC_MINS,  KC_BSLS,
//	  		-------------------------------------------------			-------------------------------------------------
            					PREV_TAB, KC_BSPC,  NEXT_TAB,           XXXXXX,   XXXXXX,   ______					
//	  							-----------------------------			-----------------------------
	),
	[_NUM] = LAYOUT_split_3x5_3(
//	  		-------------------------------------------------			-------------------------------------------------
			XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,             KC_PLUS,  KC_1,     KC_2,     KC_3,     KC_LT,
//	  		-------------------------------------------------			-------------------------------------------------
			XXXXXX,   XXXXXX,   KC_BTN2,  KC_BTN1,  XXXXXX,             KC_0,     KC_4,     KC_5,     KC_6,     KC_DOT,
//	  		-------------------------------------------------			-------------------------------------------------
			QC_MOD3,  QC_MOD2,  QC_MOD1,  RGB_MOD,  RGB_TOG,            KC_MINS,  KC_7,     KC_8,     KC_9,     KC_EQL,
//	  		-------------------------------------------------			-------------------------------------------------
            					XXXXXX,   ______,   XXXXXX,             QC_MTAB,  KC_SPC,   KC_ENT					
//	  							-----------------------------			-----------------------------
	),
	[_MEDIA] = LAYOUT_split_3x5_3(
//	  		-------------------------------------------------			-------------------------------------------------
			QC_LOCK,  KC_F1,    KC_F2,    KC_F3,    KC_F4,              KC_VOLU,  XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,
//	  		-------------------------------------------------			-------------------------------------------------
			XXXXXX,   KC_F5,    KC_F6,    KC_F7,    KC_F8,              KC_VOLD,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MSTP,
//	  		-------------------------------------------------			-------------------------------------------------
			XXXXXX,   KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_MUTE,  KC_LSFT,  QC_MOD1,  QC_MOD2,  QC_MOD3,
//	  		-------------------------------------------------			-------------------------------------------------
            					PHONE,    EMAIL,    XXXXXX,             ______,   XXXXXX,   XXXXXX					
//	  							-----------------------------			-----------------------------
	),
    [_MOUSE] = LAYOUT_split_3x5_3(
//	  		-------------------------------------------------			-------------------------------------------------
			XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,             XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,
//	  		-------------------------------------------------			-------------------------------------------------
			XXXXXX,   XXXXXX,   KC_BTN2,  KC_BTN1,  XXXXXX,             XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   
//	  		-------------------------------------------------			-------------------------------------------------
			XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,             XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   
//	  		-------------------------------------------------			-------------------------------------------------
            					XXXXXX,   XXXXXX,   XXXXXX,             XXXXXX,   XXXXXX,   XXXXXX					
//	  							-----------------------------			-----------------------------
	),
};
