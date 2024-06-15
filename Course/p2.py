import numpy as np


# A function for solving a system of differential equations by the Runge-Kutta method of the 2nd order
def f(x0, y0, h, func, x_end):
    # Initializing lists to store 'x' and 'y' values
    x = [x0]
    y = [y0]
    i = 0

    # A loop running until 'x0 + (i + 1) * h' does not exceed 'x_end'
    while x0 + (i + 1) * h <= x_end:
        # Calculating a new approximation of 'y' based on the previous value of 'y' and the 'func' function
        y_lined = np.round(y[i] + h * func(x[i], y[i]), 12)
        # Calculating a new 'y' value using the midpoint between the previous 'y' and 'y_lined'
        y_new = np.round(y[i] + h / 2 * (func(x[i], y[i]) + func(x[i] + h, y_lined)), 12)

        x.append(np.round(x[i] + h, 12))
        y.append(np.round(y_new, 12))

        # Increasing the iteration counter
        i += 1
    return np.round(x, 8), np.round(y, 8)
