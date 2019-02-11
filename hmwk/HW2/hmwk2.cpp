#include <iostream>
#include <string>
#include "player.h"

using namespace std;

int main()
{
    // test
    Player bob = Player(20, 10, 10);
    cout << bob.getSpin() << endl;


    return 0;
}