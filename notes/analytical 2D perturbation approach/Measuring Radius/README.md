# Abstract
We see that, when **measuring** the radius of a circular island, this measure obeys the _motion by curvature law_, but with an **effective initial** radius that is different from the real one.

This is a **numerical problem** due to the **space discretization**, as the mismatch with the expected relation is reduced by reducing $dx$.

But it does not seem a **problem** of the integration algorithm, but **only of the measure** of the radius, due to the difficulty of resolving the peak position of the function $|\nabla u|$.
In fact, if we take the average of $r^2$ with $|\nabla u|^2$, that is **less peaked and larger** than $|\nabla u|$, we get a better match with the same $dx$.

Then there is **another numerical error** due to time discretization.
In fact we have a mismatch **far from the initial transient** of the **slope** of $R^2(t)$.
This mismatch is reduced with $dt$ and this is a feature of how we integrate the dynamics.

[WIP] **IT COULD BE** that the mismatch respect to motion by curvature is due to an **asymmetry** of $|\nabla u|$ that rises **due to numerical error**.
Intuitively the asimmetry is amplified if we take a square root.
In this case the error is a feature of the whole dynamics, not only of the way we measure the radius.

# Costant C
### Measuring $R^2$ by taking an average of $r^2$ weighted on $|\nabla u|$ (we take the _square root_).

![sqrt](sqrt_grad2.png?raw=true)

It looks like there is an **effective INITIAL radius R0** that is different from the initial radius when $C\neq 1$.
Because we see the expected motion by curvature
$$R(t)^2 = \tilde{R_0}-2t$$
but with $\tilde{R_0}\neq R_0$.

![constC](../Measuring%20Radius/effective_radius.png?raw=true)

## A numerical problem due to _SPACE discretization_

This behaviour (apparent effective radius existance) is **numerical**, as it changes by changing **dx**.

Here **C=0.1** constant
![constC](../Measuring%20Radius/C=0.1_dx.png?raw=true)
![constC](../Measuring%20Radius/C=0.1_dt.png?raw=true)

I guess the fact that we see a closer behaviour to the expected motion by curvature by decreasing $dx$ is due to the fact that the **gradient is very peaked** and we cannot resolve the **position of the peak** if $dx$ is not sufficiently small. 

So we can weight our average of $r^2$ on $|\nabla u|^2$ instead of taking the square root for calculating $|\nabla u|$.

### Measuring $R^2$ by taking an average of $r^2$ weighted on $|\nabla u|^2$


![NOsqrt](grad2.png?raw=true)

We see a better match if we do not take the square root!
As taking or not the square root does not affect how we integrate the dynamics, but only how we measure the radius, we state that 

    This transient behaviour we see by changing C is not a feature of the simulation, but only of the measure of R. 

![constC](../Measuring%20Radius/grad_grad2.png?raw=true)


## Additional numerical error due to TIME discretization
The mismatch we see **after the transient** from the expected behaviour
$$R^2(t) = R_0^2 - 2t$$
is due to **time discretization**.
In fact the **slope mismatch** is reduced by reducing $dt$.

This is a feature of the algorithm integrating the dynamics, and not only of the way we measure $R^2$.
In fact, you can see from one of the next plots that the slope does not change if we change the way we calculate the average of $r^2$.
![changingdt](../Measuring%20Radius/mismatch_dt.png?raw=true)


# Oscillating C(t)

### Comparing $|\nabla u|$ and $|\nabla u|^2$
![changingdt](../Measuring%20Radius/oscillatingC_grad_grad2.png?raw=true)

## Measuring asymmetry of $|\nabla u|$ [WIP]
We measure **a slice of** the function $|\nabla u|$ for fixed $x=L/2$ and we quantify the asymmetry of the 1D function we get.

We do that for $C=1+1\sin(2\pi t/T)$ and we study two times $t$ when $C\simeq 0$ and $C\simeq 1$.

- $C(t)\simeq 0;\quad t=19$

![grad_C=0](../Measuring%20Radius/asym_grad.png?raw=true)
![grad2_C=0](../Measuring%20Radius/asymm_grad2.png?raw=true)


-----------------------

-----------------------

-----------------------

### Other experiments averaging over $|\nabla u|$
We see that we have the highest mismatch when $C$ approaches $C=0$.
This is the same **transient behaviour** that we see when we start from $C=0.1$.

![changingdt](../Measuring%20Radius/C0=1A=1.png?raw=true)
![changingdt](../Measuring%20Radius/C0=1A=0.5.png?raw=true)
![changingdt](../Measuring%20Radius/C0=1A=0.1.png?raw=true)

