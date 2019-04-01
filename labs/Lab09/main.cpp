// Lab9attempt2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "btnode.h"
#include "btree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	BTNode<int> test(9);
	BTNode<string> *ptr;
	BTree<string> myTree;
	myTree.insert("jumped");
	myTree.insert("quick");
	myTree.insert("brown");
	myTree.insert("fox");
	myTree.insert("did");
	myTree.insert("over");
	myTree.insert("the");
	myTree.insert("lazy");
	myTree.insert("dog");
	myTree.printOrder(myTree.root);
	cout << "After deleting lazy  my order is: \n";
	ptr = myTree.find("lazy");
	myTree.printOrder(myTree.root);
	cout << "After deleting the  my order is: \n";
	ptr = myTree.find("the");
	myTree.printOrder(myTree.root);

	/*cout << "\n After deleting dog  my order is: \n";
	ptr = myTree.find("dog");
	myTree.printOrder(myTree.root);*/

}


