# ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template<class T>
class Node {
private:
	Node<T> *next;
	T *item;

public:
	Node();
	Node(T *data);
	void 	setItem(T *data);
	void 	setNext(Node<T> *ptr);
	Node<T> *getNext();
	T 		*getItem();

};

template<class T>
T* Node<T>::getItem() {
	return item;
}

template<class T>
Node<T>* Node<T>::getNext()
{
	//cout << "Test?!?!?!?!? \n \n";
	return next;
}

template<class T>
Node<T>::Node(T *data)
{
	item = data;
	next = nullptr;
}

template<class T>
void Node<T>::setItem(T *data) {
	item=data;
}

template<class T>
void Node<T> ::setNext(Node<T> *ptr) {
	next = ptr;
}
#endif
