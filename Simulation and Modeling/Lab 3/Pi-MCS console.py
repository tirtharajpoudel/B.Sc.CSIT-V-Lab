# Estimation of PI using Monte Carlo Simulation in python.

import numpy
import random

no_of_points=[10000,100000,1000000]

for N in no_of_points:
    inside_circle=0
    for i in range(N):
        x=random.uniform(-1,1)
        y=random.uniform(-1,1)

        if (x**2+y**2<=1):
            inside_circle+=1

    approx_pi=4*inside_circle/N

    print("Out of {}, {} points inside the circle.".format(N,numpy.sum(inside_circle)))
    print('Approximated Value : {}  Actual Value : {}\n'.format(approx_pi,numpy.pi))