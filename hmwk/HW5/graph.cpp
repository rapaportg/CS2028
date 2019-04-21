#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int vert)
{
    vertices = vert;
    map = new Vertex *[vert];

    for (int i = 0; i < vert; i++)
    {
       map[i] = new Vertex(i + 1, vert);
    }
}

Graph::~Graph()
{
    delete [] map;
}

bool    Graph::addEdge(int i, int j)
{
    if (i == 0 || j == 0 || i > vertices || j > vertices)
    {
        cout << "Invalid input\n";
        return true;
    }
    for (int index = 0; index < vertices; index++)
    {
        if (map[index]->getVal() == i)
        {
            map[index]->addEdge(j);
            return false;
        }
    }
}

bool    Graph::removeEdge(int i, int j)
{
    if (i <= 0 || j <= 0 || i > vertices || j > vertices)
    {
        cout << "Invalid input\n";
        return true;
    }
    for (int index = 0; index < vertices; index++)
    {
        if (map[index]->getVal() == i)
        {
            map[index]->removeEdge(j);
            return false;
        }
    }
}

bool    Graph::hasEdge(int i, int j)
{
    for (int index = 0; index < vertices; index++)
    {
        if (map[index]->getVal() == i)
            return map[index]->hasEdge(j);
    }
    //cout << i << " Not in graph\n";
    return false;
}

int     *Graph::outEdge(int i)
{
    for (int index = 0; index < vertices; index++)
    {
        if (map[index]->getVal() == i)
        {
            return map[index]->getOutEdges();
        }
    }
}

int     *Graph::inEdge(int i)
{
    int *ret;
    int count = 0;

    for (int index = 0; index < vertices; index++)
    {
        if (map[index]->hasEdge(i))
            count++;
    }

    ret = new int[count + 1];
    ret[0] = count + 1;
    count = 1;
    for (int index = 0; index < vertices; index++)
    {
        if (map[index]->hasEdge(i))
            ret[count++] = map[index]->getVal();
    }
    return ret;
}

void    Graph::print()
{
    cout << endl;
    for (int i = 0; i < vertices; i++)
    {
        map[i]->printVertex();
    }
}