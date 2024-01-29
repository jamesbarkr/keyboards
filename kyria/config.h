/*
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

#undef RGBLED_NUM
#undef RGBLED_SPLIT

#define DEFAULT_OS WINDOWS

#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT \
    { 8, 8 }
#define RGBLED_NUM 16
#define RGBLIGHT_DEFAULT_HUE 17