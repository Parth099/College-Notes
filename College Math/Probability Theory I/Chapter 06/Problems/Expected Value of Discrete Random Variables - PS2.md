# Expected Value of Discrete Random Variables - PS1
## 1
![[cp6_2p1.png]]
$$E(X) = -1\frac{1}{3} + 0\frac{1}{3} + 1\frac{1}{3} = 0$$

$$E(X^2) = 1\frac{1}{3} + 0\frac{1}{3} + 1\frac{1}{3} = \frac{2}{3}$$

$$V(X) = E(X^2) - \mu^2 = \frac{2}{3}$$

$$D(X) = \sqrt{V(X)} = \sqrt{2/3}$$

## 2
Find $E(X), V(X), D(X)$ if
$$
p_X = \begin{pmatrix}        
        0 & 1 & 2 & 4\\      
        1/3 & 1/3 & 1/6 & 1/6
\end{pmatrix}
$$

**Expected Value**
$$
\begin{align}
	E(X) &= \frac{1}{3}0+\frac{1}{3}1+\frac{1}{6}2+\frac{1}{6}4 \\
	&= \frac{4}{3}
\end{align}
$$

**Variance \& Deviation** 
$$
\begin{align}
	E(X^2) &= \frac{1}{3}0+\frac{1}{3}1+\frac{1}{6}2^2+\frac{1}{6}4^2 \\
	&= \frac{11}{3}

\\\\
	V(X) &= E(X^2) - E(X)^2 \\
	     &= 33/9 - 16/9   \\ \\
		 &= \boxed{\frac{17}{9}}
	\\\\
	\implies D(X) &= \frac{\sqrt{17}}{3} 
\end{align}
$$

## 4
![[cp6_2p4.png]]
### (a)
$$
\begin{align}
	V(X) &= E(X^2) - \mu^2 \\
	E(X^2) &= V(X) + \mu^2 \\
		   &= 15 + 100^2 = 10015	
\end{align}
$$
---
### (b)
$$
\begin{align}
	E(3X + 10) &= 3E(X) + 10 \\
		   &= 300 + 10 = 310	
\end{align}
$$
---
### (c)
$$E(-X) = -E(X) = -100$$

---
### (d)
$$
\begin{align}
	\text{Recall } \ V(X) &= E(X^2) - [E(X)]^2\\
	\\
	V(-X) &= E((-X)^2) - [E(-X)]^2 \\
		  &= E(X^2) - [-E(X)]^2 \\
		  &= E(X^2) - E(X)^2 \\
		  
	\\
	\text{Hence, } V(-X) &= V(X)
\end{align}
$$
The answer for this specific instance is then $15$

---
### (e)
We can apply the same logic as above for $\sqrt{V(X)}$ under the sqrt operator. 
$$D(-X) = D(X) = \sqrt{15}$$

---
## 7
![[cp6_2p7.png]]
$$X = 
\begin{pmatrix}  
	0 & 1 & 2 & 3\\  
	\frac{1}{8}  & \frac{3}{8}  & \frac{3}{8}  & \frac{1}{8} 
\end{pmatrix}
$$

Then
$$
\begin{align}

E(X) &= 0\frac{1}{8} + 1\frac{3}{8} + 2\frac{3}{8} + 3\frac{1}{8} = \frac{3}{2}  \\ \\

E(X^2) &= 0\frac{1}{8} + 1\frac{3}{8} + 4\frac{3}{8} + 9\frac{1}{8} = 3  \\ \\

	V(X) &= E(X^2) - E(X)^2 \\
		 &= 3 - (3/2)^2 \\
		 &= 3 - \frac{9}{4} \\
		 &= .75
		 
		 \\ \\
		 
	D(X) = \sqrt{V(X)} &= \sqrt{\frac{3}{4}} \\
	                   &= \frac{\sqrt{3}}{2}
\end{align}
$$

## 10 - 12
![[cp6_2p10p11p12.png]]

### 10
$$
\begin{align}
	D(X+c) &= \sqrt{V(X+c)} = \sqrt{V(X)} = D(X) 
	\\
	D(cX)  &= \sqrt{V(cX)} = \sqrt{c^2V(X)} = |c|D(X)
\end{align}
$$
### 11
#### Expected Value $\mu$
$$
\begin{align}
	E(X) &= \sum_{x} xP(X = x) \\
	     &= \sum_{k = 1}^n k\cdot P(X = k) \\
		 &= \sum_{k = 1}^n k\cdot \frac{1}{n} \\
		 &= \frac{1}{n}\sum_{k = 1}^n k \\ \\
		 &= \frac{1}{n}\frac{n(n+1)}{2} \\ \\
		 &= \frac{n+1}{2}
\end{align}
$$
#### Variance $\sigma^2$
$$
\begin{align}
	V(X) = E(X^2) - \mu^2
\end{align}
$$
We need $E(X^2)$
We need to use a theorem from [[Expected Value of Functions of Random Variables]]

$$
\begin{align}
	E(X^2) &= \sum_{x} x^2 P(X = x) \\
		   &= \sum_{k = 1}^n k^2 \frac{1}{n} \\	
		   &= \frac{1}{n} \sum_{k = 1}^n k^2  \\
		   &= \frac{1}{n} \frac{n(n+1)(2n+1)}{6}  \\
		   &= \frac{(n+1)(2n+1)}{6}  \\
\end{align}
$$

Now we can attain $V(X)$
$$
\begin{align}
	V(X) &= \frac{(n+1)(2n+1)}{6} - (\frac{n+1}{2})^2 \\ \\
	     &= \frac{(n+1)(2n+1)}{6} - \frac{(n+1)^2}{4} \\ \\
		 &= \frac{2(n+1)(2n+1) - 3(n+1)^2}{12} \\ \\
		 &= \frac{(n+1)[2(2n+1) - 3(n+1)]}{12} \\ \\
		 &= \frac{(n+1)(n-1)}{12}
\end{align}
$$

### 12
$$
X^{*} = \frac{X-\mu}{\sigma}
$$

**Expected Value**
$$
\begin{align}
	E(X^{*}) &= E\biggr(\frac{X-\mu}{\sigma}\biggr) \\
	&= \frac{1}{\sigma}E(X - \mu) \\
	&= \frac{1}{\sigma}\biggr[E(X) - \mu\biggr] \\
	&= 0
\end{align}
$$

**Variance**

$$
\begin{align}
	V(X^*) &= E\biggr((X^* - \mu^*)^2\biggr)
	\\
	&= E([X^*]^2)
	\\
	&= E\biggr([\frac{X-\mu}{\sigma}]^2\biggr)
	\\
	&= \frac{1}{\sigma^2}E\biggr([{X-\mu}]^2\biggr)
	\\
	&= \frac{1}{\sigma^2}V(X)
	\\
	&= \mathbf{1}
 
\end{align}
$$