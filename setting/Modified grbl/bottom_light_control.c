/*
  light_control.c - light control methods
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

#include "grbl.h"


void bottom_light_init()
{
  BOTTOM_LIGHT_DDR |= (1 << BOTTOM_LIGHT_BIT); // Configure as output pin.
  bottom_light_stop();
}


// Returns current light output state. Overrides may alter it from programmed state.
uint8_t bottom_light_get_state()
{
    uint8_t lgt_state = BOTTOM_LIGHT_STATE_DISABLE;
	
	if ((BOTTOM_LIGHT_PORT |= (1 << BOTTOM_LIGHT_BIT))) {
    	lgt_state |= BOTTOM_LIGHT_STATE;
    return (lgt_state);
  	}
}


// Directly called by light_init(), light_set_state(), and mc_reset(), which can be at
// an interrupt-level. No report flag set, but only called by routines that don't need it.
void bottom_light_stop()
{
  BOTTOM_LIGHT_PORT &= ~(1 << BOTTOM_LIGHT_BIT);
}


// Main program only. Immediately sets flood light running state and also mist light, 
// if enabled. Also sets a flag to report an update to a light state.
// Called by light toggle override, parking restore, parking retract, sleep mode, g-code
// parser program end, and g-code parser light_sync().
void bottom_light_set_state(uint8_t mode)
{
  if (sys.abort) {
    return;  // Block during abort.
  }
  if (mode == BOTTOM_LIGHT_DISABLE) {
    bottom_light_stop();
  }
  else {
    if ( mode == BOTTOM_LIGHT_ENABLE) {
      BOTTOM_LIGHT_PORT |= (1 << BOTTOM_LIGHT_BIT);
    }
  }
  //sys.report_ovr_counter = 0; // Set to report change immediately
}

// G-code parser entry-point for setting light state. Forces a planner buffer sync and bails 
// if an abort or check-mode is active.
void bottom_light_sync(uint8_t mode)
{
  if (sys.state == STATE_CHECK_MODE) {
	return;
  }
  protocol_buffer_synchronize(); // Ensure light turns on when specified in program.
  bottom_light_set_state(mode);
}
