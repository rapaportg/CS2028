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
	Node<int> *myObject;
	LinkList<int> myList;

	for (int i = 0; i < 15; i++) {
		cout << "set value:";
		cin >> temp;
		ptr = new int(temp);
		myObject = new Node<int>(ptr);
		myList.addItem(myObject);
		myList.printList();
	}

}

