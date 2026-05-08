### 5.1 Hardware Setup in Wokwi

This
system is modeled physically using the Wokwi simulator; this simulates a
cycle-accurate version of the ESP32 DevKit V1, its peripheral interaction and
the relevant logic. The MPU6050 connects via I2C (GPIO 21/22), the DHT22 via a
digital pin (GPIO 4), and two status LEDs (red and green) on GPIO 18 and 19 for
local status indication. Wiring is in accordance with the wiring schematic set
out in Section 3.2. Cloud-based simulation provides a readily available and
repeatable testing platform for performing hardware-in-the-loop testing of the
AI inference engine quickly without requiring physical hardware access. This
also accurately simulates the timing and signal semantics that are needed for verification
of the end-to-end AIoT system.

### 5.2 Software Stack & Build Process

This
firmware was programmed using the Arduino framework where it utilizes the
Adafruit MPU6050, DHT, and Blynk libraries in order to interact with the
peripheral sensors and communicate to the cloud. The Arduino CLI was used to
compile firmware locally via VS Code (using the Wokwi VS Code extension),
rather than the Wokwi web cloud build service. The choice to compile locally
was made to avoid build queue backlogs and timeout issues with the large
firmware (the RF model alone exceeded 1.5 MB before the m2cgen pivot reduced
the model to 140 KB). The total binary is roughly 77% of the ESP32’s total
flash memory, which is a slight decrease from the 81% with the Random Forest
baseline model. WiFi credentials and Blynk authentication token are defined as
preprocessor macros at the top of the sketch file.

### 5.3 ML Inference Deployment

After
validation, the XGBoost model is converted into a standalone C function using
m2cgen and placed into `xgb_model.h` The resulting function is called `score(double *input, double *output)`and 

takes a 100 double feature array and returns a two-element
output vector, where each element contains the probability of a state being
either "pass" or "fail." Since the physical sensors cannot
produce SECOM-domain features (Section 3.4), five example samples are hardcoded
into `secom_samples_xgb.h`. This allows for testing the inference engine without
using the actual sensor streams. Inference is invoked every 5 seconds via a
BlynkTimer task; the optimal classification threshold of 0.07 (from training,
see Section 4) is applied to the model output to determine the predicted class.
When the failure probability crosses the threshold, the local LEDs and Blynk
dashboard widgets are updated to reflect the predicted state.

### 5.4 Cloud Dashboard

An
interactive interface allows users to observe sensor data in real-time via the
Blynk IoT platform which manages 10 separate datastreams associated with
virtual pins V0-V9. Datastreams V0-V5 correspond to sensor telemetry and
encompass the 3-axis acceleration values, the current temperature and humidity,
and a threshold-based fault indicator (1 = fault detected, 0 = normal). The ML
inference tier outputs are presented across four widgets: predicted class (V6),
actual class (V7), current sample index (V8), and a binary match indicator (V9).
These datastreams are visualized in the system using several different widgets
such as the temperature and humidity gauges and the failure LED display. The
datastreams are updated asynchronously at **2-second intervals for sensor
telemetry** and  **5-second intervals for ML inference results** , providing
the operator with near real-time visibility.

### 5.5 Testing & Verification

System
performance was verified through both ML inference testing and live sensor
pipeline validation. A validation test of the ML inference engine was conducted
using five pre-loaded hardcoded SECOM samples. When the 5 samples were input
into the ESP32 at 5 second intervals it was discovered that all 5 out of 5
inferences returned the correct outcome. A
representative 'Pass' sample produced a fail probability of 0.0004 (effectively
zero). A ‘Fail’ sample triggered the correct fault detection with a fail
probability between 0.58 and 0.64. This is much higher than the optimized
threshold of 0.07. The sensor pipeline was tested using a live feed of MEMS and
thermal data to the Blynk dashboard within 2 seconds of polling. Local
threshold-based fault detection was also verified: a simulated sensor breach
caused the red LED to illuminate immediately.

### 5.6 Section Summary

This
section's implementation verifies that both the IoT monitoring tier and the AI
inference tier operate concurrently on the ESP32 within a simulated industrial
environment: live sensor data streams with full fidelity, and embedded SECOM
samples are classified with 100% parity to the host machine learning model.
Having proved the end-to-end data flow and system functionality, Section 6
reflects on the obtained results and the ethical considerations regarding
edge-based predictive maintenance.
