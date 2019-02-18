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
        

    public:
        Board shelfArray[10];
        Shelf();
        void addGame(Board *game);
        Board removeGame(); 

};

#endif