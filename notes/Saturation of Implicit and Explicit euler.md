# Saturation
The Implicit Euler scheme we adopt works like this to solve the TDGL equation in Fourier space ($x\rightarrow q$)

$$`U(q,t+h)=\frac{U(q,t) - hF[u^3](q,t)}{1+h(q^2-C(t+h))}`$$

If then the profile is flat, it remains flat and there is only one mode, that is $q = 0$.
So we have a formula in the real space
$$`u(t+h)=\frac{u(t) - hF[u^3](t)}{1-hC(t+h)}`$$
You can even find the above result by considering the TDGL equation without the space derivative and appy the Implicit Euler scheme in real space.
[You have then to evaluate the Fourier transform of $u^3$ at time $t$ and not $t+h$ in order to get an usable formula].

### Evidence of saturation: A property of the integration scheme
In the code "_implicit euler map.c_" it is implemented **only** the iteration of the map $U(t)\rightarrow U(t+h)$ (there are no lines of code related to FFT, lattice sites, ecc.) for $C(t) = \sin(2\pi t)$.
If you repeat a lot of time the iteration, you find convergence (unless some small oscillation that continue even after the time average is converged) in a **fixed point different from zero**.

The same behaviour we see in the "_tdgl.c_" code, that implements the method, but in Fourier space.

![Plot saturation evidence](../Plots/saturation%20plots/fixed%20point%20evidence.png?raw=true)

Notice that we decided to plot the **absolute value** of $u(t)$ in order to show that a saturation occurs even if the initial value $u_0 < 0$, and the saturation value is **the same but with negative sign**.

Here we see that the saturation value does not depend on the initial condition AND **even if you start very close to zero, you do not converge in zero as expected**.

As we see this behaviour even in the code "_implicit euler map.c_", that **implements the discrete time map and nothing more**, it is not related to FFT and other features of the code "_tdgl.c_", **but just to the integration scheme adopted (Implicit Euler)**.

### Oscillation at long times
We see that $u(t)$ evaluated at times $t=nT$ reaches the same fixed point for every initial value $u_0$.

But even the oscillations, at long times, become the same, independently on $u_0$.
Here we show that the curves $u(t)$ obtained from different initial values overlap at long times.

![longtimes](../Plots/saturation%20plots/overlap%20of%20oscillations%20at%20long%20time.png?raw=true)

Here is, instead, the behaviour at short times, oscillations included
![shorttimes](../Plots/saturation%20plots/oscillations%20at%20short%20times.png?raw=true)


### Explicit Euler doesn't saturate!

![explicitvsimplicit](../Plots/saturation%20plots/Explicit%20do%20not%20saturate.png?raw=true)


Even if, instead of using $u^3(t)$ inside the implicit Euler formula you calculate $u^3(t+h)$ with Explicit Euler and then use it in the Implicit scheme; you have saturation.

Then we enhance that, even if Explicit Euler does not show saturation, **there is still a post-asymptotic behaviour, that is an Exponential decay to zero**)
![explicitPostAsymptotic](../Plots/saturation%20plots/explicit%20euler%20post%20asymptotic.png?raw=true)
![explicitExponentialDecay](../Plots/saturation%20plots/explicit%20euler%20post%20asymptotic%20exponential%20decay.png?raw=true)

This exponential decay begins when $u(t)\sim 10^{-3}$ that is not so close to zero.
So I guess that this behaviour is not only an effect of rounding errors, but of the integration method's error.
# ETD

With this algorithm we don't see any saturation, but still a post-asymptotic exponential decay.
![ETD](../Plots/saturation%20plots/explicit%20implicit%20and%20ETD.png?raw=true)