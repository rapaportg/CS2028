#ifndef HASHTABLE1D_H
#define HASHTABLE1D_H
#include "hashNode.h"
#include "linkList.h"

#define TABLE_SIZE 100

template<typename K, typename V>
class HashTable
{
    private:
        LinkList<HashNode<K,V>>        *table;
        K                              hashFunction;
    public:
        HashTable();
        void            insert(V val);
        int             find();
        int             remove(V val);
        void            print();
};
#endif

template<typename K, typename V>
HashTable<K, V>::HashTable()
{
    Node<HashNode<K,V>>  *tmp;

    *table = new LinkList<HashNode<K,V>>();

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        tmp = new Node<HashNode<K,V>>();
        table->addItem(tmp);
    }
}