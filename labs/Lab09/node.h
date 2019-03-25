#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    private:
        T value;

    public:
        Node *next;
        Node(T v);
        T getValue();

};

#endif

template<class T>
Node<T>::Node(T v)
{
    value = v;
    next = nullptr;
}

template<class T>
T Node<T>::getValue()
{
    return value;
}