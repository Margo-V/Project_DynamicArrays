#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");


	const int n = 256;

	/*char str[n]{};
	cout << "������� ������: "; cin >> str;
	cout << str << endl;
	cout << "������ ������: " << strlen(str) << endl;
	char str2[n]{};
	strcpy(str2, str);
	cout << "����� �����: " << str2 << endl;

	strcpy(str, "Hello");
	strcat(str, " ");
	strcat(str, "World");
	cout << str << endl;*/

	cout << strcmp("Hello", "World") << endl;
	const char* folders[] =
	{
		"addins",
		"download",
		"AppPatch",
		"debug",
		"assembler"
	};

	for (int i = 0; i < sizeof(folders) / sizeof(const char*); i++)
	{
		cout << folders[i] << endl;
	}
	for (int i = 0; i < size(folders); i++)
	{
		char buffer_i[n]{};
		strcpy(buffer_i, folders[i]);
		for (int j = 0; j < buffer_i[j]; j++)
		{
			buffer_i[j] = tolower(buffer_i[j]);
		}
		for (int j = i; j < size(folders); j++)
		{
			/*char buffer_j[n]{};
			strcpy(buffer_j, folders[j]);
			for (int i = 0; buffer_j[i]; i++)
			{
				buffer_j[i] = tolower(buffer_j[i]);
			}*/
			if (_strcmpi(folders[i], folders[j]) < 0)
			{
				const char* buffer = folders[i];
				folders[i] = folders[j];
				folders[j] = buffer;
			}
		}
	}
	cout << "\n-------------------\n\n";
	for (const char* i : folders)
	{
		cout << i << endl;
	}
}