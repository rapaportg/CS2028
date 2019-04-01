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
		class	duplicateExeception();

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
		void        emptyTree();                        					// TODO |
		BTNode<T>   *remove(T val);                     					// TODO |
		BTNode<T>   *findParent(T val, BTNode<T> *ptr); 					// TODO | // I don't think I am using this this method
		void        rebalance();											// TODO |
		BTNode<T>	*getRoot();

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
void BTree<T> :: printNodeVal(BTNode<T> *nodePtr) {
	cout << nodePtr->getVal() << "\n";
}

template<class T>
void BTree<T> ::printOrder(BTNode<T> *cur) {
	if (cur != nullptr) {
		printOrder(cur->left);
		printNodeVal(cur);
		printOrder(cur->right);
	}
}

template<class T>
int BTree<T> ::numOfChildren(BTNode<T> * cur) {
	if (cur->left == nullptr && cur->right == nullptr) {
		return 0;
	}
	if (cur->left != nullptr && cur->right != nullptr) {
		return 2;
	}
	return 1;
}

template<class T>
BTNode<T>* BTree<T>::find(T val) {
	int 		num;
	BTNode<T>	*ptrToReturn;
	BTNode<T>	*temp = root;

	// below code finds node
	while (temp != nullptr && temp->left->getVal() != val && temp->right->getVal() != val)
	{
		if (temp->getVal() < val)
			temp = temp->right;
		else
			temp = temp->left;
	}

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

#endif
