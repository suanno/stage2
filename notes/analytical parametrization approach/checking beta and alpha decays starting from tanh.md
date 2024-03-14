# Checking the analytical ansatz for Kink's evolution

**Data**: ./saves/C decaying driving a=-2 b=1 beta0 = 1 L = 1000/

Modulating 
$$C(t)=-(t-t_0)^{-1}(1+\frac{b}{a})$$
we want to check if the system evolves according to

$$u(x,t) = \beta(t)u_k(\alpha(t) x)$$

The **initial state** is prepared by keeping $C$ to a **constant value** $C=1$ for a long time ($\Delta t = 10$).

## How we check the above relation
Checking the above relation means checking two properties:

1) that the analytical shape of the kink $u_k(\chi)$ is preserved during the $C(t)$ modulation (only the width and height change but not the shape)
2) that the width and height evolve as expected
$$\alpha(t) = \pm [2a(t_0-t)]^{-\frac12}$$
$$\beta(t) = \pm [2\frac{a}{b}(t_0-t)]^{-\frac12}$$


For the **first experiment**, we will use the expected analytical expressions to compute $\alpha$ and $\beta$.
We'll use them to rescale
$$u = u_k/\beta\quad \chi = b^{-\frac12}\alpha x$$

And we'll check if
- the experimental curves $u_{k}(\chi)$ for different times overlap (this means the kink's analytical shape is not changing, but only width and height are)
- they even overlap with the NDSolve result of the ODE for $u_k(\chi)$

While for the **second experiment**, we will considered some methods to measure experimentally $\alpha$ and $\beta$ in time, and then we will compare them with the expected analytical expressions.

We will measure
- $\beta(t)$ by evaluating $u(x)$ very far from the kink center (when it reaches the **plateau**), exploiting that $u_k(\chi)\rightarrow 1$ when $\chi\rightarrow\infty$.

    As there are two kinks, so we cannot go too far from the center, we will extimate $\beta$ as  $u(\frac34 L)$.

    By taking a very big lattice ($L = 10^3$), we do not see significant overlap between the kinks, for any sampled time.
    This means that this method for $\beta$ extimation is not influenced by the overlap of kinks and so does not depend on time.

- $\alpha(t)$ by exploiting this asymptotic

    ### Asymptotic decay of $1-u_k(\chi)$ when $b=1, a = -2$

    If $b = 1$ and $a = -2$, the ODE for $u_k(\chi')$ tells that asymptotically
    
    $$\delta u_k \simeq \mu_0^2 e^{-\chi'^2}\frac{1}{\chi'^2}$$
    
    where $u_k = 1 - \delta u_k \implies \delta u_k = 1 - u_k$

    and notice that $\chi = \chi'$ as $b=1$

    $$\log(1-u_k) \simeq 2\log\mu_0 -\chi^2 - \frac12\log\chi^2$$

    Remembering that

    $$u(x,t) = \beta(t)u_k(\chi)$$
    $$\chi = \alpha(t)x$$

    We find


    $$\log(1-\frac{u(x,t)}{\beta(t)}) \simeq 2\log\mu_0 -\alpha^2 x^2 - \frac12\log(\alpha^2x^2)$$

    So if we use the expected analytical expression to find $\beta$, then we can **measure** $\alpha$ by measuring the derivative (respect to $\chi^2$) of the above function.

    If we call
    $$y = \chi^2\quad g(y) = \log(1-u/\beta)$$

    then
    
    $$\partial_y g(y) = -\alpha^2-\frac{1}{2y}$$

    so we can calculate $\alpha$ as
    $$\alpha = \sqrt{-\frac{1}{b}(\frac{\Delta g}{\Delta y}+\frac{1}{2y})}$$



# DISCLAIMER:
**In the experiments we work with an $L=10^3$ lattice.**.
In the "old/L=100/" directory you can find experiments with a smaller lattice. Here we met problems, I think related to the overlap of kinks (over the fact that we were missing something)

We made this choice because previously we had an $L=10^2$ lattice that we found **too small** for our checks for the following reason:

We do not start from a state where $u_k$ has the right shape and $\beta^2 = b\alpha^2$; so the system **needs time to BECOME CONSISTENT** with our analytical ansatz.

But, if the lattice is small, the time the system takes to become consistent with the ansatz is comparable with the time two neighboring kinks **start to overlap** (so we cannot consider anymore them independent).

In addition to the kinks' independance problem when the lattice is small, you have some problems in extimating $\beta$ by evaluating $u(x)$ at the midpoint of two kinks, because the increase of overlap, increases the distance between $u(3/4 L)$ and $\beta$!!!

## First experiment (kink's shape)

We can see that the initial state is not compatible with the ansatz.

For small times ($t = 1$, orange curve) we have some mismatch.
I think this is due to the fact that at the beginning the state has not the ansatz shape, and it **has to reach consistency with time**.

For high values of $t$, we see that all the curves overlap and overlap with the NDSolve result too.

Both the values of $\alpha(t)$ and $\beta(t)$ used for rescaling are obtained by using the expected analytical expressions.

![u_k(x)](Plots/measured%20and%20analytical%20alpha%20beta/u_k(x).png?raw=true)

## Second experiment ($\beta$ and $\alpha$ evolution)


### $\beta(t)$ can be extimated by evaluating $u(x)$ far from the kink 
(and not too close to the neighboring one)

We extimated it by evaluating $u(3/4 L)$.
![beta](Plots/measured%20and%20analytical%20alpha%20beta/beta.png?raw=true)

## $\alpha(t)$ can be extimated from tail slope

The black dots indicate the region where the slope was extimated.
As we expect this asymptotic behaviour **in the tail**, we considered the two extrema (black dots) such that
$$x_1 = x_c + 1/\alpha\quad x_2 = x_c + 2/\alpha$$
where, for the above formulas, we extimated $\alpha$ with the analytical expected value (Remember that $1/\alpha$ is a measure of the **kink's width**).

While $u_k$ was extimated by using the analytical expected value for $\beta$ as
$$u_k = u/\beta$$

![tails](Plots/measured%20and%20analytical%20alpha%20beta/tail.png?raw=true)

![alpha](Plots/measured%20and%20analytical%20alpha%20beta/alpha.png?raw=true)

## Ratio $\alpha(t)/\beta (t)$

**Notice** that the match of $\beta$ is better than the one of $\alpha$.

The little mismatch in $\alpha$ is the one that causes little mismatch in the ratio.

![ratioBetaAlpha](Plots/measured%20and%20analytical%20alpha%20beta/ratio.png?raw=true)

### Rescaled shape of the tail
By using the expected aalytical expresions for $\alpha(t)$ and $\beta(t)$ we can extimate $u_k(\chi)$.

We expect this function to be the same at any time, as the analytical shape of the kink doesn't change in time (only height and width do)

![rescaledTail](Plots/measured%20and%20analytical%20alpha%20beta/tail%20rescaled.png?raw=true)

In NDSolve we used a value for the derivative at $\chi' = 0$ that is very close to the critical value for which $u_k(\chi\rightarrow\infty)=1$ and not $0$ or $\infty$ (in the physical analogy it is a critical velocity).

$$v = 1.321043(5)$$
We are sure on the value of the critical velocity until the cifer in brakets.