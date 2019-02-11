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
        void resizeWheel(int i);
        void setWager(int w);
        void setGuess(int g);
        void setBalance(int b);
        void setSize(int i);
        int getSize();
        int getGuess();
        int getWager();
        int getBalance();
        bool getSpin(); // returns the result of the spin
};
#endif