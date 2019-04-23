#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    private:
        T val;

    public:
        Node *next;
        Node();
        Node(T val);
        void    setVal(T v);
        T       getVal();

};

#endif

template<class T>
Node<T>::Node()
{
    next = nullptr;
}

template<class T>
Node<T>::Node(T v)
{
    val = v;
    next = nullptr;
}

template<class T>
void Node<T>::setVal(T v)
{
    val = v;
}

template<class T>
T   Node<T>::getVal()
{
    return val;
}