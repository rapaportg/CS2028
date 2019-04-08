#ifndef HASHTABLE1D_H
#define HASHTABLE1D_H
#include "hashNode.h"
#include "linkList.h"

#define TABLE_SIZE 100

template<typename K, typename V> //K is int in this lab
class HashTable
{
    private:
        LinkList<HashNode<K,V>>     *table;
        K                           hashFn;
        K                           hash(string key);
        int                         count;

    public:
        HashTable();
        ~HashTable();
        void            addItem(V val);
        HashNode<K,V>   *removeItem(V val);
        HashNode<K,V>   getItem(V val);
        int             getLength();
        void            print();
};
#endif

template<typename K, typename V>
HashTable<K, V>::HashTable()
{
    Node<HashNode<K,V>>  *tmp;

    count = 0;
    *table = new LinkList<HashNode<K,V>>();

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        tmp = new Node<HashNode<K,V>>(i);
        table->addItem(tmp);
    }
}