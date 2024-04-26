# Effective INITIAL radius
## Intro
We see that, when **measuring** the radius of a circular island, this measure obeys the _motion by curvature law_, but with an effective initial radius that is different from the real one.

This is a numerical problem due to the space discretization, as the mismatch with the expected relation is reduced by reducing $dx$.

But it does not seem a problem of the integration algorithm, but only of the measure of the radius, due to the difficulty of resolving the peak position of the function $|\nabla u|$.
In fact, if we take the average of $r^2$ with $|\nabla u|^2$, that is **less peaked and larger** than $|\nabla u|$, we get a better match with the same $dx$.

## What we show here
Here we show how this effective initial radius, that we stress is not a feature of the code to integrate the dynamics, **but of the measure**, depends over the parameters dx, dt, R0.

## $R_0$ dependance
If the initial radius is different, the transient behaviour is too?

In order to check this, we plot a quantity _that we expect_ to be independent on $R_0$.
We consider $R^2-R_0^2$, that we expect to be $-2t$.
![constC](../Measuring%20Radius/effective_radius_R0.png?raw=true)

It looks like the behaviour is the same, meaning this transient behaviour **depends only on the variation of $C$, and not on $R_0$, dx, dt**. 
More explicitly, the last experiment shows that 
$$R^2 - R_0^2= \delta R_0^2(C) - 2t$$

so the _effective **initial** radius_ is
$$\tilde{R_0}^2 = \delta R_0^2(C) + R_0^2$$
where $\delta R_0^2(1)=0$, but I guess this is due to the fact that in the initial state the width of the interface is $W=1$. 
#### Comment on this transient behaviour
It is important to understand this transient, because:

If $C$ is constant, this is only an _initial transient_ and then we have the expected motion by curvature.
But if we change very fast $C(t)$ in time from C=1 to $C\neq 1$, then we will have the same behaviour! 

What happens **during** the **transient** to reach the linear dependance on time?

![constC](../Measuring%20Radius/gradient.png?raw=true)
![constC](../Measuring%20Radius/gradient_slice.png?raw=true)