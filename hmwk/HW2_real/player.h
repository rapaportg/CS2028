#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "wheel.h"

class Player: public Wheel
{
    private:
        int balance;
        int heat;

    public:
        Wheel *wheel;
        Player();
        Player(int i);
        void setBalance(int b);
        void setHeat(int h);
        int getBalance();
        int getHeat();
        bool spin(int guess);
        
};
#endif