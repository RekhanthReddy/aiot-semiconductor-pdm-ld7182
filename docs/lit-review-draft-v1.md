# Literature Review — Draft v1

**Module:** LD7182 AI for IoT
**Author:** Rekhanth Reddy Obireddy
**Word target:** ~1000 words across all subsections
**Tonight's target:** Sections 2.1 + 2.2 (~500 words)
**Started:** 27 April 2026

---

## 2. Literature Review

### 2.1 Predictive Maintenance in Semiconductor Manufacturing

Unplanned downtime remains a major cost driver in semiconductor manufacturing. Equipment failures during postsilicon validation and reliability testing can halt production lines and reduce overall yield. Predictive maintenance offers a way forward by identifying issues before they cause outages. Achouch et al. (2022) highlight how Industry 4.0 approaches, including sensor-driven monitoring, can cut machine downtime by 30–50%. The same approaches extend equipment life and lower maintenance expenses.

The UCI SECOM dataset serves as a widely used benchmark for this domain (McCann and Johnston, 2008). It contains 1567 instances with 591 features collected from real semiconductor production processes. Each instance records various process parameters along with a pass/fail label. The dataset is highly imbalanced, with only about 6.6% failure cases (104 fails out of 1567), which reflects the rarity of defects in high-volume manufacturing. From a product test engineer perspective, this imbalance is important: a single missed failure can propagate to customer-returned product, more costly than a false alarm at the line.

Early work addressed these challenges through multiple classifier ensembles. Susto et al. (2015) proposed a multi-classifier methodology specifically for handling censored, imbalanced data in semiconductor manufacturing processes. More recent studies have pushed performance higher by combining feature reduction with advanced algorithms. Salem and Bhuiyan (2025) achieved 98.6% accuracy on SECOM using Support Vector Classifier after PCA-based dimensionality reduction, though this result is reported on a class-balanced (resampled) test set, which can overstate real-world performance. In other words, headline accuracy on SECOM hides a harder problem.

These cloud- and workstation-based models demonstrate excellent predictive power on the SECOM benchmark. However, they assume abundant computing resources and constant connectivity. Such assumptions do not hold for edge devices deployed directly on test equipment, where memory, power, and latency constraints are critical. This gap motivates the need for lightweight edge solutions explored in the following section.

### 2.2 TinyML and Edge AI Foundations

Tiny Machine Learning (TinyML) enables machine learning inference directly on ultra-low-power microcontrollers, typically consuming less than one milliwatt. Ooko and Karume (2024) define TinyML as the deployment of compact models on resource-constrained edge devices, shifting intelligence closer to the data source rather than relying on distant cloud servers.

This approach delivers four key benefits in industrial settings. It reduces latency for real-time decision making, enhances data privacy by keeping sensitive information on-device, lowers energy consumption through local processing, and cuts operational costs by minimising cloud dependency and bandwidth usage (Ooko and Karume, 2024). These benefits are real, but they are not free. 

Successful TinyML systems rest on a structured five-layer stack. Njor et al. (2024) describe these layers as hardware, toolchain, model, data, and application. At the model layer, developers apply compression techniques such as quantisation, pruning, clustering, and neuron merging to shrink model size while preserving acceptable accuracy. These methods allow complex classifiers to run efficiently on devices like the ESP32 with limited memory and processing power.

Despite these advantages, TinyML comes with notable trade-offs. Model compression often leads to some accuracy loss compared with full-precision cloud models. Hardware heterogeneity across microcontroller platforms adds deployment complexity. Worse, no standardised benchmark exists for fair cross-platform comparison.

### 2.3 TinyML Applications in Predictive Maintenance

Recent studies have demonstrated that TinyML can deliver real time predictive maintenance on microcontroller platforms. Gupta and Shivhare (2025) developed an edge-based monitoring system using ESP32 with a 1D Convolutional Neural Network for a vibration based fault detection. Their model achieved a 91.4% accuracy with low inference time of 13ms across four fault classes while using only 172KB flash memory. Their work focused on rotating machinery using the custom collected vibration data. This represents one of the key reference for my work.

The practical deployment of TinyML model for PdM heavily depends on the data collection and preprocessing. Hymel et al. (2023) highlight that on edge devices, the real bottleneck is digital signal processing, which can often be the dominant factor in overall  latency, sometimes exceeding the inference time of the model itself. Efficient algorithms such as FFT and extraction of statistical features play an important role  in improving model performance and reducing latency. The authors also highlight the value of MLOps platforms like Edge Impulse for streamlining the workflow from data collection to deployment. While platforms like Edge Impulse offer streamlined workflows, this project uses pure TensorFlow Lite Micro to maintain granular control over the preprocessing and quantisation pipeline. 

It is also important to assess the environmental impact of TinyML solutions. Prakash et al. (2023) point out that while enabling localised inference on edge reduces carbon emissions by limiting the data transmission to the cloud, it introduces 'hidden' environmental costs, such as microcontroller manufacturing footprint, battery usage and eventual electronic waste management. Large scale system improvements must consider environmental sustainability alongside accuracy and latency.

In real time test environment such as semiconductor post silicon validation and testing, equipment generates high dimensional data rather than simple vibration signals. Despite these advances, current  TinyML PdM work has a notable blind spot: high-dimensional process data, as found in semiconductor test environments, remains largely unaddressed.

### 2.4 Research Gap

A clear pattern emerges from the literature reviewed above. Many TinyML applications for predictive maintenance have focused on comparatively simple vibration or audio signals from rotating machinery (Gupta and Shivhare, 2025; Hymel et al., 2023). While cloud-based studies have successfully tackled high-dimensional semiconductor process data such as the SECOM dataset (Susto et al., 2015; Salem and Bhuiyan, 2025; Abdelhafiz et al., 2024), these approaches assume abundant computing resources and constant connectivity.

What remains largely unexplored is the use of TinyML models with complex, multi-feature data from semiconductor processes on resource-limited edge devices. The combination of extreme class imbalance (only 6.6% failure cases), high dimensionality, and strict memory and power constraints of microcontrollers like the ESP32 presents unique challenges. These issues have not been adequately addressed in current TinyML PdM work.

This project addresses the gap by training a TinyML model on the SECOM dataset. It optimises the model for deployment on the ESP32 using Wokwi simulation. It also integrates cloud monitoring through Blynk. In semiconductor test floors where high dimensionality process telemetry is common, closing this gap is highly relevant.
