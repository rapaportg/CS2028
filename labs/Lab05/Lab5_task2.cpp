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
            try
            {           
                cout << "Enter a name for the new board game" << endl;
                cin >> name;
                cout << "Enter a value for the new board game" << endl;
                cin >> value;
                Board *game = new Board();
                game->setName(name);
                game->setValue(value);
                s->addGame(game);
            }
            catch (Shelf::FullShelfException err)
            {
                cout << "Error! There are already 10 games on the shelf\n";
            }
        }
        if (input == 2)
        {
            try
            { 
                Board *removedGame;
                removedGame = s->removeGame();
                cout << "Game removed: " << removedGame->getName() << endl;
            }
            catch (Shelf::EmptyShelfException err)
            {
                cout << "Error! No games on shelf to remove.\n";
            }
        }
        if (input == 3)
        {
            cout << "There are " << s->getNumOfGames() << " games on the shelf\n";
        }
    }while (input != 4);

    return 0;
}