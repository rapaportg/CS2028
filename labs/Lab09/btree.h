#ifndef BTREE_H
#define BTREE_H
#include "btnode.h"
#include <iostream>

using namespace std;

template<class T>
class BTree
{
    private:
        BTNode<T>   *root = nullptr;
        int         numElements;

    public:
        BTree<T>();
        void        insert(T val);                      // TODO: Rebalancing | NEEDS TESTING
        BTNode<T>   *find(T val);                       // DONE | NEEDS TESTING
        int         size();                             // DONE | NEEDS TESTING
        BTNode<T>   *getAllAscending();                 // TODO |
        void        getAllAscendingH(BTNode<T> *ptr, BTNode<T> **array);
        BTNode<T>   *getAllDescending();                // TODO |
        void        getAllDescendingH(BTNode<T> *ptr, BTNode<T> **array);
        void        emptyTree();                        // TODO |
        BTNode<T>   *remove(T val);                     // TODO |
        BTNode<T>   *findParent(T val, BTNode<T> *ptr); // TODO |
        void        rebalance();

};

#endif

template<class T>
BTree<T>::BTree()
{
    numElements = 0;
}

template<class T>
BTNode<T>   *BTree<T>::findParent(T val, BTNode<T> *ptr) // rewrite
{
    BTNode<T> *tmp;
    if (ptr == nullptr)
    {
        cout << "FP1" << endl;
        return nullptr;
    }
    if (ptr->getVal().compare(val) == 0)
    {
        cout << "FP2" << endl;
        return nullptr;
    }

    tmp = findParent(val, ptr->left);
    cout << "FP3" << endl;
    if ((tmp->left != nullptr && tmp->left->getVal().compare(val) == 0) && tmp != nullptr)
    {
        cout << "FP6" << endl;
        return tmp;
    }

    tmp = findParent(val, ptr->right);
    cout << "FP4" << endl;
    if ((tmp->right != nullptr && tmp->right->getVal().compare(val) == 0) ||(tmp->left != nullptr && tmp->left->getVal().compare(val) == 0))
    {
        cout << "FP5" << endl;
        return tmp;
    }

    return ptr;
}

template<class T>
void        BTree<T>::insert(T val) // Needs rebalancing
{
    BTNode<T>  *tmp;
    BTNode<T>  *newNode;
    if (root == nullptr)
    {
        cout << "insert 1" << endl;
        root = new BTNode<T>(val);
        numElements++;
    }
    else
    {
        tmp = findParent(val, root);
        if (tmp->getVal().compare(val) > 0)
        {
            if (tmp->left->getVal().compare(val) == 0)
            {
                cout << "insert 2" << endl;
                tmp->left->addFreq();
                return;
            }
            cout << "insert 3" << endl;
            newNode = new BTNode<T>(val);
            newNode->right = tmp->left->right;
            newNode->left = tmp->left->left;
            tmp->left = newNode;
            numElements++;
        }
        else
        {
            if (tmp->right->getVal().compare(val) == 0)
            {
                cout << "insert 4" << endl;
                tmp->right->addFreq();
                return;
            }
            cout << "insert 5" << endl;
            newNode = new BTNode<T>(val);
            newNode->right = tmp->right->right;
            newNode->left = tmp->right->left;
            tmp->right = newNode;
            numElements++;
        }
    }
   // rebalance();
}

template<class T>
BTNode<T>   *BTree<T>::find(T val)
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
void        BTree<T>::getAllAscendingH(BTNode<T> *ptr, BTNode<T> **array)
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

    getAllAscendingH(ptr->left, array);
    getAllAscendingH(ptr->right, array);
    *array++ = ptr;

    return;
}

template<class T>
BTNode<T>   *BTree<T>::getAllAscending()
{
    BTNode<T>  **array = new BTNode<T>[numElements];
    getAllAscendingH(root, array);
    return array;
}

template<class T>
void        BTree<T>::getAllDescendingH(BTNode<T> *ptr, BTNode<T> **array)
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

    getAllDescendingH(ptr->right, array);
    getAllDescendingH(ptr->left, array);
    *array++ = ptr;
    return;

}

template<class T>
BTNode<T>   *BTree<T>::getAllDescending()
{
    BTNode<T>  **array = new BTNode<T>[numElements];
    getAllAscendingH(root, array);
    return array;
}
