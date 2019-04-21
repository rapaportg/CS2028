#include "vertex.h"
#include <iostream>

using namespace std;

Vertex::Vertex(int val, int s)
{
    value = val;
    size = s;
    edges = new int[size];
    count = 0;
}

Vertex::Vertex(int s)
{
    size = s;
    edges = new int[size];
    count = 0;
}

Vertex::Vertex(){}

void    Vertex::addEdge(int val)
{
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
    for (int i = 0; i < size; i++)
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

int     *Vertex::getOutEdges()
{
    int *ret = new int[count + 1];
    ret[0] = count + 1;
    int j = 1;
    for (int i = 0; i < count + 1; i++)
    {
        ret[j++] = edges[i];
    }
    return ret;
}