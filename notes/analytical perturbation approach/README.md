# Perturbation approach

We know that, if the "dynamic is slow", that means

    If the variation of C(t) is slow compared to the system's relaxation time

the system will **follow** the stationary state (that is stationary only if $C$ is constant)
$$u_0 = \sqrt{C}\tanh(x\sqrt{C/2})$$

The idea is to write $u(x,t)$ as a serie of a **small** parameter $\epsilon$, that describes **how much is slow** the dynamics.
As we know what happens when the dynamics is extremely slow, we **hope that we can neglect** the higher order terms and study **up to first order** in $\epsilon$.

## What is $\epsilon$?
We can "choose" the small parameter in this way
[by choosing it we say finding a suitable parameter, so a parameter that is small **and** describes the slowness of dymamics]

The fact that $C(t)$ is slowly varying can be formalized by saying that
$$C(t) = \tilde{C}(\epsilon t)$$
where $\epsilon$ is very small and $\tilde{C}(\tau)$ is a function that sees "significant changes" **only if** you have a variation of at least $\Delta \tau \sim 1$.

This means that $\epsilon^{-1}$ is a characteristic time for the $C(t)$ variation.
So more $\epsilon$ is small and more time you need to wait to see changes in $C(t)$.
This is the property we are looking for $\epsilon$, so this is a suitable candidate to be the expansion parameter!

## The expansion
The most natural way of expanding is

$$u(x, t) = u_0(x,t) + \epsilon u_1(x,t) + O(\epsilon^2)$$

where **we require that**

$$u_0(x,t) = \sqrt{C(t)}u_{k_0}(x\sqrt{C(t)})$$
$$u_{k_0}(\chi) = \tanh(\chi/\sqrt{2})$$
as we know that if $C(t)$ is extremely slow varying ($\epsilon\rightarrow 0$) then this is the state.

Now we want to find $u_1(x,t)$ and, to do so, we **have to make assumptions**.
Notice that, by making assumptions, you are reducing the d.o.f. of the problem, because you are looking _only for solutions with a particular shape_.
It is not granted that you will find a solution and wether this will be unique; but if you find a solution, you can check numerically if that is **the one followed by the system**.
[But if you manage to find a "solution" up to first order and then you cannot match the equation for higher oder, then what you find is a solution or not? I would say no! ???]

## Assumptions
- $u_1(x, t) = \beta_1(t)u_{k_1}(\alpha_1(t)x)$
- $\alpha_1 = \alpha_0 = \sqrt{C(t)}$

By putting the above constraint, you find an equation
$$\alpha'(u_)$$

