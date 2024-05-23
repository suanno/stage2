### Title
I'm Rocco Suanno and I'm presenting my phd project on Optimal Nano-structure design at crystal surfaces.

### CV
I'm a master degree student in Solid state physics and quantum technologies at the university of Milano Bicocca.

There I had a first intership in theoretical physics, where I studied a chaotic system known as the standard map. My contribution was verifying some statistical properties numerically with codes that I developed.
Then I had also an experience in experimental physics in a low temperature lab. I did a lot of manual work to characterize a trasmission line that served to read out the state of a superconducting quantum bit.
And recently, after the suggestion of a professor, I've decided to move here and to do my **FINAL** internship at the Institut Lumiere Matiere, where I would like to extend my permanence as a phd student.
So now I will present the work of my internship and the project of the following phd.

### Project 1
Let's consider a crystal surface. Under non-equilibrium conditions, non-trivial nano-strucure emerge at the surface.
Here we have two experimental pictures of morphologies that you can reach with out of equilibrium conditions. On the left we have nanostructures of **atomic thickness**, so they are **2D monolayer islands**. While on the right we have more complex **3D nano-structures**.

In our project, we want to actively control the surface morphology at nano-scale. This means for example controlling position and shape of these monolayer islands.
The approach we propose, is to achieve this control by changing physical parameters both in time and in space.

### What inspires us

This work is inspired by some technological challenges.
In fact, we are interested in driving **the organization** of matter on a solid surface. And this could be relevant for designing quantum dots, that are nano-scale systems very used both in micro-electronics and photonics.

In this project we want to ask **fundamental** questions about control, like
What properties of the surface morphology we can control?
And how we can control them?

-----------------------

Now I will present my internship work.

### Internship

In my internship I foucsed on controlling 2D monolayer islands.

### Monolayer
Here is a schematic for the dynamics of a monolayer.
The atoms of a gas can adsorb and desorb, leading to structures like these, that have really atomic thickness. So they are really **two dimensional** objects.

This means we can describe the state of the surface with a scalar field, that tells wether a region is occupied or not. So we have the white occupied phase and the black un-occupied phase.

### Spinodal decomposition
The physics following from this schematic is the **one** of the Ising model, so this is the diagram of the **stable phases** as a function of temperature. The bifurcation point corresponds to the critical temperature of the system and if you do a temperature quench under this value, you go from a single stable disordered phase to **two** stable ordered phases.
This leads to emerging domains of the occupied and unoccupied phases, from a disordered initial state. This phenomena is known as **spinodal decomposition** and we see this both in a simulation and a real experiment.

After the temperature quench, the domains evolve with coarsening dynamics, meaning their lenghtscale increases as a power law of time.

### Model
The model we use for describing spinodal decomposition, is the TDGL equation.
This equation contains a parameter C that depends on temperature.
To understand the physical meaning of C, here we have the phase diagram of the system as a function of C, instead of temperature. The sign of C determines in what region of the diagram we are.

In my internship we studied the dynamics under **arbitrary** variation of temperature in **time**, which means arbitrary variations **of C** in time. This is a **new** approach, way more general than a simple quench of the temperature.

In particular we wanted to "understand if it's possible to control the position and the shape of the domains by changing temperature over time".

### Motion by curvature
From our model, follows that at fixed temperature the interfaces between domains **move** with a velocity that is normal to the interface and proportional to the local curvature. This dynamics is known as motion by curvature.

What we discovered, is that it doesn't matter how you change temperature over time, the dynamics of the interfaces **will not** be affected by the changes.
This means that **it's not possible** to control the shape of domains by changing temperature in time.

### Quantitative checks
We checked this quantitatively with simulations. We developed our code, starting from an existing one and changing the integration algorithm to reach better accuracy at large times.
Then we made some multiscale analysis, that enabled to study the dynamics in the limits of fast or slow oscillating temperature. And we got results coherent with the simulations.


### A general phenomena
Before presenting the phd project, I want to point out that there are **many systems** showing a dynamics that is **similar** to the one of the monolayer islands.
For instance this is a polymer solution after a quenching of the temperature. And this is a colloidal solution, after being steered.
So we expect that our results apply also to those systems.

-----------------------

Now I present my phd project

### Phd
Within the Phd project, we would like to focus on controlling 3D nanostructures.

In addition we will consider more general driving forces (as electromigration, where an electric current produces a flux of mass at the surface).
And we will also consider drivings that are **non homogeneous** both in time and in space.

### Phd: Time
Actually we're not the first considering time dependent driving forces.
In fact here are simulations of the **cross section** of a thin film; that is obtained from deposition of a binary alloy, under two different conditions.
This group used a genetic algorithm to find how to change the deposition rate in time to reach those target states.
But the problem of this approach is that you get a **solution for THIS SPECIFIC target**, but you you don't have a **general policy** that tells how to change the driving forces in time to reach the target state.

### Phd: Space
We will also consider space depending driving forces.
For example a prepatterned substrate will force the structures to grow in particular positions.
We want to invert this relation so, starting from a desired spatial configuration of the nanostructures, we want to **prepare** the substrate in such a way that it leads to that configuration.

To achieve this, we have to
- make the target configuration a stationary state of the system
- and then, if the stationary state is unstable, we will use techniques from optimal control theory to stabilize it.

### Phd

We can use optimal control also to find the best policy to change the driving forces in time to reach the target state. 

In addition, we will use Reinforcement learning, that is a very powerfull machine learning scheme that will give us insights about what properties of the system can be controlled.

By using both the approaches, we will also be able to quantify the performances of machine learning, knowing the **analytical solution** to some problems from optimal control theory.