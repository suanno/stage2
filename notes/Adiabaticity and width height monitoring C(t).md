# Adiabaticity
If $C=C(t)$ and it is varying slowly respect to the time $\tau$

- Where $\tau$ is the time the system needs, when $C$ is constant (and equal to the value of $C(t)$, so $\tau = \tau_{C(t)}$) to evolve from _any_ (maybe we can require something less strong) state to the stationary state $u_c$

Then we expect $u(x)$ to be, at any time, **following** the stationary state $u_c(x)$

$$u_c(x) = \sqrt{C}\tanh{[(x-\frac{L}{2})\sqrt{\frac{C}{2}}]}$$

That is the stationary state you expect for **constant** C.

## What we expect

If the evolution is adiabatic, we expect that, even if $C=C(t)$, the kink shape (**rescaled**) **is always the same** function

$$y = \tanh(x-L/2)$$

Where the **Rescaling** consists in
- $x\rightarrow x-L/2$, then we multiply by $\sqrt{2/L}$ and finally we readd $x'\rightarrow x'+L/2$    
- $y \rightarrow y/\sqrt{C}$

The rescaling cancels the properies of **height** and **width** of a kink, that can be defined as

- **height**: Double of the (magnitude) of plateaus value
- **width**: Double the distance from the kink site (L/2) to the point x where $y = height/2 * \tanh(1)$


#### BUT the "adiabatic condition"

$$T >> \tau_{C(t)}$$

is not always satisfyied, in particular is not satisfyied when:

- If $C(t)$ is varying close to zero, as when $C$ is constant and close to zero then $\tau$ is big, we expect the system to not evolve adiabatically at times $t$ when $C(t)\simeq 0$. Even if the period $T$ is very big.
- If $T$ is very small.

Considering only the linear part of the TDGL, we find that the characteristic time for the evolution of the system, _with constant_ $C$, is $\tau = \frac1C$.
But
- Neglecting the non-linear term $u^3$ seems to not be possible if $C\sim 1$ and so, at the plateaus, $u\sim 1$.
- I'm not sure that $\frac1C$ is a measure of the time the system takes to move to the stationary state (when $C$ is constant).

## What we see

As always $C(t) = \bar{C} + A\sin(2\pi t/T)$

- Consider $\bar{C} = 1, A = 1$ and $T = 10$
    
    This means that $C(t)$, when $t=\frac34T$, is zero.
    
    Instead, when $t$ is far from $\frac34T$, we have that $C$ is far from zero and, as the period $T>>\tau=\frac1C$, we expect to recover the adiabatic behaviour


    **Experimental behaviour**:
    Here we show the sampled values of height and width at different times, with **oscillating C(t)**. 
    We compare them with the value the system should get if **it evolves adiabatically**, so the one you get putting $C$ constant to a value and waiting **for long enough** (the height and width of the stationary state associated to $C(t)$).


    ![T=10height](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/height.png?raw=true) 
    ![T=10width](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/width.png?raw=true) 
    ![T=10C(t)](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/C(t).png?raw=true) 

    As expected, the deviation from the "adiabatic values" is sensible only when $C(t)$ gets close to zero.

    We can see that the (rescaled) shape of the kink is the same always BUT when $C(t)$ gets close to zero (and so $\tau$ becames very big).

    ![T=10kinkshape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/kinks%20shape.png?raw=true)

    We can see from a **non**-rescaled plot that the state is **still an hyperbolic tangent**, but its width and its height are not the one of the stationary state associated to $C(t)$

    (the Tanh function is plotted just to show visually that the shape of the kink is still a tanh)
    ![T=10nearC=0](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/near%20C=0%20still%20tanh.png?raw=true)

- Consider $\bar{C} = 0, A = 1$ and still $T = 10$
    Now $C(t)$ oscillates around zero, so we do not expect anymore an adiabatic behaviour.

    ![T=10Cave=0shape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/kink%20shape.png?raw=true)

    The shape of the kink is no more the adiabatic one.
    That's because $C(t)$ spends lot of time $T=10$ close to zero. And we expect a decay to zero if $C=0$ const.

    ![T=10Cave=0shape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/height.png?raw=true)


    ![T=10Cave=0shape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/width.png?raw=true)

    From the last two plots is evident that the behaviour is **non-adiabatic** as the width and height **are not periodic** as $C(t)$, so the do not follow it!

    - The height decreases, **as a power law** multiplied by an oscillation(**as expected for a flat** profile when $C(t)$ oscillates **around zero**)

    - The width also increases with time. Here it is shown a state of the system at a long time, to see how the **shape of the full state** changes.

    ![T=10Cave=0longtime](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/t=50.png?raw=true)
    ![T=10Cave=0longtime](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/t=115.png?raw=true)

    ### Is the shape of the kink still tanh after long time?
    We monitored the height and width of the kink, but we do not know if its shape is still tanh.

    This plot suggests so
    ![seemsstilltanh](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/seems%20still%20tanh.png?raw=true)

    But we should **check better** if this is the case.
    Maybe plotting one curve and then tanh with the measured height and width.

    We do that for one of the previous plot at long time (t=115)
    ![t=115tanhoverlap](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/t=115%20tanh%20overlap.png?raw=true)