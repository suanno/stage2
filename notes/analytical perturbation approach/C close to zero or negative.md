# Measure deviation form stationary state $\delta u = u - u_0$ when $C$ oscillates close to zero

We **do not expect AT ALL** the first order correction in $\epsilon$ to be sufficent to describe $\delta u$ in the cases we're going to describe, as now

$$\epsilon >> 2(C-A)$$

That is the **opposite** of the "rule of thumb" we stated to say _when_ we expect the first order correction to be sufficient.

In the cases we're going to discuss we have that the variation of $C(t)$ in time is fast compared to the time the system needs to relax.

#### Experiment 1: $C = 0.2 + 0.2\sin(2\pi t/T)\qquad T=10$

File: "/.saves/T=10 A=0.2 Cave=0.2 from tanh aftersomeperiods"

Here $C$ oscillates very close to zero, but it is always positive.
So you can always evaluate the analytical expression for $\beta_1(t)$ (that contains a square root of $C$).

![uk1Cpos](Plots/T=10%20Cave=0.2%20A=0.2/aftersomeperiods/uk1.png?raw=true)
![beta1Cpos](Plots/T=10%20Cave=0.2%20A=0.2/aftersomeperiods/beta1_extimations.png?raw=true)

#### Experiment 2: $C = 0 + 0.2\sin(2\pi t/T)\qquad T=10$

File: "/.saves/T=10 A=0.2 Cave=0 from tanh aftersomeperiods"

In this case $C(t)$ assumes negative values when $t$ is in the second semi-period.
So you cannot evaluate the analytical expression for $\beta_1(t)$ for those times and so you cannot calculate $\beta_1\epsilon$ for those times.

![uk1Cpos](Plots/T=10%20Cave=0%20A=0/aftersomeperiods/uk1.png?raw=true)
![beta1Cpos](Plots/T=10%20Cave=0%20A=0/aftersomeperiods/beta1_extimations.png?raw=true)