#ifndef CHAINEDHASHTABLE_H
#define CHAINEDHASHTABLE_H
#include <iostream>
#include <string>
#include "hashTable.h"
#include "linkList.h"

#define TABLE_SIZE 10

using namespace std;

template<typename K, typename V>
class ChainedHashTable: public HashTable<K,V>
{
    private:
        LinkList<HashNode<K,V>>     *table;
        int                         count;

    public:
        ChainedHashTable();
        ~ChainedHashTable();
        void                        addItem(V val);
        void                        addItemDown(V val, HashNode<K,V> *parent);
        HashNode<K,V>               *removeItem(V val);
        HashNode<K,V>               *getItem(V val);
        int                         getLength();
        void                        print();
};

template<typename K, typename V>
void ChainedHashTable<K,V>::addItemDown(V val, HashNode<K,V> *parent)
{

}
#endif