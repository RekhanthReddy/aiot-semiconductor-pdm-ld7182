### 2.1 Predictive maintenance in semiconductor manufacturing

In semiconductor manufacturing, the largest cost is unplanned machine downtime.
When equipment fails during post-silicon validation and reliability testing,
the assembly line comes to a halt and significantly reduces yield. Predictive
maintenance could fix this issue by diagnosing potential failures before they
cause the downtime. Achouch et al. (2022) suggest that an Industry 4.0 solution
such as using sensors to monitor the machinery can reduce maintenance
costs by 30–50% across general manufacturing. The
same approaches extend equipment life and lower maintenance expenses. Research
in this area depends on representative benchmark data.

The UCI SECOM dataset has become a standard benchmark for this problem domain (McCann and
Johnston, 2008). The dataset consists of 1567 examples and 590 features
generated in a real semiconductor manufacturing process. Each example contains
values for multiple process parameters and a binary label indicating whether
the process passed or failed. This is a highly imbalanced dataset: only about
6.6% of observations are failures (104 failures among 1567 observations).
This rate reflects the low
defect levels typical in high-volume manufacturing. The defect level is
critical for a product test engineer because the misdetection of one failure
has far greater cost implications down the line than a single false alarm at
the line.

Past approaches used multiple classifiers ensembles to deal with these difficulties.
For example, Susto et al. (2015) proposed a method using multiple classifiers
to deal with the censored, imbalanced data associated with manufacturing
processes in semiconductor manufacturing. Performance has improved more
recently as a result of a combination of feature reduction methods with newer
algorithms. Salem and Bhuiyan (2025) reported a result of 98.6% accuracy on the
SECOM benchmark with the Support Vector Classifier and PCA-based dimensionality
reduction but, like most results on SECOM, this performance was achieved on a
class-balanced (resampled) test set and doesn't necessarily reflect real world
accuracy. That is, "accuracy" can be misleading on SECOM.

Cloud/workstation-basedsystems have achieved high accuracy on the SECOM benchmark; however, these assume unlimited compute resources and consistent connectivity, assumptions that are no longer true in an edge setting. An edge system that lives on a test
piece needs to address memory, power and latency constraints.

### 2.2 TinyML and Edge AI Foundations

Tiny Machine Learning, or TinyML, allows for machine learning inference directly on
ultra-low power microcontrollers which consume power values of less than 1mW
(Ooko and Karume, 2024). According to Ooko and Karume (2024) it may be viewed
as deploying a miniature machine learning model onto resource constrained
embedded systems, meaning rather than intelligence located on remote cloud
servers, data can be processed locally. For an industrial context there are
four specific benefits. Low latency allows real-time decision making. Enhanced
data privacy keeps confidential information on the device, so it never leaves
the edge. Low power consumption results from local rather than remote
processing. Lower operational costs follow from reduced cloud and bandwidth
dependency.

A robust
TinyML system has a five-layer stack; according to Njor et al. (2024) these
layers are the hardware, toolchain, model, data and application. This
review focuses on the model layer which represents
where model compression techniques such as quantisation, pruning, clustering,
and neuron merging are used to shrink models with controlled trade-offs
in predictive performance. This
allows large classifiers to run efficiently on low-power microcontroller chips
such as the ESP32 which possess relatively limited processing power and memory
capacity.

While these
advantages are genuine, they involve significant trade-offs, such as a typical
degradation in accuracy. This degradation stems from quantization reducing
numeric precision in model weights. The variety of available hardware means
that deployment across different microcontrollers introduces further
complexity. From a
deployment perspective, the lack of standardized benchmarks means each project
must establish its own evaluation criteria rather than build on shared
evidence.

### 2.3 Applications of TinyML for Predictive Maintenance

Recent work
has shown that TinyML is capable of real time predictive maintenance on
microcontroller devices. Gupta and Shivhare (2025) developed an edge-based
monitoring system using ESP32 with a 1D Convolutional Neural Network for vibration-based
fault detection. Their model achieved an accuracy of 91.4%, with an inference
time of 13ms for four fault classes while utilizing 172KB flash memory. The
model utilizes data derived from rotating machinery and employs a custom
collected vibration data set. This serves as a key reference for the present
project.

Effective
deployment of a TinyML model in a PdM scenario is heavily reliant on efficient
data collection and preprocessing. Hymel et al. (2023) report that digital
signal processing, rather than inference, often dominates overall system
latency on edge devices. Performing DSP in an efficient manner (i.e. using FFT
and statistical feature extraction) plays an essential role in ensuring high
model performance and low latency. The authors also discuss the benefit of
MLOps platforms such as Edge Impulse for streamlining this end-to-end workflow.
However, this project uses pure TensorFlow Lite Micro to ensure complete
control over the preprocessing and quantization process.

An additional
important aspect of TinyML for PdM is the environmental impact. Prakash et al.
(2023) state that although localized inference on the edge lowers the carbon
emissions associated with data transmission to the cloud, it introduces
additional "hidden" costs such as the manufacturing footprint of
microcontrollers, battery consumption, and the problem of waste management.
System-wide improvements must factor in environmental sustainability along with
accuracy and latency performance.

Within
real-time testing environments such as semiconductor post-silicon validation,
equipment generates complex high-dimensional data as opposed to simple
vibration signals. To date, TinyML has not been successfully adapted for
semiconductor testing, where the high-dimensional data complexity exceeds
current research applications.

### 2.4 Research Gap

A clear
pattern emerges from the literature reviewed above. Many TinyML approaches
toward PdM are concerned with simpler vibration or audio inputs from rotating
machinery (Gupta and Shivhare, 2025; Hymel et al., 2023). While several
cloud-based approaches successfully used high-dimensional process data such as
the SECOM dataset (Susto et al., 2015; Salem and Bhuiyan, 2025; Abdelhafiz et
al., 2024) their solutions rely heavily on cloud computing and constant network
access.

What remains
largely unexplored is the use of TinyML models with complex, multi-feature data
from semiconductor processes on resource-limited edge devices. Three challenges
combine to make this difficult: severe class imbalance (only 6.6% failures),
high feature dimensionality, and the strict memory and power constraints of
microcontrollers like the ESP32. Current TinyML PdM research has not addressed
this combination.

This project
seeks to fill this gap by attempting to train a TinyML model on the SECOM
dataset, optimizing it to run on an ESP32, simulating it on Wokwi, and
monitoring it on the cloud using Blynk. Closing this gap matters because
high-dimensional process telemetry dominates semiconductor test floors, and
bringing predictive maintenance to the edge could reduce both cloud dependency
and decision latency for fault detection.
