### 6.1 Achievements and Limitations

Among
the successes were systematically improving the F1-score from 0.36 to 0.42
(+15.6%) and deploying the XGBoost classifier via m2cgen. 5/5 prediction
success on the embedded SECOM samples was verified through validation cycles,
demonstrating that the hardware can achieve bit-exact parity to Python-based
reference models. The limitations are also clear. Even with the 15.6% increase,
an F1-score of 0.42 remains fairly low compared to literature results on
resampled, balanced datasets. The clear boundary and physical distance between
the physical sensors and ML tier, though the intended result, does not lend to
direct, immediate sensor-driven fault detection in its current form. Relying on
a Wokwi simulation and 5 hardcoded test samples is appropriate for the
feasibility study but indicates that future work will require validation on a
physical platform and with a wider variety of samples. All of these aspects
serve as building blocks for the technical reflections discussed in the
following subsections.


### 6.2 Engineering Lessons: The Deployment Toolchain Pivot

The
most significant engineering hurdle was a failure in the initial deployment
pipeline. Emlearn was chosen as it converted tree-based models efficiently, but
the early testing showed that the Random Forest baseline was breaking
completely-it predicted the majority 'pass' class for all inputs. The issue was
found by looking through the produced C code: an (int16_t) cast was applied to the
inputs without an internal scaling factor in the toolchain. Since the inputs
were Z-scored (around -3 to +3) nearly every feature was effectively becoming 0
after truncation completely removing predictive information.

This
identified three crucial changes to the project's approach. First, the
preprocessing pipeline was redeveloped to use a MinMaxScaler with int16 safe
boundaries of [-30000, +30000] in order to maintain fidelity. Secondly, as
optimizations improved the model was changed from a Random Forest to an XGBoost
modelThe toolchain was then changed to m2cgen, which natively supports XGBoost
and uses double-precision arithmetic, avoiding the quantisation problem
entirely. The major lesson was the implicit assumption made by toolchains about
data scaling; it is crucial to examine the generated C code relative to the
Python model to confirm it functions correctly when it is deployed from desktop
to the edge.

### 6.3 Honest Discussion of F1 = 0.42

While
F1=0.4151 is modest in absolute terms, it represents a 15.6% improvement over
the baseline, and the performance can be attributed to the inherent
difficulties of the SECOM dataset. Many F1 scores reported in the SECOM
literature use resampled or balanced test sets, which may not reflect
production-realistic distributions. For predictive maintenance applications, a
high recall (0.524) is often preferable to high precision to minimise the
probability that catastrophic failures occur without detection. The AUC of 0.76
indicates meaningful class separability and provides an adequate basis for
risk-informed decision-making at the edge.


### 6.4 Ethical Considerations

Several
domain-specific ethical considerations emerge from the deployment of edge-based
predictive maintenance. Running the model inferences locally on the ESP32
increases data sovereignty and IP protection, avoiding exposure of sensitive
manufacturing telemetry to potentially vulnerable third-party cloud platforms
and keeping it within the fab's local network. However, model performance
concerns, in particular the problem of false negatives, have critical ethical
implications — undetected failures in the semiconductor fabrication process may
lead to defects entering key sectors like medical and automotive. The question
of model bias is also significant; the XGBoost classifier built on the SECOM
process parameters will likely not translate to a new fabrication environment,
yielding unreliable safety signaling when applied outside the training domain.
Lastly, despite potential labour-replacement implications, transparency in
tree-based models offers an interpretability gain, allowing human operators to
verify the system's decisions and shift from hands-on inspection to
higher-value supervisory tasks.

### 6.5 Section Summary

This
section has reflected on the successful delivery of the AIoT pipeline and the
critical engineering pivots required to maintain model integrity at the edge.
The transition from int16 quantization to double-precision inference
underscores the necessity of toolchain verification in embedded ML. With the
technical and ethical dimensions of the project fully evaluated, the report
concludes in Section 7 with a summary of findings and proposed directions for
future work.
