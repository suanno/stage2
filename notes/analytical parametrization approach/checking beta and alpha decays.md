We measure beta as the plateau value, while alpha from the slope of the tail.

# DISCLAIMER:
**Here we work with an $L=10^3$ lattice.**

We made this choice because previously we had an $L=10^2$ lattice that we found **too small** for our checks for the following reason:

We do not start from a state where $u_k$ has the right shape and $\beta^2 = b\alpha^2$; so the system **needs time to BECOME CONSISTENT** with our analytical ansatz.

But, if the lattice is small, the time the system takes to become consistent with the ansatz is comparable with the time two neighboring kinks **start to overlap** (so we cannot consider anymore them independent).

In addition to the kinks' independance problem when the lattice is small, you have some problems in extimating $\beta$ by evaluating $u(x)$ at the midpoint of two kinks, because the increase of overlap, increases the distance between $u(3/4 L)$ and $\beta$!!!

## $\beta(t)$ can be extimated by evaluating $u(x)$ far from the kink 
(and not too close to the neighboring one)

We extimated it by evaluating $u(3/4 L)$.
This has no problem with the overlap of kinks, for any sampled time $t$, because our lattice is so big that the overlap between neighboring kinks is kept very low for any sampled time $t$.

![beta](Plots/measured%20and%20analytical%20alpha%20beta/beta.png?raw=true)

## $\alpha(t)$ can be extimated from tail slope

The black dots indicate the region where the slope was extimated.
As we expect this asymptotic behaviour **in the tail**, we considered the two extrema (black dots) such that
$$x_1 = x_c + 1/\alpha\quad x_2 = x_c + 2/\alpha$$
where, for the above formulas, we extimated $\alpha$ with the analytical expected value (Remember that $1/\alpha$ is a measure of the **kink's width**).

While $u_k$ was extimated by using the analytical expected value for $\beta$ as
$$u_k = u/\beta$$

![tails](Plots/measured%20and%20analytical%20alpha%20beta/tail.png?raw=true)

The expected slope is
$$\log(1-u_k) \simeq \alpha^2 (x-x_c)^2$$
if you neglect terms that are less relevant when $x$ is big.

But you can be more precise and use this formula
$$...$$

![alpha](Plots/measured%20and%20analytical%20alpha%20beta/alpha.png?raw=true)

## Ratio $\alpha(t)/\beta (t)$

**Notice** that the match of $\beta$ is better than the one of $\alpha$.

The little mismatch in $\alpha$ is the one that causes little mismatch in the ratio.

![ratioBetaAlpha](Plots/measured%20and%20analytical%20alpha%20beta/ratio.png?raw=true)

