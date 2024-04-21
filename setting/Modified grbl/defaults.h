/*
  defaults.h - defaults settings configuration file
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

/* The defaults.h file serves as a central default settings selector for different machine
   types, from DIY CNC mills to CNC conversions of off-the-shelf machines. The settings 
   files listed here are supplied by users, so your results may vary. However, this should
   give you a good starting point as you get to know your machine and tweak the settings for
   your nefarious needs.
   NOTE: Ensure one and only one of these DEFAULTS_XXX values is defined in config.h */

#ifndef defaults_h

#ifdef DEFAULTS_GENERIC
  // Grbl generic default settings. Should work across different machines.
  #define DEFAULT_X_STEPS_PER_MM 250.0
  #define DEFAULT_Y_STEPS_PER_MM 250.0
  #define DEFAULT_Z_STEPS_PER_MM 250.0
  #define DEFAULT_X_MAX_RATE 500.0 // mm/min
  #define DEFAULT_Y_MAX_RATE 500.0 // mm/min
  #define DEFAULT_Z_MAX_RATE 500.0 // mm/min
  #define DEFAULT_X_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_Y_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_Z_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_X_MAX_TRAVEL 200.0 // mm
  #define DEFAULT_Y_MAX_TRAVEL 200.0 // mm
  #define DEFAULT_Z_MAX_TRAVEL 200.0 // mm
  #define DEFAULT_SPINDLE_RPM_MAX 1000.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK 0
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 25 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.01 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 0 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 25.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 500.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 50 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm
#endif

#ifdef DEFAULTS_ABC_AXIS
  #define DEFAULT_A_STEPS_PER_MM 250.0
  #define DEFAULT_A_MAX_RATE 500.0 // mm/min
  #define DEFAULT_A_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_A_MAX_TRAVEL 200.0 // mm

  #define DEFAULT_B_STEPS_PER_MM 250.0
  #define DEFAULT_B_MAX_RATE 500.0 // mm/min
  #define DEFAULT_B_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_B_MAX_TRAVEL 200.0 // mm

  #define DEFAULT_C_STEPS_PER_MM 250.0
  #define DEFAULT_C_MAX_RATE 500.0 // mm/min
  #define DEFAULT_C_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_C_MAX_TRAVEL 200.0 // mm
#endif

#ifdef DEFAULTS_COMPACTPNP
  // Grbl generic default settings. Should work across different machines.
  #define DEFAULT_X_STEPS_PER_MM 40.0 // $100
  #define DEFAULT_Y_STEPS_PER_MM 40.0 // $101
  #define DEFAULT_Z_STEPS_PER_MM 50.0 // $102
  #define DEFAULT_X_MAX_RATE 20000.0 // mm/min $110
  #define DEFAULT_Y_MAX_RATE 20000.0 // mm/min $111
  #define DEFAULT_Z_MAX_RATE 15000.0 // mm/min $112
  #define DEFAULT_X_ACCELERATION (1500.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2 $120
  #define DEFAULT_Y_ACCELERATION (1500.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2 $121
  #define DEFAULT_Z_ACCELERATION (1000.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2 $122
  #define DEFAULT_X_MAX_TRAVEL 145.0 // mm $130
  #define DEFAULT_Y_MAX_TRAVEL 200.0 // mm $131
  #define DEFAULT_Z_MAX_TRAVEL 40.0 // mm  $132
  #define DEFAULT_SPINDLE_RPM_MAX 1000.0 // rpm $30
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm $31
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10 // $0
  #define DEFAULT_STEPPING_INVERT_MASK 0  // $2
  #define DEFAULT_DIRECTION_INVERT_MASK 0 // $3
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 0 // msec (0-254, 255 keeps steppers enabled) $1
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled $10
  #define DEFAULT_JUNCTION_DEVIATION 0.01 // mm $11
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm $12
  #define DEFAULT_REPORT_INCHES 0 // false $13
  #define DEFAULT_INVERT_ST_ENABLE 0 // false $
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false $5
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false $20
  #define DEFAULT_HARD_LIMIT_ENABLE 1  // false $21
  #define DEFAULT_INVERT_PROBE_PIN 0 // false $6
  #define DEFAULT_LASER_MODE 1 // false $32
  #define DEFAULT_HOMING_ENABLE 1  // false $22
  #define DEFAULT_HOMING_DIR_MASK 3 // move positive dir $23
  #define DEFAULT_HOMING_FEED_RATE 200.0 // mm/min $24
  #define DEFAULT_HOMING_SEEK_RATE 1500.0 // mm/min $25
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 50 // msec (0-65k) $26
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm $27
#endif

#ifdef DEFAULTS_ABC_AXIS_COMPACTPNP
  #define DEFAULT_A_STEPS_PER_MM 4.444 // $103
  #define DEFAULT_A_MAX_RATE 15000.0 // mm/min $113
  #define DEFAULT_A_ACCELERATION (1000.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2 $123
  #define DEFAULT_A_MAX_TRAVEL 360.0 // mm $133
  
  #define DEFAULT_B_STEPS_PER_MM 250.0
  #define DEFAULT_B_MAX_RATE 500.0 // mm/min
  #define DEFAULT_B_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_B_MAX_TRAVEL 200.0 // mm

  #define DEFAULT_C_STEPS_PER_MM 250.0
  #define DEFAULT_C_MAX_RATE 500.0 // mm/min
  #define DEFAULT_C_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_C_MAX_TRAVEL 200.0 // mm

#endif

#endif
