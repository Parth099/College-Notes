# The Vector Function

A Vector Function (*VF*) is defined as:
$$\vec{r}(t) = \langle \ f(t), g(t), h(t) \ \rangle$$

## The Limit of a VF

Notice that
$$\lim_{t \to a} \vec{r}(t) = \lim_{t \to a} \langle \ f(t), g(t), h(t) \ \rangle$$

$$ = \boxed{\langle \ \lim_{t \to a} f(t),\lim_{t \to a} g(t),\lim_{t \to a} h(t) \ \rangle}$$

## Derivatives & Integrals
Now we that we have show that the *limit* can be pushed inside the brackets 
$\dfrac{d}{dt} \& \large\int$ can be shown to do the same

### Derivatives
$$\dfrac{d\vec{r}}{dt} = \vec{r}^{\prime}(t) =\lim_{h \to 0} \frac{\vec{r}(t+h) - \vec{r}(t)}{h}$$

Now $\vec{r}^{\prime}(t)$ is know as the Tangent Vector.

The **Unit** Tangent Vector $T(t)$ is  $$T(t) = \frac{\vec{r}^{\prime}(t)}{|\vec{r}^{\prime}(t)|}$$

The rules for differentiation are the same for Vector addition and Scalar Multiples.

**New Rules**:
*$f(t)$ is a scalar function*

##### Product Rules
$\dfrac{d}{dt} f(t)\vec{u}(t) = f^{\prime}(t)\vec{u}(t) + f(t)\vec{u}^{\prime}(t)$

$\dfrac{d}{dt} \vec{u}\cdot\vec{v} = \vec{u}^{\prime}\cdot\vec{v} + \vec{u}\cdot\vec{v}^{\prime}$

$\dfrac{d}{dt} \vec{u}\times\vec{v} = \vec{u}^{\prime}\times\vec{v} + \vec{u}\times\vec{v}^{\prime}$

##### Chain Rule

$\dfrac{d}{dt} \vec{u}(f(t)) = \vec{u}^{\prime}(f(t)) * f^{\prime}(t)$

## Integrals

$$
\int_a^b \vec{r}(t)\mathop{dt} = 
(\int_a^b f(t)\mathop{dt})\vec{i} + 
(\int_a^b g(t)\mathop{dt})\vec{j} + 
(\int_a^b h(t)\mathop{dt})\vec{k}
$$

### ***FTOC***!

$$\int_a^b \vec{r}(t)\mathop{dt} = \vec{R}(t)\biggr\rvert_{a}^{b}$$