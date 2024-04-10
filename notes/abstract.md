The Ginzburg-Landau free energy ansatz is a powerful tool for describing phase transitions at equilibrium, but it can also be applied to study dynamics when operating near the critical point:
$$\partial_t m = -\frac{\delta F}{\delta m}$$
We focus on the Ising model, where the time-dependent Ginzburg-Landau (TDGL) equation

$$\partial_t m = \Delta m + C(t)m-m^3$$
$$C \sim (T_c-T)$$

captures the main features of the dynamics observed in Monte Carlo simulations, known as coarsening dynamics.
This p.d.e. has been extensively studied in the past when C is constant in time. However, there is a lack of literature exploring the dynamics of this equation when C has a time-dependent behavior. 

**Our goal** is to develop a theory to describe analitically the dynamics when C is time-dependent.
This would allow understanding how to change C(t) in time to drive the system from any state to a target state.

**What we did** up to now has been exploring numerically the dynamics for the 1D and 2D cases, to get insights for the analytical work. At the same time we used a perturbative approach to develop our theory in the extreme cases where the timescale for the variation of C(t) is much different than some scales of the system.