import numpy as np
import p2
import p4

x0 = 0
h = 0.1
x_end = 1
eps = 10 ** -12
y0 = np.array([1, 1])
count = 0


# A function describing a system of differential equations
def func(x, y):
    return np.array([y[1], np.exp(x)])


# The main function that runs a recursive function with step 'h' and order 'p' = 2
def main():
    rec(h, 4)


# A recursive function for solving a system of differential equations
def rec(h, p):
    global count, check
    match p:
        # Solving a system of differential equations by the 2nd order Runge-Kutta method
        case 2:
            print("\n2nd oerder of Runge-Kutta method")
            print(f'epsilon = {eps}')
            x1, y1 = p2.f(x0, y0, h, func, x_end)
            x2, y2 = p2.f(x0, y0, h / 2, func, x_end)
            print(f'\nh = {h}')
            for i in range(len(x1)):
                # Checking the accuracy of the solution
                check = abs(y1[i][0] - y2[2 * i][0]) > 3 * eps
                print(f'x = {x1[i]:<10.10} | y = {y1[i][0]:<10.10} | y\' = {y1[i][1]:<10.10}')
            # If the accuracy is insufficient, reduce the step and repeat the solution
            if check:
                count = 0
                rec(h / 2, 2)
            # If the accuracy is sufficient, we finish the work
            else:
                count += 1
                if count == len(x1):
                    quit()

        # Solving a system of differential equations by the 4th order Runge-Kutta method
        case 4:
            print("\n4th oerder of Runge-Kutta method")
            print(f'epsilon = {eps}')
            x1, y1 = p4.f(x0, y0, h, func, x_end)
            x2, y2 = p4.f(x0, y0, h / 2, func, x_end)
            print(f'\nh = {h}')
            for i in range(len(x1)):
                check = abs(y1[i][0] - y2[2 * i][0]) > 15 * eps
                #print(f'x = {x1[i]:<11.11} | y = ')
                #print(f"{y1[i][0]:.{12}f}")
                #print(f' | y\' = {y1[i][1]:<11.11}')
                print(f'x = {x1[i]:<10.10} | y = {y1[i][0]:<14.14} | y\' = {y1[i][1]:<14.14}')

            if check:
                count = 0
                rec(h / 2, 4)
            else:
                count += 1
                if count == len(x1):
                    quit()


if __name__ == '__main__':
    main()
