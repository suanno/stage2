# Small perturbation of a flat profile

We consider the following initial state, that is a perturbation of a flat profile.
$$u(x,0) = u_0 + \delta u(x)$$

If we guess the shape of the evolution is
$$u(x,t) = u_0(t) + \delta u(x,t)$$
where $u_0(t)$ is the evolution of a flat profile $u(x,0) = u_0$, we end up with the equation

$$\delta U_t(q,t) = (f'(u_0(t))-q^2)\delta U(q,t)$$
$$f'(u_0(t)) = C(t) - 3u_0(t)^2$$

We see that, as $f'(t)$ (in principle) is not costant in time, the equation doesn't have trivial exponential solutions.
Anyway we can try to figure out wether the time dependance is slow or not.

If we assume that this time dependance can be neglected and that **$C > 0$ and costant** (otherwise we have still time dependance or $u(t)\rightarrow 0$) then we find that there are **unstable modes** q if $$f' - q^2 > 0$$ for some mode q, so if

$$f' > 0 \iff |u_0| < \sqrt{C/3}$$

Notice that, in order to see the unstable modes in the numerical solution, you need that

$$L > \lambda_{min}$$

Where $\lambda_{min} = \frac{2\pi}{q_{max}} $ is the wavelenght of the unstable mode with the largest q.

## Unstable modes grow into kinks
The stable modes decay exponentially.
So if all modes are stable, as time passes you _quickly loose the non-flat_ component of the state.

But if there is even a single unstable mode, then this grows exponentially, trasforming the quasi-flat profile in something that isn't flat anymore!

So **we expect** to see that kinks born from quasi-flat states if there are unstable modes, so if $|u_0| < \sqrt{C/3}$.

## Time dependance of $f'(u_0(t))$
We know that, if **$C>0$ constant**, then 
$$u(t) = (e^{-2Ct}(\frac{1}{u_0^2}-\frac1C) + \frac1C)^{-\frac{1}{2}}$$

It follows that, if we calculate the derivative and then take the limit $t\rightarrow \infty$, then

$$u_0(t)\rightarrow u_0$$

$$\partial_t u_0(t) \rightarrow u_0C-u_0^3$$

$$\partial_tf'(t)\rightarrow -6(u_0^2C - u_0^4)$$

If we require that the time dependence of $f'(t)$ is neglegible, so reasonably that

$$|\partial_t f'(0)| << 1$$

we find that this is true wether
- $C$ is very small
- or $u_0$ is very close to 0 or to $\sqrt{C/3}$

Considering the second case, that means that **the time dependance is not negligible always when $0 < u_0 < \sqrt{C/3}$ !!!**, but only when $u_0$ is close to the extremas of the interval.

This **doesn't mean** that you do not expect mode growth away from the extrema, but just that you don't know what to expect by making the above simple considerations.

## Difficulties in verifying the mode growth phenomena

As you expect to see mode growth only in very small intervals of values of $u_0$, it is difficult to see this growth as the flat component $u_0(t)$ increases in time (we work with $u_0 < \sqrt{C}$ to see mode growth, so $u_0(t)$ increases in time).

And, by increasing, $u_0$ exits from the very small interval where both $u_0 < \sqrt{C/3}$ and the time dependance of $f'(t)$ is negligible.

Let's consider both the extremas $0$ and $\sqrt{C/3}$.

- If $u_0$ is close to $\sqrt{C/3}$, by the increasing of $u_0$, you leave the region (of values of $u_0$) where $u_0 < \sqr{C/3}s.
So, then, you have only decaying modes and you fail seeing the mode growth behaviour.

- If $u_0$ is close to 0, instead, by the increasing of $u_0$ you do not leave the region $u_0 < \sqrt{C/3}$, but just the one very small interval where the time dependance of $f'(t)$ can be neglected.

    As you don't know, with those simple considerations, what is the dynamic for these values of $u_0$, you **may hope to** see a mode growth (because you do not have reasons to tell that all modes becames unstable, that is the opposite in the previous case).

- In general, in the region $|u_0| < \sqrt{C/3}$ there is a huge range of $u_0$ values where you don't know what expect with this simple model.
So you can see or not a mode growth, but you cannot tell that you were expecting it or not; at least with this simple reasoning.


# What we see

We said that we expect to see (without rigorous reasons, assuming that the mode growth **is not suppresed** when the time dependance of $f'(t)$ is no more negligible BUT $u_0$ is still less than $\sqrt{C/3}\simeq 0.8$ because **we chose $C=1$**)

a mode growth (and so kink formation) if $u_0$ is very close to zero.
![u0=0.01](../Plots/mode%20growth/u0%20=%200.01.png?raw=true)

Then, if $u_0$ is close to $\sqrt{C/3}$, we said that **we don't have the time** to see the growth, as the flat part of the profile increases.
![u0=0.4b](../Plots/mode%20growth/u0%20=%200.4b.png?raw=true)
![u0=0.4](../Plots/mode%20growth/u0%20=%200.4.png?raw=true)

Finally, in the **intermediate region** (of values of $u_0$) we don't know what expect as the time dependance of $f'(t)$ is not negligible

![u0=0.3](../Plots/mode%20growth/u0%20=%200.3.png?raw=true)
![u0=0.5](../Plots/mode%20growth/u0%20=%200.5.png?raw=true)
![u0=1.2](../Plots/mode%20growth/u0%20=%201.2.png?raw=true)