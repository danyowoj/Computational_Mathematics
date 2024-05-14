#include <iostream>
#include <math.h>

double f(long double x)
{
    x = 1 / x;
    return x;
}

double trapezoidalIntegral(double a, double b, int n)
{
    const double width = (b - a) / n;

    double trapezoidal_integral = 0;
    for (int step = 0; step < n; step++)
    {
        const double x1 = a + step * width;
        const double x2 = a + (step + 1) * width;

        trapezoidal_integral += 0.5 * (x2 - x1) * (f(x1) + f(x2));
    }

    return trapezoidal_integral;
}

double simpsonIntegral(double a, double b, int n)
{
    const double width = (b - a) / n;

    double simpson_integral = 0;
    for (int step = 0; step < n; step++)
    {
        const double x1 = a + step * width;
        const double x2 = a + (step + 1) * width;

        simpson_integral += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f(0.5 * (x1 + x2)) + f(x2));
    }

    return simpson_integral;
}

int main()
{
    std::cout << "Function = 1 / x" << std::endl;
    std::cout << "Limits of integration: a = 1; b = 2" << std::endl;
    std::cout << "Integral (trapqzoidal) = " << trapezoidalIntegral(1, 2, 10000) << std::endl;
    std::cout << "Integral (simpson) = " << simpsonIntegral(1, 2, 10000) << std::endl;

    return 0;
}