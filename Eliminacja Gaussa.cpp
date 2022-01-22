#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<sstream>

double const eps = 1e-7;
using namespace std;

double roundoff(double value, unsigned char prec) {
    double pow_10 = pow(10.0f, (double)prec);
    return round(value * pow_10) / pow_10;
}


void wyswietl(double** A, double* B, int m_rozmiar) {
    for (int i = 0; i < m_rozmiar; i++) {
        for (int j = 0; j < m_rozmiar; j++)
            cout << roundoff(A[i][j], 3) << "\t";
        cout << " | " << roundoff(B[i], 3);
        cout << endl;
    }
    cout << endl;
}

int wprowadz(double**& A, double*& B, char sposob, int dane) {
    int m_rozmiar = -1;
    if (sposob == 't')
    {
        cout << "Podaj rozmiar macierzy: ";
        cin >> m_rozmiar;

        if (m_rozmiar < 2) m_rozmiar = 2;

        A = new double* [m_rozmiar];
        A[0] = new double[m_rozmiar * m_rozmiar];
        for (unsigned i = 1; i < m_rozmiar; i++) A[i] = A[i - 1] + m_rozmiar;

        B = new double[m_rozmiar];

        cout << "Rozmiar macierzy - " << m_rozmiar << "x" << m_rozmiar << endl << endl;

        cout << "Wprowadz niewiadome: " << endl;
        for (int i = 0; i < m_rozmiar; i++)
        {
            for (int j = 0; j < m_rozmiar; j++)
            {
                cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
                cin >> A[i][j];
            }
            cout << "B[" << i + 1 << "] = ";
            cin >> B[i];
            cout << " " << endl;
        }
    }
    else if (sposob == 'n') {
        if (dane == 1)
        {
            m_rozmiar = 4;
            A = new double* [m_rozmiar];
            A[0] = new double[m_rozmiar * m_rozmiar];
            for (unsigned i = 1; i < m_rozmiar; i++)
                A[i] = A[i - 1] + m_rozmiar;
            B = new double[m_rozmiar];
            A[0][0] = 1;
            A[0][1] = 2;
            A[0][2] = -1;
            A[0][3] = 2;
            B[0] = 0;
            A[1][0] = 1;
            A[1][1] = 0;
            A[1][2] = -2;
            A[1][3] = 4;
            B[1] = 4;
            A[2][0] = 0;
            A[2][1] = -3;
            A[2][2] = 1.5;
            A[2][3] = 7;
            B[2] = 0;
            A[3][0] = 0;
            A[3][1] = -1;
            A[3][2] = 1;
            A[3][3] = 6;
            B[3] = -1;
        }
        else if (dane == 2)
        {
            m_rozmiar = 3;
            A = new double* [m_rozmiar];
            A[0] = new double[m_rozmiar * m_rozmiar];
            for (unsigned i = 1; i < m_rozmiar; i++)
                A[i] = A[i - 1] + m_rozmiar;
            B = new double[m_rozmiar];
            A[0][0] = 3;
            A[0][1] = 2;
            A[0][2] = -5;
            B[0] = -1;
            A[1][0] = 2;
            A[1][1] = -1;
            A[1][2] = 3;
            B[1] = 13;
            A[2][0] = 1;
            A[2][1] = 2;
            A[2][2] = -1;
            B[2] = 9;
        }
        else if (dane == 3)
        {
            m_rozmiar = 4;
            A = new double* [m_rozmiar];
            A[0] = new double[m_rozmiar * m_rozmiar];
            for (unsigned i = 1; i < m_rozmiar; i++)
                A[i] = A[i - 1] + m_rozmiar;
            B = new double[m_rozmiar];
            A[0][0] = 1;
            A[0][1] = 1;
            A[0][2] = 0;
            A[0][3] = -3;
            B[0] = 1;
            A[1][0] = 1;
            A[1][1] = 4;
            A[1][2] = -1;
            A[1][3] = -4;
            B[1] = -2;
            A[2][0] = 0.5;
            A[2][1] = 0.5;
            A[2][2] = -3;
            A[2][3] = -5.5;
            B[2] = 1.5;
            A[3][0] = 1.5;
            A[3][1] = 3;
            A[3][2] = -5;
            A[3][3] = -9;
            B[3] = -0.5;
        }
        else if (dane == 4)
        {
            m_rozmiar = 5;
            A = new double* [m_rozmiar];
            A[0] = new double[m_rozmiar * m_rozmiar];
            for (unsigned i = 1; i < m_rozmiar; i++)
                A[i] = A[i - 1] + m_rozmiar;
            B = new double[m_rozmiar];
            A[0][0] = 14;
            A[0][1] = -13;
            A[0][2] = 3;
            A[0][3] = -16;
            A[0][4] = -42;
            B[0] = -37;
            A[1][0] = 3.5;
            A[1][1] = -18;
            A[1][2] = 13;
            A[1][3] = -23.75;
            A[1][4] = -21;
            B[1] = -5.5;
            A[2][0] = 3.5;
            A[2][1] = 3;
            A[2][2] = -5.25;
            A[2][3] = 9.25;
            A[2][4] = 10.5;
            B[2] = 12.5;
            A[3][0] = 2;
            A[3][1] = 14.5;
            A[3][2] = -10.5;
            A[3][3] = 18.5;
            A[3][4] = 21;
            B[3] = 23.5;
            A[4][0] = 1.5;
            A[4][1] = 6.75;
            A[4][2] = -9.25;
            A[4][3] = 17;
            A[4][4] = -10.5;
            B[4] = -45.25;
        }
    }
    return m_rozmiar;
}


void bubbleSort(int* Tab, double* Indexs, int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N - i; j++) {
            if (Tab[j] < Tab[j - 1]) {
                swap(Tab[j], Tab[j - 1]);
                swap(Indexs[j], Indexs[j - 1]);
            }
        }
    }
}


double* wyznaczX(double** A, double* B, int m_rozmiar, int* index_arr) {
    double* result_x = new double[m_rozmiar];
    for (int i = 0; i < m_rozmiar; i++)
        result_x[i] = 0;

    for (int i = m_rozmiar - 1; i >= 0; i--) {
        result_x[i] = B[i];
        for (int j = i + 1; j < m_rozmiar; j++)
            result_x[i] = result_x[i] - A[i][j] * result_x[j];
        if (A[i][i] != 0)
            result_x[i] /= A[i][i];
        else if (B[i] == 0)
            result_x[i] = 0;
        else {
            cout << "\x1B[31mBlad matematyczny!\033[0m\t\t" << endl;
            return result_x;
        }
    }
    for (int i = 0; i < m_rozmiar; i++)
        if (abs(result_x[i]) < eps)
            result_x[i] = 0;
    bubbleSort(index_arr, result_x, m_rozmiar);

    return result_x;
}


void przesunWiersz(double** A, double* B, int krok, int index) {
    swap(A[krok], A[index]);
    swap(B[krok], B[index]);
}

void przesunKolumne(double** A, int m_rozmiar, int krok, int index, int* index_arr) {
    swap(index_arr[krok], index_arr[index]);
    for (int i = 0; i < m_rozmiar; i++)
        swap(A[i][krok], A[i][index]);
}


int* warMaxKolumna(double** A, double* B, int m_rozmiar, int krok) {
    int* max = new int[3];
    max[0] = krok;
    max[1] = krok;
    max[2] = A[krok][krok];
    for (int i = krok; i < m_rozmiar; i++)
        if (abs(A[i][krok]) > abs(max[2])) {
            max[0] = i;
            max[1] = krok;
            max[2] = A[i][krok];
        }
    return max;
}

int* warMaxPelna(double** A, double* B, int m_rozmiar, int krok, int* index_arr) {
    int* max = new int[3];
    max[0] = krok;
    max[1] = krok;
    max[2] = A[krok][krok];
    for (int i = krok; i < m_rozmiar; i++) {
        for (int j = krok; j < m_rozmiar; j++)
            if (abs(A[i][j]) > abs(max[2])) {
                max[0] = i;
                max[1] = j;
                max[2] = A[i][j];
            }
    }
    return max;
}


void matrixTransformation(double** A, double* b, int m_rozmiar, int krok, int metoda, int* index_arr) {
    int* max = new int[3];
    switch (metoda) {
    case 2: {
        max = warMaxKolumna(A, b, m_rozmiar, krok);
        if (max[0] == max[1])
            return;

        cout << "Wybor elementa maksymalnego w kolumnach - element maksymalny " << max[2] << endl;
        przesunKolumne(A, m_rozmiar, max[0], max[1], index_arr);
        cout << "Zostala zmianiona kolomna " << max[1] + 1 << " z kolumna " << max[0] + 1 << endl;
        break;
    }
    case 3: {
        max = warMaxPelna(A, b, m_rozmiar, krok, index_arr);
        if (max[0] == krok)
            return;

        cout << "Wybor elementa maksymalnego w macierze - element maksymalny " << max[2] << endl;
        przesunWiersz(A, b, krok, max[0]);
        cout << "Zostal zmieniony wiersz " << max[0] + 1 << " z wierszem " << krok + 1 << endl;
        if (A[krok][max[0]] == max[2]) {
            przesunKolumne(A, m_rozmiar, max[0], krok, index_arr);
            cout << "Zostala zmianiona kolomna " << max[1] + 1 << " z kolumna " << krok + 1 << endl;
        }
        break;
    }
    default:
        break;
    }
}

void Gauss(double** A, double* B, int m_rozmiar, int metoda) {
    
    double* result;
    int* index_arr = new int[m_rozmiar];


    for (int i = 0; i < m_rozmiar; i++)
        index_arr[i] = i;

    for (int i = 0; i < m_rozmiar - 1; i++) {
        cout << "Krok " << i + 1 << endl;

        switch (metoda) {
        case 2:
            matrixTransformation(A, B, m_rozmiar, i, 2, index_arr);
            wyswietl(A, B, m_rozmiar);
            break;
        case 3:
            matrixTransformation(A, B, m_rozmiar, i, 3, index_arr);
            wyswietl(A, B, m_rozmiar);
            break;
        default:
            break;
        }

        if (abs(A[i][i]) <= eps) {
            cout << "Operacja z a" << i + 1 << "," << i + 1 << " nie jest wykonalna!" << endl;
            return;
        }

        for (int j = i; j < m_rozmiar - 1; j++) {
            double p = A[j + 1][i] / A[i][i];
            if (abs(p) <= eps) {
                cout << "p" << j + 1 << " = " << p << " <= zero" << endl;
                continue;
            }
            for (int k = i; k < m_rozmiar; k++) {
                A[j + 1][k] = A[j + 1][k] - p * A[i][k];
            }
            B[j + 1] = B[j + 1] - p * B[i];
        }
        wyswietl(A, B, m_rozmiar);
    }
    result = wyznaczX(A, B, m_rozmiar, index_arr);
    for (int i = 0; i < m_rozmiar; i++) {
        cout << "x" << i + 1 << " = " << result[i] << endl;
    }
}


void wait() {
    system("pause");
    system("cls");
}


int main()
{
    double** A{}, * B{};
    unsigned int metoda, dane;
    char sposob;
    int m_rozmiar = -1;

    cout << setprecision(3) << fixed;

    while (true)
    {
        cout << "Projekt \"Eliminacja Gaussa\"" << endl << endl
            << "Wybierz metode eliminacji:" << endl
            << "1. Podstawowa (bez wyboru elementu maksymalnego);" << endl
            << "2. Z wyborem elementu maksymalnego w kolumnie;" << endl
            << "3. Z pelnym wyborem elementu maksymalnego;" << endl
            << "0. Wyjscie z programy.";
        cout << endl << ">>>> ";
        cin >> metoda;
        if (!(metoda >= 0 && metoda <= 3))
        {
            cerr << "Niepoprawny wybor! Sprobuj jeszcze raz." << endl;
            wait();
            continue;
        }
        else if (metoda == 0) {
            cout << endl << "\x1B[34m--------------------------Zamykanie...--------------------------\033[0m" << endl;
            system("pause");
            exit(1);
        }
        cout << "Czy chcesz sam podac dane wejsciowe, czy testowac program dla danych zawartych w programie?" << endl
            << "Tak, podaje 't'" << endl
            << "Nie, niech testuje dla danych zawartych w programie 'n'" << endl;
        cout << endl << ">>>> ";
        cin >> sposob;

        if (sposob == 't') 
        {
            m_rozmiar = wprowadz(A, B, sposob, 1);
            wyswietl(A, B, m_rozmiar);
        }

        else if (sposob == 'n')
        {
            cout << "Jakie dane zastosowac" << endl;
            for (int i = 1; i <= 4; i++) {
                cout << "Dane nr. " << i << endl;
                m_rozmiar = wprowadz(A, B, sposob, i);
                wyswietl(A, B, m_rozmiar);
            }

            cout << "Podaj nr. danych" << endl;
            cout << ">>>> "; 
            cin >> dane;

            if (!(dane >= 1 && dane <= 4)) {
                cout << "Niepoprawny wybor! Sprobuj jeszcze raz." << endl;
                wait();
                continue;
            }
            m_rozmiar = wprowadz(A, B, sposob, dane);
        }
        else
        {
            cout << "Niepoprawny wybor! Sprobuj jeszcze raz." << endl;
            wait();
            continue;
        }

        Gauss(A, B, m_rozmiar, metoda);
        wait();
    }

    return 0;
}