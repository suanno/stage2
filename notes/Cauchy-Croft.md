# Extimating the (total) interfaces' lenght $\mathcal{L}$ with the Cauchy-Croft theorem

It is possible to extimate the lenght of a curve in the plane by taking a set of equispaced $dx$ parallel lines and counting how many times $n$ the line crosses those lines. Then an extimate for the lenght of the line will be
$$\mathcal{L} \simeq \frac12 n dx \frac{\pi}{4}$$
So you can get a better estimate by choosing multiple sets of parallel lines and averaging their respective extimates.

In our case, the field $u(x,y)$ is defined on the sites of a discrete (square) lattice and the interfaces are the lines along which $u=0$.
So we can take as sets of parallel lines the horizontal and vertical lines of the lattice.
Then, it is sufficient to follow each of these lines and count the number of times the sign of $u$ changing moving across the line.

We can also take a set of oblique lines, of angle $\pi/4$. In this case, the line still pass through the lattice points, but their distance is $dx\rightarrow \sqrt{2}dx$.

## Characteristic lenght $\ell_{C-C}$
We can define a characteristic lenght of the system starting from the extimate of the (total) interfaces' lenght $\mathcal{L}$ obtained with the C-C theorem.

$$\ell_{C-C} \equiv L^2/\mathcal{L}$$

## Examples
- $C(t) = 0.5+A\sin(2\pi t/T); T = 20$

![](./2D%20phase%20transition/ellC-C/vary%20A/Cbar=0.5.png?raw=true)

- $C(t) = 0 + A\sin(2\pi t/T); A = 1; T = 20$

![](./Cbar=0/ellC-C/stepwise.png?raw=true)