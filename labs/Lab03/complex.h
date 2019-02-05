#ifndef COMPLEX_H
#define COMPLEX_H

class complex
{
    private: 
        double real;
        double imag;
        int type;

    public:
        complex(); // default constructor
        complex(double x, double y); // cart constructor
        complex(double r, double phi, int type); // polar constructor, fill type with any int valule
        void setReal(double r);
        void setImag(double i);
        double getReal();
        double getImag();
        void printComplex();
        double getR(); 
        complex operator +(complex &right);
        complex operator -(complex &right);
        complex operator *(complex &right);
        complex operator /(complex right);
        bool operator ==(complex &right);
        double getPhi();
        void printPolar();
};

#endif