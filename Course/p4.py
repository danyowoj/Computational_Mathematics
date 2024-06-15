import numpy as np


# Definition of the function 'f', which implements the 4th-order Runge-Kutta method
def f(x0, y0, h, func, x_end):
    # Initializing lists to store 'x' and 'y' values
    x = [x0]
    y = [y0]
    i = 0
    # Iterative implementation of the Runge-Kutta method
    while x0 + (i + 1) * h <= x_end:
        # Calculation of coefficients 'k1', 'k2', 'k3', 'k4'
        k1 = func(x[i], y[i])
        k2 = func(x[i] + h / 2, y[i] + h / 2 * k1)
        k3 = func(x[i] + h / 2, y[i] + h / 2 * k2)
        k4 = func(x[i] + h, y[i] + h * k3)

        y_new = y[i] + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4)

        x.append(np.round(x[i] + h, 10))
        y.append(np.round(y_new, 10))
        # Increasing the iteration counter
        i += 1

    return np.round(x, 8), np.round(y, 8)


# Definition of the 'func' function, which describes a system of differential equations
def func(x, y):
    # Calculating values for a system of differential equations and rounding them to 8 decimal places
    return np.round(np.array([y[1], np.exp(x)]), 8)


# Initialization of initial values and parameters
x0 = 0  # initial value of 'x'
y0 = np.array([1, 1])  # initial value of 'y1' and 'y2'
h = 0.1
n = 5
x_end = 1

# Calling the function 'f' with the specified parameters
y = f(x0, y0, h, func, x_end)
