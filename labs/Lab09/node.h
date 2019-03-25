#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    private:
        T       value;

    public:
        Node    *left;
        Node    *right;
        Node(T v);
        T getValue();

};

#endif

template<class T>
Node<T>::Node(T v)
{
    value = v;
    left = nullptr;
    right = nullptr;
}

template<class T>
T Node<T>::getValue()
{
    return value;
}