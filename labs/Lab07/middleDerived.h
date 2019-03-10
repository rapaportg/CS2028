#ifndef MIDDLEDERIVED_H
#define MIDDLEDERIVED_H
#include "orderedList.h"
#define MAX_ITEMS 20

template<class T>
class MiddleDerived: OrderedList<T>
{
    public:
        class   NoListException{};
        class   OutOfBoundException{};
        class   FullListException{};

        void    addItem(T *item);
        void    removeItem(int index);
        void    printResults();
        void    printList();
        bool    isEmpty();
};

#endif

template<class T>
void MiddleDerived<T>::addItem(T *item)
{
    int index = MAX_ITEMS / 2;
    /*
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
    if (this->array[MAX_ITEMS / 2] == nullptr)
    {
        this->array[MAX_ITEMS / 2] = item;
    }
    throw FullListException();
    */
    while (this->array[index] != nullptr)
    {
        this->countAdd++;
        index++:
        if (index >= MAX_ITEMS)
        {
            // index = index % (MAX_ITEMS / 2);
        }
    }
}

template<class T>
void MiddleDerived<T>::removeItem(int index)
{
    std::cout << "\nIndex: " << index << endl;
    printList();
    if (index >= MAX_ITEMS)
    {
        std::cout << "Out of Bounds\n";
        return;
    }
    T *tmp;
    printList();
    tmp = this->array[index];
    this->countRemove++;
    delete this->array[index];
}

template<class T>
void MiddleDerived<T>::printResults()
{
    std::cout << "\nAdd to Middle\n";
    std::cout << "Operation Add Count: " << this->countAdd << std::endl;
    std::cout << "Operation Remove Count: " << this->countRemove << std::endl;
}

template<class T>
bool MiddleDerived<T>::isEmpty()
{
    return this->array[MAX_ITEMS / 2] == nullptr;
}

template<class T>
void MiddleDerived<T>::printList()
{
    int i = 0;
    if (this->array[i] == nullptr)
    {
        std::cout << "EMPTY LIST\n";
        return;
    }
    while (this->array[i] != nullptr)
    {
        std::cout << i << ": "<< this->getItem(i) << " | ";
        i++;
    }
    std::cout << std::endl;
}