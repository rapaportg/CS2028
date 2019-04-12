#ifndef HASHTABLE1D_H
#define HASHTABLE1D_H
#include "hashNode.h"
#include <iostream>


//size 500

class HashTable1D
{
    private:
        HashNode<int>   *table;
        int             len;
        int             maxSize = 500;
        int             hash(int in);

    public:
        HashTable1D();
        //~HashTable1D(); // still need to do

        int     insert(int in); // Status | Testing | IP
        int     find(int in);	// Status | Testing | TD
        int     remove(int in); // Status | Testing | TD
        void    print();	    // Status | Testing | TD

};
#endif
