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

![1776887831422](image/lit-review-notes/1776887831422.png)   ![]()

**How
they classify TinyML PdM outputs (the 3 types): **

1. Anomaly detection
2. Predictive maintenance
3. Condition monitoring

**Thekey challenges of TinyML PdM they list:**(bullet the ones you find)

Lack of a Benchmark for TinyML
solutions; Hardware and Software Heterogeneity;Lack of standard models; Limited memory; Accuracy Drops; Privacy issues; Trustworthiness and reliability

**One
gap they identify that my project addresses: **

Standardization and benchmark gap.
