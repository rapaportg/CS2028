#ifndef HASHTABLE1D_H
#define HASHTABLE1D_H
#include "hashNode.h"
#include "hashKey.h"

#define TABLE_SIZE 500

template<typename K, typename V, class Key = HashKey<K>>
class HashTable1
{
    private:
        HashNode<K, V>  **table;
        Key             hashFunction;
    public:
        HashTable1();
        void            insert(V val);
        int             find();
        int             remove(V val);
        void            print();
};
#endif

template<typename K, typename V, class Key>
HashTable1<K, V, Key>::HashTable1()
{
    table = new HashNode<K, V>*[TABLE_SIZE]();
}