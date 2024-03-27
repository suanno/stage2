# Perturbation approach

We know that

    If the variation of C(t) is slow compared to the system's relaxation time

the system will **follow** the stationary state (that is stationary only if $C$ is constant)
$$u_0 = \sqrt{C}\tanh(x\sqrt{C/2})$$

we call this regime of the dynamics **adiabatic dynamics**.
But the system evolves **exactly** adiabatically only when 
$$\tau_C / \tau_{relax}\rightarrow \infty$$
if the ratio is finite, we have **corrections** to the **ideal** adiabatic dynamics.

We want to find those corrections, with the idea of writing $u(x,t)$ as a sum of powers of a **small** parameter $\epsilon$, that describes **how much we are close** to the adiabatic dynamics.
Then, if $\tau_C >> \tau_{relax}$, we **hope we can neglect** the higher order terms and study **up to first order** in $\epsilon$.

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

If $C(t) = \bar{C} + A\sin(2\pi t/T)$ we can adopt the **rule of thumb**
$$\epsilon << 2(\bar{C}-A)$$








## The expansion
The most natural way of expanding is

$$u(x, t) = u_0(x,t) + \epsilon u_1(x,t) + O(\epsilon^2)$$

where **we require that**

$$u_0(x,t) = \beta_0u_{k_0}(\alpha_0 x) = \sqrt{C(t)}u_{k_0}(x\sqrt{C(t)})$$
$$u_{k_0}(\chi) = \tanh(\chi/\sqrt{2})$$
as we know that if $C(t)$ is extremely slow varying ($\epsilon\rightarrow 0$) then this is the state.

Now we want to find $u_1(x,t)$ and, to do so, we **have to make assumptions**.

Notice that, by making assumptions, you are reducing the d.o.f. of the problem, because you are looking _only for solutions with a particular shape_.
It is not granted that you will find a solution and wether this will be unique; but if you find a solution, you can check numerically if that is **the one followed by the system**.
[But if you manage to find a "solution" up to first order and then you cannot match the equation for higher oder, then what you find is a solution or not? I would say no! ???]

## Assumptions
- $u_1(x, t) = \beta_1(t)u_{k_1}(\alpha_1(t)x)$
- $\alpha_1 = \alpha_0 = \sqrt{C(t)}$, **that we call simply $\alpha$**

By putting the above constraints and
- defining $\chi = \alpha x$, so $\partial_x = \alpha \partial_{\chi}, \partial_{xx} = \alpha^2\partial_{\chi\chi}$
- defining $\tau = \epsilon t$, so $\partial_t = \epsilon\partial_{\tau}$
- considering $\alpha' = \partial_{\tau}\alpha$ and $u_k' = \partial_{\chi}u_k$


$$\partial_t u = \epsilon(\beta_0' u_{k_0} + \beta_0 u_{k_0}'\chi\frac{\alpha'}{\alpha})$$

$$\partial_{xx} u = \beta_0\alpha^2u_{k_0}'' + \epsilon\beta_1\alpha^2 u_{k_1}''$$

$$u^3 = \beta_0^3 u_{k_0^3}+ 3\epsilon\beta_0^2 u_{k_0}^2\beta_1 u_{k_1}$$

Putting those expression in TDGL

$$\epsilon\partial_{\tau} u = \partial_{xx}u + Cu - u^3$$


and by Equating the first order in $\epsilon$ of the TDGL equation, you find this equation

$$`\alpha'(u_{k_0} + u'_{k_0}\chi) = C\beta_1(u''_{k_1} + u_{k_1}-3u_{k_0}^2u_{k_1}')`$$

Now, in order to recover an ODE, you **add an additional constraint** to remove the time dependance

$$C\beta_1 = \alpha' = \partial_{\tau}\sqrt{C} = \frac12 C'C^{-\frac12}$$

So
$$\beta_1(\tau) = \frac12 C'(\tau)C^{-\frac32}$$

$$`u_{k_0} + u'_{k_0}\chi = u''_{k_1} + u_{k_1}-3u_{k_0}^2u_{k_1}'`$$

So we can solve numerically the last equation and find a numerical solution for $u_{k_1}(\chi)$.

**NOTICE THAT**: We've imposed a lot of constraints, so we do not know if what we found is the way the system will evolve.
We simply found a solution of the TDGL equation that satisfies the required properties, but maybe it is not unique!

So we **have to** check numerically if the system evolves like this and not according to "another solution". If it is the case, this means that the analytical solution we found is right and so **we know analytically how the system evolves**, at least when $\epsilon$ is sufficiently small ($\epsilon << 2C(t)$)


## Check the consistency of this perturbative method

### Removing the time from the differential equation
When we put a constraint to remove the time dependence, we asked

$$\alpha' = C\beta_1$$
anyway we can remove the time dependence in a more general way
$$k\alpha' = C\beta_1$$
where $k$ is an arbitrary number.

Anyway the choice of $k$ does not affect the **first order correction** 
$$\epsilon\beta_1(t)u_{k_1}$$

as the new analytical expression for $\beta_1$ is $\beta_1 = k\beta_1^{OLD}$, while the new ODE for $u_{k_1}$ is solved by $u_{k_1}$ such that

$$u_{k_1} = ku_{k_1}^{OLD}$$
so the product of the two terms does not depend on $k$.

**Notice**: If you want to consider separatley $\beta_1$ and $u_{k_1}$ you need to **be consistent**. This means that you have to choose the same number $k$ in both the equations for $\beta_1$ and $u_{k_1}$. We set from the beginning $k=1$ so we do not have to think about it.
It is relevant to be consistent (in the above sense) when you compare extimates of $u_{k_1}$ (obtained by using the anlytical expression of $\beta_1$) with the NDSolve numerical solution of the ODE of $u_{k_1}$.

### Choose $\epsilon/2$ instead of $\epsilon$

The **first order** correction **must NOT depend** on the choice of the small parameter $\epsilon$ up to a multiplicative coefficient.
That must hold, because if $1/\epsilon$ is a timescale for $C(t)$, then why $1/2\epsilon$ shouldn't be so?
In addition, for practical purposes, it is better if you do not have to find the "right multiplicative coefficient".

We see in an example that we can multiply $\epsilon$ by a number, without modifying the first order correction.

Let's consider 
$$C(t) = \bar{C} + A\sin(2\pi t/T)$$

And make the different choices
- $\epsilon = 2\pi/T$
    
    $\partial_{\tau} = \epsilon^{-1}\partial_t = T/2\pi \partial_t$
- $\epsilon = \pi/T$
    
    $\partial_{\tau} = \epsilon^{-1}\partial_t = T/\pi \partial_t$

As
$$\beta_1(t) = \frac12\partial_{\tau}C C^{-\frac32}$$

**Notice**: If you consider $\beta_1$ alone, it is dependent on the choice of $\epsilon$ (the multiplicative coefficient)!!!
So, when you make tests/cheks it is better to look at the product $\epsilon \beta_1$.