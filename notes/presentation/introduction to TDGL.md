# Background on TDGL

## Universality at equilibrium

We know that, **at thermodynamic equilibrium**, many systems, that look very different as
- the Ising model
- the Gas / Liquid system

show the **same behaviour** **near the critical point**. In fact we find the same critical exponents for any system in the universality class.

- In a magnetic system (Ising model)
$$m\sim (T_c - T)^{\beta}\quad\text{when } T\rightarrow T_C, H=0$$
- In a Van der Waals gas (gas / liquid system)
$$(\rho_l - \rho_g) \sim (T_c - T)^{\beta}\quad\text{when } T\rightarrow T_C, P=P_C$$

where the exponent $\beta$ **is the same**.

## Introducing the Gitzburg-Landau ansatz

A way **of describing** this universal behaviour is to **make** the Gitzburg-Landau free energy **ansatz**.

**Close to the critical point**, you assume that the free energy of **any system** can be written as this functional. 

<!---
A way of finding the critical exponents consists in minimizing the gitzburg landau free energy density **anstatz** $\frac{\partial f}{\partial t} = 0$

[In principle the above statement is right. But in practice you do not consider all the terms of the expansion and you neglect spatial fluctuations, so the gradient, and you find the mean field approximation's approximated critical exponents]
-->

$$f(m,T,H) = \frac12|\nabla m(x)|^2-Hm(x)+\frac12am^2(x)+bm^3(x)+...$$
where $a = a_0 \frac{(T-T_c)}{T}$
and the coefficients **depend on the simmetries** of the system.

[This means that, if two systems have the same simmetries, the predicted behaviour close to the critical point is the same.]

**For example**, if we consider uniform states and up/down simmetry, the free energy will be this potential.
When temperature goes under the critical value, you **predit** a spontaneous breaking of the simmetry.

![doubleWellPotential](Plots/universal%20V(x).png?raw=true)

[where the coefficients $a_0$, b, $T_c$ are different among the systems in the universality class, but the order parameter $m(x)$ can be rescaled respect to its equilibrium value (that depends over the parameters) and so get an universal expression]

## Out of equilibrium dynamics

The Gitzburg Landau free energy expression is used to find the **equilibrium states** of the system from simmetry consideration.

But, if we consider it **even out of equilibrium**, we can look for a law that describes the **dynamics** with which **the system approaches equilibrium**.


 we can look for **an universal law of DYNAMICS**, that hold when both 
- the control parameter $H$
- and the temperature $T$

are close to the critical values.


## Non-conservative / Dissipative system

To find this dynamics from the Gitzburg-Landau ansatz, let's consider a **strongly dissipative system**.

In an **overdamped oscillator**, you can approximate the equation of motion, neglecting the **inertial term**

$$M\ddot{x}=-\gamma \dot{x} - \frac{dV(x)}{dx}\rightarrow 0\simeq -\gamma\dot{x} - \frac{dV(x)}{dx}$$
so
$$\frac{dx}{dt} = - \frac{1}{\gamma}\frac{dV}{dx}$$

[The idea of the "overdamped" approximation is that the system is "driven by" the friction and the shape of the dynamics doesn't depend on the initial energy of the system. Of course $\dot{x}(t)$ depends over $\dot{x}(0)$, but just as a prefactor and **not** in the shape (the system decays without making any oscillation if it is strongly damped; otherwise the number of oscillations depends on the initial kinetic energy)]

following the same idea, we can generalize this concept _naively_ equating the rate of change of the **order parameter** to the **thermodynamic force**

$$\frac{\partial m(x,t)}{\partial t} = -\frac{\delta F}{\delta m}$$

where $F = \int dx f(m(x))$ and we are performing a _functional derivative_.

If we now use
- the Gitzburg-Landau ansatz for the free Energy expression
- **where we** consider the ising model simmetry
- **and rescale** properly $x$ and the order parameter $m$

[adopting ising simetry: up/down means using b = 0, and in addition we neglect higher orderds than 4th.]

$$\frac{\partial m(x)}{\partial t} = \Delta m + m(C-m^2)$$

where $C$ is a parameter that depends over the control parameter $H$ and the temperature $T$.

This equation is called TDGL and is the equation we're working on.


[It's a functional derivative, so $\frac{\delta F}{\delta m(x)} = \frac{\partial f}{\partial m} - \nabla \cdot \frac{\partial f}{\partial \nabla m}$, as the dependance over $m$ and $\nabla m$ in the density $f$ is a power law dependance]

[At least in the d-dimensional Ising model, you can show, **by rescaling** both space $x$ and the order parameter $m(x)$, that **under the critical temperature** and **without magnetic field** the free energy functional is $f = \frac12(\nabla m)^2-\frac12 m+\frac14 m^2$. So by deriving it you get the above result (you do not have parameters $a,b,T_c$ in the f, because you made rescaling) You can choose to be under the critical temperature, because you are just constrained to have $T$ close to $T_c$ in order to use the G.L. ansatz, _but you can choose_ if $T<T_c$ or $T>T_c$]

## Universal dynamics

As the **shape** of the Landau Gitzburg free energy is the same for any system in the universality class of the Ising model; we **guess** that this law is an **UNIVERSAL law** for describing **non equilibrium dynamics CLOSE TO the critical point**.

Same Free energy expression (Gitzburg-Landau) $\implies$ Universal law for dynamics

[if two systems are in the same universality class, they have the same exponents. As you can find exponents from L.G. free energy (e.g. you can find the mean field approx ones of Ising model by using L.G. ansatz, simmetry up/down and ignoring the gradient, that means ignoring spatial fluctuation, as you do in mean field theory) this means that the L.G. free energy expressions of the two systems share similar properties; even thought the coefficients are not the same because they depend on the system. Anyway they can have similar properties because, if they are in the same class, they share common simmetries. So in both expression you will have coefficient b (CUBIC term) to be zero for example.]

## What describes the equation

The TDGL equation describes **coarse grain dynamics**, that is a kind of dynamics that you see in some systems (as the ising model) **below** the critical temperature.
In this dynamics, the state of the system exibiths **very sharp domains** that rise due to the **spontaneous magnetization**.

![coarseGrainedState](Plots/interface.png?raw=true)

[The reason why the domains rise under the critical temperature, can be explained considering the G.L. functional for the Ising model without magnetic field. It can be rewritten showing a double well potential and you can look for the flat profiles that minimize the free Energy] 



[The G.L. theory is developed _close to_ the critical point (critical values of $T$, $H$) but as experimentally we have the same dynamics for any $T < T_c$ (despite noise), the TDGL equation works at **any $T<0$**, even $T=0$ (no noise)]


## State of the art

Until now, the dynamics described by the equation has been studied intensively **only for constant** values of $C$.
With particular focus on the mechanisms of interaction, diffusion and annichilation of domains.

But no one has yet studied the dynamics when $C(t)$ has a time dependance.

## Our goal
We want to **explore** the dynamics with oscillating $C(t)$ to see
- in what sense we can control the state of the system: what properties of the system can be controlled by changing $C$ in time?
- and understand how, and how much, we can **control** this properties, like the size and height of domain interfaces?

## What we did so far
So far we studied states with **only one interface** and we explored dynamics with two _independent_ approaches

### Numerical exploration
We studied numerically the dynamics with sinusoidal modulation of $C(t)$
$$C(t) = \bar{C} + A\sin(2\pi t/T)$$

and we discovered there are two regimes: Adiabatic and non adiabatic.

We are in the **adiabatic regime** when the evolution of $C(t)$ is **slow** respect to the time the system relax with a constant $C$.

We know the analytical solution of TDGL for constant $C$, so we can achieve control in this regime BUT
- the control is slow
- it's not possible if $C$ oscillates around zero, because the relaxation time $\tau \sim \frac{1}{C}$

### First analytical approach
We tried a simple analytical approach, where we built our ansatz in order to control the width and height of interfaces.
$$m(x,t) = \beta(t)m_k(\alpha(t)x)$$

we managed to find a way of controlling those two properties in time, by changing $C(t)$ in a particular way. But we have managed only to decrease height and increase width; not the opposite.

Despite this, this approach gave us a better understanding of the **functional shape** that the interfaces get when we control their properties.

## What is the next step

What we are going to do now is to exploit the adiabatic behaviour we have found numerically and study, with a **perturbation method**, how the evolution of the system **deviates from following** the variation of $C$.

We'll see what we can understand at first order and then we'll decide wheter to
- take another analytical approach
- explore more phenomenology numerically

## Our motivation
The reason why we're interested in the control of the equation is the universality of the dynamics it describes.

Working close to the critical point brings, in general, to universal behaviours.
So we think, due to this generality, it's worth controlling an equation that describes physics close to a critical point.