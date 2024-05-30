# Mixed approach

Here we **mix** 
- the approach followed to find "Motion by curvature"
- and the one where $C(t)$ is slow varying (that we used in **1D**)

## Assumptions
Here we make the **same assumptions** we made to find "Motion by curvature".
Then we ask _additionally_ $C(t)$ to be slowly varying (to be fair we did that also before, but now we **quantify** the slowness).

## Difference with the approach used to find "Motion by curvature"

When we say that **the dynamics is slow** (such that the shape of the interface and its velocity have weak time dependance), we have the "_one direction_ wave equation"
$$\partial_t = -\epsilon V_1 \partial_{\xi}\quad V_1\sim 1$$

But, as $C(t)$ is slowly varying (to have a slow dynamic it must be so. Anyway we're intersted in this case)
$$C(t) = \tilde{C}(\epsilon t)\quad\text{where}\quad \delta\tau\sim1\implies\delta\tilde{C}(\tau)\sim1$$
$$\text{so}\qquad \partial_t = \epsilon\partial_{\tau}$$

In principle this second epsilon is different from the other (we have **two** timescales).
But assume, to simplify calculations, that they are the same (we **can tune** $C(t)$ as we want, so we can tune it to be in this regime).
Remember we're also assuming that this is the same $\epsilon$ that describes the lenghtscale of $u$ variations by changing $s$ (respect to the interface width, that is the lenghtscale for variation of $u$ by changing $\xi$, but we're assuming $W\sim 1$).



To take into account **both** the _slow behaviours_, we say that

$$\partial_t = \epsilon\partial_{\tau} - \epsilon V_1\partial_{\xi}$$

We just take a sum of the two expressions, because we are thiking to the chain rule of derivatives.
[YOU SHOULD THINK MORE ABOUT THIS, WHY YOU TAKE SIMPLY THE SUM???]

-------------

We still use the laplacian used to find motion by curvature
$$\Delta u = \partial_{\xi\xi} + \epsilon K_1\partial_{\xi} + \epsilon^2\partial_{SS}$$

and we adopt the Ansatz used in the perturbative approach (1D)

$$u(\xi,s,t) = \beta_0(t) u_{k_0}(\alpha_0(t)\xi) + \epsilon\beta_1(t) u_{k_1}(\alpha_1(t)\xi) + ...$$

**and we assume**, as we find out is like this in the 1D case (so we try like that)
$$\alpha_1 = \alpha_0 = \alpha \qquad \beta_0 = \alpha\qquad C = \alpha^2$$

TDGL becames

$$\epsilon\partial_{\tau} u = \partial_{\xi\xi}u + \epsilon (K_1+V_1)\partial_{\xi} u + Cu - u^3$$

That is **the same** equation we had in the 1D perturbative approach

$$\epsilon\partial_{\tau} u = \partial_{xx}u + \epsilon + Cu - u^3$$

**except for** the **new** term with $K_1+V_1$

- Order $\epsilon^0$

    $$u_{k_0}'' + u_{k_0} - u_{k_0}^3 = 0$$

    $$u_{k_0} = \tanh(\chi\sqrt{2})$$
    where $u_{k_0}' = \partial_{\chi}u_{k_0}$ and $\chi = \alpha\xi$.

- Order $\epsilon^1$

$$``\alpha^2\beta_1(u_{k_1}'' + u_{k_1} - 3u_{k_0}^2u_{k_1}) = \alpha'(u_{k_0} + u'_{k_0}\chi)-(K_1+V_1)\alpha^2u_{k_0}'``$$

## An apparent big problem

That is **the same** equation we get in the 1D perturbative approach, **except for** the term with $K_1+V_1$.

That terms makes things difficult, as we cannot get rid of the **time dependent terms** in the differential equation as easy as before (we want an ODE in $\chi$ with coefficients not depending on time).

In fact, requiring that
$$\alpha^2\beta_1 = a\alpha' = b\alpha^2$$
determines the shape of $\alpha = \sqrt{C}$ and so of $C(t)$. **That's BAD!**

-------------------

Anyway, if you use the **Fredholm alternative**, you will find the "Motion by curvature" condition
$$K_1 + V_1 = 0$$

so the uncomfortable term in the differential equation will disappear!

You **find Motion by curvature**, because:

---------------

The Homogeneous equation is

$$u_{k_1}''+(1-3u_{k_0}^2)u_{k_1} = 0$$

That has solution $\partial_{\chi}u_{k_0}$ as you can see that, if you derive the equation for order $\epsilon^0$ respect to $\chi$, you find the above equation where you plug $u_{k_1} = u_{k_0}'$ inside.

Then, you can use the Fredholm aletrnative **neglecting boundary terms**
$$<f,v> = \int d\chi\quad fv = 0$$

where 
$$f(\chi) = \alpha'(u_{k_0} + \partial_{\chi}u_{k_0}\chi) - \alpha^2(K_1+V_1)\partial_{\chi}u_{k_0}$$
$$v(\chi) = \partial_{\chi}u_{k_0}$$

By using the facts that
- $u_{k_0}$ is odd (we found it is $\tanh$), so $\partial_{\chi}u_{k_0}$ is even
- $(\partial_{\chi}u_{k_0})^2$ is always positive (or at least its integral is **strictly** positive)
- the integration domain is symmetric [??? We do not even know what is this domain!!!]

Then you find the "Motion by curvature" $V_1 = - K_1$.


-------------------

By using motion by curvature, the differential equation becames

$$\alpha^2\beta_1(u_{k_1}'' + u_{k_1} - 3u_{k_0}^2u_{k_1}) = \alpha'(u_{k_0} + u'_{k_0}\chi)$$

So the uncomfortable term disappeared and we recover **the same** ODE in $\chi$ that we found in the "**1D** perturbation approach".

So we already know that, in order to eliminate the time dependance, we require

$$\beta_1(\tau) = \frac12 C'(\tau)C^{-\frac32}$$

So we are left with this ODE

$$``u_{k_0} + u'_{k_0}\chi = u''_{k_1} + u_{k_1}-3u_{k_0}^2u_{k_1}'``$$

## Conclusions

We found that, **up to first order** in $\epsilon$ we have
- Motion by curvature [maybe you have corrections to the velocity at higher orders, or maybe it is right at any order **???**]
- The **same** analytical shape of $u$ we got in **1D**, where $$x \rightarrow \xi$$

## We're assuming only one spatial/temporal scale $\epsilon$
We're assuming that all the following (short) scales (some spatial and some temporal) **are the same** (there is the **same** $\epsilon$):

- [SPACE] Scale of the curvature 
$$\kappa = \epsilon K_1$$
- [SPACE] Wavelenght for $u$ changes moving along a fixed $\xi$ curve (assuming that the wavelenght for changes of $u$ moving along a fixed $s$ line is $W\sim 1$) 
$$\partial_{s} = \epsilon\partial_S\qquad \partial_S\sim\partial_{\xi}$$
- [SPACE/TIME] Velocity (normal) of the front/interface/kink
$$v = \epsilon V_1$$
- [TIME] Slowness for $C(t)$ changes in time
$$C(t)=\tilde{C}(\epsilon t)\qquad \delta\tau\sim 1 \implies \delta\tilde{C}(\tau)\sim 1$$

And we **never** quantified the timescale for the front/interface/kink shape changes over time (we just asked them to be slow so we can think to a propagating front).
[Maybe we're implicitly assuming that this timescale is lower than the one of the speed (for the front of performung a movement of order 1)]