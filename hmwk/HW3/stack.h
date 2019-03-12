#ifndef STACK_H
#define STACK_H
#include <string>
#include <iostream>

template<class T>
class Stack
{
    private:
        int maxSize;
        int head = 0;
        T **stack; // will become an array of pointers of maxSize

    public:
        class StackOverFlowException
        {
            private:
                int value;
            public:
                StackOverFlowException(int v)
                {
                    value = v;
                }
                int getValue() const
                {
                    return value;
                }
        };

        class StackUnderFlowException
        {
            private:
                int value;
            public:
                StackUnderFlowException(int v)
                {
                    value = v;
                }
                int getValue() const
                {
                    return value;
                }
        };
        Stack();
        Stack(int);
        void push(T *ptr);
        void setMax(int max);
        T *pop();
        T *top();
        T look(int);
        int length();
        bool isEmpty();
        bool isFull();
        void empty();
        void deleteStack();

        template <class C>
        friend void printStack(Stack<C> *stack);

};

template<class T>
Stack<T>::Stack()
{
    maxSize = 0;
    head = 0;
}

template<class T>
Stack<T>::Stack(int max)
{
    maxSize = max;
    stack = new T *[max];
}

template<class T>
void Stack<T>::setMax(int max)
{
    maxSize = max;
    stack = new T*[max];
}
template<class T>
void Stack<T>::push(T *ptr)
{
    if (isFull())
        throw StackOverFlowException(head);
    *stack[head] = *ptr;
    head++;
}

template<class T>
T *Stack<T>::pop()
{
    if (isEmpty())
        throw StackUnderFlowException(head);
    head--;
    return stack[head];
}

template<class T>
T *Stack<T>::top()
{
    return stack[head - 1];
}

template<class T>
int Stack<T>::length()
{
    return head;
}

template<class T>
bool Stack<T>::isEmpty()
{
    return (head == 0);
}

template<class T>
bool Stack<T>::isFull()
{
    return (head == maxSize);
}

template<class T>
void Stack<T>::empty()
{
    for (int i = 0; i < maxSize; i++)
    {
        delete stack[i];
    }
}

template<class T>
void Stack<T>::deleteStack()
{
    empty();
    delete stack;
}

template<class T>
T Stack<T>::look(int index)
{
    if (isEmpty())
    {
        throw StackUnderFlowException(head);
    }
    return *stack[index];
}

#endif