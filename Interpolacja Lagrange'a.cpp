#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    float x[100], y[100], xp, yp = 0, p;
    int i, j, n;

    cout << "Wprowadz liczbe wezlow: ";
    cin >> n;
    cout << "Wprowadz wartosci wezlow" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    cout << "Wpisz punkt: ";
    cin >> xp;

    for (i = 0; i < n; i++)
    {
        p=1;
        for (j = 0; j < n; j++)
            if (i != j) 
                p = p * (xp - x[j]) / (x[i] - x[j]);

        yp = yp + p * y[i];
    }
    cout << endl << "Interpolowana wartosc w(" << xp << ") rowna sie " << yp << endl << endl;
    system("pause");
    return 0;
}
