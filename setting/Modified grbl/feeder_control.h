/*
  coolant_control.h - spindle control methods
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

#ifndef feeder_control_h
#define feeder_control_h


#define FEEDER_NO_SYNC     false
#define FEEDER_FORCE_SYNC  true

#define FEEDER_STATE_DISABLE   0  // Must be zero
#define FEEDER_STATE_TWO     bit(0)

#define FEEDER_STATE_ONE     bit(1)
#define FEEDER_STATE_TWO     bit(2)
#define FEEDER_STATE_THREE    bit(3)
#define FEEDER_STATE_FOUR    bit(4)

//#define FEEDER_STATE_FOUR    bit(3)
//#define FEEDER_STATE_THREE    bit(4)
//#define FEEDER_STATE_FOUR    bit(5)




// Initializes feeder control pins.
void feeder_init();

// Returns current feeder output state. Overrides may alter it from programmed state.
uint8_t feeder_get_state();

// Immediately disables feeder pins.
void feeder_stop();

// Sets the feeder pins according to state specified.
void feeder_set_state(uint8_t mode);

// G-code parser entry-point for setting elay states. Checks for and executes additional conditions.
void feeder_sync(uint8_t mode);

#endif
