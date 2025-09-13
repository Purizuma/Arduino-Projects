#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// === OLED Configuration ===
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// === HC-SR04 Configuration ===
#define TRIG_PIN 3
#define ECHO_PIN 4

// === Setup ===
void setup() {
  Serial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED initialization failed"));
    while (true); // Halt if OLED not found
  }

  // Initialize ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Splash screen
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Ultrasonic Demo");
  display.println("Initializing...");
  display.display();
  delay(2000);
}

// === Main Loop ===
void loop() {
  long duration;
  float distance;

  // Trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo time
  duration = pulseIn(ECHO_PIN, HIGH, 30000); // Timeout after 30ms

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Display result
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("Ultrasonic Sensor");
  display.setCursor(0, 16);

  if (duration == 0) {
    display.println("No object detected");
    Serial.println("No echo received");
  } else {
    display.print("Distance: ");
    display.print(distance);
    display.println(" cm");
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  display.display();
  delay(500); // Refresh rate
}
