# The initial state
The initial state is a circular island at the center of the simulation square $L=128$ with radius $R_0=50$.

[The drawing of the circe has wrog R0 L, remake it...]

![circular](../Checking%20Crank-Nicolson%202D/Plots/circular_front%20t=0.png?raw=true)

## Choice of the Lenghtscale $\epsilon$
We choose as the lenghtscale of the system (that we guess it's _unique_) **the radius** of the system.

But, as we do not know how it evolves, we consider the **initial** radius $R_0$.
So we set
$$\epsilon = R_0^{-1}$$

[Remember that $k = \epsilon K_1$ with $K_1\sim 1$ and $k = R^{-1}$]

**Problem**: The lenghtscale $\epsilon$ has a time dependance!!!
Why we do not take this into account when we make derivatives respect to time?


# Slow oscillating C(t)
$$C(t) = \tilde{C}(\tau)$$
where $\tau = \epsilon t$ and $\delta \tau \sim 1 \implies \delta \tilde{C} \sim 1$

We consider 
$$\tilde{C}(\tau) = C_0 + A\sin(2\pi \tau)$$
with period 1 such that it makes significant changes if $\delta \tau \sim 1$.

So, using $\tau = \epsilon t$

$$C(t) = C_0 + A\sin(2\pi \epsilon t)$$

So the **period is LARGE** $T = \epsilon^{-1}=R_0$

## Extimating R(t)

The Radius is extimated **by thinking that** in the radial coordinate $u(x,y)$ is $\tanh(r-r0)$, so we can calculate $R$ as

$$R(t)^2= \frac{1}{\pi}\int_0^L \int_0^L \frac12(u(r,t)+1) dxdy$$

**But** this reasoning **assumes** that the _plateau value_ of $u(r)$ is always 1 and never changes.
If it changes, there is a problem in the definition of R, as the region of xy space where $u>0$ has not the same area of the one where $u<0$ (as it happens in the 1D case, so there is not a problem because the opposite contributions cancel)

So **we should take care** on the way the plateau value changes in time (we know something from **1D analytical study with perturbative approach**)

# Experimental results
Motion by curvature is verifyied on average, with a better match reducing the timestep $dt$.

But we see some oscillations that do not decrease by decreasing dx!
**Even though** in the 1D case those oscillations

### Changing dt
![motionbycurv](Slow%20oscillations/C0=1A=0.1dx=0.1dt=0.5.png?raw=true)
![motionbycurv](Slow%20oscillations/C0=1A=0.1dx=0.1dt=0.1.png?raw=true)
![motionbycurv](Slow%20oscillations/C0=1A=0.1dx=0.1dt=0.05.png?raw=true)
### Changing dx
![motionbycurv](Slow%20oscillations/C0=1A=0.1dx=0.1dt=0.1.png?raw=true)
![motionbycurv](Slow%20oscillations/C0=1A=0.1dx=0.05dt=0.1.png?raw=true)

# Changing A
![motionbycurv](Slow%20oscillations/C0=1A=0.1dx=0.1dt=0.1.png?raw=true)
![motionbycurv](Slow%20oscillations/C0=1A=0.5dx=0.1dt=0.1.png?raw=true)