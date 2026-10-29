#include <iostream>
#include <string>

using namespace std;

int SumRec(const int* a, const int size, int i);

template <typename T>
T SumRec(const T* a, const int size, int i);

int main() {
	const int n = 15;

	int a[n] = { -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int s1 = SumRec(a, n, 0);
	cout << "SumRec(a, n, 0) = " << s1 << endl;

	int s2 = SumRec<int>(a, n, 0);
	cout << "SumRec<int>(a, n, 0) = " << s2 << endl;

	double b[n] = { -4.4, -3.3, -2.2, -1.1, 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
	double s3 = SumRec<double>(b, n, 0);
	cout << "SumRec<double>(b, n, 0) = " << s3 << endl;

	string c[n] = { "-4 ", "-3 ", "-2 ", "-1 ", "0 ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10 " };
	string s4 = SumRec<string>(c, n, 0);
	cout << "SumRec<string>(c, n, 0) = " << s4 << endl;

	return 0;
}

int SumRec(const int* a, const int size, int i) {
	if (i >= size)
		return 0;

	if (a[i] > 0)
		return a[i] + SumRec(a, size, i + 1);
	else
		return SumRec(a, size, i + 1);
}

template <typename T>
T SumRec(const T* a, const int size, int i) {
	if (i >= size)
		return T();

	if (a[i] > T())
		return a[i] + SumRec<T>(a, size, i + 1);
	else
		return SumRec<T>(a, size, i + 1);
}