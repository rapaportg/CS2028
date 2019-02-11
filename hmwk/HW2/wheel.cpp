#include "wheel.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Wheel::Wheel()
{
    move = 0;
    spin();
}

Wheel::Wheel(int m)
{
    move = m;
    spin();
}

void Wheel::spin()
{
    int i;
    srand(time(NULL));
    i = rand()%10;
    wheel[i] = 'x';
}

bool Wheel::result()
{
    if (wheel[move] == 'x')
        return true;
    else 
        return false;
}

void Wheel::setMove(int m)
{
    move = m;
}

int Wheel::getMove()
{
    return move;
}