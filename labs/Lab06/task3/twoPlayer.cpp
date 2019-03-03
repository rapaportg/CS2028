#include "stack.h"
#include "disk.h"
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

void initTOH(Stack<Disk> *stacks[])
{
    Disk *ptr;
    Disk *ptr2;

    for (int i = stacks[0]->getMax(); i > 0; i--)
    {
        ptr = new Disk(i, 0);
        ptr2 = new Disk(i, 1);

        stacks[0]->push(ptr);
        stacks[4]->push(ptr2);
    }
}

bool validMove(Stack<Disk> *stacks[], int to, int from, int player)
{
    if (stacks[from - 1]->length() == 0)
    {
        cout << "\nNo disks on stack " << from - 1 << endl;
        return false;
    }
    else if (stacks[from - 1]->top()->getOwner() != player)
    {
        cout << "\nYOU CHEATER! DONT TOUCH WHATS NOT YOURS\n";
        return false;
    }
    else if (stacks[to - 1]->length() == 0)
    {
        return true;
    }
    else
    {
        int a = stacks[from - 1]->top()->getSize();
        int b = stacks[to - 1]->top()->getSize();
        if (a >= b)
            return false;
        else
            return true;
    }
}


void makeMove(Stack<Disk> *stacks[], int player)
{
    int from;
    int to;
    int *holder;
    bool valid;

    // Game print function
    if (player == 0)
        cout << "Player 1 (=): " << endl;
    else
        cout << "Player 2 (*): " << endl;

    do
    {
    from = validIntInput("enter to stack you want to take a disk from: ", 1, 5);
    to = validIntInput("enter a stack you want to put the disk on: ", 1, 5);
    if (valid = validMove(stacks, to, from, player))
        stacks[to - 1]->push(stacks[from - 1]->pop());
    else
        cout << "Invalid move!\n";
    }while(!valid);
}

bool isWinner(Stack<Disk> *stack[], int player)
{
    if (player == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (stack[i]->isFull())
            {
                for (int j = 0; j < stack[i]->getMax(); j++)
                {
                    if (stack[i]->look(j)->getOwner() != 1 && j == (stack[i]->getMax() - 1))
                    {
                        out << "Player 1 is the winner!\n";
                        return false;
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 3; i < 5; i++)
        {
            if (stack[i]->isFull())
            {
                for (int j = 0; j < stack[i]->getMax(); j++)
                {
                    if (stack[i]->look(j)->getOwner() == 0 && j == (stack[i]->getMax() - 1))
                    {
                        cout << "Player 1 is the winner!\n";
                        return false;
                    }
                }
            }
        }
    }
   return true;
}

int main()
{
    int numOfDisks = validIntInput("Enter the number of disks you want to use: ", 1, INT_MAX);
    Stack<Disk> *stack[5];
    Stack<Disk> *first = new Stack<Disk>(numOfDisks);
    Stack<Disk> *second = new Stack<Disk>(numOfDisks);
    Stack<Disk> *third = new Stack<Disk>(numOfDisks);
    Stack<Disk> *fourth = new Stack<Disk>(numOfDisks);
    Stack<Disk> *fifth = new Stack<Disk>(numOfDisks);

    int *ptr;
    stack[0] = first;
    stack[1] = second;
    stack[2] = third;
    stack[3] = fourth;
    stack[4] = fifth;

    initTOH(stack);
    cout << "\nGoal of game: Move everything to the third stack!\n\n";

    int count = -1;
    do // update condition to only terminate when game is won
    {
        count++;
        cout << "\n\n\n\n\n";
        printStack(stack[0]);
        printStack(stack[1]);
        printStack(stack[2]);
        printStack(stack[3]);
        printStack(stack[4]);
        makeMove(stack, count % 2);

    }while (isWinner(stack, count % 2));

    return 0;
}