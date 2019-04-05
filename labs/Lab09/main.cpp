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
	myTree.insert(3);
	myTree.insert(2);
	myTree.insert(1);
	myTree.printOrder(myTree.getRoot());
	myTree.rotateRight(myTree.getRoot(), myTree.getRoot()->left);
	cout << endl;
	myTree.printOrder(myTree.getRoot());

}
