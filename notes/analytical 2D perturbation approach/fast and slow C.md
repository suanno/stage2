# The initial state
The initial state is a circular island at the center of the simulation square $L=100$ with radius $R_0=25$.



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

## Parameters adopted
- C_0 = 1
- A = 0.1 (This choice was made to be able to use a larger $dt$, but maybe we should focus on A=1 such that $\tilde{C}$ changes of 1 if $\tau$ changes of 1)


## Results
![motionbycurv](Slow%20oscillations/motion_by_curvature.png?raw=true)
![motionbycurv](Slow%20oscillations/radius.png?raw=true)

# Fast oscillating $C(t)$
$$C(t) = C_0 + D_0(t_{-1})$$
$$t = \epsilon t_{-1}$$

We choose
$$D_0 = A\sin(2\pi t_{-1})$$

So, by using $t_{-1} = \epsilon^{-1}t$

$$C(t) = C_0 + A\sin(2\pi \epsilon^{-1}t)$$

This means that the **period is very SMALL** $T = \epsilon=R_0^{-1}$.

## Parameters adopted
- C_0 = 1
- A = 0.1 (This choice was made to be able to use a larger $dt$, but maybe we should focus on A=1 such that $\tilde{C}$ changes of 1 if $\tau$ changes of 1)

## Results

![motionbycurv](Fast%20oscillations/motion_by_curvature.png?raw=true)
![motionbycurv](Fast%20oscillations/radius_macro_dt=0.1.png?raw=true)

But, if you look closer, you can see that the motion by curvature changes its sign (the sign oscillates) as we see with a smaller $dt$


![motionbycurv](Fast%20oscillations/radius_micro_dt=0.001.png?raw=true)

But maybe this is just a transient effect, we need a longer simulation.


# Urgent to
Make a choice of $L$, $dx$, $dt$ suitable for the problem we're facing!
We cannot wait long!!!