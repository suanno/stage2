**Notice that**: Here we DO NOT assume $C$ to be constant.
Anyway, after the assumptions we make, $C(t)$ has **NOT arbitrary** time dependance, but it is **not necessarly constant**!

# Motion by curvature

## Assumptions
**Assumptions** (statements that must be true to be able to truncate the expansion at 1st order)

- The interface curvature is small (large curvature radius)
- The field $u(\xi, s)$ slowly varying changing $s$, respect on changing $\xi$.

    **Notice that**: Experimentally you can see that, after a transient, **there is only one lenghtscal in the system** (maybe this can be described with scaling theory ideas, but let's keep the reasoning **intuitive**).
    So you **intuitively expect** that the lenghtscale for **curvature $\kappa$ changes** by changing $s$, is the same of $u$.
    So assuming $u$ depends slowly on $s$ (fixed $\xi$) _brings to_ **intuitively expect** that even $\kappa$ depends slowly on $s$, _and with the same lenghtscale_.

- Slow dynamics, such slow that
    - Interfaces (normal) velocity is slow varying in time (_about constant_ velocity).
    - Interface's shape is slow varying in time.

    The dynamics is controlled by **$C(t)$, SO we need it to be slowly varying in time to have a slow dynamics**.
    BUT this does **NOT necessarly** mean that the **timescale of $C(t)$** variations **is the same** timescale of interface shape change / interface speed.
    
    [Maybe the timescale of $C(t)$ has to be **equal or less** the one of interface shape/speed **???**]

    Additionally, we have to focus on coarsening dynamics, so we work at times not so large to see extremal dynamics.

## Make the problem Simple

**Simplicity assumption** (statement made just for simplicity, it is not a matter of orders of $\epsilon$ you have to keep when truncating the expansion):

Those quantities have the **same order**
- Curvature $\kappa=\frac1r$
- Ratio of the lenght-scale for $u$ variations by changing $s$, over the lenght-scale of variations moving along $\xi$
- Interface (front) velocity $v$

This means that
- $\kappa = \epsilon K_1$, with $K_1\sim 1$
- If you define $S=\epsilon s$ then it holds **both**
    $$ \quad \delta S\sim 1 \implies \delta u \sim 1\\
    \quad \delta \xi\sim 1 \implies \delta u \sim 1$$
    So it follows that
    $$\partial_s = \epsilon\partial_{S} \quad\text{ with } \quad\partial_S \sim \partial_{\xi}$$

- $v = V_1\epsilon$, with $V_1\sim 1$

Where **the $\epsilon$ is the same**!


## Wave propagation of the interface

While the fact that both the
- Shape of the interface
- Velocity (normal) of the interface

have weak time dependance (about constant in time), you can say that
$$u(\xi,s,t) = u(\xi-vt, s)$$
That is the solution of the 1D **half**-wave equation (half because the interface moves in one direction, while the 1D wave equation has solution for wave propagating in both directions)

$$\partial_t = -v\partial_{\xi} = -\epsilon V_1\partial_{\xi}$$
the spatial derivative is in $\xi$ because the interface has only normal velocity (for an interface, that is not a particle/flow of particles, **is NOT POSSIBLE to define a _tangential_ velocity**).
Anyway, the interface propagate normally, so along $\xi$.

## Finding the front velocity

So we have the following relations:

$$\Delta u = \partial_{\xi\xi} + \epsilon K_1\partial_{\xi} + \epsilon^2\partial_{SS}$$
where the derivative have the same order, so we can neglect higher powers in $\epsilon$.
$$\partial_t = -\epsilon V_1 \partial_{\xi}$$
so we can get rid of the time derivative from the differential equation.

TDGL becomes, **up to first order** in $\epsilon$
$$-\epsilon V_1\partial_{\xi} u= \partial_{\xi\xi} u+ \epsilon K_1\partial_{\xi} u+ Cu - u^3$$

**Notice that**: there are no $s$ derivatives, so $u = u(\xi, t)$ **at least up to first order**. 

If you then expand
$$u = u_0 + \epsilon u_1 + ...$$
You find
- Order $\epsilon^0$

$$u_0(\xi, t) = C(t)^{\frac12}\tanh(\xi C(t)^{\frac12}2^{-\frac12})$$

**Notice that**: We're not assuming $C$ to be constant; but just that it is slowly varying, to have a slow dynamic and so slow variation of interface shape and slow and slow varying speed.

- Order $\epsilon^1$

$$(\partial_{\xi\xi} + C -3u_0^2)u_{1} = -(V_1 + K_1)u_{1}$$

That, by using the **Fredolm Alternative** and **assuming** that
$$[\partial_{\xi}u v - u\partial_{\xi}v]_{\partial\Omega} = 0$$

where the evaluation is at the borders of the whole space you describe with $\xi$,$s$ coordinates.
The derivative in $\xi$ at the borders will not depend on the direction you approach the borders, **if the interface(s) are far from the borders**.

You find the "Motion by curvature"
$$V_1 = -K_1$$

So the interface (front) propagates with a speed that is $v = -\epsilon K_1$.


## Why there is no explicit time dependance in $u$?

The reason is that we're using a coordinate system ($\xi$, $s$) where $\xi = 0$ means that we are **on** the interface, but **the interface moves in time** as there is motion by curvature!

So we do not see this movement explicitly in the solution $u(\xi)$, BUT just because we're using a coordinate system **that moves with** the interface.


--------------------------


# [Solved] Pointing out problems (now I added answers in the text above)
## About requiring the curvature is slow varying in $s$

The only place in the **Lecture 3** where I find this statement used, is when you calculate the laplacian in the curvilinear coordinates by starting from the **polar coordiantes** expression.
As, in order to use the polar laplacian, you need to place the origin of the coordinates system in a _specific point_ that depends _where on the interface you are_ (it depends on $s$), then if you move along the interface, the polar coordinate system changes (as **the origin moves**).

So you expect that using the (local) polar coordinates laplacian expression is a **good approximation** if the interface is about circular, so the origin of the polar coordinates **changes only slightly** _when moving along the interface_.

**BUT** the (approximated) formula you get for the laplacian contains derivatives in $s$!

So 
- Having a slow varying curvature **is not sufficient to get rid of the $s$ derivatives!!!**
- Additionally, you can consider the exact expression of the laplacian and get rid of the $s$ derivatives without asking that the curvature is slow varying. So it is **not even a necessary condition!**

To get rid of the $s$ derivatives, you consider the exact expression of the laplacian and you ask that

"$u$ changes slowly when moving along a curve with fixed $\xi$ (moving along $s$, but $\xi$ not necessarly 0), **respect on** how much it changes moving along $\xi$"

so you can neglect the $\partial_{s}$ in favor of the $\partial_{\xi}$ derivatives.

**Lastly**: We never quantify (with an $\epsilon$) the slowness of curvature change, so i think it is not necessary to ask slow curvature change.

## About $C(t)$ time dependance
We asked it to be slowly dependent over time, in order for the dynamics to be slow and so to consider the interface shape slowly varying (and even its speed)

BUT we **never quantified this slowness**!
