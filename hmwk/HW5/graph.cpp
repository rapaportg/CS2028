#include "graph.h"
#include "vertex.h"
#include "stack.h"
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
    map[i - 1]->addEdge(j);
    map[j - 1]->addEdge(i);

    return false;
}

bool    Graph::removeEdge(int i, int j)
{
    if (i <= 0 || j <= 0 || i > vertices || j > vertices)
    {
        cout << "Invalid input\n";
        return true;
    }
    map[i - 1]->removeEdge(j);
    map[j - 1]->removeEdge(i);
    return false;
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

void    Graph::DFS_helper(Stack<int> *path, int end)
{

}

int     *Graph::DFS(int beg, int end)
{
    Stack<int> *test = new Stack<int>(vertices);
    Vertex *tmp = map[beg - 1];

}