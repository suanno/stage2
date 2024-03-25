# Checking Crank-Nicholson for flat profile evolution

Here we show there are no problems of saturation/exponential decay at large times of the **space average** $u(t)$ in a **flat profile evolution** under 
$$C(t) = A\sin(2\pi t T)$$

We expect an asymptotical decay of $u(t)$ to zero as
$$u(t)\sim t^{-\frac12}$$

- By using Implicit Euler we can see a saturation _after_ the above expected asymptotics.
- By using Explicit Euler we can see an _exponential_ decay, instead of a power law one.

See more in other notes by searching the words "implicit euler, explicit euler".

![explicitvsimplicit](../../Plots/saturation%20plots/Explicit%20do%20not%20saturate.png?raw=true)

Instead, if we use Crank-Nicholoson algorithm, we see the corrected expected behaviour.

## 1D
(dt = 0.001)

![CrankNicholsonDontSaturate](Plots/1D%20Cave=0%20dt=0.001.png?raw=true)

## 2D
(dt = 0.01)

![CrankNicholsonDontSaturate](Plots/2D%20Cave=0%20dt=0.01.png?raw=true)


