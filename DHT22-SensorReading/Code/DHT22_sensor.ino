#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>

// === OLED Configuration ===
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // OLED reset pin not used
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// === DHT22 Configuration ===
#define DHTPIN 2          // Digital pin connected to DHT22
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// === Setup ===
void setup() {
  Serial.begin(9600);
  dht.begin();

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED initialization failed. Check wiring."));
    while (true); // Halt execution
  }

  // Display splash screen
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("DHT22 Sensor Demo");
  display.println("Initializing...");
  display.display();
  delay(2000);
}

// === Main Loop ===
void loop() {
  float temperature = dht.readTemperature(); // Celsius
  float humidity = dht.readHumidity();

  // Validate sensor readings
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println(F("Sensor read failed. Check DHT22 connection."));
    showErrorMessage();
    delay(2000);
    return;
  }

  // Print to Serial Monitor
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.print(F(" °C | Humidity: "));
  Serial.print(humidity);
  Serial.println(F(" %"));

  // Display on OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("DHT22 Sensor Demo");
  display.setCursor(0, 16);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" °C");
  display.setCursor(0, 32);
  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");
  display.display();

  delay(2000); // Wait before next reading
}

// === Error Display Function ===
void showErrorMessage() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("Sensor Error!");
  display.println("Check wiring or sensor.");
  display.display();
}
