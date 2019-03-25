#ifndef BTREE_H
#define BTREE_H
#include "btnode.h"

template<class T>
class BTree
{
    private:
        BTNode<T>   *root = nullptr;
        int         numElements;

    public:
        void        Insert(T val);
        BTNode<T>   *Find(T val);
        int         size();
        BTNode<T>   *GetAllAscending();
        BTNode<T>   *GetAllDescending();
        void        EmptyTree();
        BTNode<T>   *Remove(T val);
        BTNode<T>   *findParent(T val, BTNode<T> *ptr);

};

template<class T>
BTNode<T> *BTree<T>::findParent(T val, BTNode<T> *ptr) // ptr is a copy of root
{
    BTNode<T> *tmp;
    if (ptr == nullptr)
    {
        return nullptr;
    }
    if (ptr->getVal()->compare(val) == 0)
    {
        return nullptr;
    }
    tmp = findParent(val, ptr->left);
    if (tmp->left->getVal()->compare(val) == 0)
        return tmp;

    tmp = findParent(val, ptr->right);
    if (tmp->right->getVal()->compare(val) == 0 || tmp->left->getVal()->compare(val) == 0)
        return tmp;

    return ptr;
}

template<class T>
void    BTree<T>::Insert(T val)
{
    BTNode<T>  *tmp;
    if (root == nullptr)
    {
        root = BTNode<T>(val);
        size++;
    }
    else
    {
        tmp = root;
        tmp = findParent(val, tmp);
        if (tmp->getVal()->compare(val) == 0)
            tmp->left = BTNode<T>(val);
        else
            tmp->rigth = BTNode<T>(val);
    }
}

#endif