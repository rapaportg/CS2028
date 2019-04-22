#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    private:
        T val;
        bool visited;


    public:
        Node *next;
        Node();
        Node(T val);
        void    setVal(T v);
        T       getVal();
        void    markVisited();
        bool    getVisited();

};

#endif

template<class T>
Node<T>::Node()
{
    visited = false;
    next = nullptr;
}

template<class T>
Node<T>::Node(T v)
{
    val = v;
    visited = false;
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

template<class T>
void Node<T>::markVisited()
{
    visited = true;
}

template<class T>
bool Node<T>::getVisited()
{
    return visited;
}