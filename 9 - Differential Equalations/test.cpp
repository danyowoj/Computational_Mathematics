#include <iostream>
#include <math.h>

double fun(double x, double y)
{
    return 6 * x * x + 5 * x * y;
}

int main()
{
    double x0, y0, xn, h;
    int i, n;

    x0 = 1;
    y0 = 1;
    xn = 1.1;
    n = 10;

    double *x = new double[n + 1];
    double *y = new double[n + 1];
    h = (xn - x0) / n;

    std::cout << "\n---Counting x[i]---" << std::endl;
    for (i = 0; i <= n; i++)
    {
        x[i] = x0 + i * h;
        std::cout << i << "\t" << x[i] << std::endl;
    }

    std::cout << "\n---Counting y[i]---" << std::endl;
    y[0] = y0;
    for (i = 1; i <= n; i++)
    {
        y[i] = y[i - 1] + h * fun(x[i - 1], y[i - 1]);
        std::cout << i << "\t" << y[i] << std::endl;
    }

    std::cout << "\n------Answer------" << std::endl;
    std::cout << "x0 = " << x0 << ";\txn = " << xn << std::endl;
    std::cout << "y = " << y[n] << std::endl;
    std::cout << "steps made: " << n << std::endl;
    std::cout << "step size: " << h << std::endl;

    delete[] x;
    delete[] y;

    return 0;
}