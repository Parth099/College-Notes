# Checking Solutions

## Example 1
Ex  1 (first order):

$$
\begin{align}
y'+2y=0;\;y=3e^{-2x}
\end{align}
$$

Firstly see that $y'(x) = -6e^{-2x}$

Since, 

$$
( -6e^{-2x}) + 2(3e^{-2x}) = 0\ \checkmark
$$

$\boxed{3e^{-2x}}$ **is** a solution to the ODE $y'+2y=0$ .

## Example 2

$$
\begin{align}
y'' &= 9y \\ \\
y_1(x) &= e^{3x} \\
y_2(x) &= e^{-3x}
\end{align}
$$

Notice that **both** $y_1$ and $y_2$ **are** solutions to EX2.

## Example 3

$$
\begin{align}
y'' + 4y' + 4y &= 0 \\ \\
y_1(x) &= e^{-2x} \\
y_2(x) &= xe^{-2x}
\end{align}
$$

Derivatives:

$$
\begin{align}
y_1'(x) &= -2e^{-2x} \\
y_1''(x) &= 4e^{-2x}
\end{align}
$$

Subbing in:

$$
4e^{-2x} + 4(-2e^{-2x}) + 4(e^{-2x}) = 0\ \checkmark
$$

Derivatives:

$$
\begin{align}
y_2'(x) &= e^{-2x} - 2xe^{-2x} = [1-2x]e^{-2x}  \\
y_2''(x) &= -2e^{2x} + [4x-2]e^{-2x} = 4(xe^{-2x} - e^{2x})
\end{align}
$$

Subbing in:

$$
4(xe^{-2x} - e^{2x}) + 4([1-2x]e^{-2x}) + 4xe^{-2x} = 0\ \checkmark
$$