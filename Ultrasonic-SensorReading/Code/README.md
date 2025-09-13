# Ultrasonic Sensor Demo – Arduino Nano v3

This project demonstrates how to measure object proximity using an HC-SR04 ultrasonic sensor and display the distance on a 0.96" I2C OLED screen. Built with Arduino Nano v3, the system is designed for educational use, sensor calibration practice, and reproducible documentation.

---

## 🧩 Features

- Measures distance using HC-SR04 (up to ~400 cm)
- Displays real-time distance on OLED I2C 128x64 screen (in cm)
- Includes distance and error message handling
- Structured modular code for easy reuse

---

## 📦 Components Used

| Component              | Description                          |
|------------------------|--------------------------------------|
| Arduino Nano v3        | Microcontroller board                |
| HC-SR04                | Ultrasonic distance sensor           |
| OLED 0.96" I2C 128x64  | Display module for sensor output     |
| Breadboard + wires     | For prototyping and connections      |

---

## 🔌 Wiring Overview

### OLED I2C Display

| OLED Pin | Arduino Nano v3 Pin |
|----------|---------------------|
| VCC      | 5V                  |
| GND      | GND                 |
| SDA      | A4                  |
| SCL      | A5                  |

### HC-SR04 Sensor

| HC-SR04 Pin | Arduino Nano v3 Pin |
|-------------|---------------------|
| VCC         | 5V                  |
| TRIG        | D3                  |
| ECHO        | D4                  |
| GND         | GND                 |

See `Hardware/Wiring_diagram.png` for visual reference.



