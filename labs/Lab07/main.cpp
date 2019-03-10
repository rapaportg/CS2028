#include <iostream>
#include <cstdlib>
#include <random>
#include "orderedList.h"
#include "derivedOrderedList.h"
#include "middleDerived.h"

using namespace std;

int main()
{
    OrderedList<int>        *front = new OrderedList<int>();
    DerivedOrderedList<int> *back = new DerivedOrderedList<int>();
    MiddleDerived<int>      *middle = new MiddleDerived<int>();
    int                     *tmp;
    int                     input;
    random_device           rd;

    mt19937 eng(rd());

    for (int i = 0; i < 30; i++)
    {

        uniform_int_distribution<> distr(1,99);
        tmp = new int(distr(eng));
        cout << *tmp << endl;

        try
        {
            front->addItem(tmp);
        }
        catch(OrderedList<int>::FullListException err)
        {

        };
        try
        {
           back->addItem(tmp);
        }
        catch(DerivedOrderedList<int>::FullListException err)
        {

        };
        try
        {
            middle->addItem(tmp);
        }
        catch(MiddleDerived<int>::FullListException err)
        {

        };

    }
    uniform_int_distribution<> distr(0,25);
    cout << "\n\nRemoves:\n";
    /*
    while (!front->isEmpty())
    {

        try
        {
            front->removeItem(distr(eng));
        }
        catch(OrderedList<int>::NoListException err)
        {
            cout << "Remove Front: Out of Bounds" << endl;
        };
    }
    */

    while (!back->isEmpty())
    {

        try
        {
            back->removeItem(distr(eng));
        }
        catch(DerivedOrderedList<int>::FullListException err)
        {
            cout << "Remove Back: Out of Bounds" << endl;
        };
    }

    front->printResults();
    back->printResults();
    middle->printResults();
}