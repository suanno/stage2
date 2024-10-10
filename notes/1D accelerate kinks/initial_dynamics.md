# Effects of space discretization on the initial dynamics

If you look at $d(t)$ during the first seconds of a simulation, you see that the distance remains constant for many periods $T$ before decreasing, sometime, of one/two units $dx$.
This is **for sure NOT PHYSICAL**. It makes **no sense** that "some oscillations of C(t) do not affect d(t) and others do"!

This is due to the **space discretization** that makes impossible to measure changes of the distance smaller than the unit $dx$.

But, as soon as the dynamics becomes **fast enough**, so

    As soon as d(t) decreases in a period T more than dx
then you start seeing that the decreasing of $d(t)$ reflects the period of $C(t)$.

### Full dynamics (simulation) [you can see the initial dynamics]
![](d0=20/movies/Cbar=0.5T=50A=1/full_simulation.gif?raw=true)

### Later dynamics (simulation) [you can see the same periodicity in C(t) and d(t)]
![](d0=20/movies/Cbar=0.5T=50A=1/later_dynamics.gif?raw=true)
