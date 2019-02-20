#include <iostream>
#include "wheel.h"
#include "player.h"


Player::Player():Wheel()
{
    heat = 0;
    balance = 100;
    wager = 10;
}


Player::Player(int i):Wheel(i) // this constructor can set the size of the wheel at the call 
{
    heat = 0;
    balance = 100; // money player has
    wager = 0;
}

void Player::setBalance(int b)
{
    balance = b;
}

void Player::setHeat(int h)
{
    heat = h;
}

void Player::setWager(int w)
{
    wager = w;
}

int Player::getWager()
{
    return wager;
}

int Player::getBalance()
{
    return balance;
}

int Player::getHeat()
{
    return heat;
}


void Player::Spin(int playerSpin, int playerSize) // overloaded Wheel::Spin() function
{
    int i;
    srand(time(NULL));
    i = rand()%getSize() + 1;
    setSpin(i);
    if (playerSpin > i)
    {
        setSize(getSize() + 1);
        heat = 0;
    }
    else
    {
        if (heat >= 2 && getSize() > playerSize)
        {
            setSize(getSize() - 1);
            heat = 0;
        }
    }
        
}
