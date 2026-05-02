# aiot-semiconductor-pdm-ld7182

AIoT Predictive Maintenance for Semiconductor Test Equipment — LD7182

**#** AIoT Predictive Maintenance for Semiconductor Test Equipment

******Module:****** LD7182 AI for IoT
******Student:****** Rekhanth Reddy Obireddy
******Institution:****** Northumbria University London
******Deadline:****** 19 May 2026

**##** Project Overview
An AIoT predictive maintenance system that performs on-device fault
classification using TinyML, trained on the UCI SECOM semiconductor
manufacturing dataset, simulated on ESP32 in Wokwi, with cloud
monitoring via Blynk.

**##** Tech Stack
**-****Simulation:****** Wokwi (ESP32 + MPU6050 + DHT22)
**-****ML Training:****** Google Colab + TensorFlow/Keras
**-****On-device Inference:****** TensorFlow Lite for Microcontrollers
**-****Cloud Dashboard:****** Blynk IoT

**##** Project Timeline
**-****Week 1 (21–27 Apr):****** Literature review + dataset exploration + Wokwi setup
**-****Week 2 (28 Apr–4 May):****** ML model training + Blynk integration
**-****Week 3 (5–11 May):****** End-to-end integration + testing
**-****Week 4 (12–19 May):****** Report writing + submission

**##** Repository Structure
**-**`/docs` — lit review notes, report drafts
**-**`/colab` — Jupyter notebooks for ML training
**-**`/wokwi` — ESP32 simulation files
**-**`/blynk` — dashboard configuration and screenshots
**-**`/dataset` — SECOM data and preprocessing
**-**`/references` — BibTeX references

## Project Resources

- **Wokwi Simulation:** https://wokwi.com/projects/462262259358425089
- **GitHub Repository:** https://github.com/RekhanthReddy/aiot-semiconductor-pdm-ld7182
- **Status:** Week 1 — Wokwi circuit complete, SECOM exploration in progress

## Progress Log

- 23 Apr: Repo setup + Papers 1-2 (Gupta, Ooko)
- 24 Apr: Papers 3-4 (Njor, Hymel)
- 25 Apr: Papers 5-7 (Susto, Achouch, Prakash) + Wokwi circuit complete
- 26 Apr: GitHub catchup + SECOM exploration
- 30 Apr: SECOM preprocessing pipeline complete. 590 → 297 features.
  Imputer + scaler saved for downstream use.
- 30 Apr: Baseline models trained (RF, XGBoost, MLP). Best baseline:
  Random Forest with F1=0.342 at threshold 0.18. Threshold tuning
  required because default 0.5 yields zero positive predictions on
  SECOM's 93/7 imbalance. These baselines establish a lower bound
  for the TinyML model to beat.
- 2 May: Saturday TinyML day. Tested 3 NN architectures - all underperformed
  RF baseline (best NN F1=0.21 vs RF 0.34). Pivoted to RF deployment via
  emlearn. Final deployment artefact: 297-feature RF, inline C export
  (1594 KB), 39% of ESP32 flash. Sunday: ESP32 deployment + Blynk integration.
