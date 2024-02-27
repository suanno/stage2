# Stationary non-flat solutions of TDGL with constant C

The TDGL equation, if you require $\partial_t u = 0$, becames the Newton equation for a 1D particle
 $$\partial_{xx} u(x) = -\frac{dV(u)}{du}$$   
where $x$ is the time and $u$ is the particle's position and the mass is $M=1$.
The particle is moving in a potential
$$V(u) = \frac{C}{2}u^2 - \frac{1}{4}u^4$$

So **the stationary solutions of TDGL are (coincide with) the (all possible) trajectories of this 1D particle**.
Where $x(t)\rightarrow u(x)$.

But **pay attention to the boundaries!**
The stationary solutions will be only the trajectories that satisfy the boundary conditions.

## PBC
- The (unbounded) trajectories associated with an energy $E > V_{max}$ do not satisfy PBC, because they diverge at $x\rightarrow \infty)$ (diverge at infinite time)
- The (bounded) trajectory $E=V_{max}$ [the **single kink** solution] doesn't satisfy PBC, because the particle **takes infinite time** to reach "the other" maximum and so there is only one kink ($u(-\infty) = -1$ and $u(+\infty) = +1$, so the value is different)
- The trajectories with $E<V_{max}$ and $E>0$ are **periodic**, since the particle takes a finite time to reach the points where $V(x) = E$.
If the **period is a divisor** of the simulation lenght $L$, then the solution is compatible with PBC

So, adopting PBC, we have some stationary solutions for $E<V_{max}$. One for each period that divides the lenght of the box $L$.

## Analytical solution
If we do **not** apply PBC, we have a solution for the trajectory with $E=V_{max}$, that has a single kink.

For $C=1$ its analytical expression is
$$u(x) = \tanh{(\frac{x-x_c}{\sqrt{2}})}\quad \forall x_c$$

When you consider the periodic solutions ($E<V_{max}$), the shape is no more described by an arcotangent. That's because we calculate the shape of the trajectory by integrating the diffrential relation
$$dt = \frac{1}{\sqrt{2(E-V(x))}}dx$$
between the two points $x$ where $V(x) = E$.

So the integral depends as above from $E$, so it is different from different values of $E$.

## Still we expect "similarity" with the arcotangent

But we **expect at least** that, for values of $E$ close to $V_{max}$, you still have a solution that is similar to the arcotangent that you expect for $E=V_{max}$.

As we adopt PBC in the code, the stationary solution with the closest value $E$ to $V_{max}$ is the one which period is equal to $L$ (the **two kinks** solution).

## Test how well the code integrates in SPACE
We can use the above fact, to check wether the code works well in space.
Before we only studied flat profile, so wether the code integrated well the TDGL in time.

We **set $C=1$ constant** and **let the code evolve** towards the stationary state with period $L$.
We achieve this by defining an initial state flat with the addition of a _small amplitude_ sine wave with $\lambda = L$.
![riseoftwokinks](../Plots/two%20kinks/rise%20C%20=%201%20const.png?raw=true)

Here we show how faithfully the (quasi)expected atcotangent shape of the kink is represented in the numerical solution.

![riseoftwokinks](../Plots/two%20kinks/kink%20shape%20varying%20dx.png?raw=true)

You can see that $dx = 0.1$ is sufficient to resemble the expected shape.

## The kink distance must be large to avoid annichilation

Before we let the system go into a stationary state. Now let's consider to **build by hand** a two kink (initial) profile with an arcotangent shape.

If you choose a short distance between the kinks, they quickly annichilate.
![annichilationofclosekinks](../Plots/two%20kinks/short%20distance%20annichilation.png?raw=true)

The annichilation behaviour can be described analytically. In fact the velocity with which the two kinks get closer is
$$\dot{d}\sim e^{-2d}$$ 
where $d$ is the distance of the kinks.

- If they are far, it tooks a lot of time to get close, so they look still.
- But **if the distance is short**, then the annichilation is **very fast**.

Indeed, we can understand why the shown behaviour happens with two qualitative reasonings:

- If the distance between the kinks is short (so the cetral plateau region is small), then this central region **must be build up with short-$\lambda$ modes**.
But we know (from non-rigorous reasoning) that we have unstable modes if $q < q_{cutoff}$, so the short-wavelenght modes ($\lambda = 2\pi/q$) are stable.
This means that they decay exponentially, and so it does the central plateau.

- The stationary solutions are periodic. This means that we can have a stationary solution with two very close plateau but, **at the same time** there must be other plateaus, as the solution is periodic and the two kinks are very close and occupy very small space of the simulation box.

# Kinks (periodic) sytationary state stability

The periodic (with kinks) stationary states are not stable, because it exists a mechanism of annichilation of the kinks.
This mechanism is very slow, because its velocity is $\sim e^{-d}$ where $d$ is the kinks' distance.
Anyway it exists, so **the periodic stationary states are NOT stable**.

### Adiabatic and Non-adiabatic behaviour
As a consequence, it is reasonable that, if we vary $C(t)$ in time, the system does not "follow" the stationary state (whose shape depends on C).
Because the system is "not attracted" by the stationary state, as it's unstable.

As the mechanism is very slow, we expect an "adiabatic" behaviour (follow the stationary state) when $T>>\tau$ where the charateristic time for the evolution of the system $\tau$ is found like this:

In a stationary state, the plateaus are $\simeq C$ [IF $C$ is sufficiently big].
So if $C\sim 1$ (oscillates around 1), then we can neglect the non-linear term and so $u_t = Cu \implies \tau\sim\frac{1}{C}$.