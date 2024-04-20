/*
  coolant_control.c - coolant control methods
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


void feeder_init()
{
  FEEDER_ONE_DDR   |= (1 << FEEDER_ONE_BIT); // Configure as output pin.
  FEEDER_TWO_DDR   |= (1 << FEEDER_TWO_BIT); // Configure as output pin.
  FEEDER_THREE_DDR |= (1 << FEEDER_THREE_BIT); // Configure as output pin.
  FEEDER_FOUR_DDR  |= (1 << FEEDER_FOUR_BIT); // Configure as output pin.
  feeder_stop();
}

uint8_t feeder_get_state()
{
  uint8_t fdr_state = FEEDER_STATE_DISABLE;
  
   #ifdef INVERT_FEEDER_PIN 
    if (bit_isfalse(FEEDER_ONE_PORT,(1 << FEEDER_ONE_BIT))) {
   #else
    if (bit_istrue(FEEDER_ONE_PORT,(1 << FEEDER_ONE_BIT))) {
   #endif
    fdr_state |= FEEDER_STATE_ONE;
  	}
   #ifdef INVERT_FEEDER_PIN 
    else if (bit_isfalse(FEEDER_TWO_PORT,(1 << FEEDER_TWO_BIT))) {
   #else
    else if (bit_istrue(FEEDER_TWO_PORT,(1 << FEEDER_TWO_BIT))) {
   #endif
    fdr_state |= FEEDER_STATE_TWO;

  	}
   #ifdef INVERT_FEEDER_PIN 
    else if (bit_isfalse(FEEDER_THREE_PORT,(1 << FEEDER_THREE_BIT))) {
   #else
    else if (bit_istrue(FEEDER_THREE_PORT,(1 << FEEDER_THREE_BIT))) {
   #endif
    fdr_state |= FEEDER_STATE_THREE;
  	}
   #ifdef INVERT_FEEDER_PIN 
    else if (bit_isfalse(FEEDER_FOUR_PORT,(1 << FEEDER_FOUR_BIT))) {
   #else
    else if (bit_istrue(FEEDER_FOUR_PORT,(1 << FEEDER_FOUR_BIT))) {
   #endif
    fdr_state |= FEEDER_STATE_FOUR;
	}
  return (fdr_state);
}

// Main program only. Immediately sets feeder state,
// if enabled. Also sets a flag to report an update to a feeder state.
// Called by coolant toggle override, parking restore, parking retract, sleep mode, g-code
// parser program end, and g-code parser coolant_sync().
void feeder_set_state(uint8_t mode)
{
  if (sys.abort) {
    return;  // Block during abort.
  }
  if (mode == FEEDER_DISABLE) {
    feeder_stop();
  }
  else {
  	if (mode == FEEDER_ONE_CHANGE) {
    	#ifdef INVERT_FEEDER_PIN 
        	FEEDER_ONE_PORT &= ~(1 << FEEDER_ONE_BIT);
     	#else
     		FEEDER_ONE_PORT |= (1 << FEEDER_ONE_BIT);
     	#endif
    }
    else if (mode == FEEDER_TWO_CHANGE) {
    	#ifdef INVERT_FEEDER_PIN 
    		FEEDER_TWO_PORT &= ~(1 << FEEDER_TWO_BIT);
    	#else
    		FEEDER_TWO_PORT |= (1 << FEEDER_TWO_BIT);
    	#endif
    }
    else if ( mode == FEEDER_THREE_CHANGE) {
    	#ifdef INVERT_FEEDER_PIN 
    		FEEDER_THREE_PORT &= ~(1 << FEEDER_THREE_BIT);
    	#else
    		FEEDER_THREE_PORT |= (1 << FEEDER_THREE_BIT);
    	#endif
    }
    else if ( mode == FEEDER_FOUR_CHANGE) {
    	#ifdef INVERT_FEEDER_PIN
    		FEEDER_FOUR_PORT &= ~(1 << FEEDER_FOUR_BIT);
    	#else
      		FEEDER_FOUR_PORT |= (1 << FEEDER_FOUR_BIT);
    	#endif
    }
  }
}

void feeder_stop()
{
	#ifdef INVERT_FEEDER_PIN 
    	FEEDER_ONE_PORT |= (1 << FEEDER_ONE_BIT);
  	#else
		FEEDER_ONE_PORT &= ~(1 << FEEDER_ONE_BIT);
	#endif
	
	#ifdef INVERT_FEEDER_PIN
    	FEEDER_TWO_PORT |= (1 << FEEDER_TWO_BIT);
  	#else
		FEEDER_TWO_PORT &= ~(1 << FEEDER_TWO_BIT);
	#endif
	
	#ifdef INVERT_FEEDER_PIN
    	FEEDER_THREE_PORT |= (1 << FEEDER_THREE_BIT);
  	#else
		FEEDER_THREE_PORT &= ~(1 << FEEDER_THREE_BIT);
	#endif
	
	#ifdef INVERT_FEEDER_PIN
    	FEEDER_FOUR_PORT |= (1 << FEEDER_FOUR_BIT);
  	#else
		FEEDER_FOUR_PORT &= ~(1 << FEEDER_FOUR_BIT);
	#endif
		
}

// G-code parser entry-point for setting feeder state. Forces a planner buffer sync and bails
// if an abort or check-mode is active.
void feeder_sync(uint8_t mode)
{
  if (sys.state == STATE_CHECK_MODE) {
    return;
  }
  protocol_buffer_synchronize(); // Ensure feeder turns on when specified in program.
  feeder_set_state(mode);
}
