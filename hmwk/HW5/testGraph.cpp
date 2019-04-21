#include "graph.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

#define max 10

using namespace std;

void    printArray(int *arr)
{
    for (int i = 1; i < arr[0]; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int     main()
{
    Graph *test = new Graph(max);

    test->addEdge(0,7);
    test->addEdge(6,7);
    test->addEdge(7,6);
    test->addEdge(5,1);
    test->addEdge(7,5);
    test->addEdge(7,1);
    //test->addEdge(7,9);
    test->addEdge(7,9);
    test->removeEdge(7,6);

    test->print();

    printArray(test->outEdge(7));
    printArray(test->inEdge(7));
    cout << test->hasEdge(0,7) << endl;
    cout << test->hasEdge(1,7) << endl;
}