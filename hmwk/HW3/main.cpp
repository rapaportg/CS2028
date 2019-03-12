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
            cout << "Error invalid input!\n";
            validSize = false;
        }
        else
            validSize = true;

    }while (!validSize);

    return ret;
}

void computerMove(Player *cpu)
{

}

void playRound(Player *me, Player *cpu)
{
    int input;
    me->clearHand();
    cpu->clearHand();
    me->draw();
    cpu->draw();

    me->peekHand();
    me->peekSidePile();
    cout << endl;
    if (!me->isSidePileEmpty() && !me->isSidePileFull())
    {
        cout << "\n1. Save Card in side pile" << endl;
        cout << "2. Draw from side pile" << endl;
        cout << "3. Do Nothing" << endl;
        input = validIntInput("What would you like to do?", 1, 3);
    }
    else if (!me->isSidePileEmpty())
    {
        cout << "\n2. Draw from side pile" << endl;
        cout << "3. Do Nothing" << endl;
        input = validIntInput("What would you like to do?", 2, 3);
    }
    else
    {
        input = 2;

        cout << "\n1. Save Card in side pile" << endl;
        cout << "3. Do Nothing" << endl;
        input = validIntInput("What would you like to do?", 1, 3);

        while(input == 2)
        {
            cout << "Error invaild input!" << endl;
            input = validIntInput("What would you like to do?", 1, 3);
        }
    }

    // computer moves go here

    if (input == 1)
    {
        me->pushToSide();
    }
    else if (input == 2)
    {
        me->getFromPile();
    }
    cout << endl;
    me->peekHand();
    me->peekSidePile();

    if (me->handSum() > cpu->handSum())
    {
        cout << "Winner! you: " << me->handSum() << "\t cpu: " << cpu->handSum() << endl;
        me->addToHand(cpu->getHand());
        me->bury();
    }
    else
    {
        cout << "Winner! you: " << me->handSum() << "\t cpu: " << cpu->handSum() << endl;
        cpu->addToHand(me->getHand());
        cpu->bury();
    }

}

int main()
{
    Player *me;
    Player *computer;

    me = new Player();
    computer = new Player(); //initalize computer deck after a user input to allow enough time for a new random seed

    while (true)
    {
        cout << "\n\n\n";
        playRound(me, computer);
    }
    return 0;
}