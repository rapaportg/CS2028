#include "wheel.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

Wheel::Wheel()
{
    size = 10;
    wheel.resize(10);
}

Wheel::Wheel(int i)
{
    size = i;
    wheel.resize(i);
}

void Wheel::resizeWheel(int i)
{
    size = i; // Im aware that this is redundent but i didnt feel like completely rewriting everything.
    wheel.resize(i);
}

bool Wheel::spin(int guess)
{
    int i;
    srand(time(NULL));
    i = rand()%size + 1;
    std::cout << i << std::endl;
    for (int x = 0; x <= size; x++)
    {
        wheel[x] = ' ';
    }
    wheel[i] = 'x';
    return 1;
}

/*
bool Wheel::result(int guess)
{
    if (wheel[guess] == 'x')
        return true;
    else 
        return false;
}
*/

void Wheel::setWheel(int i, char x)
{
    wheel[i] = x;
}

char Wheel::getWheel(int guess)
{
    return wheel[guess];
}

int Wheel::getSize()
{
    return size;
}