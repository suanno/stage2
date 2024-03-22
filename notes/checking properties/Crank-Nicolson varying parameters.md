# Crank-Nicolson
We found that the Crank-Nicolson scheme
- Solves the linear equation $u_t = C(t)u$ without any bias in the solution
- Solves the TDGL equation _for a flat profile_ showing the expected asymptotical behaviour (no plateau/exponential decays)

Now we see how it behaves varying $\bar{C}$, $T$ and $dt$.

### Varying $\bar{C}$
$C(t) = \bar{C} + \sin{(2\pi t)}$ for different values of $\bar{C}$.

We **expect** that
- if $\bar{C} > 0$, in the long time limit (when $t >> \tau = \frac{1}{\bar{C}}$) we expect that the oscillatory part of $C(t)$ is negligible respect to $\bar{C}$.
That's because the analytical solution depends on $C(t)$ only throught it's integral over time, so you can neglect the integral of the oscillatory part if $t$ is large.
So $u(t)\rightarrow\pm\bar{C}^{-\frac12}$.

    The convergence is exponential, as we know that for costant $C=\bar{C}$
    $$(u(t)\mp\sqrt{\bar{C}}) \sim e^{-2\bar{C}t}$$

- if $\bar{C} < 0$ we expect the same behaviour, but now $u(t)\rightarrow 0$.
- if $\bar{C} = 0$ we expect that $u(t)$ goes to zero as
$$u(t=nT)\sim t^{-\frac12}$$

We **see** this

You can clearly see the _power-law decay_ when $\bar{C} = 0$ and the exponantial decay when $\bar{C} < 0$.
You can also see that $u(t)$ converges to a non-zero value if $\bar{C} > 0$, that is $\sqrt{\bar{C}}$.
![varyingCbarCrank-Nicolson](../../Plots/Crank-Nicolson/Vary%20Cave.png?raw=true)

## Varying T, dt
We expect an increase of _accuracy_ (of the numerical solution) by increasing the ratio $\frac{T}{dt}$.
We say this, because this is the accuracy associated with the encoding of the function $C(t)$ into a discrete array.

Anyway, the discretization of $C(t)$ is not the only source of numerical error. In general the discretization of time is a source of error.

In fact we can see that, fixed $\frac{T}{dt}$, we increase the resolution (and from the plot, I guess even the accuracy) of the numerical solution by lowering the time step $dt$.

![fixedToverdt](../../Plots/Crank-Nicolson/T%20over%20dt%20=%2010.png)

The amplitude of the oscillation (that decreases in time as a power law $\sim t^{-\frac12})$ increases with the period.
That's because the oscillations are governed by a term $$\sim e^{(1-\cos{(2\pi t/T)})(T/2\pi)}$$
Where the factor $T/2\pi$ comes from the integration of $\sin(2\pi t/T)$.

You see that better here
![oscillationAmplitudeDependsonT](../../Plots/Crank-Nicolson/Vary%20T.png?raw=true)

**Notice** that it makes no sense to numerical solve the equation if $T\sim dt$, because the encoding of $C(t)$ doesn't reflect $C(t)$ at all.