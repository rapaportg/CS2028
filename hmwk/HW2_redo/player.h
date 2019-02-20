#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "wheel.h"

class Player: public Wheel
{
    private:
        int balance;
        int wager;
        int heat;

    public:
        Wheel *wheel;
        Player();
        Player(int i);
        void setBalance(int b);
        void setHeat(int h);
        int getBalance();
        int getHeat();
        void setWager(int w);
        int getWager();
        void Spin(int playerSpin, int playerSizes);
        
};
#endif