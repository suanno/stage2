We'll threat the 3 regimes separately
- Small times
- Intermediate times
- Long times

of the TDGL's dynamics.

# Long times
The motion by curvature is found by considering the curvature a small parameter (respect to the interface width).
This means that it is not necessarily valid in the first stages of the dynamics, when there are no domains or they are small (large curvature) [we think to an initial disordered state]

But eventually, we see experimentally that the domains become big and the curvature small, so after some time we will reach motion by curvature.

    Motion by curvature is valid at long times. Before we do not know!

### Dimensional analysis
$[v] = \frac{[L]}{[t]}$ and motion by curvature tells that $v=D\kappa$ and $[\kappa] = \frac{1}{[L]}$.

So then you say that $D/L \sim L/t$ so
$$L(t) \sim (Dt)^{\frac12}$$
Where the diffusive factor $D$ is 1 in the TDGL (multiplicative factor of $\Delta m$).

This is naive, but if you consider a circular domain and you consider motion by curvature, you find that $R^2(t)=-t$ (here D=1 as in the TDGL).

----------

**Only one lenghtscale**: The dimensional analysis tells that **ANY lenght** of the system has that time dependance

 $$\lambda \sim t^{\frac12}$$

Actually there is a way to rigorously proove that (in 1D TDGL, not yet in 2D), at long times, the system is described by only one lenghtscale.
Explicitly this means that the morphology that you see, does not depend on time if you rescale all the lenghts by this unique lenghtscale (that depends on time).
Precisely, with "does not depend on time" we mean that "if we make a statistical average, over all possible initial states" then "the rescaled morphology does not depend on time". 

 So all the lenghts that you can measure (like average domain size or sum of all the perimeters) are **multiples** of this unique lenghtscale.

----------

So, in order to see this behaviour of the lenghtscale $\lambda \sim t^{\frac12}$ (known as coarsening with exponent $\frac12$), it is not relevant what observable of the system you track in time (average domain size or sum of the perimeters of the domains or ...) to check the coarsening's behaviour.

### Small times
Here you cannot say that there is motion by curvature, so you cannot say there is coarsening dynamics.

By the way, if you start from an initial disorded state with small deviations from zero (so $m\simeq 0$ everywhere) then, at least in the first stages of the dynamics, you can linearize the TDGL equation.

It turns out that, if you consider the linearized equation and an initial state $m(x,y)\simeq 0\quad\forall x, y$ then the quantity $<q^2>$ (average of $q^2$ weighted by the fourier transform $M(q)=F[m(x)]$) evolves such that

$$\lambda = \frac{2\pi}{<q^2>^{\frac12}} \sim t^{\frac12}$$


But this holds ONLY
- for the initial dynamics. At a certain time you will loose $m\simeq 0$ in some points of the space.
- if the initial state is a disorded state with small deviation from zero ($m(x)\simeq 0 \quad \forall x$).


# Intermediate times
Here we cannot tell anything


# What we expect to see

### $<q^2>$
As during coarsening there is only one lenghtscale, then we expect that _even_ $\frac{1}{<q^2>^{\frac12}}$ has the $t^{\frac12}$ dependance at **long times**.
And it has this dependance _even_ at **small times**, if the initial state is close to zero.

### Other lenghts (observables that are lenghts)
They have the $t^{\frac12}$ dependance at long times, but at small times we cannot say anything.

**e.g.**: The sum of the perimeters of all the domains (integral of the gradient squared)

### Intermediate times
Here we cannot say anything about any observable.