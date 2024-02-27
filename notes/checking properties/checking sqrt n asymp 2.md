## Numerical evidence of $u(nT)\sim n^{-\frac12}$ asymptotic behavior

**Note**: As we're intersted on constant (in spce) states, from now on we adopt the following space parameters
- N = 2 (space lattice points)
- dx = 0.01 (space lattice step)
so we choose to have only a few lattice points to have a faster code.
--------------

Analytically, we anticipate that 
$$\frac{1}{u^2(nT)} = \frac{1}{u_0^2} + 2nI_0(T)$$
where the expression of the integral **was wrong the previous time**, because

As $b(t) = \sin(2\pi t/T)$, when we integrate it $$\int_0^t b(t') dt' = \frac{T}{2\pi}(1-\cos(2\pi t/T)$$ and **we were missing** the factor $\frac{T}{2\pi}$.

$$I_0(T)=\int_0^T dt e^{2\frac{T}{2\pi}(1-\cos{\frac{2\pi t}{T}})} = T \int_0^1 du e^{\frac{T}{\pi}(1-\cos 2\pi u)}=$$ 
$$= Te^{-\frac{T}{\pi}}\int_0^1 du e^{-\frac{T}{\pi}\cos(2\pi u)}$$
that is an increasing function of T. 
Numerically we can find the value of $I_0(T)$, for example 
$$I_0(1)\simeq 1.404$$
--------------
As $n$ becomes large, the term with $n$ dominates the right-hand side, yielding the **asymptotic behavior**
$$u(nT)\simeq \frac{1}{\sqrt{2I_0(T)}}n^{-\frac12}$$
Quantitatively, this behavior holds true when $2nI_0(T) >> \frac{1}{u_0^2}$, which occurs when $n>>\tilde{n}$ with $`\tilde{n} = \frac{1}{2*I_0(T)*u_0^2}`$.

The pre-asymptotic behavior can be eliminated **by increasing $T$ or $u_0$**.

However, significantly increasing $u_0$ gets the _initial dynamics_ very fast, due to the non-linear term $u^3$.
If the dynamic is fast, the numerical error you have in the first steps is large.


### Pre-asymptotic behavior

We can see the pre-asymptotic behavior for a small initial value $u_0 = 0.2$ ![here](../../Plots/asymptotic%20new%20plots/analytical%20u=0.2.png?raw=true)

### Asymptotic behavior
The asymptotic behavior is observable in the numerical solutions ![here](../../Plots/asymptotic%20new%20plots/analytical%20u=10.png?raw=true), where we adopted a large $u_0=10$ in order to get rid of the pre-asymptotic behaviour

**However:**
        
        The asymptotic behavior persists **until** a certain $n_{max}$, which decreases with the time step $dt$.

### Post-asymptotic behavior
The saturation time is independent on the period $T$ as shown her
![here](../../Plots/asymptotic%20new%20plots/fixed%20dt=0.008%20u=0.2.png?raw=true)

So the saturation time depends only on $dt$ and not on $T$.

The _lenght_ of the _saturation tail_ seems to be infinite as shows this $tspan = 10^4$ evolution ($u_0 = 10$)
![here](../../Plots/asymptotic%20new%20plots/saturation%20tail.png?raw=true)