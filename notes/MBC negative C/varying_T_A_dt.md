# Scenario
Simulation of the 2D TDGL equation, starting from an initial state that is an **isolated circular island**
$$u(r,t=0) = \tanh((r-R_0)2^{-\frac12})$$

where $R_0$ is the initial radius of the domain. In our simulation
- $R_0 = 40$
- $dx=0.1$, $L=128$ (size of the simulation box)

### What we expect (Motion by curvature)
If $C$ is **constant** and the curvature is large compared to the interface thikness $\sim 1$ (this is true at any time $t$, except when $t\rightarrow t_c$ that is the **collapse time** of the domain).

We proved
$$R^2(t)-R_0^2 = -2t$$
so the island shrinks, preserving the circular shape, until it collapses (disappears) at $t_c = \frac12 R_0^2=800$.

### What we do

We verify, with simulations, the last equation when $C=C(t)$, in particular
$$C(t)=\bar{C}+A\sin(2\pi t/T)$$
with $\bar{C}>0$, **but** $C(t)<0$ **for some values of $t$**.

# Varying the period $T$
Data: ".saves/23_08_(D,E,F)"

Here we set
$$C(t)=1+1.5\sin(2\pi t/T)$$
and we make simulations for different values of $T$.

As we want to compare simulations with different values of $T$, we would like to present plots where on the $x$-axis there is $t/T$ instead of $t$.

Dividing
$$R^2(t)-R_0^2 = -2t$$
by $T$, we find
$$\frac1T [R^2(t)-R^2_0]=-2\frac{t}{T}$$
so we verify the last relation, by plotting
- $y = \frac1T [R^2(t)-R^2_0]$
- $x = \frac{t}{T}$
expecting a linear dependence with slope $-2$ (the **dashed red line**)

![varyT](varyT/main.png?raw=true)

The picture presents some **bumps** that show approximately up when
$$(t \mod T) \in [\frac12 T, T]$$
that are the time intervals when $C>0$ but very small, or $C<0$. They show up with period $T$.

## What seems to be Interesting
In the complementary time interval
$$(t \mod T) \in [T, \frac12T]$$
the value on the $y$-axis decays linearly as $\sim -2x$ (as expected).
However, this experimental line **gets more far from the expected red line each period**. And this separation grows faster if the period is larger.

To highlight this phenomena, we **plot only datapoint where**
$$(t\mod T)\simeq \frac14T$$
(so we're sure to be at a time $t$ far from the bumps).

![varyTnobumps](varyT/nobumps.png?raw=true)
We adopted $dt=0.01$ for $T=1,10$, while $dt=0.1$ for $T=100$.

**Notice:** As the simulations show that, far from the bumps, 
$$(R^2(t)-R_0^2)/T\propto t/T$$
then also 
$$(R^2(t)-R_0^2)\propto t$$
with the **same** proportionality factor.
# Varying the amplitude $A$
We made simulations with
$$C(t)=1+A\sin(2\pi t/T);\quad T=10$$
And $dt=0.01$ in all the simulations.
![varyA](varyA/main.png?raw=true)
And considering only the datapoints when $(t\mod T)\simeq T/4$
![varyAnobumps](varyA/nobumps.png?raw=true)

# Varying $dt$
Here we studied a case where $T=10$ and another where $T=100$

### T=10

$$C(t)=1+1.5\sin(2\pi t/T);\quad T=10$$
and we run simulations with different values of $dt=0.01, 0.02, 0.05$.

We want to understand if the behaviours observed in the previous simulations **are real or just a numerical effect**.

![varydt](varydt/main.png?raw=true)
And considering only the datapoints when $(t\mod T)\simeq T/4$
![varydtnobumps](varydt/nobumps.png?raw=true)

Now we consider the slopes of the dashed black lines and we plot them as a function of $dt$

![dt_extrapolation](varydt/extrapolation.png?raw=true)

For a purely numerical effect, we expect that an extrapolation towards $dt\rightarrow 0$ leads to a zero slope.
Instead here we find that the growth of the distance between the experimental $(R^2(t)-R^2_0)/T$ and the expected value $-2t/T$ is of order
$$\sim -10^{-3}\quad \text{per period}$$

As the distance of the 3 datapoints from the black line is much smaller than the extrapolated value at $dt=0$ (the red point is the origin (0;0)), I guess that this phenomena **is NOT a numerical effect**.



### T=100

$$C(t)=1+1.5\sin(2\pi t/T);\quad T=100$$
and we run simulations with different values of $dt=0.1, 0.2, 0.05$.

![varydtT=100](varydt/T=100/main.png?raw=true)

Plotting only datapoints where $(t \mod T)\simeq \frac{T}{4}$
![varydtT=100](varydt/T=100/nobumps.png?raw=true)

Extrapolating the slope at $dt\rightarrow 0$

![varydtT=100](varydt/T=100/extrapolation.png?raw=true)

Here the order of the slope is higher
$$\sim -10^{-2}\quad \text{per period}$$

### Conclusion (varying dt)
Both the extrapolations (in the case T=10 and in the case T=100) show that there is an influence of the $C(t)$'s oscillation on the speed of MBC.
However, the extrapolations also show that this effect is one order of magnitude larger if $dt=0.1$ (for T=100) or $dt=0.01$ (for T=10) is used.

## About the choice of $\bar{C}$
The initial state is prepared with an interface thickness that is the equilibrium one when $C=1$ constant. In fact, the 1D stable stationary state for $C$ constant is
$$u(x)=\tanh((x-x_0)(C/2)^{\frac12})$$
and the initial state is prepared like this, with $C=1$.
As a consequence, it is as if 
$$C(t)=1\quad\forall t<0$$
so, in order for $C(t)$ to be **continuos**, we are not free to choose $\bar{C}$ and we have to set
$$\bar{C}=1$$
