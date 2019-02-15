#include <iostream>
#include "wheel.h"
#include "player.h"


Player::Player():Wheel()
{
    heat = 0;
    balance = 100;
}


Player::Player(int i):Wheel(i)
{
    heat = 0;
    balance = 100; // money player has
}

/*
Player::Player(int b):Wheel(int i)
{
    heat = 0;
    balance = b;
}
*/

/*
void Player::resizeWheel(int i)
{
    delete wheel;
    wheel = new Wheel(i);
}
*/

void Player::setBalance(int b)
{
    balance = b;
}

void Player::setHeat(int h)
{
    heat = h;
}

int Player::getBalance()
{
    return balance;
}

int Player::getHeat()
{
    return heat;
}

/*
bool Player::getResult(int guess) 
{
    wheel->spin();
    return wheel->result(guess);
}
*/

bool Player::spin(int guess)
{
    int i;
    srand(time(NULL));
    i = rand()%getSize() + 1;
    std::cout << i << std::endl;
    for (int x = 0; x <= getSize(); x++)
    {
        //std::cout << "TEST\n";
        setWheel(x, ' ');
    }
    setWheel(i, 'x');

    if (getWheel(guess) == 'x')
        return true;
    else 
        return false;
}