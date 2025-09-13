# DHT22 Sensor Demo – Arduino Nano v3

This project demonstrates how to read temperature and humidity data from a DHT22 sensor and display it on a 0.96" I2C OLED screen using an Arduino Nano v3. It is designed for educational use, sensor calibration practice, and reproducible documentation.

---

## 🧩 Features

- Reads temperature and humidity from DHT22
- Displays real-time data on OLED 128x64 I2C screen
- Modular code structure for easy reuse and extension
- Includes calibration notes and troubleshooting guide

---

## 📦 Components Used

| Component             | Description                          |
|-----------------------|--------------------------------------|
| Arduino Nano v3       | Microcontroller board                |
| DHT22                 | Temperature and humidity sensor      |
| OLED 0.96" I2C 128x64 | Display module for sensor output     |
| Breadboard + wires    | For prototyping and connections      |

---

## 🔌 Wiring Overview

| OLED Pin | Arduino Nano v3 Pin |
|----------|---------------------|
| VCC      | 5V                  |
| GND      | GND                 |
| SDA      | A4                  |
| SCL      | A5                  |

| DHT22 Pin | Arduino Nano v3 Pin |
|-----------|---------------------|
| VCC       | 5V                  |
| DATA      | D2                  |
| GND       | GND                 |

See `Hardware/Wiring_diagram.png` for visual reference.

