### Title
I'm Rocco Suanno and today I'm presenting my phd project on Optimal Nano-structure design at crystal surfaces.

### CV
I'm a master degree student in Solid state physics and quantum technologies at the university of Milano Bicocca.

There I did my bachelor thesis in theoretical physics, where I studied a chaotic system known as the standard map. My contribution was verifying some statistical properties numerically with codes that I developed.
Then I had also an experience in experimental physics in a low temperature lab, where characterized a trasmission line that served to read out the state of a superconducting quantum bit.
And recently, after the suggestion of a professor, I've decided to move here and to do my **FINAL** internship at the Institut Lumiere Matiere, where I would like to extend my permanence as a phd student.

[Slowly]
I will start presenting the work of my internship and then I will focus on my phd project.

### Project 1
So, let's consider a crystal surface. Under non-equilibrium conditions, like **growth conditions**, non-trivial nano-strucure emerge at the surface.
_Here we have_ two experimental pictures, on the left we have nanostructures of **atomic thickness**, so they are **2D monolayer islands**. While on the right we have more complex **3D nano-structures**.

_To reach_ those configuration, all the variables that we can control during the growth (like temperature and flow of particles) are kept **fixed**. And this is the **usual** way of doing crystal growth.

In our project, we want to actively control the surface morphology at nano-scale. This means for example controlling position and shape of these monolayer islands.
And we propose a **new approach** to achieve this control, that is varying the physical parameters both in time and in space, so they are not kept fixed.

### What inspires us

This work is inspired by some technological challenges.
In fact, we are interested in controlling shape and size of the nanostructures at the surface and this could be relevant for designing quantum dots, that are nano-scale systems very used in micro-electronics and photonics.

But to achieve this control of the surface morphology, we need to understand **what are** the basic mechanisms that determine how matter organizes in the presence of external forces.
And as those mechanisms **limit** our control on the system, we want to understand
- what are the properties of the morphology we can **and cannot** control
- and then how we can control them

-----------------------

Now I will present my internship work.

### Internship

Where we foucsed on controlling 2D monolayer islands.

### Monolayer
This is a schematic for the dynamics of a monolayer.
The atoms of a gas can adsorb and desorb, leading to these white structures, that have really atomic thickness. So they are really **two dimensional** objects.

This means we can describe the state of the surface with a scalar field, that tells wether a region is occupied or not. So we have the white occupied phase and the black un-occupied phase.

### Spinodal decomposition
This system is interesting because it undergoes spinodal decomposition.
In fact you can proove that this system is equivalent to the Ising model, so there is a critical temperature, represented by the point of the bifurcation in this diagram.
This diagram illustrates what people usually do in experiments, that is a **rapid cooling of the system**, so the temperature is brought under the critical value quickly. This leads to the phenomena on the right, where domains of the occupied and unoccupied phases emerge from a disordered configuration. This phenomena is known as spinodal decomposition and we can see it both in a simulation and a real experiment.

In this simulation, we can see what happens **after** the spinodal decomposition.
Once the domains appear, they evolve with coarsening dynamics, so their _average size_ increases as a power law _of time_.

### Model
The model we use for describing spinodal decomposition, is the TDGL equation.
This equation contains a parameter C that depends on temperature and to understand the physical meaning of C, here we have the **same** diagram shown before, where we see that a positive C corresponds to a lower temperature and a negative C to an higher temperature.

-------------
This equation has been studied only when the parameter C is **constant** in time, that means at **fixed** temperature.
Instead, we studied the dynamics under **arbitrary** variation of C in time, that means arbitrary variations of the temperature. And this is way more general than considering a rapid cooling.
------------

In particular we wanted to "understand if it's possible to control the position and the shape of the domains by changing temperature over time".

### Motion by curvature
From our model follows that, at fixed temperature, that means constant C, the dynamics is governed by motion by curvature. This means that the interface between two domains **moves** with a velocity that is normal to the interface and proportional to the local curvature.

Before my internship we didn't know **anything** about the dynamics under time dependent C. And what we discovered, is that **it doesn't matter** how you vary the parameter over time, the motion by curvature will **still** be present.
This means that **it's not possible** to control the shape of domains by varying the temperature in time.

### Quantitative checks
We checked this quantitatively with simulations. In fact we developed a code to find approximate solutions of this equation. Actually we already had a code, but I implemented a new integration method, to have better accuracy at long time.

Then we made some analytical calculations, exploiting that in our system there are two timescales: the one of the interface motion and the one of the variations of C in time.
So in the limit of slow and fast oscillating C, we could define a small parameter and expand the terms of the equation in this parameter. And what we ***proved** is that, at leading order, we have still motion by curvature. 


### A general phenomena
Before presenting the phd project, I want to point out that there are **many systems** showing a dynamics that is **similar** to the one of the monolayer islands.
For instance this is a polymer solution, as time passes after a sudden cooling. While this is a colloid as time passes after steering it.
In both cases wee see spinodal decomposition, so we expect that our results apply **also** to those systems.

-----------------------

Now I present my phd project

### Phd
Where we will focus on controlling 3D nanostructures.

In addition we will consider more general driving forces (as electromigration, where an electric current produces a flux of mass at the surface.
The morphology on the left is produced by electromigration, starting from a **flat** crystal facet. While on the right we see an experimental proof that you can **move** monolayer islands with electromigration).

-----------
Then we will consider driving forces that are **can vary** in time and in space.
----------


### Phd: Time
Actually we're not the first considering time dependent driving forces.
In fact this is a **simulations** of the **cross section** of a thin film; that is obtained from deposition of a binary alloy, under two different conditions.
This group used a **genetic algorithm** to find how to change the deposition rate in time to reach those target states.
But the problem of this approach is that the genetic algorithm is a **black box** so it doesn't provide **theoretical** understanding of the underlying physics.

And we don't like this, because we want to develop an **analytical theory** that will help finding an **universal** strategy to reach **any** arbitrary target. 

### Phd: Space
We will also consider space depending driving forces.
For example, a prepatterned substrate will force the nanostructures to grow in particular positions.
We want to invert this relation so, starting from a target configuration of nanostructures, we want to find the substrate morphology that determines it.

This means:
- solving an inverse problem, where you require the target state to be stationary
- and then, if this stationary state is unstable, we will use techniques from optimal control theory to stabilize it.

### Phd

We can use this theory also to find **the best way** to change the driving forces in time to reach the target state. 

In addition, we will use Reinforcement learning, that is a very powerfull machine learning scheme that will give us insights about what properties of the system can be controlled.

### Calendar
To conclude my presentation, I want to show our work plan.
In the first year, we will work on space-depending driving forces, like the prepatterned substrate that I showed.
Then, in the second year we will look at time-depending forces. In particular we will look for **what** physical variables you can vary in time to control the nanostructures. And this is non-trivial, as we saw there are some properties that you **cannot** control.
While in the last year we will compare the our results with experiments, collaborating with a laboratory in Marseille.