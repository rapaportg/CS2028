#ifndef CHAINEDHASHTABLE_H
#define CHAINEDHASHTABLE_H
#include <iostream>
#include <string>
//#include "hashNode.h"
#include "hashTable.h"
#include "linkList.h"

//#define TABLE_SIZE 10

using namespace std;

template<typename V>
class ChainedHashTable: protected HashTable<V>
{
    private:
        LinkList<HashNode<V>>      *table;
        int                        buckets;
        int                        hashC(V val);

    public:
        ChainedHashTable();
        ~ChainedHashTable();
        void                      addItem(V val);
        HashNode<V>               *removeItem(V val);
        HashNode<V>               *getItem(V val);
        int                       getLength();
        void                      print();
};

template<typename V>
ChainedHashTable<V>::ChainedHashTable()
{
    table = new LinkList<HashNode<V>>[TABLE_SIZE];
}

template<typename V>
int ChainedHashTable<V>::hashC(V val)
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

template<typename V>
void ChainedHashTable<V>::addItem(V val)
{
    int index = hashC(val);
    Node<HashNode<V>> *temp = new Node<HashNode<V>>();
    HashNode<V>       *lol = new HashNode<V>(val);
    temp->setItem(lol);
    table[index].addItem(temp);
    if (table[index].size() == 1)
        buckets++;
}

template<typename V>
HashNode<V>   *ChainedHashTable<V>::removeItem(V val)
{
    int         i;
    int         index = hashC(val);

    for (i = 0; i < table[index].size(); i++)
    {
        if (table[index].seeAt(i)->getVal() == val)
        {
            return table[index]->remove(i);
        }

    }
}

template<typename V>
int     ChainedHashTable<V>::getLength()
{
    int total;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        total += table[i]->size();
    }

    cout << "Buckets: " << buckets << "\nTotal Number of Items: " << total << endl;

}

template<typename V>
void    ChainedHashTable<V>::print()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "Bucket: " << i << ".\t";
        for (int j = 0; j < table[i].size(); j++)
        {
            cout << "---> " << table[i].seeAt(j)->getItem()->getVal();
        }
        cout << endl;
    }
}
#endif