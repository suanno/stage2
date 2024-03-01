# Height and width monitoring with oscillating $C(t)$

For **definitions** of width and height find the notes on "Adiabaticity".

During the simulations

$$C(t) = \bar{C} + A\sin(2\pi t/T)$$

And the **initial state** is prepared as $u_{C=1}(x)$ [is the _2 kinks_ stationary state for $C=1$ constant] in this way:

### Initial state preparation

You keep $C=1$ constant for a (long) time $t_{initial}$ that is a **multiple of the period $T$**; only then $C(t)$ becomes the oscillating function.

This is an example for $T=10$ where we let the system evolve for $t=20$ with $C=1$ const.
![initialstate](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/initial_state.png?raw=true)

We choose $t_{initial}$ as a multiple of the period $T$ so then, after the preparation, $C(t-t_{initial}) = C(t)$ [the sine starts from 0 after $t_{initial}$].

**Remember**: That in your plots you have to **subtract** $t_{initial}$ to the times $t$ of the saves.

# Monitoring

### Consider $\bar{C} = 1, A = 1$ and $T = 10$
    
This means that $C(t)$, when $t=\frac34T$, is zero.
    
Instead, when $t$ is far from $\frac34T$, we have that $C$ is far from zero and, as the period $T>>\tau=\frac1C$, we expect to recover the adiabatic behaviour


**Experimental behaviour**:

Here we show the sampled values of height and width at different times, with **oscillating C(t)**. 
We compare them with the value the system should get if **it evolves adiabatically**, so the one you get putting $C$ constant to a value and waiting **for long enough** (the height and width of the stationary state associated to $C(t)$).

- **Height** monitoring
![T=10height](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/height.png?raw=true) 

We can compare the plot with the oscillation of a flat profile with the same $C(t)$.
Where the flat profile is prepared with $u_0$ equal to (half) the initial height.

![T=10flat_profile](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/flat_profile.png?raw=true) 

- **Width** monitoring

![T=10width](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/width.png?raw=true) 

We show a plot of $C(t)$
![T=10C(t)](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/C(t).png?raw=true) 

We see a deviation from the adiabatic behaviour **as soon as** $C(t)$ approaches zero **for the first time**.
Then the observed behaviour seems to be _dephased_ from the adiabatic one.
It's like as if the system cannot follow anymore $C(t)$ when it approaches zero and so **it is left behind**.

We can see that the (**rescaled**) shape of the kink is the same always BUT when $C(t)$ gets close to zero (and so $\tau$ becames very big).

![T=10kinkshape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/kinks%20shape.png?raw=true)

We can see from a **non**-rescaled plot that the state is **still an hyperbolic tangent**, but its width and its height are not the one of the stationary state associated to $C(t)$

(the Tanh function is plotted just to show visually that the shape of the kink is still a tanh)
![T=10nearC=0](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%201/near%20C=0%20still%20tanh.png?raw=true)

### Consider $\bar{C} = 0, A = 1$ and still $T = 10$
Now $C(t)$ oscillates around zero, so we do not expect anymore an adiabatic behaviour.

![T=10Cave=0shape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/kink%20shape.png?raw=true)

The shape of the kink is no more the adiabatic one.
That's because $C(t)$ spends lot of time $T=10$ close to zero. And we expect a decay to zero if $C=0$ const.

- **Height** monitoring
        
    ![T=10Cave=0shape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/height.png?raw=true)

    Let's compare with the plot of (two times) the flat value when we evolve a **flat profile** where
    - $u_0$ (initial value of the flat) is (half) the initial height
    - C(t) varying in the same way

    ![flatprofilecomparison](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/flat%20profile%20height.png?raw=true)

- **Width** monitoring
    ![T=10Cave=0shape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/width.png?raw=true)
    ![T=10Cave=0shape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/width%20linear%20scale.png?raw=true)
    ![T=10Cave=0shape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/width%20loglog.png?raw=true)
    ![T=10Cave=0shape](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/width%20semilogy.png?raw=true)

    From the height and width plots is evident that the behaviour is **non-adiabatic** as the width and height **are not periodic** as $C(t)$, so the do not follow it!

    The width also increases with time. Here it is shown a state of the system at a long time, to see how the **shape of the full state** changes.

    ![T=10Cave=0longtime](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/t=50.png?raw=true)
    ![T=10Cave=0longtime](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/t=115.png?raw=true)



## Is the shape of the kink still tanh after long time?
We monitored the height and width of the kink, but we do not know if its shape is still tanh.

This plot suggests so
![seemsstilltanh](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/seems%20still%20tanh.png?raw=true)

But we should **check better** if this is the case.
    Maybe plotting one curve and then tanh with the measured height and width.
    
We do that for one of the previous plot at long time (t=115)
    ![t=115tanhoverlap](../Plots/kink%20shape%20varying%20C/rescaled/T%20=%2010%20C%20near%200/t=115%20tanh%20overlap.png?raw=true)