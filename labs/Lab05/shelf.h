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
        
        Shelf();
        void addGame(Board *game);
        void getGameInfo();
        Board *removeGame();
        int getNumOfGames(); 

};

#endif