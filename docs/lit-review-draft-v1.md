# Literature Review — Draft v1

**Module:** LD7182 AI for IoT
**Author:** Rekhanth Reddy Obireddy
**Word target:** ~1000 words across all subsections
**Tonight's target:** Sections 2.1 + 2.2 (~500 words)
**Started:** 27 April 2026

---

## 2. Literature Review

### 2.1 Predictive Maintenance in Semiconductor Manufacturing

Unplanned downtime remains a major cost driver in semiconductor manufacturing. Equipment failures during postsilicon validation and reliability testing can halt production lines and reduce overall yield. Predictive maintenance offers a way forward by identifying issues before they cause outages. Achouch et al. (2022) highlight how Industry 4.0 approaches, including sensor-driven monitoring, can cut machine downtime by 30–50% while extending equipment life and lowering maintenance expenses.

The UCI SECOM dataset serves as a widely used benchmark for this domain (McCann and Johnston, 2008). It contains 1567 instances with 591 features collected from real semiconductor production processes. Each instance records various process parameters along with a pass/fail label. The dataset is highly imbalanced, with only about 6.6% failure cases (104 fails out of 1567), which reflects the rarity of defects in high-volume manufacturing.

Early work addressed these challenges through multiple classifier ensembles. Susto et al. (2015) proposed a multi-classifier methodology specifically for handling censored, imbalanced data in semiconductor manufacturing processes. More recent studies have pushed performance higher by combining feature reduction with advanced algorithms. Salem and Bhuiyan (2025) achieved 98.6% accuracy on SECOM using Support Vector Classifier after PCA-based dimensionality reduction, though this result is reported on a class-balanced (resampled) test set, which can overstate real-world performance.

These cloud- and workstation-based models demonstrate excellent predictive power on the SECOM benchmark. However, they assume abundant computing resources and constant connectivity. Such assumptions do not hold for edge devices deployed directly on test equipment, where memory, power, and latency constraints are critical. This gap motivates the need for lightweight edge solutions explored in the following section.

### 2.2 TinyML and Edge AI Foundations

Tiny Machine Learning (TinyML) enables machine learning inference directly on ultra-low-power microcontrollers, typically consuming less than one milliwatt. Ooko and Karume (2024) define TinyML as the deployment of compact models on resource-constrained edge devices, shifting intelligence closer to the data source rather than relying on distant cloud servers.

This approach delivers four key benefits in industrial settings. It reduces latency for real-time decision making, enhances data privacy by keeping sensitive information on-device, lowers energy consumption through local processing, and cuts operational costs by minimising cloud dependency and bandwidth usage (Ooko and Karume, 2024).

Successful TinyML systems rest on a structured five-layer stack. Njor et al. (2024) describe these layers as hardware, toolchain, model, data, and application. At the model layer, developers apply compression techniques such as quantisation, pruning, clustering, and neuron merging to shrink model size while preserving acceptable accuracy. These methods allow complex classifiers to run efficiently on devices like the ESP32-S3 with limited memory and processing power.

Despite these advantages, TinyML comes with notable trade-offs. Model compression often leads to some accuracy loss compared with full-precision cloud models. Hardware heterogeneity across microcontroller platforms adds deployment complexity. Worse, no standardised benchmark exists for fair cross-platform comparison.
