#ifndef __QUEUE_H
#define __QUEUE_H
#include "node.h"
#include <iostream>

template<class T>
class Queue
{
    private:
        Node<T>     *front;
        Node<T>     *back;
        int         len;

    public:
        class       UnderFlow{};
        Queue();

        void        enqueue(T item);
        T           dequeue();
        T           peekFront();
        bool        isEmpty();
        void        print();
        int         length();

};

#endif

template<class T>
Queue<T>::Queue()
{
    front = nullptr;
    back = nullptr;
    len = 0;
}

template<class T>
void    Queue<T>::enqueue(T item)
{
    Node<T>     *tmp = new Node<T>(item);

    len++;

    if (front == nullptr)
    {
        front = tmp;
        back = tmp;
        return;
    }
    back->next = tmp;
    back = tmp;
    return;
}

template<class T>
T   Queue<T>::dequeue()
{
    T           ret;
    Node<T>     *tmp;

    if (isEmpty())
        throw UnderFlow();

    len--;
    tmp = front;
    front = front->next;
    ret = tmp->getVal();
    delete tmp;
    return ret;
}

template<class T>
T     Queue<T>::peekFront()
{
    return front->getVal();
}

template<class T>
bool    Queue<T>::isEmpty()
{
    return len <= 0;
}

template<class T>
void    Queue<T>::print()
{
    Node<T> *tmp = front;

    for (int i = 0; i < len; i++)
    {
        std::cout << tmp->getVal() << " <---";
        tmp = tmp->next;
    }
    std::cout << " END" << std::endl;
}

template<class T>
int     Queue<T>::length()
{
    return len;
}