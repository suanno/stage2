# Background on TDGL
$$\partial_t m = \Delta m + C(t)m-m^3$$

## Gitzburg landau Free Energy ansatz
The G-L ansatz is that, close to the point of a phase transition (the _critical point_) the Free Energy $F$ can be approximated as an **analytical function** of the order parameter.
As this parameter is a **scalar field** the expansion contains space derivatives of $m(x)$ over its powers.

$$F_{GL} = F_0 + \frac12|\nabla m|^2 + Hm +am^2 +bm^3 + pm^4 + ...$$

From the simmetries of the system, we can conclude that some coefficients (H,a,b,p,...) are zero.
This means that systems that show the same simmetries (at the level of the G.L. Free Energy ansatz) **share** the **same shape** of the Free Energy near the critical point, **so we expect they behave the same** close to that point (**universal** behaviour).

### 'Close' to the critical point
We require to be close to the critical point because **here the order parameter is very small** (because "before" the phase transition the order parameter is zero).
So close to this point we can TRUNCATE the expansion.
This is the (only) reason why we _stress out_ the requirement of being close to the phase transition point, as we HAVE TO TRUNCATE the expansion for **practical usage** of the ansatz.

In principle you could include all the terms and not be constrained being near the critical point. But for practical purposes, you truncate the expansion.

## The Ising model
Let's consider the ising model, where there is no external magnetic field.
In general we consider that there are **no external fields** and the **ONLY field _you can tune_ is temperature $T$**.

There is no preferential direction (up or down), so the Free Energy must be even

$$H=0\qquad b=0$$

Let's consider the coefficients $a, p$ and let's look for their temperature dependance.

### $m^2$ coefficient ($a$)
In the (isolated) Ising model you have a **spontaneous breaking** of the up/down simmetry when $T$ becomes lower than a critical value $T_c$.
Instead, if $T>T_c$, the (space) average magnetization is zero (the statistical average is 0).

In order for the G-L ansatz to describe this phenomena, the Free Energy expression must show
- A non-degenerate global minima at $m=0$ if $T>T_c$
- Two degenerate minimas, one positive and one negative (and simmetric), if $T>T_c$

If you truncate the expansion at the quartic term ($m^4$), **in order for your TRUNCATED expansion to describe correctly the model** (at least the spontaneous magnetization effect), you need that

- $a < 0$ if $T < T_c$
- $p > 0$ for any $T$

Those are the conditions for the potential
$$V(m) = am^2 + pm^4$$
to be
- A **double well potential** if $T<T_c$
- A single well (at $m=0$) potential if $T>T_c$

Then, as exactly at $T=T_c$ we have the transition from a single to a double well, we have that

$$a(T=T_c) = 0$$

As the TRUNCATED ansatz is supposed to hold only close to the critical point (because here the order parameter is small), we can use the truncated expansion ONLY close to the phase transition point.

This means that there is no loss of generality in expanding $a(T)$ close to the critical point ($T\simeq T_c$).
As $a(T)$ goes zero when $T\rightarrow T_c$, we have that

$$a(T) = 0 + a_0(T-T_c) + O((T-T_c)^2)$$
where 
$$a_0 > 0$$
because it must hold that $a<0$ if $T<T_c$. 


We consider only the first order: $a\simeq a_0(T-T_c)$.

### $m^4$ coefficient (p)
We can also expand $p(T)$ close to the critical point, as the truncated expansion is supposed to work only there

$$p(T) = p(T=T_c) + p_1(T-T_c) + ...$$

But now $p_0 = p(T=T_c)$ is not necessarily zero!
In particular, in order for $p>0$ for any $T$ (so even at $T=T_c$), it must hold that
$$p_0 > 0$$

Then, as not only $(T-T_c)$ is small close to the critical point, **but the order parameter $m$ too**, we neglect the term $p_1(T-T_c)$ as 
$$p_1m^4(T-T_c)$$
is of **higher order than**
$$a_0m^2(T-T_c)$$

-----------
So the TRUNCATED expression for the Free Energy is

$$F = F_0 + \frac12|\nabla m|^2 + a_0(T-T_c)m^2 + p_0m^4$$

That we can write as
$$F = \frac12|\nabla m|^2 + V(m)$$
where the potential is
$$V(m) = a_0(T-T_c)m^2 + p_0m^4$$
and we neglected constant terms summed to energy.

If you rewrite the potential as
$$V(m) = \tilde{V}\frac14(C-m^2)^2$$

and you neglect (summed) constant terms, you find
$$C = \frac{a_0}{4p_0}(T_c-T)$$
That means
$$sign(C) = sign(T_c-T)$$
So
- $C > 0$ if $T < T_c$
- $C < 0$ if $T > T_c$

## Get the TDGL equation
If a physical system is **very overdamped**, then you are used to neglect inertia in $F=ma$, and you say

$$0 = -\gamma \dot{x} -\frac{dV}{dx}$$
and so you end up with a dynamics described by this equation
$$\dot{x} = -\frac{1}{\gamma}\frac{dV}{dx}$$

**Naively** you can generalize this equation, by stating that the dynamycs of a **strongly damped system** is described by the law

$$\partial_t m = -\frac{\delta F}{\delta m}$$
where this is a _functional derivative_.

-----------------

Let's consider the TRUNCATED G-L ansatz for the Free Energy of the (isolated) Ising model, the one described before

$$F = \frac12|\nabla m|^2 + V(m)$$
$$V(m) = \tilde{V}\frac14(C-m^2)^2$$

Performing the functional derivative

$$\partial_t m = \Delta m + m\tilde{V}(C-m^2)$$
$$\partial_t m = \Delta m +C\tilde{V}m - \tilde{V}m^3$$

The TDGL equation we're considering in our work is the above equation where $\tilde{V} = 1$.
And you can remove $\tilde{V}$ from the equation **by rescaling $x$ and $t$** such that

$$\partial_{t} = \tilde{V}\partial_{t^*}$$
$$\partial_{x} = \tilde{V}^{\frac12}\partial_{x^*}$$

We remember the **physical meaning** of the **control parameter** $C(t)$ is
$$C(t) = \frac{a_0}{4p_0}(T_c - T(t))$$
where we stressed out that $C$ can be time dependent as you can change the temperature $T$ in time.

As both $a_0, p_0$ must be positive in order for the TRUNCATED expansion to well describe physics, then
$$sign(C) = sign(T_c-T)$$
So
- $C > 0$ means $T < T_c$
- $C < 0$ means $T > T_c$
