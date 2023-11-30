# Midterm Note Sheet

## Terms
+ **Field** - $\forall 0_R\neq b\in R: \exists b^{-1} \in R$
+ **Integral Domain** - Non zero commutative ring where for any ***non-zero*** $a, b \in R: a\cdot b \neq 0_R$
	+ Implies no zero divisors
	+ "cancellable" multiplication under non-zero conditions
	+ ***T:*** Each *finite* ID is a **Field**.
+ **monomorphism** - injective (*1\:1*) homomorphism
+ **epimorphism** - surjective (*onto*) homomorphism
+ **Ring Unit** - An element in the ring where its multiplicative inverse also exists in the ring.

**Multiplying Polynomials**

$$
fg = \sum_{i\geq 0}\biggr[ \sum_{j,k\geq 0;\ j+k=i} a_jb_k \biggr]x_i
$$

## Core Topics
### Subrings

To show that $S$ is a subring of $R$ you need to ensure

1. $S \neq \emptyset$
2. $S \subseteq R$
3. $0_R \in S$ and $1_R \in S$
4. $S$ is **closed** under *subtraction* and *multiplication*


Note about Homomorphism of rings: Let $f: R\to S$ be a homomorphism of rings. Then $\text{im} f$ is a subring of $S$ .

### Ring Homomorphisms

Let $R$ and $S$ be rings. Then a function $f: R\to S$ is a homomorphism if:

1. $f(1_R) = 1_S$
2. $f(a+b)=f(a)+f(b)$
3. $f(ab) = f(a)f(b)$

for any $a, b \in R$

### Associates in Rings

#### Preface 

1. $aR=auR$ for $u$ a unit.
2. $b|a \iff bv|au$ where $v, u \in R$ units.

--- 

> Association is a *equivalence relation*.

Elements $r$ and $s$ in $R$ are associates if there exists a unit $u$ such that $$r=us$$ 

### Irreducibility


#### General Rings
Let $R$ be an integral domain (ID). 

***T:*** An element $r \in R$ is called irreducible if $r \neq 0$ and $r \not \in R^{\times}$ and $r$ only has the trivial divisors. 

Notice by the above definition the trivial divisors are associates of $1$ and $r$ :

+ All $1_Ru$ for $u\in R^\times$
+ All $ru$ for $u\in R^\times$


***T:*** $r \in R$ is irreducible if
+ $r \neq 0_R,\, r\not\in R^\times$
+ Whenever $r=ab$ (factored) one of $a$ or $b$ is a unit.
 
#### Polynomial Rings

The following is equivalent to saying $0 \neq f\in F[x]$ is irreducible. 

**IMPORTANT**: $f$ is required to be non-constant

1. The only monic divisors are $1_F$ and $\tilde{f}$ 
2. For all factorizations $f=ab$ , either $a$ or $b$ is a constant (units: $F^\times$ )
3. $f$ cannot be factored into two other polynomials with both lower degree
4. For any $a\in F[x]$, $f\nmid a \implies (a, f)=1$
5. $f|ab \implies f|a \text{ or } f|b$  



