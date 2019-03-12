#ifndef NODE_H
#define NODE_H

class Node
{
    private:
        int     value;

    public:
        Node    *next;
        Node(int c);
        int getValue();

};

#endif