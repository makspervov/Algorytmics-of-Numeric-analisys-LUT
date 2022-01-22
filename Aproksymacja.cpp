#include <iostream>
#include <math.h>
using namespace std;
int i, k;
long double a, b, x1, x2, x3, x4, x5, x6, c, d;
int main()
{
    int n;
    cout << "Podaj ilosc wezlow: ";
    cin >> n;
    long double t[2][n];
    cout << "Wybierz funkcje:\n1. g(x)=ax+b\n2. g(x)=a/x+b\n3. g(x)=b*a^x\n";
    cin >> k;
    if (k == 1)
    {
        cout << "Podaj xi i yi:\n";
        for (i = 0; i < n; i++)
            cin >> t[0][i] >> t[1][i];
        x1 = n;
        for (i = 0; i < n; i++)
        {
            x2 += t[0][i];
            x3 += t[1][i];
            x4 += t[0][i];
            x5 += pow(t[0][i], 2);
            x6 += t[0][i] * t[1][i];
        }
        b = (x3 * x5 - x2 * x6) / (x1 * x5 - x2 * x4);
        a = (x1 * x6 - x3 * x4) / (x1 * x5 - x2 * x4);
        if (b < 0)
            cout << "g(x)=" << a << "x" << b;
        else
            cout << "g(x)=" << a << "x+" << b;
    }
    else if (k == 2)
    {
        cout << "Podaj licznik i mianownik xi i yi:\n";
        for (i = 0; i < n; i++)
        {
            cin >> c >> d >> t[1][i];
            t[0][i] = c / d;
        }
        x1 = n;
        for (i = 0; i < n; i++)
        {
            x2 += 1 / t[0][i];
            x3 += t[1][i];
            x4 += 1 / t[0][i];
            x5 += pow((1 / t[0][i]), 2);
            x6 += (1 / t[0][i]) * t[1][i];
        }
        b = (x3 * x5 - x2 * x6) / (x1 * x5 - x2 * x4);
        a = (x1 * x6 - x3 * x4) / (x1 * x5 - x2 * x4);
        if (b < 0)
            cout << "g(x)=" << a << "/x" << b;
        else
            cout << "g(x)=" << a << "/x+" << b;
    }
    else if (k == 3)
    {
        cout << "Podaj xi i wykladnik potegi yi:\n";
        for (i = 0; i < n; i++)
            cin >> t[0][i] >> t[1][i];
        x1 = n;
        for (i = 0; i < n; i++)
        {
            x2 += t[0][i];
            x3 += t[1][i];
            x4 += t[0][i];
            x5 += pow(t[0][i], 2);
            x6 += t[0][i] * t[1][i];
        }
        b = (x3 * x5 - x2 * x6) / (x1 * x5 - x2 * x4);
        a = (x1 * x6 - x3 * x4) / (x1 * x5 - x2 * x4);
        cout << "g(x)=e^" << b << "*e^" << a << "x";
    }
    else
        cout << "Bledna wartosc";
    return 0;
}