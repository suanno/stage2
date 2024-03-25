# Measure deviation form stationary state $\delta u = u - u_0$

Let's consider the quantity
$$\delta u = u - u_0 = \epsilon\beta_1u_{k_1}(\alpha x) + O(\epsilon^2)$$

we **can measure** this quantity, because we know that
$$u_0 = \sqrt{C}\tanh(\sqrt{C/2}x)$$

# Verifying analytical behaviour of $\beta_1$

We want to verify the expected behaviour
$$\beta_1(t) = \frac12\partial_{\tau}C C^{-\frac32}$$

We see from the experiments that $\delta u$ reaches a plateau when $x >> 0$.
And also from the numerical solution of the ODE for $u_{k_1}$ we see a plateau.

So, if $x>>0$ we have

$$\tilde{\delta u} \simeq \epsilon\beta_1(t)\tilde{u_{k_1}}$$

where we can measure both the plateau value, by evaluating $\delta u$ at $x>>0$ and by looking at the ODE for $u_{k_1}$ in the $x>>0$ limit

$$0 = \tilde{u_{k_1}}(1-3)$$
$$\tilde{u_{k_1}} = -\frac12$$
where we've used that $u_{k_0}\rightarrow 1$ faster than $\chi$.

So we can extimate $\epsilon\beta_1$, by measuring the plateau value of the deviation $\tilde{\delta u}$ as

$$\epsilon\beta_1 \simeq - 2\tilde{\delta u}$$

## The experiment

Code for data analysis: "plot/second analytical approach/distance from stationary state.ipynb"

We choose $C(t)$ to change in time as a sine, so it is easy to recognize the timescale of its variation

$$C(t) = \bar{C} + A\sin(2\pi t/T)$$

So the small parameter in this case is $$\epsilon = 2\pi/T$$

Now we know the analytical expression for $\beta_1$

$$\beta_1(\tau) = \frac12C^{-\frac32}\partial_{\tau}C$$

So we have the expected analytical expression of $\epsilon\beta_1(t)$ **and we can measure it** as 
$$\epsilon\beta_1 \simeq - 2\tilde{\delta u}$$

<!--
    ![deviationT=100](Plots/T=100%20Cave=1%20A=0.2/deltau.png?raw=true)

     [In the first plot we checked if there is any difference in the evolution of the system if we start with a state prepared by keeping $C$ constant for a long time or by defining it as the stationary state for contant $C$ (in the second case the initial state does not satisfy PBC, this is the main reason of this check)]
-->

### Monitoring $\delta u$ in the first period (from the state's preparation)
Here we study the dynamics in the first period after the preparation of the state.
As not much time is passed from the beginning, the dynamics in this region of time can show features that **depend on how the initial state was prepared**.
So we can see a **transient** behaviour that is different from the **permanent** behaviour you see at long times.

**SEE BELOW** for long time behaviour.

#### Experiment 1: $C\in (1\pm0.2), \epsilon = 0.06$

File: "/.saves/T=100 A=0.2 Cave=1 from tanh"


![beta1extT=100](Plots/T=100%20Cave=1%20A=0.2/beta1_extimation_analytical.png?raw=true)


Then we can use the analytical expression for $\epsilon\beta_1(t)$ and $\alpha = \sqrt{C}$ to extimate $u_{k_1(\chi)}$ from $\delta u$ as

$$\delta u \simeq \epsilon\beta_1(t)u_{k_1}(\alpha x)$$

![uk1T=100](Plots/T=100%20Cave=1%20A=0.2/uk1.png?raw=true)


#### Experiment 2: $C\in (0.3\pm0.2), \epsilon = 0.06$

File: "/.saves/T=100 A=0.2 Cave=0.3 from tanh"

![uk1T=100Cave=0.3](Plots/T=100%20Cave=0.3%20A=0.2/uk1.png?raw=true)
![beta1extT=100Cave=0.3](Plots/T=100%20Cave=0.3%20A=0.2/beta1_extimation_plateau.png?raw=true)
    

    
  
#### Experiment 3: $C\in (1\pm0.2), \epsilon = 0.6$

File: "/.saves/T=10 A=0.2 Cave=1 from tanh"

![uk1=10Cave=1](Plots/T=10%20Cave=1%20A=0.2/uk1.png?raw=true)

![beta1extT=10Cave=1](Plots/T=10%20Cave=1%20A=0.2/beta1_extimation_plateau.png?raw=true)

We see that the experimental data does not return to the same value after a period.
That's because we are looking at the dynamics in the first period, so we are seeing a **transient** dynamics.
If we wait enough we have periodicity in the experimental data, as you can see below.



### Monitoring $\delta u$ at long times (after 3 periods form state's preparation)


If you wait some time, so the idea is that "**you loose memory** about the initial state preparation".

#### Experiment 1: $C\in (1\pm0.2), \epsilon = 0.06$
File: "/.saves/T=100 A=0.2 Cave=1 from tanh aftersomeperiods"


![uk1T=100after](Plots/T=100%20Cave=1%20A=0.2/aftersomeperiods/uk1.png?raw=true)

![beta1extT=100after](Plots/T=100%20Cave=1%20A=0.2/aftersomeperiods/beta1_extimations.png?raw=true)

#### Experiment 2: $C\in (0.3\pm0.2), \epsilon = 0.06$

File: "/.saves/T=100 A=0.2 Cave=0.3 from tanh aftersomeperiods"

![uk1T=100Cave=0.3](Plots/T=100%20Cave=0.3%20A=0.2/aftersomeperiods/uk1.png?raw=true)
![beta1extT=100Cave=0.3](Plots/T=100%20Cave=0.3%20A=0.2/aftersomeperiods/beta1_extimations.png?raw=true)

#### Experiment 3: $C\in (1\pm0.2), \epsilon = 0.6$

File: "/.saves/T=10 A=0.2 Cave=1 from tanh aftersomeperiods"

![uk1T=10Cave=1after](Plots/T=10%20Cave=1%20A=0.2/aftersomeperiods/uk1.png?raw=true)
![beta1extT=10Cave=1after](Plots/T=10%20Cave=1%20A=0.2/aftersomeperiods/beta1_extimations.png?raw=true)

Now, looking at the dynamics after a long time from the state's preparation, you can see that the experimental data returns to the same value after a period of $C(t)$.