#include "vertex.h"

Vertex::Vertex(int val)
{
    value = val;
    edges = new LinkList<int>();
}

void    Vertex::addEdge(int val)
{
    edges->addItem(&val);
}

void    Vertex::removeEdge(int val)
{
    edges->removeItem(&val);
}