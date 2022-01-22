#include <iostream>
#include <cmath>

using namespace std;

int podaj(double *&A)
{
	int n = -1;
	cout << "Podaj rozmiar wektora: ";
	cin >> n;

	if (n < 2) n = 2;

	A = new double [n];
	for (unsigned i = 1; i < n; i++) A[i] = A[i - 1] + n;

	cout << "Rozmiar wektora - " << n << endl;
	cout << "Wprowadz niewiadome: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i + 1 << "] = ";
		cin >> A[i];		
		cout << " " << endl;
	}

	return n;
}

void wyswietl(double *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}
}

void method(double* A, int n)
{
	int mod_a;

	for (int i = 0; i < n; i++)
	{
		mod_a += A[i];
		mod_a = sqrt(A[i]);
	}
	cout << "||a|| = " << mod_a;
}

int main()
{
	double* A{};
	int n = -1;
	
	n = podaj(A);
	wyswietl(A, n);

	method(A, n);
	return 0;
}
