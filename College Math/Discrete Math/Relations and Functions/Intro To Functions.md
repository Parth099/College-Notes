# Intro To Functions
At first we will think of functions as relations. 

**Definition**:
Let $A, B$ be sets then a function $f$ with the domain in $A$ and range(image) in $B$. The function $f$ is a subset $A\times B$ with the following property:

For any $a\in A$, there exists **at most** $b\in B$ such that the pair $(a, b)\in f$

## Domain
The domain is defined by this set:
$$\{a\in A: \exists! b\in B \text{ s.t } (a, b)\in f\}$$

Notation: $\text{dom }f$ or $D_f$

> Recall that $\exists!$ represents "there exists only one"

## Range (Image)
The range is represented by the set 
$$\{f(a): a\in\text{dom }f\}\subseteq B$$

Notation: $\text{ran }f$ or $\text{im }f$

## Function Alternate Definition 
Often times we use this definition for functions:

A function $f$ is a mapping from a set $A$ to $B$
$$f:A\to B$$
Still $f\subseteq A\times b$ but now $D_f = A$
Now we can say the following:

$\forall a\in A, \exists!b\in B\text{ s.t }(a, b)\in f$

