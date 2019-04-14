// Lab 10.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" 
#include <iostream>
#include <string>
//#include "hashTable.h"
#include "chainedHashTable.h"

using namespace std;

int menuTask3and4()
{
	int userChoice = 0;
	cout << "Please choose what you would like to do: " << endl << endl;
	cout << "Add an Item							Enter 1" << endl;
	cout << "Remove an Item							Enter 2" << endl;
	cout << "Get an Item							Enter 3" << endl;
	cout << "Print Hash Table						Enter 4" << endl;
	cout << "Get the length of the Table					Enter 5" << endl;
	cout << "Exit								Enter 6" << endl;
	while (1)
	{
		if (cin >> userChoice && !(userChoice > 6) && !(userChoice <= 0)) {
			break;
		}
		else {
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return userChoice;
}

int main()
{

	HashTable<string>   *table;
	table = new HashTable<string>();

	ChainedHashTable<string> *cTable;
	cTable = new ChainedHashTable<string>();

	int n = 0;
	int userInput = 0;
	int menuChoice = 0;
	int length = 0;
	bool menuLoop = true;
	string strTemp = "";
	HashNode<string>	 *node;

	cout << "For a Hash Table with Linear Probing \t\t Enter 1 " << endl;
	cout << "For a Chained Hash Table \t\t\t Enter 2 " << endl;
	cout << "To see a test of both and their performances \t Enter 3 " << endl;
	cout << "Exit \t\t\t\t\t\t Enter 4 " << endl;

	while (1)
	{
		if (cin >> n && !(n > 4) && !(n <= 0)) {
			break;
		}
		else {
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	switch (n)
	{
	case 1: 
		cout << endl << "You chose a Hash Table with Linear Probing - " << endl;
		while (menuLoop)
		{
			menuChoice = menuTask3and4();

			if (menuChoice == 1)
			{
				cout << "Type the string you would like to add: " << endl;
				cin >> strTemp;
				table->addItem(strTemp);
				cout << endl << strTemp << " has been added to the Hash Table. " << endl << endl;
			}
			else if (menuChoice == 2)
			{
				cout << "Type the item you would like to remove: " << endl;
				cin >> strTemp;
				node = table->removeItem(strTemp);
				if (node == nullptr)
				{
					continue;
				}
				else
				{
					cout << endl << strTemp << " has been removed from the Hash Table. " << endl << endl;
				}
			}
			else if (menuChoice == 3)
			{
				cout << "Type the item you would like to get: " << endl;
				cin >> strTemp;
				node = table->getItem(strTemp);
				if (node == nullptr)
				{
					continue;
				}
				else
				{
					cout << endl << "You got " << node->getVal() << " from the Hash Table. " << endl << endl;
				}
			}
			else if (menuChoice == 4)
			{
				table->print();
			}
			else if (menuChoice == 5)
			{
				length = table->getLength();
				cout << "The length of the Hash Table is: " << length << endl << endl;
			}
			else if (menuChoice == 6)
			{
				menuLoop = false;
			}
		}
	case 2: 
		cout << endl << "You chose a Chained Hash Table - " << endl;
		while (menuLoop)
		{
			menuChoice = menuTask3and4();

			if (menuChoice == 1)
			{
				cout << "Type the string you would like to add: " << endl;
				cin >> strTemp;
				cTable->addItem(strTemp);
				cout << endl << strTemp << " has been added to the Hash Table. " << endl << endl;
			}
			else if (menuChoice == 2)
			{
				cout << "Type the item you would like to remove: " << endl;
				cin >> strTemp;
				node = cTable->removeItem(strTemp);
				if (node == nullptr)
				{
					continue;
				}
				else
				{
					cout << endl << strTemp << " has been removed from the Hash Table. " << endl << endl;
				}
			}
			else if (menuChoice == 3)
			{
				cout << "Type the item you would like to get: " << endl;
				cin >> strTemp;
				node = cTable->getItem(strTemp);
				if (node == nullptr)
				{
					continue;
				}
				else
				{
					cout << endl << "You got " << node->getVal() << " from the Hash Table. " << endl << endl;
				}
			}
			else if (menuChoice == 4)
			{
				cTable->print();
			}
			else if (menuChoice == 5)
			{
				length = cTable->getLength();
				cout << "The length of the Hash Table is: " << length << endl << endl;
			}
			else if (menuChoice == 6)
			{
				menuLoop = false;
			}
		}
	case 3:
		cout << "Task 5 here" << endl;
		break;
	case 4:
		cout << "Goodbye! " << endl;
		break;
	default: 
		cout << "You chose no valid option!" << endl;
		break;			// this should never happen
	}

	
	return 0;
}
