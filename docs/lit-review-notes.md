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


**##**** Susto et al. (2015)** **Full citation: **

 Susto, G.A., Schirru, A., Pampuri, S.,
McLoone, S. and Beghi, A. (2015) 'Machine Learning for Predictive Maintenance:
A Multiple Classifier Approach', IEEE Transactions on Industrial Informatics,
11(3), pp. 812–820.

**Why
I'm using this: **

Introduces Multiple classifiers for PDM in semiconductor
manufacturing process which can effectively deals with unbalanced data for
planning of maintenance schedules and cost minimization.

Influential PdM methodology paper for semiconductor manufacturing — demonstrates how to
handle imbalanced, high-dimensional, censored data

**Key
facts to paraphrase (3-4 bullets): **

- What is the "Multiple Classifier" approach they propose?

Basically, kdifferent classifiers are used to run on module, each classifier has different classification
problems; hence it’s providing multiple solutions for performance. It’s like running
different classifiers all working in parallel on different problems given
current costs and time.

- Why is unbalanced data THE key challenge in PdM?

Unbalanced (or skewed) data is a major challenge in Predictive Maintenance (PdM) because  **observations
from "normal production" significantly outnumber observations from
"abnormal or faulty production"** . This happens because machines
ideally spend most of their time working correctly, leading to very few data
points representing actual failures

From a machine learning perspective, this skewness is problematic because it generally
results in  **poor prediction accuracy and poor generalization performance** .
The paper’s "Multiple Classifier" approach attempts to solve this by
labeling the last *m* iterations of a cycle as "faulty," which
artificially increases the number of failure samples and reduces the dataset's
skewness

**##**** Achouch et al. (2022)** **Full citation: **

Achouch, M.,
Dimitrova, M., Ziane, K., Sattarpanah Karganroudi, S., Dhouib, R., Ibrahim, H.
and Adda, M. (2022) 'On Predictive Maintenance in Industry 4.0: Overview,
Models, and Challenges', Applied Sciences, 12(16), p. 8081.

**Why I'm using this: **

**predictive maintenance (PdM)- transition from costly,
reactive maintenance strategies to a more efficient, data-driven approach that
ensures sustainable operational management. **

**1.
****Cost and Efficiency Optimization**

**Improved Production Quality**

3. ** Strategic Competitiveness**
4. ** Advanced Monitoring and Prediction**

**Key facts to paraphrase (3-4 bullets): **

- Maintenance evolution: reactive → preventive → predictive

The maintenance landscape has progressed through three primary stages: **Reactive
maintenance** (fixing machines after they break), **Preventive maintenance**
(scheduled, time-based interventions), and finally **Predictive maintenance**
(using data-driven insights to predict failure before it occurs)

- The main challenges (list 4-5 they identify)

Data Quality and Quantity:** Managing the massive volume of data while ensuring it
is accurate and clean.

Computational** Complexity:** The difficulty of running complex AI/ML
models in real-time within industrial environments.

Interoperability**:** Integrating legacy machinery with modern IoT
sensors and communication protocols.

Human**-Machine
Collaboration:** The challenge of upskilling the workforce to interact with
advanced diagnostic tools.

·Security** and Privacy:** Protecting sensitive industrial data
from cyber-attacks, as increased connectivity opens new vulnerabilities.

Financial impact numbers — any specific cost-saving stats?

Predictive maintenance is shown to offer substantial economic benefits, such as reducing
unplanned downtime by **30–50% **and extending the useful life of machinery by **20–40%**.
These efficiencies significantly lower overall
operational costs compared to traditional "run-to-failure" approaches.

- How they define "Maintenance 4.0"

The authors define **Maintenance 4.0** as a paradigm shift that integrates Industry 4.0
technologies—specifically the Internet of Things (IoT), Big Data, Cloud
Computing, and Artificial Intelligence—into the maintenance process. It moves
beyond simple prediction to create a "smart" environment where
systems can self-diagnose, communicate their health status, and optimize their
own maintenance schedules autonomously

**##**** Prakash et al. (2023)** **Full citation: **

 Prakash, S., Stewart, M., Banbury, C.,
Mazumder, M., Warden, P., Plancher, B. and Reddi, V.J. (2023) 'Is TinyML
sustainable? Assessing the environmental impacts of machine learning on
microcontrollers', Communications of the ACM, 66(11), pp. 68–77.

**Why I'm using this: **

This sustainability framing acknowledges that TinyML is not an inherently
"green" technology, but rather a strategic tool with significant
ecological trade-offs. While TinyML reduces operational carbon emissions by
enabling localized inference—thereby avoiding the energy-intensive process of
continuous data transmission to the cloud—it introduces "hidden"
environmental costs, such as the energy consumed during hardware manufacturing,
battery production, and eventual electronic waste management. A responsible
lifecycle analysis reveals that sustainability at the scale of billions of
devices depends on balancing these manufacturing impacts against the
operational savings achieved through aggressive model optimization techniques
like quantization and pruning. Consequently, TinyML’s environmental footprint
is determined by its specific deployment context, requiring developers to
prioritize energy efficiency alongside model accuracy as a primary design
metric.

**Key
facts to paraphrase (3-4 bullets): **

·       **Operational Carbon Savings:** TinyML reduces operational carbon
emissions by enabling localized "edge" processing, which avoids the
energy-intensive process of continuously transmitting raw data to cloud servers
for inference.

·       Hidden** Environmental Costs:**
Beyond operational energy, TinyML involves significant "hidden"
ecological costs, including the energy-intensive manufacturing of
microcontrollers, battery production, and the eventual management of electronic
waste (e-waste).

·       Lifecycle** Analysis Methodology:**
A robust sustainability assessment requires a full lifecycle methodology,
evaluating the environmental footprint across the entire lifespan of a
device—from raw resource extraction and hardware fabrication to energy usage
during model training/inference and final hardware disposal.

·       Implications** of Global Scale:**
When deployed at the scale of billions of devices, the cumulative environmental
impact of TinyML becomes substantial; therefore, aggressive model optimization
(such as pruning and quantization) is critical to minimize the global
ecological footprint.
