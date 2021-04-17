

#include "FillRand.h"
#include "Print.h"
#include "Arrays1.h"
#include "Arrays2.h"

#define ARRAYS1


void main()
{
	setlocale(LC_ALL, "rus");
	int index;
	
#ifdef ARRAYS1
	int n = 0;
	int value;//Добавляемое значение
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

	int m_2 = 0; // количество строк
	int n_2 = 0; //количество элементов строки(столбцы)

	cout << "\n\n\nВведите количество строк: ";
	cin >> m_2;
	cout << "Введите количество элементов строки: ";
	cin >> n_2;
	//1) Создаем массив указателей и сохраняем его адрес в указ на указ
	int** arr2 = new int* [m_2];
	//2) Выделяем память под строки 2-мерного массива:
	for (int i = 0; i < m_2; i++) {
		arr2[i] = new int[n_2] {};
	}

	cout << "Память выделена: " << endl;

	FillRand(arr2, m_2, n_2);
	Print(arr2, m_2, n_2);

	cout << "Добаление строки в КОНЕЦ массив:\n";
	push_row_back(arr2, m_2, n_2);
	Print(arr2, m_2, n_2);

	cout << "Добаление строки в НАЧАЛО массив:\n";
	push_row_front(arr2, m_2, n_2);
	Print(arr2, m_2, n_2);

	cout << "Добаление строки ПО ИНДЕКСУ в массив:\n";
	cout << "Введите индекс добавляемого элемента:"<< tab; cin >> index;
	insert_row(arr2, m_2, n_2, index);
	Print(arr2, m_2, n_2);

	cout << "\n\nУдаление строки из КОНЦА массива: \n";
	pop_row_back(arr2, m_2, n_2);
	Print(arr2, m_2, n_2);

	cout << "\n\nУдаление строки с НАЧАЛА массива: \n";
	pop_row_front(arr2, m_2, n_2);
	Print(arr2, m_2, n_2);

	cout << "\n\nУдаление строки ПО ИНДЕКСУ из массива: \n";
	cout << "Введите индекс:" << tab; cin >> index;
	erase_row(arr2, m_2, n_2, index);
	Print(arr2, m_2, n_2);

	//3) Удаление элементов строк
	for (int i = 0; i < m_2; i++) {
		delete[] arr2[i];
	}
	//4) Удаление массива указателей
	delete[] arr2;

}
