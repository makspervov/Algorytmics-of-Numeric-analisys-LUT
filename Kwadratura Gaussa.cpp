#include <iostream>

using namespace std;

int main()
{
    double x[100], H[100], wynik;
    int i, n;

    cout << "Wprowadz liczbe wezlow: ";
    cin >> n;
    if (n == 2)
    {
        x[0] = -0.707107;
        x[1] = 0.707107;

        H[0] = H[1] = 0.886227;
    }
    else if (n == 3) 
    {
        x[0] = -1.224745;
        x[1] = 0;
        x[2] = 1.224745;

        H[0] = H[2] = 0.295409;
        H[1] = 1.181636;
    }
    else if (n == 4)
    {
        x[0] = -1.650680;
        x[1] = -0.524648;
        x[2] = 0.524648;
        x[3] = 1.650680;

        H[0] = H[3] = 0.236927;
        H[1] = H[2] = 0.478629;
    }
    else if (n == 5) 
    {
        x[0] = -0.906180;
        x[1] = -0.538469;
        x[2] = 0;
        x[3] = 0.538469;
        x[4] = 0.906180;

        H[0] = H[4] = 0.236927;
        H[1] = H[3] = 0.478629;
        H[2] = 0.568889;
    }
    for (i = 0; i < n; i++) {
        cout << x[i] << endl << H[i] << endl;
    }

    for (i = 0; i < n; i++)
    {
        wynik = H[i] * (1 / sqrt(1 + pow(x[i],2)));
        
    }

    cout << endl << "Wynik: " << wynik << endl;
    system("pause");
    return 0;
}

