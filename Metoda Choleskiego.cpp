#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<sstream>

using namespace std;

void Choleski(int n, double** A, double** l)
//a - macierz symetryczna, dodatnio okreslona, l – macierz wyzerowana, A=LLT
{
	double sum = 0.0;
	for (int s = 0; s < n; s++)
	{
		for (int i = s; i < n; i++)
		{
			sum = 0.0;
			for (int j = 0; j < s; j++)
				sum += l[i][j] * l[s][j];
			l[i][s] = A[i][s] - sum;
			if (s == i)
				l[i][s] = sqrt((l[i][s]));
			else
				l[i][s] = l[i][s] / l[s][s];
		} //for i
	} //for s
}

void wyswietl(double** A, double* B, int m_rozmiar) {
	for (int i = 0; i < m_rozmiar; i++) {
		for (int j = 0; j < m_rozmiar; j++)
			cout << (A[i][j], 3) << "\t";
		cout << " | " << (B[i], 3);
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
    else if (sposob == 'n') 
    {
        m_rozmiar = 4;
        A = new double* [m_rozmiar];
        A[0] = new double[m_rozmiar * m_rozmiar];
        for (unsigned i = 1; i < m_rozmiar; i++)
            A[i] = A[i - 1] + m_rozmiar;
        B = new double[m_rozmiar];
        A[0][0] = 4;
        A[0][1] = 6;
        A[0][2] = -4;
        A[0][3] = -6;
        B[0] = 2;
        A[1][0] = 6;
        A[1][1] = 25;
        A[1][2] = 6;
        A[1][3] = -17;
        B[1] = -13;
        A[2][0] = -4;
        A[2][1] = 6;
        A[2][2] = 14;
        A[2][3] = 1;
        B[2] = -14;
        A[3][0] = -6;
        A[3][1] = -17;
        A[3][2] = 1;
        A[3][3] = 23;
        B[3] = 5;
    }
    return m_rozmiar;
}

int main()
{
    cout << "Rozkład Choleskiego" << endl;
}