#include <iostream>
#include <conio.h>

using namespace std;

#define tab "\t"

//#define RECURSION_BASICS
//#define FACTORIAL
//#define POWER
#define DataType unsigned long long int
#define LONG_INT_TYPE unsigned long long int

// typedef unsigned long long int DataType2

void elevator(int floor);
int factorial(int n);
int factorial_2(int n);
int factorial_3(int n);
int factorial_4(int n);
int fibonacci(int n);
#ifdef FACTORIAL
int Fibonacci_1(int n, int a = 0, int b = 1);
int Fibonacci_2(int n, DataType a, DataType b);
#endif // FACTORIAL

// �� ��������� �������� ��������� �����
int Fibonacci_hometask(int n, int x = 0 );

int Fibonacci_hometask_2(int count, LONG_INT_TYPE x = 0 );

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

#ifdef POWER
	int a; //��������� �������
	int b; //���������� �������
	cout << "������ ��������� �������: " << endl; cin >> a;
	cout << "������ ���������� �������: " << endl; cin >> b;

	cout << power(a, b);
#endif // POWER

#ifdef FACTORIAL
	int fib, n;
	cout << "\n������� ��������, �� �������� ����� ������� ��� ���������:\t";
	cin >> fib;
	Fibonacci_1(fib);
	cout << "������� ����� �� ���� ����� �������" << endl;
	cin >> n;
	Fibonacci_2(n);
#endif // FACTORIAL

	int n, count;
	cout << "������� ����� ��� ���������� ����� ���������: ";cin >> n;
	Fibonacci_hometask(n);

	cout << "\n\n������� ����� ���������� ����� ������ ������� �� �����: "; cin >> count;
	Fibonacci_hometask_2(count);
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

#ifdef FACTORIAL

int Fibonacci_1(int n, int a, int b)
{
	//������� ����� ��������� �� ��������� �������
	if (a > n)return;
	cout << a << tab;
	Fibonacci_1(n, b, a + b);
}

int Fibonacci_2(int n, DataType a, DataType b)
{
	//������� �������� ���������� ����� �� ���� ���������
	if (n == 0)return;
	cout << a << tab;
	Fibonacci_1(n - 1, b, a + b);

	/*static int i = 0;
	if (i > n)return;
	cout << i++ << " - " << a << tab;
	Fibonacci_1(n, b, a + b);*/
}

#endif // FACTORIAL

int Fibonacci_hometask(int n, int x)
{
	// �� ��������� �������� ��������� �����
	if (x > n) return 0;

	static int c = 1;
	c = x + c;
	cout << x << tab;
	if (c > n)
	{
		cout << tab;
	}
	else {
		cout << c << tab;
	}
	
	Fibonacci_hometask( n, x + c);
}

int Fibonacci_hometask_2(int count, LONG_INT_TYPE x)
{
	static int c = 1;
	if (count == 0 || count < 0) return 0;

	c = x + c;
	cout << x << tab;
	count--;
	cout << c << tab;
	Fibonacci_hometask_2(count -1, x + c);
	
}