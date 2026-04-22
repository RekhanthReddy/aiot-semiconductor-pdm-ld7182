# ⚠️ **NOTE TO SELF — AI-ASSISTED SKELETON**

This document is **structural guidance only** — an AI-assisted map, not content to copy.

- The "What to cover" bullets are **prompts**, not text to paste into the report
- All example quotes (especially in Section 8 Reflection) are **AI-generated placeholders** — I must write my own authentic reflections
- **Verify the "Qualcomm HTOL/ESD" reference (Section 1.1)** — delete if not accurate to my actual background
- **Verify all citation suggestions** against `references/references.bib` — do not cite papers I haven't read
- **Declare AI use honestly** in the AI declaration form per the assessment brief

*Created: 22 Apr 2026 — kept as planning scaffolding, not for direct inclusion in submitted report.*

---

# LD7182 Final Report — Detailed Skeleton

**Module:** LD7182 AI for IoT
**Student:** Rekhanth Reddy Obireddy
**Project Title:** AIoT Predictive Maintenance & Anomaly Detection System for Semiconductor Test Equipment
**Total Word Limit:** 4000 words (excluding references, appendix, declaration)
**Deadline:** 19 May 2026, 16:00

---

## How to Use This Skeleton

This document is your **map**, not your report. For each section you'll see:

- **Word count target** (sums to ~4000)
- **What to cover** — the substance you must include
- **Citations to drop in** — from your `references.bib`
- **Evidence to capture** — screenshots, tables, figures to take during Wokwi/Colab work
- **Writing prompts** — questions that, when answered honestly, become your paragraphs

Read this skeleton tomorrow morning. As you build the project, take screenshots and notes against the "Evidence to capture" lists. By Week 4 you'll be assembling, not writing from scratch.

---

# FRONT MATTER (not in word count)

## Cover Page

- Module code & title
- Student name & ID
- Total word count (you'll fill in)
- Submission date

## AI Declaration Form (REQUIRED, place at front)

Use the template from your assessment brief. Tick the boxes that genuinely apply. Honest options likely include:

- ☐ I have used AI tools to help me edit and improve my spelling and grammar
- ☐ I have used AI tools to help me develop the structure
- ☐ I have used AI tools to provide feedback and suggestions for improvement on my content

**Do not** tick "generate initial ideas" if your ideas were genuinely your own. **Do not** leave it blank — that's worse than disclosing.

Add a reference declaration statement at the end of your reference list listing each AI tool used and how.

## Table of Contents

Auto-generated from your headings.

---

# 1. INTRODUCTION (~400 words)

## 1.1 Background and Motivation (~200 words)

**What to cover:**

- The cost problem: unplanned downtime in semiconductor manufacturing (cite a stat — see EpiSensor or Achouch et al.)
- Your domain hook: connect to your Qualcomm HTOL/ESD background (1–2 sentences, generic)
- Why traditional cloud-based PdM is insufficient for some equipment monitoring scenarios (latency, privacy, network reliability in fabs)
- The promise of edge AI / TinyML as a complementary approach

**Citations to drop in:**

- Achouch et al. (2022) — for PdM as a Maintenance 4.0 pillar
- Susto et al. (2015) — for the original SECOM motivation

**Writing prompt:** *Why does this matter? Who suffers when test equipment fails unexpectedly, and what would change if we could predict failures on-device?*

## 1.2 Aim and Objectives (~100 words)

**What to cover:**
A clear aim sentence followed by 4–5 numbered objectives. Example structure:

> "This project aims to design, implement, and evaluate an AIoT predictive maintenance system that performs on-device fault classification using TinyML, with cloud-based remote monitoring."

Objectives:

1. Review the literature on TinyML for semiconductor PdM
2. Train a lightweight ML model on the SECOM dataset suitable for edge deployment
3. Simulate the system in Wokwi using ESP32 with virtual sensors
4. Integrate Blynk for cloud monitoring and alerts
5. Evaluate performance, ethics, and limitations of the approach

**No citations needed here.**

## 1.3 Report Structure (~100 words)

A short signposting paragraph: "Section 2 reviews relevant literature… Section 3 describes the system design… Section 4 details the AI component… Section 5 evaluates performance… Section 6 reflects on ethical and sustainability considerations… Section 7 concludes."

---

# 2. LITERATURE REVIEW (~1000 words) — 30% WEIGHTING

This is your highest-weighted section. Treat it accordingly.

## 2.1 Predictive Maintenance in Semiconductor Manufacturing (~250 words)

**What to cover:**

- Define PdM and contrast with reactive/preventive maintenance
- The SECOM dataset as the standard benchmark — describe it (1567 records, 591 features, 93/7 imbalance)
- Recent ML approaches and accuracy (XGBoost+SMOTE, SVC with PCA reaching 98.6%)
- Critique: most are cloud/workstation-based, ignoring edge constraints

**Citations to drop in:**

- Susto et al. (2015) — seminal SECOM paper
- Salem & Bhuiyan (2025) — recent SECOM SOTA
- Kim et al. (2024) — preprocessing study
- Abdelhafiz et al. (2024) — class imbalance handling

**Writing prompt:** *What's the current best-known approach to SECOM, and what gap does it leave open?*

## 2.2 TinyML and Edge AI Foundations (~300 words)

**What to cover:**

- Define TinyML (ML on resource-constrained microcontrollers, sub-1mW operation)
- The four core benefits: latency, privacy, energy efficiency, cost
- The TinyML stack: hardware → toolchain → model → data → application
- Key constraints: limited memory (often <1MB), no OS, hardware heterogeneity
- Standard optimisations: quantization (FP32 → INT8), pruning, knowledge distillation

**Citations to drop in:**

- Ooko & Karume (2024) — TinyML benefits and PdM process flow
- Njor et al. (2024) — 5-layer stack, optimisation techniques
- Yelchuri & Rashmi (2022) — privacy benefits

**Writing prompt:** *Explain TinyML to someone who knows ML but not embedded systems. What changes when you move from a server to a microcontroller?*

## 2.3 TinyML Applied to Predictive Maintenance (~300 words)

**What to cover:**

- Recent TinyML PdM systems on ESP32 and similar MCUs
- Gupta & Shivhare's vibration analysis: 1D CNN, 92% accuracy, 13ms inference, 172KB flash
- Why preprocessing/DSP matters for embedded ML (FFT, MFCC, statistical features)
- MLOps platforms emerging (Edge Impulse) to streamline TinyML workflows
- Sustainability angle: TinyML reduces transmission energy but introduces hardware/battery production cost

**Citations to drop in:**

- Gupta & Shivhare (2025) — direct precedent
- Hymel et al. (2023) — MLOps and DSP importance
- Prakash et al. (2023) — sustainability nuance

**Writing prompt:** *What's the state of the art for ESP32-based PdM right now, and what are its known limitations?*

## 2.4 Research Gap (~150 words)

**What to cover:**

- Existing TinyML PdM work focuses on simple vibration data from rotating machinery (motors, bearings, fans)
- Multi-feature semiconductor process data (like SECOM) has not been deployed to edge devices
- This gap is significant because semiconductor test equipment generates exactly this kind of high-dimensional process data
- Your project addresses the gap by simulating SECOM-trained inference on ESP32 with cloud monitoring

**No new citations** — refer back to gaps identified in earlier subsections.

**Writing prompt:** *In one sentence: what does my project do that nobody else has done? Now justify why that matters.*

---

# 3. SYSTEM DESIGN AND ARCHITECTURE (~700 words)

## 3.1 System Overview (~150 words)

**What to cover:**

- High-level data flow: virtual sensors → ESP32 → preprocessing → TFLite Micro inference → Blynk cloud
- Justify each major design choice in one sentence

**Evidence to capture:**

- **Architecture diagram** (use draw.io / Lucidchart / PowerPoint)
  - Show: sensors → ESP32 → ML inference → Blynk cloud → dashboard
  - Label data formats and protocols

**Citations:** Reference your stack choices to literature (Njor et al. for the 5-layer model)

## 3.2 Hardware Components — Simulated (~200 words)

**What to cover:**

- ESP32 specifications (dual-core Xtensa, 520KB SRAM, 4MB flash, WiFi)
- MPU6050 accelerometer — represents vibration sensing for mechanical anomalies
- DHT22 — represents thermal anomalies
- LEDs as visual fault indicators
- Note that all components are simulated in Wokwi; explain WHY simulation is acceptable for this project (cost, accessibility, reproducibility — Wokwi is mentioned in the assessment guidance)

**Evidence to capture:**

- **Wokwi circuit screenshot** showing all components and wiring
- **Component table** with pin assignments

**Writing prompt:** *Why these specific virtual sensors? How do they map to real semiconductor test equipment monitoring scenarios?*

## 3.3 Software Stack (~200 words)

**What to cover:**

- Wokwi for simulation
- Arduino IDE / PlatformIO for firmware development
- Google Colab + TensorFlow/Keras for model training
- TensorFlow Lite for Microcontrollers (TFLM) for on-device inference
- Blynk IoT platform for cloud dashboard
- Python libraries: pandas, scikit-learn, imbalanced-learn for SECOM preprocessing

**Citations:**

- Hymel et al. (2023) — for the MLOps stack discussion
- Mention that you considered Edge Impulse but chose pure TF/TFLM for greater control

## 3.4 Data Flow (~150 words)

**What to cover:**
Step-by-step description of one inference cycle:

1. Sensors generate readings every N seconds
2. ESP32 reads I2C/digital inputs
3. Preprocessing (normalization to match training distribution)
4. TFLite Micro inference produces fault probability
5. Threshold check determines alert state
6. Status sent to Blynk via WiFi (HTTP/MQTT)
7. LED state updated locally; dashboard updated remotely

**Evidence to capture:**

- **Sequence diagram or numbered flow diagram**

---

# 4. AI COMPONENT: DESIGN AND DEPLOYMENT (~800 words) — 20% WEIGHTING

## 4.1 Dataset and Preprocessing (~250 words)

**What to cover:**

- SECOM dataset description (UCI ML Repository)
- 1567 samples, 591 features (sensor readings from semiconductor manufacturing)
- Class imbalance: ~93% pass, ~7% fail
- Preprocessing steps you applied:
  - Missing value imputation (mean/median for numerical)
  - Removal of constant or near-constant features
  - Standardisation (z-score)
  - Feature selection (top N via variance threshold or feature importance)
  - Class balancing (SMOTE or class_weight)

**Evidence to capture:**

- **Table:** before/after preprocessing (feature count, sample count per class)
- **Bar chart:** class distribution before and after balancing

**Citations:**

- Susto et al. (2015), Kim et al. (2024) — preprocessing approaches
- Abdelhafiz et al. (2024) — class imbalance methods

**Writing prompt:** *What did the data look like raw, and what did you do to make it suitable for a tiny model?*

## 4.2 Model Architecture and Training (~250 words)

**What to cover:**

- Why you chose your architecture (start with a simple MLP or 1D CNN — keep it small)
- Layer-by-layer description (input → hidden → output, activation functions)
- Hyperparameters: batch size, epochs, optimizer (Adam), learning rate
- Loss function (binary cross-entropy with class weights)
- Train/validation/test split (typical: 70/15/15)
- Early stopping criterion

**Evidence to capture:**

- **Model summary screenshot** (model.summary() output)
- **Training curves:** accuracy and loss vs. epochs (matplotlib plots)
- **Code snippet** in appendix

**Citations:**

- Gupta & Shivhare (2025) — for model size benchmark comparison

**Writing prompt:** *Why this model and not something bigger? What constraints drove the choice?*

## 4.3 Quantization and Conversion to TFLite (~150 words)

**What to cover:**

- Why quantization is needed (FP32 model too large for ESP32, slower inference)
- Post-training quantization to INT8
- Use of representative dataset for calibration
- Conversion process via TFLiteConverter
- Final model size in KB

**Evidence to capture:**

- **Before/after table:** model size, accuracy, inference time
- **Code snippet** showing TFLiteConverter usage

**Citations:**

- Njor et al. (2024) — quantization theory

**Writing prompt:** *What did you lose by quantizing, and what did you gain?*

## 4.4 Deployment to ESP32 (~150 words)

**What to cover:**

- Embedding the .tflite model as a C array (xxd command)
- TFLite Micro interpreter setup
- Tensor arena allocation
- Inference loop in main code
- Integration with sensor reads and Blynk send

**Evidence to capture:**

- **Code snippet** showing the inference call
- **Serial monitor screenshot** showing successful inference output

---

# 5. IMPLEMENTATION AND EVALUATION (~700 words)

## 5.1 Implementation Details (~200 words)

**What to cover:**

- Wokwi project setup
- Firmware structure (setup() and loop())
- WiFi connection to Blynk (using Wokwi-GUEST network)
- Blynk dashboard widgets created (gauges, LED, history graph, notification)
- Challenges encountered (e.g., Wokwi memory limits, library conflicts)

**Evidence to capture:**

- **Blynk dashboard screenshot**
- **Wokwi serial monitor output during normal operation**
- **Wokwi serial monitor output during simulated fault**

## 5.2 Performance Evaluation (~300 words)

**What to cover:**
This is critical — gather REAL data, not made-up numbers.

Metrics to report:

- **Accuracy** on test set (overall and per-class)
- **F1-score** — emphasise this for imbalanced data
- **Confusion matrix** (test set)
- **Inference latency** on simulated ESP32 (use Wokwi timer or millis())
- **Model size** (flash usage in KB)
- **RAM usage** (estimated from tensor arena size + program data)
- **End-to-end latency** (sensor read → inference → Blynk update)

**Evidence to capture:**

- **Confusion matrix figure** (matplotlib heatmap)
- **Performance table** comparing to Gupta & Shivhare (2025) baseline
- **Latency measurements table**

**Writing prompt:** *How did the system perform? What surprised you?*

## 5.3 Comparison with Cloud-Based Alternative (~200 words)

**What to cover:**

- Theoretical comparison: if everything ran in the cloud
- Network latency (50–200ms typical)
- Bandwidth: 591 features × float32 × frequency = X kbps per device
- Privacy: data leaves the device
- Cost: cloud API calls per device per month
- Reliability: depends on network

Then contrast with your edge approach.

**No new citations needed** — refer back to Section 2.

**Writing prompt:** *If a fab manager asked "why not just use AWS?" — what's your answer?*

---

# 6. ETHICS, PRIVACY AND SUSTAINABILITY (~600 words) — 15% WEIGHTING

This section is often weak in student reports. Take it seriously.

## 6.1 Data Privacy and GDPR (~200 words)

**What to cover:**

- The on-device inference model aligns with GDPR's data minimisation principle (Article 5)
- Sensor data never leaves the ESP32 — only inference results (fault/normal)
- Explicit reference to GDPR principles: lawfulness, purpose limitation, data minimisation, accuracy, storage limitation, integrity/confidentiality
- Even though this project uses non-personal industrial data, the principles still apply if deployed at scale (e.g., monitoring worker areas)
- Mention DPIAs (Data Protection Impact Assessments) as a recommended pre-deployment step

**Citations:**

- EpiSensor (2024) — GDPR practical guide for IoT
- Yelchuri & Rashmi (2022) — TinyML privacy benefits

**Writing prompt:** *Whose data is involved, and what could go wrong if this scaled to 1000 devices in a fab?*

## 6.2 Security Considerations (~150 words)

**What to cover:**

- Threat model: what could attackers do?
  - Spoof sensor data → false alerts → disrupted production
  - Intercept Blynk traffic → reveal operational patterns
  - Tamper with model weights → bypass detection
- Mitigations:
  - TLS for Blynk communication (mention even if not implemented in simulation)
  - Authentication tokens
  - OTA update integrity checks
  - Model encryption at rest

**Citations:**

- EpiSensor (2024) — IoT security best practices
- Njor et al. (2024) — TinyML security challenges

## 6.3 Sustainability (~150 words)

**What to cover:**

- Edge inference saves transmission energy (significant at scale)
- BUT: hardware manufacturing has carbon cost
- Battery production for many sensors adds environmental burden
- Honest framing: sustainability is a trade-off, not a slam-dunk for TinyML
- Mention e-waste considerations

**Citations:**

- Prakash et al. (2023) — the key sustainability paper

**Writing prompt:** *Is TinyML actually green, or just less bad than cloud ML?*

## 6.4 Bias and Fairness (~100 words)

**What to cover:**

- SECOM is a single-fab dataset — model may not generalise to other equipment types
- Class imbalance can bias model toward predicting "pass" — dangerous for safety-critical equipment
- Mention transfer learning as a mitigation for new deployments

**No new citations needed.**

**Writing prompt:** *Where could this model be wrong in ways that matter?*

---

# 7. CRITICAL EVALUATION AND REFLECTION (~500 words) — 15% WEIGHTING

## 7.1 Strengths of the Approach (~150 words)

**What to cover:**

- End-to-end working system
- Real benchmark dataset (SECOM, not toy data)
- Honest performance measurement
- Clear path from research to deployment
- Privacy-preserving architecture

**Writing prompt:** *What would you genuinely brag about?*

## 7.2 Limitations (~200 words)

Be honest. Examiners reward critical self-assessment.

**What to cover:**

- Simulation vs. real hardware: Wokwi can't replicate sensor noise, drift, RF interference
- SECOM is a 2008 dataset — modern fabs use different sensor configurations
- Class imbalance handling via SMOTE creates synthetic samples that may not reflect real fault patterns
- Single-model approach — production systems use ensemble methods
- No on-device training — cannot adapt to drift
- Blynk free tier limitations (data retention, widget count)

**Writing prompt:** *Where would your supervisor push back?*

## 7.3 Future Work (~150 words)

**What to cover:**

- Deploy to physical ESP32-S3 hardware to validate simulation results
- Federated learning across multiple devices
- Integration with industrial protocols (OPC-UA, MQTT)
- Add explainability (SHAP values) for predictions
- Connect to real fab FDC data via partnership
- Add LLM-based natural-language explanations of anomalies (your portfolio extension)

**Writing prompt:** *If you had 6 more months, what would you build?*

---

# 8. REFLECTION ON LEARNING (~300 words)

This is your personal voice. Don't make it generic.

**What to cover:**

- What you learned about ML: e.g., "I underestimated how much preprocessing dominates the workflow"
- What you learned about embedded systems: e.g., "Memory constraints fundamentally change model design"
- What you learned about MLOps: e.g., "Reproducibility is harder than I thought"
- Honest connection to your career goals: link to semiconductor industry plans
- One specific thing you'd do differently if starting again

**Writing prompt:** *Forget the marker for a moment — what do you actually think about this experience?*

---

# 9. CONCLUSION (~200 words)

**What to cover:**

- Restate the aim
- Summarise key results (accuracy, latency, model size)
- One sentence on the contribution (addressed gap in TinyML PdM for semiconductor process data)
- One sentence on broader implications
- Forward-looking close

**No new citations.**

---

# REFERENCES (not in word count)

Use Harvard style. Generate from your `references.bib`.

End with the AI tool declaration:

> "AI tool declaration: I used Claude (Anthropic) to assist with [list specific tasks: structuring the report outline, suggesting citation placement, proofreading grammar]. All analysis, model development, results interpretation, and written content are my own work."

---

# APPENDIX (not in word count, but keep concise)

## Appendix A: Wokwi Circuit Diagram and Code

- Full diagram.json
- Full sketch.ino with comments
- Wokwi project URL

## Appendix B: Colab Notebook

- Link to GitHub-hosted notebook (.ipynb)
- Key code cells with comments

## Appendix C: Blynk Dashboard Configuration

- Screenshot of widget setup
- Virtual pin mapping table

## Appendix D: User Guide (REQUIRED by brief — keep short)

1. Open Wokwi project at [URL]
2. Click "Start Simulation"
3. Open Blynk app/web dashboard at [URL]
4. Observe normal operation (green LED, low gauge values)
5. To simulate fault: in Wokwi, click MPU6050 and increase acceleration values
6. Observe red LED and Blynk alert

## Appendix E: GitHub Repository

- Full URL
- README with project overview

---

# WORD COUNT TARGETS — RUNNING TOTAL

| Section                        | Target | Cumulative |
| ------------------------------ | ------ | ---------- |
| 1. Introduction                | 400    | 400        |
| 2. Literature Review           | 1000   | 1400       |
| 3. System Design               | 700    | 2100       |
| 4. AI Component                | 800    | 2900       |
| 5. Implementation & Evaluation | 700    | 3600       |
| 6. Ethics & Sustainability     | 600    | 4200       |
| 7. Critical Evaluation         | 500    | 4700       |
| 8. Reflection                  | 300    | 5000       |
| 9. Conclusion                  | 200    | 5200       |

**Total target after first draft: ~5200 words**
**Final after editing: 4000 words (cut 23%)**

It's almost always easier to cut than to expand. Aim long on the first draft.

---

# EVIDENCE COLLECTION CHECKLIST — UPDATE AS YOU BUILD

Tick these off in your GitHub README as you go through Weeks 2 and 3. Without these, you can't write Sections 3–5.

## Week 2 Evidence

- [ ] SECOM raw data shape and class distribution (Colab cell output)
- [ ] Preprocessing pipeline code (Colab notebook)
- [ ] Class distribution before/after SMOTE (bar chart)
- [ ] Model summary output (model.summary())
- [ ] Training history plot (accuracy + loss curves)
- [ ] Test set confusion matrix (heatmap)
- [ ] Per-class precision/recall/F1 (sklearn classification_report)
- [ ] Quantized .tflite model size in KB
- [ ] Wokwi project with sensors and basic firmware reading values
- [ ] Blynk dashboard with at least 3 widgets configured

## Week 3 Evidence

- [ ] TFLite model embedded as C array on ESP32
- [ ] Successful inference on Wokwi (serial monitor screenshot)
- [ ] Inference latency measurement (millis() before/after)
- [ ] RAM usage estimate (tensor arena + reported program memory)
- [ ] End-to-end test: sensor → inference → Blynk update (video or screenshots)
- [ ] Fault simulation: spike sensor values, verify alert (screenshots)
- [ ] At least 30 test cycles logged with results
- [ ] Comparison table: your numbers vs. Gupta & Shivhare baseline
- [ ] Architecture diagram (draw.io export)
- [ ] System data flow diagram

## Week 4 Evidence (Writing-only)

- [ ] All sections drafted at first-pass word count
- [ ] All citations placed and verified against bib file
- [ ] All figures captioned and numbered
- [ ] Word count check (target: 4000 ± 10%)
- [ ] AI declaration completed honestly
- [ ] Spelling/grammar pass
- [ ] References formatted in Harvard style
- [ ] Appendix complete with code and links
- [ ] Final PDF generated and submitted

---

# READING ORDER FOR THIS SKELETON

When you read this tomorrow morning, do it in this order to maximise retention:

1. **Front matter and Section 1** — orient yourself
2. **Section 2 outline + your existing reference notes** — refresh lit context
3. **Sections 3–5 evidence checklists** — note what to capture during builds
4. **Sections 6–7** — these need ongoing reflection, not just data
5. **Word count table** — internalise the proportions
6. **Evidence checklist** — print this and pin it next to your screen

---

# WHAT NOT TO DO

- Don't write any sections before you've done the work — your future self will thank you
- Don't fabricate numbers — examiners cross-check against your code/Wokwi project
- Don't overuse direct quotes — paraphrase from your sources
- Don't pad the lit review with citations you haven't read
- Don't leave the AI declaration blank or dishonestly minimal
- Don't skip the limitations section — it's where critical thinking shows
- Don't submit late — even a 1-minute late submission is capped at the pass mark under most university rules

---

End of skeleton. Good luck with the build.
