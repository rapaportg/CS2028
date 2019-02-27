#include "stack.h"

/*
template<class T>
Stack::Stack(int max)
{
    maxSize = max;
    stack = new T *[max];
}

template<class T>
void Stack::push(T *ptr)
{
    if (isFull())
        throw StackOverFlowException(head);
    *stack[head] = *ptr;
    head++;
}

template<class T>
T *Stack::pop()
{
    if (isEmpty())
        throw StackUnderFlowException(head);
    head--;
    return stack[head];
}

template<class T>
T *Stack::top()
{
    return stack[head - 1];
}

template<class T>
int Stack::length()
{
    return head;
}

template<class T>
bool Stack::isEmpty()
{
    return (head == 0);
}

template<class T>
bool Stack::isFull()
{
    return (head == maxSize);
}

template<class T>
void Stack::empty()
{
    for (int i = 0; i < maxSize; i++)
    {
        delete stack[i];
    }
}

template<class T>
void Stack::deleteStack()
{
    empty();
    delete stack;
}
*/

int main()
{
    Stack<int> *test = new Stack<int>(9);
}