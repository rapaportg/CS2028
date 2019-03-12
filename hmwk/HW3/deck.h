#ifndef DECK_H
#define DECK_H
#include "node.h"

class Deck
{
    private:
        int length = 0;
        Node *head = nullptr;

    public:
        class EmptyListException
        {
            private:
                int value;
            public:
                EmptyListException(int v)
                {
                    value = v;
                }
                int getValue() const
                {
                    return value;
                }
        };

        void enqueue(int card);
        int dequeue();
        int size();
        void printDeck();

};
#endif