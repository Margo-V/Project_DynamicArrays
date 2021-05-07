#include <iostream>
#include <conio.h>

using namespace std;

//#define RECURSION_BASICS
//#define FACTORIAL


void elevator(int floor);
int factorial(int n);
int factorial_2(int n);
int factorial_3(int n);
int factorial_4(int n);
int fibonacci(int n);


double power(double a, int n);


void main()
{
	setlocale(LC_ALL, "ru");

#ifdef RECURSION_BASICS
	system("CLS");
	cout << "Hello world\n" << endl;

	int floor;
	cout << "�� ����� �� �����?"; cin >> floor;
	elevator(floor);

	cout << "��� �������? (y/n)";
	if (_getch() == 'y')main(); // _getch() -������� ������� �������,
	//� ���������� ASCII-��� ������� �������  
#endif // RECURSION_BASICS

#ifdef FACTORIAL
	int n;
	cout << "������� ����� ��� ���������� ����������: "; cin >> n;
	cout << factorial_4(n) << endl;
#endif // FACTORIAL

	/*int a; //��������� �������
	int b; //���������� �������
	cout << "������ ��������� �������: " << endl; cin >> a;
	cout << "������ ���������� �������: " << endl; cin >> b;
	
	cout << power(a, b);*/

	int fib;
	cout << "\n������� ����� ��� ������� ����� ���������:\t"; cin >> fib;
	cout << fibonacci(fib);
}


void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "������ ������" << endl;
		return;
	}
	static int counter = 0;

	cout << "�� �� " << floor << "�����" << "\t";
	cout << counter++ << endl;

	elevator(floor - 1);

	cout << "�� �� " << floor << "�����" << endl;
	cout << counter++ << endl;
}

int factorial(int n)
{
	int factorial_num = n;
	if (n == 1)
	{
		return factorial_num;
	}
	cout << factorial_num << "\t";
	return factorial_num * factorial(n - 1);
}

int factorial_2(int n)
{
	if (n == 0) return 1;
	int f = n * factorial_2(n - 1);
	return f;
}

int factorial_3(int n)
{
	if (n == 0) return 1;
	return n * factorial_3(n - 1);
}

int factorial_4(int n)
{
	return n == 0 ? 1 : n * factorial_4(n - 1);
}

double power(double a, int n)
{
	return n == 0 ? 1 : n > 0? a * power(a, n - 1):1 / a * power(a, n + 1);
}

int fibonacci(int n)
{
	//cout << n << endl;
	//1- � ������ � ������� �� �����
	if (n == 0)
	{
		cout << n << endl;
		return 0;
		
	}
	else if (n == 1)
	{
		cout << n << endl;
		return 1;
		
	}
	else
	{
		cout << n << endl;
		return (fibonacci(n - 1) + fibonacci(n - 2));
		
	}


	//2-� ������
	//return n == 0  ? 0 : (n == 1) ? 1  : (fibonacci(n - 1) + fibonacci(n - 2));
	
}