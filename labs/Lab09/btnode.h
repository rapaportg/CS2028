#ifndef BTNODE_H
#define BTNODE_H

template<class T>
class BTNode
{
    private:
        T           val;

    public:
        BTNode      *left; // smaller
        BTNode      *right; // larger
        BTNode(T v);
        T getVal();

};

#endif

template<class T>
BTNode<T>::BTNode(T v)
{
    val = v;
    left = nullptr;
    right = nullptr;
}

template<class T>
T BTNode<T>::getVal()
{
    return val;
}