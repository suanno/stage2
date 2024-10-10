# What concretely happens when $C(t)$ oscillates taking (also) negative values?

In the following **animation**, the measured value of $d(t)$ is represented along with other quantitities.
- **top left**: The state u(x)
- **bottom left**: $\log d(t)$ v.s. $\log (t_c-t)$
- **top right**: Plateau between the kinks $u(L/2)$
- **bottom right**: $C(t)$ 

### top left
The black marks on the top-left plot, highlight **the zeros of** the function $u(x)$. The distance is extimated by evaluating the x-distance between the points.

### bottom left
The value $t_c$ is the annhilation time. The value used to calculate the x-axis data from the data of $t$ is **extimated** by searching **the first time** that $d(t_c) < dx$.

[the frame of the animation are captured each 1 seconds, but the simulation was ran adopting $dt=0.1$]
![](d0=20/movies/Cbar=0.5T=50A=1/later_dynamics.gif?raw=true)

Here we did not show the initial dynamics, that is strongly affected by the space discretization (see [here](initial_dynamics.md))

# Comment
It seems that $d(t)$ (after an _initial behaviour_ where the oscillations of $C(t)$ seem to not affect $d$) is
- **constant** when $C(t)$ **decreases** (from when it reaches the maximum value $\bar{C}+A$ to when it reaches the smallest $\bar{C}-A$).
- **decreases monotonically** when $C(t)$ increases (from when $C(t)=\bar{C}-A<0$ to when $C(t)=\bar{C}+A$).

Look _/../.saves/twokinks/d0=20/Cbar=0.5/T=50/A=1/_ to see each snapshot as a .png