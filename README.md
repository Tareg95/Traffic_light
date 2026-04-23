# Traffic_light

STM32 Traffic Light Controller (IS1300 Project)
📌 Overview

This project implements a traffic light control system using the STM32 Nucleo-L476RG development board and a Traffic Light Shield.

The system simulates a real-world intersection with:

🚗 Car traffic from multiple directions
🚶 Pedestrian crossings with button input
⏱️ Timed signal transitions
⚡ Real-time behavior and synchronization

The project was developed as part of the IS1300 Embedded Systems course at KTH.

🧠 System Description

The system controls a full traffic intersection using embedded software logic. It handles:

Traffic light state transitions (Red → Orange → Green)
Pedestrian crossing requests via button input
Safe coordination between cars and pedestrians
Timing constraints for realistic traffic behavior

The implementation is modular, allowing separate handling of:

Pedestrian crossings
Vehicle traffic
Full system integration
⚙️ Features

Depending on implementation level, the system includes:

🚶 Pedestrian Crossing Logic
Button-triggered crossing requests
Blinking indicator before crossing
Delay before switching traffic lights
Fixed walking duration
🚗 Vehicle Traffic Logic
Multiple directions with no collision paths
Smart switching based on active cars
Automatic cycling when no cars are present
Delay handling for waiting vehicles
🔗 Full System Integration
Combines pedestrian and vehicle systems
Ensures only one crossing is active at a time
Synchronizes all traffic signals
💡 (Optional Features)
SPI communication for shift registers
OLED display showing timing values
LED brightness control via potentiometer
🏗️ Hardware
STM32 Nucleo-L476RG
Traffic Light Shield
USB interface (power + communication)
🛠️ Technologies Used
Embedded C
STM32 HAL / Low-level drivers
GPIO, Timers
(Optional) SPI communication
(Optional) FreeRTOS
🧩 How It Works (High-Level)
System initializes with default traffic state
Inputs (buttons/switches) simulate pedestrians and cars
Control logic decides safe transitions
Timers enforce delays (e.g., walking time, signal delay)
Outputs update LEDs representing traffic lights
▶️ How to Run
Flash the code to the STM32 board
Connect the Traffic Light Shield
Power via USB
Use switches/buttons to simulate traffic and pedestrians
📚 Learning Outcomes

This project demonstrates:

Embedded system design
Real-time event handling
State machine implementation
Hardware-software integration
Modular system architecture
