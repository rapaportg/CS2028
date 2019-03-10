#include <iostream>
#include <cstdlib>
#include <ctime>
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

    std::srand (unsigned(std::time(0)));

    for (int i = 0; i < 30; i++)
    {
        input = rand()%100 + 1;
        tmp = new int(input);
        cout << *tmp << endl;

        try
        {
            front->addItem(tmp);
        }
        catch(OrderedList<int>::FullListException err)
        {

        };
        //cout << "\nA";
        try
        {
            back->addItem(tmp);
        }
        catch(DerivedOrderedList<int>::FullListException err)
        {

        };
        //cout << "\nB";
        try
        {
            middle->addItem(tmp);
        }
        catch(MiddleDerived<int>::FullListException err)
        {

        };
        //cout << "\nC\n\n";
    }
    front->removeItem(0);

    int i = 19;
    /*
    while (!front->isEmpty())
    {
        try
        {
            front->removeItem(i);
        }
        catch(OrderedList<int>::FullListException err)
        {

        };
        i--;
    }
    */
    i = 0;

    cout << "What the fuck is wrong" << endl;
    while (!back->isEmpty())
    {
        try
        {
            cout << "Bitch" << endl;
            back->removeItem(i);
        }
        catch(DerivedOrderedList<int>::FullListException err)
        {

        };
        i++;
    }


    //front->printResults();
    back->printResults();
}