#include "wheel.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Wheel::Wheel()
{
    size = 10;
    wheel = new char[size];
}

Wheel::Wheel(int i)
{
    size = i;
    wheel = new char[i];
}

void Wheel::spin()
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
}

bool Wheel::result(int guess)
{
    if (wheel[guess] == 'x')
        return true;
    else 
        return false;
}

int Wheel::getSize()
{
    return size;
}