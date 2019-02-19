#ifndef WHEEL_H
#define WHEEL_H
#include <string>
#include <cstdlib>
#include <vector>

class Wheel
{
    private:
        int size; // size must be detemined at the creation of instance Wheel. if not choosen it will default to 10
        std::vector<char> wheel; // stores actual spin result
    public:
        Wheel(); //default constructor
        Wheel(int i);
        void resizeWheel(int i);
        void setWheel(int i, char x);
        int getSize();
        char getWheel(int guess);
        virtual bool spin(); //sets random spin result on wheel
        bool result(int guess); // returns true or false based on if its a winning spin or not
};

#endif