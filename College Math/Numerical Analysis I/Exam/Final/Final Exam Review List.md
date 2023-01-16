# Final Exam Review List
## Chapter 1
+ Errors
	+ Actual Error
	+ Absolute Error
	+ Relative Error
+ Finite Digit Arithmetic - Rounding
	+ Chopping 
	+ Rounding
+ Algorithmic Convergence 
	+ $f(h) \in O(h^k) \implies f$ converges to its limit $L$ at a rate proportional to $h^k$ as both approaching $h=0$
	+ $g(n) \in O(\frac{1}{n^p}) \implies g$ converges to $0$ at  a rate proportional to $1/n^p$ when $n\to\infty$

**Taylor's Theorem**:

$$
f(x) = 
\biggr[\sum^{n}_{k=0} \frac{f^{(k)}(x_0)}{k!}(x-x_0)\biggr] +
\frac{f^{n+1}(\xi(x_0))}{(n+1)!}(x - x_0)^{n+1}
$$

For $\xi(x)$ between $x$ and $x_0$

## Chapter 2
1. Bisection Method (root finding)
2. Fixed Point Iteration
3. Newtons Method / Secant Method (root finding)
4. Order of Convergence

## Chapter 3
1. Lagrange Interpolation
2. Hermite Interpolation
3. Divided Differences
4. Splines

## Chapter 4
1. Numerical Differentiation
	1. Midpoint three point
	2. Endpoint three point
	3. Second Derivative Midpoint
2. Numerical Integration
	1. Trapazodial Rule
	2. Simpsons
	3. Composite (1) and (2)

## Chapter 5
1. Forwards Eular's Method
2. Backwards Eular's Method

## Chapter 6
1. Basic Linear (Gaussian Elim)
2. $LU$ Factorization
3. Partial Pivoting and $PA = LU$ Factorization

## Chapter 7
1. Vector Norms
2. Matrix Norms
3. Iterative Matrix Methods
	+ Jacobi Method
	+ Gauss-Seidel Method

## Chapter 8
1. Least Squares - Curve Fitting