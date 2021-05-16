#include <iostream>

#define tab "\t"


using namespace std;

void change_values(int &a,int &b);

void main()
{
	setlocale(LC_ALL, "ru");
	int a, b;
	cout << "Введите первое число: "; cin >> a;
	cout << "Введите второе число: "; cin >> b;
	cout << "Ваши числа:\na = " << a << "\nb = " << b << endl;
	change_values(a, b);
	cout << "Результат после функции:\na = " << a << "\nb = " << b << endl;
}
void change_values(int &a, int &b)
{
	//int a = 2, b = 5;
	a = a + b;
	b = a - b; // b =2
	a = a - b; // a =5
}