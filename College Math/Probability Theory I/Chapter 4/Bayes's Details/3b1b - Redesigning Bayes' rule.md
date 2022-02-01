# The Paradox
Suppose we have a sample of $1,000$ people. Say $1\%$ **have** cancer and the other $99\%$ don't.

10 people have cancer, 990 do not. 

They all then get screened for this cancer. The screen **correctly** reports that $9$ of the $10$ have cancer but failed to correctly see that the 10th person also had cancer.

For these 10 people, there are 9 **True** positives and 1 **False** negative.

It was correct about the positive status of 9 people and incorrect about 1 of them, thus a **'False'** negative.

Now in the no cancer group ($n=990$), 89 of them get a **false** positive while the rest (901) get a **True** negative. 

Supposed now we speak with a woman from this sample. She said that her screening *detected* cancer. Since her test was positive she must be from the $9$ person real-cancer group or $89$ person non-cancer group.

$$P(\text{Has Cancer}\ |\ \text{positive test}) = \frac{9}{9+89} \approx \frac{1}{11}$$

See that $|C\cap \lnot C| = 9$ here.  
This $\frac{1}{11}$ is known as the Positive Predictive Value(PPV)

It gauges how accurate a positive result really is.
## Test Accuracy
Test Accuracy is measured by $2$ numbers
1. Sensitivity : The chance its correct on those with the disease
2. Specificity :  The chance its correct on those without the disease

In our case, 
Sensitivity: $\frac{9}{10} = 90\%$
Specificity: $\frac{901}{990} =91\%$

Now we can see the *paradox*. The test seems to be accurate as it has a $90\%$ rate of success but its PPV is a lowly $\frac{1}{11}$ 

$$\text{Accurate} \not\implies \text{Predictive}$$

We note that tests **are not** deterministic about tests.
Instead, they **update** your chances about having a disease. 

Suppose then the cancer we where screening for had a $1\%$ prevalence for that age group screened. This means before taking the test they had a $1\%$ of having the cancer. 

Now our screening has chanced those odds to $\frac{1}{11}$ if you had tested positive. 

The PPV represents the strength of the **updating** and not its overall predictive ability. 

# The Bayes Factor
How Strong is this **Updation**.

This is what the **Bayes Factor**(**BF**) measures. In this scenario the BF is measured by
$$
\frac{P(+ \ |\ \text{Cancer})}{P(+ \ |\ \text{No Cancer)}} = \frac{90\%}{9\%} = \boxed{10}
$$
The $+$ represents the screen saying the person has cancer. 

We take the BF and multiply it with the previous \% to get the new updated percent.

Recall that having this cancer was a $1\%$ chance, so taking the chance and seeing its positive increases by a factor(**BF**) of 10.
Meaning $\approx 10\%$

In this example, the BF examines this question:
> How much more likely is the test positive when you actually have the cancer?
> 
> In Other words: How much more likely are you able to see the positive test result with cancer than without
## Flaw
Suppose our prior (chance of cancer) was $10\%$. This meant of of a hundred sampled 10 **would** have the cancer.

Recall the test had a $90\%$ Sensitivity so 9 of them would be detected of the cancer and one would be misdiagnosed. 

The test also had a Specificity of $91\%$ meaning $9\%$ **False** positives ($8.1$ people).

This makes our PPV
$$\frac{9}{9+8}$$
and not $100\%$ like the BF would predict as we had a $10\%$ prior and then a Bayes Factor of 10. 

# Bayes Rule
We will shift from Probability to Odds. Odds represent events in ratios. Like $1:9$ odds means the event has a 10\% chance of happening.

Here are the odds at the start before the test:
$$\#\text{ With Cancer} : \#\text{ Without} \to \frac{\#\text{ With Cancer}}{\#\text{ Without Cancer}}$$
Then we filter down to those with positive test results:
The number of people will be scaled down:

$$\frac{\#\text{ With Cancer} \times P(+ \ | \ \text{Cancer})}{\#\text{ Without Cancer} \times P(+ \ | \ \text{No Cancer})}$$

Look at either the numerator for denominator: the values are being scaled by the probabilities from the test. These are the new **updated** odds of having cancer after taking the test. 

Notice the term $$\frac{P(+ \ | \ \text{Cancer})}{P(+ \ | \ \text{No Cancer})}$$

This is the Bayes Factor.

Lets go back to our 1000 person sample space where cancer prevalence was $1\%$
The ration cancer: without was $1:99$
We multiple this by the **BF**
$$(1:99)\times10=10:99$$
which is $\frac{10}{109}$

We can also explore the 100 person sample space with cancer odds at $10\%$ or $1:9$

$$(1:9)*10* = 10:9 = \frac{9}{19} \approx .53$$

## Negative Test Results
The Bayes Factor here will be:
$$\frac{P(- \ | \ \text{Cancer})}{P(- \ | \ \text{No Cancer})} = \frac{10\%}{91\%}$$

See that this negative result **lowers** your chance at cancer. 

# Overall Formula
$$O(D \ |\ +) = O(D)\frac{P(+ \ |\ D)}{P(+ \ |\ \lnot D)}$$

It says: 
> The odds of having the disease **given** a positive test result is the prior chance (pre-test) of having it, times the *Bayes Factor*.

For the common use formula see [[Bayes' Theorem]]

## Connection to The Main Formula
> Original Formula:
> $$P(A|B) = \frac{P(B|A)P(A)}{P(B|A)P(A)+P(B|\bar{A})P(\bar{A})}$$

Let $A$ be the event The Person has Cancer.
Let $B$ be the event The Test is Positive.

LHS : $P(A|B)$ asks about the Probability a person has cancer given the test is positive. 

The top of the fraction: $P(B|A)P(A)$ represents the scaling we talked about before. $P(B|A)$ gives the chance of a positive result given someone **does** have cancer and $P(A)$ just scales it to the sample size. 

The bottom is a bit more complex but not by much.
The first part: $P(B|A)P(A)$ is the same information as above. The $P(B|\bar{A})P(\bar{A})$ represents the **False** positives. $P(B|\bar{A})$ is the chance the test is triggered to be true when someone **does not** have the cancer. Then its scaled by that side of the same size $P(\bar{A})$.

This all boils down to:
$$\frac{\#\text{People correctly tagged with Cancer by Test}}{\#\text{People Tagged with Cancer}}$$