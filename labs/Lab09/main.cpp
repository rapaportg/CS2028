// Lab9attempt2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"		// Kurt's precompiled header
#include "stdafx.h"		// Lando's precompiled header
#include "btnode.h"
#include "btree.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void printOrders(BTree<string> **tmp)
{
	cout << "Ascending\n";
	BTNode<string> **arr1 = (*tmp)->GetAllAscending();
	cout << "\n\nDescending\n";
	BTNode<string> **arr2 = (*tmp)->GetAllDescending();
}

void newWordComp(string word, BTree<string>* aTree)
{
	for (unsigned int i = 0; i < word.length(); ++i) 
	{
		word[i] = tolower(word[i]);			// converts word to lowercase
	}
	BTNode<string>* ptr = nullptr;
	
	ptr = aTree->find(word);	

	if (ptr != nullptr)
	{
		ptr->addFreq();
	}
	else
	{
		aTree->insert(word);
	}
	return;
}

string getFileName() 
{
	string input;
	bool check;

	do
	{
		cout << "Enter the name of the file: " << endl;
		cin >> input;
		ifstream f(input.c_str());
		check = f.good();
		if (check == false)
		{
			cout << "Error... File does not exist" << endl << endl;
		}

	} while (!check);
	return input;
}

BTree<string>* toTreeFromFile()
{
	BTree<string>* newTree = new BTree<string>;
	string word;
	char chr;
	string fileName;

	fileName = getFileName();
	ifstream inputFile;	
	inputFile.open(fileName.c_str());

	while (!inputFile.good())
	{
		cout << "Not a file, please re-enter a valid file name: " << endl;
		fileName = getFileName();
		inputFile.open(fileName.c_str());
	}
	while (!inputFile.eof())
	{
		chr = inputFile.get();

		while (chr == '\n' || chr == ' ')
		{
			chr = inputFile.get();			
			continue;
		}
		while (chr != ' ' && chr != '\n' && !inputFile.eof())
		{
			if (chr < 65 || chr > 122)
			{
				chr = inputFile.get();
				continue;
			}
			else
			{
				if (chr < 91 || chr > 96)
				{
					word = word + chr;
					chr = inputFile.get();
				}
				else
				{
					chr = inputFile.get();
					continue;
				}
			}
		}
		newWordComp(word, newTree);
		word.clear();
	}
	inputFile.close();
	return newTree;
}



int main()
{

	BTree<string> 	*myTree;
	BTNode<string> 	**tmp;
	char 			input;
	string			searchBuffer;

	myTree = toTreeFromFile();
	// myTree->printOrder(myTree->getRoot());

	cout << "Would you like to search for a word? Enter y for yes, anything else for no. " << endl;
	cin >> input;

	while (input == 'y')
	{
		cout << "What word would you like to search for? (All lower-case) " << endl;
		cin >> searchBuffer;
		myTree->searchTree(searchBuffer);
		cout << "Would you like to search again? Enter y for yes, anything else for no. " << endl;
		cin >> input;
	}

	cout << "\nWould you like to see the tree in ascending and desending order (Y/N): \n";
	cin >> input;

	if (input == 'Y' || input == 'y')
	{
		printOrders(&myTree);
	}

<<<<<<< HEAD
=======
	return 0;
>>>>>>> 58ced758a4f9e61c3751a469f00cab950c5585fe
}

