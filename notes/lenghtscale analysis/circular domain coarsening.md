In the asymptotic regime, the dyamics is governed by MBC.
If we make the scaling hypotesis (only one lenghtscale $L$), a dimensional analysis tells that
$$L\sim t^{\frac12}$$

## Random initial conditions
Here we see experimentally that
$$\lambda_{DW} \propto (\int dxdy |\nabla u|^2)\sim L^{\frac12})^{-1}$$

And this quantity is related to the **total lenght of interfaces** that, if $C$ is constant, is
$$\mathcal{L} = L^2/\lambda_{DW}$$
so $\mathcal L\sim t^{-\frac12}$ (with a minus sign, so it decreases! As we expect because at very long times there are no domains and so no interfaces!)

## Circular domain initial conditions
From MBC it follows that
$$R^2(t) = R(0)^2 - 2t$$

So we're tempted to state
$$R(t) \sim t^{\frac12}$$
BUT we have to be carefull, as $R(0)^2 - 2t > 0$, otherwise the domain does not exist! So there isn't a timespan where $2t >> R(0)^2$ and so it is **not correct** to state $$R(t) \sim t^{\frac12}$$
where the positive power correspond to a decrease, because there is a minus sign (-2t).

Then if we consider the _total domains lenght_ $\mathcal L = 2\pi R$, we're tempted to state (even if the expression above is not correct) that $\mathcal L \sim t^{\frac12}$, instead of $t^{-\frac12}$ like we see when the initial conditions are random.


For a **CIRCULAR DOMAIN** under C = 1 (L=128, R0=50)

![circularGrad2](../lenghtscale%20analysis/grad2/R0=50_C=1/nopowerlaw.png?raw=true)