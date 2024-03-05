# When two kinks are independent?

### Analytically
Our analytical work is built on an **infinite lattice** so we do not have boundary conditions.
In this framework, if $C>0$ constant, we have a **single kink** stationary solution.
What we (plan to) do analytically is this:

    We question about the evolution of the SINGLE KINK state if we make C(t) vary in time

### Numerically
The "enviroment" of our numerical simulation is a **finite** lattice where we adopt **PBC** boundaries.
Here we **do not have** the single kink stationary solution, because it is incompatible with the boundaries.
We just have the **periodic** solutions (so in the simulation cell we have an _even_ numer of kinks, in a stationary state)

So the two enviroments are different, but the **main idea** is that

    If the neighboring kinks are far, then their shape is close to the one of the single (isolated) kink that we study analytically

The above statement can be motivated by thinking to the stationary states as the trajectories of the "reversed double well potential". If the energy of the considered (periodic) trajectory is close to the one of the single kink trajectory, then **the integrals that give the trajectories shall be similar**.


So, in order to have the neighboring kinks far apart, we work with the **two kinks** solution (that means, in the simulation cell, we have only two kinks. Not 4,6, or more)



## When the shapes of the two kinks begin to differ from the single (isolated) kink?

If $C$ is too small (compared to the simulation cell size $L$, we'll see why) then the **width of each kink increases**.
We see that experimentally, but we can expect that if we think to a system evolving adiabatically and remember that the stationary state associated with a value $C$ has width $\sim \frac1C$.

If the widths of the two kinks overlap, that means **naively** that 
    
    the shapes of the two kinks overlap

so we **cannot say anymore** that the shape of each kink can be studied **as if it was the only kink**.
Because we pointed out that there is an effect **due to** the presence **of the other** kink!

So, in this regime of small values of $C$, we cannot compare anymore our analytical results with the numerical simulations.

### Understand WHEN we cannot do anymore comparisons

**Experimentally** we can see when we enter this regime by monitoring the kink's width defined as
$$w=2(\tilde{x}-x_c) : y(\tilde{x}) = (height/2)\tanh(1)$$
where $x_c$ is the kink's position.
When we enter this unconfortable regime, we see a **saturation of the kink's width** (that was previously increasing while decreasing $C$).