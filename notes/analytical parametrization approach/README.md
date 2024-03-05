# Parametrization approach

## The Ansatz

The Ansatz we start with is that we can write the solution of TDGL $\partial_t u = \partial_{xx} u + u(C-u^2)$ as

$$u(x,t) = \beta(t)u_k(\alpha(t) x)$$

so we assume that the time dependance is only in the parameters $\alpha, \beta$ and NOT in the _shape_ $u_k(x)$.

The **idea behind** this ansatz is that, if $u_k(x)$ is a **one kink function** (naively intending that, plotting it, **we see a SINGLE kink**, like in the functions $\tanh(x)$ or $Erf(x)$) then

- $\beta(t)$ [or $2\beta(t)$] is the kink's height
- $1/\alpha(t)$ [or $2/\alpha(t)$] is the kink's width

To get that idea, think to the function $\beta \tanh(\alpha x)$.


So, with this ansatz, the time dependance is only in the kink's height and width and not on the kink's shape.
We adopt this ansatz because we want to vary $C(t)$ by **keeping the same shape of the kink in time** while driving its height and width.

But, for the moment, **we do not assume anything about the shape $u_k(x)$**.

## First change of variable $\chi = \alpha x$

We make a natural change of variable $x\rightarrow \chi = \alpha(t) x$ so

$$u_k(\alpha x) = u_k(\chi)$$
$$x = \chi \alpha^{-1}$$
$$\partial_x = \alpha \partial_{\chi}$$
$$x\partial_x = \chi\partial_{\chi}$$

 and we insert the ansatz in the TDGL equation

$$\frac{\partial_t\alpha}{\alpha}\chi \partial_{\chi}u_k(\chi) = \alpha^2 \partial_{\chi \chi}u_k(\chi)+u_k(\chi) [\frac{C-\partial_t\beta}{\beta}-\beta^2u_k^2(\chi)]$$

## Assumption on the shape $u_k(\chi)$
As we want to study _one kink solutions_, **we look for a solution $u_k$ that has a _one kink shape_**.
So we make the **ASSUMPTION**
$$u_k(\pm \infty) = \pm 1 \implies \partial_{\chi}u_k$$
(the signs depends on if the solution has kink or anti-kink shape. But the following calculations do not depend on this)

**Note** that we haven't asked any other property that a _one kink shape_ we expect to have. We asked just how it has to behave at infinity.

If we evaluate the last equation for $\chi = \pm\infty$, using the assumption we end up with
$$0 = \frac{(C-\partial_t\beta)}{\beta}-\beta^2$$

So

$$\partial_t\beta = \beta(C-\beta^2)$$
(that has the same shape of the TDGL equation for flat profiles)

Using the last formula back in the equation (the one that holds for every $\chi$, not the one for $\chi=\pm\infty$) we end up with

$$\frac{\partial_t \alpha}{\alpha}\chi \partial_{\chi} u_k = \alpha^2 \partial_{\chi\chi}u_k + \beta^2u_k(1-u_k^2)$$

**There is a Problem**: We want to have an **ODE** for $u_k$ in order to find it, but in this equation we have both space and time dependance.

## Impose some constraints to eliminate the time dependance in the equation

Now we impose some relations on $\alpha,\beta$ in order to eliminate the time dependance in the last equation.

**We can** impose **arbitrary** constraints on the parameters, without affecting the existance of a solution $u_k$ of the differential equation.
That's because our ansatz contains three "to be determined quantities"

- two parameter $\alpha,\beta$
- the shape $u_k$, that we requested just to go to $\pm 1$ at $\pm \infty$ but nothing else, so its shape is still to be determined

So we have 3 d.o.f. and we can loose 2 of them imposing arbitrary constraints, having still 1 degree left.

Anyway, if at the end we find a solution, it means there is a solution.

The constraints we choose (chosen to remove the time dependance) are

- $\frac{\partial_t\alpha}{\alpha} = a\alpha^2$
- $\beta^2 = b\alpha^2$
where we have introduced the two "free" parameters $a,b$ to find more general solutions $u_k$.

Imposing the constraints, we end up with a differential equation with just space dependance

$$a\chi \partial_{\chi}u_k = \partial_{\chi\chi}u_k + bu_k(1-u_k^2)$$

## Evolution of the parameters $\alpha, \beta$

Integrating the constraints we find
$$\frac{1}{\alpha(t)^2} = \frac{1}{\alpha(0)^2}-2at$$
So
$$\alpha(t) = \pm[2a(t_0 - t)]^{-\frac12}$$
where $t_0 = \frac{1}{2a\alpha(0)^2}$

and the sign $\pm$ is the sign of $\alpha(0)$ (check that putting $t=0$ and considering that $2at_0 = \alpha(0)^{-2}$)

- If $a > 0$

    then $t_0 > 0$ and the expression is well defined only if $t < t_0$

   ![Plot_alpha_a>0]

- If $a < 0$

    then $t_0 < 0$ and the expression is well defined only if $t > t_0$

    ![Plot_alpha_a>0]

The evolution of $\beta(t)$ is barely the same of $\alpha(t)$ because $\beta^2 = b \alpha^2$

$$\beta(t) = \pm[2\frac{a}{b}(t_0-t)]^{-\frac12}$$

## Determining $C(t)$

As we put some constraints, we have just one d.o.f. left that is the shape $u_k$, so we cannot choose anymore arbitrarly $C(t)$.

We find $C(t)$ from the equation we found imposing $u_k(\pm\infty) = \pm 1$

$$C = \frac{\partial_t \beta}{\beta} + \beta^2$$
and we know 
$$C(t) = -\frac{1}{2(t-t_0)}(1+\frac{b}{a})$$

This is the expression **we HAVE TO adopt for $C(t)$ in order to have** the above evolutions of $\alpha(t),\beta(t)$ and a shape $u_k$ that solves the ODE.

- If a > 0

    ![Plot_C(t)_a>0]
- If a < 0 and 0 < b < -a

    ![Plot_C(t)_a<0b<-a]
- If a < 0 and b > -a
    
    ![Plot_C(t)_a<0b>-a]

## ODE for the shape $u_k(\chi)$
We found that the shape $u_k$ solves

$$a\chi \partial_{\chi}u_k = \partial_{\chi\chi}u_k + bu_k(1-u_k^2)$$

### Second change of variable
we can make an additional change of variable in order to let the above equation depend only over one parameter

$$\chi' = b^{\frac12}\chi$$
$$\partial_{\chi\chi} u_k = b \partial_{\chi'\chi'}u_k$$
$$u_k(\chi) = u_k(b^{-\frac12}\chi')$$

and we get an expression depending only on one parameter $\frac{a}{b}$
$$\frac{a}{b}\chi'\partial_{\chi'}u_k = \partial_{\chi'\chi'}+u_k(1-u_k^2)$$

### Physical analogy

We can visualize this equation with a **physical analogy** if $\chi' \rightarrow t$ and $u_k\rightarrow x$

$$\ddot{x} = \frac{a}{b}t\dot{x} - x(1-x^2)$$

if we call $\gamma(t) = -\frac{a}{b} t$ and $V(x) = \frac12 x^2 - \frac14 x^4$ we find

$$\ddot{x} = -\gamma(t)\dot{x}-\frac{dV(x)}{dx}$$

that is the equation of a 1D particle (with mass $M=1$) moving in the double well potential $V(x)$ while **experiencing a "friction" that increases in time**.

- If $a > 0$, we do not have a friction, instead we have a force that increases the velocity of the particle with a linear time dependance. So, if $a > 0$, the particle will eventually cross one of the two barrier and move forward in that direction, independently on the initial conditions.
This means that 
    $$a > 0 \implies u_k(\infty)=\pm\infty$$

    But, thanks to the analogy, the solutions of the ODE are the trajectories of the 1D particle. And before we asked $u_k(\infty)=\pm 1$ so $a > 0$ is inconsistent with our assumptions.

- If $a < 0$, we have a friction.
    If the particle starts from $x=0$ at $t=0$, there is a **critical velocity** $v_{crit}(-\frac{a}{b})$ such that
    - If $v(0) > v_{crit}$ the particle will manage to cross the barrier. Then $x$ will grow undefinetly.
    - If $v(0) < v_{crit}$ the particle will not cross the barrier. Instead it will make oscillations around $x=0$ until it stops at $x=0$ for the friction.
    - If $v(0) = v_{crit}$ the particle **will reach the top of the barrier in an infinite time**.

    The three cases correspond to different kinds of solutions of the ODE.
    In the first two $u_k(\infty) = \pm\infty$ or $0$. Both cases are inconsistent with our previous assumptions; they are not kink solutions.

    The last case is the only one consistent.
    This means that ALL the solutions of the ODE that have a kink shape, have **the same value for the derivative at $\chi' = 0$**

    $$\partial_{\chi'}u_k|_{\chi' = 0} = v_{crit}(-\frac{a}{b})$$

    We can _try to_ find the critical velocity through an **energy balance**.
    If you multiply the equation of motion of the 1D particle by $\dot{x}$ both sides and use
    $$\dot{x}\ddot{x} = \dot{x}\frac{d\dot{x}}{dt} = \frac12 \frac{d}{dt}\dot{x}^2$$
    $$\dot{x}\frac{dV}{dx} = \frac{dx}{dt}\frac{dV}{dx} = \frac{dV}{dt}$$

    you find
    $$\frac{d}{dt} [\frac12 \dot{x}^2 + V(x)] = \frac{a}{b}t\dot{x}^2$$

    that we can integrate in time
    $$\frac{a}{b}\int_0^{\infty} t\dot{x}^2 dt = [\frac12 \dot{x}^2 + V(x)]|_{t=0}^{t = \infty}$$

    and we know that, to have a _single kink solution_, $u_k(\infty)=\pm 1$, so $\dot{x}^2(\infty) = 1$. Then $V(0) = 0$, $V(1) = \frac14$.

    $$\dot{x}^2(0) = \frac14 - \frac{a}{b}\int_0^{\infty} t \dot{x}^2 dt$$

    But we do not know how to solve this integral equation.

### Analytical solutions for special choices of $a, b$

Consider $\chi$ as the variable

$$\frac{a}{b}\chi\partial_{\chi}u_k = \partial_{\chi\chi}u_k + bu_k(1-u_k^2)$$

- $b \rightarrow 0$

    In this limit the term without derivatives (the double well potential $V(x)$, that contains _the non linear term_) becomes negligible
    $$\frac{a}{b}\chi\partial_{\chi}u_k = \partial_{\chi\chi}u_k$$
    This equation is linear and has solution
$$u_k(\chi) = Erf(\sqrt{-a/2}\chi) + const.$$

- $a \rightarrow 0$

    In this case the term with the second derivative becomes negligible and we recover the stationary TDGL equation with $C=1$ constant.

    $$\partial_{\chi\chi}u_k + bu_k(1-u_k^3)$$
    that has solution

    $$u_k(\chi) = \tanh(2^{-\frac12}\chi)$$


## About the Sign of a, b
The sign of those parameter is not arbitrary, in order to be consistent with our previous assumptions / imposed constrains.

- $a < 0$ because we asked $u_k(\infty) = \pm 1$
- $b > 0$ because $\alpha, \beta$ are real and we imposed the constraint $\beta^2 = b\alpha^2$

**As a consequence**, if $a$ cannot be positive, we cannot achieve a $C(t)$ driving that increases $|\alpha|,|\beta|$. Because if we drive $C(t)$ with the profile showed for $a>0$, then the solutions of the ODE for $u_k$ **will not** have a _one kink shape_. So **we cannot tell what happens** if we drive $C(t)$ like that and we start with an initial state with kink shape.

### What we achieved
As $a$ must be negative, with this analytical approach we **only achieved to control** the **height** and **width** of the kink for **decreasing** them.

And we still do not know the analytical shape of the kink $u_k$.