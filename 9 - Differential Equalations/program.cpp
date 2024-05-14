#include <iostream>

// y' = f(x,y)
double f(double const x, double const y)
{
    return 6 * x * x + 5 * x * y;
}

int main()
{
    double const h = 0.01; // step size
    double x = 1;          // x_0
    double y = 1;          // y_0
    int n = 10;            // amount of iterations

    // iterating by Euler's method
    for (; n--; y += h * f(x, y), x += h)
        ;

    // printing the result
    std::cout << "x: " << x << "\ty: " << y;

    return 0;
}