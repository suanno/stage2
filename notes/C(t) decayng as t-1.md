# We consider $C(t) = \frac{a+b}{\frac{b}{\beta_0^2}-2at}\sim t^{-1}$

This is the Constraint we find for $C(t)$ when we try to find the kink's shape while $C(t)$ is varying in time.

- a < 0, otherwise we have a time when $\alpha_0^2$, that is a square, becomes negative.
- b > 0, because is the proportionality constant of two squares.
- $\beta(t)$ describes the kink's height. The kink's height is factorized and the factor is $\beta(t)$. $\beta_0 = \beta(0)$.


### Choose a = -1, b = 2, $\beta_0 = 1$

- Kink's shape (rescaled)

The curve deviates, for any time (even small times) the initial, because the rescaling is done such that

"If the kink's shape (non-rescaled) is the stationary state associated to $C(t)$, the rescaked shape is $\tanh((x-x_c)/\sqrt{2})$, that is the shape of the rescaled initial curve"

and $C(t)$ is **close to zero from the beginning** ($C(0) = \frac12$ and then decreases to zero).
So the evolution of the kink's shape is **not adiabatic**.

**Anyway** the shape still seems to be $\tanh$ (We should rescale the shape using **measured** height and width, instead of the adiabatic expected ones!)

![kinksshaperescaled](../Plots/kink%20shape%20varying%20C/rescaled/C(t)%20decaying%20t-1/kink%20shape%20rescaled.png?raw=true)

- Height

Here the curves do not overlap. We expect that is because the value of $C(t)$ is very small and so we do not expect an adiabatic behaviour.

**Anyway** we expect they overlap after a long time $\tau \sim \frac1C$, but what happens at longer times ($t\sim 10^3$) is that **width saturates** and this is an effect of kink's interaction that happens because the lattice is finite.

As our analytical stuff are based on an infinite lattice, we cannot compare our expected results to the simulations when width saturates. So we do not make simulations at higher times!

![height](../Plots/kink%20shape%20varying%20C/rescaled/C(t)%20decaying%20t-1/height.png?raw=true)

- Width
![width](../Plots/kink%20shape%20varying%20C/rescaled/C(t)%20decaying%20t-1/width.png?raw=true)

### Width saturation
