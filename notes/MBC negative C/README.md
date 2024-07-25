Here we explore how MBC is affected by an oscillating $C(t)$ with 
$$\braket{C} > 0 \qquad\text{BUT}\quad C(t) < 0 \quad \text{for some t}$$
Notice that in our analytical analysis we assumed $C(t)>0$ always, such that we could make an expansion around the kink stationary state $u_0(x)$ (that does exist only if $C>0$, otherwise there is only a flat u=0 stationary state!)


# Initial state
We used _circleinit.c_ to prepare the initial state as an isolated circular island.

$$L = 128\quad R_0 = 40 \quad dx = 0.1$$

Then we adopted
$$C(t) = 0.5 + 1\sin(2\pi t/T)$$
$$T = 20, 200, 2000 \quad \text{and}\quad C=0.5\quad\text{constant}$$

# Measuring the radius
We calculate $R^2$ by making an average of $r^2$ weighted on $(\nabla m)^2$, that is a function very peaked at the kink.

# Results
![circular_island_C_negative_oscillating](bumps.png?raw=true)

We can see 
- **bumps** with an amplitude that increases with the period $T$. They appear with the same period of $C(t)$. Previous investigation pointed that those bumps appear along an **asymmetry of the kink** that appears when $C\rightarrow 0^+$. And now that $C$ gets negative the amplitude seems to be bigger.

So the bumps do not represent an oscillation of the radius of the island, BUT I guess they are due only to the asymmetry.

- The average (in time) of $R^2$ decays **a little bit faster** when the period is larger.
A longer simulation has to be done to make a fit at long time and check if the prefactor of the linear decay is $-2t$. **BUT** this requires a larger system, because after a time $R_0^2/2$ the island collapses!!!

# Asymmetry of $(\nabla m)^2$
We evaluate $(\nabla m)^2$ along the line $x=L/2$ (so $r=y$ is the radial coordinate).

We do so on a state generated with $T=200$ and at the time $t=150$ that is the one when $C$ has the smallest value ($C(t=150)=-0.5$) and it is the time of the peak of the (first) bump.

![asymmetryBIG](grad2%20asymmetry/1D%20slice.png?raw=true)

You can see that the extimate of the radius of the island obtained as the square root of the average of $r^2$ weighted on $(\nabla m)^2$ (that is supposed to be a good extimator as the gradient square is supposed to be very peaked at the kinks) is different than the value of the peak of the gradient squared.

### Statement

That points out that "the mode and the average are different", so the gradient squared **is asymmetric respect to its maximum**. This implies that **the kink itself has an asymmetric shape!!!**

This asymmetry will influence of course the average of $r^2$ so it is the reason of the bumps.

### Idea to explain it
The bumps appear when $C$ goes close to zero or to negative value. When $C$ is positive but close to zero, there is a stationary kink state, but its width is very big. So there could be an overlap of the kinks at $y=+r$ and $y=-r$ that makes the kinks asymmetric!



![asymmetryBIG](grad2%20asymmetry/zoom_1D_slice.png?raw=true)


