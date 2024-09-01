## What we simulate
The initial state is a state with two kink
$$u(x) = \tanh((x-x_-)\sqrt{\frac12})-\tanh((x-x_+)\sqrt{\frac12})-1$$
where $x_+-x_- \equiv d$ is the distance between the kinks and $L\in[0,L]$ where $L$ is the size of the simulation box.

If $C$ is constant, we expect the distance to decrease logaritmically, with a decay time $\sim e^{-d_0}$.

But in the following simulations, we use
$$C(t)=1+1.5\sin(2\pi t/T);\quad T=35$$
So the average value $\bar{C}>0$, but sometimes $C(t)<0$.
And $T$ is large compared to the intrinsic timescale $\tau \sim \frac{1}{\bar{C}} = 1$.
So we are in the _slow varying limit_.

## How the radius $R(t)$ is measured
An estimate of the distance $d$ is obtained by measuring the distance between the zeros of the function $\partial_{xx}u$, as the interfaces are points where the curvature of the state $u(x)$ changes.

## Simulation with $d_0<<L/2$
In the following **animation**, the measured value of $R(t)$ is represented along with other quantitities.
- **top left**: The state u(x)
- **bottom left**: $\log d(t)$ v.s. $\log (t_c-t)$
- **top right**: Plateau between the kinks $u(L/2)$
- **bottom right**: $C(t)$ 

The value $t_c$ represent the time when the kinks annhilate. It is estimated just by looking at the data of $d(t)$. The estimate of $t_c$ used in the bottom left panel is reported as the title of that panel.
Changing the value of $t_c$ used to calculate $\log(t_c-t)$ influences the plot for values of $t$ close to $t_c$ but not for the values that are very far.

![L=128](d0=20/varying_L/L=128_d=20.gif?raw=true)

### Amplitude of the plateau's oscillation
The plateau between the kinks ($u(L/2)$) oscillates periodically between about 0 and 1.6, where $1.6\simeq\sqrt{C_{max}}=1.58$ where $C_{max}=2.5$ is the maximum value assumed by $C(t)$.

## Simulation with $d_0 = L/2$
This is a special case because, due to the periodic boundary conditions, the distance between the kinks is the same wether you measure it from right to left or from left to right.

Due to this simmetry of the initial state, we expect this distance to be constant in time. This is confirmed by the following simulation, where
$$L=40;\quad d_0=20$$
[here the value we choose for $t_c$ to calculate the x-axis of the bottom left plot is not relevant, as $d(t)$ is constant in time.]
![L=40](d0=20/varying_L/L=40_d=20.gif?raw=true)


But it is sufficient for the initial state to be **slightly asymmetric** to see an annhilation eventually. As you can see in the following simulation, where
$$L=45;\quad d_0=20$$
![L=45](d0=20/varying_L/L=45_d=20.gif?raw=true)