#ifndef BTNODE_H
#define BTNODE_H

template<class T>
class BTNode
{
    private:
        T               val;
        unsigned int    freq;

    public:
        BTNode      *left; // smaller
        BTNode      *right; // larger

        BTNode(T v);
        void        addFreq();
        T           getVal();
        int         getFreq();

};

template<class T>
BTNode<T>::BTNode(T v)
{
    val = v;
    freq = 0;
    left = nullptr;
    right = nullptr;
}

template<class T>
void BTNode<T>::addFreq()
{
    freq++;
}

template<class T>
T BTNode<T>::getVal()
{
    return val;
}

template<class T>
int BTNode<T>::getFreq()
{
    return freq;
}
#endif
