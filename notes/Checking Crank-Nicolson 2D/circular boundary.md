# Circular front/domain evolution with _constant_ $C=1$

The initial state (circular island) is prepared like this

$$u(r) = -\tanh((r-R_0)2^{-\frac12})$$
$$R_0 = 25$$

Where $r$ is the radius of a set of polar coordinates centered at the center of the simulation box (L/2, L/2).

**Notice that**: The value of $u$ at the center of the circle is, by construction, slightly smaller than 1, and at the borders of the box is slightly greater than -1.
And we're adopting PBC.

I think that the **transient behaviour** that i see in the first timesteps is related to this fact.
The width of the interface is, by construction (i put the $2^{\frac12}$ for this purpose) $W=1$.

![circularisland](Plots/circular_front%20t=0.png?raw=true)

--------------

We expect to see "Motion by curvature" if $C$ is constant
$$v = -\kappa$$

Where $v$ is the (normal) front velocity, that is positive if you move from the center of _the tangent circle_ (that is _the_ circle itself, if the boundary is a circle) to the outside.
That's because $\xi$ is increasing in that direction and
$$\partial_t = -v\partial_{\xi}$$
tells that the sign of v is positive when the _wave_ moves towards increasing $\xi$.

While $\kappa$ is the _local curvature_ of the interface (that is the same in the whole interface, if it is a circle) and **is defined as** $\kappa = 1/R$, so **it is always positive**.
As the radial coordinate (of polar coordinates, centered at the center of the tangential circle, that is the circle itself here) is $r=R$ at the boundary and increases if you move from the center of the circe to the outside, then
$$r = \frac{1}{\kappa} + \xi$$
(there is a **plus sign**, this is the result of our reasoning)

So $\kappa$ is always positive, by definition. The only time we talk about a sign "related to $\kappa$" is when we say that $r$ is obtained **by summing** $R=\frac{1}{\kappa}$ and $\xi$.
This means that **$v$ is always negative**, so

    The motion by curvature tends to shrink a circular domain to zero, independently on its size or sign (+1 or -1)


-----------------

We can extimate the _area_ of the $+1$ domain (the circular domain) by calculating the integral

$$A = \int dx \int dy \frac12(u(x,y)+1) = \frac12(\bar{u}+1)L^2$$

If the state is well approximated by the $\tanh$ function, then this formula is right (no errors, as you have _opposite errors_ that cancel out).

From which you can extimate the radius $r$ as $A=\pi r^2$ and so both $\kappa = \frac{1}{r}$ and $v=dr/dt$.

Here you can see there is a direct proportionality _with a negative sign_ between $v$ and $k$.

The data of this plot is got as time passes, from smaller values of $\kappa$ to larger;
the second plot shows how the radius decreases (and so $\kappa$ increases) as time passes.

![circularislandC=1](Plots/motion_by_curvature_dt=0.1.png?raw=true)
![circularislandC=1radius](Plots/motion_by_curvature_radius_dt=0.1.png?raw=true)