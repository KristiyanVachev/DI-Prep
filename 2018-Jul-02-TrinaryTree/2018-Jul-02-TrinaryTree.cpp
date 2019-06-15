// 2018-Jul-02-TrinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <fstream>

using namespace std;

//create trinary tree
class Node
{
public:
	char value;
	Node* left;
	Node* middle;
	Node* right;

	Node(char value)
	{
		this->value = value;
	}
};

class Trie
{
public:
	Node* head;

	Trie(Node* head)
	{
		this->head = head;
	}
};


std::string ReadLast(Trie* trie)
{
	int lastLevel = 0;
	std::string lastWord = "";

	//Queue to save the nodes for the BFS.
	//Using a tuple to also save the depth level. Tuples are... fun. https://en.cppreference.com/w/cpp/utility/tuple
	std::queue<std::tuple<Node*, int>> q;
	q.push(std::make_tuple(trie->head, 0));

	while (!q.empty())
	{
		//Get next node
		std::tuple<Node*, int> tuple = q.front();
		Node* v = std::get<0>(tuple);
		int currLevel = std::get<1>(tuple);
		q.pop();

		//Check if we have gone a level deeper
		if (lastLevel != currLevel)
		{
			//If we have, delete last word
			lastLevel = currLevel;
			lastWord = "";
		}

		//Append the letter to the last word
		lastWord += v->value;

		//Standart BFS; Add children to the queue.
		if (v->left != nullptr)
		{
			q.push(std::make_tuple(v->left, currLevel + 1));
		}
		if (v->middle != nullptr)
		{
			q.push(std::make_tuple(v->middle, currLevel + 1));
		}
		if (v->right != nullptr)
		{
			q.push(std::make_tuple(v->right, currLevel + 1));
		}
	}

	return lastWord;
}

//Serialize

class Text
{
public:
	std::string text = "";
};

//Go trough the elements with DFS, passing a reference to an object containing the string.
void DFS(Node* currNode, Text* text)
{
	//If the node is empty, save add the *
	if (currNode == nullptr)
	{
		text->text += ' ';
		text->text += '*';
		return;
	}

	//Else add the node value
	text->text += ' ';
	text->text += '(';
	text->text += currNode->value;

	//Go trough the other children, classic DFS way
	DFS(currNode->left, text);
	DFS(currNode->middle, text);
	DFS(currNode->right, text);
	
	text->text += ')';
}

void Serialize(Trie* trie, std::string file)
{
	Text* text = new Text();

	//Start traversing
	Node* currNode = trie->head;	
	DFS(currNode, text);

	//Save the text to a file
	std::ofstream out(file);
	out << text->text;
	out.close();
}

int main()
{
	////First trie
	//Node* head = new Node('k');

	//head->left = new Node('a');
	//head->middle = new Node('k');
	//head->right = new Node('o');

	//head->left->left = new Node('k');
	//head->left->right = new Node('o');
	//head->middle->middle = new Node('a');
	//head->right->middle = new Node('l');
	//head->right->right = new Node('a');

	//Trie* trie = new Trie(head);

	////Trie from the task
	Node* head = new Node('b');

	head->left = new Node('x');
	head->middle = new Node('y');

	head->left->left = new Node('p');
	head->left->middle = new Node('q');
	head->left->right = new Node('r');

	head->middle->right = new Node('s');
	
	head->left->right->left = new Node('c');
	head->left->right->right = new Node('a');

	head->middle->right->middle = new Node('t');

	Trie* trie = new Trie(head);

	//Read last
	std::string word = ReadLast(trie);
	std::cout << word << std::endl;

	//Serialize
	Serialize(trie, "output.txt");
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
