Here, instead of starting with a state prepared with Costant C (tanh)
We started with the NDSolve numerical solution for u_k ODE with 
derivative at x = 0: v = 1.321043(5)	(last digit is not sure)

**Notice** that this value of the velocity is slighly higher than the
critical one (the one for which u_k goes exactly to 0). So the initial state has, for some values of x, u_k(x)>1.
So there are problems taking the log (1-u_k), so the curve with t=0 is not present in the plot.

