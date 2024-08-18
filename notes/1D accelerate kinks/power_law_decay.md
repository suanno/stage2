data: _.saves/twokinks/d=20_

Here we study wether the distance between two neighbouring kinks $d(t)$, when
$$C=\bar{C}+A\sin(2\pi t/T)$$
has a time dependence
$$d(t)\sim (t_c-t)^n$$
where $t_c$ is the time when the two kinks collapse.

The initial state was prepared as in _README.md_ and $d(t)$ has been measured in time as explained in the same file.

In the following simulations we adopted
$$\bar{C}=0.5;\quad A=1$$

The logarithm of $t_c-t$ and $d$ are plotted, so we verify if they are linear dependent
$$\log d \sim n\log(t_c-t)$$

### Estimate $t_c$

And $t_c$ is extimated by taking the time when $d$ goes (for the first time) below a treshold value $\epsilon$. In this case we adopted $\epsilon=1$, observing $\log(t_c)$ does not change much if you take a value of $\epsilon$ closer to zero.

### Simulations

- T=25
![](../1D%20accelerate%20kinks/d0=20/varying_T/tc-t/T=25.png?raw=true)
- T=40
![](../1D%20accelerate%20kinks/d0=20/varying_T/tc-t/T=40.png?raw=true)


I made a linear fit far from the collapse ($t_c-t >> 1$).

# Dependence of $t_c$ on the amplitude $A$
I show also the following simulations, where a different value of $A$ was adopted in each one

![](../1D%20accelerate%20kinks/d0=20/varying_A/loglog.png?raw=true)