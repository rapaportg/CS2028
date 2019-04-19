#ifndef VERTEX_H
#define VERTEX_H
#include "linkList.h"

class Vertex
{
    private:
        int             value;
        //int               weight;
        LinkList<int>   *edges;

    public:
        Vertex(int val);
        void    addEdge(int val);
        void    removeEdge(int val);
        bool    hasEdge(int val);

};

#endif