#include <iostream>
#include <math.h>
#define e 2.718281
#define analytical_value 1.02814
#define eps pow(10, -4)

double function(double x)
{
    return pow(e, x) / sqrt(1 + pow(e, x));
}

double RectangleIntegral(double a, double b)
{
    double h, x, f = 0;
    int i = 0, n = 10000;

    x = a;
    h = (b - a) / n;

    while (i <= n)
    {
        x = a + (i - 0.5) * h;
        f += h * function(x);
        i++;

        if ((analytical_value - f) < eps)
            break;
    }

    return f;
}

int main()
{
    std::cout << "Function = pow(e, x) / sqrt(1 + pow(e, x))" << std::endl;
    std::cout << "Limits of integration: a = 0; b = 1" << std::endl;
    std::cout << "Integral = " << RectangleIntegral(0, 1) << std::endl;
    return 0;
}