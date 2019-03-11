# ifndef LINKLIST_H
#define LINKLIST_H

#include "node.h"
#include <iostream>

using namespace std;

template<class T>
class LinkList {
private:
	Node<T> *head = nullptr;
	int length=0;
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

	if (*(head->getItem()) > *(itemToAdd->getItem()))
	{
		itemToAdd->setNext(head);
		head = itemToAdd;
		length++;
		return;
	}
	Node<T> *parent = findParent(itemToAdd);
	
	if (parent->getNext() == nullptr) {
		//cout << "The added item has next value of:" << itemToAdd->getNext()<<"\n";
		parent->setNext(itemToAdd);
	}
	else
	{
		itemToAdd->setNext(parent->getNext());
		parent->setNext(itemToAdd);
	}
	length++;
}

template<class T>
Node<T> *LinkList<T>::findParent(Node<T> *itemToAdd) {
	Node<T> *ptr = head;
	T temp = *(itemToAdd->getItem());
	while(ptr->getNext() != nullptr) {
		if (*(ptr->getNext()->getItem())>temp) {
			//cout << "Returning the ptr item val " << *(ptr->getItem()) << " with next adress " << ptr->getNext() << "\n";
			return ptr;
		}
		ptr = ptr-> getNext();
	}
	//cout << "Returning the ptr item val "<< *(ptr->getItem()) <<" with next adress "<< ptr->getNext() <<"\n";
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
		cout << *(temp->getItem()) << " ";
		temp = temp->getNext();
	}
	cout << "\n";
}

#endif // 
