#ifndef MIDDLEDERIVED_H
#define MIDDLEDERIVED_H
#include "orderedList.h"
#define MAX_ITEMS 20

template<class T>
class MiddleDerived: OrderedList<T>
{
    public:
        void addItem(T *item);
        void removeItem(int index);
};

#endif

template<class T>
void MiddleDerived<T>::addItem(T *item)
{
    int middle = MAX_ITEMS / 2;
    while (this->array[middle] != nullptr)
    {
        this->countAdd++;
        middle--;
        if (middle == -1)
            middle = MAX_ITEMS - 1;
    }
    while (middle != MAX_ITEMS / 2)
    {
        this->countAdd++;
        if (middle == MAX_ITEMS - 1)
        {
            middle = 0;
        }
        this->array[middle] = this->array[middle + 1];
        middle++;
    }
    this->array[MAX_ITEMS / 2] = item;
}

template<class T>
void MiddleDerived<T>::removeItem(int index)
{
    this->countRemove++;
    delete this->array[index];
}