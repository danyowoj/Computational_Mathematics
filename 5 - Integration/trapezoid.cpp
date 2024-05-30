#include <iostream>
#include <math.h>

double trapezoid(double (*f)(double), double a, double b, double eps)
{
    int counter = 0;
    double old_i = 0, new_i = old_i + 2 * eps;

    for (unsigned int n = 1; abs(new_i - old_i) > eps; n *= 2)
    {
        std::cout << "Step " << counter++ << ": \t" << new_i << std::endl;

        old_i = new_i;
        double h = (b - a) / n;
        double s = -(f(a) + f(b)) / 2;

        for (int i = 0; i <= n; ++i)
            s += f(a + i * h);

        new_i = s * h;
    }

    return new_i;
}

double y(double x)
{
    return 1 / x;
}

int main(int argc, char *argv[])
{
    std::cout << std::fixed;
    std::cout.precision(8);

    std::cout << trapezoid(y, 1, 2, 1e-8) << " is the answer." << std::endl;
}