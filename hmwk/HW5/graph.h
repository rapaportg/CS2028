#ifndef GRAPH_H
#define GRAPH_H
#include "vertex.h"
#include "stack.h"
#include "queue.h"
#include <iostream>

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
        int     *outEdge(int i);                            // returns an array of all the vertices that i connects to. Note the first item in the array is the number of items in the array..
        int     *inEdge(int i);                             // returns an array of all the vertices that connect to i. Note the first item in the arry is the number of items in the array
        void    print();
        bool    allVisited();

        // Task 3 NOT
        void    findPath(int beg, int end);                      // Uses Stacks
        void    FP_helper(Stack<Vertex> *path, int end);


        // Task 3
        void    depthFirstSearch();
        void    DF_helper(Stack<Vertex> *path);


        // Task 4
        void    breathFirstSearch();                      // Uses Queues

};

#endif