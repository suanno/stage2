## Questions

+ What I did in bachelor, laboratory
+ Multi-scale expansion: what we did (timescale separation between the two scales: what?)
+ Measure techniques of experimental images and what exactly they show
ok Phase separation in polymer and colloid solution (papers)
ok Capillarity (if a channel is all wet, there is no capillarity)
+ Coarsening
+ Crank-Nicolson (in Fourier space)
+ Montecarlo Ising: possible algorithms (e.g. Metropolis)
+ Genetic algorithm
- ML, Reinforcement learning
- Bio-imaging
+ Single electron transistor (charge island)
- Gas-Lattice model (about the equivalence with the ising model)
+ Electromigration (electron wind-force)
- Optimal control theory
- Growth is just one non-eq condition ($\Delta\mu\neq 0$). What are the other possible conditions?
- TDGL equation: Derivation, interpretation of terms both on the stationary states and physical interpretation
+ Crys growth techniques: PVD, MBE
- Gorwth condition: What physical parameters ($\Delta\mu$, T, what else?)
- Pre-patterned surface, growth on it (especially on sinusoidal profile, growth on maxima)
- Si(100) and Si(111) reconstructions, dimer rows, isotropy at hight temperature.
- Growth of metal on metal (surface diffusion and attach/detach competition)
- Quanum dot shape as function of size (aspect ratio)

- Phase diagram Ising B=0 (SIMPLEST continuos phase transition diagram for SECOND order transition)
- Thin film and bulk differences
- Micro-channel (and with colloidal solution. Basic mechanism of flow in microchannel)
- Binary alloy film deposition (lateral and vertical states)

#### Answered ones
- Discontinuos phase transitions (1st order): We do not know what happens, because we did not studied them.
- What do you expect changing other fields over temperature? I expect to achieve more control, as we already know that in growth the chemical potential value can be adjusted to make the islands increase or decrease. So we will have for sure a control on the size, we do not yet know about position and shape.
- Applications in microelectronic: If we can manage to place nanostructures in the positions we want, we could fabricate nanoscale electronic systems [like single electron transistors (in the picture)] without lithography. So this research could lead to cheaper methods.
- Our theory applies to every subtsrate ad adatoms species. But the group in Mareille has strong experience on semiconductors, so we will try on them. Even if electromigration is stronger in metals, but they have apparatuses for silicon.
- Can you do this with graphene? Every system has ITS OWN microscopic underlying physical mechanisms. But even if they are different, macroscopically we can see the same morphology we see in metal on metal deposition.
But as the microscopic mechanisms are different, the strategy to drive will be different.
What we want to do is to find a strategy to control the system, that depends on its underlying physical mechanisms.
We can model them by looking at the simmetries and then the generality of a strategy will be among the class of systems with the same simmetries.<>


## TDGL
- Plot the R^2 for FAST oscillating C, comment it and then try to put A=1. Simulate for some periods, so not a large tspan!
- Plot the values of the slope for C=1 and different dts and plot OVER the one for slow changing C(t). Polyfit and then put the standard deviation of the fit (subtract the fitted line and compute std)
- Draw a scheme where you picture the differences between spinoidal/nucleation decomposition and conservative(surface diffusion)/non-conservative (attachment/detachment) and you picture the equivalence between the 2D lattice-gas model and the Ising model (what is B and what is T; where happens the 1st order transition?)