#include <iostream>
#include <cmath>
#include <string>
#include "complex.h"

using namespace std;

int main()
{
    complex temp, temp2, result;
    bool check = true;
    bool check2;
    bool res;
    string op, blink;
    char type;
    double s;
    double x; // = 1;
    double y; // = 1;
    double i; // = 1; 
    double j; // = 3.14159; 

    /*
    temp = complex(x, y);
    temp2 = complex(1, j, 1);

    
    temp.printComplex();
    temp2.printComplex();

    result = temp + temp2;
    cout << "\nA + B = "; result.printComplex();
    cout << "expected: 0 + i\n\n";

    result = temp - temp2;
    cout << "\nA - B = "; result.printComplex();
    cout << "expected: 2 + 1i\n\n";

    result = temp * temp2;
    cout << "\nA * B = "; result.printComplex();
    cout << "expected: -1 + -1i\n\n";

    result = temp / temp2;
    cout << "\nA / B = "; result.printComplex();
    cout << "expected: -1 + -1i\n\n";

    i = 1;
    j = 0;

    x = 0;
    y = 1;

    temp = complex(i, j);
    temp2 = complex(x, y);

    cout << endl << endl;
    cout << "C = "; temp.printComplex();
    cout << "D = "; temp2.printComplex();

    result = temp + temp2;
    cout << "\nC + D = "; result.printComplex();
    cout << "expected: 1 + 1i\n\n";

    result = temp - temp2;
    cout << "\nC - D = "; result.printComplex();
    cout << "expected: 1 + -1i\n\n";

    result = temp * temp2;
    cout << "\nC * D = "; result.printComplex();
    cout << "expected: 0 + 1i\n\n";

    result = temp / temp2;
    cout << "\nC / D = "; result.printComplex();
    cout << "expected: 0 + -1i\n\n";


    i = 39;
    j = (3.14159 / 4);

    x = 1 / 39;
    y = (5 * 3.14159) / 4;

    cout << endl << endl;
    temp = complex(i, j);
    temp2 = complex(x, y);

    cout << "E = "; temp.printComplex();
    cout << "F = "; temp2.printComplex();

    result = temp * temp2;
    cout << "\nE * F = "; result.printComplex();
    cout << "expected: 1 + 0i\n\n";

    result = temp / temp;
    cout << "\nE / E = "; result.printComplex();
    cout << "expected: 1 + 0i\n\n";

    */

   
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;

    temp = complex(x, y);

    while (check)
    {
        s = 1;
        cout << "Enter operation to be preformed: (+, -, *, /, ==): ";
        cin >> op;

        cout << "Would you like to compute with a scalar or another complex number (s or c)? ";
        cin >> type;

        if (type == 's' || type == 'S')
        {
            cout << "Enter scalar value: ";
            cin >> s;
            temp2 = complex(s, 0);
            check2 = true;
        }
        else if(type == 'c' || type == 'C')
        {
            cout << "Enter x: ";
            cin >> i;
            cout << "Enter y: ";
            cin >> j;
            temp2 = complex(i, j); 
            check2 = true;
        }
        else
        {
            cout << "invaild input\n";
            check2 = false;
        }

        if (op == "+" && check2)
            result = temp + temp2;

        else if (op == "-" && check2)
            result = temp - temp2;
        
        else if (op == "*" && check2)
            result = temp * temp2;
        
        else if (op == "/" && check2)
            result = temp / temp2;
        
        else if (op == "==" && check2)
        {
            s = 0;
            res = temp == temp2;

            if (res == true)
                blink = "True";
            else 
                blink = "False";

            cout << "A "  << op << " B = " << blink << endl; 

        }
        else
        { 
            cout << "Error invalue operator input!\n";
            check2 = false;
        }

        if (check2 && s != 0)
        {
            cout << "A "  << op << " B = "; 
            result.printComplex();

            cout << "\nIn polar form: \n";
            cout << "A " << op << " B = ";
            result.printPolar();
            cout << "\n\n";
        }

        cout << "Would you like to continue? Y/N ";
        cin >> type;

        if (type == 'N' || type == 'n')
            check = false;
    }
    return 0;
}