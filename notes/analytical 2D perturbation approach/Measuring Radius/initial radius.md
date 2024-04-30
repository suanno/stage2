We monitor an initial circular island with radius $R_0 = 25$. 

# How we make measurements
- $R^2$: We make an average of $r^2$ weighted on $|\nabla u|$ (we **take a square root here!**), unless differently specified.

# Constant C

C = 0.1

### Changing dt
![constC](../Measuring%20Radius/C=0.1_dt.png?raw=true)
### Changing dx
![constC](../Measuring%20Radius/C=0.1_dx.png?raw=true)

### Changing the formula for $R^2$ extimation

![constC](../Measuring%20Radius/grad_grad2.png?raw=true)

# Conclusions
### New INITIAL radius

It looks like there is a **new** initial radius $\tilde{R_0}$ for which the motion by curvature

$$R^2(t) = \tilde{R_0}^2-2t$$

is respected, and $\tilde{R_0}\neq \tilde{R}$ unless $C=1$ (notice that in the initial state the interface width is $W=1$).

- The magnitude of the time discreteness **dt** is **not influent** on the magnitude of the deviation we see at small times.
- Instead, by reducing **dx** we have a better match with the expected motion by curvature.

This means that this deviation we see at small times (the discrepancy between the _true_ initial radius and the _new one_) is of **numerical nature**.
Then, as it is not dependent on $dt$, that discrepancy is not a feature of the algorithm integrating the dynamics.
The fact that 
- depends on $dx$ (that is the same adopted when integrating the gradient to extimate $R^2$)- and on the formula we use for extimating $R^2$

suggests this is a feature of the way we extimate/measure $R^2$ at each step.