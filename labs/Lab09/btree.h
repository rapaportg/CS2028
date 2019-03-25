#ifndef BTREE_H
#define BTREE_H
#include "node.h"

template<class T>
class BTree
{
    private:
        BTNode      *root = nullptr;
        int         size;

    public:
        void        Insert(T val);
        *BTNode     Find(T val);
        int         size();
        *BTNode     GetAllAscending();
        *BTNode     GetAllDescending();
        void        EmptyTree();
        *BTNode     Remove(T val);
        *BTNode     findParent(T val, BTNode *ptr);

};

template<class T>
BTNode *BTree<T>::findParent(T val, BTNode *ptr) // ptr is a copy of root
{
    BTNode *tmp;
    if (ptr == nullptr)
    {
        return nullptr;
    }
    if (ptr->data == val)
    {
        return nullptr;
    }
    tmp = findParent(val, ptr->left);
    if (tmp->left->data == val)
        return tmp;

    tmp = findParent(val, ptr->right);
    if (tmp->right->data == val || tmp->left == val)
        return tmp;

    return ptr;
}

template<class T>
void    BTree<T>::Insert(T val)
{
    BTNode  *tmp;
    if (root == nullptr)
    {
        root = BTNode(val);
        size++;
    }
    else
    {
        tmp = root;
        tmp = findParent
    }
}

#endif