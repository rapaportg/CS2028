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

void initTOH(Stack<int> *stacks[])
{
    cout << "init: A" << endl;
    cout << "inti: B" << endl;

    int *temp;

    for (int i = stacks[0]->getMax(); i > 0; i--)
    {
        temp = new int(i);
        cout << "init: C" << endl;
        stacks[0]->push(temp);
    }
}

bool validMove(Stack<int> *stacks[], int to, int from)
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


void makeMove(Stack<int> *stacks[])
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

/*
void printStack(Stack<int> *stack)
{
    string tmp = "";
    string out = "";
    string filler = "";
    int fillAmount;
    int fillAmountR;
    int diskSize;
    int numOfDisk = stack->length();
    int maxSize = stack->getMax();

    for (int i = maxSize; i >= 0; i--)
    {
        filler = "";
        tmp = "";

        if (numOfDisk <= i)
        {
            diskSize = 0;
        }
        else
        {
            diskSize = stack->look(i);
        }
        //cout << diskSize << "\t" << maxSize << endl;

        fillAmount = (maxSize - diskSize);
        for (int k = 0; k < fillAmount; k++)
        {
            filler = filler + " ";
        }

        for (int j = 0; j < diskSize; j++)
        {
            tmp = tmp + "=";
        }
        out = out + filler + tmp + "|" + tmp + filler + "\n";
    }
    cout << out << "\n\n";

}
*/

int main()
{
    int numOfDisks = validIntInput("Enter the number of disks you want to use: ", 1, INT_MAX);
    Stack<int> *stack[3];
    Stack<int> *first = new Stack<int>(numOfDisks);
    Stack<int> *second = new Stack<int>(numOfDisks);
    Stack<int> *third = new Stack<int>(numOfDisks);

    int *ptr;
    stack[0] = first;
    stack[1] = second;
    stack[2] = third;

    cout << "A" <<endl;
    initTOH(stack);
    cout << "\nGoal of game: Move everything to the third stack!\n\n";

    cout << "B" << endl;
    while (!stack[2]->isFull()) // update condition to only terminate when game is won
    {
        cout << "C" << endl;
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        printStack(stack[0]);
        printStack(stack[1]);
        printStack(stack[2]);
        makeMove(stack);
    }
    printStack(stack[0]);
    printStack(stack[1]);
    printStack(stack[2]);


    return 0;
}