### Formal Definition
We say that a system
- that has **two** phases (e.g. a mixture of two materials: alloy, polymer mixture. Rich and poor phases)
- where the scaling hypotesis is true (in a lot of system this is true only after a sufficiently long time) 

evolves with coarsening dynamics if the (unique, due to scaling hypotesis) lenght-scale of the system increases as a power law of time.
As there is only one lenghtscale, you can measure this time dependance by considering
- the average domain size ["Max Planck Institute" description of coarsening](https://www.mis.mpg.de/pattern-formation-energy-landscapes-scaling-laws/coarsening)
- the sum of all domains perimeters (integral of the gradient square over the whole space) [Olivier idea]()
- the maximum in the 1D spectrum of the FFT averaged over radius ($F(k)$ where $k^2 = k_x^2+k_y^2$) [Colloids in micro-channel article](http://dx.doi.org/10.1063/1.4767399)

That's it.

### Physical systems where you see coarsening
You usually see coarsening in systems where the main contribution to the Free energy is due to the **interfacial energy**.
This statement is supported by the fact that this is the leading contribution in those systems where we see coarsening
- Ising model 2D (and so Gas/Lattice model)
- Binary alloy
- Polymer mixtures

The system, minimizing the Free Energy, moves towards configurations where
- the domains are round shaped (small curvatures)
- the small domains disappear (and the bigger grow if you have conservative dynamics)

and we observe both things in coarsening dynamics.

Usually you see domains emerging and a following coarsening dynamics (after some time, I guess because you need to wait for the scaling hypotesis to be good) after a **temperature quench** under a critical value.
The easiest way to _model_ this, is to say that the free energy, under the critical temperature, has two ordered stable phases instead of a single disordered stable phase.
You can model the free energy shape as
- double well (no nucleation barrier: spinodal decomposition. Simplest shape for Second order transition)
- double well with nucleation barrier (nucleation: you need fluctuations for domains to emerge. Simplest intermediate shape of First order transition)

**Notice**: You can have coarsening even in a system where you have nucleation and not spinodal decomposition. By the way we think only about spinodal decomposition.

From a double well free energy shape, you get two models for describing coarsening in a non-conservative or conservative regime: Chan-Allen ($\lambda \sim t^{1/2}$) or Chan-Hilliard ($\lambda \sim t^{1/3}$) equations.

### Physical mechanisms responsible for coarsening
- **Diffusion**: Meaning that each particle that constitute a domain, has a dynamic as an independent object, like in a gas. This is the main mechanism in binary alloys (liquid) and polymer mixtures when the domains are small. In this regime $\lambda \sim t^{1/3}$ (the dynamic is conservative in those systems. Mass conserves, so we have the Chan-Hilliard exponent)
- **Hydrodynamics**: In a polymer mixture, when the domains become sufficiently big, then they start to behave as fluids. So you have friction due to viscosity. Now the single partile has no more an independent dynamics, but the whole domains has a fluid dynamics. In this regime  $\lambda \sim t^{1}$, so Chan-Allen or Chan-Hilliard does not describe good the dynamics

- [Even liquid droplets wet the surface (reach a thin layer) with coarsening dynamics, but with exponents $t^{1/4}$ or $t^{1/5}$]

So Chan-Hilliard well describes those **real** systems, but only for time not so long (before the domains become too big). 