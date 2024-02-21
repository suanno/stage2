# Small perturbation of a flat profile

We consider the following initial state, that is a perturbation of a flat profile.
$$u(x,0) = u_0 + \delta u(x) = u_0 + \epsilon \sin{(2\pi x/\lambda)}$$

We already know how the flat part $u_0(x,t)$ evolves and we are intersted in how the deviation from the flat profile $\delta u(x,t)$ evolves.
This happens according to
$$\delta U_t(q,t) = (f'(u_0(t))-q^2)\delta U(q,t)$$
$$f'(u_0(t)) = C(t) - 3u_0(t)^2$$

If we neglect the time dependance of $f'(t)$, **even at long times t**, the above equation has exponential solutions 
$$\delta U(t) = e^{f'(u_0(0)-q^2)t}\delta U(0)$$


So the mode $q$ is unstable if $f'(u_0(0)) > q^2$.


As a consequence, we know that the TDGL equation **admits unstable modes $q$** only if
- $f'(u_0) > 0$ so if $|u_0|<\sqrt{C/3}$
- C > 0
- The mode with the smallest wavelenght $\lambda_{min}$ must satisfy $\lambda_{min} > L$


## Checking if there are unstable modes only for the predicted values of C (for costant C)

We choose $C = 1$ and $L = 100$.

We add to the flat initial profile a _smooth perturbation_ that is a sine with a wavelenght $\lambda = 20$ that we choose such that 
$$\lambda >> \lambda_{min}(u_0 = 0.5) \simeq 12$$ 
so we can check the instability modes precence at least until $u_0 = 0.5$ that is very close to the border $\sqrt{C/3}\simeq 0.588$.

- From $u_0 = 0$ to $u_0 = 0.4$ we see the mode growth (so the instability)

![u_0=0](../Plots/mode%20growth/u0%20=%200.png?raw=true)
![u_0=0.3](../Plots/mode%20growth/u0%20=%200.3.png?raw=true)
![u_0=0.4](../Plots/mode%20growth/u0%20=%200.4.png?raw=true)


- But for $u_0 = 0.5$ **we cannot** see that in this simple way

![u_0=0.5](../Plots/mode%20growth/u0%20=%200.5.png?raw=true)

- Then, for $u_0 = 1.2 > C$ we can see the mode decay

![u_0=1.2](../Plots/mode%20growth/u0%20=%201.2.png?raw=true)


It seems that the region between $C$ and $\sqrt{C/3}$ is difficult to check and even outside just near the two values.