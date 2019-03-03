#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        int card;
        Node *next = nullptr;

        Node(int c)
        {
            card = c;
        }
        int getCard()
        {
            return card;
        }
};

#endif