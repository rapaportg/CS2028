// Lab9attempt2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include "btnode.h"
#include "btree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	BTNode<int> *ptr;
	BTree<int> myTree;
	/*
	myTree.insert("jumped");
	myTree.insert("quick");
	myTree.insert("brown");
	myTree.insert("fox");
	myTree.insert("did");
	myTree.insert("over");
	myTree.insert("the");
	myTree.insert("lazy");
	myTree.insert("dog");
	*/
	//
	/*
	myTree.insert(5);
	myTree.insert(4);
	myTree.insert(3);
	myTree.insert(7);
	myTree.insert(2);
	myTree.insert(1);
	*/

	int tmp;
	while(true)
	{
		cout << "Emter a value\n";
		cin >> tmp;
		myTree.insert(tmp);
	 	myTree.printOrder(myTree.getRoot());
	}


	//myTree.rotateRight(myTree.getRoot(), myTree.getRoot()->left);

	cout << endl;
	myTree.printOrder(myTree.getRoot());

}
