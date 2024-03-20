# Perturbation approach

We know that

    If the variation of C(t) is slow compared to the system's relaxation time

the system will **follow** the stationary state (that is stationary only if $C$ is constant)
$$u_0 = \sqrt{C}\tanh(x\sqrt{C/2})$$

we call this regime of the dynamics **adiabatic dynamics**.
But the system evolves **exactly** adiabatically only when 
$$\tau_C / \tau_{relax}\rightarrow \infty$$
if the ratio is finite, we have **corrections** to the **ideal** adiabatic dynamics.

We want to find those corrections, with the idea of writing $u(x,t)$ as a serie of a **small** parameter $\epsilon$, that describes **how much we are close** to the adiabatic dynamics.
As we know what happens in the adiabatic dynamics, we **hope that we can neglect** the higher order terms and study **up to first order** in $\epsilon$.

## Two timescales $\tau_C$, $\tau_{relax}$
Before looking for a suitable small parameter $\epsilon$, we calculate the two relevant timescales.

The characteristic time for the evolution of $C(t)$ can be defined as the time $\tau_C$ such that

$$\Delta t \sim \tau \implies \Delta C \sim 1$$

Then we've another timescale.
Consider the case when $C$ is kept constant $C_0$ for a long time and then its value is **improvvisely** changed _and then kept constant_ $C_0'$.
Before the change, the system is in the stationary state associated with $C_0$ and then _will start to move_ towards the one associated with $C_0'$.
But **how much time it takes?**

If we look far from the kink's center, the state is about flat so the TDGL equation reduces to _the one for flat states_

$$\partial_t u = Cu-u^3$$

In our case, after the change, $u$ is no more the stationary state associated with $C$, but a small deviation (if the change in $C$ was small)

$$u = u_0 + \epsilon \eta(t)$$
Now let's study the evolution of $\eta(t)$ to see **how fast** the system reaches the stationary state

$$\eta(t) = \eta_0 e^{-2Ct}$$

So
$$\tau_{relax} = \frac{1}{2C}$$
## What is $\epsilon$?
Unfortunately, $\tau_{relax}$ depends on the **instantaneous** value of $C(t)$, while $\tau_{C}$ doesn't.

So we cannot define a small parameter $C$ that is both
- time independent
- quantifies the relationship between the two timescales

What we can do is to choose the small parameter as
$$\epsilon = \tau_C^{-1}$$
so it goes to zero when the variation of $C(t)$ in time is extremely slow.

Then, to take into account the fact that the adiabatic dynamics is true only when $\tau_C << \tau_{relax}$, we **expect that** our expansion **can be truncated** at first order when
$$C(t) >> \frac{\epsilon}{2}$$

If $C(t) = \bar{C} + A\sin(2\pi t/T)$ we can adopt the rule of thumb
$$\epsilon << 2(\bar{C}-A)$$








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
- $\alpha_1 = \alpha_0 = \sqrt{C(t)}$, that we call simply $\alpha$

By putting the above constraints and
- defining $\chi = \alpha x$, so $\partial_x = \alpha \partial_{\chi}, \partial_{xx} = \alpha^2\partial_{\chi\chi}$
- defining $\tau = \epsilon t$, so $\partial_t = \epsilon\partial_{\tau}$
- considering $\alpha' = \partial_{\tau}\alpha$ and $u_k' = \partial_{\chi}u_k$
- equating the first order in $\epsilon$ of the TDGL equation

 you find this equation
$$\alpha'(u_{k_0} + u'_{k_0}\chi) = C\beta_1(u''_{k_1} + u_{k_1}-3u_{k_0}^2u_{k_1}')$$

Now, in order to recover an ODE, you **add an additional constraint** to remove the time dependance

$$C\beta_1 = \alpha' = \partial_{\tau}\sqrt{C} = \frac12 C'C^{-\frac12}$$

So
$$\beta_1(\tau) = \frac12 C'(\tau)C^{-\frac32}$$
$$u_{k_0} + u'_{k_0}\chi = u''_{k_1} + u_{k_1}-3u_{k_0}^2u_{k_1}'$$

So we can solve numerically the last equation and find a numerical solution for $u_{k_1}(\chi)$.
## Measure deviation form stationary state $\Delta u = u - u_0$

Let's consider the quantity
$$\Delta u = u - u_0 = \epsilon\beta_1u_{k_1}(\alpha x) + O(\epsilon^2)$$

we **can measure** this quantity, because we know that
$$u_0 = \sqrt{C}\tanh(\sqrt{C/2}x)$$

### Verifying analytical behaviour of $\beta_1$

We see from the experiments that $\Delta u$ reaches a plateau when $x >> 0$.
And also from the numerical solution of the ODE for $u_{k_1}$ we see a plateau.

So, if $x>>0$ we have

$$\tilde{\Delta u} \simeq \epsilon\beta_1(t)\tilde{u_{k_1}}$$

where we can measure both the plateau value, by evaluating $\Delta u$ at $x>>0$ and by looking at the ODE for $u_{k_1}$ in the $x>>0$ limit

$$0 = \tilde{u_{k_1}}(1-3)$$
$$\tilde{u_{k_1}} = -\frac12$$
where we've used that $u_{k_0}\rightarrow 1$ faster than $\chi$.

So we can extimate $\epsilon\beta_1$, by measuring the plateau value of the deviation $\tilde{\Delta u}$ as

$$\epsilon\beta_1 \simeq - 2\tilde{\Delta u}$$

By using
- $\beta_1 = \frac12 C'(\tau)C^{-\frac32}$
- $\alpha = \sqrt{C}$