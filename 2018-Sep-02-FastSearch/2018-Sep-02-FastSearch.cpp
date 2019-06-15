// 2018-Sep-02-FastSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

class Node
{
public:
	int value;
	Node* next;
	Node* nextK;
};

class List
{
public:
	int n;
	int k;
	Node* head;
};

List* readList()
{
	Node* head = new Node();	
	List* list = new List();
	list->head = head;

	Node* currNode = head;
	int numberCount = 0;

	////Reading it with strings. Don't know any other way that wont take 3 hours to write.
	std::ifstream file("Read.txt");
	std::string str;

	while (std::getline(file, str))
	{
		std::string currNum = "";

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				//Convert to int and clear the currNum
				int num = std::stoi(currNum, nullptr, 10);
				currNum = "";

				//Save the value
				currNode->value = num;

				//Create a new node and set it as next
				Node* newNode = new Node();
				currNode->next = newNode;

				//Point to the new node as current
				currNode = newNode;

				numberCount++;
			}
			else
			{
				currNum += str[i];
			}	
		}
	}

	////Save n and k
	list->n = numberCount;
	list->k = std::sqrt(numberCount);

	//Or if you must do it without sqrt;
	for (int i = 2; i < 1000; i++)
	{
		if (i * i > list->n)
		{
			list->k = i - 1;
			break;
		}
	}

	////Connect every k-th node
	Node* lastNode = list->head;
	currNode = list->head;

	for (int i = 1; i <= list->n; i++)
	{
		currNode = currNode->next;

		if (i % list->k == 0)
		{
			lastNode->nextK = currNode;
			lastNode = currNode;
		}
	}

	return list;
}

bool isMember(List* list, int n)
{
	Node* currNode = list->head;
	
	while (true)
	{	
		//// Part 1: Checking every K-th element.
		// Check if the current K-th element is the solution
		if (currNode->value == n)
		{
			return true;
		}

		// If the element we seek is smaller than the NextK, we continue traversing by k.
		if (currNode->nextK != nullptr && currNode->nextK->value < n)
		{
			currNode = currNode->nextK;
		}
		//If it's not, then it is on the left of the list. We start checking every next element.
		else 
		{		
			//// Part 2: Checking every next element.
			while (true)
			{
				if (currNode->value == n)
				{
					return true;
				}

				//If there are no more next elements or the next element is larger, the element is not in the list.
				if (currNode->next == nullptr || currNode->next->value > n)
				{
					return false;
				}

				//Else, we continue checking each net element.
				currNode = currNode->next;
			}
		}
	}

	return false;
}

int main()
{
	//Read file
	List* list = readList();
	std::cout << list->head->nextK->nextK->nextK->value << std::endl;

	//Is member
	std::cout << isMember(list, 10) << std::endl;
}
