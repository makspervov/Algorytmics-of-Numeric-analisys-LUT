#include <iostream>


using namespace std;

int Horner(int wsp[], int st, int x)
{
    if (st == 0) return wsp[0];
    return x * Horner(wsp, st - 1, x) + wsp[st];
}

int main()
{
    int* wsp1;
    int stopien, punkt;

    cout << "Podaj stopien wielomianu: ";
    cin >> stopien;
    cout << endl;

    wsp1 = new int[stopien + 1];
    for (int i = 0; i <= stopien; i++)
    {
        cout << "Podaj wspolczynnik: ";
        cin >> wsp1[i];
        cout << endl;
    }

    cout << "Podaj punkt: ";
    cin >> punkt;
    cout << "w(" << punkt << ") = " << Horner(wsp1, stopien, punkt) << endl;
    delete[]wsp1;
    system("pause");
    return 0;
}
