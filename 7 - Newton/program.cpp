#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <math.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void calculateDifferenceTable(double y[], double delta[][5], int n)
{

    for (int i = 0; i < n; ++i)
    {
        delta[i][0] = y[i];
    }

    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < n - j; ++i)
        {
            delta[i][j] = delta[i + 1][j - 1] - delta[i][j - 1];
        }
    }
}

double NewtonInterpolation_1(double x[], double y[], double delta[][5], int n, double xi)
{

    double result = y[0];
    double temp;
    double q = (xi - x[0]) / 1;
    double koef;

    for (int i = 1; i <= n; ++i)
    {
        koef = q;
        temp = delta[0][i] / factorial(i);
        for (int j = 1; j < i; ++j)
            koef *= q - j;
        result += (temp * koef);
    }

    return result;
}

double NewtonInterpolation_2(double x[], double y[], double delta[][5], int n, double xi, int h)
{

    double result = y[n];
    double temp;
    double q = (xi - x[n]) / h;
    double koef;

    for (int i = 1; i <= n; ++i)
    {
        koef = q;
        temp = delta[n - i][i] / factorial(i);
        for (int j = 1; j < i; ++j)
            koef *= q + j;
        result += (temp * koef);
    }

    return result;
}

int main()
{

    const int N = 5;
    double x[N] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[N] = {1.0, 0.5, 0.3333, 0.25, 0.2};
    double delta[N][5] = {0};

    std::cout << std::fixed;
    std::cout.precision(4);

    int n = 3;
    calculateDifferenceTable(y, delta, N);

    std::cout << std::endl
              << "Unequal nodes (method 1):" << std::endl;
    double N1 = NewtonInterpolation_1(x, y, delta, n, 2.56);
    std::cout << "f(2.56) = " << N1 << std::endl;
    std::cout << std::endl
              << "Equal nodes (method 2):" << std::endl;
    double N2 = NewtonInterpolation_2(x, y, delta, n, 2.5, 1);
    std::cout << "f(2.5) = " << N2 << std::endl;

    return 0;
}