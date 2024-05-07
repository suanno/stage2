# Phase separation
[We present a slideshow of physical systems undergoing phase separation]

![beginningImage](images/phase_separation/oil_water/oil_water.jpeg?raw=true)

Let's talk about phase separation phenomenas.

[I'd like to say that those phenomenas are very frequent and we see them in very different systems. So this is the reason why we want to study phase separation in general.]

### Polymer solution
Here we can see an homgeneous solution with an high concentration of a polymer.

Quenching at a lower temperature we see the rising of the high and poor concentrated phases.
Each experiment was carried on for a longer time.

As time goes on, we see better a distinction between the rich (the black) and poor polymer phases.

![poly0](images/phase_separation/polymer/initial.png?raw=true)
![poly0](images/phase_separation/polymer/T=90C_t=30s.png?raw=true)
![poly0](images/phase_separation/polymer/T=90C_t=60s.png?raw=true)

[Backscatter Electron microscope. (a) Initial / (b) Quenched at 90C for 30s / (c) Quenched at 90C for 60s. Black is the polymer concentrated phase]

### Colloids
Here we see a solution of colloids in a $\mu$-channel, that goes under a phase-separation process. Here the white phase has less concentration of colloids.
![colloids](images/phase_separation/colloid/perp_gravity.png?raw=true)
[Confocal laser scanning microscopy (CLSM) images of an inner layer (bulk) of the channel. The channel confinement is in the gravity direction of 18 $\mu m$. The colloids R=110nm. White phase has 1kg/m3 less colloids than the black.]

### Binary alloy
Here instead we have a binary alloy CoCrCu just after casting, here the two phases differ on the concentration of the two components.
As casting is slow, you can see there are domains of one phase trapped in the other.

![CoCrCu](images/phase_separation/binary_alloy/CoCrCu/CoCrCu.png?raw=true)

[Trasmission electron microscope. As-cast (fast cooled) CoCrCu binary alloy. The black phase is the CoCr rich one]

# Spinoidal decomposition

[supportImages?] We focus on a particular class of phase separation phenomenas: the spinoidal decomposition.
In particular we focus on the case when the dynamics is non-conservative.

This phenomena happens in the Ising model when it is quenched under the critical temperature.

![Ising montecarlo]()

As a "**monolayer deposition process**" is equivalent to the 2D Ising model, we can see this phase separation **in a real system**:

![AuOnAu](images/phase_separation/GoldOnGold.png?raw=true)
[Au thin film, black spots indicate holes in the first layer. The surface touches an acqueos solution of Au atoms and an acid KCl. Applying a strong potential difference between the surface and the STM tip, atoms are electrochemically detached from the first layer, way faster than the surface diffusion rate.]

Here gold atoms are detached from the first layer of a gold film electrochemically, by creating holes that are the black regions.
Those **ramified** patterns that the domains form are the characteristic feature of spinoidal decomposition.



# A continuos theory (TDGL)
It is possible to give a continuos description of phase separation even if we deal with atoms, by defining a scalar **smooth order parameter** that describes what is the phase of the system (the local magnetization for the Ising model).

In the case of non-conservative spinoidal decomposition, the order parameter undergoes this equation

$$\partial u = \Delta u + Cu - u^3$$

where C is a parameter that we can control, for example in the Ising model by changing the Temperature $C\propto (T_c-T)$.

### Universality
This equation is called time-dependent Gitzburg-Landau equation, because you can obtain it from the Gitzburg-Landau free energy ansatz of the Ising model's universality class.
This means that, close to the critical point, where the ansatz is good, **many systems are described by this equation**.

# Goal
Our goal follows from this consideration. If the equation describes an universal dynamics, **are there general ways of controlling systems** near the critical point?

# Two options (T, B)

So we focus on this equation [? particularly Ising] and we realize that to _control the evolution of the order parameter_, the only variables we can _tune_ (in the Ising model) are the temperature or the magnetic field.

The goal of my internship is to study the dynamics by changing **only the temperature** and keeping the magnetic field to zero.

### Universality
If we can understand how the dynamics is affected by the temperature, then we can achieve control not only in the Ising model, but in all the system sharing the same simmetries! 


# We cannot do much!
But what we found is that we cannot do much!
Changing only the temperature does not seem enough to control the dynamics of the domains.

### Motion by curvature

In fact the main feature of the dynamics described by the equation is that **at fixed temperature** domains boundaries evolve due to motion by curvature.

Each point of an interface moves with a normal velocity proportional to the local curvature $\kappa$.

$$v = -\kappa$$

![Image with some domains and arrow with lenght prop to minus the curvature](.)

So far we studied how this aspect of the dynamics is affected **by changing temperature over time**.

### Tools
We **developed** both analytical and numerical tools to study how the system behaves:
- **Analytical tool**: Multi-scale expansions that enable to study the system response in the limits of fast and slow changing temperature. 
- **Numerical tool**: We implemented an existing code for simulations. We realized it used to fail in simulating some features of the dynamics. So we made a study for selecting the right integration algorithm and we adopted Crank-Nicholson in Fourier space. 

[Experimental (plot) and Analytical (multiscale expansions))] 

![extrapolatingSlope](images/extrapolation_motionbycurvature.png?raw=true)
