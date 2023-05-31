import numpy as np




## the backward or implicits Euler method solves y[k+1] = y[k] + h dy [ t[k+1], y[k+1] ]
## at each step, an iteration scheme must be used like newton root, bisection or fixed point iteration
## here, we used fixed point iteration solving y = g(y) at each step. it is stable when |g(y_true)|<1, which
## for the function y = y0 exp(kt) implies stability when |h k | < 1.



## define the function and test it on exponential
## vectorize it, i.e. make it able to handle coupled diff equations.