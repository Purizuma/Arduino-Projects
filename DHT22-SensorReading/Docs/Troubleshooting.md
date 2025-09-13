# 🛠️ Troubleshooting Guide – DHT22 Sensor Demo

This guide outlines common issues encountered when working with the DHT22 sensor and OLED display on the Arduino Nano v3. Each section includes symptoms, possible causes, and recommended solutions to ensure reproducibility and smooth operation.

---

## ⚡ 1. No Sensor Data Displayed

**Symptoms**: OLED screen is blank or shows static text; no temperature/humidity values appear.

**Possible Causes**:
- DHT22 not connected properly (loose jumper wires or incorrect pin)
- Incorrect data pin defined in code
- Missing or incompatible DHT library
- Sensor not initialized correctly in `setup()`

**Solutions**:
- Double-check wiring: VCC → 5V, GND → GND, DATA → digital pin (e.g., D2)
- Confirm `#define DHTPIN 2` matches your wiring
- Ensure `DHT.begin()` is called in `setup()`
- Use the official [Adafruit DHT sensor library](https://github.com/adafruit/DHT-sensor-library)

---

## 🧊 2. Sensor Reads 0.0°C or 0% RH Constantly

**Symptoms**: OLED or Serial Monitor shows zero values for both temperature and humidity.

**Possible Causes**:
- Sensor not receiving power
- Faulty sensor or damaged DATA line
- Incorrect sensor type defined in code

**Solutions**:
- Verify VCC is connected to 5V (not 3.3V)
- Check `#define DHTTYPE DHT22` is correctly set
- Replace jumper wires or test with a known-good DHT22
- Add a 10kΩ pull-up resistor between DATA and VCC (optional but recommended)

---

## 🔄 3. OLED Display Not Working

**Symptoms**: OLED screen remains off or shows random pixels.

**Possible Causes**:
- Incorrect I2C address or wiring
- Missing or incompatible OLED library
- Power supply issue (OLED needs stable 3.3–5V)

**Solutions**:
- Confirm SDA → A4 and SCL → A5 on Arduino Nano
- Use the [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) and [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library) libraries
- Try scanning I2C address using an I2C scanner sketch
- Ensure OLED is powered from 5V pin (not 3.3V)

---

## 🧪 4. Inconsistent or Fluctuating Readings

**Symptoms**: Temperature or humidity values jump erratically or drift over time.

**Possible Causes**:
- Sensor exposed to airflow, heat sources, or moisture
- Electrical noise from nearby components
- Insufficient delay between readings

**Solutions**:
- Place sensor in a stable, enclosed environment during testing
- Add `delay(2000);` between readings to match DHT22 sampling rate
- Use shielded cables or separate power rails if needed

---

## 🧼 5. Compilation Errors

**Symptoms**: Arduino IDE shows errors related to `DHT` or `Adafruit_SSD1306`.

**Possible Causes**:
- Missing libraries
- Library version conflicts
- Incorrect object initialization

**Solutions**:
- Install required libraries via Library Manager:
  - `DHT sensor library by Adafruit`
  - `Adafruit SSD1306`
  - `Adafruit GFX`
- Ensure correct object declarations:
  ```cpp
  DHT dht(DHTPIN, DHTTYPE);
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
