# Kink's annhilation when $C(t)$ assumes also negative values

# Simulations for different periods $T$
$$C(t) = \bar{C}+A\sin(2\pi t/T)$$
$$\bar{C} = 0.5; A = 1$$

Save folder: _../.saves/twokinks/d0=20/Cbar=0.5/T=?/A=1_

## Initialization
The initial state is prepared using _/initialization/twokinksinit.c_ as
$$u(x,0) = \sqrt{\bar{C}}[\tanh(\sqrt{\bar{C}/2}(x-x_1))+\tanh(\sqrt{\bar{C}/2}(x-x_2))-1]$$
where the initial distance $d_0 = x_2-x_1$ we chose
$$d_0 = 20$$

$$L=128; dx=0.1; dt=0.1$$
## Simulations
It seems that, **asymptotically** (large distance $d(t)$) the distance follows this time dependance

$$d(t)\sim \log[(t_c(T)-t)^{n(T)}]$$

The value of $t_c$ used to calculate the x-axis data from the $t$ data, is obtained by looking at the data of $d(t)$ from t=0, as soon as, **for the first time**, $d(t_c) < dx$. This is the condition we consider for the annhilation, to extimate the annhilation time $t_c$.
![](d0=20/vary_T/C0=0.5A=1/big.png?raw=true)

![](d0=20/vary_T/C0=0.5A=1/asymp.png?raw=true)

### Exponent $n(T)$
It seems that $n(T)\sim T$ and that 
$$T\rightarrow 0 \implies n\rightarrow 1/2$$
**BUT** we expect that, if the oscillation is very fast ($T\rightarrow 0$) then the dynamics is the same we see if $C=\bar{C}$ costant.
And in this case, we expect $n=1$ [**ARE WE SURE??? The exponent is a multiplicative factor in front of the log!!!**]

#### Computational limit
Maybe, for low values of $T$, there is a _saturation_ of $n(T)$ to 1. But to verify this, we should run simulations for very slow values of $T$, for which $t_c$ is very large and so the simulation is very long!!!

We can extimate $t_c(T)$ with a fit (see below) and then run a "short" simulation just to sample the tail of the plot.
Anyways, as the initial dynamics is very slow if $T$ is small, then we need to run "long" simulation in order to see $d(t)$ change of many units $dx$. This difficulty is due to the space discretization, that forbids to measure small changes of the distance.

![](d0=20/vary_T/C0=0.5A=1/n(T).png?raw=true)

### Annhilation time $t_c(T)$
Experimentally, there seems to be a polynomial depenence of $t_c$ on $T$
![](d0=20/vary_T/C0=0.5A=1/tc(T).png?raw=true)
![](d0=20/vary_T/C0=0.5A=1/logtc(T).png?raw=true)
