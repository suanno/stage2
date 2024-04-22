# Investigating possible oscillations of kink's position (1D) when PBC boundaries are applied

**Resumee**: At least in 1D, we see oscillations of the measured kink position whose amplitude depends on the choice of the integration step $dx$.
This means that those oscillations are **only due to** a **numerical discretization**.

In addition, form our theory we do not predict **any** oscillations, at least for slow varying $C(t)$ and using PBC.

----------------------------- 

# Analytical considerations

**To say first**: We know, at least for constant / very slow varying $C(t)$, that
$$u(x,t) = C(t)^\frac12 \tanh ((x-x_0)\sqrt{\frac{C(t)}{2}})$$
is a **stationary solution** $\forall x_0$.
**But** we find this result without applying boundary conditions!
So it is worth thinking about what happens to $x_0$ if we apply boundary conditions.

------------------------

$$\partial_t u = \partial_{xx} u + C(t)u - u^3$$

Let's define the quantity 
$$l(t) = \int_{-\frac{L}{2}}^{+\frac{L}{2}} u(x,t) dx$$
We expect that, for simmetry reasons, that the kink function preserves its oddness respect to the kink position. So the evolution of $l(t)$ will describe the evolution of the kink position $x_0$.
This quantity is independent from the evolution of the kink's height/width due to its oddness (respect to $x_0$). 

If we integrate the TDGL equation in $dx$ we get
$$\partial_t l = \int_{-\frac{L}{2}}^{+\frac{L}{2}} \partial_x(\partial_x u) dx + C(t) l - \int_{-\frac{L}{2}}^{+\frac{L}{2}} u^3 dx$$

By **using the PBC**, the **integral of the laplacian is zero!!!**
So we are left with this equation
$$\partial_t l = C(t) l - \int_{-\frac{L}{2}}^{+\frac{L}{2}} u^3 dx$$

Now, if you consider this shape for the kink function
$$u(x,t) = C(t)^\frac12 \tanh ((x-x_0)\sqrt{\frac{C(t)}{2}})$$
that is a good approximation if $C(t)$ is slow varying, as this is a stationary state for $C$ constant **without applying boundary conditions**, then **both**

$$C(t)u\sim C^\frac32$$
$$u^3\sim C^\frac32$$

So, to investigate the sign of $\partial_t$, we just focus on the sign of
$$\int \tanh((x-x_0)\sqrt{\frac{C(t)}{2}}) - \tanh^3((x-x_0)\sqrt{\frac{C(t)}{2}})$$

Let's call $f(x,t) = \tanh((x-x_0)\sqrt{\frac{C(t)}{2}})$, then
$$x > x_0 \implies f^3 > f$$
$$x < x_0 \implies f^3 < f$$

As a consequence,

$$x_0 < 0 \implies \int f^3 > \int f$$
$$x_0 > 0 \implies \int f^3 < \int f$$

So, if $C(t) > 0$

$$sign(\partial_t l) = sign(x_0)$$

in general

$$sign(\partial_t l) = sign(x_0)sign(C(t))$$


And $l > 0$ means that $[C(t) < 0, x_0 > 0]$ or $[C(t) > 0, x_0 < 0]$, because $\tanh(-\infty) = -1$.

So
$$sign(\partial_t l) = -sign(l)$$

This means that eventually $l\rightarrow 0$ **without making a singke oscillation**!

## Analytical conclusion

**We conclude** that, at least if
- $C(t)$ is slowly varying in time (so we can assume adiabaticity: following of the $C(t)$ stationary state).
- We adopt PBC boundary conditions.

Then the kink position $x_0$ tends to reach $x_0 = 0$ **without making oscillations**.
So, after applying PBC boundaries, we have less stationary state ($x_0$ is no more arbitrary, but can only take the value 0).

**No oscillations** of $x_0$ are predicted, **both if** its initial value is already zero or no, as 
$$sign(\partial_t l) = -sign(l)$$


# Measuring kink position's oscillation

Let's consider as the initial state a _single kink function_ (it does not match the PBC boundaries, but after a transient a new kink will appear at the border in order to satisfy the PBC conditions)

$$u(x,t=0) = \tanh((x-x_0)2^{-\frac12})$$

So we're considering the stationary state _for constant_ $C=1$ as the initial state. 

We can **monitor the position of the interface** in two ways
- By extimating, at each time t, the $x$ value such that $u(x) = 0$.
- Or by calculating, at each time, the integral
    $$I=\int_0^L \frac12(u(x,t) + 1) dx = \frac12(<u> + L)$$
    The idea of this integral is clear if you think to integrating the initial state.
    The +1 shift the $\tanh $ such that the -1 plateau becomes a 0 plateau and so does not contribute to the integral. While the $\frac12$ makes the +1 plateau still +1 and not +2.

    ## Why this measures kink position oscillations?
    So this is the area under the +1 domain.
    If the kink position is $x_0 = \frac{L}{2}$, then by **oddness of the kink function** respect to the kink (**we EXPECT** that a **kink** function has this **propery**: it is an _assumption_ based on simmetries)
    $$\int_0^L u(x)|_{x_0=\frac{L}{2}} dx = 0$$
    **Notice that**: this is true **even if** you consider a **different amplitude or width of the kink function** (it is not necessary to work with the stationary state of $C=1$!!!)

    **In conclusion** this integral is **independent from** the evolution of the **height/width** of the kink, **while** it **depends on the kink position**, as the extrema of integration are still $(0, L)$ even though $x_0\neq \frac{L}{2}$!

    So its evolution in time reflects the one of the kink position $x_0$.
    If the kink position is constant and $x_0 = 0$, then $A=\frac{L}{2}$ is constant. If $x_0$ oscillates, then we expect oscillation of $A$.


### Measuring the integral

#### $x_0 = L/2$
In those experiments **we consider** $x_0 = \frac{L}{2}$, so the kink is at the middle of the simulation lenght.
The amplitude of the oscillations depends on $dx$, so it is a **numerical problem**

#### dx=0.1
![dx=0.1](Plots/x0_oscillations_C0=1/integral_dx=0.1.png?raw=true)
#### dx=0.01
![dx=0.01](Plots/x0_oscillations_C0=1/integral_dx=0.01.png?raw=true)

#### $x_0 = L/2 + \epsilon$

If, instead, we do not start from $x_0 = 0$, the amplitude of the oscillation increases with the deviation $\epsilon$ from $L/2$.
![dx=0.01](Plots/x0_oscillations_C0=1/integral_x0=51.png?raw=true)
![dx=0.01](Plots/x0_oscillations_C0=1/integral_x0_vs_amplitude.png?raw=true)

### Measuring the position where $u=0$
If dx is too small, then this measure does not show oscillations in dx (if the amplitude of the oscillation in smaller than the discrete step dx).

![dx=0.1](Plots/x0_oscillations_C0=1/x0_dx=0.1.png?raw=true)
![dx=0.01](Plots/x0_oscillations_C0=1/x0_dx=0.01.png?raw=true)