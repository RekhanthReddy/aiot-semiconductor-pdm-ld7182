# AIoT Predictive Maintenance for Semiconductor Manufacturing

**Edge ML for semiconductor wafer-yield prediction:** XGBoost classifier trained on the UCI SECOM benchmark, exported to C via m2cgen, and verified bit-exact on an ESP32 microcontroller (140 KB). Paired with a live IoT telemetry pipeline (sensors to ESP32 to Blynk cloud dashboard).

> MSc project (LD7182, AI for IoT) bridging prior post-silicon validation experience at Qualcomm with machine learning applied to semiconductor test workflows.

---

## Results

| Metric              | Value                                                                                                     |
| ------------------- | --------------------------------------------------------------------------------------------------------- |
| F1 Score            | 0.4286 best offline (127-feature RF); 0.4151 final deployed config (XGBoost, top-100 features, SMOTE 0.5) |
| Baseline F1         | 0.342 (Random Forest, 297 features, threshold-tuned)                                                      |
| AUC                 | 0.76                                                                                                      |
| Recall              | 0.52                                                                                                      |
| Deployed model size | 140 KB (m2cgen C export) vs 1,594 KB (emlearn inline export) — over 10x smaller                          |
| ESP32 flash usage   | ~10%                                                                                                      |
| Python-to-C parity  | Bit-exact, verified against stored SECOM test samples                                                     |

Result of 8 orthogonal tuning experiments spanning SMOTE oversampling ratios, RF-importance feature selection (590 to 100), alternative oversamplers, hyperparameter tuning, and classifier comparison (Random Forest, MLP, XGBoost) — full reasoning for each step in the engineering log.

## Problem

Semiconductor wafer fabs face a severe class imbalance problem: failure rates are typically 6-8%, which makes naive classifiers useless — a default 0.5 threshold on this data yields zero positive predictions for every model tested. The UCI SECOM benchmark (1,567 wafers, 590 process sensor readings, 6.6% failure rate) is the standard public dataset for this problem.

This project builds and validates a classifier for that problem, then investigates what it actually takes to deploy it to constrained edge hardware (an ESP32) with verified Python-to-embedded parity — surfacing a real deployment pitfall along the way (see Key technical decisions, below).

## What this project actually demonstrates

Two pipelines, deliberately kept separate, each doing a different job:

1. **ML pipeline (offline-trained, embedded-verified):** XGBoost trained and validated on SECOM process data; exported to C; bit-exact parity confirmed by running the exported model on the ESP32 against stored SECOM test samples.
2. **IoT pipeline (live):** MPU6050 + DHT22 sensors feeding the ESP32, running threshold-based fault logic, streaming live telemetry to a Blynk cloud dashboard.

**Why these two pipelines don't feed into each other:** SECOM's 590 process features describe fab equipment measurements with no valid mapping to the ESP32's 5 physical sensor channels. Forcing live sensor readings through a model trained on different physical quantities would be mathematically possible but scientifically meaningless. Rather than fake that connection for a more impressive-looking demo, the project documents this as a known architectural limitation and scopes true sensor-fused live inference as future work. The full reasoning is in the engineering log (Decision 11).

## Architecture



ML pipeline:   SECOM dataset  ->  XGBoost (Python)  ->  m2cgen C export  ->  ESP32 (bit-exact verified)

IoT pipeline:  MPU6050 + DHT22  ->  ESP32 (threshold logic)  ->  Blynk cloud dashboard


- **Edge:** ESP32 microcontroller
- **ML deployment:** XGBoost model exported to C via m2cgen, verified bit-exact against stored test samples
- **Live sensors:** MPU6050 (vibration) + DHT22 (thermal)
- **Cloud:** Blynk IoT, 6 datastreams, 2-second polling, live fault indicator
- **Simulation:** Wokwi (full ESP32 + sensor emulation, local compile to bypass free-tier server queue)

## Key technical decisions

**Why XGBoost over a neural network?**
Tested 3 NN architectures; all underperformed a Random Forest baseline (best NN F1 = 0.21 vs RF F1 = 0.34). With only 83 minority-class training samples, dense networks overfit badly in high-dimensional space — a pattern consistent with published findings that tree ensembles outperform NNs on small, high-dimensional tabular data. XGBoost on RF-selected features ultimately beat both.

**Why m2cgen over emlearn for final deployment?**
emlearn is purpose-built for classical ML to C export and was the first choice for the Random Forest model. Two issues surfaced: emlearn's compact `loadable` export mode uses fixed-point quantisation that collapsed the model's output range, destroying accuracy (F1 dropped from 0.43 in Python to 0.15 once deployed). Switching to emlearn's lossless `inline` mode fixed the accuracy problem but produced a 1,594 KB file. Separately, emlearn's int16 casting assumes integer-valued sensor inputs (e.g. raw ADC readings) and silently truncates standardised float features — a deployment pitfall not obvious from the documentation, diagnosed by tracing emlearn's generated C source down to the exact cast statement. m2cgen (used for the XGBoost model) avoided this entirely and produced a 140 KB export — over 10x smaller with better accuracy.

**The quantisation bug, in detail:**
Z-score standardised features (range roughly -3 to +3) get cast directly to int16 with no scale factor in emlearn's inline export, truncating nearly all values to just {-3, -2, -1, 0, 1, 2, 3} and destroying discriminative information. Root-caused by reading emlearn's generated C source directly. Fixed in the final pipeline by retraining on min-max scaled features (range plus-or-minus 30,000), which stay safely inside int16 bounds and restore full precision.

## Tech stack

- **ML training:** Python, scikit-learn, XGBoost, imbalanced-learn (SMOTE)
- **Deployment:** m2cgen (XGBoost to C), emlearn (Random Forest to C, explored and superseded)
- **Embedded:** ESP32, C/C++, Arduino framework
- **Simulation:** Wokwi (online ESP32 emulator) — [live project](https://wokwi.com/projects/462262259358425089)
- **Cloud:** Blynk IoT (dashboard, virtual pin telemetry)

## Repository structure



/colab/        - Jupyter notebooks: data exploration, model training, experiment comparison

/wokwi/        - ESP32 firmware (C/C++), Wokwi simulation files

/blynk/        - Dashboard configuration, screenshots

/dataset/      - SECOM preprocessing pipeline (590 -> 297 -> 100/127 feature reduction stages)

/docs/         - Literature review, full report, engineering decision log

/references/   - BibTeX


## Running the project

1. `pip install -r requirements.txt`
2. Open `/colab/train_xgboost_secom.ipynb` and run end-to-end — reproduces the SMOTE + feature-selection + XGBoost pipeline
3. The notebook exports the champion model to C via m2cgen
4. Open the [Wokwi project](https://wokwi.com/projects/462262259358425089), load the generated header file, and run the simulation
5. Connect a Blynk account and point the virtual pins at your dashboard to see live sensor telemetry

## Engineering log

The full set of 12 engineering decisions behind this project — alternatives considered, what happened in practice, and what was learned — is documented in [`docs/project-journey.md`](docs/project-journey.md). This includes the complete investigation trail for the quantisation bug and the reasoning behind every architectural trade-off.

## About

Built for module LD7182 (AI for IoT), MSc AI Technology, Northumbria University London, 2026.

**Author:** Rekhanth Reddy Obireddy — ex-Qualcomm post-silicon validation engineer
**LinkedIn:** [linkedin.com/in/rekhanth-reddy-obireddy-a3b033241](https://www.linkedin.com/in/rekhanth-reddy-obireddy-a3b033241/)
**Contact:** rekhanth.191@gmail.com
