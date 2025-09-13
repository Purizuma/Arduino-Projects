# 📏 Calibration Notes – HC-SR04 Ultrasonic Sensor

This guide provides practical steps to validate and calibrate the HC-SR04 ultrasonic sensor used in the Arduino Nano v3 demo project. While the sensor offers reasonable accuracy out of the box, environmental factors and signal timing can affect reliability. These notes help ensure consistent and reproducible distance measurements.

---

## 📐 1. Sensor Specifications

| Parameter        | Value                      |
|------------------|----------------------------|
| Range            | 2 cm to 400 cm             |
| Accuracy         | ±3 mm                      |
| Resolution       | ~0.3 cm                    |
| Operating Voltage| 5V                         |
| Trigger Pulse    | ≥10 µs                     |
| Echo Timeout     | ~38 ms (max range)         |

---

## 🧪 2. Calibration Environment Setup

To minimize measurement error:

- Place the sensor on a **stable surface** facing a flat, hard object (e.g., wall or book).
- Avoid soft or absorbent targets (e.g., fabric, foam).
- Ensure **no ambient noise or airflow** interferes with the signal.
- Use a **measuring tape** or laser rangefinder as a reference.

---

## 🔍 3. Validation Procedure

1. **Position the sensor** at known distances (e.g., 10 cm, 50 cm, 100 cm).
2. **Record readings** from the OLED and Serial Monitor.
3. **Compare actual vs. measured values**:
   - Δ = Measured − Actual
4. Repeat for multiple distances and calculate average deviation.

---

## 🧰 4. Optional Software Offset

If consistent deviation is observed, apply a correction factor in code:

```cpp
float distance = measureDistance();
float correctedDistance = distance + offset; // e.g., offset = -1.5
```
Define the offset based on your validation results:

```cpp
const float offset = -1.5; // Sensor reads 1.5 cm too far
```
---

## 📎 5. Notes on Reliability

- HC-SR04 performs best with flat, perpendicular surfaces.
- Avoid measuring through transparent or absorbent materials.
- For high-precision applications, consider averaging multiple readings.

