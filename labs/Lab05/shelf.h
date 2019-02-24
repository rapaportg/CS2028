#ifndef SHELF_H
#define SHELF_H
#include "base.h"
#include "board.h"
#include <string>
#include <iostream>

class Shelf
{
    private:
        int head;
        const int maxSize = 10;
        Board *shelf;

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

        Shelf();
        void push(Board *game);
        Board pop();
        Board peek();
        bool isEmpty();
        bool isFull();
        //Board *removeGame();
        int getNumOfGames(); // is the length function but with a different name
        void printShelf();

};

#endif