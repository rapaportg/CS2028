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

void initTOH(Stack *stacks[])
{
    int numOfDisks;
    numOfDisks = validIntInput("Enter the number of disks you want to use: ", 1, INT_MAX);
    stacks[0]->setMax(numOfDisks);
    stacks[1]->setMax(numOfDisks);
    stacks[2]->setMax(numOfDisks);

    int *temp;

    for (int i = numOfDisks; i > 0; i--)
    {
        //cout << "INIT: " << i << "     ";
        temp = new int(i);
        //cout << "INIT 2" << endl;
        stacks[0]->push(temp);
    }
}

bool validMove(Stack *stacks[], int to, int from)
{

    if (stacks[to - 1]->length() == 0)
    {
        return true;
    }
    else
    {
        int a = *stacks[from - 1]->top();
        int b = *stacks[to - 1]->top();
        if (a > b)
        {
            return false;
        }
        else
            return true;
    }
}

void makeMove(Stack *stacks[])
{
    int from;
    int to;
    int *holder;

    // Game print function
    from = validIntInput("Enter to stack you want to take a disk from: ", 1, 3);
    to = validIntInput("Enter a stack you want to put the disk on: ", 1, 3);
    if (validMove(stacks, to, from))
        stacks[to - 1]->push(stacks[from - 1]->pop());
    else
        cout << "Invalid move! you cannot put a larger piece on a smaller piece\n";
}

void print(Stack *stacks[])
{
    cout << stacks[0]->length() << "      " << *stacks[0]->top() << endl;
    cout << stacks[1]->length() << endl;// << "      " << *stacks[2]->top()<< endl;
    cout << stacks[2]->length() << endl;// << "      " << *stacks[3]->top()<< endl;
}

int main()
{
    Stack *first = new Stack();
    Stack *second = new Stack();
    Stack *third = new Stack();
    Stack *stacks[3];
    int *ptr;
    stacks[0] = first;
    stacks[1] = second;
    stacks[2] = third;

    initTOH(stacks);
    cout << "\nGoal of game: Move everything to the third stack!\n\n";
    while (!stacks[2]->isFull()) // update condition to only terminate when game is won
    {
        print(stacks);
        makeMove(stacks);
    }
    print(stacks);
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