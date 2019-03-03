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

    for (int i = stacks[0]->getMax(); i > 0; i--)
    {
        ptr = new Disk(i, 0);
        stacks[0]->push(ptr);
    }
}

bool validMove(Stack<Disk> *stacks[], int to, int from)
{
    if (stacks[from - 1]->length() == 0)
    {
        cout << "\nNo disks on stack " << from - 1 << endl;
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

    if (player == 0)
        cout << "Player 1 (=): " << endl;
    else
        cout << "Player 2 (*): " << endl;

    do
    {
    from = validIntInput("enter to stack you want to take a disk from: ", 1, 5);
    to = validIntInput("enter a stack you want to put the disk on: ", 1, 5);
    if (valid = validMove(stacks, to, from))
        stacks[to - 1]->push(stacks[from - 1]->pop());
    else
        cout << "Invalid move!\n";
    }while(!valid);
}

void botMove(int num, Stack<Disk> *stacks[], int beg, int end, int aux)
{
    if (validMove(stacks, end, beg))
        stacks[end]->push(stacks[beg]->pop());
    if (num == 1)
        return;
    botMove(num - 1, stacks, 1, 3, 2);
    botMove(1, stacks, 1, 2, 3);
    botMove(num - 1, stacks, 2, 1, 3);
}

bool isWinner(Stack<Disk> *stack[], int player)
{
    if (stack[1]->isFull() || stack[2]->isFull())
        return false;
    else
        return true;

}

int main()
{
    int numOfDisks;
    int *ptr;
    bool tmp;

    numOfDisks = validIntInput("Enter the number of disks you want to use: ", 1, INT_MAX);
    Stack<Disk> *stack[3];
    Stack<Disk> *first = new Stack<Disk>(numOfDisks);
    Stack<Disk> *second = new Stack<Disk>(numOfDisks);
    Stack<Disk> *third = new Stack<Disk>(numOfDisks);

    stack[0] = first;
    stack[1] = second;
    stack[2] = third;

    initTOH(stack);
    cout << "\nGoal of game: Move everything to the third stack!\n\n";

    int count = -1;
    do // update condition to only terminate when game is won
    {
        cout << "\n\n\n\n\n";
        printStack(stack[0]);
        printStack(stack[1]);
        printStack(stack[2]);

        //makeMove(stack, 0);
        botMove(stack[0]->getMax(), stack, 1, 2, 3);

    }while (isWinner(stack, 0));

    return 0;
}