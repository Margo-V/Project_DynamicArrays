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