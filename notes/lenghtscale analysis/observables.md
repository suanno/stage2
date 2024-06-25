What observables we can monitor? to see
- coarsening (at long times, when domains are present)
- linear behaviour (at short times from a random initial state)

## Gradient squared (coarsening)
The quantity
$$\int |\nabla u|^2 dxdy$$
where the integral is **over ALL the space**, is a measure of the _total perimeter_ of the domains.
But it is an extensive quantity, as we expect it to grow as the $L$ grows. And we expect it to decrease in time, as we will have less and less domains, with flatter interfaces.

### Intensive quantity
To have an intensive quantity, we can define this lenght
$$\frac{A_{system}}{\int |\nabla u|^2 dxdy}$$
where $A_{system} = L^2$ is the _total area_ of the system.

### Two lenght-scales (long and short scales)
This is an intensive quantity, but it has a dependence over the width of the interfaces!
And that makes this quantity **not good** for monitoring the coarsening, because the scaling $\lambda \sim t^{\frac12}$ affects (at long times) only the **large-scale** features of the system, and NOT the width of the interfaces!
There is another lenghtscale that describes the **short-lenght** features, like the interfaces' width, and we should factorize the dependance on this from the monitored quantity.

### Calculating the interface's thickness
The idea is that, by integrating the gradient squared on the whole space, we measure the "area" of the borders and not only the perimeter; somehow we measure the perimeter times the interface's thickness.
So, to remove the information about the interface thickness, we multiply this $$\frac{A_{system}}{\int |\nabla u|^2 dxdy}$$ times the width/tichness of the interface (multiplying means dividing the integral at denominator).
And the width of the interface can be extimated by integrating the gradient squared along a **line perpendicular to the interface**.

**We expect that** this quantity (interface's thickness) can be calculated by considering the 1D equation and calculating the integral of the gradient squared of _the stationary solution with only one kink_. And we can calculate this analytically, because a stationary solution (1D) solves

$$\partial_{xx} u + V'(u) = 0\quad V(u) = -\frac14 u^4 + \frac{C}{2}u^2$$
And this is the equation of the motion of a point in a 1D _flipped_ double well potential.

There is no friction, so the Energy $E = \frac12(\partial_x u)^2+V(u)$ is conserved and the trajectory with energy corresponding to the potential maxima ($E=V(\pm\sqrt{C})$), it corresponds to the stationary solution with only one kink (it takes infinite time to move from a maxima to the other; and the zero energy is defined as the energy of a maxima)

So, if we consider the stationary solution with a single kink
$$\frac12(\partial_x u)^2 + V(u) = V(\pm \sqrt{C})$$
$$\partial_x u = [2(V(\pm \sqrt{C}) - V(u))]^{\frac12}$$

we can calculate analitically the integral of the gradient squared on the stationary solution with only one kink (that we expect to resemble the value of the integral along a line perpendicular to an interface, in the 2D case).

$$\int (\partial_x u)^2 dx = \int \partial_x u(\partial_x u) dx= \int_{-\infty}^{+\infty} \frac{\partial u}{\partial x}dx(\partial_x u) = \int_{-1}^{+1} du (\partial_x u) = $$
$$ = \int_{-1}^{+1} du [2(V(\pm \sqrt{C}) - V(u))]^{\frac12}$$

And you can calculate this by writing explicitly the expression for $V(u)$ and $V(\pm\sqrt{C})$ and recognizing a square and then drawing the function you see that it means calculating the integral of a parabola. So

$$\int_{-\infty}^{+\infty} (\partial_x u)^2 dx = \frac{2\sqrt2}{3}C^{\frac32}$$

### Resumee
So an intensive quantity, that is not dependent on the short-scale features is

$$\lambda = \frac{L^2}{\int |\nabla u|^2 dxdy}W$$
where, if $C$ is constant in time
$$W = \frac{2\sqrt2}{3}C^{\frac32}$$
As we expect the denominator to decrease, we expect $\lambda$ to increase in time. And, according to coarsening, we expect
$$\lambda \sim t^{\frac12}$$
at long times (once the domain have formed and have become big).

## Average momentum $<q^2>$ (linear regime)
$$<q^2> = \frac{\int q^2|U(q)|^2dq}{D\int |U(q)|^2dq}$$
where $U(q,t)$ is the fourier transform of $u(x,t)$ and $D$ is the dimension of the problem. We normalize by the dimension, because increasing the dimension of the system, you have waves of larger wavelenght (the ones in the _diagonal_ direction and not on x and y).

This is an average, so we expect it to be intensive (???).

### Linear regime
If we start with a **random initial state** and we **look for short times** (or $C(t)$ is such that the $u^3$ term is negligible for the timespan considered), then we expect that

$$\lambda = \frac{2\pi}{<q^2>}\simeq 4\pi t^{\frac12}$$

where the approximation is valid after a small transient, that you can see from this plot
![linearTDGLq2](linear_regime_q2.png?raw=true)
where the curves, from the bottom to the top, correspond to different values of $q_{min} = 10^{-2}, 10^{-1}, 1, 10, 10^2$.
Where $q_{min}$ is the larger momentum (fourier component with the larger $q$) that can exist. Due to the space discretization
$$q_{min} = \frac{\pi}{dx}$$
The red line shows when (for what times $t$) we expect the power-law behaviour $<q^2>\sim t^{-1}$. Of course, at times sufficiently large, the linear approximation (could be) not valid anymore.