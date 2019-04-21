#ifndef LINKLIST_H
#define LINKLIST_H
#include "node.h"


template<class T>
class LinkList
{
    private:
		Node<T>		*head;
		int			length;

    public:
		class NotInList{};
		class OutOfBounds{};

		LinkList();
		void	addItem(T *item);
		void	removeItem(T *item);
		bool 	hasItem(T *item);
		int		size();
		Node<T>	*seeAt(int index);

};
#endif


template<class T>
int LinkList<T>::size()
{
	return length;
}

template<class T>
LinkList<T>::LinkList()
{
	head = nullptr;
	length = 0;
}

template<class T>
bool LinkList<T>::hasItem(T *item)
{
	Node<T> *tmp = head;
	while(tmp != nullptr)
	{
		if (*(tmp->getItem()) == *item)
			return true;

		tmp = tmp->getNext();
	}
	return false;
}

template<class T>
void LinkList<T>::addItem(T *item)
{
	Node<T> *tmp;
	Node<T> *newNode = new Node<T>(item);
	length++;

	if (head == nullptr)
	{
		head = newNode;

		return;
	}

	tmp = head;
	while (tmp->getNext() != nullptr)
	{
		tmp = tmp->getNext();
	}
	tmp->setNext(newNode);
	return;
}

template<class T>
void	LinkList<T>::removeItem(T *item)
{
	Node<T>	*tmp = head;
	Node<T> *toDel;

	if (head != nullptr && head->getItem() == item)
	{
		head = tmp->getNext();
		delete tmp;
		length--;
		return;
	}

	while (tmp->getNext() != nullptr && tmp->getNext()->getItem() != item)
	{
		tmp = tmp->getNext();
	}
	if (tmp->getNext() == nullptr)
	{
		throw NotInList();
	}
	else
	{
		toDel = tmp->getNext();
		tmp->setNext(toDel->getNext());
		delete toDel;
		length--;
		return;
	}
}

template<class T>
Node<T>	 *LinkList<T>::seeAt(int index)
{
	if (index > length)
	{
		throw OutOfBounds();
	}

	Node<T> *tmp = head;
	for (int i = 0; i < index; i++)
	{
		tmp = tmp->getNext();
	}
	return tmp;
}