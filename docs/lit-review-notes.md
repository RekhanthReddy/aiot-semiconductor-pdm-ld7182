**#** Literature Review Notes

**Embedded TinyML for Predictive Maintenance: Vibration Analysis
on**

**ESP32 with Real-Time Fault Detection in Industrial Equipment**

**One-sentence summary: **

It’s about developing an edge-based monitoring system for
real-time predictive maintenance using Tiny ML model and ESP-32 controller
within its memory and processing limitations for fault classification.

**The 4 fault classes they used: **

n  Normal

n  Misaligned

n  Imbalanced

n  Bearing wear

**Their accuracy: ** -

| **Metric** | **1D CNN** | **CNN-LSTM** |
| ---------------- | ---------------- | ------------------ |
| Accuracy         | 91.4%            | 93.6%              |
| Inference time   | 13 ms            | 26 ms              |
| Flash            | 172 KB           | 268 KB             |
| RAM              | 52 KB            | 84 KB              |
| Power            | 93 mW            | 115 mW             |

=**Why they chose 1D CNN over CNN-LSTM: **

1D CNN uses less memory and power compared to

CNN-LSTM. 1D CNN gives balanced performance with efficient execution.

**One thing I can critique: ** (e.g.,
"Used a custom dataset, limiting reproducibility")

AS mentioned, used a custom dataset, from my exp I worked in
Qualcomm, the test facility has many hardware equipment it would really help if
we can get live data (I think lot of problems will arise in live data need to
sample data carefully.)

Paper 2: **Application
of Tiny Machine Learning in Predicative**

**Maintenance in Industries**

**One-sentence summary: **

It’s about
Tiny ML models, their potential advantages and challenges. Future research and
development in Tiny ML.

**The 4
main benefits of TinyML they identify: **

1. TinyML enhances
   responsive and privacy and data security
2. Reduces energy consumption;
   time.
3. Low power ML
   algorithms; Minimal environmental footpront
4. Reduces need for
   extensive data transmission and storage.

**Their
TinyML PdM process flow (the stages): **

**1.****Data acquisition****** — sensor data collected from industrial equipment (vibration, temperature, etc.)
**2.****Data preprocessing****** — cleaning, normalisation, feature extraction (e.g., FFT, statistical features)
**3.****Model design and training****** — selection and training of an ML model, typically done on cloud/workstation
**4.****Model optimisation****** — compression via quantisation and pruning to fit MCU memory/compute budget
**5.****Conversion and deployment****** — convert to inference-ready format (e.g., TFLite) and flash to edge device
**6.****On-device inference****** — real-time prediction on live sensor streams
**7.****Action/output****** — anomaly alert, predictive maintenance trigger, or condition monitoring update sent to user or system

**How they classify TinyML PdM outputs (the 3 types): **

1. Anomaly detection
2. Predictive maintenance
3. Condition monitoring

**The key challenges of TinyML PdM they list:**(bullet the ones you find)

Lack of a Benchmark for TinyML
solutions; Hardware and Software Heterogeneity;Lack of standard models; Limited memory; Accuracy Drops; Privacy issues; Trustworthiness and reliability

**One
gap they identify that my project addresses: **

Standardization and benchmark gap.


**##**** Njor et al. (2024) — Holistic Review of
TinyML Stack for PdM**
**Full citation:** Njor, E., Hasanpour, M.A., Madsen, J.
and Fafoutis, X. (2024) 'A Holistic Review of the TinyML Stack for Predictive
Maintenance', IEEE Access, 12, pp. 184861–184882.

**One-sentence
summary: ** (what does this paper do that Ooko didn't?)

It covers not only Neural Networks but also traditional ML models and their advantages and
disadvantages.

**The
5-layer TinyML stack: **

1. Application layer — Different purpose of PdM syatems with examples for TinyML
2. Data layer – Importance of data and it’s optimisation
3. Model layer – Various ML models and their suitability for TinyML based PdM
4. Toolchain layer – Information about different tools for developing and
   deploying TinyML models.
5. Hardware layer – Different tradeoffs between various types of hardware in terms
   of efficiency, flexibility, usability and cost.

**The
3 PdM output types: **

1. Classification — Models with output categorical values
2. Anomaly Detection —  Attention heads(autoencoders)
   special neural networks for anomaly detection
3. Regression — (usually Remaining Useful Life / RUL)

**Datasets they mention for PdM:**

ToyADMOS; MIMII; Turbofan Engine Degradation Dataset

**Their critique / research gap: **

Doesn’t include any experimental evalution of resource requirement so for now its all theory.

**Hardware platforms surveyed: **

Arduino Nano 33 BLE Sense; Sparkfun Edge: ESP32-C6-DevKitC-1:Google Coral Dev Board Micro:Raspberry Pi 4 Model B:

**Model compression techniques listed: **

Quantization; Pruning; Clustering; Neuron merging

**One thing I can critique: **

Reviews existing work but doesn't propose a benchmark. Nothing new just comparison of different works.

**##**** Hymel et al. (2023) — Edge Impulse MLOps
Platform** **Full citation:** Hymel, S., Banbury, C., Situnayake, D.
et al. (2023) 'Edge Impulse: An MLOps Platform for Tiny Machine Learning',
Proceedings of Machine Learning and Systems (MLSys), 5.

**One-sentence summary: **

It’s about a cloud based MLOPs platform Edge Impulse for
developing TInyML systems.

**The 5 challenges of TinyML development they identify: **

1. Data collection
2. Preprocessing
3. Model development
4. Deployment
5. Monitoring

*Why
DSP preprocessing matters on embedded devices: **

DSP preprocessing is essential because it can **drastically reduce the model size
and computational burden** by using efficient algorithms (like FFT) that are
much faster than achieving the same result through neural network layers.Furthermore, the sources
point out that  **preprocessing can often be the dominant factor in overall
latency** , sometimes exceeding the inference time of the model itself

**The model-size vs accuracy trade-off (their framing) :**

The authors frame this trade-off as a **co-optimization problem** where accuracy
must be balanced against the **strict energy and memory budgets** of
battery-powered devices. They argue that accuracy is not just a performance
metric but a  **power-saving feature** ; for example, false positives in
wake-word detection cause unnecessary wireless transmissions that quickly
deplete the device's battery.

Supported hardware listed:

The sources mention several specific hardware targets and architectures:

* **Arduino** (specifically the Nano 33 BLE Sense).
* **ESP32** (specifically the ESP-EYE).
* **Syntiant** (specifically the NDP101 keyword spotting accelerator).
* **Raspberry Pi Pico** (RP2040).
* **STM32** (the 32-bit Arm Cortex MCU family).
* **Linux boards** utilizing x86 or ARM architectures.

Why I chose pure TF/TFLM over Edge Impulse for my project

While Edge Impulse offers a visual GUI and AutoML tools to lower the barrier for
newcomers, a developer might choose **pure TF/TFLM** for the following
reasons:

* **Granular Control:**
  Standard TinyML pipelines are often a "tangled web of software
  versions". Working directly with TFLM provides the **flexibility**
  to manage specific dependencies and low-level optimizations without the
  abstractions of a platform.
* **Academic Rigor and Reproducibility:**
  To address the "reproducibility crisis," developers must have
  precise version control over the data, preprocessing, and model code. A
  pure TFLM workflow allows for a **fully transparent, script-based
  pipeline** that may be easier to document for research purposes than a
  web-based GUI.
* **Avoiding Ecosystem Lock-in:**
  Hardware-specific frameworks often  **lock a developer into a particular
  ecosystem** . Using the "standard inference engine" of TFLM
  ensures the project remains open-source and flexible across the widest
  possible range of tools and research projects.
