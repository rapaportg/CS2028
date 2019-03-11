# ifndef LINKLIST_H
#define LINKLIST_H

#include "node.h"
#include <iostream>

using namespace std;

template<class T>
class LinkList {
private:
	Node<T> *head = nullptr;
	int length;
	Node<T> *findParent(Node<T> *itemToAdd);
public:
	class NoListException {};
	void addItem(Node<T> *itemToAdd);
	void printList();



};


template<class T>
void LinkList<T>::addItem(Node<T> *itemToAdd) {
	if (head == nullptr) {
		head = itemToAdd;		// IF head is empty adds to first element to list
		length++;
		return;
	}

	if (head->item > itemToAdd->item)
	{
		itemToAdd->next = head;
		head = itemToAdd;
		length++;
		return;
	}
	Node<T> *parent = findParent(itemToAdd);
	
	if (parent->next == nullptr) {
		parent->next = itemToAdd;
	}
	else
	{
		itemToAdd->next = parent->next;
		parent->next = itemToAdd;
	}
	length;
}

template<class T>
Node<T> *LinkList<T>::findParent(Node<T> *data) {
	Node<T> *ptr = head;
	while (ptr->next != nullptr && ptr->next->item > data->item)
	{
		ptr = ptr->next;
	}
	return ptr;
}

template<class T>
void LinkList<T>::printList() {
	if (length == 0) {
		cout << "Empty List \n";
		return;
	}
	Node<T> * temp = head;
	while (temp != nullptr) {
		cout << *temp->item << " ";
		temp = temp->next;
	}
	cout << "\n";
}

#endif // 
