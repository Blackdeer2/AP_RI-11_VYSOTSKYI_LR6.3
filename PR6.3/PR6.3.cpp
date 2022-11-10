#include <iostream>
#include <time.h>
using namespace std;

void Create(int* mas, const int n, int A, int B, int i) {
	mas[i] = A + rand() % (B - A + 1);
	if (i < n - 1)
		Create(mas, n, A, B, i + 1);
}

void Print(int* mas, const int n, int i) {
	cout << " " << mas[i];
	if (i < n - 1)
		Print(mas, n, i + 1);
	else cout << " ";
}

int Suma_v2(int* mas, const int n, int i, int s) {

	if (i < n)
		return  s + mas[i] * mas[i] + Suma_v2(mas, n, i + 1, s);
	else
	return s;
}

template <typename T1>
void CreateT(T1* mas, const int n, int A, int B, int i) {
	mas[i] = A + rand() % (B - A + 1);
	if (i < n - 1)
		CreateT(mas, n, A, B, i + 1);
}

template <typename T1>
void PrintT(T1* mas, const int n, int i) {
	cout << " " << mas[i];
	if (i < n - 1)
		PrintT(mas, n, i + 1);
	else cout << " ";
}

template <typename T1>
T1 Suma_v2T(T1* mas, const int n, int i, T1 s)
{
	if (i < n)
		return  s + mas[i] * mas[i] + Suma_v2T(mas, n, i + 1, s);
	else
		return s;
}

int main()
{
	srand(time(NULL));
	const int a = 10;
	int A[a]{};
	double B[a]{};
	Create(A, a, -20, 50, 0);
	cout << "A {"; Print(A, a, 0); cout << "}";
	cout << " suma = " << Suma_v2(A, a, 0, 0) << endl;

	CreateT(B, a, -20, 50, 0);
	cout << "A {"; PrintT(B, a, 0); cout << "}";
	cout << " sumaT = " << Suma_v2T(B, a, 0, 0.0) << endl;
	return 0;
}