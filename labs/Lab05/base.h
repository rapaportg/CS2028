#ifndef BASE_H
#define BASE_H
//#include "entertainmentCollection.h"
#include <string>

class Base
{
    private:
        std::string name;
        int value;

    public:
        Base();
        Base(std::string n, int v);
        void setName(std::string n);
        void setValue(int v);
        std::string getName();
        int getValue();
        void Winner();
        // virtual function: a function that you expect to be redefined in a derived class
        virtual void Play();
};

#endif