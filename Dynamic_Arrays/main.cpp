#include <iostream>
using namespace std;
#define tab "\t"
//#define ARRAYS1


void FillRand(double arr[], const int n);
template<typename T>void FillRand(T arr[], const int n);
void FillRand(double** arr, const int m, const int n);
template<typename T>void FillRand(T** arr, const int m, const int n);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int m, const int n);

template<typename T>void push_back(T*& arr, int& n, T value);
template<typename T>void push_front(T*& arr, int& n, T value);
template<typename T>void insert(T*& arr, int& n, T value, int index);

template<typename T>void pop_back(T*& arr, int& n);
template<typename T>void pop_front(T*& arr, int& n);
template<typename T>void erase(T*& arr, int& n, int index);


template<typename T>void push_row_back(T**& arr, int& m, const int n);
template<typename T>void push_row_front(T**& arr, int& m, const int n);
template<typename T>void insert_row(T**& arr, int& m, const int n, int index);

template<typename T>void pop_row_back(T**& arr, int& m, const int n);
template<typename T>void pop_row_front(T**& arr, int& m, const int n);
template<typename T>void erase_row(T**& arr, int& m, const int n, int index);

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

void FillRand(double arr[], const int n)
{
	cout << typeid(arr[0]).name() << endl;
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 1000;
		arr[i] /= 100;
	}
}
template<typename T>void FillRand(T arr[], const int n) 
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(double** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = double(rand() % 10000) /100;
		}
	}
}
template<typename T>void FillRand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}
template<typename T>void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

template<typename T>void push_back(T*& arr, int& n, T value)
{
	//1) Создаем буферный массив нужного размера (buffer):
	T* buffer = new T[n + 1]{};
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
template<typename T>void push_front(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};

	for (int i = 0; i < n; i++) {
		//Копируем элементы со смещением на один элемент вправо
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
template<typename T>void insert(T*& arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};

	for (int i = 0; i < index; i++) {
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++) {
		buffer[i + 1] = arr[i];
	}

	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}
template<typename T>void pop_back(T*& arr, int& n)
{
	T* buffer = new T[--n]{};

	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T>void pop_front(T*& arr, int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T>void erase(T*& arr, int& n, int index)
{
	T* buffer = new T[--n]{};

	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	arr = buffer;
}

template<typename T>void push_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T* [m + 1];

	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	arr[m] = new T[n] {};
	m++;
}
template<typename T>void push_row_front(T**& arr, int& m, const int n)
{

	T** buffer = new T*[m + 1]{};

	for (int i = 0; i < m; i++) {
		buffer[i + 1] = arr[i];
	}

	delete[] arr;
	arr = buffer;
	arr[0] = new T[n]{};
	m++;
}
template<typename T>void insert_row(T**& arr, int& m, const int n, int index)
{
	T** buffer = new T* [m + 1]{};

	for (int i = 0; i < index; i++) {
		buffer[i] = arr[i];
	}
	for (int i = index; i < m + 1; i++) {
		buffer[i + 1] = arr[i];
	}

	delete[] arr;
	arr = buffer;
	arr[index] = new T[n] {};
	m++;
}
template<typename T>void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T* [--m]{};
	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr[m];
	delete[] arr;
	arr = buffer;
}
template<typename T>void pop_row_front(T**& arr, int& m, const int n) 
{
	T** buffer = new T* [--m]{};

	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i + 1];
	}

	delete[] arr[0];
	delete[] arr;
	arr = buffer;

}
template<typename T>void erase_row(T**& arr, int& m, const int n, int index)
{
	T** buffer = new T* [--m]{};

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