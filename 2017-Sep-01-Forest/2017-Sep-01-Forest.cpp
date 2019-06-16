#include <iostream>

//Recursive search in a matrix
int getArea(char arr[100][100], bool visited[100][100], int row, int col, int area)
{
	if (row >= 98 || row < 0 || col >= 98 || col < 0 || arr[row][col] != '4' || visited[row][col] == true)
	{
		return 0;
	}

	visited[row][col] = true;

	//Saving the area of the neighboring elements in a different counter, 
	//so that we can pass the same current area to each side
	int neighbourArea = 0;

	neighbourArea += getArea(arr, visited, row + 1, col, area);
	neighbourArea += getArea(arr, visited, row - 1, col, area);
	neighbourArea += getArea(arr, visited, row, col + 1, area);
	neighbourArea += getArea(arr, visited, row, col - 1, area);

	return area + neighbourArea;
}

//Finding the largest area
int findArea(char arr[100][100]) 
{
	int bestArea = 0;
	int currArea = 0;
	bool visited[100][100];

	//Check the area for each element in the matrix.
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			//If we encounter a NULL here, it means that there are no more filled cells to the right.
			if (arr[i][j] == NULL)
			{
				break;
			}

			if (arr[i][j] == '4')
			{
				currArea = getArea(arr, visited, i, j, 1);

				if (currArea > bestArea)
				{
					bestArea = currArea;
				}
			}
		}

		//If we encounter a NULL in the row, there are no more filled cells below or on the right.
		if (arr[i][0] == NULL)
		{
			break;
		}
	}

	return bestArea;
}

int main()
{
	//Making the array the max possible size. 
	//Something that is not declared == NULL.
	char arr[100][100] =
	{
		{'R', 'R', '1', '1', '2', '2'},
		{'1', '4', '4', '4', '1', '2'},
		{'4', '3', '3', 'R', '2', '3'},
		{'4', '4', '4', 'S', 'R', 'R'}
	};

	std::cout << findArea(arr) << std::endl;
}