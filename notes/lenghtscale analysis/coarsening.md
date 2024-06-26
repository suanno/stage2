# Coarsening
Not seeing the coarsening power law behaviour with $L=256, dx=0.1$ (dt=0.1)
![C=1L=256](grad2/C=1/19_06.png?raw=true) 
I decided to increase the system size to $$L=512, dx=0.1$$
those are the $L,dx$ value adopted in ALL the simulations below.

## Monitoring $\lambda = \frac{A_{system}}{\int |\nabla u|^2 dxdy}$ at long times
**Data:** /.saves/21_06_(A,B,C)

The simulations ran with two different time steps $dt$.
- Untill t=11, that is the time when (with L=256) you can clearly see already domains, $dt=1e-3$. It is small because at the beginning the dynamics is fast, before domains emerge.
- From t=11, we used $dt=1e-1$ to fastener the simulation.

#### C=1 (constant)
Here the width of an interface can be calculated analitically, by integrating the 1D stationary state's $|\nabla u|^2$ in the whole $R$. $$W=\frac{2\sqrt2}{3}C^{\frac32}$$
![C=1L=512grad2](grad2/C=1/21_06.png?raw=true)

The black line indicates the time $t=11$ when the $dt$ was increased. It looks like this change affects the measure, but that happens because around $t\simeq 11$ the domains emerge.
This hypotesis is supported by the following simulation, where the timestep was changed at $t=20$ just to see how the change of dt influences the results.
![dt=20](grad2/C=1/25_06_change_dt_t=20.png?raw=true)

#### $C=1+0.5\sin(2\pi t/T)$ T=2.5
![](grad2/oscillatory%20C0=1/T=2.5/21_06.png?raw=true)
If the initial dynamics is not integrated with a smaller time-step $dt$ (but the initial state is the same)
![](grad2/oscillatory%20C0=1/T=2.5.png)
#### $C=1+0.5\sin(2\pi t/T)$ T=25
![C=1L=512q2](grad2/oscillatory%20C0=1/T=25/21_06.png?raw=true)

As the period is large, we can try to assume _adiabaticity_ to extimate the interface's width like
$$W(t)\simeq \frac{2\sqrt2}{3}C(t)^{\frac32}$$
![C=1L=512q2](grad2/oscillatory%20C0=1/T=25/21_06_adiabaticW.png?raw=true)
notice that we get an exponent closer to the expected one ($\frac12$) and a prefactor close to the one we see for constant $C=1$ (1).


#### Comments
The coarsening exponent is close to the expected value 0.5 in all the 3 cases. The prefactor seems to be $1\pi$ for all cases.

- Monitor the width oscillation of a 1D profile under the same C(t) and multiply lambda by this width. It is more accurate than assume adiabaticity.
- A longer simulation with C=1 could make possible to make a better fit. As now the fitted curve's slope seems to depend much on the interval of the fit.

## Monitoring $\braket{q^2}$ at long times

### The need of introducing a cutoff wave-lenght $\lambda_{cutoff}$
We do not want to take into account modes $q$ with short wave-lenght $\lambda \sim 1/q$. That's because the scaling hypotesis looks to be valid only for large wavelenght features. In fact, while the size of domains grows in time, the width of interfaces is constant at constant C, or just fluctuates if C has a time dependance.
So to monitor the evolution of the unique wavelenght $\lambda(t)$, by considering $\braket{q^2}$, we have to put a CUTOFF to exclude from the average the modes that are responsible for the interfaces, so the short wave-lenght ones.

This is how the POWER is distributed among modes with different $\lambda$ in the initial (random) state and after $t=11$, when domains emerged.
![C=1L=512q2](power%20spectrum/q2/L=512/t=0.png?raw=true)
![C=1L=512q2](power%20spectrum/q2/L=512/t=11.png?raw=true)

From this picture the cutoff of $\lambda = 5$ seems a little bit drastical as it corresponds to $q^2 = (2\pi/\lambda)^2 \simeq 1.5$.
But we adopted 
$$\lambda_{cutoff} = 5$$
for ALL the following simulations

#### C = 1 (constant)
We see that the exponent at long times is $\frac14$ instead of the $\frac12$ that we see at short times (in the linear regime).
While the prefactor is $5\pi$ instead of $4\pi$.
![C=1L=512grad2](q2/C=1/21_06.png?raw=true)
![C=1L=512grad2](q2/C=1/20_06_linear_regime.png?raw=true)
#### $C=1+0.5\sin(2\pi t/T)$ T=2.5
![C=1L=512grad2](q2/oscillatory%20C0=1/T=2.5/21_06.png?raw=true)
#### $C=1+0.5\sin(2\pi t/T)$ T=25
![C=1L=512grad2](q2/oscillatory%20C0=1/T=25/21_06.png?raw=true)

## Do the exponents/prefactor depend on the **initial state**?
We ran simulations with **another** (a different one) random initial state
**Data**: "/.saves/25_06_(A,B)"
![q2newseed](q2/C=1/different_init/25_06.png?raw=true)
![q2newseed](grad2/C=1/different_init/25_06.png?raw=true)
It looks like the results we found do not depend on the (random) initial state.

## Results
Starting from random initial conditions (_datainit.c_).
At **long times** (coarsening)
- $\lambda = \frac{A_{system}}{\int |\nabla u|^2 dxdy}W\simeq 1\pi t^{\frac12}$.
- $\lambda = 2\pi/\sqrt{\braket{q^2}} \simeq 5\pi t^{\frac14}$, where $\lambda_{cutoff} = 5$.

    While in the linear regime (short times) we have $\lambda = 4\pi t^{\frac12}$.
Independently on the seed used for generating the initial state.