# Kink shape cose to the core

Even thought the initial state is not a function of the kind

$$u(x,t) = \beta(t)u_k(\alpha(t) x)$$

we want to check wether, at least at long times, this is the shape if the modulation of $C(t)$ is

$$C(t) = -\frac{1}{t-t_0}(1+b/a)$$
where $t_0 = (2\alpha_0^2 a)^{-1}$

## How we check the statement

We can **extimate** easily $\beta(t)$ by measuring the kink's height.

But is **not easy** to extimate $\alpha(t)$, as it **requires knowledge of the analytical shape of $u_k(\chi)$**, at least close to the kink's core.

[That's because if you take as an example $u(x,t) = f(2x)$, it can be that $u_k(\chi) = f(\chi)$ and $\alpha = 2$ **OR that** $u_k(\chi) = f(2\chi)$ and $\alpha = 1$]

So we can check the statement only if we assume the shape of $u_k$.

## What we did

We assumed that, **close to the kink's core**, $$u_k(\chi)\simeq \tanh(\chi)$$

[there is no reason why we assumed it, just that the code we have to measure width assumes this fact]

so we could extimate both $\alpha(t), \beta(t)$. We'll label the extimates as $\alpha*(t), \beta*(t)$.

Now **we can extimate** 

$$u_k(\chi) = \frac{u(x,t)}{\beta*(t)}$$

and $\chi = \alpha*(t)x$


If
-the ansatz $u(x,t) = \beta(t)u_k(\alpha(t)x)$ is true
- and $u_k(\chi)$ is well approximated by $\tanh(x)$, at least close to the kink

Then **the extimates** of the function$u_k(\chi)$, obtained at different times, **must overlap**

## What we see

The extimates of $u_k(\chi)$ overlap, but they do not overlap with the numerical solution $u_k(\chi')$ (NDSolve) of the ode

$$\frac{a}{b}\chi'\partial_{\chi'}u_k = \partial_{\chi'\chi'}u_k + u_k(1-u_k^2)$$

with $a=-2$, $b= 1$

**Notice that**: As $b=1$, $\chi' = \chi$, so we can comparise directly the curves. 

![kinkShapeDecayingCt=20](../../Plots/kink%20shape%20varying%20C/rescaled/C(t)%20decaying%20t-1/u_k(chi)%20NDSolve%20comparison.png?raw=true)

I hope this is related to the assumption on the shape of $u_k(\chi)$ close to the kink's center, and not on the first ansatz.

Maybe we missed the approximation of the shape of $u_k(\chi)$ close to the center, only for a factor multiplying $\chi$.

So we can try to assume $u_k(\chi)\simeq \tanh(\chi\frac{2}{\sqrt2})$, instead of simply $\tanh(\chi)$. 
So we get this

![kinkShapeDecayingCt=20](../../Plots/kink%20shape%20varying%20C/rescaled/C(t)%20decaying%20t-1/u_k(chi)%20NDSolve%20comparison%20tanh(2rad2).png?raw=true)

And we see that is not only a matter of choosing the factor multiplying $\chi$.