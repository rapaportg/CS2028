#ifndef GRAPH_H
#define GRAPH_H
#include "linkList.h"

using namespace std;

class Graph
{
    private:
        LinkList<Vertex>     *map;
        int                     vertices;

    public:
        Graph();
        Graph(int verts);
        void    addEdge(int i, int j);




};

#endif