#ifndef BTREE_H
#define BTREE_H
#include "node.h"

template<class T>
class BTree
{
    private:
        Node    *root;
        int     size;

    public:
        void    Insert(T val);
        *Node   Find(T val);
        int     size();
        *Node   GetAllAscending();
        *Node   GetAllDescending();
        void    EmptyTree();
        *Node   Remove(T val);

};

#endif