/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
 * Copyright 2022 Connor Barker <connorbarkr@gmail.com>nn
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

#pragma once
#include "quantum.h"

#define LAYOUT_qnr_kyria(                              					 \
  k00, k01, k02, k03, k04,		    	 		k44, k43, k42, k41, k40, \
  k10, k11, k12, k13, k14,		    	 		k54, k53, k52, k51, k50, \
  k20, k21, k22, k23, k24,		    	 		k64, k63, k62, k61, k60, \
       k32, k33, k34, k35, k36,            k76, k75, k74, k73, k72	     \
)                                                       				 \
{ 																		 \
    { KC_NO, KC_NO, k04,   k03,   k02,   k01,   k00,   KC_NO }, 		 \
    { KC_NO, KC_NO, k14,   k13,   k12,   k11,   k10,   KC_NO }, 		 \
    { KC_NO, KC_NO, k24,   k23,   k22,   k21,   k20,   KC_NO }, 		 \
    { k36,   k35,   k34,   k33,   k32,   k32,   KC_NO, KC_NO }, 		 \
    { KC_NO, KC_NO, k44,   k43,   k42,   k41,   k40,   KC_NO }, 		 \
    { KC_NO, KC_NO, k54,   k53,   k52,   k51,   k50,   KC_NO }, 		 \
    { KC_NO, KC_NO, k64,   k63,   k62,   k61,   k60,   KC_NO }, 		 \
    { k76,   k75,   k74,   k73,   k72,   k72,   KC_NO, KC_NO }, 	 	 \
}
