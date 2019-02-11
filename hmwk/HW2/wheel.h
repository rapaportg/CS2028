#ifndef WHEEL_H
#define WHEEL_H
#include <string>
#include <cstdlib>

class Wheel
{
    private:
        int move; //players guess
        int i;
        char* wheel; // stores actual spin result
    public:
        Wheel(int i); //default constructor
        Wheel(int i, int m);
        void setMove(int m);
        int getMove();
        void spin(); //sets random spin result on wheel
        bool result(); // returns true or false based on if its a winning spin or not
};

#endif