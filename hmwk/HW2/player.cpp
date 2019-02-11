#include <iostream>
#include "wheel.h"
#include "player.h"

Player::Player(int i)
{
    size = i;
    wheel = new Wheel(i); // Must declare the size of the wheel when creating in
    balance = 0; // money player has
    wager = 0; // amount bet on current spin
    guess = 0; 
    
}

Player::Player(int i, int w, int g)
{
    size = i;
    wheel = new Wheel(i);
    balance = 0;
    wager = w;
    guess = g;
}

void Player::resizeWheel(int i)
{
    delete wheel;
    wheel = new Wheel(i);
}

void Player::setSize(int i)
{
    size = i;
}

void Player::setWager(int w)
{
    wager = w;
}

void Player::setGuess(int g) // must be a number from 1 to size
{
    guess = g;
}

void Player::setBalance(int b)
{
    balance = b;
}

int Player::getSize()
{
    return size;
}
f
int Player::getWager()
{
    return wager;
}

int Player::getGuess()
{
    return guess;
}

int Player::getBalance()
{
    return balance;
}

bool Player::getSpin() 
{
    wheel->setMove(guess);
    wheel->spin();
    return wheel->result();
}