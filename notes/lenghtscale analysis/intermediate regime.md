This is the regime we fail to study analytically.
It is located between the linear regime and the asymptotic one.
This is the regime of dynamics when **domains start to form but are not yet well formed**.

Experimentally, in this regime $\lambda$ and $\lambda_{DW}$ change shape in a way that connects the linear and the asymptotic behaviours.

-------------------

# Duration of the linear regime
Each mode $q$ evolves according to
$$U_q(t) = U_q(0)e^{\int_0^t (C(t') - q^2)dt'}$$
If the initial conditions are _random_, then $U_q(0)=U_0 \forall q$ and to see when the linear regime ends, we reasonably say:
- consider only the q modes that explode
    
    If C is constant, then $U_q(t)=U_0 e^{(C-q^2)t} = e^{-\frac{t}{\tau_q}}$ with
    $$\tau_q = \frac{1}{q^2-C}$$

    So a mode explodes if $\tau < 0$.
- among the exploding modes, select the one that explodes in the less time

    So we take the mode for which $C-q^2$ is maximum.
    Then the characteristic time for the explosion will be $-\tau_q$, where the sign is there just to have a positive value.

Now $C-q^2$ is maximum when q = 0 (and there is a mode q=0 in our simulation. The discreteness of the lattice introduces a maximum value for $q_x, q_y$ but NOT a minimum one).
So the characteristic time for the explosion is $$\tau = \frac{1}{C}$$

# Value of $\lambda$ at the end of the linear regime

In the linear regime, starting from random initial conditions, we know analytically that
$$\lambda(t)\simeq 4\pi t^{\frac12}$$

So, at the end of the linear regime ($\tau \propto \frac{1}{\tau})$, it will have the value

$$\tilde{\lambda} = \lambda(\alpha\frac{1}{\tau}) = 4\pi \alpha^{\frac12}C^{-\frac12}$$

So we can say that $\log(\tilde{\lambda}) + \frac12 \log(C)$ is **independent on C**.

--------------

After this consideration, we track $\lambda(t)$ in experiments with different values of C.

Data: ".saves/25_06_A" (for C=1); ".saves/12_07_(A,B,C)" (for C=2 , 3, 0.5)

L = 512, dx = 0.1, dt = 0.001

Normalizing the time respect to the duration of the linear regime:
![normalized_lambda_C_x](../lenghtscale%20analysis/q2/different_Cs/normalized_x.png?raw=true)

And normalizing even $\lambda$ respect to the value at the end of the linear regime $\tilde{\lambda}$


![normalized_lambda_C_xy](../lenghtscale%20analysis/q2/different_Cs/normalized_xy.png?raw=true)


From the last experimental result, we state that, **experimentally** the function

$$F(t) = \lambda(\frac{t}{C})C^{\frac12}$$

does not depend on C.
You can conclude this from the last plot, by defining $\tau = tC$ so on the x-axis you will have $\log(\tau)$ and on the y-axis $t\rightarrow \frac{\tau}{C}$. Then you can re-name $\tau$ as $t$.

In order to cancel the dependance on C, we must have that
$$\lambda(\frac{t}{C})=f(t)C^{-\frac12}$$
So
$$\lambda(\tau) = f(C*\tau)C^{-\frac12}$$

-------------

You can see that the above statement **makes sense** because:

In the linear regime ($t<<\tau$, so $t<<\frac{1}{C}$) we know that
$$\lambda(t)\simeq 4\pi t^{\frac12}$$
So $$f(C*t)C^{-\frac12}\simeq 4\pi t^{\frac12}$$
when $t << \frac1C  \implies C*t << 1$.

So defining $T = Ct$

$$f(T)\simeq 4\pi T^\frac12\qquad T<<1$$

So you can see that the last expression, and the regime of validity, both do not depend on C.
