#include "stack.h"
#include <iostream>
#include <string>

#define INT_MAX 2147483647

using namespace std;

int validIntInput(string outputMsg, int min, int max) // just like the other validIntInput but this one has an option valid range toooooo
{
    string tmp;
    const char *str;
    bool validSize;
    int ret;

    do
    {
        cout << outputMsg << "(" << min << " - " << max << "): ";
        cin >> tmp;
        str = tmp.c_str();
        while (!isdigit(*str) && *str != '\0')
        {
            str++;
        }
        ret = atoi(str);
        //cout << ret << endl;

        if (ret < min || ret > max)
        {
            cout << "Error invalid number!\n";
            validSize = false;
        }
        else
            validSize = true;

    }while (!validSize);

    return ret;
}

void initTOH(Stack *first, Stack *second, Stack *third)
{
    int numOfDisks;
    numOfDisks = validIntInput("Enter the number of disks you want to use: ", 1, INT_MAX);
    first->setMax(numOfDisks);
    second->setMax(numOfDisks);
    third->setMax(numOfDisks);

    int *temp;

    for (int i = numOfDisks; i > 0; i--)
    {
        //cout << "INIT: " << i << "     ";
        temp = new int(i);
        //cout << "INIT 2" << endl;
        first->push(temp);
    }
}

int main()
{
    Stack *first = new Stack();
    Stack *second = new Stack();
    Stack *third = new Stack();
    int *ptr;

    initTOH(first, second, third);
    // cout << endl;
    /*
    while (!first->isEmpty())
    {
        ptr = first->pop();
        cout << *ptr << endl;
    }
    */





    return 0;
}