#include "shelf.h"
#include "board.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
    Shelf *s = new Shelf();
    int input;
    string name;
    int value;

    do
    {
        cout << "\nPress 1 to add a board game to the shelf" << endl;
        cout << "Press 2 to remove a board game from the shelf"  << endl;
        cout << "Press 3 to see how many board games are on the shelf" << endl;
        cout << "Press 4 to quit" << endl;
        cin >> input;

        if (input == 1)
        {
            cout << "Enter a name for the new board game" << endl;
            cin >> name;
            cout << "Enter a value for the new board game" << endl;
            cin >> value;
            //Board *game = new Board(name, value);
            Board *game = new Board();
            game->setName(name);
            game->setValue(value);
            //cout << game->getName() << "\t" << game->getValue() << endl;
            s->addGame(game);
            ///s->getGameInfo();
            //cout << s->shelfArray[0].getName() << endl;
        }
        if (input == 2)
        {
            Board *removedGame;
            removedGame = s->removeGame();
            cout << "Game removed: " << removedGame->getName() << endl;
        }
        if (input == 3)
        {
            cout << "There are " << s->getNumOfGames() << " games on the shelf\n";
        }
    }while (input != 4);

    return 0;
}