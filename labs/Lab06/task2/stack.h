#ifndef STACK_H
#define STACK_H
#include <string>

class Stack
{
    private:
        int maxSize;
        int head;
        int **stack; // will become an array of pointers of maxSize

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
        //Stack(int);
        void setMax(int max);
        int getMax();
        int getHead();
        void push(int*);
        int *pop();
        int *top();
        int look(int); // returns the pointer at the index given
        int length();
        bool isEmpty();
        bool isFull();
        void empty();
        void deleteStack();
        friend void printStack();

};

#endif