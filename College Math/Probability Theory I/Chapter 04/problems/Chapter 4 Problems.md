# Chapter 4 Problems
Goals: 1, 6, 7, 8, 12, 14, 16, 17, 24, 25, 36
## 1
![[c4p1.png]]
Know:
$$P(E|F) = \frac{P(E\cap F)}{P(F)}$$
Then:
$$
\begin{align*}
 	P(E|F) &= P(E) \\
	\frac{P(E\cap F)}{P(F)} &= P(E) \\
	P(E\cap F) &= P(F)P(E) \\
\end{align*}
$$
Apply to $P(F|E)$
$$
\begin{align*}
	P(E\cap F) &= P(F)P(E) \\
	P(F|E) &= \frac{P(E\cap F)}{P(E)} \\
	P(F|E) &= \frac{P(F)P(E)}{P(E)} \\
	
	\\\\
	P(F|E)&=\boxed{P(F)}{}
\end{align*}
$$
## 6
![[c4p6.png]]

Used weird notation to fit $P(p)$ notation
Need $P(2_2|12_\sum)$

$$P(2_2|12_\sum) = \frac{P(2_2 \cap 12_\sum)}{P(12_\sum)}$$
This is a uniform distribution
$$\implies \frac{|2_2 \cap 12_\sum|}{|12_\sum|}$$

Ways to make 12 from 3 picks (order irrelevant) is 10
```python
[(2, 2, 8), (2, 4, 6), (2, 6, 4), (2, 8, 2), (4, 2, 6), (4, 4, 4), (4, 6, 2), (6, 2, 4), (6, 4, 2), (8, 2, 2)]
```
for 2, 2 and c we can only have $c = 8$.
There are $3!/2!$ or $6$ arrangements here

$P(2_2|12_\sum) = \frac{3}{10}$
## 7
![[c4p7.png]]
$$
\begin{align*}
	\Omega &= \{HH, HT, TH, TT\} \\
	A &= \{HH, HT\} \\
	B &= \{HH, TH\} \\
	C &= \{HH, TT\} \\
	\\
	A \cap B &= \{HH\}\\
	A \cap C &= \{HH\}\\
	B \cap C &= \{HH\}\\
\end{align*}
$$
Pairwise Independence: Any 2 events is independent. Recall from [[Independent Events]] this means:
$$P(X\cap Y)=P(X)P(Y)$$
We can see from the table above its *clearly* true.
### $C$ is independent of $A$ and $B$ 
$$P(C|A) = \frac{P(C \cap A)}{P(A)} = \frac{1/4}{1/2} = \frac{1}{2} = P(C)$$

$B$ goes the same way.
## 8
![[c4p8.png]]
The first part:
$$
\begin{align*}
	A \cap B \cap C &= \{a\} \implies P(\{a\}) = \frac{1}{8}\\
	P(A) &= \frac{2*3}{16} + \frac{1}{8} = \frac{1}{2}\\
	P(A) = P(B) = P(C) &= \frac{1}{2}
	
	\\\\
	&\boxed{P(A \cap B \cap C) = \frac{1}{8} = \frac{1}{2}\frac{1}{2}\frac{1}{2}}
\end{align*}
$$

## 12
![[c4p12.png]]
### Example 4.17
A doctor is testing for cancer. The case rate in average people is only $\frac{1}{1000}$. In 99% of cases where cancer is not present the test is correct, for people who do have cancer the test is 95% correct. How strong is this update?

Let $C$ be the event a person has cancer.
$$
\begin{align*}
P(\text{Prior}) &= 0.001\\
P(\text{+|{C}}) &= .95 \\
P(\text{+|}\lnot\text{{C}}) &= .05\\
\end{align*}
$$
What we want is $P(\text{C|+})$ via Bayes Formula

$$P(\text{C|+}) = \frac{P(\text{+|{C}})P(\text{Prior})}{P(\text{+|{C}})P(\text{Prior})+P(\text{+|}\lnot\text{{C}})P(\lnot\text{Prior})}$$
Eval the formula and we see that:
$$P(\text{C}|+) = 0.01866\dotso$$
The strength of the update is around $19$(See Bayes Factor in [[3b1b - Redesigning Bayes' rule]]).

We need to alter the $P(C)$ to get $P(C|+)$ to $\approx .5$
Lets first note that the Bayes factor here is
$$\frac{P(+|C)}{P(+|\lnot C)} = 19$$
This means our test increases our test chances by 19 times.
Recall the original odds were $1:999$ or $\frac{1}{1+999}$
%%Finish up%%

## 14
![[c4p14.png]]
$$P(A|B) = \frac{P(A\cap B)}{P(B)} \to P(A|B)P(B) = P(A\cap B)$$
$$P(B) = 1 - P(\lnot B) \implies P(B) = \frac{3}{4}$$
$$\text{Ans: }\boxed{3/8}$$
## 16
![[c4p16.png]]
$$P(A)\frac{P(A\cap B)}{P(A)}\frac{P(A \cap B \cap C)}{P(A\cap B)} = P(A \cap B \cap C)$$
## 17
![[c4p17.png]]
### A:
$$P(A \cap \lnot B) = P(A) - P(A\cap B)$$

This is because:
$$A \cap \lnot B = A - (A \cap B)$$
![[c4p17_aid_A.png]]
See that $\lnot B = U - B \to A \cap (U - B)$
Work:
$$
\begin{align*}
P(A \cap \lnot B) &= P(A) - P(A\cap B)\\
&= P(A) - P(A)P(B) \\
&= P(A)(1 - P(B)) \\
&= P(A)P(\lnot B) \implies \text{Independent}
\end{align*}$$

### B
![[c4p17_aid_B.png]]
$$
\begin{align*}
P(\lnot A \cap \lnot B) &= P(U) - P(A) - P(B) - P(A\cap B) \\
&=[ 1 - P(A) ] - P(B) - P(A)P(B)\\
&=P(\lnot A) - P(B)(1 - P(A)) \\
&= P(\lnot A) - P(B)P(\lnot A) \\
&= P(\lnot A)(1 - P(B)) \\
&= P(\lnot A)P(\lnot B) \implies \text{Independent}
\end{align*}
$$
## 24
![[c4p24.png]]
$$P(k \text{ heads}) = b(n, \frac{1}{2}, k) = (\frac{1}{2})^{n-k} (\frac{1}{2})^k \binom{n}{k} = (\frac{1}{2})^n\binom{n}{k}$$
This is a Bernoulli Trials Process

$$P(\text{Heads on trial number } j) = \frac{1}{2}\times b(n-1, \frac{1}{2}, k-1)$$
We need the previous $k-1$ to be heads and then the next one to be heads $p = .5$.

%%finish up%%