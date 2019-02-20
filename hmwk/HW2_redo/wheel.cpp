#include "wheel.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

Wheel::Wheel() // Default constuctor wheel that defaults to size 10
{
    size = 10;
    spin = 0;
}

Wheel::Wheel(int i) 
{
    size = i;
    spin = 0;
}

void Wheel::Spin()
{
    int i;
    srand(time(NULL));
    spin = rand()%size + 1;
}

void Wheel::setSpin(int sp)
{
    spin = sp;
}

void Wheel::setSize(int s)
{
    size = s;
}

int Wheel::getSpin()
{
    return spin;
}

int Wheel::getSize()
{
    return size;
}