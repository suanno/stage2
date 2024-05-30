# Definition of chaotic system
A dynamical system that is very sensible to initial condition.
So if you take two points in the phase space infinitesimally close, the two trajectories you get by evolving those two initial states will separate exponentially fast in time

---------

- there are some trivial examples where this definition is satisfied but the dynamics is trivial (a map that multiplies by a number, like 2). But you can say that the def is that, excluding those trivial example. Or if you want you can add the requirement that the periodic orbits are dense in the phase space, that is a property that all the systems _that we want to label as_ chaotic have.
- if the prefactor of time at the exponent is positive, then you say the sys is chaotic
- the separation in different (orthogonal) direction has a different prefactor (lyapunov exponent). But the one that matters at long time is the MLE (maximum lyapunov exponent)
- The Lyapunov exponents are well defined in the timespan where the dynamical system can be threated in the linear approximation. This works even at long times if the trajectories at t=0 are infinitesimally close. That's because you find that that the separation is exponential by making a linearization expanding _in the initial distance $\epsilon$ the distance at time t_, and not expanding in time t. You get an exponential, as you get it when you have a linear system, so when you linearize in time $t$. So it is not strage that you get an exponential.

----------

# Mixing system
Mixing means that eventually (for all times larger than a certain one) the evolutions of two subsets of the phase space will intersecate (will never stop intersecate anymore).
Visually, any finite set of points in the phase space is spread on the whole phase space (with a distribution that is not necessarily uniform, but resembles the conserved measure of the system)
