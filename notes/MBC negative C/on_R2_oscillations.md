## What we simulate
The initial state is an isolated circular domain, defined as
$$u(r,t=0) = \tanh((r-R_0)\sqrt{\frac12})$$
where $r$ is the radial coordinate: $r^2=x^2+y^2$.

If $C$ is constant, we expect motion by curvature, so
$$R^2(t)-R_0^2 = -2t$$

But in the following simulations, we use
$$C(t)=1+1.5\sin(2\pi t/T);\quad T=100$$
So the average value $\bar{C}>0$, but sometimes $C(t)<0$.
And $T$ is large compared to the intrinsic timescale $\tau \sim \frac{1}{\bar{C}} = 1$.
So we are in the _slow varying limit_.

## How the radius $R(t)$ is measured
An estimate of $R^2(t)$ is obtained by calculating
$$R^2_{\text{estimate}} = \frac{\int r^2|\nabla u|^2 dxdy}{\int |\nabla u|^2 dxdy}$$
that is the average of $r^2$ weighted on $|\nabla u|^2$, that is a function expected to be peaked at the interfaces between domains; in this case at the border of the island.

## $R(t)$ is APPARENTLY bigger [triangular shaped oscillations]
In the following **animation**, the measured value of $R(t)$ is represented along with other quantitities.
- **top left**: A **slice** of the state: u(x,y=L/2)
- **bottom left**: a slice of $|\nabla u|^2|_{y=L/2}$
- **top right**: $R^2(t)-R_0^2$
- **bottom right**: $C(t)$ 

While the **black stars** show the estimated position of the interface, using the estimated value of $R(t)$ as
$$x_{\pm} = L/2 \pm R$$
![L=128](varyL/L=128.gif?raw=true)


From the **bottom-left** plot you can see that the estimated value for $R(t)$ produces an estimate for the position of the interface that is **BIGGER** than the peak position. This happens when $C<0$.

If the positions of the peaks of $|\nabla u|^2$ represent the positions of the interface, then **the way we estimate $R(t)$ gives an estimation that is BIGGER than the TRUE value**, when $C<0$.

## Asymmetry of $|\nabla u|^2$ (is it due to overlap of the peaks?)
The slice of $|\nabla u(x,y)|^2|_{y=L/2}$ is obtained evaluating the function $|\nabla u(x,y)|^2$ along the line $y=L/2$, that passes from the center of the island.
As there seems to be a radial simmery $u=u(r)$, then the plots on the left represent $u(r)$ and $(\partial_r u)^2$.

When $C<0$ and our estimate of $R(t)$ is bigger than the real value, you can see that the peaks of $(\partial_r u)^2$ are **asymmetric** respect to the maximum.
This leads to the estimate of the radius to not coincide with the peak position.
### Is the asymmetry due to an overlap between the peaks?
As we're solving the TDGL equation with periodic boundary conditions,
there are two ways the peaks can overlap; when the peaks are
- close to the **center** of the simulation box;
- cose to the **borders** of the simulation box.

In the simulation we showed above, the peaks look close to the borders at the beginning and close to the center after.
So we ran a simulation of a **larger system** (of size $L=256$ instead of $L=128$) and we chose the initial radius, such that the interface is in the **middle point** between the center and the borders: $R_0=64$.

![L=256](varyL/L=256.gif?raw=true)
In the last simulation there seem to be no overlap between the peaks, although the peaks are still asymmetric.
Additionally, the amplitude of the peaks is the same as in the smaller system, enhancing the fact that **the peak's asymmetry is not due to an overlap of the peaks**.

![comparison_peak_amplitude](varyL/comparison.png?raw=true)

## What if $C<0$ constant?
In the following simulation we kept $C=-0.5$ constant, where $0.5$ is the minimum value that $C$ takes in the previous simulations.
![C=-0.5](varyL/C=-0.5.gif?raw=true)