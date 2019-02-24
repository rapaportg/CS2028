#ifndef ENTERTAINMENTCOLLECTION_H
#define ENTERTAINMENTCOLLECTION_H
#include "base.h"
#include "board.h"
#include "VidGame.h"
#include <string>
#include <iostream>

using namespace std;

template <class T>
class EntertainmentCollection
{
    private:
        int head = 0;
        int maxSize;
        T *collection;

    public:

        class StackOverFlowException
        {
            private:
                int value;
            public:
                StackOverFlowException(int v)
                {
                    value = v;
                }
                int getValue() const
                {
                    return value;
                }
        };

        class StackUnderFlowException
        {
            private:
                int value;
            public:
                StackUnderFlowException(int v)
                {
                    value = v;
                }
                int getValue() const
                {
                    return value;
                }
        };


        EntertainmentCollection(int);
        EntertainmentCollection(){maxSize = 0; collection = 0;}
        void push(T *item);
        T pop();
        T peek();
        bool isEmpty();
        bool isFull();
        int getNumOfItems(); // is the length function but with a different name
        void printCollection();
        void setMaxSize(int x);

};

template <class T>
EntertainmentCollection<T>::EntertainmentCollection(int size)
{
    head = 0;
    maxSize = size;
    collection = new T[maxSize];
}

template <class T>
void EntertainmentCollection<T>::push(T *item)
{
    if (head == 10)
    {
        throw StackOverFlowException(head);
    }
    else
    {
        collection[head].setName(item->getName());
        collection[head].setValue(item->getValue());
        //std::cout << shelfArray[numOfGames].getName() << std::endl;
        head++;
    }

}

template <class T>
T EntertainmentCollection<T>::pop()  // it doesnt actually remove the game but it changes the number of games on the shelf making the last entry overwriteable if needed
{
    if (head <= 0)
    {
        throw StackUnderFlowException(head);
    }
    head--;
    return collection[head];
}

template <class T>
T EntertainmentCollection<T>::peek()
{
    if (isEmpty())
    {
        throw StackUnderFlowException(head);
    }
    return (collection[head - 1]);
}

template <class T>
int EntertainmentCollection<T>::getNumOfItems()
{
    return head;
}

template <class T>
bool EntertainmentCollection<T>::isFull()
{
    return (head == maxSize);
}

template <class T>
bool EntertainmentCollection<T>::isEmpty()
{
    return (head == 0);
}

template<class T>
void EntertainmentCollection<T>::setMaxSize(int x)
{
    maxSize = x;
    collection = new T[maxSize];
}

template <class T>
void EntertainmentCollection<T>::printCollection()
{
    int i = 0;
    int j = 0;

    cout << "\n\n\n";
    while (i < head)
    {
        j = collection[i].getName().length();
        std::cout << "|";
        if (i == 9)
            std::cout << '-';
        std::cout << "----";
        for (int k = 0; k <= j; k++)
            std::cout << "-";
        std::cout << "|";
        i++;
    }
    std::cout << std::endl;
    i = 0;
    while (i < head)
    {
        std::cout << "| " << i + 1 << ". " << collection[i].getName() << " |";
        i++;
    }
    std::cout << std::endl;
    i = 0;
    while (i < head)
    {
        j = collection[i].getName().length();
        std::cout << "|";
        if (i == 9)
            std::cout << '-';
        std::cout << "----";
        for (int k = 0; k <= j; k++)
            std::cout << "-";
        std::cout << "|";

        i++;
    }
}

#endif