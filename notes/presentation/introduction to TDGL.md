# Background on TDGL

## Universality at equilibrium

We know that, **at thermodynamic equilibrium**, many systems, that look very different as
- the Ising model
- the Gas / Liquid system

show the **same behaviour** **near the critical point**, _in the sense that_ we find the same critical exponents.

In fact, the **velocity** with which the _average_ magnetization of the 3D ising model decays at the critical point, is the same of the decay of the difference in densities in a Gas/Liquid system.
[STOP]

- In a magnetic system (Ising model)
$$m\sim (T_c - T)^{\beta}\quad\text{when } T\rightarrow T_C, H=0$$
- In a Van der Waals gas (gas / liquid system)
$$(\rho_l - \rho_g) \sim (T_c - T)^{\beta}\quad\text{when } T\rightarrow T_C, P=P_C$$

where the exponent $\beta$ **is the same**.

## Introducing the Gitzburg-Landau ansatz

A way **of describing** this universal behaviour is to **make** the Gitzburg-Landau **ansatz** for the free energy formula.

**Close to the critical point**, we assume that the free energy of **any system** can be written as this functional. 

<!---
A way of finding the critical exponents consists in minimizing the gitzburg landau free energy density **anstatz** $\frac{\partial f}{\partial t} = 0$

[In principle the above statement is right. But in practice you do not consider all the terms of the expansion and you neglect spatial fluctuations, so the gradient, and you find the mean field approximation's approximated critical exponents]
-->

$$f(m,T,H) = \frac12|\nabla m(x)|^2-Hm(x)+\frac12am^2(x)+bm^3(x)+...$$
where $a = a_0 \frac{(T-T_c)}{T}$, $m$ is the order parameter (as the magnetization) and $H$ is an external field (as the magnetic field).

The coefficients (like $a$ and $b$) **depend on the simmetries** of the system.

[This means that, if two systems have the same simmetries, the predicted behaviour close to the critical point is the same.]

### To make an example
If we consider 
- up/down simmetry
- no magnetic field
- and uniform states

### Spontaneous magnetization
The free energy will be this potential.
When temperature goes under the critical value, you **predit** a spontaneous breaking of the up/down simmetry.

![doubleWellPotential](Plots/universal%20V(x).png?raw=true)

[where the coefficients $a_0$, b, $T_c$ are different among the systems in the universality class, but the order parameter $m(x)$ can be rescaled respect to its equilibrium value (that depends over the parameters) and so get an universal expression]


So we see that we can use the Gitzburg Landau ansatz to find the **equilibrium states** of the system;


## Dynamics while reaching equilibrium states

But, can we say something about how the system reaches equilibrium?

The answer is yes, because we can say something, by exploiting the ansatz **even out of equilibrium**.

<!--
 we can look for **an universal law of DYNAMICS**, that hold when both 
- the control parameter $H$
- and the temperature $T$

are close to the critical values.

-->

## Non-conservative / Dissipative system

To find a **law of dynamics** from the Gitzburg-Landau ansatz, we _have to_ consider a **strongly dissipative system**. So let's consider an overdamped oscillator.

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

where $C$ is a parameter that depends over the external field $H$ and the temperature $T$.

#### This equation is called TDGL and is the equation we're working on.


[It's a functional derivative, so $\frac{\delta F}{\delta m(x)} = \frac{\partial f}{\partial m} - \nabla \cdot \frac{\partial f}{\partial \nabla m}$, as the dependance over $m$ and $\nabla m$ in the density $f$ is a power law dependance]

[At least in the d-dimensional Ising model, you can show, **by rescaling** both space $x$ and the order parameter $m(x)$, that **under the critical temperature** and **without magnetic field** the free energy functional is $f = \frac12(\nabla m)^2-\frac12 m+\frac14 m^2$. So by deriving it you get the above result (you do not have parameters $a,b,T_c$ in the f, because you made rescaling) You can choose to be under the critical temperature, because you are just constrained to have $T$ close to $T_c$ in order to use the G.L. ansatz, _but you can choose_ if $T<T_c$ or $T>T_c$]



## What describes the equation

The TDGL equation describes **coarse grain dynamics**, that is a kind of dynamics that you see in some systems (as the ising model) **below** the critical temperature.
In this dynamics, the state of the system exibiths **very sharp domains** that rise due to the **spontaneous magnetization** effect.

![coarseGrainedState](Plots/interface.png?raw=true)

[The reason why the domains rise under the critical temperature, can be explained considering the G.L. functional for the Ising model without magnetic field. It can be rewritten showing a double well potential and you can look for the flat profiles that minimize the free Energy] 



[The G.L. theory is developed _close to_ the critical point (critical values of $T$, $H$) but as **experimentally we have the same dynamics for any $T < T_c$** (despite noise), the TDGL equation works at **any $T<0$**, even $T=0$ (no noise)]

The system admits uniform stationary states, but even stationary states where both the phases coexist; so there is an interface

![equilibriumStates](Plots/stationary%20states.png?raw=true)

When the system is far from equilibrium, it moves towards a stationary state **throught the interaction of neighboring interfaces**, that tend to **annichilate**.
And at the end you have only one phase.

![annichilation](Plots/annichilation.png?raw=true)

## What do we know ALREADY about this dynamics?

Until now, the dynamics described by the equation has been studied intensively **only for constant** values of $C$.

### Driving C(t)

But no one has been interested in the dynamics when $C(t)$ has a time dependance.

## Our goal
So we want to **explore** the dynamics with time dependent $C(t)$ to see
- in what sense we can control the state of the system: what properties of the system can be controlled by changing $C$ in time?
- and understand how, and how much, we can **control** this properties, like the size and height of domain interfaces?

## What we did so far (two paths)
So far we studied the equation 
- in one dimension 
- and states with **only one interface**

and we explored dynamics with two _independent_ approaches
- numerical
- analytical

### Numerical exploration

At the beginning **we really spent time** to implement an algorithm for integrating the equation; requiring that it was
- fast and stable (long simulation)
- correctly integrate analytical results we had

and **we used end up using** a simple implicit method (Crank - Nicolson)


After that, we considered a sinusoidal modulation of $C$ and we integrated numerically the dynamics 
$$C(t) = \bar{C} + A\sin(2\pi t/T)$$


## Two time scales

As in the system there are two timescales
- the period of the modulation of $C$
- and the time the system takes to reach a stationary state, when $C$ is constant

We expect to see two regimes of dynamics, depending on wether the two timescales are close or far.

## Two kinds of dynamics

In fact we saw that there are two regimes for the dynamics
- Adiabatic
- Non adiabatic.

In the **adiabatic regime**, the evolution of $C$ is **slow** respect to the relaxation time, so the evolotuion of the system follows the evolution of $C$, because the system "has time to relax after $C$ is changed".

While, in the other regime, this is not the case.

As we know the analytical solution of TDGL for constant $C$, we can **easily** achieve control in this regime BUT
- the control is slow if $C$ oscillates close to zero, as the relaxation time diverges.

### First analytical approach
We tried a simple analytical approach, where we built our ansatz in order to control the width and height of interfaces (so we **parametrized** the two properties).
$$m(x,t) = \beta(t)m_k(\alpha(t)x)$$

we managed to find a way of controlling the properties in time, by changing $C(t)$ in a particular way. 


### Result of height/width control

But we have managed only to decrease height and increase width; not the opposite.

Despite this, this approach gave us a better understanding of the **functional shape** that the interfaces get when we control their properties.

## What is the next step

What we are going to do now is to exploit the adiabatic behaviour we have found numerically and study, with a **perturbation method**, how the evolution of the system **deviates from following** the variation of $C$.

We'll see what we can understand at first order and then we'll decide wheter to
- take another analytical approach
- explore more phenomenology numerically

## Our Motivation: Universal dynamics

As the **shape** of the Landau Gitzburg free energy is the same for many systems that **share the same simmetries** of the Ising model; we **guess** that the law is an **UNIVERSAL law** for describing **non equilibrium dynamics CLOSE TO the critical point**.


"""Same Free energy expression (Gitzburg-Landau) $\implies$ Universal law for dynamics"""

So we think that, due to this generality that rises **close to the critical point**, it's worth

 #### Studying how we can control an equation that describes physics close to a critical point.


[if two systems are in the same universality class, they have the same exponents. As you can find exponents from L.G. free energy (e.g. you can find the mean field approx ones of Ising model by using L.G. ansatz, simmetry up/down and ignoring the gradient, that means ignoring spatial fluctuation, as you do in mean field theory) this means that the L.G. free energy expressions of the two systems share similar properties; even thought the coefficients are not the same because they depend on the system. Anyway they can have similar properties because, if they are in the same class, they share common simmetries. So in both expression you will have coefficient b (CUBIC term) to be zero for example.]

<!--
## Our motivation
The reason why we're interested in the control of the equation is the universality of the dynamics it describes.

Working close to the critical point brings, in general, to universal behaviours.
So we think, due to this generality, it's worth controlling an equation that describes physics close to a critical point.
-->