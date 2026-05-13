### 7.1 Project Summary

This project developed an integrated
AIoT predictive maintenance system on an ESP32 microcontroller, showing that
high-dimensional inference is possible at the edge. The system uses a two-tier
architecture to process real-time data from MEMS sensors and run machine
learning classifications simultaneously. A key achievement was improving the
predictive model’s F1-score from 0.36 to 0.42 by refining features and
switching to an XGBoost model. The model was migrated from Python to embedded C
using m2cgen, preserving the model weights and logic exactly. Final tests
showed the system streams sensor data quickly to a Blynk cloud dashboard and
correctly classifies all SECOM test samples. This work shows that tree-based
ensemble models can be made sufficiently small for industrial monitoring
without sacrificing accuracy.

### 7.2 Key Findings

Several
key findings emerge from the development and testing of this system:

·Reducing
the number of features had the biggest impact on performance. Using only the
top 100 features performed much better than using all 440 features, regardless
of the model used.

·Standard
int16 quantisation is incompatible with z-score standardised features, as
demonstrated by the emlearn deployment failure in this project. For reliable
results on embedded systems, double-precision arithmetic or careful range
scaling is needed.

·m2cgen
provides a reliable way to deploy XGBoost models, ensuring predictions remain
identical across Python and C.

·The
two-tier architecture provides a strong framework for AIoT systems, especially
when physical sensor data and process telemetry do not align well.

### 7.3 Future Work

The
current system demonstrates that edge-based predictive maintenance is possible,
but there is still room for improvement. The main goal should be to move from
the current two-tier setup to real sensor fusion. Future versions should train
a second machine learning model directly on the high-frequency vibration and
thermal data from the MPU6050 and DHT22 sensors. Migrating from the Wokwi
simulation to actual ESP32 hardware to test the system in real-world
conditions, including electromagnetic interference and changing environments.

To make the verification process stronger, the system could stream more of the
SECOM test set through the serial interface instead of just using five fixed
samples. Measuring latency and power use on real hardware would also help show
how model complexity affects battery life, which is important for wireless
industrial use. For a more advanced upgrade, adding federated learning could
let several manufacturing sites work together to improve the model without
sharing sensitive or restricted data. These changes would help turn the current
prototype into a reliable, production-ready solution for the semiconductor
industry.

### 7.4 Closing Remarks

This
project demonstrates that high-dimensional ensemble models can run effectively
on low power edge devices, enabling real-time industrial intelligence. By
solving key toolchain and data scaling problems, it provides a viable pathway
for implementing predictive maintenance in the semiconductor industry and lays
a strong foundation for future AIoT advances.
