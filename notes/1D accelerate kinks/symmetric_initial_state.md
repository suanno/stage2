# Symmetric initial configuration
You can prepare the initial state, such that you find the same distance between the kinks, wheter you calculate the distance moving to the left or to the right (think that **periodic boundary conditions** are adopted).

In this case, as the initial state is _symmetric_ there is no reason why the kinks should attract in one direction or the other.
So we expect their distance does not change over time.

## Simulation with $d_0 = L/2$
In the following simulation, in order to take an initial distance of $d_0=20$, like we usually do, we took a smaller simulation box
$$L=40;\quad d_0=20$$
[here the value we choose for $t_c$ to calculate the x-axis of the bottom left plot is not relevant, as $d(t)$ is constant in time.]
![L=40](d0=20/.old/varying_L/L=40_d=20.gif?raw=true)


But it is sufficient for the initial state to be **slightly asymmetric** to see an annhilation eventually. As you can see in the following simulation, where
$$L=45;\quad d_0=20$$
![L=45](d0=20/.old/varying_L/L=45_d=20.gif?raw=true)
