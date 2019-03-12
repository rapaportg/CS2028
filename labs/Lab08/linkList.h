# ifndef LINKLIST_H
#define LINKLIST_H

#include "node.h"
#include <iostream>

using namespace std;

template<class T>
class LinkList {
private:
	Node<T> *head = nullptr;
	int length = 0;
	Node<T> *findParent(Node<T> *itemToAdd);
public:
	class NoListException {};
	void addItem(Node<T> *itemToAdd);
	Node<T>* getListItem(Node<T> *itemToGet);
	bool isInList(Node<T> *itemToCheck);
	bool isEmpty();
	int Size();
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
Node<T> *LinkList<T>::getListItem(Node<T> *itemToGet)
{
	Node<T> *tmp1 = head;
	Node<T> *tmp2 = head->getNext();
	if (*(head->getItem()) == *(itemToGet->getItem()))
	{
		head = head->getNext();		// if item is in the first spot in the list, head->next becomes new head, return old head
		length--;
		return tmp1;
	}
	else
	{
		do
		{
			if (*(tmp2->getItem()) == *(itemToGet->getItem()))	// if item is in the current spot being checked, prev spot's next becomes current spot's next
			{							// return what's in the current spot
				tmp1->setNext(tmp2->getNext());
				length--;
				return tmp2;
			}
			else
			{
				if (tmp2->getNext() == nullptr)	// if current spot's next is null, it's the end of the list; return null
				{
					return nullptr;
				}
				tmp2 = tmp2->getNext();		// advances our current and prev spots
				tmp1 = tmp1->getNext();
			}
		} while (*(tmp1->getItem()) != *(itemToGet->getItem()));
		return nullptr;
	}
}

template<class T>
bool LinkList<T>::isInList(Node<T> *itemToCheck)	// Checks for item in current spot, then advances the current spot through the list as long as 
{							// current next is not null (end of the list)
	Node<T>* tmp = head;
	do
	{
		if (*(tmp->getItem()) == *(itemToCheck->getItem()))
		{
			return true;
		}
		if (tmp->getNext() != nullptr)
		{
			tmp = tmp->getNext();		
		}
	} while (tmp->getNext() != nullptr);

	return false;
}

template<class T>
bool LinkList<T>::isEmpty()
{
	if (head == nullptr)		
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
int LinkList<T>::Size()
{
	return length;
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
