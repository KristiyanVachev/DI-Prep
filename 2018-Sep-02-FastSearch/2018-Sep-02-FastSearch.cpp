// 2018-Sep-02-FastSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

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

void readList()
{
	Node* head = new Node();

	std::ifstream file("Read.txt");
	std::string str;

	while (std::getline(file, str))
	{
		std::cout << str;
		
	}

	//read list
	//save n and k
}

bool isMember()
{
	return false;
}

int main()
{
	//read file
	readList();

	//construct list

    std::cout << "Hello World!\n"; 
}
