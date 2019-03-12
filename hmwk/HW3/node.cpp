#include "node.h"

Node::Node(int c)
{
    value = c;
    next = nullptr;
}

int Node::getValue()
{
    return value;
}