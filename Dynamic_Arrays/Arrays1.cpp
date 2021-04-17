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