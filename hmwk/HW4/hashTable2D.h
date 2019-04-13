#pragma
#ifndef HASHTABLE2D_H
#define HASHTABLE2D_H
#include "hashTable.h"
//#include "hashNode.h"
#include <iostream>

using namespace std;
///size 100 5

class HashTable2D: private HashTable
{
    private:
        HashNode<int>   **table;
        int             maxLength;
        int             maxDepth;
        int             hash(int in);

    public:
        HashTable2D(int len, int depth);
        //~HashTable2D();

        int             insert(int in);
        int             find(int in);
        int             remove(int in);
        void            print();
        int             getMaxLength();
        int             getMaxDepth();
};
#endif

HashTable2D::HashTable2D(int len, int depth)
{
    HashTable();
    maxLength = len;
    maxDepth = depth;
    table = new HashNode<int>*[len];
    for (int i = 0; i < len; i++)
    {
        table[i] = new HashNode<int>[depth];
    }
}

int HashTable2D::hash(int in)
{
    return in % (maxLength);
}

int HashTable2D::insert(int in)
{
    int     key = hash(in);
    int     i = -1;
    do
    {
        i++;
        if (table[key][i].getState() != 'f')
        {
            table[key][i].setVal(in);
            return i + 1;
        }

    }while (i < maxDepth);
    // throw FullBucketException();
    return i + 1; // if returned value is equal to maxDepth + 1, the bucket is full.
}

int HashTable2D::find(int in)
{
    int     key = hash(in);
    int     i = -1;

    do
    {
        i++;
        if (table[key][i].getVal() == in)
        {
            return i + 1;
        }

    }while (i < maxDepth);

    //throw NotInTableException();
    return i + 1; // if returned value is equal to maxDepth + 1, the value is not in the table
}

int HashTable2D::remove(int in)
{
    int     key = hash(in);
    int     i = -1;

    do
    {
        i++;
        if (table[key][i].getVal() == in)
        {
            table[key][i].setState('d');
            return i + 1;
        }

    }while(i < maxDepth);

    //throw NotInTableException();
    return i + 1; // if returned value is equal to maxDepth + 1, the value is not in the table
}

void HashTable2D::print()
{
    cout << endl;
    cout << "\nBUCKET|\tITEM->\n        ";
    for (int i = 0; i < maxDepth; i++)
    {
        cout << i+1 << "\t\t";
    }
    cout << endl;

    for (int i = 0; i < maxLength; i++)
    {
        cout << i + 1 << ". ";
        for (int j = 0; j < maxDepth; j++)
        {
            if (j == maxDepth - 1)
                if (table[i][j].getState() != 'f')
                    cout << "\tNULL";
                else
                    cout << "\t" << table[i][j].getVal();
            else
                if (table[i][j].getState() != 'f')
                    cout << "\tNULL\t|";
                else
                    cout << "\t" << table[i][j].getVal() << "\t|";
        }

        cout << endl << "-----====";


        for (int i = 0; i < maxDepth; i++)
        {
            cout << "==============";

        }

        cout << endl;
    }
    cout << endl;
}

int HashTable2D::getMaxLength()
{
    return maxLength;
}

int HashTable2D::getMaxDepth()
{
    return maxDepth;
}