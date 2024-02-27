# Sensibility of initial dynamics to $u_0$
We expect the initial dynamics to be fast if $u_0$ is large, due to the non linear term $u^3$.

And if the dynamics is fast, we expect to have a big numerical error at the beginning, if we discretize time.

Here we compare the initial dynamics for different values of $u_0 = 0.2, 1, 10$.

**Note**: The "analytical" prediction is evaluated only at times $t=nT$, so fluctuations are absent.

![0.2](../Plots/asymptotic%20new%20plots/initial%20dynamics%20u=0.2.png?raw=true)
![1](../Plots/asymptotic%20new%20plots/initial%20dynamics%20u=1.png?raw=true)
![10](../Plots/asymptotic%20new%20plots/initial%20dynamics%20u=10.png?raw=true)

In the last case ($u_0 = 1$) the initial dynamics is strongly dependent on the time step $dt$.