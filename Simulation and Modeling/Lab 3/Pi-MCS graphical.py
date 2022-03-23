# Estimation of PI using Monte Carlo Simulation in python.

import numpy
import matplotlib.pyplot as plt

no_of_points=[10000,100000,1000000]

for N in no_of_points:

    x=numpy.random.uniform(low=-1,high=1, size=[N,1])
    y=numpy.random.uniform(low=-1,high=1, size=[N,1])

    inside_circle = x**2+y**2<1

    print("Out of {}, {} points inside the circle.".format(N,numpy.sum(inside_circle)))

    approx_pi=4*numpy.sum(inside_circle)/N
    print('Approximated Value : {}  Actual Value : {}\n'.format(approx_pi,numpy.pi))

    x_in=x[inside_circle]
    y_in=y[inside_circle]

    plt.figure(figsize=[4,4])
    plt.scatter(x,y,s=1)
    plt.scatter(x_in,y_in,color='r',s=1)
    plt.show()
    plt.close()