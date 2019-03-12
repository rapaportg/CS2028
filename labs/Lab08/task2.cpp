// lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "linkList.h"
#include "node.h"
#include <iostream>


using namespace std;



int main()
{
	int temp;
	int *ptr;
	int *ptr2;
	Node<int> *myObject;
	Node<int> *myObject2;
	LinkList<int> myList;

	for (int i = 0; i < 15; i++)
	{
		cout << "set value:";
		cin >> temp;

		ptr = new int(temp);
		myObject = new Node<int>(ptr);

		myList.addItem(myObject);
		myList.printList();
	}

	for (int j = 0; j < 15; j++)
	{
		cout << "what value do you want to remove? ";
		cin >> temp;

		ptr2 = new int(temp);
		myObject2 = new Node<int>(ptr2);

		if (myList.isInList(myObject2))
		{
			cout << "Removing " << *(myList.getListItem(myObject2))->getItem() << " from the list " << endl;
			myList.printList();
		}
		else
		{
			cout << "That item is not in the list! " << endl;
		}
	}

	if (myList.isEmpty())
	{
		cout << "isEmpty() works! the list was empty " << endl;
	}
	else if (!myList.isEmpty())
	{
		cout << "isEmpty() works! the list wasn't empty " << endl;
	}
	cout << "The size of the list is: " << myList.Size() << endl;

	return 0;
}

