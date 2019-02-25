#ifndef STACK_H
#define STACK_H

class Stack
{
    private:
        int maxSize;
        int head = 0;
        unsigned char **stack; // will become an array of pointers of maxSize

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
        Stack(int);
        void push(unsigned char *ptr);
        unsigned char *pop();
        unsigned char *top();
        int length();
        bool isEmpty();
        bool isFull();
        void empty();
        void deleteStack();
        friend void printStack();

};

#endif