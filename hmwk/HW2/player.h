#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "wheel.h"

class Player
{
    private:
        int balance;
        int heat;

    public:
        Wheel *wheel;
        Player();
        Player(int i);
        Player(int size, int b); // b = balance, constructor for creating house instance
        //Player(int size, int wager, int guess);
        void resizeWheel(int i);
        //void setWager(int w);
        //void setGuess(int g);
        void setBalance(int b);
        void setHeat(int h);
        //int getGuess();
        //int getWager();
        int getBalance();
        int getHeat();
        bool getResult(int guess); // returns the result of the spin
        
};
#endif