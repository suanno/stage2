# Adiabaticity
If $C=C(t)$ and it is varying slowly respect to the time $\tau$

- Where $\tau$ is the time the system needs, when $C$ is constant (and equal to the value of $C(t)$, so $\tau = \tau_{C(t)}$) to evolve from _any_ (maybe we can require something less strong) state to the stationary state $u_c$

Then we expect $u(x)$ to be, at any time, **following** the stationary state $u_c(x)$

$$u_c(x) = \sqrt{C}\tanh{[(x-\frac{L}{2})\sqrt{\frac{C}{2}}]}$$

That is the stationary state you expect for **constant** C.

## What we expect

If the evolution is adiabatic, we expect that, even if $C=C(t)$, the kink shape (**rescaled**) **is always the same** function

$$y = \tanh(x-L/2)$$

Where the **Rescaling** consists in
- $x\rightarrow x-L/2$, then we multiply by $\sqrt{2/L}$ and finally we readd $x'\rightarrow x'+L/2$    
- $y \rightarrow y/\sqrt{C}$

The rescaling cancels the properies of **height** and **width** of a kink, that can be defined as

- **height**: Double of the (magnitude) of plateaus value
- **width**: Double the distance from the kink site (L/2) to the point x where $y = height/2 * \tanh(1)$


#### BUT the "adiabatic condition"

$$T >> \tau_{C(t)}$$

is not always satisfyied, in particular is not satisfyied when:

- If $C(t)$ is varying close to zero, as when $C$ is constant and close to zero then $\tau$ is big, we expect the system to not evolve adiabatically at times $t$ when $C(t)\simeq 0$. Even if the period $T$ is very big.
- If $T$ is very small.

Considering only the linear part of the TDGL, we find that the characteristic time for the evolution of the system, _with constant_ $C$, is $\tau = \frac1C$.
But
- Neglecting the non-linear term $u^3$ seems to not be possible if $C\sim 1$ and so, at the plateaus, $u\sim 1$.
- I'm not sure that $\frac1C$ is a measure of the time the system takes to move to the stationary state (when $C$ is constant).

**See notes on width and height monitoring** for experimental check of the above statements.