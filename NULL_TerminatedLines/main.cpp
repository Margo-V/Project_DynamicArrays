#include <iostream>
#include <Windows.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>


using namespace std;
#define tab "\t";
//#define STRING_DECLARATION
//#define STRING_FUNCTIONS
//#define HOMETASK
//#define CHECK_1
#define BINERY

void ASCII();
int StringLength_STL(char str[]);

void to_upper_STL(char str[]);		// переводит строку в верхний регистр
void to_lower_STL(char str[]);		// Переводит строку в нижний регистр
void capitalize(char str[]);	// Первую букву каждого слова в предложении делает заглавной


void Shrink(char str[]);
bool Is_Palindrome(char str[]);
void Remove_Symbol(char str[], char symbol);
bool Is_Int_Number(char str[]);
int To_Int_Number(char str[]);
bool Is_Bin_Number(char str[]);
char* Dec_To_Bin(int decimal);
int Bin_To_Dec(char str[]);
void insert_spaces(char str[]);
bool is_hex_num_STL(char str[]);// Проверяет, яв-ся ли функция шестнадацатиричным числом
long int hex_to_dec_STL(char hex[]);//Если строка-16-ричное число, функция вернет его десятичное значение


char* dec_to_hex(int decimal); //Функция принимает десятичное число и возвращает его шестнадцатеричное значение
bool is_mac_address(char str[]); //Проверяет, является ли строка MAC-адресом

#ifdef HOMETASK
void shrink(char str[]);		// Удаляет из строки лишние пробелы
bool is_palindrome(char str[]);
bool is_int_number(char str[]); //Определяет, является ли строка целым числом
int to_int_number(char str[]);  //Если строка-целое число, функция вернет его числовое значение
bool is_bin_number(char str[]); //Проверяет, является ли строка двоичным числом

#endif // HOMETASK


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
? ? ? dec_to_hex(int decimal); //Функция принимает десятичное число и возвращает его шестнадцатеричное значение

bool is_mac_address(char str[]); //Проверяет, является ли строка MAC-адресом
bool is_ip_address(char str[]); //Проверяет, является ли строка IP-адресом
//Hardcore:	Если строка целое число, функция вернет его письменное значение кирилицей
//==========================================================

#endif // STRING_FUNCTIONS


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

	const int n = 256;
	char str[n] = {}; // выделеную память забиваем нулями
	//char str[n] = { "Аргентина манит негра" };
	//char str[n] = "Аргентина манит негра";

	//cout << "Введите строку: " << endl;
	//SetConsoleCP(1251);
	//cin.getline(str, n);//CP1251
	//SetConsoleCP(866);

	//cout << Is_Bin_Number(str) << endl;

	/*int decimal;
	cout << "Введите десятичное число: "; cin >> decimal;
	cout << Dec_To_Bin(decimal) << endl;*/

	//cout << str << "(bin) = " << Bin_To_Dec(str) << "(dec)\n";
#ifdef HOMETASK
	cout << "\n\nВведите шестнадцатеричное число: ";
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
	cout << "Строка " << str << (is_hex_number(str) ? "" : " НЕ") << " является шестнадцатеричным числом" << endl;
	cout << "\n\nВведите шестнадцатеричное число: ";
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
	cout << str << " - из шестнадцатеричной в десятичную = " << hex_to_dec(str);


	long int decimal1 = 0;
	cout << "\n\nВведите десятичное число: ";
	cin >> decimal1;
	dec_to_hex(decimal1);
	cout << endl;


	const int m = 256;
	char str_mac[m]{};
	cout << "\nВведите строку( проверим, является ли строка mac-адресом): " << endl;
	cin >> str_mac;


	//char str[n] = { "00:E0:18:C3:11:89" };
	cout << "Строка " << str_mac << (is_mac_address(str_mac) ? "" : " НЕ") << " MAC-адресом" << endl;


#endif // HOMETASK

	cout << "\n\nВведите шестнадцатеричное число: ";
	SetConsoleCP(1251);
	cin.getline(str, n);//CP1251
	SetConsoleCP(866);
	//cout << "Строка " << str << (Is_Hex_number_2(str) ? "" : " НЕ") << " является шестнадцатеричным числом" << endl;
	//cout << "Строка " << str << (is_hex_num_STL(str) ? "" : " НЕ") << " является шестнадцатеричным числом" << endl;
	//cout << str << "(hex) = " << Hex_To_Dec_2(str) << "(dec)\n";
	//cout << str << "(hex) = " << hex_to_dec_STL(str) << "(dec)\n";
	cout << "Длина строки " << str << " = " << StringLength_STL(str) << endl;


#ifdef CHECK_1
	
	//cout << str << endl;//CP866
	Shrink(str);
	cout << str << endl;
	cout << "Строка " << (Is_Palindrome(str) ? "" : "НЕ ") << "является палидромом" << endl;
	cout << "Строка " << str << (Is_Int_Number(str) ? "" : " НЕ") << " является целым числом" << endl;
	cout << str << endl;
	cout << To_Int_Number(str) * 10 << endl;
#endif // CHECK_1

#ifdef HOMETASK
	shrink(str);
	cout << str << endl;


	cout << "\n\nПроверим, является ли строка целым числом( 1- Да, 0 - Нет):" << endl;
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
#endif // HOMETASK

}

void Shrink(char str[])
{
	//Общий случай
	for (int i = 0; str[i]; i++)
	{
		/*while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}*/

		if (
			str[i] == ' ' && 
			(
				str[i+1] == ' ' || 
				str[i+1] == ',' || 
				str[i+1] == '.' || 
				str[i+1] == '?' || 
				str[i+1] == '!' ||
				str[i+1] == ':' ||
				str[i+1] == ';' ||
				str[i+1] == '-' ||
				str[i+1] == ')'
			) 
			|| str[0] == ' ' 
			|| str[i-1] == '(' && str[i] == ' '
			|| str[i-1] == '-' && str[i] == ' '
			)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}
void Remove_Symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++) 
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
bool Is_Palindrome(char str[])
{
	int length = StringLength(str);
	char* buffer = new char[length + 1] {};

	for (int i = 0; i < length; i++)
	{
		buffer[i] = str[i];
	}

	to_lower(buffer);
	Remove_Symbol(buffer, ' ');
	length = StringLength(buffer);
	bool is_palindrome = true;
	for (int i = 0; i < length /2; i++)
	{
		if (buffer[i] != buffer[length - 1 - i])
		{
			is_palindrome = false;
			break;
		}
	}
	delete[] buffer;
	return is_palindrome;
}
bool Is_Int_Number(char str[])
{
	for (int i = 0; str[i]; i++) {
		if (str[i] == ' ' && str[i + 1] == ' ') return false;
		//if(!(str[i] >= '0' && str[i] <= '9'))
		if((str[i] < '0' && str[i] > '9') && str[i] != ' ')
		{
			return false;
		}	
		
	}
	return true;
}
int To_Int_Number(char str[])
{
	if (!Is_Int_Number(str)) return 0;
	int decimal = 0;			//Десятичное значение числа 

	for (int i=0; i <str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			decimal *= 10; //Сдвигаем число на 1 разряд влево
			decimal += str[i] - 48;
		}	
	}
	return decimal;
}
bool Is_Bin_Number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
			return false;
		if (str[i] == ' ' && str[i - 1] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}
void insert_spaces(char str[])
{
	for (int i = 1, digit=0; str[i]; i++)
	{
		if (digit % 4 == 0)
		{
			for (int j = strlen(str); j > 1; j--)
			{
				str[j] = str[j - 1];
			}
			str[i] = ' ';
		}
		digit++;
	}
}
char* Dec_To_Bin(int decimal)
{
	//1) Определим количество двоичных разрядов:
	int capacity = 0;
	int buffer = decimal;
	for (; buffer > 0; capacity++) {
		buffer /= 2;
		if (capacity % 4 == 0) capacity++;
	}
	//2) Выделяем память под двоичное число

	char* bin = new char[capacity + 1]{};
	//3) Получаем разряды двоичного числа и сохраняем их в строку
	for (int i = 0; decimal; i++)
	{
		if (i % 4 == 0)
		{
			bin[i++] = ' ';
		}
		else 
		{
			bin[i] = decimal % 2 + '0'; // Получаем младший разряд числа:
			decimal /= 2;				//Убираем младший разряд из числа
		}
	}
	//insert_spaces(str);
	return bin;
}
int Bin_To_Dec(char str[])
{
	if (!Is_Bin_Number(str))return 0;

#ifdef DEBUG
	int decimal = 0;  //Конечное десятичное число
	int weight = 1;   //Весовой коэффициент разряда 2^n; 
	int capacity = strlen(str); //Разрядность двоичного числа
	for (int i = capacity - 1; i >= 0; i--)
	{
		decimal +=
	}
#endif // DEBUG

	int decimal = 0; 
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ') {
			decimal *= 2;
			decimal += str[i] - '0';
		}
	}
	return decimal;
}

char* dec_to_hex(int decimal)
{
	int capacity = 0;
	int buffer = decimal;
	for (; buffer > 0; capacity++) 
	{
		buffer /= 16;
		if (buffer % 16 > 14) {
			capacity++;
		}
	}
	char* hex_arr = new char[capacity + 1]{};
	int num = 0;
	for (int i = 0; decimal >0; i++)
	{
		num = decimal % 16;
		decimal /= 16;
		switch (num)
		{
		case 10:
			hex_arr[i] = 'A';
			break;
		case 11:
			hex_arr[i] = 'B';
			break;
		case 12:
			hex_arr[i] = 'C';
			break;
		case 13:
			hex_arr[i] = 'D';
			break;
		case 14:
			hex_arr[i] = 'E';
			break;
		case 15:
			hex_arr[i] = 'F';
			break;
		default:
			hex_arr[i] = num + '0';
			break;
		}		
	}
	for (int i = capacity; i >= 0; i--)
	{
		cout << hex_arr[i];
	}

	delete[] hex_arr;
	return 0;
}
bool is_mac_address(char str[])
{
	int length = StringLength(str);
	bool max_address = false;
	if (length != 17)return max_address;
	else 
	{
		char* buffer = new char[length + 1]{};
		bool max_address = true;
		int b = 0;
		int j = 2;
		for (int i = 0; i < length; i++)
		{
			buffer[i] = str[i];
		}
		for (int i = 0; i < length; i++)
		{
			
			if (buffer[0] == '0' && buffer[i + 1] == 'X')
			{
				max_address = true;
				i++;
			}
			else if (
				(buffer[i] <= '9' && buffer[i] >= '0')
				)
			{
				max_address = true;
			}
			else if (buffer[i] > '@' && buffer[i] < 'G')
			{
				max_address = true;
			}
			else if ( buffer[j]== ':') 
			{
				j += 3;
				max_address = true;
			}
			else
			{
				max_address = false;
				break;
			}
		}
		delete[] buffer;
		return max_address;

	}	
}


#ifdef HOMETASK
void shrink(char str[])
{
	int length = StringLength(str);
	// ' ' = 32;
	int i = 0;

	while (str[0] == ' ') {
		for (int j = i; j < length; j++) {
			str[j] = str[j + 1];
		}
		//str[i] = str[i + 1];
		str[--length] = '\0';

	}

	for (; i < length;) {

		if (str[i] == ' ' && str[i + 1] == ' ') {
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
#endif // HOMETASK


void ASCII()
{
	for (int i = 0; i < 256; i++) {
		cout << i << "\t";
		cout << (char)i << endl;
	}
}
int StringLength_STL(char str[])
{
	int length = 0;
	length = strlen(str);

	return length;
}
void to_upper_STL(char str[])
{
	for (int i = 0; str[i]; i++) 
	{
		toupper(str[i]);
	}
}
void to_lower_STL(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		tolower(str[i]);
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


bool is_hex_num_STL(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!isxdigit(str[i]))
		{
			return false;
		}
	}
	

	return true;
}
long int hex_to_dec_STL(char hex[])
{
	if (!is_hex_num_STL(hex))return false;
	long int number = 0;
	number = strtol(hex, NULL, 16);

	return number;
}