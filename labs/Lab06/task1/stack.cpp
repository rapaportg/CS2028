#include "stack.h"

Stack::Stack(int max)
{
    maxSize = max;
    stack = new unsigned char*[max];
}

void Stack::push(unsigned char *ptr)
{
    if (isFull())
        throw StackOverFlowException(head);
    *stack[head] = *ptr;
    head++;
}

unsigned char *Stack::pop()
{
    if (isEmpty())
        throw StackUnderFlowException(head);
    head--;
    return stack[head];
}

unsigned char *Stack::top()
{
    return stack[head - 1];
}

int Stack::length()
{
    return head;
}

bool Stack::isEmpty()
{
    return (head == 0);
}

bool Stack::isFull()
{
    return (head == maxSize);
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