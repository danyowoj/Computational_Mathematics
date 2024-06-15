#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;
typedef double (*pointFunc)(double);

double f(double x)
{
    return (1 / x);
}

double simpson_integral(pointFunc f, double start, double end, double initial_h, double E) 
{
    double x1, x2, x3, y1, y2, y3, result, x;
    double h = initial_h, old_result = 0;
    int count = 1, num_steps;
    while (true) 
    {
        num_steps = (end - start) / h;
        result = 0;
        x = start;
        for (int i = 0; i < num_steps; i += 2) 
        {
            x1 = x + i * h;
            x2 = x1 + h;
            x3 = x2 + h;
            if (x3 > end) 
            {
                break;
            }
            y1 = f(x1);
            y2 = f(x2);
            y3 = f(x3);
            result += (x3 - x1) * (1.0 / 6.0 * y1 + 4.0 / 6.0 * y2 + 1.0 / 6.0 * y3);
        }
        cout << "step " << count++ << " h = " << h << setw(14) << "integral = " << result << endl;
        if (abs(result - old_result) < E) 
        {
            break;
        }
        old_result = result;
        h /= 2.0;
    }
    return result;
}

double trapezoid_integral(pointFunc f, double start, double end, double initial_h, double E) 
{
    double y1, y2, result, x;
    double h = initial_h, old_result = 0;
    int count = 1, num_steps;
    while (true) 
    {
        num_steps = (end - start) / h;
        result = 0;
        x = start;
        for (int i = 0; i < num_steps; i++) 
        {
            y1 = f(x);
            y2 = f(x + h);
            result += h * (0.5 * y1 + 0.5 * y2);
            x += h;
            if (abs(result - old_result) < E) 
            {
                break;
            }
        }
        cout << "step " << count++ << " h = " << h << setw(14) << "integral = " << result << endl;
        if (abs(result - old_result) < E) 
        {
            break;
        }
        old_result = result;
        h /= 2.0;
    }
    return result;
}

int main()
{
    double a = 1;
    double b = 2;
    double eps = 1e-8, h = 0.1; 

    cout << fixed;
    cout.precision(8);
    cout << endl << "Result of the Simpson's method:\n" << simpson_integral(f, a, b, h, eps) << endl;
    cout << "_____________________________________________" << endl;
    cout << endl << "Result of the trapezoidal method:\n" << trapezoid_integral(f, 1, 2, h, eps) << endl;

    return 0; 
}