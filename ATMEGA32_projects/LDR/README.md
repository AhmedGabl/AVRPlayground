# Light Sensing and Room Temperature Adaptation

## Description
This project is designed to sense light using an LDR (Light Dependent Resistor), display the intensity on an LCD, and adapt room temperature using a PWM-controlled LED.

## Features
- Threshold configuration for LDR using a keypad input.
- Read LDR values using ADC (Analog-to-Digital Converter).
- Display the light percentage on an LCD.
- Adjust LED brightness using PWM based on the light intensity.

## Setup
### Hardware Requirements
- Microcontroller (model and specifications)
- LDR Sensor
- Keypad
- LCD Display
- LED (for PWM control)
- Necessary connecting wires

### Software Requirements
- C/C++ Compiler compatible with the microcontroller
- Required libraries and drivers for the peripherals (provided in the project folders)

## Implementation

### Hardware Connections
- LDR Sensor: Connect to ADC Channel 0.
- Keypad: Used to set LDR threshold.
- LCD Display: To show LDR threshold and light intensity.
- LED: Controlled by PWM to adjust room temperature.

### Software Implementation
- Initialization of necessary GPIO pins and modules.
- Configuration and setup of ADC, LCD, Keypad, and PWM.
- Keypad Input: Set LDR threshold through keypad input.
- Read LDR: ADC used to read LDR values.
- Light Percentage Display: Map ADC readings to a percentage displayed on the LCD.
- PWM Control: Adjust LED brightness based on light intensity.

## Usage
1. Upon starting the program, input the LDR threshold using the keypad.
2. View the LDR threshold on the LCD.
3. The program continuously senses light, displaying the LDR value on the LCD.
4. LED brightness changes according to the light intensity, affecting room temperature.

## Libraries and Resources Used

### Libraries
- **MCAL/DIO/DIO_interface.h:** Used for Digital I/O functionality.
- **MCAL/PORT/PORT.h:** Utilized for port initialization and configurations.
- **MCAL/PORT/PORT_cnf.h:** Configuration header for ports.
- **MCAL/TIMERS/TIMER0/includes/TMR0_interface.h:** Timer library for Timer0 functionalities.
- **MCAL/ADC/includes/ADC_interface.h:** ADC library for analog-to-digital conversion.

### External Components
- **HAL/LCD/LCD.h:** Library used for interfacing with the LCD display.
- **HAL/KEYPAD/KP_interface.h:** Library handling the keypad inputs.

The project extensively utilized these libraries and resources for handling peripheral interfaces, setting up components, and facilitating functionalities within the microcontroller environment.

## Credits
- **Author:** Ahmed Abogabl

## Acknowledgments

The development of this project utilized the following libraries and resources:

### Libraries
- **MCAL/DIO/DIO_interface.h:** Used for Digital I/O functionality.
- **MCAL/PORT/PORT.h:** Utilized for port initialization and configurations.
- **MCAL/PORT/PORT_cnf.h:** Configuration header for ports.
- **MCAL/TIMERS/TIMER0/includes/TMR0_interface.h:** Timer library for Timer0 functionalities.
- **MCAL/ADC/includes/ADC_interface.h:** ADC library for analog-to-digital conversion.

### External Components
- **HAL/LCD/LCD.h:** Library used for interfacing with the LCD display.
- **HAL/KEYPAD/KP_interface.h:** Library handling the keypad inputs.

The project extensively utilized these libraries and resources for handling peripheral interfaces, setting up components, and facilitating functionalities within the microcontroller environment.
