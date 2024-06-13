# Study of $<q^2>(t)$ at small times

## What we expect

$$\lambda = \frac{2\pi}{<q^2>} \simeq \frac{4\pi}{\sqrt{D}} t^{\frac12}$$

at times sufficiently small that you can adopt the **linear approximation** of the TDGL equation.
And this we expect **independently** on the shape of $C(t)$, if the initial state is random (all fourier components weight almost the same).

More precisely, we expect this behaviour at times not so small.
In fact $<q^2> = \frac{2\pi}{\lambda}$ and this (**in the below figure**) is the expected behaviour of $<q^2>$ in the linear approximation of the TDGL (so at small times, before the term $u^3$ becomes relevant).

![linearTDGLq2](linear_regime_q2.png?raw=true)

Where on the x axis there is time $t$ and each colored curve corresponds to a different value of $q_{min} = 10^{-2}, 10^{-1}, 1, 10, 10^2$ (from bottom to top) is the maximum value of $q_x$ or $q_y$. As we work on a lattice, waves can have only a discrete set of momentums, and the bigger value of $q_x$ or $q_y$ is
$$q_{min} = \frac{2\pi}{L}k_{max}\quad k_{max} = N/2$$
$$q_{min} = \frac{\pi}{dx}$$

In our simulations, $dx = 0.1$, so $q_{min}\simeq 30$.

From the above plot, this means that the $<q>\sim t^{-\frac12}$ is **expected for $t>>0.3$**.

## Simulations

### C = 0 constant
We see this power-law behaviour, but only if the timestep $dt$ is sufficiently small ($dt\sim 10^{-3}$)! In fact we cannot see it if $dt\sim10^{-2}$.



- $dt=10^{-2}$

![1e-2](C=0/q2/dt=0.01.png?raw=true)

- $dt=10^{-3}$ (fitted range $[0.3, 0.5]$ because we expect the 1/2 power-law when $t\simeq 0.3$)

![1e-3](C=0/q2/dt=0.001.png?raw=true)

We measure the right exponent $\frac12$ if we exclude the first instants from the fit.
If, instead, we consider them, we find an higher exponent.

### Oscillating C(t) with $<C> = 0$
We adopted this shape for $C(t)$
![C(t)](C0=0_A=1/C(t).png?raw=true)
And we found the expected power-law behaviour
![powerlaw](C0=0_A=1/q2.png?raw=true)

### C = 1 constant
![C=1](C=1/q2/dt=0.001.png?raw=true)

# Study of global lengh-scale $\lambda$ at long times

### C = 1 constant
There is a strong dependance on $dt$
- $dt=10^{-2}$
![C=1](C=1/q2/dt=0.01.png?raw=true)
- $dt=3\cdot 10^{-1}$
![C=1](C=1/q2/dt=0.3.png?raw=true)