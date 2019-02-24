#include <string>
#include <iostream>
// using array

//template<class T>

class Stack
{
    private:
        int head = 0;
        const int maxSize;
        char *items; 
    
    public:

        Stack(int size)
        {
            maxSize = size;
            items = new char[size];
        }

        void push(char data)
        {
            if (isFull())
                throw StackOverFlow; // needs to be defined
    
            items[head] = data;
            head++;
        }

        char pop()
        {
            if (isEmpty())
                throw StackUnderFlow; // needs to be defines

            head--;
            return items[head];
        }

        bool isFull()
        {
            return (head == maxSize);
        }

        bool isEmpty()
        {
            return (head == 0);
        }

        char peek()
        {
            if (isEmpty)
                throw StackUnderFlow; // needs to be defined
            return item[head - 1];
        }

        int length()
        {
            return head;
        }

        void makeEmpty()
        {
            head = 0;
        }

        int getCapacity()
        {
            return maxSize;
        }



        


};