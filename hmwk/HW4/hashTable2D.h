#ifndef HASHTABLE2D_H
#define HASHTABLE2D_H
#include "hashNode.h"
#include <iostream>

using namespace std;
///size 100 5

class HashTable2D
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
    maxLength = len;
    maxDepth = depth;
    table = new HashNode<int>*[len];
    for (int i = 0; i < len; i++)
    {
        table[i] = new HashNode<int>[depth];
    }
}