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

void adc_init()
{
    // Select Vref=AVcc
    ADMUX |= (1<<REFS0);
	
    //set prescaller to 128 and enable ADC 
    ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
    #ifdef BOARD_REV6
	ADCSRB &= ~(1<<MUX5); 	//ebable ADC 0-7
	#else
	ADCSRB |= (1<<MUX5);	//enable ADC 8-15
	#endif
}

uint16_t read_adc()
{
	 if (sys.abort) {
    return;  // Block during abort.
	 }else {
    	//select ADC channel with safety mask A15
    	ADMUX = (ADMUX & 0xF0) | (CONTROL_ADC_BIT & 0x0F);
    	//single conversion mode
    	ADCSRA |= (1<<ADSC);
    	// wait until ADC conversion is complete
    	while( ADCSRA & (1<<ADSC) );
	return (ADC);
	}
}

uint8_t adc_get_state()
{
  uint8_t vcm_state = ADC_STATE_DISABLE;
  return (vcm_state);
}

// Main program only. Immediately sets feeder state,
// if enabled. Also sets a flag to report an update to a feeder state.
// Called by coolant toggle override, parking restore, parking retract, sleep mode, g-code
// parser program end, and g-code parser coolant_sync().
void adc_set_state(uint8_t mode)
{
  if (sys.abort) {
    return;  // Block during abort.
  }
  if (mode == ADC_ENABLE) {
  	report_vacuum_message(read_adc());
  }
}

// G-code parser entry-point for setting feeder state. Forces a planner buffer sync and bails
// if an abort or check-mode is active.
void adc_sync(uint8_t mode)
{
  if (sys.state == STATE_CHECK_MODE) {
    return;
  }
  protocol_buffer_synchronize(); // Ensure vacuum turns on when specified in program.
  adc_set_state(mode);
}
