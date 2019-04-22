#ifndef GRAPH_H
#define GRAPH_H
#include "vertex.h"
#include "stack.h"

using namespace std;

class Graph
{
    private:
        Vertex  **map;      // Will use a hash table of Vertice next time
        int     vertices;

    public:
        //Graph();
        Graph(int verts);
        ~Graph();
        bool    addEdge(int i, int j);
        bool    removeEdge(int i, int j);
        bool    hasEdge(int i, int j);
        int     *outEdge(int i);    // returns an array of all the vertices that i connects to. Note the first item in the array is the number of items in the array..
        int     *inEdge(int i);     // returns an array of all the vertices that connect to i. Note the first item in the arry is the number of items in the array
        void    print();

        // Task 3
        int     *DFS(int beg, int end);
        void    DFS_helper(Stack<int> *path, int end);




};

#endif