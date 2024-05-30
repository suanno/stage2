# What we expect
From our theory, we expect that motion by curvature is not affected by the time dependance of C(t) at first order in $\epsilon$ in both cases:
- C(t) is slowly changing ($\tau=\epsilon t$)
- C(t) is fastly changign ($t'=t/\epsilon$)

# What we do
We verify experimentally the motion by curvature by considering the evolution of a circular island ($\kappa = R^{-1}$).
If motion by curvature holds ($\dot{R} = -\kappa$) then we expect
$$R(t)^2 = R(0)^2 - 2t$$

So here we verify experimentally that condition.

# How we extimate R(t)
Our way of extimating R comes from **thinking of having** this analytical shape of the circular island sate
$$u(r) = \tanh((r-R)2^{-\frac12})$$
Then, we can extimate the area of the circular island by shifting the state of +1 (so the -1 plateau becames a 0 plateau) and then integrate over all the space

$$A = \pi R^2 = \int\int dx dy \frac12 (u(x,y)+1)$$

So the **quantity we monitor experimentally** (and plot) is the integral

$$I = \int\int dx dy \frac12 (u(x,y)+1)$$

### Problem

**But** this integral is $R^2$ **ony if** the height of the interface is 1 (from -1 to +1), otherwise the negative plateau contributes to the integral **even after** the +1 shift.
And, as the **areas** of the positive domain and the negative domain are **different**, then there is a dependance of the integral on the value of $C(t)$!!!

We need to find an expected relation for $I(t)$ if there is motion by curvature, and then verify it.

## Slow oscillating C(t)
If C has a slow time dependance, then we're close to the adiabatic limit.
In this limit, at any time, the plateaus are well approximated by $\pm C(t)^\frac12$ so we can extimate the integral
$$\int \int u(x,y) \simeq C(t)^\frac12\pi R^2 - C(t)^\frac12 (L^2-\pi R^2)$$

If we put this result in the expression of the monitored quantity $I$, then we have an expression $I(R^2)$ that we can verify
$$I(R^2) = C^\frac12 R^2 + L^2 \frac{(C^\frac12-1)}{2\pi}$$


if we plug in the motion by curvature relation for 
$$R^2(t)=R(0)^2-2t$$
then we find an expression $I(t)$ to verify.

## Fast oscillating C(t) [!!! FILL]
In this case we're **far** from the adiabatic limit and so we cannot use the above method to verify the motion by curvature.
What we can do is to measure, at any time, the plateau value and calculate the integral $I$ in the same way **but** considering as plateau value not $C(t)$ but the measured value.



# The initial state
The initial state is a circular island at the center of the simulation square $L=128$ with radius $R_0=50$ (_the following plot has the wrong R and L_).



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


## Results
The expected expression for the integral $I(t)$ seems to be verifyied.
Especially the **initial concavity** of the experient (that is the opposite of the one of C(t)) is the same expected.
Anyway this match becomes less and less as time passes.

##### $C_0 = 1; A<<1$
On average, the integral monitored coincides with the expected expression for $R^2$.
This is not strange, as the average of C(t) is $C_0=1$ and if $C=1$ we know that the integral coincides with $R^2$.

![T=50C0=1](Slow%20oscillations/C0=1A=0.1dx=0.1dt=0.1T=50.png?raw=true)


##### $C_0 = 2$

If $C_0 \neq 1$, then it makes no more sense to plot the expected curve for $R^2(t)$ as the negative plateau for $C=C_0$ is no more -1.
In fact the integral does not coincide with $R^2$ **not even on average** (see one of the plots below with $C_0 = 2$, where the analytical expression for the expected $R^2(t)$ is reported) 
![T=50C0=1](Slow%20oscillations/C0=2dx=0.1.png?raw=true)


As the time passes, the matching gets worse.
The expected curve and the experimental one get separated.
This **separation can be reduced by reducing dt**, while does not depend on dx.

![T=50C0=1](Slow%20oscillations/C0=2dx=0.5.png?raw=true)
![T=50C0=1](Slow%20oscillations/C0=2dx=0.5dt=0.05_average.png?raw=true)




So this mismatch is of numerical nature and **due to the time discretization**. It is not due to the fact that we're close to the adiabatic limit, but not at the limit, as we see a _drift_ in time and not an _imperfect following_ of the expected curve.


##### $C_0 = 0$
Now $C$ gets even negative values, so the $\tanh$ is n more a stationary state of the system!
As the idea with which we are checking motion by curvature holds on the fact tha the state **is a 1D kink function in the _radial_ coordinate**, then it makes no sense monitoring the quantity in this case.

![T=50C0=1](Slow%20oscillations/C0=0A=0.1.png?raw=true)
![T=50C0=1](Slow%20oscillations/C0=0A=0.1_twoperiods.png?raw=true)


##### $C_0 = 1; A = 1$
In this case $C>0$ at any time, but sometimes it is very close to zero.

Here we see that, in the times $t$ when $C\rightarrow 0$, the expected value deviates much from the experimental one, and that's because **we get far from the adiabatic limit** and so the plateau values are no more $\pm C^\frac12$.

![T=50C0=1](Slow%20oscillations/C0=1A=1.png?raw=true)

#### $C_0=2; A=1$
![T=50C0=1](Slow%20oscillations/C0=2A=1.png?raw=true)


# Fast oscillating $C(t)$
Here, instead, we're far from the adiabatic regime.

$$C(t) = C_0 + D_0(t_{-1})$$
$$t = \epsilon t_{-1}$$



We choose
$$D_0 = A\sin(2\pi t_{-1})$$

So, by using $t_{-1} = \epsilon^{-1}t$

$$C(t) = C_0 + A\sin(2\pi \epsilon^{-1}t)$$

This means that the **period is very SMALL** $T = \epsilon=R_0^{-1}$.

## Results

As we said, now we are very far from the adiabatic limit, so we cannot extimate the integral as we did before, because the plateau values are no more well approximated by $\pm C^{\frac12}$.

We here show that the analytical expression we expect for slow changing C(t) does not match the experiment.
We should make an extimation where we use the _measured_ values of the plateaus instead of using C(t).

#### $C_0 = 1$

On averga, for $C_0=1$, the integral still well approximates $R^2(t)$.

![T=50C0=1](Slow%20oscillations/T=50-1dt=0.001.png?raw=true)

But you can see that the expected oscillations (from the extimation method used for slow changing C) are way larger than the experimental ones.

![T=50C0=1](Slow%20oscillations/T=50-1dt=0.001_fewperiods_.png?raw=true)
![T=50C0=1](Slow%20oscillations/T=50-1dt=0.001_fewperiods.png?raw=true)