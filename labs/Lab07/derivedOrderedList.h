#ifndef DERIVEDORDEREDLIST_H
#define DERIVEDORDEREDLIST_H
#define MAX_ITEMS 20
#include "orderedList.h"

template<class T>
class DerivedOrderedList:OrderedList
{
    public:
        void addItem(T *item);
        void removeItem(int index);
};

#endif

template<class T>
void DerivedOrderedList<T>::addItem(T *item)
{
    int pos = 1;
    if (array[MAX_ITEMS] == nullptr)
    {
        array[MAX_ITEMS] = item;
    }
    while (array[MAX_ITEMS - pos] != nullptr && pos <= MAX_ITEMS)
    {
        pos++;
        countAdd++;
    }
    if (array[0] != nullptr)
    {
        throw FullListException();
    }
    array[MAX_ITEMS - pos] = item;
    countAdd++;
}

template<class T>
void DerivedOrderedList<T>::removeItem(int index)
{
    if (index >= MAX_ITEMS || index < 0)
    {
        throw OutOfBoundsException();
    }
    if (array == nullptr)
    {
        throw NoListException();
    }
    if (array[index] != nullptr)
    {
        delete array[index];
    }
    countRemove++;
    while (index > 0 && array[index - 1] != nullptr)
    {
        array[index] = array[index - 1];
        index--;
        countRemove++;
    }
}