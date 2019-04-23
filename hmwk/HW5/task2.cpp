#include <iostream>
#include "graph.h"

using namespace std;

void    printArray(int *arr)
{
    cout << "\nEDGES: ";
    for (int i = 1; i < arr[0]; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void    printMenu()
{
    //cout << "\n\n\n\n\n";
    cout << "Press 1 to add an edge to graph.\n";
    cout << "Press 2 to remove an edge from graph\n";
    cout << "Press 3 Find an edge in the graph\n";
    cout << "Press 4 Find the out edges of a vertice\n";
    cout << "Press 5 Find the in edges of a vertice\n";
    cout << "Press 6 to find the DFS path\n";
    cout << "Press 7 to quit\n";

}

int     main()
{
    const int size = 15;
    Graph   *graph = new Graph(size);
    int     selection;
    int     i;
    int     j;
    bool    x;

    while(true)
    {
        x = true;
        printMenu();
        cin >> selection;

        if (selection == 1)
        {
            while (x)
            {
                cout << "Enter the edge you want to add 1-" << size << " (i j): ";
                cin >> i >> j;
                x = graph->addEdge(i,j);
            }
        }
        if (selection == 2)
        {
            while (x)
            {
                cout << "Enter the edge you want to remove 1-" << size << " (i j): ";
                cin >> i >> j;
                x = graph->removeEdge(i,j);
            }
        }
        if (selection == 3)
        {
            bool    check;

            x = true;

            while (x)
            {
                cout << "Enter the edge you want to find 1-" << size << " (i j): ";
                cin >> i >> j;
                x = false;
                if (i <= 0 || j <= 0 || i > size || j > size)
                {
                    cout << "Invalid input!\n";
                    x = true;
                }
            }

            check = graph->hasEdge(i,j);
            cout << endl;
            if (check == true)
            {
                cout << "\nThe Edge " << i << " to " << j << " E(" << i << ", " << j << ") exist in the graph.\n";
            }
            else
            {
                cout << "\nThe Edge " << i << " to " << j <<  " E(" << i << ", " << j << ") does not exist in the graph.\n";
            }
            cout << endl;
        }
        if (selection == 4)
        {
            int     i;

            while (x)
            {
                cout << "Enter the vertex you want to check: ";
                cin >> i;

                x = false;
                if (i <= 0 || i > size)
                {
                    x = true;
                }
            }
            printArray(graph->outEdge(i));
        }
        if (selection == 5)
        {
            int     i;

            while (x)
            {
                cout << "Enter the vertex you want to check: ";
                cin >> i;

                x = false;
                if (i <= 0 || i > size)
                {
                    x = true;
                }
            }
            printArray(graph->inEdge(i));
        }

        if (selection == 6)
        {
            cout << "Enter the endpoint you want to find the path for (beg to end) 1-" << size << " (i j): ";
            cin >> i >> j;
            graph->DFS(i,j);

        }

        if (selection == 7)
        {
            return 0;
        }

        graph->print();
        cout << endl;
    }
}