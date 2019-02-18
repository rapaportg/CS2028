#ifndef ENTERTAINMENTCOLLECTION_H
#define ENTERTAINMENTCOLLECTION_H
#include "base.h"
#include "board.h"
#include <string>
#include <iostream>

template<class T>

class EntertainmentCollection
{
    private:
        int numOfGames;
        T shelfArray[10];

    public:

        class OutOfIndexException
        {
            private:
                int value;
            public:
                OutOfIndexException(int v)
                {
                    value = v;
                }
                int getValue() const
                {
                    return value;
                }
        };

        class NoGamesExceptions
        {
            private:
                int value;
            public:
                NoGamesExceptions(int v)
                {
                    value = v;
                }
                int getValue() const
                {
                    return value;
                }
        };

        EntertainmentCollection();
        void addGame(Board *game);
        void getGameInfo();
        Board *removeGame();
        int getNumOfGames(); 

};

#endif