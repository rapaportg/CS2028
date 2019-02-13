#include <iostream>
#include "wheel.h"
#include "player.h"

Player::Player()
{
    wheel = new Wheel(0);
    heat = 0;
    balance = 100;
}

Player::Player(int i)
{
    wheel = new Wheel(i); // Must declare the size of the wheel when creating in
    heat = 0;
    balance = 100; // money player has
}

Player::Player(int i, int b)
{
    wheel = new Wheel(i);
    heat = 0;
    balance = b;
}

void Player::resizeWheel(int i)
{
    delete wheel;
    wheel = new Wheel(i);
}

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

bool Player::getResult(int guess) 
{
    wheel->spin();
    return wheel->result(guess);
}