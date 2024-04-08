# Flat profile evolution (with oscillating $C(t)$)

The algorithm implemented in "tdgl.c" is the (2D) Crank-Nicholson algorithm.

Here we show there are no problems of saturation/exponential decay at large times of the **space average** $u(t)$ in a **flat profile evolution** under 
$$C(t) = 0 + A\sin(2\pi t T)$$
We consider $\bar{C}=0$ because it is the most interesting case.

We expect an asymptotical decay of $u(t)$ to zero as
$$u(t=nT)\sim t^{-\frac12}$$

![flatprofileaverage2D](Plots/flat_profile.png?raw=true)

