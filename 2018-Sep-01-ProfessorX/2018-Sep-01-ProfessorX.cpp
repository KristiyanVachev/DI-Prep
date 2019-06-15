// 2018-Sep-01-ProfessorX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void revealPassword(int m, int n, char arr[20][30][100], int password[100])
{
	int nextPassInd = 0;
	int middleBookInd = n % 2 == 0 ? n / 2 - 1 : n / 2;

	//For each column
	for (int i = 0; i < m; i++)
	{
		bool isOrdered = true;

		//Check whether row is valid - alphabetically ordered.
		for (int j = 0; j < n - 1; j++)
		{		
			for (int k = 0; k < 100; k++)
			{
				if (arr[i][j][k] != arr[i][j + 1][k])
				{
					if (arr[i][j][k] > arr[i][j + 1][k])
					{
						isOrdered = false;
					}

					break;
				}
			}

			//If the row is not ordered in any step, we stop checking.
			if (isOrdered == false)
			{
				break;
			}
		}

		//If the row is valid, save the digits of the password
		if (isOrdered)
		{
			char* middleBook = arr[i][middleBookInd];
			
			int wordLen = 0;

			//Count the lenght of each word
			for (int l = 0; l < 100; l++)
			{
				//If the word has ended, save the lenght
				if (middleBook[l] == ' ' || middleBook[l] == '\0')
				{
					password[nextPassInd] = wordLen;
					nextPassInd++;
					wordLen = 0;
				}
				else 
				{
					wordLen++;
				}

				//Break if the title has finished
				if (middleBook[l] == '\0')
				{
					break;
				}
			}
		}
	}
	
	//Mark the end of the password array
	password[nextPassInd] = -1;
}

int main()
{
	//Input
	const int m = 3;
	const int n = 3;
	char arr[20][30][100] =
	{
		{{"Algebra"}, {"Analytical geometry"}, {"Mathematical analysis"}},
		{{"Programming basics"}, {"Object-oriented programming"}, {"Data structures and algorithms"}},
		{{"Databases"}, {"Intelligent systems"}, {"Xunctional programming"}},
	};

	//Reveal password
	int password[100];
	revealPassword(m, n, arr, password);

	//Print
	for (int i = 0; i < 100; i++)
	{
		if (password[i] == -1)
		{
			break;
		}

		std::cout << password[i] << ' ';
	}

}
