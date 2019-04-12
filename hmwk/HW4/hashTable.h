#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "hashNode.h"
#include <iostream>

using namespace std;
//size 500

class HashTable
{
    private:
        HashNode<int>   *table;
        int             len;
        int             maxSize = 500;
        int             hash(int in);

    public:
        HashTable();
        //~HashTable(); // still need to do

        int     insert(int in); // Status | Testing | IP
        int     find(int in);	// Status | Testing | TD
        int     remove(int in); // Status | Testing | TD
        void    print();	    // Status | Testing | TD

};
#endif


int HashTable::hash(int in)
{
    return in % maxSize;
}

HashTable::HashTable()
{
    table = new HashNode<int>[maxSize];
}

int HashTable::insert(int in)
{
    int i;
    int key = hash(in);

    for (i = 0; i < maxSize; i++)
    {
        if (table[key].getState() == 'f')
        {
            key = (key + 1) % maxSize;
        }
        else
        {
            table[key].setState('f');
            table[key].setVal(in);
            return i;
        }

    }
    return i; // if i is equal to maxSize then table is full

}

int HashTable::find(int in)
{
    int ret;
    int key = hash(in);

    for (ret = 0; ret < maxSize; ret++)
    {
        if (table[key].getVal() == in)
        {
            key = (key + 1) % maxSize;
        }
        else
        {
            return ret;
        }
    }
    return ret;  // if ret is equal to maxSize, then it is not in list
}

int HashTable::remove(int in)
{
    int i;
    int key = hash(in);

    for (i = 0; i < maxSize; i++)
    {
        if (table[key].getState() == 'f' && table[key].getVal() == in)
        {
            table[key].setState('d');
            return i;
        }
        else
        {
            key = (key + 1) % maxSize;
        }
    }
    return i; // if i is equal maxSize, then it is not in the table
}

void HashTable::print()
{
    for (int i = 0; i < maxSize; i++)
    {
        if (i % 10 == 0)
        {
            cout << "\\n";
        }
        if (table[i].getState() == 'f')
        {
            cout << table[i].getVal() << " | ";
        }
        else
        {
            cout << "EMPTY | ";
        }
    }
}