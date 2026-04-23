## 🧠 System Description

The system controls a full traffic intersection using embedded software logic. It handles:

- Traffic light state transitions (Red → Orange → Green)
- Pedestrian crossing requests via button input
- Safe coordination between cars and pedestrians
- Timing constraints for realistic traffic behavior

The implementation is modular, allowing separate handling of:

- 🚶 Pedestrian crossings  
- 🚗 Vehicle traffic  
- 🔗 Full system integration  

---

## ⚙️ Features

Depending on implementation level, the system includes:

### 🚶 Pedestrian Crossing Logic
- Button-triggered crossing requests  
- Blinking indicator before crossing  
- Delay before switching traffic lights  
- Fixed walking duration  

### 🚗 Vehicle Traffic Logic
- Multiple directions with no collision paths  
- Smart switching based on active cars  
- Automatic cycling when no cars are present  
- Delay handling for waiting vehicles  

### 🔗 Full System Integration
- Combines pedestrian and vehicle systems  
- Ensures only one crossing is active at a time  
- Synchronizes all traffic signals  

### 💡 Optional Features
- SPI communication for shift registers  
- OLED display showing timing values  
- LED brightness control via potentiometer  

---

## 🏗️ Hardware
- STM32 Nucleo-L476RG  
- Traffic Light Shield  
- USB interface (power + communication)  

---

## 🛠️ Technologies Used
- Embedded C  
- STM32 HAL / Low-level drivers  
- GPIO, Timers  
- (Optional) SPI communication  
- (Optional) FreeRTOS  

---

## 📁 Project Structure

- `Core/` → Application code (main logic, state machines)
- `Drivers/` → STM32 HAL drivers
- `Traffic_Light.ioc` → STM32CubeMX configuration
- `Debug/` → Build output files
- `.project / .cproject` → STM32CubeIDE project files

- ## 🧪 Setup & Build

1. Open the project in **STM32CubeIDE**
2. Connect the STM32 Nucleo-L476RG board via USB
3. Build the project
4. Flash to the board using ST-Link

Optional:
- Configure hardware using `Traffic_Light.ioc`
