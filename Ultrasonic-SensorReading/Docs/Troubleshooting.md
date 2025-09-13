# 🛠️ Troubleshooting Guide – Ultrasonic Sensor Demo

This guide outlines common issues encountered when working with the HC-SR04 ultrasonic sensor and OLED I2C display on the Arduino Nano v3. Each section includes symptoms, possible causes, and recommended solutions to ensure reproducibility and smooth operation.

---

## ⚡ 1. OLED Display Not Working

**Symptoms**: OLED screen remains blank or shows random pixels.

**Possible Causes**:
- Incorrect I2C address or wiring
- Missing or incompatible OLED library
- Power supply issue (OLED requires stable 3.3–5V)

**Solutions**:
- Confirm wiring: SDA → A4, SCL → A5
- Use the Adafruit SSD1306 and Adafruit GFX libraries
- Check OLED I2C address (default is `0x3C`)
- Ensure OLED is powered from the 5V pin

---

## 📡 2. HC-SR04 Sensor Returns 0 cm or No Reading

**Symptoms**: OLED or Serial Monitor shows 0 cm or “No object detected”

**Possible Causes**:
- Sensor not receiving power
- TRIG/ECHO pins miswired
- Object out of range or not reflective
- Timeout due to poor surface or angle

**Solutions**:
- Confirm wiring: TRIG → D3, ECHO → D4, VCC → 5V, GND → GND
- Use a flat, hard surface for testing (e.g., wall or book)
- Ensure object is within 2–400 cm range
- Add timeout handling in code (`pulseIn` with max duration)

---

## 🔄 3. Inconsistent or Fluctuating Distance Readings

**Symptoms**: Distance values jump erratically or drift over time

**Possible Causes**:
- Electrical noise or unstable power
- Sensor facing soft or angled surfaces
- No delay between readings

**Solutions**:
- Add `delay(500);` between readings
- Use averaging to smooth output:
  ```cpp
  float distance = 0;
  for (int i = 0; i < 5; i++) {
    distance += measureDistance();
    delay(50);
  }
  distance /= 5;
  ```
Avoid measuring through fabric, foam, or glass
  
## 🧼 4. Compilation Errors
  
Symptoms: Arduino IDE shows errors related to Adafruit_SSD1306 or display.begin()
Possible Causes:
- Missing libraries
- Incorrect object initialization
- Library version conflicts
Solutions:
- Install required libraries via Library Manager:
  - Adafruit SSD1306
  - Adafruit GFX
- Ensure correct object declaration:

```cpp
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
```


## ✅ Final Checklist

| Component    | Checkpoint                            |
| :---         | :---                                  |
| HC-SR04      | Proper TRIG/ECHO wiring, stable power |
| OLED Display | Correct I2C pins, valid address       |
| Code         | Sensor logic, display initialization  |
| Power Supply | 5V regulated, no voltage drops        |



