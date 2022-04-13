# Ergodic and Regular Markov Chains
## Limits of Matrix Powers
### Example 1
$$
\mathbf{A} = 
\begin{pmatrix}
        1 & 1\\
        1 & 1  
\end{pmatrix}  
$$

Notice that 
$$
\mathbf{A}^n = {
	\begin{pmatrix}
			2^n & 2^n\\
			2^n & 2^n 
	\end{pmatrix}
}
$$

$$\lim_{n\to\infty}A^n = \text{DNE}$$

### Example 2
$$
\mathbf{B} = \begin{pmatrix}
        1 & 1\\
        1 & -1
\end{pmatrix}
$$

$$
\begin{align}
\mathbf{B}^2 &= \begin{pmatrix}2&0\\0&2\end{pmatrix} \\
\\
\mathbf{B}^3 &= \begin{pmatrix}2&2\\2&-2\end{pmatrix} \\
\\
\mathbf{B}^4 &= \begin{pmatrix}4&0\\0&4\end{pmatrix} \\
\end{align}
$$

Not only does it have an alternating pattern the numbers internally do not converge.
$$\lim_{n\to\infty}\mathbf{B}^n = \text{DNE}$$

### Example 3 : Absorbing Chain 
$$
\mathbf{C} = \begin{pmatrix}
        1/2 & 1/2\\
        0 & 1
\end{pmatrix}
$$

$$
\begin{align}
\mathbf{C}^2 &= \begin{pmatrix}\frac{1}{4}&\frac{3}{4}\\ 0&1\end{pmatrix} \\
\\
\mathbf{C}^3 &= \begin{pmatrix}\frac{1}{8}&\frac{7}{8}\\ 0&1\end{pmatrix} \\
\\
\mathbf{C}^4 &= \begin{pmatrix}\frac{1}{16}&\frac{15}{16}\\ 0&1\end{pmatrix} \\
\end{align}
$$

Generally
$$
\mathbf{C}^n = \begin{pmatrix}\frac{1}{2^n}&1-\frac{1}{2^n}\\ 0&1\end{pmatrix}
$$

Then, 
$$
\lim_{n\to\infty} \begin{pmatrix}\frac{1}{2^n}&1-\frac{1}{2^n}\\ 0&1\end{pmatrix} = \begin{pmatrix}0&1\\0&1\end{pmatrix}
$$

### Example 4 : Regular Chain 
$$
\mathbf{D} = \begin{pmatrix}1/4&3/4\\ 3/4&1/4\end{pmatrix}
$$

$$
\begin{align}
\mathbf{D}^2 &= \begin{pmatrix}\frac{5}{8}&\frac{3}{8}\\ \frac{3}{8}&\frac{5}{8}\end{pmatrix} \\
\\
\mathbf{D}^3 &= \begin{pmatrix}\frac{7}{16}&\frac{9}{16}\\ \frac{9}{16}&\frac{7}{16}\end{pmatrix} \\
\\
\mathbf{D}^4 &= \begin{pmatrix}\frac{17}{32}&\frac{15}{32}\\ \frac{15}{32}&\frac{17}{32}\end{pmatrix}
\end{align}
$$


Then, 
$$
\lim_{n\to\infty} \mathbf{D}^n = \begin{pmatrix}\frac{1}{2}&\frac{1}{2}\\\frac{1}{2}&\frac{1}{2}\end{pmatrix}
$$

### Example 4 Via Theorem \"Shortcut\"

$$
\mathbf{P} = \begin{bmatrix}1/4&3/4\\ 3/4&1/4\end{bmatrix} , \: \vec{w} = [\:w_1 \:\: w_2\:]
$$

Recall that $\vec{w}\mathbf{P} = \vec{w}$
Thus
$$
\begin{bmatrix}1/4&3/4\\ 3/4&1/4\end{bmatrix}\cdot[\:w_1 \:\: w_2\:]
$$

From this we know that
$$
\begin{align}
\frac{1}{4}w_1 + \frac{3}{4}w_2 &= w_1\\
\\
\frac{3}{4}w_1 + \frac{1}{4}w_2 &= w_2\\
\end{align}
$$

Suppose $w_1 = 1$, then by elimination $w_2 = 1$

Now we know that $[\:1\:1\:]\mathbf{P} = [\:1\:1\:]$

Since we know that $w_1 + w_2 = 1$ ($\vec{w}$ is a probability  vector.) We can make all our entries sum to one by dividing each entry by the total sum of $2$. 

Thus, $\vec{w} = [\:1/2\:\:1/2\:]$

Finally we know that for $n\to\infty$
$$
\mathbf{P}^n \to \begin{bmatrix}\frac{1}{2}&\frac{1}{2}\\\frac{1}{2}&\frac{1}{2}\end{bmatrix}
$$