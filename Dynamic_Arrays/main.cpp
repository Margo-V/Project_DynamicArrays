#include <iostream>
using namespace std;
#define tab "\t"
#define ARRAYS1

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);
void erase(int*& arr, int& n, int index);


void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);
void insert_row(int**& arr, int& m, const int n, int index);

void pop_row_back(int**& arr, int& m, const int n);
void pop_row_front(int**& arr, int& m, const int n);
void erase_row(int**& arr, int& m, const int n, int index);

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

void FillRand(int arr[], const int n) 
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

void push_back(int*& arr, int& n, int value)
{
	//1) Создаем буферный массив нужного размера (buffer):
	int* buffer = new int[n + 1]{};
	//2) Копируем все значения из исходного масива в буферный(чтобы сохранить данные):
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];//Копируем элементы соответственно
	}
	//3) После того, как данные скопированы исходный массив можно удалить:
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив:
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в конец масива:
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};

	for (int i = 0; i < n; i++) {
		//Копируем элементы со смещением на один элемент вправо
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};

	/*for (int i = 0; i < index; i++) {
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++) {
		buffer[i + 1] = arr[i];
	}*/

	for (int i = 0; i < n; i++) {
		/*if (i < index) {
			buffer[i] = arr[i];
		}
		else {
			buffer[i + 1] = arr[i];
		}*/

		(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
		//buffer[i < index ? i : i + 1] = arr[i];

	}

	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};

	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}
void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[--n]{};

	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	arr = buffer;
}


void push_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1];

	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	arr[m] = new int[n] {};
	m++;
}
void push_row_front(int**& arr, int& m, const int n)
{

	int** buffer = new int*[m + 1]{};

	for (int i = 0; i < m; i++) {
		buffer[i + 1] = arr[i];
	}

	delete[] arr;
	arr = buffer;
	arr[0] = new int[n]{};
	m++;
}
void insert_row(int**& arr, int& m, const int n, int index)
{
	int** buffer = new int* [m + 1]{};

	for (int i = 0; i < index; i++) {
		buffer[i] = arr[i];
	}
	for (int i = index; i < m + 1; i++) {
		buffer[i + 1] = arr[i];
	}

	delete[] arr;
	arr = buffer;
	arr[index] = new int[n] {};
	m++;
}

void pop_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr[m];
	delete[] arr;
	arr = buffer;
}
void pop_row_front(int**& arr, int& m, const int n) 
{
	int** buffer = new int* [--m]{};

	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i + 1];
	}

	delete[] arr[0];
	delete[] arr;
	arr = buffer;

}
void erase_row(int**& arr, int& m, const int n, int index)
{
	int** buffer = new int* [--m]{};

	for (int i = 0; i < index; i++) {
		buffer[i] = arr[i];
	}
	for (int i = index; i < m; i++) {
		buffer[i] = arr[i + 1];
	}
	delete[]arr[index];
	delete[] arr;
	arr = buffer;

}