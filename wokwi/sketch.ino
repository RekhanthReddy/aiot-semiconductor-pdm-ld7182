// ============================================
// AIoT PdM Semiconductor — ESP32 + Blynk
// LD7182 — Rekhanth Reddy Obireddy
// ============================================

#define BLYNK_TEMPLATE_ID   "TMPL5A8UVc2sA"
#define BLYNK_TEMPLATE_NAME "AIoT PdM Semiconductor"
#define BLYNK_AUTH_TOKEN    "YOUR_AUTH_TOKEN_HERE" 

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <math.h>

// Pin config (matches your existing wiring)
#define DHTPIN 4
#define DHTTYPE DHT22
#define RED_LED 18
#define GREEN_LED 19

// Wokwi WiFi (no real password needed for simulator)
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// Sensor objects
Adafruit_MPU6050 mpu;
DHT dht(DHTPIN, DHTTYPE);

// Blynk timer for periodic data sending
BlynkTimer timer;

// Fault detection thresholds
const float ACCEL_THRESHOLD = 15.0;  // total acceleration m/s²
const float TEMP_THRESHOLD = 40.0;   // °C

void sendSensorData() {
  // Read MPU6050
  sensors_event_t a, g, temp_mpu;
  mpu.getEvent(&a, &g, &temp_mpu);
  
  // Read DHT22
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  // Handle DHT NaN safely
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT22 read failed, using last good values");
    return;
  }
  
  // Calculate total acceleration magnitude
  float total_accel = sqrt(a.acceleration.x * a.acceleration.x +
                           a.acceleration.y * a.acceleration.y +
                           a.acceleration.z * a.acceleration.z);
  
  // Threshold-based fault detection (placeholder for ML model)
  bool fault = (total_accel > ACCEL_THRESHOLD) || (temperature > TEMP_THRESHOLD);
  int fault_status = fault ? 1 : 0;
  
  // Send to Blynk dashboard
  Blynk.virtualWrite(V0, a.acceleration.x);
  Blynk.virtualWrite(V1, a.acceleration.y);
  Blynk.virtualWrite(V2, a.acceleration.z);
  Blynk.virtualWrite(V3, temperature);
  Blynk.virtualWrite(V4, humidity);
  Blynk.virtualWrite(V5, fault_status);
  
  // Local LED + serial output
  if (fault) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    Serial.println(">>> FAULT DETECTED <<<");
  } else {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }
  
  // Serial debug
  Serial.print("Accel: ");
  Serial.print(a.acceleration.x); Serial.print(", ");
  Serial.print(a.acceleration.y); Serial.print(", ");
  Serial.print(a.acceleration.z);
  Serial.print(" | Temp: "); Serial.print(temperature);
  Serial.print(" | Humid: "); Serial.print(humidity);
  Serial.print(" | Fault: "); Serial.println(fault_status);
}

void setup() {
  Serial.begin(115200);
  delay(500);
  
  // Initialize LEDs
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  
  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1) delay(10);
  }
  Serial.println("MPU6050 ready");
  
  // Initialize DHT22
  dht.begin();
  delay(2000);
  Serial.println("DHT22 ready");
  
  // Connect to Blynk via Wokwi WiFi
  Serial.println("Connecting to Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // Schedule sensor reads every 2 seconds
  timer.setInterval(2000L, sendSensorData);
  
  Serial.println("=== System ready ===");
}

void loop() {
  Blynk.run();
  timer.run();
}