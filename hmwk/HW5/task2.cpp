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
    cout << "Press 6 to quit\n";

}

int     main()
{
    const int size = 10;
    Graph   *graph = new Graph(size);
    int     selection;
    int     i;
    int     j;

    while(true)
    {
        printMenu();
        cin >> selection;

        if (selection == 1)
        {
            bool x = true;
            while (x)
            {
                cout << "Enter the edge you want to add 1-" << size << " (i j): ";
                cin >> i >> j;
                x = graph->addEdge(i,j);
            }
        }
        if (selection == 2)
        {
            bool x = true;
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
            bool    valid = true;

            while (valid)
            {
                cout << "Enter the edge you want to find 1-" << size << " (i j): ";
                cin >> i >> j;
                valid = false;
                if (i <= 0 || j <= 0 || i > size || j > size)
                {
                    cout << "Invalid input!\n";
                    valid = true;
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
            bool    valid = true;
            int     i;

            while (valid)
            {
                cout << "Enter the vertex you want to check: ";
                cin >> i;

                valid = false;
                if (i <= 0 || i > size)
                {
                    valid = true;
                }
            }
            printArray(graph->outEdge(i));
        }
        if (selection == 5)
        {
            bool    valid = true;
            int     i;

            while (valid)
            {
                cout << "Enter the vertex you want to check: ";
                cin >> i;

                valid = false;
                if (i <= 0 || i > size)
                {
                    valid = true;
                }
            }
            printArray(graph->inEdge(i));
        }
        if (selection == 6)
        {
            return 0;
        }

        graph->print();
        cout << endl;
    }
}