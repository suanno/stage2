# Saturation
The Implicit Euler scheme we adopt works like this to solve the TDGL equation in Fourier space ($x\rightarrow q$)

$$U(q,t+h)=\frac{U(q,t) - hF[u^3](q,t)}{1+h(q^2-C(t+h))}$$

If then the profile is flat, it remains flat and there is only one mode, that is $q = 0$.
So we have a formula in the real space
$$u(t+h)=\frac{u(t) - hF[u^3](t)}{1-hC(t+h)}$$
You can even find the above result by considering the TDGL equation without the space derivative and appy the Implicit Euler scheme in real space.
[You have then to evaluate the Fourier transform of $u^3$ at time $t$ and not $t+h$ in order to get an usable formula].

### Evidence of saturation: A property of the integration scheme
In the code "_implicit euler map.c_" it is implemented **only** the iteration of the map $U(t)\rightarrow U(t+h)$ (there are no lines of code related to FFT, lattice sites, ecc.) for $C(t) = \sin(2\pi t)$.
If you repeat a lot of time the iteration, you find convergence (unless some small oscillation that continue even after the time average is converged) in a **fixed point different from zero**.

The same behaviour we see in the "_tdgl.c_" code, that implements the method, but in Fourier space.

![Plot saturation evidence](../Plots/saturation%20plots/fixed%20point%20evidence.png?raw=true)

Here we see that the saturation value does not depend on the initial condition AND **even if you start very close to zero, you do not converge in zero as expected**.

As we see this behaviour even in the code "_implicit euler map.c_", that **implements the discrete time map and nothing more**, it is not related to FFT and other features of the code "_tdgl.c_", **but just to the integration scheme adopted (Implicit Euler)**.
### Explicit Euler doesn't saturate!

![explicitvsimplicit](../Plots/saturation%20plots/Explicit%20do%20not%20saturate.png?raw=true)


Even if, instead of using $u^3(t)$ inside the implicit Euler formula you calculate $u^3(t+h)$ with Explicit Euler and then use it in the Implicit scheme; you have saturation.