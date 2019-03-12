#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        int value;
        Node *next = nullptr;

        Node(int c)
        {
            value = c;
        }
        int getValue()
        {
            return value;
        }

};

#endif