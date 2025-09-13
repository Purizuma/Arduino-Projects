# 📏 Calibration Notes – DHT22 Sensor

This guide provides practical steps to validate and calibrate the DHT22 sensor used in the Arduino Nano v3 demo project. While the DHT22 is factory-calibrated, environmental factors and sensor placement can affect accuracy. These notes help ensure consistent and reliable readings.

---

## 🌡️ 1. Understanding DHT22 Accuracy

- **Temperature Accuracy**: ±0.5°C (typical)
- **Humidity Accuracy**: ±2–5% RH
- **Sampling Rate**: ~0.5 Hz (1 reading every 2 seconds)
- **Operating Range**:
  - Temperature: -40°C to +80°C
  - Humidity: 0–100% RH

---

## 🧪 2. Calibration Environment Setup

To minimize error during calibration:

- Place the sensor in a **stable indoor environment** (no direct sunlight or airflow).
- Avoid proximity to heat sources, windows, or human breath.
- Use a **reference thermometer and hygrometer** for comparison (preferably digital and recently calibrated).

---

## 🔍 3. Validation Procedure

1. **Power up the system** and wait 2–3 minutes for the sensor to stabilize.
2. **Record readings** from the DHT22 and your reference instruments every 30 seconds for 5–10 minutes.
3. **Compare values** and calculate average deviation:
   - ΔT = DHT22_Temp − Reference_Temp
   - ΔH = DHT22_Humidity − Reference_Humidity
4. If deviation is consistent, apply a **software offset** in your Arduino code:
   ```cpp
   float correctedTemp = dht.readTemperature() + tempOffset;
   float correctedHumidity = dht.readHumidity() + humidityOffset;
