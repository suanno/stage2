# [OLD] Kink's analytical shape
# DISCLAIMER:

**The following notes are WRONG for the following reasons**

- We were missing a factor $1/2$ in the formula for $C(t)$.
By fixing this, we've a good match between measured and expected values of $\beta$ and $\alpha$.

-----------------

Even thought the initial state is not a function of the kind

$$u(x,t) = \beta(t)u_k(\alpha(t) x)$$

we want to check wether, at least at long times, this is the shape if the modulation of $C(t)$ is

$$C(t) = -\frac{1}{t-t_0}(1+b/a)$$
where $t_0 = (2\alpha_0^2 a)^{-1}$

**More explicitly**, by checking this is the shape, we want to check wheter this choice of $C(t)$ achieves to control the height and the width of the kink, without modifying its analytical shape $u_k(\chi)$.


In the following we'll also se wether the analytical expressions for $\alpha(t)$ and $\beta(t)$ match the simulations.

## How we check the statement

The idea is to find a way of extimating $\alpha(t)$ and $\beta(t)$ that we can use to extimate $u_k(\chi)$.
Then we will compare the extimations of $u_k$, for different times $t$, and check if they overlap.

In addition, we'll compare the $u_k(\chi)$ extimations with the numerical solution of the ODE for $u_k(\chi)$.

In those test we'll not only see if the analytical shape of the kink $u_k(\chi)$ is preserved during the $C(t)$ modulation (only the width and height change but not the shape)
**but also** we will check what methods for estimating $\alpha$ (width) and $\beta$ (height) work properly.

## $\alpha$ and $\beta$ extimations
There are two ways of extimating $\beta(t)$

- Take the value of $u(x,t)$ when $x >> x_c$, so we're at the plateau.

    **Cons**:

    - In this way you always **understimate** $\beta$, as the function $u(x)$ reaches the plateau value only in the limit $x\rightarrow \infty$.

    - As in your simulation you do not have an isolated kink, you cannot evaluate $u(x)$ to far from $x_c$ to extimate $\beta$.
    So the best you can do is to evaluate $u(x)$ **at the midpoint $\hat{x}$** of two neighboring kinks.
    But, doing so, when $x\rightarrow \hat{x}$ you'll see a divergence of $\log(1-u(x)/\beta)$, as you'll have, **by construction**, that $u(\hat{x}) = \beta$.

        This divergence is **non-natural** as, for an isolated kink, you expect to have divergence as $x\rightarrow \infty$, while here you have divergence at a finite value!

    If $x$ is not so close to the evaluation point $\hat{x}$, we expect that the little understimation of $\beta$ is negligible and we're far from the divergence.
        So, at least in this regime, it seems to be a good approximation of $\beta$.

- By using the expected analytical expression 

$$\beta(t) = sign(\beta_0)[2a/b(t_0-t)]^{-\frac12}$$    

To extimate $\beta$ there are also two ways.
There will be a third way if we knew the analytical shape of $u_k(\chi)$ close to the kink's center, but is not the case.

- As we know the asymptotic shape of $u_k(\chi)$, we can extimate $\alpha$ by looking at this asymptotics (Topic of another notebook)
- Or we can use the expected analytical expression

$$\alpha(t) = sign(\alpha_0)[2a(t_0-t)]^{-\frac12}$$   

### Using analytical expression for BOTH $\alpha(t), \beta(t)$ extimations
![alphabeta_anal_core](../../Plots/analytical%20approach/measured%20and%20analytical%20alpha%20beta/kink_center_anal_beta.png?raw=true)

You can see that $u_k(\chi)$ does not go to 1 when $\chi\rightarrow\infty$, as it should be.

The curves for different times do not overlap and do not overlap with the NDSolve result.

### Plateau value for $\beta(t)$ and analytical $\alpha(t)$ extimations
![alphabeta_plateau_core](../../Plots/analytical%20approach/measured%20and%20analytical%20alpha%20beta/kink_center_plateau_beta_.png?raw=true)

Here you can see that the curves **overlap for high times** and they overlap with the NDSolve result.

We can compare the two extimations of $\beta(t)$

![beta_comparison](../../Plots/analytical%20approach/measured%20and%20analytical%20alpha%20beta/beta.png?raw=true)

You can see that the two slopes are different. This means that the two extimation do not just differ by a costant multiplication factor.

If the slopes are different, it means that
$$\beta_{anal} = e^{k t}\beta_{plateau}$$
with $k > 0$. (the two extimation are both 1 at the beginning by construction of the experiment)

But this relationship is not expected.
In fact, if we evaluate $u(x)$ at a point $x$ that is not the midpoint of two neighboring kinks, then **its distance** to $\beta$ **we expect to cheange in time** as the width of the kink increases.

But, if we evaluate $u(x)$ ad midpoint, we do not expect it to be influenced by the width variation. So we expect the distance from $\beta(t)$ to be costant in time in this case, that is not compatible with the exponential separation of the extimates.

### Comments / Problems
**To sum up**, the analytical extimation of $\beta(t)$ seems to **not work**.

Maybe it is a numerical problem of the simulations.

Instead, the analytical extimation of $\alpha$ seems to work well when $\beta$ is extimated with the "plateau value".