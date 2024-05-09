#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <math.h>

const int n = 3;

void AitkenInterpolation(double x[], double y[], double xi)
{
    int k = n + 1;
    double P[n + 1][n + 1];

    for (int i = 0; i < k; ++i)
    {
        P[i][0] = y[i];
    }

    for (int j = 1; j < k; ++j)
    {
        for (int i = 0; i < k - j; ++i)
        {
            P[i][j] = (P[i][j - 1] * (xi - x[i + j]) - P[i + 1][j - 1] * (xi - x[i])) / (x[i] - x[i + j]);
            std::cout << "| Px" << i << "x" << j << " = " << P[i][j] << " | ";
        }
        std::cout << std::endl;
    }
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

    std::cout << "Interpolation by Aitken:" << std::endl;
    AitkenInterpolation(x, y, 2.5);

    return 0;
}