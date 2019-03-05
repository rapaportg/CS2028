#include "player.h"
#include <iostream>

using namespace std;

// Need to figure out how to handle all the computer moves
// void computer(Player me, Player computer)

int main()
{
    Player *me;
    Player *computer;
    unsigned int seed;

    me = new Player();
    //computer = new Player(); initalize computer deck after a user input to allow enough time for a new random seed
    cout << me->deck->dequeue() << '\t' <<  me->deck->size() << endl;
    return 0;
}