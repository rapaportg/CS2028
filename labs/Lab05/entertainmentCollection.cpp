#include "entertainmentCollection.h"
#include "VidGame.h"
#include "board.h"
#include <iostream>
#include <string>

/*
template <class T>
EntertainmentCollection<T>::EntertainmentCollection(int size)
{
    head = 0;
    maxSize = size;
    collection = new T[maxSize];
}

/*
template <class T>
EntertainmentCollection<T>::~EntertainmentCollection()
{
  if (maxSize > 0)
    delete [] collection;
}
*/

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