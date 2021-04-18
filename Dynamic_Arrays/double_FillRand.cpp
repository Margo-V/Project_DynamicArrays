#include "double_FillRand.h"


void FillRand(double arr[], const int n)
{
	cout << typeid(arr[0]).name() << endl;
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 1000;
		arr[i] /= 100;
	}
}
void FillRand(double** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = double(rand() % 10000) / 100;
		}
	}
}