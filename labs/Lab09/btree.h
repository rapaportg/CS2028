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
        void        GetAllAscendingH(BTNode<T> *ptr, BTNode<T> **array);
        BTNode<T>   *GetAllDescending();                // TODO |
        void        GetAllDescendingH(BTNode<T> *ptr, BTNode<T> **array);
        void        EmptyTree();                        // TODO |
        BTNode<T>   *Remove(T val);                     // TODO |
        BTNode<T>   *findParent(T val, BTNode<T> *ptr); // TODO |

};

template<class T>
BTNode<T>   *BTree<T>::findParent(T val, BTNode<T> *ptr)
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
    if (tmp->left->getVal()->compare(val) == 0 && tmp != nullptr)
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
        root = new BTNode<T>(val);
        size++;
    }
    else
    {
        tmp = findParent(val, root);
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
   // rebalance();
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

template<class T>
void        BTree<T>::GetAllAscendingH(BTNode<T> *ptr, BTNode<T> **array)
{
    if (ptr->right == nullptr)
    {
        *array++ = ptr;
        return;
    }
    if (ptr->left == nullptr)
    {
        *array++ = ptr;
        return;
    }
    GetAllAscendingH(ptr->left, array);
    GetAllAscendingH(ptr->right, array);
    *array++ = ptr;
    return;
}

template<class T>
BTNode<T>   *BTree<T>::GetAllAscending()
{

    BTNode<T>  **array = new BTNode<T>[numElements];
    GetAllAscendingH(root, array);
    return array;
}

template<class T>
void        BTree<T>::GetAllDescendingH(BTNode<T> *ptr, BTNode<T> **array)
{
    if (ptr->right == nullptr || ptr->right == *(array - 1)) // comparing addresses
    {
        *array++ = ptr;
        return;
    }
    if (ptr->left == nullptr || ptr->left == *(array - 1)) // comparing addresses
    {
        *array++ = ptr;
        return;
    }
    GetAllDescendingH(ptr->right, array);
    GetAllDescendingH(ptr->left, array);
    *array++ = ptr;
    return;
}

template<class T>
BTNode<T>   *BTree<T>::GetAllDescending()
{

    BTNode<T>  **array = new BTNode<T>[numElements];
    GetAllAscendingH(root, array);
    return array;
}

#endif