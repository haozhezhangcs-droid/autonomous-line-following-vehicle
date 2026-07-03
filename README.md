# autonomous-line-following-vehicle
## Overview
This project is an embedded autonomous line-following vehicle developed using an MSP430 microcontroller. The system uses infrared sensors to detect the track, motor control to adjust movement, and an OLED display for system feedback.

## Features
- Infrared sensor-based line detection
- DC motor control
- Timer interrupt control
- OLED display
- Embedded C firmware
- Closed-loop control for stable tracking

## Hardware
- MSP430F5529
- Infrared sensors
- DC motors
- OLED display
- Motor driver module

## Software
- Code Composer Studio
- Embedded C

## Project Structure
- `main.c` — Main control logic
- `Motor.c / Motor.h` — Motor control
- `sensor.c / sensor.h` — Sensor processing
- `Infrared_Sensor.c / Infrared_Sensor.h` — Infrared tracking module
- `TimeB0.c / TimeB0.h` — Timer configuration
- `OLED.c / OLED.h` — OLED display driver

## Author
Haozhe Zhang
