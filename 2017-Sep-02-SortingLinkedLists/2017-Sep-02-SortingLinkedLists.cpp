#include <iostream>

//Template Node, to avoid making two - ints and LinkedLists
//Though it may get quite confusing and just writing two nodes may be better.
template <class type>
class Node
{
public:
	type value;
	Node<type>* next;

	Node(type value)
	{
		this->value = value;
		this->next = nullptr;
	}
};

//Also template, to show what type the nodes are going to be.
template <class type>
class LinkedList
{
public:
	Node<type>* head;
};

//Method for placing a new value in the LinkedList, while keeping it ordered.
void fillList(LinkedList<int>* list, int value)
{
	////Case A: New element must be head
	//Case 1: List is empty => just add it as head
	if (list->head == nullptr)
	{
		list->head = new Node<int>(value);
		return;
	}
	
	//Case 2: New value is smaller than the head => New head is assigned
	if (list->head->value > value)
	{
		Node<int>* newNode = new Node<int>(value);
		newNode->next = list->head;
		list->head = newNode;
		return;
	}

	////Case B: Not head => Check all the elements one by one until a larger element is found
	Node<int>* currNode = list->head;

	while (currNode != nullptr)
	{
		//Case 3: No larger element is found. Assign it at the end of the list
		if (currNode->next == nullptr)
		{
			currNode->next = new Node<int>(value);
			return;
		}

		//Case 4: The next element of the currentNode is larger => Place the new value in between
		if (currNode->next->value > value)
		{
			Node<int>* newNode = new Node<int>(value);
			newNode->next = currNode->next;
			currNode->next = newNode;
			return;
		}
		
		currNode = currNode->next;
	}
}

int main()
{
	//Constructing lists
	LinkedList<int>* list = new LinkedList<int>();
	list->head = new Node<int>(2);
	list->head->next = new Node<int>(3);
	list->head->next->next = new Node<int>(4);

	LinkedList<int>* list2 = new LinkedList<int>();
	list2->head = new Node<int>(5);
	list2->head->next = new Node<int>(1);
	list2->head->next->next = new Node<int>(8);

	LinkedList<LinkedList<int>*>* listlist = new LinkedList<LinkedList<int>*>();
	listlist->head = new Node<LinkedList<int>*>(list);
	listlist->head->next = new Node<LinkedList<int>*>(list2);
		
	//std::cout << listlist.head->value.head->value << std::endl;

	//Ordering lists - Create a new LinkedList and add every value from the other lists in order.
	LinkedList<int>* result = new LinkedList<int>();

	Node<LinkedList<int>*>* currList = listlist->head;

	while (currList != nullptr)
	{
		Node<int>* currNode = currList->value->head;

		while (currNode != nullptr)
		{
			fillList(result, currNode->value);

			currNode = currNode->next;
		}

		currList = currList->next;
	}

	//Print resut
	Node<int>* currNode = result->head;

	while (currNode != nullptr)
	{
		std::cout << currNode->value << std::endl;
		currNode = currNode->next;
	}
}