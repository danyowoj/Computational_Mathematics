#include <math.h>
#include <iostream>
#define M_E 2.71828182845904523536

using namespace std;

double f(double x)
{
    return -(x * x * x) + 9 * (x * x) - 24 * x - 2;
} // Здесь ваша формула

//---------------------------------------------------------------------------
double ab(double i)
{
    if (i < 0)
        return -i;
    else
        return i;
} // это модуль

//---------------------------------------------------------------------------

int main()
{
    double a, b, g, h, fu1, fu2, eps = 0.000001;

    for (int i = -1; i <= 1; i += 2) // Сначало ищем минимум, затем максимум
    {

        a = -5;
        b = 3;

        g = a + (b - a) * (0.38);
        h = b - 0.38 * (b - a);
        fu1 = i * f(g);
        fu2 = i * f(h);

        do
        {

            if (fu1 <= fu2)
            {
                b = h;
                h = g;
                fu2 = fu1;
                g = a + (b - a) * (0.38); // Основная формула
                fu1 = i * f(g);
            }
            else
            {
                a = g;
                g = h;
                fu1 = fu2;
                h = b - 0.38 * (b - a); // Основная формула
                fu2 = i * f(h);
            }
        } while (ab(a - b) > eps); // Условие выхода
        i == -1 ? cout << "Maximum " : cout << "Minimum ";
        cout << "= " << (fu1 - fu2) / 2 + fu2 << "; x = " << h << endl;
    }

    return 0;
}