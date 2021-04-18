/*#include <iostream>
using namespace std;
#define tab "\t"*/

#include "templated_Print.h"
#include "double_FillRand.h"
#include "templated_Print.cpp"
#include "templated_FillRand.h"
#include "templated_FillRand.cpp"
#include "templated_Arrays1.h"
#include "templated_Arrays1.cpp"
#include "templated_Arrays2.h"
#include "templated_Arrays2.cpp"
#define ARRAYS1

void main()
{
	setlocale(LC_ALL, "rus");
	int index;
	
#ifdef ARRAYS1
	int n = 0;
	int value = 0;//Добавляемое значение
	cout << "Введите размер массива: " << endl;
	cin >> n;
	int* arr = new int[n] {};

	FillRand(arr, n);
	Print(arr, n);
	cout << "\n\n";

	cout << "\n\nВведите добавляемое значение в конец массива:" << endl;
	cin >> value;
	cout << "\n\n";
	push_back(arr, n, value);
	Print(arr, n);

	cout << "\n\nВведите добавляемое значение в начало массива:" << endl;
	cin >> value;
	cout << "\n\n";
	push_front(arr, n, value);
	Print(arr, n);

	cout << "\n\nВведите ДОБАВЛЯЕМОЕ значение" << tab; cin >> value;
	cout << "\n\nВведите индекс добавляемого элемента: \n\n"; cin >> index;
	insert(arr, n, value, index);
	cout << "\n\n";
	Print(arr, n);

	cout << "\n\nУдаление элемента из НАЧАЛА массива: \n\n";
	pop_front(arr, n);
	Print(arr, n);
	cout << "\n\n";

	cout << "\n\nУдаление элемента с КОНЦА массива: \n\n";
	pop_back(arr, n);
	Print(arr, n);

	cout << "\n\nВведите индекс УДАЛЯЕМОГО элемента: \n\n"; cin >> index;
	erase(arr, n, index);
	cout << "\n";
	Print(arr, n);

	delete[] arr;
#endif // ARRAYS1

	int rows = 0; // количество строк
	int cols = 0; //количество элементов строки(столбцы)

	cout << "\n\n\nВведите количество строк: ";
	cin >> rows;
	cout << "Введите количество элементов строки: ";
	cin >> cols;
	//1) Создаем массив указателей и сохраняем его адрес в указ на указ
	double** arr2 = new double* [rows];
	//2) Выделяем память под строки 2-мерного массива:
	for (int i = 0; i < rows; i++) {
		arr2[i] = new double[cols] {};
	}

	cout << "Память выделена: " << endl;

	FillRand(arr2, rows, cols);
	Print(arr2, rows, cols);

	cout << "Добаление строки в КОНЕЦ массив:\n";
	push_row_back(arr2, rows, cols);
	Print(arr2, rows, cols);

	cout << "Добаление строки в НАЧАЛО массив:\n";
	push_row_front(arr2, rows, cols);
	Print(arr2, rows, cols);

	cout << "Добаление строки ПО ИНДЕКСУ в массив:\n";
	cout << "Введите индекс добавляемого элемента:"<< tab; cin >> index;
	insert_row(arr2, rows, cols, index);
	Print(arr2, rows, cols);

	cout << "\n\nУдаление строки из КОНЦА массива: \n";
	pop_row_back(arr2, rows, cols);
	Print(arr2, rows, cols);

	cout << "\n\nУдаление строки с НАЧАЛА массива: \n";
	pop_row_front(arr2, rows, cols);
	Print(arr2, rows, cols);

	cout << "\n\nУдаление строки ПО ИНДЕКСУ из массива: \n";
	cout << "Введите индекс:" << tab; cin >> index;
	erase_row(arr2, rows, cols, index);
	Print(arr2, rows, cols);

	//3) Удаление элементов строк
	for (int i = 0; i < rows; i++) {
		delete[] arr2[i];
	}
	//4) Удаление массива указателей
	delete[] arr2;

}
