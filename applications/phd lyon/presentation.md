### Title
Good morning, my name is Rocco and I'm a master degree student in Solid State Physics at the University of Milano Bicocca. But currently I'm engaged in an intership here in Lyon at the Institut Lumiere Matiere, where I would like to continue my experience as a phd student.

### Intro
The goal of my internship and the following PhD project is to **control the morphology** of crystal surfaces.
In my internship we focused on a monolayer, that is a bidimensional surface. But during the phd we want to extend our horizons to tridimensional surfaces.

### 2D surface
Let's consider a bidimensional surface in contact with a gas. The atoms of the gas can adsorb and desorb, **but** modifying **only the first** atomic layer.

### 2D systems
What happens is that [under the critical temperature] the morphology of the **monoayer islands** evolve as the magnetic domains of a ferromagnetic system.
**So** we can study the evolution of the surface **by thinking to** the **process of separation** of the two magnetic **phases**, that leads to the formation of magnetic domains.

### Phase separation
Now phase separation **is a very general** phenomena, it does **not** take place **only** in magnetic systems.
For instance here we can see a polymer solution that is quenched under the critical temperature. At time goes on, domains of the poor and concentrated phases rise and grow.
At the bottom instead, we have a colloidal solution confined in a microchannel. After steering the solution, domains rise and expand as time passes.

**But** among all kinds of phase separation, we focused on the **simplest one**, the spinoidal decomposition.

### Spinoidal decomposition
And this is the one occuring both in magnetic systems and bidimensional surfaces when Temperature is close to the critical value.
If we bring the temperature **under** this critical value, we **start** having **two** stable phases and so domains of the two magnetic phases rise.
Now, as we're interested in the morphology of those domains, that is a large scale feature; we can adopt a **continuos** theory to describe the dymamics.

### Continuos theory
And it happens **there is** a well-known model giving a **continuos description** of spinoidal decomposition.
**In fact** this equation dictates the evolution of magnetic domains or monolayer islands, in the regime where the amounts of each phase are not conserved in time. But actually is **way more general**, because it holds **for every** system undergoing spinoidal decomposition.
In the equation there is a parameter C that is Temperature dependent and its sign enables us to choose the region of the diagram where the system is.

The Goal of my internship was to understand **wether we can** control the shape and size of the domains by changing the Temperature over time. And to understand this, we had to understand how the motion of the interfaces is affected by temperature.

### Interfaces' dynamics
At fixed temperature, the dynamics is dominated by motion by curvature, this means that each point of the interface has a velocity that is **normal and proportional** to the local curvature.
To study this behaviour we developed both analytical and numerical tools, as
- multi-scale expansions, that enabled us to predict what happens when the temperature is slowly or fastly oscillating;
- and a code for simulations. We had already a code, but I **had to** change the integration algorithm to have correct predictions at long times. And we came up using Crank-Nicholson in fourier space.

**For simplicity** we considered a state with only one circular domain and we studied its dynamics while changing temperature over time.

And we found that we cannot do **anything!**
In fact we checked **quantitatively** that motion by curvature is **not affected** by changes of temperature both fast and slow; so it is **not possible** to control the morphology **by just** changing temperature in time.