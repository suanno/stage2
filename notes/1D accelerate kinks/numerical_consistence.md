# Is the acceleration of the kinks' annhilation JUST a NUMERICAL effect?

To check this, we ran simulations with different values of $dt$ and $dx$ to see if there is any difference.

## Changing $dx$
Two kinks at an initial distance $d_0=20$ (see [here](changing_T.md) for details on initialization)
$$L=128; dt=0.1$$
$$C(t)=\bar{C}+A\sin(2\pi t/T)$$

Despite on short time-scales, comparable to the period $T$, the curve look different (see the [last paragraph of this file](#short-time-scale)); on a large scale there is a good match.

![](d0=20/numerical_consistence/dt=0.1_L=128_vary_dx.png?raw=true)


## Changing $dt$
$$L=128; dx=0.1$$
$$C(t)=\bar{C}+A\sin(2\pi t/T)$$

![](d0=20/numerical_consistence/dx=0.1_L=128_vary_dt.png?raw=true)

### Short time-scale
Here I show _the beginning_ (the first 1000 seconds) of two identical simulation, except the space discretization $dx$ is different.

You can tell there is a difference in how the distance decreases, but we saw that if you look at the data on a large time-scale, there is not much difference.

$$C(t)=0.5+1\sin(2\pi t/40)$$

$dx=0.1$
![](d0=20/numerical_consistence/dx=0.1movie.gif?raw=true)
$dx=0.05$
![](d0=20/numerical_consistence/dx=0.05movie.gif?raw=true)