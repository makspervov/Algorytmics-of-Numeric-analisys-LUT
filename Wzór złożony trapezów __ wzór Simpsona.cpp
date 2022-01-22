#include <iostream>
#include <conio.h>

using namespace std;

void Trapezy(int a, int b, int m)
{
    double h;
    double trap;

    cout << "Wybrales wzor zlozony Simpsona. Pamietaj, ze m jest parzystym." << endl;
    cout << "Wprowadz m: ";
    cin >> m;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    h = (b - a) / m;

    for (int i = 0; i <= m; i++)
    {
        trap = h * (0.5*);
    }
}

int main()
{
    int m;

    int calka;
    char wzor; // ustawienia

    cout << "Wybierz calke: " << endl
        << "0. int{0,1} sqrt(1+x) dx;" << endl
        << "1. int{0,2pi} sin^2(x)+2 dx;" << endl
        << "2. int{0,2} e^x - 2x^3 dx." << endl;
    cin >> calka;

    while (calka >= 0 and calka <= 2)
    {
        switch (calka) {
        case 0:
            cout << endl
                << "Wybierz wzor: " << endl
                << "S. Wzor zlozony Simpsona;" << endl
                << "T. Wzor zlozony trapezow." << endl;
            cin >> wzor;

            if (wzor == 'S')
            {
                
                break;

            }
            else if (wzor == 'T')
            {
                break;
            }
            else
            {
                cout << "Nieprawidlowy znak. Sprobuj ponownie";
                break;
            }
            break;
        case 1:
            cout << endl
                << "Wybierz wzor: " << endl
                << "S. Wzor zlozony Simpsona;" << endl
                << "T. Wzor zlozony trapezow." << endl;
            cin >> wzor;

            if (wzor == 'S')
            {

            }
            else if (wzor == 'T')
            {

            }
            break;
        case 2:
            cout << endl
                << "Wybierz wzor: " << endl
                << "S. Wzor zlozony Simpsona;" << endl
                << "T. Wzor zlozony trapezow." << endl;
            cin >> wzor;

            if (wzor == 'S')
            {
                break;
            }
            else if (wzor == 'T')
            {
                break;
            }
            break;
        }
    }
    system("pause");
    return 0;
}
