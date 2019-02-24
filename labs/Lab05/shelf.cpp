#include "shelf.h"
#include "board.h"
#include <iostream>
#include <string>

Shelf::Shelf()
{
    head = 0;
    shelf = new Board[maxSize];
}

/*
void Shelf::getGameInfo()
{
    std::cout << std::endl << shelf[head - 1].getName() << std::endl;
}
*/

void Shelf::push(Board *game)
{
    if (head == 10)
    {
        throw StackOverFlowException(head);
    }
    else
    {
        shelf[head].setName(game->getName());
        shelf[head].setValue(game->getValue());
        head++;
    }

}

Board Shelf::pop()  // it doesnt actually remove the game but it changes the number of games on the shelf making the last entry overwriteable if needed
{
    if (head <= 0)
    {
        throw StackUnderFlowException(head);
    }
    head--;
    return shelf[head];
}

Board Shelf::peek()
{
    if (isEmpty())
    {
        throw StackUnderFlowException(head);
    }
    return (shelf[head - 1]);
}

int Shelf::getNumOfGames()
{
    return head;
}

bool Shelf::isFull()
{
    return (head == maxSize);
}

bool Shelf::isEmpty()
{
    return (head == 0);
}

void Shelf::printShelf()
{
    int i = 0;
    int j = 0;

    while (i < head)
    {
        j = shelf[i].getName().length();
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
        std::cout << "| " << i + 1 << ". " << shelf[i].getName() << " |";
        i++;
    }
    std::cout << std::endl;
    i = 0;
    while (i < head)
    {
        j = shelf[i].getName().length();
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