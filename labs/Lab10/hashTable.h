#ifndef HASHTABLE1D_H
#define HASHTABLE1D_H
#include "hashNode.h"
#include "linkList.h"
#include <string>

#define TABLE_SIZE 100

template<typename V>		// For this lab V will be a string
class HashTable
{
    private:
        LinkList<HashNode<V>>		*table;
		int							hash(V val);
		int							count;
		int							testCounter;

    public:
        HashTable();											// Done
		~HashTable();											// Done
		void						addItem(V val);				// Done
		HashNode<V>					*removeItem(V val);			// Done
		HashNode<V>					*getItem(V val);			// Done
        void						print();					// Done
		int							getLength();				// Done
		int							getTestCounter();

};
#endif

template<typename V>
HashTable<V>::HashTable()						// Constructor
{
	Node<HashNode<V>>  		*tmp;
	HashNode<V>				*tmp2;
	testCounter = 0;

	count = 0;
	table = new LinkList<HashNode<V>>();

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		tmp = new Node<HashNode<V>>();
		tmp2 = new HashNode<V>();
		tmp->setItem(tmp2);
		table->addItem(tmp);
	}
}

template<typename V>
HashTable<V>::~HashTable()						// Destructor 
{													
	table->~LinkList();
}

template<typename V>					
int HashTable<V>::hash(V val)						// hash
{
	int							ret = 0;
	int							length;

	length = val.length();

	for (int i = 0; i < length; i++)
	{
		ret += val[i];
	}
	return ret % TABLE_SIZE;
}

template<typename V>					// add Item
void HashTable<V>::addItem(V val)
{
	bool						flag = true;
	Node<HashNode<V>>			*temp;

	int hashVal = hash(val);

	if (count > 99)
		return; // Table Is Full Do we have to let the user known??????????

	while (flag)
	{
		temp = table->seeAt(hashVal);
		if (temp->getItem()->getState() != 'f') // the cell is empty
		{
			temp->getItem()->setVal(val);
			temp->getItem()->setState('f');
			count++;
			flag = false;
		}
		else
		{
			hashVal = (hashVal + 1) % TABLE_SIZE; // linear probing
		}
	}
}

template<typename V>					// remove Item
HashNode<V> *HashTable<V>::removeItem(V val)
{
	int								counter;
	Node<HashNode<V>>				*temp;
	int 							hashVal;

	counter = 0;
	hashVal = hash(val);

	while (true)
	{
		if (counter > 99) // full table but no value
		{
			cout << "That item is not in the Hash Table! " << endl;
			return nullptr;
		}
		temp = table->seeAt(hashVal);

		if (temp->getItem()->getState() != 'd') // Is either full or emtpy , not deleted (if it is deleted we know to go to the next node)
		{
			if (temp->getItem()->getState() == 'f')
			{
				if (temp->getItem()->getVal() == val)
				{
					temp->getItem()->setState('d');
					count--; // the number of element in table decreased by one
					return temp->getItem();// TO DO!!!!!!!!!!!!
				}
				else
				{
					hashVal = (hashVal + 1) % TABLE_SIZE; // linear probing
				}
			}
			else //This means we have an empty cell
			{
				cout << "That item is not in the Hash Table! " << endl;
				return nullptr;
			}
		}
		else
		{
			hashVal = (hashVal + 1) % TABLE_SIZE; // linear probing
		}
		counter++; // we have to do linear probing
	}
}

template<typename V>					// get Item
HashNode<V> *HashTable<V>::getItem(V val)
{
	int							counter;
	Node<HashNode<V>>			*temp;
	int							hashVal;

	counter = 0;
	hashVal = hash(val);

	for (int counter = 0; counter < TABLE_SIZE; counter++)
	{
		temp = table->seeAt(hashVal);

		if (temp->getItem()->getState() != 'd') // Is either full or emtpy , not deleted (if it is deleted we know to got to the next node)
		{
			if (temp->getItem()->getState() == 'f')
			{
				if (temp->getItem()->getVal() == val)
				{
					return temp->getItem();
				}
				else
				{
					testCounter++;
					hashVal = (hashVal + 1) % TABLE_SIZE; // linear probing
				}
			}
			else //This means we have an empty cell
			{
				cout << "That item is not in the Hash Table! " << endl;
				return nullptr;
			}
		}
		else
		{
			testCounter++;
			hashVal = (hashVal + 1) % TABLE_SIZE; // linear probing
		}
	}
	cout << "That item is not in the Hash Table! " << endl;
	return nullptr;
}

template<typename V>					// print
void HashTable<V>::print()
{
	HashNode<V>	*temp;

	temp = table->seeAt(0)->getItem();
	cout << temp->getVal();

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		temp = table->seeAt(i)->getItem();
		if (temp->getState() != 'f')
			cout << "EMPTY\t|\t";
		else
			cout << temp->getVal() << "\t|\t";
	}
	cout << "\n";
}

template<typename V>					// get Length
int HashTable<V>::getLength()
{
	return count;
}

template<typename V>
int HashTable<V>::getTestCounter()
{
	return testCounter;
}
