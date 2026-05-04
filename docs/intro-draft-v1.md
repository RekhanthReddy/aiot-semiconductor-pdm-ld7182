For manufacturing, wafer lines run at razor-thin profit margins, and one hiccup
with equipment can lead to devastating loss in yield. Within specialized
environments like High-Temperature Operating Life (HTOL) or post-silicon
validation, an undetected fault doesn't just stall a single batch. It
compromises months of reliability data and risks the delivery of silicon to
global supply chains Each
hour of fab downtime can cost tens of thousands of dollars, and legacy
monitoring systems often cannot distinguish between signal noise and real
hardware faults. As test data is high - dimensional today, traditional
maintenance techniques do not keep up with real-time fault detection.

The Artificial Intelligence of Things (AIoT) brings sensing and intelligence
together directly on the hardware. In an industrial setting, this allows
shifting from the "end-to-end cloud" to an
"on-device-thinking" mechanism. By running optimized models on
microcontrollers via TinyML, manufacturers can detect premature mechanical fatigue or thermal anomalies
without delay or data leakage to an external cloud. Although the real-time
diagnostic potential is considerable, current TinyML research is concentrated
on low complexity, such as vibration sensing and keyword spotting only. More
challenging, high-dimensional industrial application areas remain largely unexplored.

This project develops a TinyML-based predictive maintenance system for high-dimensional
fault detection in semiconductor test equipment. The UCI SECOM dataset provides
a representative benchmark, comprising 1567 process samples, 590 features, and
a challenging 6.6% failure rate. A suitable optimized classification model is
first trained offline, followed by deploying the compressed architecture on the
ESP32 microcontroller, where it will infer the predictions on the edge. The
reliability of the deployment will be investigated using the Wokwi simulation
environment (for hardware) and the Blynk IoT platform (for monitoring
predictions of failures in the cloud). In essence, this serves as a deployment
feasibility study in the field and tests the limits of resource-constrained
hardware with complex industrial data.

The remaining part of the report consists of 8 sections. Section 2 reviews the Literature and
defines the gap for the research, then followed by the architecture for the
hardware and software in Section 3. The AI component is explained in Section 4,
which defines the model, how it's trained and evaluated. Section 5 explains the
implementation using wokwi and Blynk. Section 6 deals with Ethics, while Section
7 provides a critical reflection of the results. The final section 8 has the
future work of the project.
