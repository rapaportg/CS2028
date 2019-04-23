#include "graph.h"

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
        std::cout << "Invalid input\n";
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
        std::cout << "Invalid input\n";
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
    return nullptr;
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
    std::cout << "\n" << std::endl;
    for (int i = 0; i < vertices; i++)
    {
        map[i]->printVertex();
    }
}

bool    Graph::allVisited()
{
    for (int i = 0; i < vertices; i++)
    {
        if (map[i]->getVisited() == false)
            return false;
    }
    return true;
}

void    Graph::FP_helper(Stack<Vertex> *path, int end)
{
    int     *edges = path->back().getOutEdges();

    for (int i = 1; i < edges[0]; i++)
    {
        if (!map[edges[i] - 1]->getVisited())
        {
            map[edges[i] - 1]->markVisited();
            path->push_back(*map[edges[i] - 1]);
            FP_helper(path, end);
        }
    }

    if (path->back().getVal() == end)
    {
        std::cout << "\n\nPATH: ";
        path->print();
    }

}

void    Graph::findPath(int beg, int end)
{
    for (int i = 0; i < vertices; i++)
    {
        map[i]->resetVisited();
    }
    Stack<Vertex> *path = new Stack<Vertex>();
    map[beg - 1]->markVisited();
    path->push_back(*map[beg - 1]);

    FP_helper(path, end);
    path->~Stack();
}


void   Graph::DF_helper(Stack<Vertex> *path)
{
    int     *edges = path->back().getOutEdges();

    for (int i = 1; i < edges[0]; i++)
    {
        if (!map[edges[i] - 1]->getVisited())
        {
            map[edges[i] - 1]->markVisited();
            cout << map[edges[i] - 1]->getVal() << "--> ";
            path->push_back(*map[edges[i] - 1]);
            DF_helper(path);
        }
    }
    delete [] edges;
    path->pop_back();
}


void   Graph::depthFirstSearch()
{
    Stack<Vertex> *path = new Stack<Vertex>();

    for (int i = 0; i < vertices; i++)
    {
        map[i]->resetVisited();
    }
    std::cout << map[0]->getVal() << "--> ";
    map[0]->markVisited();
    path->push_back(*map[0]);
    DF_helper(path);

}

void    Graph::breathFirstSearch()
{
    Queue<Vertex> *path = new Queue<Vertex>();
    int *edges;

    for (int i = 0; i < vertices; i++)
    {
        map[i]->resetVisited();
    }
    std::cout << map[0]->getVal() << "--> ";
    map[0]->markVisited();
    path->enqueue(*map[0]);

    edges = path->peekFront().getOutEdges();
    while (!allVisited())
    {
        int x = path->dequeue().getVal() - 1;
        edges = map[x]->getOutEdges();
        for (int i = 1; i < edges[0]; i++)
        {
            if (!map[edges[i] - 1]->getVisited())
            {
                std::cout << edges[i] << "--> ";
                map[edges[i] - 1]->markVisited();
                path->enqueue(*map[edges[i] - 1]);
            }
        }
    }
}