# Time Rate of Change
> How some quantity changes as it relates in time. 

$$
\begin{align}
P &= \text{Population}\\ t &= \text{Time}
\end{align}
$$

$$
\dfrac{dP}{dt} \leftarrow \text{the way the population is changing WRT time}
$$

Often times $\dfrac{dP}{dt}$ depends on the number of people alive. 

If $\dfrac{dP}{dt}$ is said to be proportional to the people alive then $\dfrac{dP}{dt} = kP$ .

The (*given*) solution is $P(t) = Ce^{kt}$ .

Let $t_0 = 1000$ (pop. count)

$$P(t_0) = P(0) = 1000 \implies C = 1000$$

Suppose $t_1 = 3000$ (after 1 year population tripled)

$$
P(1) = 1000e^{k} = 3000 \implies k = \ln 3
$$

This means that the particular solution is: 

$$
P(t) = 1000e^{k\ln3} = 1000(e^{\ln 3})^t = 1000(3^t)
$$

> We can use this to predict the population in $t$ years