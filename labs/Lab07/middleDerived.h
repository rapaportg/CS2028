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
    int middle = MAX_ITEMS / 2;
    int pos = 1;
    int count = 0;
    int index[MAX_ITEMS];

    printList();
    if (this->array[middle] == nullptr)
    {
        this->countAdd++;
        this->array[middle] = item;
    }
    else if (this->array[middle] != nullptr)
    {
        while (this->array[middle + pos] != nullptr && pos != 0)
        {
            if (middle + pos == MAX_ITEMS)
            {
                pos = -middle;
            }
            if (pos == 0)
            {
                throw FullListException();
            }
            index[count] = middle + pos;
            count++;
            pos++;
        }
        while (count > 0)
        {
            this->array[index[count]] = this->array[index[count - 1]];
            count--;
            this->countAdd++;
        }
        this->array[middle] = item;
        this->countAdd++;
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
    int i = MAX_ITEMS / 2;
    if (this->array[i] == nullptr)
    {
        std::cout << "EMPTY LIST\n";
        return;
    }
    while (this->array[i] != nullptr && i != MAX_ITEMS / 2)
    {
        if (i == MAX_ITEMS)
            i = 0;
        std::cout << i << ": "<< this->getItem(i) << " | ";
        i++;
    }
    std::cout << std::endl;
}