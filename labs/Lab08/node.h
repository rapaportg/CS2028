# ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template<class T>
class Node {
private:

	
public:	
	Node<T> *next;
	T *item;
	Node();
	Node(T *data);
	void setItem(T *data);

};


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
#endif
