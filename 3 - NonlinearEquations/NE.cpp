#include <iostream>
#include <cmath>

const double epsilon = 1e-10;

// the calculated function
double f(double x)
{
    return x * x - 3;
}

// the derivative of the function
double df(double x)
{
    return 2 * x;
}

void HalfDevision(double a, double b)
{
    double c;
    int counter = 0;

    while (b - a > epsilon)
    {
        counter++;
        c = (a + b) / 2;

        if (f(b) * f(c) < 0)
            a = c;
        else
            b = c;
    }

    std::cout << "x = " << (a + b) / 2 << std::endl;
    std::cout << "Steps: " << counter << std::endl;
}

void Chord(double a, double b)
{
    int counter = 0;
    while (fabs(b - a) > epsilon)
    {
        counter++;
        a = a - (b - a) * f(a) / (f(b) - f(a));
        b = b - (a - b) * f(b) / (f(a) - f(b));
    }
    // a, b — (i - 1)-й и i-й члены

    std::cout << "x = " << b << std::endl;
    std::cout << "Steps: " << counter << std::endl;
}

void Newton(double x0)
{
    int counter = 0;
    double x1 = x0 - f(x0) / df(x0); // первое приближение
    while (fabs(x1 - x0) > epsilon)
    { // пока не достигнута точность epsilon
        counter++;
        x0 = x1;
        x1 = x0 - f(x0) / df(x0); // последующие приближения
    }
    std::cout << "x = " << x1 << std::endl;
    std::cout << "Steps: " << counter << std::endl;
}

int main()
{
    std::cout << "\nHalf Devision Method:" << std::endl;
    HalfDevision(1, 2);

    std::cout << "\nThe Chord Method:" << std::endl;
    Chord(1, 2);

    std::cout << "\nNewton method:" << std::endl;
    Newton(2);

    return 0;
}