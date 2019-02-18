#include "shelf.h"
#include "board.h"
#include <iostream>
#include <string>

Shelf::Shelf()
{
    numOfGames = 0;

}

void Shelf::getGameInfo()
{
    std::cout << std::endl << shelfArray[numOfGames - 1].getName() << std::endl;
}

void Shelf::addGame(Board *game)
{
    shelfArray[numOfGames].setName(game->getName()); 
    shelfArray[numOfGames].setValue(game->getValue());
    //std::cout << shelfArray[numOfGames].getName() << std::endl;
    numOfGames++;
}

Board* Shelf::removeGame()  // it doesnt actually remove the game but it changes the number of games on the shelf making the last entry overwriteable if needed
{
    if (numOfGames == 0)
    {
        std::cout << "Error no games on shelf!\n";
        return nullptr;
    }
    numOfGames--;
    return &shelfArray[numOfGames];
}

int Shelf::getNumOfGames()
{
    return numOfGames;
}