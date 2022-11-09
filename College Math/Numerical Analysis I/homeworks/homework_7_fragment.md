| Name        | HW  |
| ----------- | --- |
| Parth Patel | $7$ | 

# Homework 7 
## Q8
$$
\begin{align}
f(x) &= \int_0^2 x^2e^{-x^2} \mathop{dx} \\
h &= 0.25 \implies n = 8
\end{align}
$$

The code for the below parts are attached on the lab submission. 

### Part 1 - Composite Trapezoidal rule
```matlab
>> format long e
>> f = @(x) (x.^2).*((exp(1).^(-(x.^2))));
>> a = 0;
>> b = 2;
>> n = 8;
>> comp_trap_rule(f, a, b, n)

ans =

     4.215820371981019e-01
```

### Part 2 - Composite Simpson's rule
```matlab
>> format long e
>> f = @(x) (x.^2).*((exp(1).^(-(x.^2))));
>> a = 0;
>> b = 2;
>> n = 8;
>> comp_simp_rule(f, a, b, n)

ans =

     4.227161879339765e-01
```

