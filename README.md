# 3-Phase and 1-Phase Under and Over Voltage Protection

## Description
This project implements a voltage protection system using Arduino to monitor and protect against under and overvoltage conditions in 3-phase and 1-phase power systems. The system allows users to set the operating mode (1-phase or 3-phase) and configure upper and lower voltage limits. It incorporates advanced features such as phase fault detection, which identifies variations in voltage between any two or three phases. The project utilizes Arduino Uno, ZMPT101B voltage sensor, 16x2 LCD display, potentiometer, relays, voltage regulator, and other components.

## Features
- Voltage Protection: Monitors the voltage levels in 3-phase and 1-phase power systems to protect against under and overvoltage conditions.
- Operating Modes: Users can select between 1-phase and 3-phase operating modes.
- Voltage Limits: Configurable upper and lower voltage limits allow users to set appropriate thresholds for protection.
- Phase Fault Detection: Identifies phase faults by comparing voltage variations between any two or three phases.
- Real-time Display: Shows relevant information such as voltage readings, operating mode, and fault status on a 16x2 LCD display.

## Hardware Requirements
- Arduino Uno or compatible board
- ZMPT101B voltage sensor module
- 16x2 LCD display
- Potentiometer (for adjusting settings)
- Relays (for controlling external devices or alarms)
- Voltage regulator (if necessary)
- Connecting wires
- Power supply

## Software Requirements
- Arduino IDE (Integrated Development Environment)
- Libraries for LCD display (e.g., LiquidCrystal library)

## Installation and Setup
1. Clone the repository to your local machine using the following command: git clone https://github.com/rezaul-rimon/3-Phase-Over-Under-Voltage-Protection.git
Replace `your-username` with your GitHub username and `voltage-protection` with the name of the repository.

2. Connect the ZMPT101B voltage sensor, LCD display, potentiometer, and relays to the Arduino Uno according to the provided schematic or pin connections in the code.

3. Open the Arduino IDE.

4. Open the Arduino sketch (.ino file) for the voltage protection system.

5. Install any required libraries, such as the LiquidCrystal library for the LCD display.

6. Upload the sketch to the Arduino board.

7. Power on the system and ensure all connections are properly made.

8. Calibrate the system if necessary by adjusting the potentiometer to match the desired voltage readings.

## Usage
1. Power on the system and select the operating mode using the potentiometer or a dedicated switch (if available).

2. Set the upper and lower voltage limits using the potentiometer or buttons (if available) on the system.

3. The system will continuously monitor the voltage levels and compare them against the configured limits.

4. If an under or overvoltage condition is detected, the system will trigger the appropriate relay(s) to activate alarms, disconnect external devices, or perform any other desired action.

5. The LCD display will provide real-time information such as voltage readings, operating mode, and fault status.

6. Use the potentiometer or buttons to adjust settings as needed.

## Contributing
Contributions to this project are welcome! If you have any suggestions, improvements, or encounter any issues, feel free to open an issue or submit a pull request.

