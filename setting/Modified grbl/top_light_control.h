/*
  light_control.h - spindle control methods
  Part of Grbl

  Copyright (c) 2012-2016 Sungeun K. Jeon for Gnea Research LLC

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef top_light_control_h
#define top_light_control_h

#define TOP_LIGHT_NO_SYNC     false
#define TOP_LIGHT_FORCE_SYNC  true

#define TOP_LIGHT_STATE_DISABLE   0  // Must be zero
#define TOP_LIGHT_STATE     bit(0)


// Initializes light control pins.
void top_light_init();

// Returns current light output state. Overrides may alter it from programmed state.
uint8_t top_light_get_state();

// Immediately disables light pins.
void top_light_stop();

// Sets the light pins according to state specified.
void top_light_set_state(uint8_t mode);

// G-code parser entry-point for setting light states. Checks for and executes additional conditions.
void top_light_sync(uint8_t mode);

#endif