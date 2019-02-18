#include "entertainmentCollection.h"
#include "board.h"
#include <iostream>
#include <string>

EntertainmentCollection::EntertainmentCollection()
{
    numOfGames = 0;

}

void EntertainmentCollection::getGameInfo()
{
    std::cout << std::endl << shelfArray[numOfGames - 1].getName() << std::endl;
}

void EntertainmentCollection::addGame(Board *game)
{
    if (numOfGames < 10)
    {
        shelfArray[numOfGames].setName(game->getName()); 
        shelfArray[numOfGames].setValue(game->getValue());
        //std::cout << shelfArray[numOfGames].getName() << std::endl;
        numOfGames++;
    }
    else
    {
        throw OutOfIndexException(numOfGames);
    }
}

Board* EntertainmentCollection::removeGame()  // it doesnt actually remove the game but it changes the number of games on the shelf making the last entry overwriteable if needed
{
    if (numOfGames == 0)
    {
        throw NoGamesExceptions(numOfGames);
    }
    numOfGames--;
    return &shelfArray[numOfGames];
}

int EntertainmentCollection::getNumOfGames()
{
    return numOfGames;
}