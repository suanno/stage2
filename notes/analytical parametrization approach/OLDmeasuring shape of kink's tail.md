# [OLD]What we expect
# DISCLAIMER:

**The following notes are WRONG for the following reasons**

- We were missing a factor $1/2$ in the formula for $C(t)$.
By fixing this, we've a good match between measured and expected values of $\beta$ and $\alpha$.

- We studied the asymptotic regime **in the wrong** $y$ values region!

--------------

If $b = 1$ and $a = -2$ we expect that

 $$\delta u_k \sim e^{-\chi'^2}\frac{1}{\chi'^2}$$

where $u_k = 1 - \delta u_k \implies \delta u_k = 1 - u_k$

So, asymptotically ($\chi' \rightarrow \infty$)

$$\log(1-u_k) \sim -\chi'^2$$

But we look for a relation that connects $x$ with $u(x,t)$, so we use

$$u(x,t) = \beta(t)u_k(\chi)$$
$$\chi' = b^{\frac12}\quad \chi = \alpha(t)x$$

We find

$$\log(1-\frac{u(x,t)}{\beta(t)}) \sim -\chi'^2 = \alpha^2 b x^2$$

In order to check if $u_k(\chi')$ has this asymptotic (and eventually to measure $\alpha$ thanks to this asymptotic relation) we can, **at different times**

- Make an extimate of $\alpha$ and $\beta$, and use them to 
- Extimate $u_k = u/\beta$
- Extimate $\chi$ as $\alpha x$

And then plot the extimates of $u_k(\chi)$ v.s. $\chi^2$ in the same canvas.
If they overlap, and the plot shows a linear asymptotic, that means that the asymptotic is veryfied.

Eventually we'll plot, on the same canvas, the NDSolve result for the $u_k(\chi')$ ODE.

# Experimental measure

## Experimental difficulties
- As we adopt PBC boundaries, we can simulate only 2 kinks (not just a single one!).

    So we expect the asymptotic behaviour **only for certain values of x**, such that the approximation of isolated kinks holds; **not** for any $x$ sufficiently large. If $x$ increases so much that it approaches the other kink, we do not expect the asymptotic behaviour anymore!

- The kinks are centered in position different from $x=0$.

    So we have to substitute $x\rightarrow \tilde{x} = (x-x_c)$ in the expected relation, that will hold if $\tilde{x} >> 0$.

## Initial state preparation

**Notice that**: Our **initial state is prepared** by keeping $C=1$ constant for a time $t >> \tau = \frac{1}{C}$, in order to reach the stationary state associated to $C=1$ constant.
This state is

$$u_{C = 1}(x) = \tanh(\frac{x}{\sqrt2})$$

that is **incompatible with our ansatz**, as asymptotically 

$$1-u_{C=1}(x) \sim e^{-2x}$$

instead of having the shape we're going to check.

**We should** check the expected behaviour starting from a state compatible with the ansatz, **but we don't do that**.
For that reason, the initial height and width are **NOT related by** the equation $\beta = b\alpha$.

We simply adopt an initial height compatible with the ansatz (so we choose $\beta_0 = 1$).
But, as we said, $\alpha_0$, that is determined by the proportionality relation, is NOT the reciprocal of the initial width $\frac{1}{1/\sqrt2}$.

[WHY it is so  ???]
**Additionally** I measured the width of the initial state, and I get $w = 3$, instead of getting

$$w = 2(\frac{1}{\frac{1}{\sqrt2}}) = 2\sqrt2 \simeq 2.8$$

## What we see

### Extimating BOTH $\beta(t), \alpha(t)$ with the expected analytical expressions

![tail_alphabeta_anal](../../Plots/analytical%20approach/measured%20and%20analytical%20alpha%20beta/saturation_beta_analytical.png?raw=true)

You can see there is a saturation, instead of a linear decrease.

The experimental curves overlap, but they are not compatible with the NDSolve result.

The reason why there is a saturation, is that adopting this extimate of $\beta$, we have seen (other notebook on kink's shape) that **the extimate of** $u_k(\chi)$ does not converge to 1, but to a value $< 1$.

As a consequence $1-u_k$ does not converge to zero at $\chi\rightarrow\infty$ and so its logarithm converges to a finite value, instead of diverging to zero. 

### Extimating $\beta(t)$ evaluating $u(x)$ at the midpoints of neighboring kinks

![tail_alphabeta_anal](../../Plots/analytical%20approach/measured%20and%20analytical%20alpha%20beta/tail_anal_alpha.png?raw=true)

Here we have a good match between the curves and a linear decay, at least until a certain value of $\chi$.

Then, we do not see anymore the asymptotic behaviour and that is due to the fact that this extimation of $\beta$ brings the divegence at $x\rightarrow \infty$ to a finite value (midpoint of two kinks).

Here you can see those **non-natural** divergences

![finiteDivergence](../../Plots/analytical%20approach/measured%20and%20analytical%20alpha%20beta/unnatural_divergence.png?raw=true)

[Anyway, as the kink is not isolated, we cannot make a simulation where the divergence is at infinity...]

But there is not a good match with the NDSolve result

### Extimating $\alpha(t)$ from the slope of the decay

If we measure $\alpha(t)$ by measuring the derivative of the logarithm (and so the slope of the linear decay) we can extimate $\alpha$ as

$$\alpha = \sqrt{-\frac{1}{b}(\frac{\Delta g}{\Delta y}+\frac{1}{2y})}$$
where $g(y) = \log(1-u(x,t)/\beta(t))$ and $\beta(t)$ is extimated with the "plateau value".

In this way we reach a better match
![alpha_measured_from_slope](../../Plots/analytical%20approach/measured%20and%20analytical%20alpha%20beta/tail_measured_alpha.png?raw=true)

### Comparison of two methods to extimate $\alpha$

We can see that there is a huge mismatch for small times.
I think this is due to the fact that $\alpha$ does not start from $\alpha_0$ (problem due to the fact that the initial state is not compatible with $\beta^2 = b\alpha^2$).

But then, for larger times, the two curves seem to merge.

I think that is thanks to this matching at high times that we had a good match with the numerical solution in the notebook about "kink shape", where we extimated $\alpha$ with its analytical expression.

![comparisonAlpha](../../Plots/analytical%20approach/measured%20and%20analytical%20alpha%20beta/alpha.png?raw=true)

<!--
We want to see this asymptotic behaviour

$$\log(1-\frac{u(x,t)}{\beta(t)}) \sim x^2$$

Where **we extimated $\beta(t)$** by taking the value of $u(x,t)$ at $x$ very big respect to the kink's core, so that you reach the plateau.
In particular, we took its value near the midpoint of the two kinks.

![variousTimesKinkShape](../../Plots/kink%20shape%20varying%20C/rescaled/C(t)%20decaying%20t-1/tail_shape_lot_of_t.png?raw=true)

There are **three regions** of values of $x$
- When $x \sim > x_c$ we are close to the center of the kink, so we do not expect the **asymptotic** behaviour.
- When $x >> x_c$, but not so much to be closer to the other kink.

- When $x$ approaches the midpoint between the two kinks.
    
    If you look at the state of the system (**focus on the kink at the center of the image**), you will see that you expect a divergence to $-\infty$ of the above plot when $x$ crosses the midpoint between the kinks.
    That's because **we extimated** $\beta(t)$ as the plateau value (the plateau at the right of the kink, where $x > x_c$).

    If you look at the previou plot, you see that the expected "linear" asymptotic behaviour is numerically seen only until a certain $x$.
    If you compare with the second plot, this happens when $x$ starts to approach the midpoint between the two values.
    ![kinkShapeDecayingCt=20](../../Plots/kink%20shape%20varying%20C/rescaled/C(t)%20decaying%20t-1/t%20=%2020.png?raw=true)

So we can see the expected asymptotic, but only for values of $t$ sufficiently large.
This must be related to the fact that we're starting with a state that is incompatible with the ansatz, so doesn't show the expected asymptotic from the beginning.

Pay attention to the fact that, for large times, the kinks overlap and so the "independent kink approximation" no more holds.

![kinkShapeDecayingCt=20](../../Plots/kink%20shape%20varying%20C/rescaled/C(t)%20decaying%20t-1/t%20=%2050.png?raw=true)

Anyway, from the previous plot it seems that the shape of the tail follows the expected asymptotic behaviour even when the kinks overlap.

### Comparison with NDSolve numerical solution of the $u_k(\chi)$ ODE

We said that we expect 

$$\log(1-u_k(\chi)) \sim -\chi^2$$
$$\log(1-\frac{u(x,t)}{\beta(t)})\sim -\alpha(t)^2x^2$$

If we 

So, if we plot **over** the previous figure the numerical solution $u_k(\chi)$ obtained from NDSolve (v.s. $\chi^2$) we **cannot make serious comparisons**. 
That's because there is a factor $\alpha^2$ in one of the two cases so we expect a different inclination of the line we expect to see.

Anyway we report this result [Note that, for the numerical solution, you are plotting $u_k(\chi); \chi^2$ **instead of** $u(x,t); x^2$]


![kinkShapeDecayingCt=20](../../Plots/kink%20shape%20varying%20C/rescaled/C(t)%20decaying%20t-1/tail_shape_NDSolve%20comparison.png?raw=true)

In order to make a serious comparison, you should **measure** the width (and so extimate $\alpha(t)$) and put on the x axis $\chi^2$ instead of $x^2$ **even for** the simulation data.
-->