#ifndef STACK_H
#define STACK_H
#include "node.h"
#include <iostream>

template<class T>
class Stack
{
    private:
        Node<T> *head;
        Node<T> *cur;
        int     len;

    public:
        class   StackUnderFlow{};
        Stack();
        void    push_back(T item);
        T       back();
        void    pop_back();
        void    print();
};

#endif

template<class T>
Stack<T>::Stack()
{
    head = nullptr;
    cur = nullptr;
    len = 0;
}

template<class T>
void    Stack<T>::push_back(T item)
{
    Node<T> *tmp;
    tmp = new Node<T>(item);

    len++;

    if (head == nullptr)
    {
        head = tmp;
        cur = head;
        return;
    }
    cur->next = tmp;
    cur = tmp;
    return;
}

template<class T>
T   Stack<T>::back()
{
    return cur->getVal();
}

template<class T>
void    Stack<T>::pop_back()
{
    Node<T> *tmp = head;
    int i = 0;

    if (len == 0)
        throw StackUnderFlow();
    while (i++ < len - 2)
    {
        tmp = tmp->next;
    }
    cur = tmp;
    tmp = cur->next;
    len--;
    tmp->~Node();
}

template<class T>
void    Stack<T>::print()
{
    Node<T> *tmp = head;
    int i = 0;
    while (i++ < len)
    {
        std::cout << tmp->getVal().getVal() << "---> ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}