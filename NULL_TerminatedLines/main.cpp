#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;
#define tab "\t";
//#define STRING_DECLARATION
//#define STRING_FUNCTIONS

void ASCII();
int StringLength(char str[]);

void to_upper(char str[]);		// переводит строку в верхний регистр
void to_lower(char str[]);		// Переводит строку в нижний регистр
void capitalize(char str[]);	// Первую букву каждого слова в предложении делает заглавной



void shrink(char str[]);		// Удаляет из строки лишние пробелы
bool is_palindrome(char str[]);
bool is_int_number(char str[]); //Определяет, является ли строка целым числом
int to_int_number(char str[]);  //Если строка-целое число, функция вернет его числовое значение
bool is_bin_number(char str[]); //Проверяет, является ли строка двоичным числом


#ifdef STRING_FUNCTIONS

//============================== TO DO:
void shrink(char str[]); // Удаляет из строки лишние пробелы
						 //например: Хорошо  живет  на  свете  Винни  Пух ->
						 // Хорошо живет на свете Винни Пух

bool is_palindrome(char str[]); // Туда и обратно читается одинаково
bool is_int_number(char str[]); //Определяет, является ли строка целым числом
								// Строка является целым числом,
								//когда она состоит только из цифр
int to_int_number(char str[]);  //Если строка-целое число, функция вернет 
								//его числовое значение
bool is_bin_number(char str[]); //Проверяет, является ли строка двоичным числом
int bin_to_dec(char str[]);     //Если строка- двоичное число, функция вернет его десятичное значение

? ? ? dec_to_bin(int decimal);		//Функция принимает десятичное число и возвращает его двоичное значение

bool is_hex_number(char str[]);// Проверяет, яв-ся ли функция шестнадацатиричным числом
int hex_to_dec(char str[]); //Если строка-16-ричное число, функция вернет его десятичное значение
? ? ? dec_to_bin(int decimal); //Функция принимает десятичное число и возвращает его шестнадцатеричное значение

bool is_mac_address(char str[]); //Проверяет, является ли строка MAC-адресом
bool is_ip_address(char str[]); //Проверяет, является ли строка IP-адресом

#endif // STRING_FUNCTIONS


//Hardcore:	Если строка целое число, функция вернет его письменное значение кирилицей
//==========================================================
void main()
{
	setlocale(LC_ALL, "ru");

#ifdef STRING_DECLARATION
	char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << str << endl;

	char str_2[] = "Hello";
	cout << "str_2: " << str << endl;
	str_2[1] = 'E';
	cout << "str_2: " << str << endl;

	cout << sizeof(str_2) << endl;
	  
#endif // STRING_DECLARATION


	//ASCII();
	//cout << (int)'a' - (int)'A' << endl;
	//cout << 'a' - 'A' << endl;
#ifdef STRING_FUNCTIONS
	
	cout << StringLength(str) << endl;

	to_upper(str);
	//cout << str << endl;

	capitalize(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
#endif // STRING_FUNCTIONS
	
	//cout << i << tab;
	//cout << int(i) << endl;

	const int n = 20;
	char str[n] = {}; // выделеную память забиваем нулями

	cout << "Введите строку: " << endl;
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
	cout << str << endl;//CP866
	shrink(str);
	cout << str << endl;


	cout << "\n\nПроверим, является ли строка целым числом( 1- Да, 0 - Нет):" <<endl;
	cout << "Введите строку: " << endl;
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
	cout << is_int_number(str);


	cout << "\n\nПроверим, является ли строка двоичным числом( 1- Да, 0 - Нет):" << endl;
	cout << "Введите строку: " << endl;
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
	cout << is_bin_number(str);


	cout << "\n\nЕсли строка-целое число, функция вернет его числовое значение:" << endl;
	cout << "Введите строку: " << endl;
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
	cout << to_int_number(str);



	cout << "Проверим, туда и обратно читается ли одинаково( 1- Да, 0 - Нет):" << endl;
	cout << "Введите строку: " << endl;
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
	cout << is_palindrome(str);
}


void shrink(char str[])
{
	int length = StringLength(str);
	// ' ' = 32;
	int i = 0;

	while (str[0] == ' ' ) {
		for (int j = i; j < length; j++) {
			str[j] = str[j + 1];
		}
		//str[i] = str[i + 1];
		str[--length] = '\0';
	
	}

	for (; i < length;) {

		if (str[i] == ' ' && str[i+1] == ' ') {
			for (int j = i; j < length; j++) {
				str[j] = str[j + 1];
			}
			//str[i] = str[i + 1];
			str[--length] = '\0';
		}
		else {
			i++;
		}
	}
}
bool is_palindrome(char str[])
{
	int length = StringLength(str);
	for (int i = 0; i < length / 2; i++) {
		if (str[i] == str[length - 1 - i]) {
			continue;
		}
		else {
			return 0;
		}		
	}
	return true;
}
bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++) {
		if (str[i] >= '0' && str[i] <= '9' || str[i] == ' ') {
			continue;
		}
		else {
			return 0;
		}
	}
	return 1;
}
int to_int_number(char str[]) {
	if (is_int_number(str)) {
		return int(str);
	}
	else {
		return false;
	}
}
bool is_bin_number(char str[])
{
	if (is_int_number(str)) {

		for (int i = 0; str[i]; i++) {
			if (str[i] == '0' || str[i] == '1') {
				continue;
			}
			else {
				return false;
			}
		}

		return true;
	}	
	else {
		cout << "введите цифры, строка содержит недопустимые знаки" << endl;
		return false;
	}

}


void ASCII()
{
	for (int i = 0; i < 256; i++) {
		cout << i << "\t";
		cout << (char)i << endl;
	}
}
int StringLength(char str[])
{
	int i =0;
	for (; str[i]; i++);
	return i;

	/*
	false - это 0
	true - все что НЕ 0
	*/
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++) 
	{
		if (// ЕСЛИ символ 
			str[i] >= 'a' && str[i] <= 'z' || // маленькая англ буква ИЛИ
			str[i] >= 'а' && str[i] <= 'я'	  // маленькая русская буква
			)// тогда переводим в верхний регистр
			str[i] -= ' ';
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= 'А' && str[i] <= 'Я'
			)
			str[i] += 32;
	}
}
void capitalize(char str[])
{
	to_lower(str);
	if (str[0] >= 'a' && str[0] <= 'z' ||
		str[0] >= 'а' && str[0] <= 'я')str[0] -= 32;
	for (int i = 1; str[i]; i++)
	{
		if (str[i - 1] == ' ')
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
				str[i] -= 32;
		}
	}
	
}