#include "shelf.h"
#include "board.h"
#include <iostream>
#include <string>

#define INT_MAX 2147483647

using namespace std;

int validIntInput(string outputMsg, int min, int max) // just like the other validIntInput but this one has an option valid range toooooo
{
    string tmp;
    const char *str;
    bool validSize;
    int ret;

    do
    {
        cout << outputMsg << "(" << min << " - " << max << "): ";
        cin >> tmp;
        str = tmp.c_str();
        while (!isdigit(*str) && *str != '\0')
        {
            str++;
        }
        ret = atoi(str);
        //cout << ret << endl;

        if (ret < min || ret > max)
        {
            cout << "Error invalid number!\n";
            validSize = false;
        }
        else
            validSize = true;

    }while (!validSize);

    return ret;
}

int validIntInput(string outputMsg) // accepts only positive integers
{
    string tmp;
    const char *str;
    bool validSize;
    int ret;

    do
    {
        cout << outputMsg;
        cin >> tmp;
        str = tmp.c_str();
        while (!isdigit(*str) && *str != '\0')
        {
            str++;
        }
        ret = atoi(str);
        //cout << ret << endl;

        if (ret < 0 || ret > INT_MAX)
        {
            cout << "Error invalid number!\n";
            validSize = false;
        }
        else
        {
            validSize = false;
            for(int x = 0; x < tmp.length(); x++)
            {
                if (isdigit(tmp[x++]))
                {
                    validSize = true;
                }
            }
        }
        
    }while (!validSize);

    return ret;
}

int main()
{
    Shelf *s = new Shelf();
    int input;
    string name;
    int value;

    do
    {
        cout << "\n\n\n";
        s->printShelf();
        cout << "\nPress 1 to add a board game to the shelf" << endl;
        cout << "Press 2 to remove a board game from the shelf"  << endl;
        cout << "Press 3 to see how many board games are on the shelf" << endl;
        cout << "Press 4 to quit" << endl;
        input = validIntInput("Enter: ", 1, 4);

        if (input == 1)
        {
            try
            {           
                cout << "Enter a name for the new board game" << endl;
                cin.ignore();
                getline(cin, name, '\n');
                cin.clear();

                cout << "Enter a value for the new board game" << endl;
                value = validIntInput("A number: ");
                Board *game = new Board();
                game->setName(name);
                game->setValue(value);
                s->push(game);
            }
            catch (Shelf::StackOverFlowException err)
            {
                cout << "\n\n\nStackOverFlow Error! There are already 10 games on the shelf";
            }
        }
        if (input == 2)
        {
            try
            { 
                Board removedGame;
                removedGame = s->pop();
                cout << "Game removed: " << removedGame.getName() << endl;
            }
            catch (Shelf::StackUnderFlowException err)
            {
                cout << "\n\n\nStackUnderFlow Error! No games on shelf to remove.";
            }
        }
        if (input == 3)
        {
            cout << "There are " << s->getNumOfGames() << " games on the shelf\n";
        }
    }while (input != 4);

    return 0;
}