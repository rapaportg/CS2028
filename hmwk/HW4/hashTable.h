#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "hashNode.h"
#include <iostream>


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
