#include <iostream>
#include <math.h>
#include <cmath>

const double a = 1;
const double b = 2;
const double eps = 1e-8;

typedef double (*pointFunc)(double);

double f(double x)
{
    return (1 / x);
}

double simpson_integral(pointFunc f, double a, double b, int n)
{
    const double h = (b - a) / n;
    double k1 = 0, k2 = 0;

    for (int i = 1; i < n; i += 2)
    {
        k1 += f(a + i * h);
        k2 += f(a + (i + 1) * h);
    }

    return h / 3 * (f(a) + 4 * k1 + 2 * k2);
}

int main()
{
    std::cout << std::fixed;
    std::cout.precision(8);

    int counter = 0;
    double s1, s;
    int n = 1; // the initial number of steps

    s1 = simpson_integral(f, a, b, n); // the first approximation for the integral
    std::cout << "Step " << counter++ << ": \t" << s1 << std::endl;

    do
    {
        s = s1;    // the second approximation
        n = 2 * n; // doubling the number of steps,
                   // that is, reducing the step value by half
        s1 = simpson_integral(f, a, b, n);
        std::cout << "Step " << counter++ << ": \t" << s1 << std::endl;
    } while (fabs(s1 - s) > eps); // comparison of approximations with a given accuracy

    std::cout << "\nAnswer is " << s1 << std::endl;
}