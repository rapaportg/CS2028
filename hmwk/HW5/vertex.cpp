#include "vertex.h"
#include <iostream>

using namespace std;

Vertex::Vertex(int val, int s)
{
    value = val;
    size = s;
    edges = new int[size];
    count = 0;
    visited = false;
}

Vertex::Vertex(int s)
{
    size = s;
    edges = new int[size];
    count = 0;
    visited = false;
}

Vertex::Vertex(){}

void    Vertex::addEdge(int val)
{
    if (val >= size)
    {
        cout << "ERROR invalid input\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (edges[i] == val)
        {
            cout << "\nERROR! E(" << value << ", " << val << ") already exist\n";
            return;
        }
        if (edges[i] == '\0')
        {
            count++;
            edges[i] = val;
            return;
        }
    }
    //cout << "List full\n";
}

void    Vertex::removeEdge(int val)
{
    for (int i = 0; i < size; i++)       // Will Refactor this shifting the array everytime is ineffiecent
    {
        if (edges[i] == val)
        {
            count--;
            while(i < size)
            {
                edges[i] = edges[i + 1];
                i++;
            }
            return;
        }
    }
    cout << "\nERROR! E(" << value << ", " << val << ") does not exist\n";
}

bool    Vertex::hasEdge(int j)
{
    for (int i = 0; i < size; i++)
    {
        if (edges[i] == j)
        {
            return true;
        }
    }
    return false;
}

void    Vertex::printVertex()
{
    cout << value << ": ";
    for(int i = 0; i < size; i++)
    {
        if (edges[i] == '\0')
            break;
        else
        {
            cout << "--> ";
        }

        cout << edges[i];
    }
    cout << endl;
}

void    Vertex::setVal(int val)
{
    value = val;
}

int     Vertex::getVal()
{
    return value;
}

int     *Vertex::getOutEdges()          // Will Refactor to return a points to the edges array or to replace edges array with a link list
{
    int *ret = new int[count + 1];      // The extra index it to store the size of the array in ret[0] so i will know how large the array is when i process it
    ret[0] = count + 1;                 // could throw a NULL on the end to do the same thing
    int j = 1;
    for (int i = 0; i < count; i++)
    {
        ret[j] = edges[i];
        j++;
    }
    return ret;
}

int     Vertex::length()
{
    return count;
}

void    Vertex::markVisited()
{
    visited = true;
}

void    Vertex::resetVisited()
{
    visited = false;
}

bool    Vertex::getVisited()
{
    return visited;
}