#ifndef WHEEL_H
#define WHEEL_H
#include <string>
#include <cstdlib>

class Wheel
{
    private:
        int move; //players guess
        char wheel[10]; // stores actual spin result
    public:
        Wheel(); //default constructor
        Wheel(int m);
        void setMove(int m);
        int getMove();
        void spin(); //sets random spin result on wheel
        bool result(); // returns true or false based on if its a winning spin or not
};

#endif