#ifndef HASHTABLE1D_H
#define HASHTABLE1D_H
#include "hashNode.h"
#include "linkList.h"

#define TABLE_SIZE 100

template<typename K, typename V> //K is int in this lab
class HashTable
{
private:
	LinkList<HashNode<K, V>>    *table;
	K                           hash(V val);
	int                         count;

public:
	HashTable();
	~HashTable();
	void            			addItem(V val);
	HashNode<K, V>   			*removeItem(V val);
	HashNode<K, V>   			*getItem(V val);
	int             			getLength();
	void            			print();
};
#endif

template<typename K, typename V>
HashTable<K, V>::HashTable()
{
	Node<HashNode<K, V>>  		*tmp;

	count = 0;
	table = new LinkList<HashNode<K, V>>();

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		tmp = new Node<HashNode<K, V>>;
		table->addItem(tmp);
	}
}

template<typename K, typename V>
K HashTable< K, V>::hash(V val)
{
	int							ret;
	int							length;

	length = val.length();

	for (int i = 0; i < length; i++)
	{
		ret += val[i];
	}
	return ret % TABLE_SIZE;
}

template<typename K, typename V>
void HashTable<K, V>::addItem(V val)
{
	bool						flag = true;
	Node<HashNode<K, V>>			*temp;

	K hashVal = hash(val);

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

template<typename K, typename V>
HashNode<K, V> *HashTable<K, V>::removeItem(V val)
{
	int							counter;
	Node<HashNode<K, V>>		*temp;
	K 							hashVal;

	counter = 0;
	hashVal = hash(val);

	while (true)
	{
		if (counter > 99) // full table but no value
			return nullptr;

		temp = table->seeAt(hashVal);

		if (temp->getItem()->getState != 'd') // Is either full or emtpy , not deleted (if it is deleted we know to got to the next node)
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

template<typename K, typename V>
HashNode<K, V> *HashTable<K, V>::getItem(V val)
{
	int							counter;
	Node<HashNode<K, V>>		*temp;
	K 							hashVal;

	counter = 0;
	hashVal = hash(val);

	for (int counter = 0; counter < TABLE_SIZE; counter++)
	{
		temp = table->seeAt(hashVal);

		if (temp->getItem()->getState != 'd') // Is either full or emtpy , not deleted (if it is deleted we know to got to the next node)
		{
			if (temp->getItem()->getState() == 'f')
			{
				if (temp->getItem()->getVal() == val)
				{
					return temp->getItem();
				}
				else
				{
					hashVal = (hashVal + 1) % TABLE_SIZE; // linear probing
				}
			}
			else //This means we have an empty cell
			{
				return nullptr;
			}
		}
		else
		{
			hashVal = (hashVal + 1) % TABLE_SIZE; // linear probing
		}
	}

	return nullptr;
}

template<typename K, typename V>
int HashTable<K, V>::getLength() 
{
	return count;
}

template<typename K, typename V>
HashTable<K, V>::~HashTable()
{
	table->~LinkList();
}

template<typename K, typename V>
void HashTable<K,V>::print()
{
	HashNode<K,V>	*temp;


	for (int i = 0; i < TABLE_SIZE; i++) 
	{
		temp = table->seeAt(i);
		if (temp->getState() != 'f')
			cout << "EMPTY\t|\t";
		else
			cout << temp->getVal() << "\t|\t";
	}
	cout << "\n";
}
