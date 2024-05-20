### Title

### CV
I briefly present myself.
I'm Rocco Suanno and I'm a master degree student in Solid state physics and quantum technologies at the university of Milano Bicocca.

During my studies I had a first intership in theoretical physics, where I studied a chaotic system known as the standard map. My contribution was verifying some statistical properties numerically with codes that I developed.
Then I had also an experience in experimental physics in a low temperature lab. I did a lot of manual work to characterize a trasmission line that served to read out the state of a superconducting quantum bit.
And recently, after the suggestion of a professor, I've decided to move here and to do my final internship at the Institut Lumiere Matiere, where I would like to extend my permanence as a phd student.
So now I will present the work of my internship and the project of the following phd.

### Project 1
In the last 20 years people have studied film growth on crystal facets.
By setting the temperature or the chemical potential to a **different** value, we bring the system out of equilibrium and this leads to morphologies like these ones.
Here we have two experimental pictures, on the left the structures have **atomic thickness**, so they are **monolayer islands**. While the structures on the right are so small that effects due to quantum confinement become relevant.

Up to now, the research in this field focused on understanding **how** the applied non-equilibrium conditions are related with the emerging morphologies.
**But** that's **not** what we want to do. **Instead** we want **actively control** the morphology, so we want to understand **how can we can manipulate** matter in order to control the position and the shape of those clusters of atoms.
And the approach we adopt is to change the growth parameters in **time** and **space**, while usually they are kept fixed during the growth process.

### Potential Applications

A sufficient control **on** these structures, could lead to **potential** applications in the fields of microelectronics and photonics. That's because these structures are known as quantum dots, and have relevant usage in both fields.
Being able to control their shape, could bring to a new method for designing them, avoiding expensive litographic techniques.

Within the phd, we're **not** going to **solve** the open problems in the two fields, but this potential application is the **ispiration** behind our **fundamental** research.

What we ask is, Can we control anything? Or there are some properties of the morphology that **cannot** be controlled? 


### Project 2
In my internship I foucsed on controlling monolayer islands.
Then in the phd we would like to explore **more rough** morphologies.

### Monolayer
Here is a schematic for the dynamics of a monolayer growth.
The atoms of a gas can adsorb and desorb, leading to the evolution o    clusters of atomic thickness.

So we can describe the state of the surface with a scalar field, that tells wether a region is occupied or not. This means we've two phases, the occupied and the unoccupied one.

### Spinoidal decomposition
The physics following from this schematic is the **one** of the Ising model.
So there is a critical temperature and if you bring the temperature under this value, you go from a single stable disordered phase to **two** stable ordered phases.
This leads to emerging domains of the occupied and unoccupied phases, that we see both in a simulation and a real experiment.

After the temperature quench, the domains evolve with coarsening dynamics, meaning their lenghtscale increases as a power law of time.

### A general phenomena
But this phenomena is way more general and is known as Spinoidal decomposition.
Here we have a polymer solution undergoing spinoidal decomposition after a quenching of the temperature. And here we have a colloidal solution confined in a microchannel, after being steered.

### Model
There is a well-known model for describing spinoidal decomposition, that is the TDGL equation.
This equation depends on a parameter C that depends on temperature and it describes the distance of the system from the critical point.

In my internship we studied the dynamics under **arbitrary** variation of temperature in **time**, which means arbitrary variations **of C** in time. This is more general than an simple quench of the temperature.

In particular our goal was to "understand if it's possible to control the shape and the size of the domains by changing temperature over time".

### Motion by curvature
We already knew that, at fixed temperature, the interfaces between domains evolve with a velocity that is normal and proportional to the local curvature. This dynamics is known as motion by curvature.

What we discovered, is that it doesn't matter how you change temperature over time, the dynamics of the interfaces **will not** be affected by the changes.

### Quantitative checks
We checked this quantitatively with simulations. We developed our code, starting from an existing one and changing the integration algorithm to reach better accuracy at large times.
Then we made some multiscale analysis, that enabled to study the dynamics in the limits of fast or slow oscillating temperature.
We found that motion by curvature **still** governs the dynamics in those limits and this is coherent with the simulations.

So this has been my internship work.




### Phd
Now with within the Phd project we would like to extend our challenge to the control of rough morphologies and to consider more general driving forces (as an electric field that is tangential to the surface) for controlling monolayer clusters.

### Phd: State of the art
We're not the first working on this subject. In fact in the last years people have used machine learning an genetic algorithms to control crystal growth.
For instance this is a simulation of the the cross section of a thin film of a binary alloy, that is obtained through physical vapor deposition.
Both the deposition rate and the surface mobility are changed over time by a genetic algorithm, that managed to reach those configurations. 

Now the main problem of using those algorithm for controlling the growth, is that we find how to reach some configurations, but we do not know what configuration we can reach and what we cannot, as there is no theory linking how we modulated the growth parameters in time and the final configuration. 

### Phd: Our goal
The goal of the project is to understand what properties of the surface morphology we can control and what we cannot control.
And this is not a trivial question, because during the internship we discovered there is something that we cannot do, as controlling the dynamics of monolayer clusters by changing temperature in time.

The way we're goind to work, is to understand how reach a target state and how to stabilize a configuration.