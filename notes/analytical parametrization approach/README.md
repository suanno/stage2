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

![Plot_alpha_a>0](Plots/alpha(t)%20a%20>%200.png?raw=true)

- If $a < 0$

    then $t_0 < 0$ and the expression is well defined only if $t > t_0$

![Plot_alpha_a>0](Plots/alpha(t)%20a%20<%200.png?raw=true)

**Notice that**, in both cases, $\alpha(t)$ is well defined in a neighborhood of $t = 0$. This is important, because $t=0$ is the time when $\alpha(t)=\alpha_0$, so it's the time when we start varying $C(t)$.
It's important that what happens to $\alpha(t), \beta(t)$ after a small from the one you started varying $C$ in time is well defined.

The evolution of $\beta(t)$ is barely the same of $\alpha(t)$ because $\beta^2 = b \alpha^2$

$$\beta(t) = \pm[2\frac{a}{b}(t_0-t)]^{-\frac12}$$

## Determining $C(t)$

As we put some constraints, we have just one d.o.f. left that is the shape $u_k$, so we cannot choose anymore arbitrarly $C(t)$.

We find $C(t)$ from the equation we found imposing $u_k(\pm\infty) = \pm 1$

$$C = \frac{\partial_t \beta}{\beta} + \beta^2$$
and we know 
$$C(t) = -\frac{1}{2(t-t_0)}(1+\frac{b}{a})$$

This is the expression **we HAVE TO adopt for $C(t)$ in order to have** the above evolutions of $\alpha(t),\beta(t)$ and a shape $u_k$ that solves the ODE.

- If a > 0,
    
    then $t_0 > 0$ and $\beta(t)$ is well defined only if $t < t_0$; so even $C(t)$, that is a function of $\beta(t)$.


![Plot_C(t)_a>0](Plots/C(t)%20a%20>%200.png?raw=true)
- If a < 0 and 0 < b < -a
    
    then $t_0 < 0$ and $\beta(t)$ is well defined only if $t > t_0$; so even $C(t)$, that is a function of $\beta(t)$.
    The sign of $C(t)$ is positive.
- If a < 0 and b > -a

    here too $t_0 < 0$ and $C(t)$ is well defined only for $t > t_0$. And the sign of $C(t)$ is negative.
    
![Plot_C(t)_a<0](Plots/C(t)%20a%20<%200.png?raw=true)

## ODE for the shape $u_k(\chi)$
We found that the shape $u_k$ solves

$$a\chi \partial_{\chi}u_k = \partial_{\chi\chi}u_k + bu_k(1-u_k^2)$$

### Second change of variable $\chi' = b^{\frac12}\chi$
we can make an additional change of variable in order to let the above equation depend only over one parameter

$$\chi' = b^{\frac12}\chi$$
$$\partial_{\chi\chi} u_k = b \partial_{\chi'\chi'}u_k$$
$$u_k(\chi) = u_k(b^{-\frac12}\chi')$$

and we get an expression depending only on one parameter $\frac{a}{b}$
$$\frac{a}{b}\chi'\partial_{\chi'}u_k = \partial_{\chi'\chi'}u_k+u_k(1-u_k^2)$$

**Pay attention** to the fact that the solution of this equation is $u_k(b^{-\frac12}\chi')$ and NOT $u_k(\chi')$!!!

So, after you find a solution, that will be a function of $\chi'$, say $y(\chi')$; to recover $u_k(\chi)$ you have to use the fact that $y(\chi') = u_k(b^{-\frac12}\chi')$.

### Physical analogy

We can visualize this equation with a **physical analogy** if $\chi' \rightarrow t$ and $u_k\rightarrow x$

$$\ddot{x} = \frac{a}{b}t\dot{x} - x(1-x^2)$$

if we call $\gamma(t) = -\frac{a}{b} t$ and $V(x) = \frac12 x^2 - \frac14 x^4$ we find

$$\ddot{x} = -\gamma(t)\dot{x}-\frac{dV(x)}{dx}$$

that is the equation of a 1D particle (with mass $M=1$) moving in the double well potential $V(x)$ while **experiencing a "friction" that increases in time**.

![DoubleWellPotential](Plots/double%20well.png?raw=true)

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

    #### Numerical calculation of the critical velocity

    Numerically we can calculate the critical velocity, so the **minimum velocity** that a particle must have at $x=0$ to cross one of the two barriers of the potential $V(x)$.

    Here we report this numerical calculation, where we plotted another curve for comparison.
    The number $1/\sqrt{2}$ is the minimum velocity to cross the barrier in absence of the friction.

![numericalCritycalVelocity](Plots/numerical%20critical%20velocity.png?raw=true)

### Analytical solutions for special choices of $a, b$

Consider $\chi$ as the variable

$$\frac{a}{b}\chi\partial_{\chi}u_k = \partial_{\chi\chi}u_k + bu_k(1-u_k^2)$$

- $b \rightarrow 0$

    In this limit the term without derivatives (the double well potential $V(x)$, that contains _the non linear term_) becomes negligible
    $$\frac{a}{b}\chi\partial_{\chi}u_k = \partial_{\chi\chi}u_k$$
    This equation is linear and has solution (if we require $u_k(\infty)=1$)
$$u_k(\chi) = Erf(\sqrt{\frac{-a/b}{2}}\chi)$$

- $a \rightarrow 0$

    In this case the term with the second derivative becomes negligible and we recover the stationary TDGL equation with $C=1$ constant.

    $$\partial_{\chi\chi}u_k + bu_k(1-u_k^3)$$
    that has solution

    $$u_k(\chi) = \tanh(\frac{\chi}{\sqrt2})$$

### Linearization @ $\chi' \rightarrow \infty$

Let's consider $\chi'$ as variable

$$\frac{a}{b}\chi'\partial_{\chi'}u_k = \partial_{\chi'\chi'}u_k + u_k(1-u_k^2)$$

We assumed that $u_k \rightarrow \pm 1$ if $\chi'\rightarrow \infty$, so let's write $u_k$ as
$$u_k = 1-\delta u_k$$
where $\delta u_k$ is small if $\chi'\rightarrow \infty$.

$$\partial_{\chi'}u_k = -\partial_{\chi'}\delta u_k$$
$$u_k(1-u_k^2)=u_k(1+u_k)(1-u_k)\simeq 2\delta u_k$$

So the linearized equation is
$$-\frac{a}{b}\chi'\partial_{\chi'}\delta u_k = -\partial_{\chi'\chi'} + 2\delta u_k$$


#### Analytical solution for $\frac{a}{b} = -2$

This is a special case, because we can find that the solution is
$$\delta u_k = c_1 \chi' + c_2e^{-\chi'^2}(1+e^{\chi'^2}\sqrt{\pi}\chi'Erf(\chi'))$$

Both the two independent solutions **diverge** when $\chi'\rightarrow \infty$.
But both diverge **linearly in $\chi'$**, so we can make a choice of $c_1$ and $c_2$ such that the two divergencies "destroy each other".

This choice is $c_1 = -\sqrt{\pi}c_2$.

After you remove the divergence by choosing the coefficients, you have to consider the next orders of the $Erf$ expansion.
The second order cancels with $c_1e^{-\chi'^2}$, so you have to consider the next order. Finally, when $\chi'\rightarrow\infty$
$$\delta u_k \simeq \frac{c_2}{2}\frac{1}{\chi'^2}e^{-\chi'^2} + O[\frac{e^{-\chi'^2}}{\chi'^4}]$$

where the coefficient $c_2$ must be positive if $u_k$ must be less than 1.

#### It simpler when $\frac{a}{b} \neq -2$

In this case the two independent solutions are one divergent and one convergent to zero (and alway positive as $\delta u_k$ should be).

So only one of the two solution is compatible with the boundary condition $u_k(\infty)=\pm 1$.

Expanding that solution for $\chi'\rightarrow \infty$ with **Mathematica**, we find it goes as

$$\delta u_k \sim \frac{1}{\chi'^{k_2}}e^{-k_1\chi'^2}$$
where both $k_1, k_2 > 0$.

So $\delta u_k$ (and so $u_k$) goes zero as the $Erf(\chi')$ function and NOT as the $\tanh(\chi')$

$$\tanh (\chi') \simeq 1 - 2e^{-2\chi'}$$
$$Erf(\chi') \simeq 1 - \frac{1}{\sqrt{\pi}\chi'}e^{-\chi'^2}$$

### Third change of variable $\chi'' = |a/b|^{\frac12}\chi'$

The ODE becomes

$$\frac{a}{b}\chi''\partial_{\chi''}u_k = |\frac{a}{b}|\partial_{\chi''\chi''}u_k + u_k(1-u_k^2)$$

If we take the limit $|a/b|\rightarrow \infty$ **and we say that a kink solution $u_k$ is always limited** between $-1 < u_k < 1$ [**Note** that we did NOT assumed YET this statement, but just that $u_k(\chi) \rightarrow 1$ when $\chi\rightarrow \infty$]
then the term without $\frac{a}{b}$ **is of order 1 so** can be neglected in favor of the other two, leaving to the equation


$$\chi''\partial_{\chi''}u_k = -\partial_{\chi''\chi''}u_k$$

where we simplified $\frac{a}{b}$ and used the fact that $|\frac{a}{b}| = -\frac{a}{b}$ because the ratio is negative.

This equation is linear and its analytical solution (**without imposing any boundary** condition) is

$$f(\chi'') = c_1 + c_2 Erf(\frac{\chi''}{\sqrt2})$$

and if we write this as a function of $\chi$ (instead of $\chi''$) [this **is equivalent** to equate $f(\chi'') = u_k(\chi)$, that we know to be the solution, and make use of the fact that $\chi'' = |\frac{a}{b}|^{\frac12}b^{\frac12}\chi''$]
we find

$$u_k(\chi) = f(|a|^{\frac12}\chi'') = c_1 + c_2Erf(\sqrt{\frac{|a|}{2}}\chi)$$

if now we impose the boundary condition, so we require $u_k(\chi)$ _to have a kink shape_ $u_k(\infty) = +1 \implies c_1 = 0, c_2 = 1$

$$u_k(\chi) = Erf(\sqrt{\frac{|a|}{2}}\chi)$$

We said that the function above is a solution of the kink's shape ODE **IF** $a\rightarrow \infty$, but **let's be more quantitative:**

When we took the limit $a\rightarrow \infty$ we neglected the term $u_k(1-u_k^2)$ in favor of the other two because we said that this term is of order one, as we expect the kink's shape to be a limited function.
But, if we consider $\chi'' \rightarrow \infty$, then the derivatives of $u_k$ go zero, as $u_k\rightarrow 1$.
So, for **very large** (compared to $|\frac{a}{b}|$) values of $\chi''$, the approximation we made is no more true.

In fact the approximation is correct **only if** the derivatives and the neglected term are of the same order and so, if you make $a\rightarrow \infty$, you make the terms with the derivatives larger.
But now the neglected term is of order one, while **the derivatives are smaller**!

**More quantitatively**, if we look at the solution of the equation as a function of $\chi''$

$$u_k = Erf(\frac{\chi''}{\sqrt2})$$

we have that the derivatives of $u_k$ are of order 1 **only if** $|\chi''| << 1$ (that means that $\chi''$ takes values **within the width** of the error function).
And **only if** the derivatives are of order 1, so **the same of** the term we neglect, we can neglect it!

This means that, the error function it's a **correct solution** if **both**

- $a \rightarrow \infty$
- $\chi'' << 1 \implies \chi = \frac{\chi''}{|a|^{\frac12}}<<\frac{1}{|a|^{\frac12}}$

When $\chi \sim> |a|^{\frac12}$, then $u_k(\chi)$ can deviate from the error function shape (because the neglected terms are no more negligible).
To understand how $u_k(\chi)$ behaves at large values of $\chi$, you can linearize the ODE for large values of $\chi$.

## About the Sign of a, b
The **sign of $a, b$ is NOT arbitrary**, in order to be consistent with our previous assumptions / imposed constrains.

- $a < 0$ because we asked $u_k(\infty) = \pm 1$
- $b > 0$ because $\alpha, \beta$ are real and we imposed the constraint $\beta^2 = b\alpha^2$

**As a consequence**, if $a$ cannot be positive, we cannot achieve a $C(t)$ driving that increases $|\alpha|,|\beta|$. Because if we drive $C(t)$ with the profile showed for $a>0$, then the solutions of the ODE for $u_k$ **will not** have a _one kink shape_. So **we cannot tell what happens** if we drive $C(t)$ like that and we start with an initial state with kink shape.

### What we achieved
As $a$ must be negative, with this analytical approach we **only achieved to control** the **height** and **width** of the kink for **decreasing** them.

And we still do not know the analytical shape of the kink $u_k$, we only know

- The shape when $a\rightarrow 0$

- The shape when $a\rightarrow \infty$