#ifndef VERTEX_H
#define VERTEX_H
#include <string>

class Vertex
{
    private:
        int  value;
        int  size;
        int  count;
        int  *edges;

    public:
        Vertex();
        Vertex(int size);
        Vertex(int val, int size);
        void    addEdge(int val);
        void    removeEdge(int val);
        bool    hasEdge(int val);
        void    printVertex();
        void    setVal(int Val);
        int     getVal();
        int     *getOutEdges();
};

#endif