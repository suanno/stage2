# Introduction
Today I will introduce the **topic** we're working on, **its background** and what is **our goal**.
Then I will briefly show what we're doing.

To make things **more natural** let's consider **this** type of system. 

## Adatoms diffusion on a crystal monolayer
We have a planar surface in contact with a gas of atoms that can adsorb on the surface.

The dynamics is dominated by two **processes**

## Ising model: discrete to continuos
Then, even if it is a discrete model, we can define a local magnetization by averaging its value over a sufficiently large number of neighbouring spins.
So now the state of the system is described by a **continuos** order parameter.

## Phase transition
In absence of a magnetic field, if we go below a critical temperature, the system goes from a state where the average magnetization is zero, to one where it is non zero (positve or negative)

## Landau-Gitzburg
This phenomena, can be well described by making the Gitzburg-Landau Free Energy ansatz.
In fact the Free Energy has two degenerate minima when the temperature goes below the critical value

## Dynamics
The minimas are the state where we find the system at equilibrium, but **there is a dynamics** that brings the system to the equilibrium state.
And this dynamics can be retrieved from the expression of the Free Energy, by requiring that the evolution in time of the order parameter is governed by the thermodynamical force

...

The idea of this formula is that, in a very damped system, you neglect the inertia in the Newton's law

This happens for a 1D particle and, **naively**, you can think to generalize the formula as we did.

## TDGL
By considering the G.L. Free Energy expression for the 2D Ising model **up to 4th order**, we find out this equation

As **we truncated** the Free Energy expansion, we expect this formula to describe the dynamics but **only when we are close to the critical point, where the order parameter is small**.


## Visual comparison with Montecarlo simulation of 2D Ising model


## Our goal: Control

