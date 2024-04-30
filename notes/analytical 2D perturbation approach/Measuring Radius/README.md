
# Numerical errors
That affect the simulation of an initial circular island.

# What we see in simulations

### New INITIAL radius
For which the motion by curvature is satisfied, instead of the _real_ initial radius.
See that the orange line has a distance from the others, **as if there was a different initial radius**.

[See here](initial%20radius.md)

![constanC](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/constantC.png?raw=true)

### Deviation of the slope
from "-2" that is the one expected by motion by curvature.

[See here](slope%20and%20oscillations.md)

![dtC=1](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/dt/C=1/main.png?raw=true)

-------------------------

Deviations from motion by curvature:
- There seems to be an **effective initial radius** different from the initial radius, when $C\neq 1$ (the initial width of the interface is $W=1$);
- The slope of $R^2(t)=-2t$ is not exactly 2;
- We see oscillations deviating from the expected linear behaviour.

# Conclusions
Both the phenomenas of the new initial radius (deviation at small times) and the wrong slope (and presence of unexpected oscillations) are of **numerical nature** as their magnitude changes with $dx$ and $dt$.

- The new initial radius is an effect introduced by the way we extimate $R^2$ and it is not a feature of the integration of the dynamics.

- Instead, the wrong slope and the oscillations are a property of the integration algorithm.