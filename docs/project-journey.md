# AIoT Predictive Maintenance Project — Journey Analysis

**LD7182 Final Project | Rekhanth Reddy Obireddy**
**Submission deadline: 19 May 2026**
**Date written: 5 May 2026 (Tuesday Day 11)**

This document walks through the 12 key decisions made during this project chronologically. For each, it captures alternatives considered, reasoning behind the choice, what happened in practice, and lessons learned. It serves three purposes: (1) personal reference for the professor meeting, (2) raw material for Sections 5, 7, and 8 of the final report, and (3) honest documentation of an iterative engineering process.

---

## Decision 1 — Choice of SECOM Dataset

**Decision:** Use UCI SECOM dataset (1567 samples, 590 features, 6.6% fail rate) as the project's data source.

**Alternative considered:** Custom data collection from MEMS sensors on rotating machinery (similar to Gupta and Shivhare, 2025).

**Why SECOM:**

- Authentic semiconductor manufacturing data — directly aligns with my Qualcomm post-silicon validation/HTOL/ESD test engineer background
- Builds portfolio credibility in my domain — academic work in my actual specialisation strengthens future career narrative
- Public, citeable, reproducible — markers can verify the work
- Genuinely challenging: high dimensionality + severe class imbalance
- Most TinyML PdM literature uses simpler vibration data — SECOM creates a clear research gap to fill

**Trade-off accepted:** SECOM features don't directly map to live MEMS sensor readings. This means the Wokwi sensor pipeline cannot feed the model directly without sensor fusion. Documented as future work (see Decision 11).

---

## Decision 2 — Preprocessing Pipeline

**Decision:** Drop high-missing features (28), drop zero/near-zero variance features (265), apply median imputation, apply StandardScaler. Result: 590 → 297 features.

**Alternatives considered:**

- Row deletion for missing values (rejected: 100% of rows have ≥1 missing value, would empty the dataset)
- Mean imputation (rejected: SECOM features are skewed, median is more robust)
- Min-max scaling (rejected: StandardScaler is standard for ML pipelines)
- Keep all 590 features (rejected: 47% carried no information)

**Why this approach:**

- Domain reality: every row in SECOM has missing values → must impute, can't delete
- Feature scaling spans 4+ orders of magnitude → standardisation mandatory
- Aggressive but justified feature reduction — kept only features with real signal

**Saved artefacts:** Pickled imputer + scaler so any future inference uses identical preprocessing.

---

## Decision 3 — Baseline Model Comparison

**Decision:** Train and compare three baseline models — Random Forest, XGBoost, and MLP — to establish performance benchmarks before committing to a deployment approach.

**Why three models:**

- Random Forest: classical strong performer on tabular data
- XGBoost: industry-standard gradient boosting, often best-in-class for structured data
- MLP: neural network baseline to see if deep learning offers an advantage

**Why baselines first:** Avoid premature commitment. Empirical comparison drives the deployment choice.

**Critical methodological discovery:** All three models initially showed F1 = 0.0 at default 0.5 threshold. Investigation revealed classifiers were refusing to predict the minority class entirely (severe imbalance + class_weight defaults). Threshold tuning was essential.

**Results after threshold tuning:**

- Random Forest: F1 = 0.342, AUC = 0.7444 at threshold 0.18 ← best
- XGBoost: F1 = 0.340 at threshold 0.05
- MLP: F1 = 0.148 at threshold 0.14 ← clearly worst

**Decision outcome:** Random Forest selected as primary baseline; XGBoost very close but RF preferred for downstream emlearn compatibility.

---

## Decision 4 — Threshold Tuning Discovery

**Decision:** Use ROC-curve threshold optimisation rather than the default 0.5 cutoff for binary classification.

**Context:** All three baseline models initially produced F1 = 0.0. Looked like complete model failure.

**Investigation:**

- At threshold 0.5, classifiers predicted "Pass" for every sample
- Confusion matrix: 0 true positives, 0 false positives — no positive predictions made
- Model was technically "correct" 93.4% of the time (always predicting majority class) but useless

**Why default threshold failed:**

- Severe class imbalance (6.6% fails) means probabilities for true positives clustered far below 0.5
- Even when the model "knew" something was likely a fault, it couldn't push probability above the default cutoff

**Solution:** Sweep thresholds from 0.05 to 0.95, find the value maximising F1 score. Optimal landed at 0.18 for RF.

**What this taught:** Default thresholds assume balanced classes. Imbalanced datasets need explicit threshold tuning.

---

## Decision 5 — TinyML Neural Network Attempts

**Decision:** Tested three neural network architectures designed for TinyML deployment, expecting compatibility with TFLite Micro to ease ESP32 deployment.

**Three NN variants tested:**

1. **NN v1** — Initial dense network, 297 features, ~21,000 parameters, SMOTE 1:1 balancing → F1 = 0.20, severe overfitting
2. **NN v2** — Heavily regularised: L2 + dropout 0.5, ~10,000 parameters, SMOTE 0.5 → F1 = 0.21, AUC = 0.64
3. **NN v3** — Aggressive feature reduction: top 30 features by RF importance, only 641 parameters → F1 = 0.13, AUC = 0.43

**Why all three failed:**

- SECOM has only 83 minority training samples after split
- Dense NNs need more data than tree ensembles for stable learning
- SMOTE in 297-dimensional space generates synthetic points that don't generalise
- Curse of dimensionality bites harder for NNs than for RF on tabular data

**Critical observation:** This is a literature-confirmed pattern. Tree ensembles outperform NNs on small high-dimensional tabular data (Borisov et al., 2024).

**Decision outcome:** Pivoted to RF deployment via emlearn. The NN failures became evidence-based justification for the architectural choice.

---

## Decision 6 — emlearn vs TFLite Micro

**Decision:** Use emlearn for sklearn → C conversion of the Random Forest model.

**Why this was a real choice:**

- **TFLite Micro:** Best for neural networks. Mature, well-documented, broad ESP32 support
- **emlearn:** Specifically designed for classical ML (sklearn pipelines, decision trees, ensembles)

**Why emlearn won:**

- We pivoted away from NNs (Decision 5), so TFLite Micro's NN strengths weren't relevant
- Random Forest in TFLite Micro would require manual conversion — fragile
- emlearn directly exports sklearn objects to C — clean integration
- emlearn was developed academically with citable references

**Risk accepted:** emlearn is less mature than TFLite Micro. Smaller community, fewer Stack Overflow answers, riskier debugging path. **This risk materialised on Sunday** (see Decision 9).

---

## Decision 7 — 297 vs 127 Features

**Decision:** Initially exported the full 297-feature Random Forest. Later experimented with top-127 features by RF importance, expecting performance loss but smaller model size.

**Surprising finding:** The 127-feature model performed BETTER in sklearn:

- 297 features: F1 = 0.3415, AUC = 0.7444
- 127 features: F1 = 0.4286, AUC = 0.8216

**Why this happened:**

- Top 127 features captured 63.5% of total RF importance, dropping mostly-noisy features
- Curse of dimensionality: only 83 minority training samples don't well-support 297 dimensions
- Removing low-signal features lets trees focus on real patterns rather than fitting noise

**Why we explored 127 specifically:**

- emlearn's `loadable` export method has a hard limit of 127 features
- When we hit that limit, retraining on top-127 became the natural test
- The unexpected accuracy gain validated the dimensionality reduction

**However:** The 127-feature deployment via emlearn's `loadable` method had a quantisation issue (see Decision 8). Final deployment artefact uses 297-feature inline export.

---

## Decision 8 — emlearn `inline` vs `loadable` Export

**Decision:** Use emlearn's `inline` export method (large file, lossless) over the `loadable` method (compact, quantised).

**emlearn provides two C export modes:**

1. **`inline`** — Generates explicit if/else branches; float thresholds preserved exactly. Lossless but huge files (1594 KB)
2. **`loadable`** — Compact array-based representation with fixed-point quantisation. Smaller (189 KB) but lossy; max 127 features

**Initial expectation:** `loadable` would be obvious — smaller is better for ESP32.

**Reality discovered:** Tested 127-feature `loadable` model showed:

- sklearn-level F1: 0.4286 ✓
- C-deployed F1 at any threshold: 0.15 ✗ (catastrophic degradation)

**Diagnosis:** emlearn's `loadable` mode uses fixed-point arithmetic that compressed the model's effective probability output range to just 0.055–0.16 (down from 0.0–1.0). Predictions collapsed.

**Decision:** Accept the 1594 KB size penalty. `inline` preserves model behaviour; size is comfortably within ESP32's 4 MB flash (39% usage).

---

## Decision 9 — int16 Quantisation Diagnosis

**Decision:** Investigated emlearn's input handling deeply on Sunday morning, eventually diagnosing a fundamental incompatibility between emlearn's inline method and z-score standardised features.

**The puzzle:** Even the "lossless" `inline` method showed degraded performance when called from C code.

**Investigation path (3+ hours):**

1. Inspected `cmodel` attributes — found `dtype: int16_t`
2. Inspected emlearn's Python wrapper — discovered it runs the binary as a subprocess with float CSV input
3. Found the C source `mytree.c` and `mytree.h` files generated by emlearn
4. Located `predict_wrapper` function — the bridge between float input and int16 internal representation
5. The smoking gun:

```c
   int16_t features[297];
   for (int i=0; i<length; i++) {
       features[i] = (int16_t)values[i];  // direct cast, no scaling
   }
```

**The core issue:** emlearn's inline method casts float to int16 with no scale factor. For z-score standardised features (range roughly -3 to +3), this truncates almost all values to {-3, -2, -1, 0, 1, 2, 3} — destroying discriminative information.

**Why emlearn assumes integer inputs:** Designed for sensor data domains where features are naturally integer-valued (e.g., raw 0-1023 ADC readings, pixel values 0-255). Z-score standardisation breaks this assumption.

**Decision:** Stop the investigation at the 60-minute hard pivot point. Document the diagnosis as a real engineering finding rather than continuing to chase a workaround.

**What this becomes:** Genuine technical contribution to TinyML deployment friction documentation. Future researchers using emlearn with standardised features will benefit from this diagnosis.

---

## Decision 10 — Wokwi vs Physical Hardware

**Decision:** Use Wokwi (browser-based ESP32 simulator) for all hardware development, instead of physical hardware.

**Why Wokwi:**

- **Cost:** Free vs ~£30-50 for ESP32 + sensors + accessories
- **Time:** Immediate iteration vs ordering, waiting, soldering
- **Reproducibility:** Wokwi project shareable via URL — markers can run identical simulation
- **Rapid debugging:** No physical wiring errors, no broken sensors
- **MSc context:** Learning intent is the deployment pipeline, not hardware fabrication

**Limitations accepted:**

- Sensor data is simulated, not real
- Some hardware-specific issues (power consumption, real-world noise, thermal effects) cannot be tested

**Mitigation in report:** Clearly framed as "simulation-based feasibility study." Section 5 explicitly states physical deployment as future work.

---

## Decision 11 — Threshold-Based Fault Detection (vs Live Model Inference)

**Decision:** Use simple threshold-based fault detection logic on the ESP32 sketch (acceleration > 15 m/s² OR temperature > 40 °C), rather than running the deployed RF on live sensor data.

**Two reasons this was right:**

**Reason 1 — Sensor/feature mismatch:**

- The trained RF expects 297 SECOM process features
- The ESP32 has 5 sensor readings (3 accel + temp + humidity)
- These cannot be sensibly mapped — different phenomena
- Forcing predictions on padded/zero-filled sensor data would be mathematically valid but scientifically meaningless

**Reason 2 — emlearn deployment friction (Decision 9):**

- The C-deployed model has documented integration problems with standardised inputs

**What we DID demonstrate:**

- Model trained, validated, exported to C (1594 KB artefact)
- End-to-end IoT pipeline: sensors → ESP32 logic → cloud monitoring → live alerts
- Threshold-based detection as a working stand-in for ML inference

**What we explicitly avoided:** Faking it. Predictions on incompatible inputs would be meaningless. Academic integrity over visual impressiveness.

---

## Decision 12 — Blynk Cloud Integration

**Decision:** Use Blynk IoT platform for cloud monitoring of sensor data and fault status from the ESP32.

**Why Blynk:**

- Specifically requested by professor — meets explicit assessment expectations
- Free tier sufficient for project scope
- ESP32 first-class support — official library
- Web + mobile dashboard with no app development required
- Wokwi-compatible (via `Wokwi-GUEST` WiFi)

**What we built:**

- 6 datastreams: accel_x, accel_y, accel_z, temperature, humidity, fault_status
- Web dashboard: 5 gauge widgets + 1 LED indicator
- 2-second polling interval
- Live fault status indicator triggered by ESP32-side threshold logic

**Verification (3 functional tests):**

1. Static reading: gauges show correct rest values
2. Live update: moving Wokwi MPU slider triggers cloud update within 2 seconds
3. Recovery: returning slider to rest clears the fault indicator within 2 seconds

**Pre-submission:** Auth token to be regenerated before final submission.

---

## Summary — What This Project Demonstrates

1. **Methodologically rigorous baseline comparison** — three models tested with proper threshold tuning before commitment
2. **Evidence-based architectural pivot** — NN failures empirically justified the move to RF
3. **Honest scoping of deliverables** — simulation, threshold logic stand-in, documented integration gap
4. **End-to-end IoT pipeline working** — sensors → device → cloud → dashboard
5. **Genuine technical contribution** — emlearn deployment friction with standardised features documented for future reference
6. **Domain alignment** — semiconductor focus matches author's professional background

## What's NOT Yet Done

- Live RF inference on ESP32 (architecturally blocked by Reason 1 above; needs sensor fusion work)
- Physical hardware validation
- Power consumption measurement
- Long-running stability testing
