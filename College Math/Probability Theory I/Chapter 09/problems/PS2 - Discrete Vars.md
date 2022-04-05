# PS2 - Discrete Vars
## 1
![[cp9_2p1.png]]
$$\text{Let }S_{24} = \sum_{i = 0}^{24} X_i$$
$X_i$ represents a individual dice roll. Then: 

Part *a*:
$$
\begin{align}
	E(S_{24}) &= 24 * \frac{7}{2} = 84\\
	V(S_{24}) &= 24 * \frac{35}{12} = 70\\
	D(S_{24}) &= \sqrt{70}  \\
\end{align}
$$


We need $P(S_{24} \gt 84)$
$$
\begin{align}
	P(S_{24} \gt 84) &\approx P(S^*_{24} \geq \frac{84 - 84 + \frac{1}{2}}{\sqrt{70}} = 0.06) \\
	&\approx 0.5 - NA(0.06) \\
	&\approx 0.476
\end{align}
$$

Part *b*:
$$
\begin{align}
	P(S_{24} = 84) &\approx \frac{P(S^*_{24} = \frac{84-84}{\sqrt{70}} = 0)}{\sqrt{70}}
	\\
	&= \frac{\phi(0)}{\sqrt{70}} \\
	&= 0.0477
\end{align}
$$

## 3
![[cp9_2p2.png]]

$$S_{100} = \sum_{i = 1}^{100}\text{strand}_i$$

Each strand has $\sigma = 1$. Thus $\sigma^2 = 1$. Due to the fact its an **independent** trials process, the variance adds linearly. Thus $V(S_{100}) = 100$ and subsequently, $D(S_{100}) = 10$

$$
\begin{align}
P(S_{100} \geq 1000) &\approx P(S^*_{100} \lt 0)\\&\approx 0.52 \\

P(S_{100} \geq 970) &\approx P(S^*_{100} \geq \frac{970-\frac{1}{2}-1000}{10})\\ &= 0.5+\text{NA}(0, -3.05) \\
&=0.9988
\end{align}
$$

## 5
![[cp9_2p5.png]]
### a
If more than 210 tosses are required than this means the sum $S_{210} \leq 700$

Note each roll has $\mu = \frac{7}{2}$, $\sigma^2 = \frac{35}{12}$

For $210$ **independent** rolls, 
$$
\begin{align}
	E(S_{210}) &= 735\\
	V(S_{210}) &= 612.5\\
	D(S_{210}) &= \sqrt{612.5}
\end{align}
$$

$$
\begin{align} 
	P(S_{210} \lt 700) \to P(S^*_{210} \lt -1.43) = 0.07572
\end{align}
$$

### b
If less than 190 tosses are required this means by the $189$-th roll the sum $S_{189}$ is $\geq$ 700

For $189$ **independent** rolls, 
$$
\begin{align}
	E(S_{189}) &= 661.5\\
	V(S_{189}) &= 551.25\\
	D(S_{189}) &= \sqrt{551.25}
\end{align}
$$

$$P(S_{189} \geq 700) = P(S^*_{189} \geq 700) = 0.05278$$

### c
To be under $210$ we need  $\geq700$ by the time we roll $210$ times. To be over $179$ rolls we need $\lt 700$ by roll $179$:

$$P(S_{179} < 700, S_{210} \geq 700)$$

<!-- TO BE FINISHED -->

