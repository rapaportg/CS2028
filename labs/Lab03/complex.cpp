#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std;

complex::complex()
{
    real = 0;
    imag = 0;
    type = 0;
}

complex::complex(double x, double y) // cartesian contrustor 
{
    real = x;
    imag = y;
    type = 0; // default to cartesian
}

complex::complex(double r, double phi, int check) // polar constructor, fill check with something to call polar version
{
    if (check != 1)
    {
        check = 1;
    }
    real = r * cos(phi); // converts polar to cart for storage
    imag = r * sin(phi);
    type = check; // 0 is cart, 1 is polar
}

double complex::getReal() 
{
    return real;
}

double complex::getImag() 
{
    return imag;
}

void complex::setReal(double r)
{
    real = r;
}

void complex::setImag(double i)
{
    imag = i;
}

void complex::printComplex()
{
    cout << "z = " << real << " + " << imag << "i\n";
}

complex complex::operator +(complex &right)
{
    complex temp;
    temp.real = real + right.real;
    temp.imag = imag + right.imag;
    return temp;
}

complex complex::operator -(complex &right)
{
    complex temp;
    temp.real = real - right.real;
    temp.imag = imag - right.imag;
    return temp;
}

complex complex::operator *(complex &right)
{
    complex temp;
    temp.real = real * right.real - imag * right.imag;
    temp.imag = real * right.imag + imag * right.real;
    return temp;
}

complex complex::operator /(complex right)
{
    complex temp;

    double r = right.getR() * right.getR();

    if (right.real == 0 && right.imag == 0)
    {
        cout << "Error! division by zero.\n";
        return temp;
    }

    right.imag = -1 * right.imag;
    temp.real = ((real * right.real - imag * right.imag) * (1 / r));
    temp.imag = ((real * right.imag + imag * right.real) * (1 / r));
    return temp;
}

bool complex::operator ==(complex &right) 
{
        if (real!=right.real) 
            return false;
        if (imag != right.imag) 
            return false;
        return true;
}

double complex::getPhi()
{
    if (real == 0 && imag >= 0)
        return (3.14159 / 2);

    if (real == 0 && imag < 0)
        return -(3.14159 / 2);

    if (real < 0 && imag >= 0 || real < 0 && imag < 0)
        return (atan(imag / real) + 3.14159);

    if (real == 0 && imag == 0)
    {
        cout << "Error! Zero does not have a polar represenation\n";
        return 0;
    }
    return (atan(imag / real));   
}

double complex::getR()
{
    double r = (real * real) + (imag * imag);
    return sqrt(r);
}

void complex::printPolar()
{
    cout << getR() << " + " << getImag() << "i";
}