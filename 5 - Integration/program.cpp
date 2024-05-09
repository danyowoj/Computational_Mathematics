#include <iostream>
#include <math.h>
#define e 2.718281
#define epsilon pow(10, -5)
#define Integral 1.02814

long double f(long double x)
{
    x = pow(e, x) / sqrt(1 + pow(e, x));
    return x;
}

long double integral(long double a, long double b)
{
    long double i;
    long double h = 0.0, sint = 0.0;

    h = (b - a) / 10000;
    i = a + h / 2;

    while (i <= b)
    {
        sint += f(i) * h;
        i += h;
        if (fabs(sint - Integral) < epsilon)
            break;
    }

    return sint;
}

int main()
{
    std::cout << "Function = pow(e, x) / sqrt(1 + pow(e, x))" << std::endl;
    std::cout << "Limits of integration: a = 0; b = 1" << std::endl;
    std::cout << "Integral = " << integral(0, 1) << std::endl;

    return 0;
}