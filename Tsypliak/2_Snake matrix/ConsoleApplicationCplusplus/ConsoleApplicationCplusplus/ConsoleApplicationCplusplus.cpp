// ConsoleApplicationCplusplus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
//підключення бібліотек 
using namespace std;

const int arraySize = 5;
const int arraySizeSingle = arraySize * arraySize;

void showArray(int arrayToShow[arraySize][arraySize], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			cout << arrayToShow[i][j] << "\t";
		}
		cout << "\n";
	}
}

int main()
{
	//випадкові числа
	srand(time(NULL));

	int testDate[arraySize][arraySize];
	int sortedArray[arraySizeSingle];
	int counter = arraySizeSingle;
	int choose = 1; 

	while (choose != 0) 
	{
		cout << "Type choise:\n";
		cout << "0. Quite. \n";
		cout << "1. Sequential array. \n";
		cout << "2. Random array. \n";
		cout << "3. Predifined array. \n";
		cin >> choose; 
		switch (choose)
		{
			default:
				choose = -1; 
				break;
			case 0:
				choose = -2;
				break;
			case 1:
				//input sequential numbers
				for (int i = 0; i < arraySize; i++)
				{
					for (int j = 0; j < arraySize; j++)
					{
						testDate[i][j] = counter;
						counter--;//counter=counter-1;
					}
				}
				break;
			case 2: 
				//input random values 
				for (int i = 0; i < arraySize; i++)
				{
					for (int j = 0; j < arraySize; j++)
					{
						testDate[i][j] = rand() % 1000 + 1;
					}
				}
				break;
			case 3:

				const int subSize = 5; 
				int a[subSize][subSize] = { 
			    { 0, 1, 2, 3, 4},
				{5, 6, 7, 8, 9},
				{10, 11, 12, 13, 14},
				{15, 16, 17, 18, 19},
				{20 , 21, 22, 23, 24 } };

				for (int i=0; i<= subSize; i++)
				{
					for (int j = 0; j <= subSize; j++)
					{
						testDate[i][j] = a[i][j];
					}
				}
				break;

		}

		if (choose == -2) {
			break;
		}
		else if (choose != -1)
		{
			//show
			showArray(testDate, arraySize);


			//to one array
			counter = 0;
			for (int i = 0; i < arraySize; i++)
			{
				for (int j = 0; j < arraySize; j++)
				{
					sortedArray[counter] = testDate[i][j];
					counter++;
				}
			}

			//sorting
			for (int i = 0; i < arraySizeSingle; i++)
			{
				for (int j = 0; j < arraySizeSingle - i - 1; j++)
				{
					if (sortedArray[j] > sortedArray[j + 1])
					{
						int c = sortedArray[j];
						sortedArray[j] = sortedArray[j + 1];
						sortedArray[j + 1] = c;
					}
				}
			}

			//change first half of matix 
			int diagonalCounter = 0;
			int totalCounter = 1;
			int matrixSize = arraySize;
			counter = 0;
			while (diagonalCounter < matrixSize)
			{
				int x;
				int y;
				if (diagonalCounter % 2 == 0)
				{

					y = diagonalCounter;
					x = 0;

					do
					{
						testDate[x][y] = sortedArray[counter];
						counter++;
						x++;
						y--;
					} while (y >= 0);
				}
				else
				{

					x = diagonalCounter;
					y = 0;

					do
					{
						testDate[x][y] = sortedArray[counter];
						counter++;
						x--;
						y++;
					} while (x >= 0);

				}
				diagonalCounter++;
			}

			//fill random second half of matrix
			counter = 1;
			for (int i = 1; i < arraySize; i++)
			{
				int  j = arraySize - 1;
				int rep = 0;
				while (rep < counter)
				{
					rep++;
					testDate[j][i] = testDate[i][j] = rand() % 1000 + 1;
					j--;
				}
				counter++;
			}

			cout << "\n" << "***" << "\n\n";
			showArray(testDate, arraySize);
			counter = arraySizeSingle;
		}
		
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
