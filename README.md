IoT Alcohol Detection Engine Locking System

This is an Arduino-based IoT project that detects alcohol using an MQ3 sensor. When alcohol is detected, the system activates a buzzer, displays a warning on the LCD, and locks the engine to prevent the vehicle from starting — helping to enhance road safety.

Components Used:
Arduino UNO
MQ3 Gas Sensor
LCD Display
Buzzer
Motor
Jumper Wires
Breadboard
Software:
Arduino IDE
Programming Language: C/C++

Features:
Real-time alcohol detection
Engine control based on sensor input
Visual and audible alerts

How It Works:
1. The MQ3 sensor checks for alcohol in the driver's breath.
2. If detected above the threshold:
LCD shows a warning.
Buzzer sounds an alert.
Motor (engine) remains off.
3. If no alcohol is detected, the engine runs normally.
