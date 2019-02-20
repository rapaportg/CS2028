#ifndef WHEEL_H
#define WHEEL_H
#include <string>
#include <cstdlib>
#include <vector>

class Wheel
{
    private:
        int size; // size must be detemined at the creation of instance Wheel. if not choosen it will default to 10
        int spin;
        
    public:
        Wheel(); //default constructor
        Wheel(int i);
        void setSize(int s);
        void setSpin(int sp);
        int getSize();
        void Spin(); //sets random spin result on wheel
        int getSpin();
        bool result(int guess); // returns true or false based on if its a winning spin or not
};

#endif