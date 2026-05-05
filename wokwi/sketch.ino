// ============================================
// AIoT PdM Semiconductor — ESP32 + Blynk + ML Inference
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

// ML model and stored samples
#include "rf_secom_int16safe.h"
#include "secom_samples.h"

// Pin config
#define DHTPIN 4
#define DHTTYPE DHT22
#define RED_LED 18
#define GREEN_LED 19

// Wokwi WiFi
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// Sensor objects
Adafruit_MPU6050 mpu;
DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

// Threshold-based fault detection (sensor-side)
const float ACCEL_THRESHOLD = 15.0;
const float TEMP_THRESHOLD = 40.0;

// ML inference state
int current_sample_idx = 0;
const float MODEL_THRESHOLD = 0.19;  // optimal threshold from training

// Sensor data sender (existing functionality, every 2 sec)
void sendSensorData() {
  sensors_event_t a, g, temp_mpu;
  mpu.getEvent(&a, &g, &temp_mpu);
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT22 read failed");
    return;
  }
  
  float total_accel = sqrt(a.acceleration.x * a.acceleration.x +
                           a.acceleration.y * a.acceleration.y +
                           a.acceleration.z * a.acceleration.z);
  
  bool fault = (total_accel > ACCEL_THRESHOLD) || (temperature > TEMP_THRESHOLD);
  int fault_status = fault ? 1 : 0;
  
  // Send sensor data to Blynk
  Blynk.virtualWrite(V0, a.acceleration.x);
  Blynk.virtualWrite(V1, a.acceleration.y);
  Blynk.virtualWrite(V2, a.acceleration.z);
  Blynk.virtualWrite(V3, temperature);
  Blynk.virtualWrite(V4, humidity);
  Blynk.virtualWrite(V5, fault_status);
  
  // LED indicator (sensor-side fault)
  if (fault) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  } else {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }
}

// ML inference cycle (every 5 sec, runs on stored SECOM samples)
void runMLInference() {
  Serial.println();
  Serial.print("=== ML Inference: ");
  Serial.print(SAMPLE_NAMES[current_sample_idx]);
  Serial.println(" ===");
  
  const int16_t* sample = SAMPLES[current_sample_idx];
  int actual_label = SAMPLE_LABELS[current_sample_idx];
  
  // Get probabilities from model (proba-based, allows custom threshold)
  float probabilities[2];  // [prob_pass, prob_fail]
  rf_secom_i16_predict_proba(sample, N_FEATURES, probabilities, 2);
  
  float prob_pass = probabilities[0];
  float prob_fail = probabilities[1];
  
  // Apply our optimal threshold from training
  int prediction = (prob_fail >= MODEL_THRESHOLD) ? 1 : 0;
  
  // Detailed serial output
  Serial.print("Probabilities -> Pass: ");
  Serial.print(prob_pass, 4);
  Serial.print(" | Fail: ");
  Serial.println(prob_fail, 4);
  Serial.print("Threshold: ");
  Serial.print(MODEL_THRESHOLD);
  Serial.print(" | Predicted: ");
  Serial.print(prediction);
  Serial.print(" | Actual: ");
  Serial.println(actual_label);
  
  bool correct = (prediction == actual_label);
  Serial.print("Match: ");
  Serial.println(correct ? "YES ✓" : "NO ✗");
  
  // Send to Blynk
  Blynk.virtualWrite(V6, prediction);
  Blynk.virtualWrite(V7, actual_label);
  Blynk.virtualWrite(V8, current_sample_idx);
  Blynk.virtualWrite(V9, correct ? 1 : 0);
  
  // Cycle to next sample
  current_sample_idx = (current_sample_idx + 1) % NUM_SAMPLES;
}
void setup() {
  Serial.begin(115200);
  delay(500);
  
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  
  // Initialize sensors
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1) delay(10);
  }
  Serial.println("MPU6050 ready");
  
  dht.begin();
  delay(2000);
  Serial.println("DHT22 ready");
  
  // Connect to Blynk
  Serial.println("Connecting to Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // Schedule both tasks
  timer.setInterval(2000L, sendSensorData);
  timer.setInterval(5000L, runMLInference);
  
  Serial.println("=== System ready ===");
  Serial.print("Stored ML samples: ");
  Serial.println(NUM_SAMPLES);
  Serial.print("Model threshold: ");
  Serial.println(MODEL_THRESHOLD);
}
void loop() {
  Blynk.run();
  timer.run();
}