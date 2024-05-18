#include <math.h>
#include <iostream>

// our function
double f(double x)
{
    return x * x - 6 * x;
}

int main()
{
    double a, b, g, h, fu1, fu2, eps = 0.00000001;

    // at first we search for Min, then for Max
    for (int i = -1; i <= 1; i += 2)
    {

        a = -100;
        b = 100;

        g = a + (b - a) * (0.381966);
        h = b - 0.381966 * (b - a);
        fu1 = i * f(g);
        fu2 = i * f(h);

        do
        {

            if (fu1 <= fu2)
            {
                // main formula
                b = h;
                h = g;
                fu2 = fu1;
                g = a + (b - a) * (0.381966);
                fu1 = i * f(g);
            }
            else
            {
                // main formula
                a = g;
                g = h;
                fu1 = fu2;
                h = b - 0.381966 * (b - a);
                fu2 = i * f(h);
            }
        } while (fabs(a - b) > eps); // exit condition

        i == -1 ? std::cout << "Max: " : std::cout << "Min: ";
        std::cout << "F(x) = " << (fu1 - fu2) / 2 + fu2 << "; \tx = " << h << std::endl;
    }

    return 0;
}