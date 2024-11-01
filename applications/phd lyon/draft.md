# Optimal Nano-structure design at crystal surfaces
![chan-allen-domains](images/chan-allen.png)

# Intro slide
Systems with which we're working / we will work on
- **Internship**: 2D Ising model, monolayer deposition (2D lattice in contact with a gas).
![ising](images/isingBeta=4J.png?raw=true)
![monolayer](images/monolayerDeposition.png?raw=true)
- **PhD project**: More general nanostructures, like cristal surface with atomic steps.
![nanoscaleSteps](images/nanoscaleSteps.png?raw=true)


# Phase separation
""In those systems **we're studying phase separation**
This is an **out of equilibrum** phenomena that occurs in many different systems. For example:""

### Examples of phase separation

Here we have a polymer solution, after quenching we see a separation between the black concentrated phase and the other one.
[Time arrow]

![poly0](images/phase_separation/polymer/initial.png?raw=true)
![poly0](images/phase_separation/polymer/T=90C_t=30s.png?raw=true)
![poly0](images/phase_separation/polymer/T=90C_t=60s.png?raw=true)

[Backscatter Electron microscope. (a) Initial / (b) Quenched at 90C for 30s / (c) Quenched at 90C for 60s. Black is the polymer concentrated phase]

Here we see a solution of colloids in a polymer, that is confined in a $\mu$-channel. After steering the solution, we see the white colloid concentrated phase separates from the other.
![colloids](images/phase_separation/colloid/perp_gravity.png?raw=true)
[Confocal laser scanning microscopy (CLSM) images of an inner layer (bulk) of the channel. The channel confinement is in the gravity direction of 18 $\mu m$. The colloids R=110nm. White phase has 1kg/m3 less colloids than the black.]



# Spinoidal decomposition

But we focus **just on** a particular kind of phase separation: the spinoidal decomposition.

This is the kind of separation occurring in magnetic systems and in monolayer depositions.

In particular we **focus on the regime** when the amount of each phase is not conserved in time.

![Ferromagnetic System]()
![AuOnAu](images/phase_separation/GoldOnGold.png?raw=true)
[Au thin film, black spots indicate holes in the first layer. The surface touches an acqueos solution of Au atoms and an acid KCl. Applying a strong potential difference between the surface and the STM tip, atoms are electrochemically detached from the first layer, way faster than the surface diffusion rate.]




# A continuos theory (TDGL)
We have a **simple continuos** model to describe this kind of phase separation.
In fact it is possible to give a **continuos** description by defining a **scalar order parameter** as the **local magnetization**.

Then the dynamics of the order parameter, close to the critical temperature is

$$\partial u = \Delta u + Cu - u^3$$

where C is a parameter that we can control by changing the Temperature $C\propto (T_c-T)$.

![PhaseDiagramIsingB=0](images/phase_diagram.png?raw=true)

By going from positive to negative value of C, the disordered phase goes from stable to unstable, so we have the spinoidal decomposition.


### Universality
This equation is called time-dependent Gitzburg-Landau equation, because it cames from the Landau-Gitzburg theory.
As that theory is accurate close to the critical point, then this equation **must hold for all systems** that resemble the simmetries of the Ising model, as soon as the temperature is close to the critical point.

# Goal

So the question that motivates our work is: can we control the properties of the domains (shape, size, density) by only changing a **macroscopic variable** as the **temperature** (close to the critical value)?

In order to understand what properties of the domains we can control, we need to understand how the dynamics of the boundaries is affected by changes of temperature over time.

### Motion by curvature

The mechanism governing the dynamics of interfaces **at fixed temperature** is motion by curvature.

Each point of an interface moves with a normal velocity proportional to the local curvature $\kappa$.

$$v = -\kappa$$

![Image with some domains and arrow with lenght prop to minus the curvature](images/arrows_motionbycurvature.png?raw=true)



### Tools
To check if this behaviour is affected by changes in temperature over time, we **developed** both analytical and numerical tools:
- **Analytical tool**: Multi-scale expansions that enable to study the system response in the limits of fast and slow changing temperature. 
- **Numerical tool**: We implemented an existing code for simulations. We realized it used to fail in simulating some features of the dynamics. So we made a study for selecting the right integration algorithm and we adopted Crank-Nicholson in Fourier space. 

We considered a simple initial state, where the curvature is constant all over the boundary.

![chaos_rightarrow_circularIsland](images/simpler.png?raw=true)

There we checked **quantitatively** motion by curvature in the simulations, for a fixed temperature.
Then we saw that it is still present when you change temperature in time: both for slow and fast oscillating temperature. And this is in agreement with our analytical studies.

![T(t)_graphs](.)

This means that **we cannot do much** by simply changing temperature in time.

# Backup slides

![extrapolatingSlope](images/extrapolation_motionbycurvature.png?raw=true)