# Why Explicit and Implicit Euler are both Biased and we should use Crank-Nicolson

$$C(t) = \bar{C} + \sin(2\pi t)$$

Let's consider, for **simplicity**, the equation **without the non-linear term**.
If $u(t)$ is close to zero, this is a good approximation of the TDGL eq., because $u^3 << Cu$.

## What we expect
$$u_t = C(t)u$$

The analytical solution is
$$u(t) = u(0)e^{\int_0^t}C(t')dt'$$

If $C(t) = \bar{C} + \sin(2\pi t)$, then we have that
$$u(t)\sim e^{\bar{C}t}*\text{Oscillation(t)}$$

So **we expect that** $u(t)$ explodes (if $\bar{C}>0$) or decays (if $\bar{C} <0$) in a carachteristic time $\tau = \frac{1}{\bar{C}}$.

## What happens
- Implicit Euler
$$u(t+dt) = \frac{u(t)}{1-C(t+dt)dt}$$
![implicitExplosion](../../Plots/no%20cubic%20term/Implicit%20Euler%20explosion.png?raw=true)

Notice that, even if for $\bar{C}=0$ we don't expect an explosion, we see that using Implicit Euler.

- Explicit Euler
$$u(t+dt) = u(t) + C(t)u(t)dt$$
![explicitExplosion](../../Plots/no%20cubic%20term/Explicit%20Euler%20explosion.png?raw=true)

Using Explicit Euler we do not have an explosion for $\bar{C} = 0$, **but** we have a decay that we do not expect neither.

# Understanding what happens at long times when $\bar{C} = 0$
If we now include even the non-linear term
$$u_t = C(t)u-u^3$$
we can make the following considerations **when $\bar{C} = 0$**.

### Implicit Euler
- When $u$ is small (so when the non-linear contribute vanishes), we just saw that the Implicit Euler methods gives an _exponentially **increasing** solution_ (even if it's not expected analytically, this happens).

    So $u$ tends to get far from $u$ if it is close to.

- When $u$ is not small anymore, the non-linear term becames relevant. As considering only the non-linear term
    $$u_t = -u^3$$ 
    gives a _decaying_ analytical solution
    $$u(t)\sim t^{-\frac12}$$ 
    
    So we have two **opposite** behaviours, one that gets $u(t)$ far from zero and the other that gets $u(t)$ close to zero, when it is far form zero.

    After the above consideration, it is not strange to see a **plateau** at long times.

### Explicit Euler
- When $u$ is small, we just saw that the Explicit Euler method gives a numerical solution that decays (exponentially).

    So, if $u$ is close to zero, it doesn't tend to get far from it!
    So the $u^3$ term doesn't became relevant and $u(t)$ reaches zero exponentially.

    So it isn't anymore strange to see an **exponential decay** at long times.

### So the methods do NOT fail DUE to the non-linear term precence (it's a problem of the linear equation!)

# Removing the bias
We see that, for $\bar{C} = 0$, we have this Bias in the two methods
- Implicit Euler: Exponential increase
- Explicit Euler: Exponential decay

We guess that the different bias is due to the fact that, if you think on how you find the formulas
- Implicit Euler privileges the time $t+dt$
- Explicit Euler privileges the time $t$

So, to remove this bias, one could try to build a "semi-implicit" method that does not privilege any of the two instat, **but makes a fair average**

## Crank-Nicolson method
$$\frac{1}{dt}(u(t+dt)-u(t)) \simeq \frac12\big( C(t+dt)u(t+dt) + C(t)u(t) \big)$$

Notice that, in the previous methods, you keep just one of the two terms in the RHS average. Here you average them.

It follows the Crank-Nicolson scheme
$$u(t+dt) = u(t)\frac{(1+\frac{dt}{2}C(t))}{(1-\frac{dt}{2}C(t+dt))}$$

![noexplosionCrank-Nicolson](../../Plots/no%20cubic%20term/Crank-Nicolson.png?raw=true)

This scheme seems to be a successfull way of removing the bias.
It seems that, if you choose $\bar{C}=0$, **you can suppress** the exponential increase/decay (absent in the analytical solution) by adopting the Crank-Nicolson method.

## Crank-Nicolson including non-linear term $-u^3$

$$u(t+dt) = u(t)\frac{(1+\frac{dt}{2}C(t))}{(1-\frac{dt}{2}C(t+dt))}-\frac{u(t)^3dt}{(1-\frac{dt}{2}C(t+dt))}$$

Now we expect, for $\bar{C}=0$, to have a **power law decay** $u(t)\sim t^{-\frac12}$

![nosaturationordecaysWithCrank-Nicolson](../../Plots/saturation%20plots/Crank-Nicolson%20no%20saturation.png?raw=true)

We can see there is nor a saturation nor an exponential decay after the expected asymptotical behaviour!

With Euler's method we found those two unexpected behaviour already at $t\sim 10^3$ for the adopted parameters ($T=1, u_0=1, dt=0.008$).
But here we don't see them even at $t\sim 10^5$!!!