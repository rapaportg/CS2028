// A graph is a data structure where a set of nodes can have multiple childern and multiple parents

    //  Each node is called a vertex

    //  Each connection is between 2 nodes. this is called an edge. The egde connects exactly 2 nodes.
    //  the 2 nodes can be the same.

        //  The edge can be assigned a cost or wieght such as the 1st example.

        //  the edge can be directional.

        //  A graph is a collection of vertices and egdes such that:

            //  G = (V, E)
            //  V(G) = {A,B,C,D}
            //  E(G) = {(A,B),(A,C),(A,D),(B,C),(C,D),(D,E)}


        // Adjaceny - 2 nodes (A,B) are adjacent if they exist together in the egde set. if there is an edge between A and B, they are adjacent

        // Path = a series of vertices that connect 2 nodes

        // A complete graph - a graph in which every vertex is connected to every other vertex

        // Cycle- a series of nodes containing a path back to the starting node


//  How do we store this?

    // Options 1: 2D Matrix

        // a 2D array holding all the edges as values

        //      A   B   C   D   E
        //  A   0   1   1   1   0
        //  B   1   0   1   0   0
        //  C   1   1   0   1   0
        //  D   1   0   1   0   1
        //  E   0   0   0   1   0


        // a 1 means there is an egde,  a 0 means no egde.

        // If it is directed you have to use the whole thing.
        // if not you can use half the table


        // Advantage:
           // -   easy to modify connections(edges)
           // -   finding an edge is O(1)



        // Disadvantage:
           // -   Uses a lot of spaces, especially for spare graphs
           // -   hard to number of vertices


        // Performance:
            // - finding all ......




    //  Option 2: Adjacency List - a list of nodes and a list of edges for those nodes

        //  A  | -->B-->C-->D
        //  B  | -->A-->C
        //  C  | -->A-->B-->D
        //  D  | -->A-->C-->E
        //  E  | -->D

        //  the list of nodes can be any previous data structure but is usually an array or a link list.
        //  the list of edges is usually a link list.


        // ADVANTAGE:
           // -   easier to add new nodes
           // -   more memory efficient. O(N + M)   N = num of nodes, M = number of edges


        // DISADVANTAGE:
           // -   harder to determine if an edge exists between 2 nodes. O(E)





// Typical operation of a graph

    //  - AddEdge(i,j); where i is the from node and j is the to node.

    //  RemoveEdge(i,j);

    //  HasEdge(i,j);

    //  OutEdge(i); returns a list of vertices

    //  InEdges(i); returns a list of vertices

    //  AddNode(i);

    //  RemoveNode(i) - this will remove all egdes in and out as well


// Depth first search - will find a path between 2 vertices if it exists. This may not be the shortest path.

    // Basic Routine:
        // -mark a node as visted

        // -push all child nodes onto the stack if not already visited.

        // -Pop 1 node off stack and repeat for that node

        // -Stop when the stack is empty or you reached your destination








// Breadth first search - will find the shortest path (based on th enumber of steps, not weight)

    // Basic Routine:
/*
        - Mark a node visited

        - Stop if we are at the destination

        - Mark all childern as visited

        - Enqueue all childern

        - Dequeue 1st child and repeat





    // For a weigthed graph we need to use a priority queue. This needs to be all inclusive weights, not just the step weight

    Dijkstra's Algorithm


    // Performance

        -  O(V + E)
*/
