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
	class	duplicateExeception {};

	BTree<T>(); // is the constructor
	void        insert(T val);                      					// Done (without any concern with rebalancing)|
	void		printOrder(BTNode<T> *cur);								// Used for testing. Can be modified for getALLAscending
	void		printPreOrder();										// Outputs "queue" to remake the same tree.
	void		printPostOrder();										// Outputs "stack" to remake the same tree.
	BTNode<T>   *find(T val);                      						// TODO |
	int         size();                             					// TODO |
	BTNode<T>   *GetAllAscending();                 					// TODO |
	void        GetAllAscendingH(BTNode<T> *ptr, BTNode<T> **array);	// TODO |
	BTNode<T>   *GetAllDescending();                					// TODO |
	void        GetAllDescendingH(BTNode<T> *ptr, BTNode<T> **array);	// TODO |
	void        emptyTree(BTNode<T>* ptr);                        					// Done
	BTNode<T>   *remove(T val);                     					// TODO |
	BTNode<T>   *findParent(T val); 					// TODO | // I don't think I am using this this method
	void        rebalance(BTNode<T> *parent);							// TODO |
	BTNode<T>	*getRoot();
	int			levels(BTNode<T> *parent);
	void		rotateLeft(BTNode<T> *parent, BTNode<T> *child);
	void		rotateRight(BTNode<T> *parent, BTNode<T> *child);

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
	while (!(temp->getVal() < val && temp->right == nullptr) && !(temp->getVal() > val && temp->left == nullptr) && temp->getVal() != val) {
		if (temp->getVal() < val)
			temp = temp->right;
		else
			temp = temp->left;
	}

	if (temp->getVal() == val) {
		throw duplicateExeception();
	}

	if (temp->getVal() < val)
	{
		temp->right = ptr;
		numElements++;
	}
	else
	{
		temp->left = ptr;
		numElements++;
	}

	rebalance(root);
}

template<class T>
void BTree<T> ::printNodeVal(BTNode<T> *nodePtr)
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
	bool parentFind;
	if (temp != nullptr)
	{
		parentFind = true;
	}
	else
	{
		return temp;
	}
	while (parentFind)
	{
		if (temp != nullptr && temp->left == nullptr && temp->right == nullptr)
		{
			return nullptr;
		}
		else if (temp != nullptr && temp->left == nullptr && temp->right != nullptr)
		{
			if (temp->getVal() < val && temp->right->getVal() != val)
			{
				temp = temp->right;
				continue;
			}
			else if (temp->getVal() < val && temp->right->getVal() == val)
			{
				return temp;
			}
			else
			{
				return nullptr;
			}
		}
		else if (temp != nullptr && temp->left != nullptr && temp->right == nullptr)
		{
			if (temp->getVal() > val && temp->left->getVal() != val)
			{
				temp = temp->left;
				continue;
			}
			else if (temp->getVal() > val && temp->left->getVal() == val)
			{
				return temp;
			}
			else
			{
				return nullptr;
			}
		}
		else
		{
			if (temp != nullptr && temp->left != nullptr && temp->right != nullptr && temp->left->getVal() != val && temp->right->getVal() != val)
			{
				if (temp->getVal() < val)
				{
					temp = temp->right;
					continue;
				}
				else
				{
					temp = temp->left;
					continue;
				}
			}
			else if (temp->left->getVal() == val || temp->right->getVal() == val)
			{
				return temp;
			}
		}
		parentFind = false;
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
int BTree<T>::levels(BTNode<T> *parent)
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
void BTree<T>::rotateRight(BTNode<T> *parent, BTNode<T> *child)
{

	if (parent == root)
	{
		 if (parent->left->left) // line rotation
		 {
			 parent->left = child->right;
			 child->right = parent;
			 root = child;
		 }
	}
	else 
	{
		BTNode<T>* grandParent = findParent(parent->getVal());
		if (grandParent->left == parent)
		{
			grandParent->left = child;
		}
		else 
		{
			grandParent->right = child;
		}
		parent->left = child->right;
		child->right = parent;
	}
}

template<class T>
void BTree<T>::rotateLeft(BTNode<T> *parent, BTNode<T> *child)  // needs checking
{

	if (parent == root)
	{
		{
			parent->right = child->left;
			child->left = parent;
			root = child;
		}
	}
	else 
	{
		BTNode<T>* grandParent = findParent(parent->getVal());
		if (grandParent->right == parent)
		{
			grandParent->right = child;
		}
		else
		{
			grandParent->left = child;
		}
		parent->right = child->left; // Tree 2
		child->left = parent;
	}
}

template<class T>
void	BTree<T>::rebalance(BTNode<T> *parent)
{
	int		levelR = 0;
	int		levelL = 0;
	int 	difference = 0;
	if (parent->left)
		rebalance(parent->left);
	if (parent->right)
		rebalance(parent->right);

	if (parent->right)
		levelR = 1 + levels(parent->right);
	cout << "The parent is:" << parent->getVal() << " and levelR is:" << levelR << "\n \n";
	if (parent->left)
		levelL = 1 + levels(parent->left);

	difference = levelR - levelL;

	
	if (1 < difference) // using wiki chart
	{
		levelR = 0;
		levelL = 0;
		if (parent->right->right) 
			levelR = 1 + levels(parent->right->right);
		if (parent->right->left)
			levelL = 1 + levels(parent->right->left);
		
		if (levelL < levelR) // right : right case
		{
			rotateLeft(parent,parent->right);
		}
		else // right : left case
		{
			rotateRight(parent->right, parent->right->left);
			rotateLeft(parent, parent->right);			
		}
	}
	else if (difference < -1) // left
	{
		levelR = 0;
		levelL = 0;
		if (parent->left->right)
			levelR = 1 + levels(parent->left->right);
		if (parent->left->left)
			levelL = 1 + levels(parent->left->left);
		if (levelR < levelL) // left : left case
		{
			rotateRight(parent, parent->left);
		}
		else// left right case
		{
			rotateLeft(parent->left, parent->left->right);
			rotateRight(parent, parent->left);
		}
	}
	return;
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
