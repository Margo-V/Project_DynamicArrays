#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

#define  tab "\t"
#define FIFTEENTH 

using namespace std;

void ASCII();

#ifdef FIFTEENTH
void initField();
void createField(int**& arr, int ROW, int COL);
void printField(int(& arr)[][],const int ROW, const int COL);
#endif // FIFTEENTH


void main() {

	setlocale(LC_ALL, "ru");

	initField();

	ASCII();

}

void ASCII()
{
	setlocale(LC_ALL, "C");
	for (int i = 0; i < 256; i++)
	{
		/*if (i % 16 == 0)cout << endl;
		cout << (char)i << " ";*/

		cout << i << tab << (char)i << endl;
	}
}

#ifdef FIFTEENTH
void initField()
{
	const int ROW = 5;
	const int COL = 5;
	int count = 1;
	char waste_block = ' ';

	int field[ROW][COL] =
	{
		{12, 2, 8, 10},
		{6, 11, 7, 13},
		{9, 4, 1, 15},
		{5, 14, 3, }
	};

	/*int** field = new int* [ROW] {};
	for (int i = 1; i < ROW; i++)
	{
		field[i] = new int[COL] {};
	}

	for (int i = 1; i < ROW; i++)
	{
		for (int j = 1; j < COL; j++)
		{
			field[i][j] = count;
			//field[i][j] = rand();
			count++;
		}
	}*/

	//createField(field, ROW, COL);
	printField(field, ROW, COL);

	/*for (int i = 1; i < ROW-1; i++)
	{
		delete[] field[i];
	}
	delete[] field;*/
}


void createField(int **&arr, int ROW, int COL)
{
	int field_size = 16;
	bool flag = false;

	srand(time(NULL));

	for (int i = 1; i < ROW; i++)
	{
		int j = rand()%15  + 1;

		int temp = arr[i][j];
		arr[i][j] =arr[i][j+1];
		arr[i][j+1] = temp;
		//if (i % 3== 0)arr[i][j] = arr[i+]
	}

	printField(arr, ROW, COL);
}


void printField(int (&arr)[][], const int ROW, const int COL)
{
	for (int i = 1; i < ROW; i++)
	{
		for (int j = 1; j < COL; j++)
		{
			cout << arr[i][j] << tab;
			//if (i == 4 && j == 4)field[4][3] = waste_block;
		}
		cout << endl;
	}
}
void playGame()
{
	char key;
	key = _getch();

}
#endif // FIFTEENTH
