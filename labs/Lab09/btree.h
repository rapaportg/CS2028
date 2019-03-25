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
        void        Insert(T val);                      // TODO: Rebalancing | NEEDS TESTING
        BTNode<T>   *Find(T val);                       // DONE | NEEDS TESTING
        int         size();                             // DONE | NEEDS TESTING
        BTNode<T>   *GetAllAscending();                 // TODO |
        BTNode<T>   *GetAllDescending();                // TODO |
        void        EmptyTree();                        // TODO |
        BTNode<T>   *Remove(T val);                     // TODO |
        BTNode<T>   *findParent(T val, BTNode<T> *ptr); // TODO |

};

template<class T>
BTNode<T>   *BTree<T>::findParent(T val, BTNode<T> *ptr) // ptr is a copy of root
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
void        BTree<T>::Insert(T val) // Needs rebalancing
{
    BTNode<T>  *tmp;
    BTNode<T>  *newNode;
    if (root == nullptr)
    {
        root = BTNode<T>(val);
        size++;
    }
    else
    {
        tmp = root;
        tmp = findParent(val, tmp);
        if (tmp->getVal()->compare(val) > 0)
        {
            if (tmp->left->getVal()->compare(val) == 0)
            {
                tmp->left->addFreq();
                return;
            }
            newNode = new BTNode<T>(val);
            newNode->right = tmp->left->right;
            newNode->left = tmp->left->left;
            tmp->left = newNode;
        }
        else
        {
            if (tmp->right->getVal()->compare(val) == 0)
            {
                tmp->right->addFreq();
                return;
            }
            newNode = new BTNode<T>(val);
            newNode->right = tmp->right->right;
            newNode->left = tmp->right->left;
            tmp->right = newNode;
        }
    }
}

template<class T>
BTNode<T>   *BTree<T>::Find(T val)
{
    BTNode<T>  *ptr = root;
    ptr = findParent(val, ptr);
    if (ptr->left->getVal()->compare(val) == 0)
        return ptr->left;
    if (ptr->right->getVal()->compare(val) == 0)
        return ptr->right;
    return nullptr;
}

template<class T>
int     BTree<T>::size()
{
    return numElements;
}

#endif