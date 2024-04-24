#include <stdio.h>
#include <math.h>

double InterpolateLagrangePolynomial(double x, double *x_values, double *y_values, int size)
{
    double lagrange_pol = 0;
    double basics_pol;

    for (int i = 0; i < size; i++)
    {
        basics_pol = 1;
        for (int j = 0; j < size; j++)
        {
            if (j == i)
                continue;
            basics_pol *= (x - x_values[j]) / (x_values[i] - x_values[j]);
        }
        lagrange_pol += basics_pol * y_values[i];
    }
    return lagrange_pol;
}

double testF(double x)
{
    return x * x * x + 3 * x * x + 3 * x + 1; // for example
}

int main(void)
{
    const int size = 10;
    double x_values[size];
    double y_values[size];

    for (int i = 0; i < size; i++)
    {
        x_values[i] = i;
        y_values[i] = testF(i);
    }

    printf("%lf\n", InterpolateLagrangePolynomial(13.6, x_values, y_values, size));

    return 0;
}