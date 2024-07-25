Data: ".saves/twokinks/"

Those numerical results show that **it's possible** to accelerate the annhilation of two neighboring kinks, by oscillating $C(t)$ in such a way that
$$\braket{C} > 0 \qquad C(t) < 0 \quad \text{for some t}$$

I will show before that you can accelerate the process with which the kinks get closer, then I will show that you can use this to select the distance between the two kinks.

# Initial state
It was prepared with _twokinks.c_ ($dx = 0.1$).
$$u(x, t=0) = \tanh (x)-\tanh(x-d_0) + 1$$

This is a state with a kink and and antikink at a distance $d_0$. For $d_0 = 10$
![d0=10_init](d0=10/initial.png?raw=true)

# Measuring the kinks position
If we consider the initial state, it has an interesting propery: it changes curvature at the kinks' positions, so $u_xx = 0$ at a kink.

Following this idea and assuming that, as time passes, the two kinks get closer (so d=d(t)) BUT their shape does not change, we can MEASURE the kinks' positions at each time by calculating the second space derivative of the state $u_xx$ and looking for its two zeros.

This is a good way of measuring the distance **when the distance of the kink is much greater than their width (OVERLAP)**. Otherwise what happens is that, if you consider the initial state's shape, if $d_0$ is not much greater than the kinks width (that in the initial state is 1), then the zeros of $u_xx$ are not spaced anymore by a distance $d_0$.

So when we read the data, we should take into account that the distance between the zeros of $u_xx$ that we measure is not always a good measure of the distance between kinks.

# Accelerating the annhilation
**Notice:** From now on, in the reported plots, some data of the measured distance is not represented. We represent only data when the condition
$$2\sqrt{C/2} < d$$

Where the LH side is twice the width of a kink if you keep $C>0$ costant for a long time $\Delta t >> \frac1C$. So this is a naive condition to state "when the kinks do not overlap".

- $d_0 = 10$

![d0=10_acceleration](d0=10/distance.png?raw=true)

# Controlling the distance (between neighbouring kinks)

- $d_0 = 20$

We oscillated $C(t)$ to accelerate the closening of the kinks and then I put $C=1$ constant in order to **relax** the shape of the kinks towoards the one of the stationary state associated to $C=1$ constant.
You can see that the value of the distance **is kept** after we switch to constant C.

![d0=20_distance_control](d0=20/distance.png?raw=true)

The final state is

![d0=20_final](d0=20/final_state.png?raw=true)