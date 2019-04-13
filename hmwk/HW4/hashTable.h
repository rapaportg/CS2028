#pragma
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
        int             maxSize;
        int             hash(int in);

    public:
        HashTable();
        HashTable(int size);
        //~HashTable(); // still need to do

        int             insert(int in); // Status | Testing | IP
        int             find(int in);	// Status | Testing | TD
        int             remove(int in); // Status | Testing | TD
        void            print();	    // Status | Testing | TD
        void            reset();
        int             getMaxSize();

};
#endif

HashTable::HashTable()
{
    table = nullptr;
    maxSize = 0;
}

int HashTable::getMaxSize()
{
    return maxSize;
}

int HashTable::hash(int in)
{
    return in % maxSize;
}

HashTable::HashTable(int size)
{
    maxSize = size;
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
            return i+1;
        }

    }
    return i+1; // if i is equal to maxSize + 1 then table is full

}

int HashTable::find(int in)
{
    int ret;
    int key = hash(in);

    for (ret = 0; ret < maxSize; ret++)
    {
        if (table[key].getState() == 'f' && table[key].getVal() == in)
        {
            return ret + 1;
        }
        else
        {
            key = (key + 1) % maxSize;
        }
    }
    return maxSize + 2;  // if ret is equal to maxSize + 1, then the input is not in list
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
            return i+1;
        }
        else
        {
            key = (key + 1) % maxSize;
        }
    }
    return maxSize + 2; // if ret is equal maxSize + 1, then it is not in the table
}

void HashTable::print()
{
    cout << endl;
    for (int i = 0; i < maxSize; i++)
    {
        if (i % 10 == 0)
            cout << endl << "|\t";

        if (table[i].getState() == 'f')
        {
            cout << table[i].getVal() << "\t|\t";
        }
        else
        {
            cout << "EMPTY\t|\t";
        }
    }
    cout << endl << endl;
}

void HashTable::reset()
{
    for (int i = 0; i < maxSize; i++)
    {
        table[i].setState('e');
    }
}