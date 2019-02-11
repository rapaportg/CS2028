#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "wheel.h"

class Player
{
    private:
        Wheel *wheel;
        int balance;
        int wager;
        int guess;
        int size;

    public:
        Player(int size); // default constructor
        Player(int size, int wager, int guess);
        void setWager(int w);
        void setGuess(int g);
        void setBalance(int b);
        void resizeWheel(int i);
        int getGuess();
        int getWager();
        int getBalance();
        bool getSpin(); // returns the result of the spin
};
#endif