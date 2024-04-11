# [2nd part] Checking the analytical ansatz for Kink's evolution

Here we prepare the **initial state** in a different way.

We consider it as the numerical solution (Mathematica NDSolve) of
$$\frac{a}{b}\chi\partial_{\chi}u_k = \partial_{\chi\chi}u_k + u_k(1-u_k^2)$$
where $a = -2, b = 1$ and we use the boundaries
$$u_k(0) = 0\qquad u'_k(0) = 1.321043(5)$$
where we chose for the derivative a value very close to the critical velocity (it is equal to the critical velocity until the cifer in brakets)

![center](Plots/measured%20and%20analytical%20alpha%20beta/NDsolve%20initial/u_k(x).png?raw=true)

![tail](Plots/measured%20and%20analytical%20alpha%20beta/NDsolve%20initial/tail.png?raw=true)

Notice that the plot above **is the same** we got starting from a state of shape $\tanh(x)$, at least for long times.
We **see only small differences** at small times.

So this "post-asymptotic" behaviour (saturation) of the logarithm seem to not be due to the incompatibility of the initial state with our ansatz.
So it **seems it is NOT related** to the fact that "some **information** needs time to **propagate** from the center to the tail". 

![tailRescaled](Plots/measured%20and%20analytical%20alpha%20beta/NDsolve%20initial/rescaled%20tail.png?raw=true)