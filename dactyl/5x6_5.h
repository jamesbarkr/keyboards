/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2022 Connor Barker <connorbarkr@gmail.com>
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
#define XXX KC_NO

#define LAYOUT_qnr_5x6_5(                                \
  k00, k01, k02, k03, k04,     k54, k53, k52, k51, k50, \
  k10, k11, k12, k13, k14,     k64, k63, k62, k61, k60, \
  k20, k21, k22, k23, k24,     k74, k73, k72, k71, k70, \
            k33, k43, k44,     k94, k93, k83,           \
				 k41, k42,     k92, k91					\
)                                                       \
{ \
	{ XXX, XXX, XXX, XXX, XXX, XXX }, \
    { XXX, k00, k01, k02, k03, k04 }, \
    { XXX, k10, k11, k12, k13, k14 }, \
    { XXX, k20, k21, k22, k23, k24 }, \
    { XXX, XXX, XXX, XXX, k33, XXX }, \
    { XXX, XXX, k41, k42, k43, k44 }, \
\
	{ XXX, XXX, XXX, XXX, XXX, XXX }, \
    { k54, k53, k52, k51, k50, XXX }, \
	{ k64, k63, k62, k61, k60, XXX }, \
	{ k74, k73, k72, k71, k70, XXX }, \
    { XXX, k83, XXX, XXX, XXX, XXX }, \
    { k94, k93, k92, k91, XXX, XXX }, \
}
