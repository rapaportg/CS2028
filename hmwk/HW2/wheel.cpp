#include "wheel.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Wheel::Wheel(int i)
{
    move = 0;
    wheel = new char[i];
}

Wheel::Wheel(int i, int m)
{
    move = m;
    wheel = new char[i];
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