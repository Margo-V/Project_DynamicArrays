#include <iostream>
#include <Windows.h>
#include <math.h>
#include <string.h>
using namespace std;
#define tab "\t";
//#define STRING_DECLARATION
//#define STRING_FUNCTIONS
//#define HOMETASK
//#define CHECK_1
#define BINERY

void ASCII();
int StringLength(char str[]);

void to_upper(char str[]);		// переводит строку в верхний регистр
void to_lower(char str[]);		// Переводит строку в нижний регистр
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
bool Is_Hex_number_2(char str[]);
int Hex_To_Dec_2(char hex[]);



bool is_hex_number(char str[]);// Проверяет, яв-ся ли функция шестнадацатиричным числом
int hex_to_dec(char str[]); //Если строка-16-ричное число, функция вернет его десятичное значение
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
	cout << "Строка " << str << (Is_Hex_number_2(str) ? "" : " НЕ") << " является шестнадцатеричным числом" << endl;
	cout << str << "(hex) = " << Hex_To_Dec_2(str) << "(dec)\n";


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
bool Is_Hex_number_2(char str[])
{
	for (int i = str[0] == '0' &&(str[1] =='x'||str[1]=='X') ? 2 : 0; str[i]; i++)
	{
		
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			!(str[i] >= 'a' && str[i] <= 'a')
			)
			return false;
	}
	return true;
}
int Hex_To_Dec_2(char hex[])
{
	if (!Is_Hex_number_2(hex)) return 0;
	int decimal = 0; 
	for (int i = 0; hex[i]; i++)
	{
		decimal *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')decimal += hex[i] - '0';
		if (hex[i] >= 'A' && hex[i] <= 'F')decimal += hex[i] - 'A' + 10;
		if (hex[i] >= 'a' && hex[i] <= 'f')decimal += hex[i] - 'a' + 10;
	}

	return decimal;
}


bool is_hex_number(char str[])
{
	int length = StringLength(str);
	char* buffer = new char[length + 1]{};

	for (int i = 0; i < length; i++)
	{
		buffer[i] = str[i];
	}

	bool hex_num = true;

	to_upper(buffer);

	for (int i = 0; i <length; i++) 
	{
		if (buffer[0] == '0' && buffer[i +1] == 'X')
		{
			hex_num = true;
			i++;
		}
		else if (!(
			(buffer[i] > '9' || buffer[i] < '0') &&
			buffer[i] != ' ')) 
		{
			hex_num = true;		
		}
		else if(buffer[i] >'@' && buffer[i] < 'G')
		{
			hex_num = true;
		}
		else 
		{
			hex_num = false;
			break;
		}
	}

	delete[] buffer;
	return hex_num;
}
int hex_to_dec(char str[])
{
	if(!(is_hex_number(str))) {
		return 0;
	}
	else 
	{
		int hex_num = 0, hex_num_to_dec =0;
		int length = StringLength(str);
		for (int i = 0; i < str[i]; i++)
		{
			//если введено число с приставкой 0x
			if (
				(str[0] == '0' && str[i + 1] == 'x') ||
				(str[0] == '0' && str[i + 1] == 'X')
				)
			{
				int* buffer1 = new int[length -2]{};

				for (int i = 0; i < length - 2; i++)
				{
					if (str[i + 2] > '@' && str[i + 2] < 'G')
					{
						switch (str[i + 2])
						{
						case 'A':
							buffer1[i] = (49 - '0') + (57 - '0');
							break;
						case 'B':
							buffer1[i] = (50 - '0') + (57 - '0');
							break;
						case 'C':
							buffer1[i] = (51 - '0') + (57 - '0');
							break;
						case 'D':
							buffer1[i] = (52 - '0') + (57 - '0');
							break;
						case 'E':
							buffer1[i] = (53 - '0') + (57 - '0');
							break;
						case 'F':
							buffer1[i] = (54 - '0') + (57 - '0');
							break;
						default:
							cout << endl;
						}
					}
					else if (str[i + 2] >= 'a' && str[i + 2] <= 'f')
					{
						switch (str[i+2])
						{
						case 'a':
							buffer1[i] = (49 - '0') + (57 - '0');
							break;
						case 'b':
							buffer1[i] = (50 - '0') + (57 - '0');
							break;
						case 'c':
							buffer1[i] = (51 - '0') + (57 - '0');
							break;
						case 'd':
							buffer1[i] = (52 - '0') + (57 - '0');
							break;
						case 'e':
							buffer1[i] = (53 - '0') + (57 - '0');
							break;
						case 'f':
							buffer1[i] = (54 - '0') + (57 - '0');
							break;
						default:
							cout << endl;
						}
					}
					else
					{
						buffer1[i] = str[i +2] - '0';
					}
				}

				for (int i = length - 3, j = 0; i >= 0; i--)
				{
					hex_num_to_dec += buffer1[i] * pow(16, j);
					//cout << "buffer1[" << i << "] * pow(16, " << j << ") = "<< buffer1[i] << " * " << pow(16, j) << " = " << buffer1[i] * pow(16, j) << endl;
					j++;
				}
				//cout << "hex_num_to_dec = " << hex_num_to_dec << endl;

				delete[] buffer1;
				return hex_num_to_dec;
			}
			else {
				//если введено число без приставки 0x
				int* buffer = new int[length + 1]{};

				//создаем массив числовых значений
				for (int i = 0; i < str[i]; i++)
				{
					if (str[i] > '@' && str[i] < 'G')
					{
						switch (str[i])
						{
						case 'A':
							buffer[i] = (49 - '0') + (57 - '0');
							break;
						case 'B':
							buffer[i] = (50 - '0') + (57 - '0');
							break;
						case 'C':
							buffer[i] = (51 - '0') + (57 - '0');
							break;
						case 'D':
							buffer[i] = (52 - '0') + (57 - '0');
							break;
						case 'E':
							buffer[i] = (53 - '0') + (57 - '0');
							break;
						case 'F':
							buffer[i] = (54 - '0') + (57 - '0');
							break;
						default:
							cout << endl;
						}
					}
					else if (str[i] >= 'a' && str[i] <= 'f')
					{
						switch (str[i])
						{
						case 'a':
							buffer[i] = (49 - '0') + (57 - '0');
							break;
						case 'b':
							buffer[i] = (50 - '0') + (57 - '0');
							break;
						case 'c':
							buffer[i] = (51 - '0') + (57 - '0');
							break;
						case 'd':
							buffer[i] = (52 - '0') + (57 - '0');
							break;
						case 'e':
							buffer[i] = (53 - '0') + (57 - '0');
							break;
						case 'f':
							buffer[i] = (54 - '0') + (57 - '0');
							break;
						default:
							cout << endl;
						}
					}
					else
					{
						buffer[i] = str[i] - '0';
					}
				}

				//высчитываем десятичное число
				for (int i = length - 1, j = 0; i >= 0; i--)
				{
					hex_num_to_dec += buffer[i] * pow(16, j);
					//cout << "buffer[" << i << "] * pow(16, " << j << ") = " << buffer[i] << " * " << pow(16, j) << " = " << buffer[i] * pow(16, j) << endl;
					j++;
				}
				//cout << "hex_num_to_dec = " << hex_num_to_dec << endl;


				delete[] buffer;
				return hex_num_to_dec;
			}
		}
	}
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