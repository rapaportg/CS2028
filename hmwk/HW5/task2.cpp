#include <iostream>
#include <random>
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
    cout << "Press 6 to auto fill with size * 2 elements\n";
    cout << "Press 7 to find the DFS path\n";
    cout << "Press 8 to find the BFS path\n";
    cout << "Press 9 to quit\n";

}

int     main(int ac, char **argv)
{
    int     size = atoi(argv[1]);
    Graph   *graph;
    int     selection;
    int     i;
    int     j;
    bool    x;

/*
    if (ac == 1)
        size = atoi(argv[1]);
    else
        size = 10;
*/

    graph = new Graph(size);


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
            //graph->print();
        }
        if (selection == 2)
        {
            while (x)
            {
                cout << "Enter the edge you want to remove 1-" << size << " (i j): ";
                cin >> i >> j;
                x = graph->removeEdge(i,j);
            }
            //graph->print();
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
            int *tmp = graph->inEdge(i);
            printArray(tmp);
            delete tmp;
        }

        if (selection == 6)
        {
            random_device rd;
            int x = size * 2;

            mt19937 gen(rd());
            uniform_int_distribution<> dis(1,size);
            while(x--)
            {
                i = dis(gen);
                j = dis(gen);
                graph->addEdge(i,j);
            }
            //graph->print();

        }

        if (selection == 7)
        {
            graph->depthFirstSearch();
        }

        if (selection == 8)
        {
            graph->breathFirstSearch();
        }

        if (selection == 9)
        {
            return 0;
        }

        if (selection == 10)
        {
            graph->print();
        }


        cout << endl;
    }
}