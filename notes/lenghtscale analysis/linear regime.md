# Linear regime


## What we expect
$$\braket{q^2} = \frac{\int q^2|U(q)|^2dq}{D\int |U(q)|^2dq}$$
$$\lambda = \frac{2\pi}{\braket{q^2}} \simeq 4\pi t^{\frac12}$$
Notice that $\braket{q^2}$ is, already in the definition, normalized by the dimension $D$, so $\lambda$ does not depend on $D$.


At times sufficiently small that you can adopt the **linear approximation** of the TDGL equation.
And this we expect **independently** on the shape of $C(t)$, if the initial state is random (all fourier components weight almost the same).

More precisely, we expect this behaviour at times not so small.
In fact $\braket{q^2} = \frac{2\pi}{\lambda}$ and this (**in the below figure**) is the expected behaviour of $\braket{q^2}$ in the linear approximation of the TDGL (so at small times, before the term $u^3$ becomes relevant).

![linearTDGLq2](linear_regime_q2.png?raw=true)

Where on the x axis there is time $t$ and each colored curve corresponds to a different value of $q_{min} = 10^{-2}, 10^{-1}, 1, 10, 10^2$ (from bottom to top) is the maximum value of $q_x$ or $q_y$. As we work on a lattice, waves can have only a discrete set of momentums, and the bigger value of $q_x$ or $q_y$ is
$$q_{min} = \frac{2\pi}{L}k_{max}\quad k_{max} = N/2$$
$$q_{min} = \frac{\pi}{dx}$$

In our simulations, $dx = 0.1$, so $q_{min}\simeq 30$.

From the above plot, this means that the $<q>\sim t^{-\frac12}$ is **expected for $t>>0.3$**.


## Simulations
The selected fit region is
$$t_{min} = 0.3\quad t_{max} = 5$$
while $L=512, dx=0.1$ and the timestep in the linear regime is small ($dt=1e-3$).

![](q2/C=1/20_06_linear_regime.png?raw=true) 
![](q2/oscillatory%20C0=1/T=2.5/21_06_linear.png?raw=true) 
![](q2/oscillatory%20C0=1/T=25/21_06_linear_regime.png?raw=true)

But the result is expected without considering a cutoff.

### Without $\lambda_{cutoff}$
Here still $dt=1e-3$ but the fit region is smaller [0.3, 0.5].
![1e-3](C=0/q2/dt=0.001.png?raw=true)

We measure the right exponent $\frac12$ if we exclude the first instants from the fit.
If, instead, we consider them, we would find an higher exponent. But we do not expect a power law beaviour with exponent $\frac12$ when $t<<0.3$.

We adopted this shape for $C(t)$
![C(t)](C0=0_A=1/C(t).png?raw=true)
And we found still the expected power-law behaviour
![powerlaw](C0=0_A=1/q2.png?raw=true)