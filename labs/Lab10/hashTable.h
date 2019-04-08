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
        void            insert(V val)   // This function should return the number of spots it checks before inserting the item in the hash table so if it has no collisions, it should return 1 and if it has 3 collisions and then finds a spot on the 4th try, it return 4.
        int             find();         // returns the number of spots checked to find the value or determine its not in table
        int             remove(V val);  // Removes val found in table .returns the number of spots checked to find the value or determine its not in table
        void            print();        // prints all items in the hash table including an indication of which spots are not occupied.

};
#endif

template<typename K, typename V, class Key>
HashTable1<K, V, Key>::HashTable1()
{
    table = new HashNode<K, V>*[TABLE_SIZE]();
}