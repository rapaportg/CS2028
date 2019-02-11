#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "wheel.h"

class Player
{
    private:
        int balance;

    public:
        Wheel *wheel;
        Player();
        Player(int b);
        Player(int size, int b); // b = balance, constructor for creating house instance
        //Player(int size, int wager, int guess);
        void resizeWheel(int i);
        //void setWager(int w);
        //void setGuess(int g);
        void setBalance(int b);
        //int getGuess();
        //int getWager();
        int getBalance();
        bool getResult(int guess); // returns the result of the spin
};
#endif