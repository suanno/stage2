### Title
I'm Rocco Suanno and I'm presenting my phd project on Optimal Nano-structure design at crystal surfaces.

### CV
I'm a master degree student in Solid state physics and quantum technologies at the university of Milano Bicocca.

There I did my bachelor thesis in theoretical physics, where I studied a chaotic system known as the standard map. My contribution was verifying some statistical properties numerically with codes that I developed.
Then I had also an experience in experimental physics in a low temperature lab, where characterized a trasmission line that served to read out the state of a superconducting quantum bit.
And recently, after the suggestion of a professor, I've decided to move here and to do my **FINAL** internship at the Institut Lumiere Matiere, where I would like to extend my permanence as a phd student.

[Slowly]
Now I will present the work of my internship and the project of the following phd.

### Project 1
Let's consider a crystal surface. Under non-equilibrium conditions, like **growth conditions**, non-trivial nano-strucure emerge at the surface.
Here we have two experimental pictures, on the left we have nanostructures of **atomic thickness**, so they are **2D monolayer islands**. While on the right we have more complex **3D nano-structures**.

To reach those configuration, all the variables that we can control during the growth (like temperature and flow of particles) are kept **fixed** as this is the **usual** way of doing crystal growth.

In our project, we want to actively control the surface morphology at nano-scale. This means for example controlling position and shape of these monolayer islands.
And we propose a **new approach** to achieve this control, that is varying physical parameters both in time and in space, so they are not kept fixed.

### What inspires us

This work is inspired by some technological challenges.
In fact, as we are interested in controlling shape and size of the nanostructures at the surface, our work could be relevant for designing quantum dots, that are nano-scale systems very used in micro-electronics and photonics.

But to achieve this control of the surface morphology, we need to understand **what are the basic mechanisms** that determine how matter organizes in the presence of external forces.
And as those basic mechanisms **limit** our control on the system, we want to understand
- first what are the properties of the morphology we can control
- and then how we can control them

-----------------------

Now I will present my internship work.

### Internship

In my internship I foucsed on controlling 2D monolayer islands.

### Monolayer
Here is a schematic for the dynamics of a monolayer.
The atoms of a gas can adsorb and desorb, leading to structures like these, that have really atomic thickness. So they are really **two dimensional** objects.

This means we can describe the state of the surface with a scalar field, that tells wether a region is occupied or not. So we have the white occupied phase and the black un-occupied phase.

### Spinodal decomposition
This system is interesting because it undergoes spinodal decomposition.
In fact there is a critical temperature, that is represented in the left diagram by the bifurcation point.
This diagram illustrates what people usually do in experiments, that is a rapid quench of the temperature. This leads to the phenomena on the right, where domains of the occupied and unoccupied phases emerge from a disordered configuration. This phenomena is known as spinodal decomposition and we can see it both in a simulation and a real experiment.

In this simulation we see the dynamics after the temperature quench. After the domains appeare, they evolve with coarsening dynamics, meaning their lenghtscale increases as a power law _of time_.

### Model
The model we use for describing spinodal decomposition, is the TDGL equation.
This equation contains a parameter C that depends on temperature.
To understand the physical meaning of C, here we have the **same** diagram shown before, where we see that a positive C corresponds to a lower temperature and a negative C to an higher temperature.

In my internship we studied the dynamics under **arbitrary** variation of temperature in **time**, which means arbitrary variations **of C** in time. This is more general than considering a rapid quench, that is what people usually do.

In particular we wanted to "understand if it's possible to control the position and the shape of the domains by changing temperature over time".

### Motion by curvature
From our model, follows that at fixed temperature, that means constant C, the interfaces between domains **move** with a velocity that is normal to the interface and proportional to the local curvature. This dynamics is known as motion by curvature.

What we discovered, is that it doesn't matter how you change temperature over time, the dynamics of the interfaces **will not** be affected by the changes.
This means that **it's not possible** to control the shape of domains by changing temperature in time.

### Quantitative checks
We checked this quantitatively with simulations. In fact we developed a code, starting from an existing one and changing the integration algorithm to reach better accuracy at large times.
Then we made some analytical calculations, exploiting that in our system there are two timescales: the one of the interface motion and the one of the variations of C.
In the limit of slow and fast oscillating C, we could define a small parameter and expand the terms of the equation in this parameter. And we found that the motion by curvature is still present. 


### A general phenomena
Before presenting the phd project, I want to point out that there are **many systems** showing a dynamics that is **similar** to the one of the monolayer islands.
For instance this is a polymer solution after a quenching of the temperature. And this is a colloidal solution, after being steered.
In both cases wee see spinodal decomposition, so we expect that our results apply **also** to those systems.

-----------------------

Now I present my phd project

### Phd
Within the Phd project, we would like to focus on controlling 3D nanostructures.

In addition we will consider more general driving forces (as electromigration, where an electric current produces a flux of mass at the surface. The morphology on the left is produced by electromigration, starting from a crystal facet. While on the right we see an experimental proof that you can move monolayer island exploiting this phenomena).
We will also consider drivings that are **can vary** both in time and in space.

### Phd: Time
Actually we're not the first considering time dependent driving forces.
In fact here are **simulations** of the **cross section** of a thin film; that is obtained from deposition of a binary alloy, under two different conditions.
This group used a genetic algorithm to find how to change the deposition rate in time to reach those target states.
But the problem of this approach is that the genetic algorithm is a **black box** so it doesn't provide **theoretical** understanding of the underlying physics.
This means that we cannot generalize this method, in the sense we cannot formulate an universal strategy for reaching an arbitrary target

### Phd: Space
We will also consider space depending driving forces.
For example a prepatterned substrate will force the structures to grow in particular positions.
We want to invert this relation so, starting from a desired spatial configuration of the nanostructures, we want to **prepare** the substrate in such a way that it leads to that configuration.

To achieve this, we have to
- make the target configuration a stationary state of the system (this means solving an inverse problem)
- and then, if the stationary state is unstable, we will use techniques from optimal control theory to stabilize it.

### Phd

We can use optimal control also to find the best policy to change the driving forces in time to reach the target state. 

In addition, we will use Reinforcement learning, that is a very powerfull machine learning scheme that will give us insights about what properties of the system can be controlled.

By using both the approaches, we will also be able to quantify the performances of machine learning, knowing the **analytical solution** to some problems from optimal control theory.