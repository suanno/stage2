Data: ".saves/twokinks/"

# Accelerating the kink's annhilation with non-strictly positive $C(t)$ 

Those numerical results show that **it's possible** to **accelerate** the annhilation of two neighboring kinks, by oscillating $C(t)$ in such a way that
$$\braket{C} > 0 \qquad C(t) < 0 \quad \text{for some t}$$

You can then exploit this effect to select the distance between the two kinks.

# Initial state$
It was prepared with _twokinks.c_.
$$u(x, t=0) = \tanh (x)-\tanh(x-d_0) + 1$$

This is a state with a kink and and antikink at a distance $d_0$. 

For $d_0 = 10$, the initial state is
![d0=10_init](d0=10/initial.png?raw=true)

# Non-strictly positive C(t)
During the following simulations, we adopted
$$C(t) = 0.5 + \sin(2\pi t/T)$$
for different values of $T$.
And we monitored the distance of the kink/anti-kink pair as a function of time $d(t)$.

# Measuring the kinks position
If we consider the initial state, it has an interesting propery: it changes curvature at the kinks' positions, so $u_xx = 0$ at a kink.

Then, if they are sufficiently far so they do not overlap, their distance changes in time $d=d(t)$. BUT their analytical shape doesn't change! So the above property is preserved in time, and can be exploited to measure $d(t)$ as a function of time,

The measure of $d(t)$ is performed, at each time step
- calculating the second space derivative of the state $u_xx$;
- looking for its two zeros and measuring their distance $d(t)$.


# Accelerating the annhilation
**Notice:** From now on, in the reported plots, some data of the measured distance is not represented. We represent only data measured at time $t$ such that
$$2\sqrt{C(t)/2} < d(t)$$
where $d(t)$ is the measured value of the distance.
This is a naive condition to **exclude measures** where the kink and the anti-kink **overlap**, so our method to measure $d(t)$ doesn't work.


- **Simulation** for an initial distance $d_0 = 10$
$$C(t) = 0.5 + \sin(2\pi t/T)\quad \forall t$$

![d0=10_acceleration](d0=10/distance.png?raw=true)

- **Simulation** for an initial distance $d_0 = 20$
$$C(t) = 0.5 + \sin(2\pi t/T)\qquad\text{Until $t\simeq 800$}$$
$$C = 1 \quad\text{fixed}\qquad\text{After $t\simeq 800$}$$

You can see that the value of the distance at the end of the $C(t)$'s oscillation, **is kept** after we switch to constant C.

![d0=20_distance_control](d0=20/.old/distance.png?raw=true)

The final state is

![d0=20_final](d0=20/.old/final_state.png?raw=true)