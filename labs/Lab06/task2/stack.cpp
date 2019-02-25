#include "stack.h"
#include <iostream>
#include <string>

Stack::Stack()
{
    maxSize = 0;
    head = 0;
}

/*
Stack::Stack(int max)
{
    maxSize = max;
    stack = new int*[max];
}
*/

void Stack::setMax(int max)
{
    maxSize = max;
    stack = new int*[max];
}

void Stack::push(int *ptr)
{
    if (isFull())
        throw StackOverFlowException(head);
    else
    {
        // std::cout << "PUSH: " << head << std::endl;
        stack[head] = ptr;
        head++;
    }
}

int* Stack::pop()
{
    // std::cout << "POP: " << head << "      ";
    if (head <= 0)
    {
        throw StackUnderFlowException(head);
    }
    head--;
    return stack[head];
}

int* Stack::top()
{
    if (isEmpty())
    {
        throw StackUnderFlowException(head);
    }
    return stack[head - 1];
}

int Stack::length()
{
    return head;
}

bool Stack::isEmpty()
{
    return (head <= 0);
}

bool Stack::isFull()
{
    return (head == (maxSize));
}

void Stack::empty()
{
    for (int i = 0; i < maxSize; i++)
    {
        delete stack[i];
    }
}

void Stack::deleteStack()
{
    empty();
    delete stack;
}

int* Stack::look(int index)
{
    return *stack[index - 1];
}