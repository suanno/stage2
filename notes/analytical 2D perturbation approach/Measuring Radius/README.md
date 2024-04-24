# $|\nabla| or |\nabla|^2$
![sqrt](sqrt_grad2.png?raw=true)
![NOsqrt](grad2.png?raw=true)

# Costant C
![constC](../Measuring%20Radius/constantC.png?raw=true)

What happens during the **transient**?

![constC](../Measuring%20Radius/gradient.png?raw=true)
![constC](../Measuring%20Radius/gradient_slice.png?raw=true)

It looks like there is an **effective initial radius R0** that is different from the initial radius when $C\neq 1$.

# Numerical error constant C
The mismatch we see with constant C from the expected behaviour from motion by curvature
$$R^2(t) = R_0^2 - 2t$$
is due to time discretization.
![changingdt](../Measuring%20Radius/mismatch_dt.png?raw=true)

# Two different R0
But we saw that the deviation its of numerical nature as it gets less if you reduce dt...
![changingdt](../Measuring%20Radius/two_R0.png?raw=true)


# Oscillating C(t)
![changingdt](../Measuring%20Radius/C0=1A=1.png?raw=true)
![changingdt](../Measuring%20Radius/C0=1A=0.5.png?raw=true)
![changingdt](../Measuring%20Radius/C0=1A=0.1.png?raw=true)

