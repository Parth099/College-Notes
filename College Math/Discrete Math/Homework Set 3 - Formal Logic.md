# Chapter 1
## Section 7 Day 1
##### 7.3
> Show the two props are the same
> $$(x \land y) \lor (x \land \lnot y) \text{ and } x$$

| $x$ | $y$ | $x \land y$ | $x \land \lnot y$ | $(x \land y) \lor (x \land \lnot y)$ |
| --- | --- | ----------- | ----------------- | ------------------------------------ |
| $T$ | $T$ | $T$         | $F$               | T                                    |
| $T$ | $F$ | $F$         | $T$               | T                                    |
| $F$ | $T$ | $F$         | $F$               | F                                    |
| $F$ | $F$ | $F$         | $F$               | F                                    | 

##### 7.4
> Show 
> $$x\to y \equiv \lnot y\to\lnot x$$

| $x$ | $y$ | $x\to y$ | $\lnot y\to\lnot x$ |
| --- | --- | -------- | ------------------- |
| T   | T   | T        | T                   |
| T   | F   | F        | F                   |
| F   | T   | T        | T                   |
| F   | F   | T        | T                   | 

##### 7.10 Disproving Logical Equivalences
###### 7.10.a
> Disprove
> $$x\to y\equiv y\to x$$

Let $x$ = $T$ and $y$ = $F$
Then: 
$$
\begin{align*}
	x \to y &\equiv F \\
	y \to x &\equiv T
\end{align*}
$$
Since they aren't equal for the same values of $(x, y)$ they simply are **not** equivalences.

###### 7.10.b
> Disprove
> $$x\to y\equiv x \leftrightarrow y$$

They aren't equal when 
$$
\begin{align*}
	x&=F\\
	y&=T\\\\
	x \to y &\equiv T \\
	x \leftrightarrow y &\equiv F
\end{align*}
$$

###### 7.10.c
> Disprove
> $$x\lor y\equiv (\lnot x \land y)\lor(x \land \lnot y)$$

$$
\begin{align*}
	x&=T\\
	y&=T\\\\
	x\lor y &\equiv T \\
	(\lnot x \land y)\lor(x \land \lnot y) &\equiv F
\end{align*}
$$

## Sec 7 Day 2
##### 7.5
> Show
> $x \leftrightarrow y \equiv \lnot x \leftrightarrow \lnot y$

Know:
$$x \leftrightarrow y \equiv (x\to y) \land (y \to x)$$

RHS:
$$\lnot x \leftrightarrow \lnot y \equiv (\lnot x\to \lnot y) \land (\lnot y \to \lnot x)$$

Apply Contrapositive to both sides of RHS:
$$x \to y \equiv \lnot y \to \lnot x$$
This means
$$
\begin{align*}
	\lnot y \to \lnot x &\equiv x \to y\\
	\lnot x \to \lnot y &\equiv y \to x\\
\end{align*}
$$
Sub back in:
$$\lnot x \leftrightarrow \lnot y \equiv (\lnot x\to \lnot y) \land (\lnot y \to \lnot x)$$
$$\lnot x \leftrightarrow \lnot y \equiv (x \to y) \land (y \to x)$$
This is the same as the LHS
$$\boxed{\lnot x \leftrightarrow \lnot y \equiv x \leftrightarrow y}$$
##### 7.7
> Show 
> $$x \leftrightarrow y \equiv (x\to y) \land (\lnot x \to \lnot y)$$

We know that $(1)$:
$$x \leftrightarrow y \equiv (x\to y) \land (y \to x)$$

We also know this via Contrapositive
$$x \to y \equiv \lnot y \to \lnot x$$

We can apply the Contrapositive to the 2nd part of $(1)$
$$y \to x \equiv \lnot x \to \lnot y$$

Sub it back in: 
$$x \leftrightarrow y \equiv \boxed{(x\to y) \land (\lnot x \to \lnot y)}$$