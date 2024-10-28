# Dependence of the plot $d(t)$ v.s. $\log(t_c-t)$ on the parameters
$$d_0; \bar{C}; A; T$$

## Initial distance $d_0$
By increasing the initial distance, we get the same curve.

As this curve seems to be a line asymptotically (when $t>>t_c$), then it seems to hold a relation
$$d(t) = n\log(\alpha(t_c-t)) = n\log\alpha + \log((t_c-t)^n)$$
where the values $n, \alpha, t_c$ do not depend on $d_0$ (if $\bar{C}, A, T$ are fixed).
### How does $t_c$ scale with $d_0$?

$$d_0=d(0)=n\log(\alpha t_c)$$
$$t_c = \alpha^{-1}e^{\frac{d0}{n}}$$

So, if $d_0\rightarrow 10*d_0\implies t_c\rightarrow t_c^{10}\alpha^{9}$

So it is difficult to sample more the tail of this plot, as it needs to take a larger value of $d_0$.

#### And if we simulate large initial distance just until $\log(t_c-t) = 13$ and we use an extimate of $t_c$?
It makes sense to arrive until 13, so we see if it matches with the precedent curves.

Well, the **minimum** time $t$ of the simulation will be given by
$$t = t_c-e^{13}$$
but, as $t_c\sim e^{d0/n}$, if $n\sim 1$, then if we take $d_0\geq 30$ we see that
$$e^{30}>>e^{13}$$
so the minimum duration of the simulation $t\sim t_c$.

#### What else can we do?
An idea could be changing the parameters A,C0,T in order to have a **much faster** decay, meaning a lower value of $t_c$ for large distances.
In this way, we can simulate scenarios starting from large distances.
- T=30
![](d%20vs%20log%20t/T=30/main.png?raw=true)
![](d%20vs%20log%20t/T=30/slopes.png?raw=true)
![](d%20vs%20log%20t/T=30/tau.png?raw=true)
- T=50
![](d%20vs%20log%20t/T=50/main.png?raw=true)
![](d%20vs%20log%20t/T=50/slope.png?raw=true)
![](d%20vs%20log%20t/T=50/tau.png?raw=true)
- T=100
![](d%20vs%20log%20t/T=100/main.png?raw=true)
![](d%20vs%20log%20t/T=100/slope.png?raw=true)
![](d%20vs%20log%20t/T=100/tau.png?raw=true)