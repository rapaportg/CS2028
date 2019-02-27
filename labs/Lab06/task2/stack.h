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
        void setMax(int);
        void push(T *ptr);
        T *pop();
        T *top();
        T look(int);
        int length();
        int getMax();
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
    std::cout << "PUSH: A" << std::endl;
    if (isFull())
        throw StackOverFlowException(head);
    else
    {
        stack[head] = ptr;
        std::cout << "PUSH: A" << std::endl;
        head++;
    }
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

template<class T>
int Stack<T>::getMax()
{
    return maxSize;
}

template<class T>
void printStack(Stack<T> *s)
{
    std::string tmp = "";
    std::string out = "";
    std::string filler = "";
    int fillAmount;
    int fillAmountR;
    int diskSize;
    int numOfDisk = s->head;
    int maxSize = s->maxSize;

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
            diskSize = s->look(i);
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
    std::cout << out << "\n\n";
}

#endif