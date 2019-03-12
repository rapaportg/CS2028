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

/*
void computerMove(Player *cpu)
{

}
*/

void playRound(Player *me, Player *cpu)
{
    int input;


    me->clearHand();
    cpu->clearHand();

    me->draw();
    cpu->draw();
    //cpu->clearHand();  // Uncomment to test win condition in a reasonable amount of time

    cout << "\nCards left in your deck: " << me->cardsLeftInDeck() << endl;
    cout << "Cards left in CPU deck: " << cpu->cardsLeftInDeck();

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

    // computer moves go here use function

    if (input == 1)
    {
        me->pushToSide();
        me->draw();
    }
    else if (input == 2)
    {
        me->getFromPile();
    }


    me->peekHand();
    me->peekSidePile();

    if (me->handSum() > cpu->handSum())
    {
        cout << "\n\nWinner! you: " << me->handSum() << "\t cpu: " << cpu->handSum();
        me->addToHand(cpu->getHand());
        //me->peekHand();
        me->bury();
    }
    else
    {
        cout << "\nLoser! you: " << me->handSum() << "\t cpu: " << cpu->handSum();
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



    while (me->cardsLeftInDeck() != 0 && computer->cardsLeftInDeck() != 0)
    {
        cout << "\n------------------------------------------\n\n";
        playRound(me, computer);
    }

    return 0;
}