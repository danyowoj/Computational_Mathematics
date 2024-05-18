#include <iostream>
#include <math.h>
#include <conio.h>

const double answer = 0.69314718;
const double eps = pow(10, -8);

double f(long double x)
{
    x = 1 / x;
    return x;
}

double trapezoidalIntegral(double a, double b, int n)
{
    const double width = (b - a) / n;

    double trapezoidal_integral = 0;
    int step = 0;

    do
    {
        const double x1 = a + step * width;
        const double x2 = a + (step + 1) * width;

        trapezoidal_integral += 0.5 * (x2 - x1) * (f(x1) + f(x2));

        std::cout << trapezoidal_integral << std::endl;
        system("pause");

        step++;
    } while (answer - trapezoidal_integral > eps);

    return trapezoidal_integral;
}

double simpsonIntegral(double a, double b, int n)
{
    const double width = (b - a) / n;

    double simpson_integral = 0;

    int step = 0;
    do
    {
        const double x1 = a + step * width;
        const double x2 = a + (step + 1) * width;

        simpson_integral += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f(0.5 * (x1 + x2)) + f(x2));

        std::cout << simpson_integral << std::endl;
        system("pause");

        step++;
    } while (answer - simpson_integral > eps);

    return simpson_integral;
}

int main()
{
    std::cout << std::fixed;
    std::cout.precision(8);

    std::cout << "Function = 1 / x" << std::endl;
    std::cout << "Limits of integration: a = 1; b = 2" << std::endl;
    std::cout << "Integral (trapezoidal): " << trapezoidalIntegral(1, 2, 10) << std::endl;
    // std::cout << "Integral (simpson): " << simpsonIntegral(1, 2, 10) << std::endl;

    return 0;
}