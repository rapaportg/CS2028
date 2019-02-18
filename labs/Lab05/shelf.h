#ifndef SHELF_H
#define SHELF_H
#include "base.h"
#include "board.h"
#include <string>
#include <iostream>

class Shelf
{
    private:
        int numOfGames;
        Board shelfArray[10];

    public:

        class FullShelfException
        {
            private:
                int value;
            public:
                FullShelfException(int v)
                {
                    value = v;
                }
                int getValue() const
                {
                    return value;
                }
        };

        class EmptyShelfException
        {
            private:
                int value;
            public:
                EmptyShelfException(int v)
                {
                    value = v;
                }
                int getValue() const
                {
                    return value;
                }
        };

        Shelf();
        void addGame(Board *game);
        void getGameInfo();
        Board *removeGame();
        int getNumOfGames(); 

};

#endif