#include "base.h"
#include <string>
#include <iostream>

Base::Base()
{
    name = " ";
    value = 0;
}

Base::Base(std::string n, int v)
{
    name = n;
    value = v;
}

void Base::setName(std::string n)
{
    name = n;
}

void Base::setValue(int v)
{
    value = v;
}

std::string Base::getName()
{
    return name;
}

int Base::getValue()
{
    return value;
}

void Base::Winner()
{
    std::cout << "Not Yet" << std::endl;
}

void Base::Play(){}


int main(int ac, char **str)