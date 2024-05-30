### What is it?
It is a second order scheme to solve differential equations.
It is defined as an average betwee explicit and the implicit Euler schemes, so it is semi-implicit.

### Why we use it?
Before starting my internship, there was already a code that used the implicit euler scheme to solve the time-dependent Ginzburg-Landau equation.
And what I discovered is that the implicit Euler scheme fails in simulating the evolution of a flat profile; in the sense that the numerical solution deviates exponentially fast from the analytical solution.
[More precisely, we considered the linearized equation, that is simpler. Then we considered C to oscillate around zero and the analytical solution also oscillates around zero. But the numerical one, oscillates around a value that is not fixed, but grows exponentially fast]