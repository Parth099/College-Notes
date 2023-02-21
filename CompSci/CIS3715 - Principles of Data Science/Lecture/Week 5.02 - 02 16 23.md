# Logistic Regression Cont.

**Loss Function**

$$
\min_{\vec{w}} 
\biggr[
y_i\log{p_i} + (1-y_i)\log{(1-p_i)}
\biggr]
$$

> The derivation will be covered by me later or in *CIS4526*. 

A hyperparameter is attached onto the above term to control the components of $\vec{w}$ .

$$
+\lambda\|\vec{w}\|_2^2
$$

## Evaluation for Binary Classification
### Accuracy

$$
\text{Accuracy} = \frac{\# \text{ num correct predicts}}{\# \text{ Total predicts}}
$$

This is valid for *balanced* datasets but does not end well for imbalanced datasets. Consider a data with 9 negative samples and 1 positive sample with the predictor always returning a `0`. This would result in a 90% overall accuracy yet a complete misclassification of a class. 

### Metrics: TP, FP, FN, TN

|                    | Positive (truth)    | Negative (Truth)    |
| ------------------ | ------------------- | ------------------- |
| Positive (Predict) | TP - True Positive  | FP - False Positive |
| Negative (Predict) | FN - False Negative | TN - True Negative  | 

#### Recall and Precision

> Think of Conditional Probability when looking at these. 

$$
P(A | B) = \frac{P(A \cap B)}{P(B)}
$$

##### Recall

$$
\text{Recall} = \frac{TP}{TP + FN}
$$

Recall will measure the proportion of positives classified correctly out of all real Positive instances. 

A large recall means more positives instances would be found by the classifier.

##### Precision

$$
\text{Precision} = \frac{TP}{TP + FP}
$$

Precision will measure the proportion of positive predictions is actually correct.

A large precision implies a higher probability a positive prediction is correct. 

##### F1 Score
> Harmonic mean between precision and recall

$$
F_1 = \frac{2}{\frac{1}{\text{Recall}}+\frac{1}{\text{Precision}}} = \frac{2\times\text{Recall}\times\text{Precision}}{\text{Recall}+\text{Precision}}
$$