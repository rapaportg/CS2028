#include "shelf.h"
#include <iostream>
#include <string>

Shelf::Shelf()
{
    numOfGames = 0;

}

void Shelf::addGame(Board game)
{
    shelfArray[numOfGames].setName(game.getName()); 
    shelfArray[numOfGames].setValue(game.getValue());
    numOfGames++;
}

Board Shelf::removeGame()  // it doesnt actually remove the game but it changes the number of games on the shelf making the last entry overwriteable if needed
{
    numOfGames--;
    return shelfArray[numOfGames + 1];
}