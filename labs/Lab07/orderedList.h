#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#define MAX_ITEMS 20
#include <iostream>


template<class T>
class OrderedList
{
    private:
        T **array = nullptr; // with be intialized as an array if pointers at runtime
        int count;

    public:
        class NoListException
        {
            public:
                NoListException();
        };

        class OutOfBoundException
        {
            public:
                OutOfBoundException();
        };

        void addItem(T item);
        void removeItem(int index);
        void makeEmpty();
        void printResults();
        bool isEmpty();
        bool isFull();
};

template<class T>
OrderedList<T>::OrderedList()
{
    array = new T[MAX_ITEMS];
    count = 0;
}

template<class T>
void OrderedList<T>::addItem(T *item)
{
    int pos = 0;

    if (array == nullptr)
    {
        /*
        OrderedList();       We have options here
        array[pos] = item;
        count++;
        */
        throw NoListException();
    }
    else
    {
        while(array[pos] != nullptr && pos < MAX_ITEMS)
        {
            pos++;
            count++;
        }
        if (pos == MAX_ITEMS)
        {
            count++;
            throw OutOfBoundException();
        }
        else
        {
            array[pos] = item;
            count++;
        }
    }
}

template<class T>
void OrderedList<T>::removeItem(int index)
{
    if (index >= MAX_ITEMS)
    {
        throw OutOfBoundException();
    }
    else
    {
        array[index] = nullptr;
        count++;
        while (array[index + 1] != nullptr && index < MAX_ITEMS - 1)
        {
            array[index] = array[index + 1];
            count++;
        }
    }
}

template<class T>
void OrderedList<T>::makeEmpty()
{
    int pos = 0;
    while (pos < MAX_ITEMS)
    {
        delete array[pos];
        count++;
    }
}
template<class T>
void OrderedList<T>::printResults()
{
    std::cout << "Operation Count: " << count << endl;
}

template<class T>
bool OrderedList<T>::isEmpty()
{
    return array[0] == nullptr;
}

template<class T>
bool OrderedList<T>::isFull()
{
    return array[MAX_ITEMS - 1] != nullptr;
}

#endif