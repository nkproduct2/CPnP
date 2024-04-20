/*
  adc.h - spindle control methods
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

#ifndef adc_control_h
#define adc_control_h

#define ADC_NO_SYNC     false
#define ADC_FORCE_SYNC  true

#define ADC_STATE_ENABLE   1
#define ADC_STATE_DISABLE  0  // Must be zero
#define ADC_STATE     bit(0)


// Initializes adc control pins.
void adc_init();

// Returns current adc input state. Overrides may alter it from programmed state.
uint8_t adc_get_state();

// Read the vaccum value.
uint16_t read_adc();

// Sets the adc pins according to state specified.
void adc_set_state(uint8_t mode);

// G-code parser entry-point for setting adc states. Checks for and executes additional conditions.
void adc_sync(uint8_t mode);

#endif
