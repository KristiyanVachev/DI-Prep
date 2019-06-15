// 2018-Jul.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int digitsCount(int num)
{
	int count = 1;

	while (num / 10 > 0) {
		count++;
		num = num / 10;
	}

	return count;
}

int firstIsLarger(int a, int b)
{
	int aLen = digitsCount(a);
	int bLen = digitsCount(b);

	//Make them the same lenght
	if (aLen > bLen)
	{
		int multiplier = 1;
		for (int i = 0; i < aLen - bLen; i++)
		{
			multiplier *= 10;
		}

		b *= multiplier;
	}
	else
	{
		int multiplier = 1;
		for (int i = 0; i < bLen - aLen; i++)
		{
			multiplier *= 10;
		}

		a *= multiplier;
	}

	//compare
	if (a > b)
	{
		return true;
	}

	return false;
}

void sortLex(int n, int arr[])
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			//compare both and switch
			if (firstIsLarger(arr[j], arr[j + 1]))
			{
				//switch
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	//int n = 6;
	//int arr[] = { 13, 14, 7, 2018, 9, 0 };

	int n = 10;
	int arr[] = { 13, 14, 7, 2018, 9, 0, 22222, 1999999, 442, 123};


	sortLex(n, arr);

	//print
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ' ';
	}
}
