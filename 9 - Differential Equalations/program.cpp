#include <iostream>
#include <math.h>

#define n 100

// y' = f(x,y)

// f(x,y)
float f(float x, float y)
{
    return y / x - log(x) / x;
}

//  analytical solution
float ya(float x)
{
    return log(x) + 1;
}

int main()
{
    float a, b, h, x, y[n];
    int k;

    a = 1;
    b = 2;
    h = (b - a) / (n - 1);

    // initial condition
    y[0] = 1;

    // Euler's method
    for (k = 1; k < n; k++)
    {
        x = a + k * h;
        y[k] = y[k - 1] + h * f(x, y[k - 1]);
    }

    // comparison with the analytical solution
    for (k = 0; k < n; k++)
    {
        x = a + k * h;
        std::cout << "X = " << x << "\tNumerical: " << y[k] << "\tAnalytical: " << ya(x) << std::endl;
    }

    return 0;
}