We monitor an initial circular island with radius $R_0 = 25$. 




# How we make measurements
- $R^2$: We make an average of $r^2$ weighted on $|\nabla u|^2$;
- **Average over $[t\pm T]$**: Average over the data in the range $[t\pm T]$ [it is well defined only for $t>T$ and $t<tspan-T$];
- **Slope**: Variation of $R^2$ between a data point at $t=0.75*tspan$ and a point at $t=0.5*tspan$;
- **Oscillations respect to average**: The average over $[t\pm T]$ is subtracted from the data;
- **Amplitude of oscillations**: We consider 4 periods and we calculate (half) the difference of maximum and minimum value [it is not the peak2peak value, because from oscillations we see it increases over time].


# Constant C

### Changing C

dx = 0.1; dt = 0.1

![constanC](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/constantC.png?raw=true)
![constanC](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/constantC_slopes.png?raw=true)

### Changing dt

dx = 0.1; C = 1

![dtC=1](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/dt/C=1/main.png?raw=true)
![dtC=1](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/dt/C=1/slopes.png?raw=true)

# Slow oscillating C

$C_0 = 1; A = 1; T = R_0 = 25$

![Coscill](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/C=1_and_C0=1A=1oscill.png?raw=true)

### Changing dx

dt = 0.1

![dxCoscill](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/dx/main2.png?raw=true)
![dxCoscill](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/dx/oscillations2.png?raw=true)

### Changing dt

dx = 0.1

![dtCoscill](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/dt/C0=1A=1T=R0=25/C0=1A=1.png?raw=true)
![dtCoscill](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/dt/C0=1A=1T=R0=25/oscillations.png?raw=true)
![dtCoscill](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/dt/C0=1A=1T=R0=25/amplitude.png?raw=true)
![dtCoscill](../Measuring%20Radius/numerical%20deviation%20motion%20by%20curvature/dt/C0=1A=1T=R0=25/slope.png?raw=true)

# What we see
There is a deviation from motion by curvature:
- There seems to be an **effective initial radius** different from the initial radius, when $C\neq 1$ (the initial width of the interface is $W=1$);
- The slope of $R^2(t)=-2t$ is not exactly 2;
- We see oscillations deviating from the expected linear behaviour.
# Conclusions
### Slope and oscillations' amplitude

- The magnitude of the space discreteness **dx** is **not influent** on the magnitude of the slope or the oscillations.
- Instead, by reducing **dt** we have a better match of the slope and weaker oscillations.

This means that the wrong slope and the oscillations are of **numerical nature** and are due to time discretization and not space!
So this numerical error affects **the integration of the dynamics** and not the way we calculate $R^2$ at each step (that does not depend on dt, but only dx).