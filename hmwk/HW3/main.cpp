#include "player.h"
#include <iostream>

using namespace std;

// Need to figure out how to handle all the computer moves
// void computer(Player me, Player computer)
int validIntInput(string outputMsg, int min, int max)
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
        while (!isdigit(*str))
        {
            str++;
        }
        ret = atoi(str);

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


void playRound(Player *me, Player *cpu)
{
    int input;
    me->draw();
    cpu->draw();

    me->peekHand();
    cout << "\n1. Save Card in side pile" << endl;
    cout << "2. Draw from side pile" << endl;
    input = validIntInput("What would you like to do?", 1, 2);
}

int main()
{
    Player *me;
    Player *computer;

    me = new Player();
    computer = new Player(); //initalize computer deck after a user input to allow enough time for a new random seed

    playRound(me, computer);
    return 0;
}