#ifndef BTREE_H
#define BTREE_H
#include "btnode.h"
#include <iostream>

using namespace std;

template<class T>
class BTree
{
	private:
		//BTNode<T>   *root = nullptr;
		void		printNodeVal(BTNode<T> *nodePtr);
		int         numElements;
		int			numOfChildren(BTNode<T> *cur);
		BTNode<T>   *root = nullptr;

	public:
		class	duplicateExeception{};

		BTree<T>(); // is the constructor
		void        insert(T val);                      					// Done (without any concern with rebalancing)|
		void		printOrder(BTNode<T> *cur);								// Used for testing. Can be modified for getALLAscending
		void		printPreOrder();										// Outputs "queue" to remake the same tree.
		void		printPostOrder();										// Outputs "stack" to remake the same tree.
		BTNode<T>   *find(T val);                      						// TODO |
		int         size();                             					// TODO |
		BTNode<T>   *getAllAscending();                 					// TODO |
		void        getAllAscendingH(BTNode<T> *ptr, BTNode<T> **array);	// TODO |
		BTNode<T>   *getAllDescending();                					// TODO |
		void        getAllDescendingH(BTNode<T> *ptr, BTNode<T> **array);	// TODO |
		void        emptyTree(BTNode<T>* ptr);                        					// Done
		BTNode<T>   *remove(T val);                     					// TODO |
		BTNode<T>   *findParent(T val); 					// TODO | // I don't think I am using this this method
		void        rebalance(BTNode<T> *parent);							// TODO |
		BTNode<T>	*getRoot();
		int			levels(BTNode<T> *parent);
		void		rotateRight(BTNode<T> *parent, BTNode<T> *child);
		void		rotateLeft(BTNode<T> *parent, BTNode<T> *child);

};

template<class T>
BTree<T>::BTree()
{
	numElements = 0;
}

template<class T>
void BTree<T>::insert(T val)
 {                                          // if dupicate val then added to feq
	BTNode<T>	*ptr;
	ptr = new BTNode<T>(val); // create a node with val and ptr points at that node
	if (root == nullptr) {
		root = ptr;
		numElements++;
		return;
	}
	BTNode<T> *temp = root;
	// Below loop will take temp to the approiate node.
	while ( !(temp->getVal()<val && temp->right == nullptr) && !(temp->getVal() > val && temp->left == nullptr) && temp->getVal() != val){
		if (temp->getVal() < val)
			temp = temp->right;
		else
			temp = temp->left;
	}

	if (temp->getVal() == val) {
		throw duplicateExeception();
	}

	if (temp->getVal() < val) {
		temp->right = ptr;
		numElements++;
		return;
	}

	temp->left = ptr;
	numElements++;
}

template<class T>
void BTree<T> :: printNodeVal(BTNode<T> *nodePtr)
{
	if (nodePtr->left && nodePtr->right)
	{
		cout << nodePtr->getVal() << '\t' << nodePtr->left->getVal() << '\t' << nodePtr->right->getVal() << "\n";
	}
	else if (nodePtr->left && !nodePtr->right)
	{
		cout << nodePtr->getVal() << '\t' << nodePtr->left->getVal() << '\t' << "EMPTY" << "\n";
	}
	else if (!nodePtr->left && nodePtr->right)
	{
		cout << nodePtr->getVal() << '\t' << "EMPTY" << '\t' << nodePtr->right->getVal() << "\n";
	}
	else
	{
		cout << nodePtr->getVal() << '\t' << "EMPTY" << '\t' << "EMPTY" << "\n";
	}

}

template<class T>
void BTree<T>::printOrder(BTNode<T> *cur) {
	if (cur != nullptr)
	{
		printNodeVal(cur);
		printOrder(cur->left);
		printOrder(cur->right);
	}
}

template<class T>
int BTree<T>::numOfChildren(BTNode<T> * cur) {
	if (cur->left == nullptr && cur->right == nullptr) {
		return 0;
	}
	if (cur->left != nullptr && cur->right != nullptr) {
		return 2;
	}
	return 1;
}

template<class T>
BTNode<T> *BTree<T>::findParent(T val)
{
	BTNode<T> *temp = root;

	while (temp != nullptr && temp->left->getVal() != val && temp->right->getVal() != val)
	{
		if (temp->getVal() < val)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return temp;

}

template<class T>
BTNode<T>* BTree<T>::find(T val) {
	BTNode<T>	*ptrToReturn;
	BTNode<T>	*temp = findParent(val);

	if ((temp->left != nullptr) && (temp->left->getVal()) == val)
	{
		return temp->left;
	}
	else if ((temp->right != nullptr) && (temp->right->getVal()) == val)
	{
		return temp->right;
	}
	else
	{
		return nullptr;
	}
}

template<class T>
BTNode<T>	*BTree<T>::getRoot()
{
	return root;
}

template<class T>
BTNode<T>   *BTree<T>::remove(T val)
{
	BTNode<T> 	*tmp = findParent(val);
	BTNode<T> 	*ret;
	int			num;

	if (!tmp)
	{
		return nullptr;
	}

	if (tmp->right != nullptr && tmp->right->getVal() == val)
	{
		num = numOfChildren(tmp->right);

		if (num == 0)
		{
			ret = tmp->right;
			tmp->right = nullptr;
			return ret;
		}
		if (num == 1)
		{
			ret = tmp->right;
			if (tmp->right->right)
			{
				tmp->right = ret->right;
			}
			else
			{
				tmp->right = ret->left;
			}
			return ret;
		}
		if (num == 2)
		{
			/// Will do after rebalance function
		}

	}
	if (tmp->left != nullptr && tmp->left->getVal() == val)
	{
		num = numOfChildren(tmp->left);


		// Needs finishing

	}

}

template<class T>
int BTree<T>::levels (BTNode<T> *parent)
{
    int RLevels = 0;
    int LLevels = 0;
    if (parent->left != nullptr)
    {
        LLevels = 1 + levels(parent->left);
    }
    if (parent->right != nullptr)
    {
        RLevels = 1 + levels(parent->right);
    }
	return (LLevels >= RLevels ? LLevels : RLevels); // return max(LLevels, RLevels)
}

template<class T>
void BTree<T>::rotateLeft(BTNode<T> *parent, BTNode<T> *child)
{
	BTNode<T> *T1;
	BTNode<T> *T2;
	BTNode<T> *T3;

	if (child == root)
	{
		cout << "Child = root" << endl;
		return;
	}
    else if (parent->right == child)
    {
		T1 = parent->left;
		T2 = child->left;
		T3 = child->right;

		parent->left = T1;
		parent->right = T2;
		child->left = parent;
		child->right = T3;
    }
    else
	{
		rotateRight(parent, child);
    }
}

template<class T>
void BTree<T>::rotateRight(BTNode<T> *parent, BTNode<T> *child)  // needs checking
{
	BTNode<T> *T1;
	BTNode<T> *T2;
	BTNode<T> *T3;

	if (child == root)
	{
		cout << "Child = root" << endl;
		return;
	}
    else if (parent->left == child)
    {
		T1 = child->left;
		T2 = child->right;
		T3 = parent->right;

		parent->left = T1;
		parent->right = child;
		child->left = T2;
		child->right = T3;
    }
    else
	{
		rotateLeft(parent, child);
    }
}

template<class T>
void	BTree<T>::rebalance(BTNode<T> *parent)
{
	int		levelR = 1 + levels(parent->right);
	int		levelL = 1 + levels(parent->left);
	int 	difference = levelL - levelR;

	if (difference < -1 || difference > 1)				// Needs to be rebalanced if true
	{
		if (parent->left != nullptr)
		{
			rebalance(parent->left);
			rebalance(parent->right);
		}
		if (levelL > levelR)
			rotateRight(parent, parent->left);
		else
			rotateLeft(parent, parent->right);
	}
}

template<class T>
void BTree<T>::emptyTree(BTNode<T>* ptr)
{
	if (ptr == nullptr)
	{
		return;
	}

	emptyTree(ptr->left);
	emptyTree(ptr->right);
	delete ptr;
}


#endif
