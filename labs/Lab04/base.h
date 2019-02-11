#ifndef BASE_H
#define BASE_H
#include <string>

class Base
{
    private:
        std::string name;
        int value;

    protected:
        void setName(std::string n);
        void setValue(int v);
        std::string getName();
        int getValue();

    public:
        Base();
        Base(std::string n, int v);
        // virtual function: a function that you expect to be redefined in a derived class
        virtual void Winner();
        void Play();
};

#endif