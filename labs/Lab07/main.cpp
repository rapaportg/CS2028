
//#include "pch.h"	//INCLUDE IF RUNNING IS VISUAL STUDIOS
#include <iostream>
#include <cstdlib>
#include <random>
#include "orderedList.h"
#include "derivedOrderedList.h"
#include "middleDerived.h"

using namespace std;

void Task4_part1(OrderedList<int> *front, DerivedOrderedList<int> *back, MiddleDerived<int> *middle)
{
    int             add = 1;
    int             removed = 1;
    int             holder;
    int             *tmp;
    random_device   rd;

	mt19937 eng(rd());
    uniform_int_distribution<> distr(0, MAX_ITEMS);

    front->makeEmpty();
    back->makeEmpty();
    middle->makeEmpty();
    while (add + removed <= 55)
    {
        holder = distr(eng);
        if (holder % 2 == 0 && add <= 30)
        {
            cout << add <<": ADD" << endl;
            add++;
            tmp = new int(distr(eng));
            try
            {
                front->addItem(tmp);
            }
            catch (OrderedList<int>::FullListException)
            {
                cout << "Full Stack\n";
            }
        }
        else if (holder % 2 != 0 && removed <= 25)
        {
            cout << removed <<": REMOVE" << endl;
            removed++;
            front->removeItem(distr(eng));
        }
    }

    add = 0;
    removed = 0;
    while (add + removed <= 55)
    {
        holder = distr(eng);
        if (holder % 2 == 0 && add <= 30)
        {
            cout << add <<": ADD" << endl;
            add++;
            tmp = new int(distr(eng));
            try
            {
                back->addItem(tmp);
            }
            catch (DerivedOrderedList<int>::FullListException)
            {
                cout << "Full Stack\n";
            }
        }
        else if (holder % 2 != 0 && removed <= 25)
        {
            cout << removed <<": REMOVE" << endl;
            removed++;
            back->removeItem(distr(eng));
        }
    }

    add = 0;
    removed = 0;
    while (add + removed <= 55)
    {
        holder = distr(eng);
        if (holder % 2 == 0 && add <= 30)
        {
            cout << add <<": ADD" << endl;
            add++;
            tmp = new int(distr(eng));
            try
            {
                middle->addItem(tmp);
            }
            catch (MiddleDerived<int>::FullListException)
            {
                cout << "Full Stack\n";
            }
        }
        else if (holder % 2 != 0 && removed <= 25)
        {
            cout << removed <<": REMOVE" << endl;
            removed++;
            middle->removeItem(distr(eng));
        }
    }
}

int main()
{
    // part A
	OrderedList<int>        *front = new OrderedList<int>();
	DerivedOrderedList<int> *back = new DerivedOrderedList<int>();
	MiddleDerived<int>      *middle = new MiddleDerived<int>();
	int                     *tmp;
	int                     *tmp2;
	int                     *tmp3;
    int                     i;
	random_device           rd;

	mt19937 eng(rd());

//  #########################################
//   part B
//  #########################################
	for (int i = 0; i < 30; i++)
	{

		uniform_int_distribution<> distr(1, 99);
		tmp = new int(distr(eng));
		tmp2 = new int(distr(eng));
		tmp3 = new int(distr(eng));

		try
		{
			front->addItem(tmp);
		}
		catch (OrderedList<int>::FullListException err)
		{
			cout << "Front - Overflow: " << i; // edited by kurt
		};
		try
		{
			back->addItem(tmp2);
		}
		catch (DerivedOrderedList<int>::FullListException err)
		{
			cout << "\tBack - Overflow: " << i; // edited by kurt
		};
		try
		{
			middle->addItem(tmp3);
		}
		catch (MiddleDerived<int>::FullListException err)
		{
			cout << "\tMiddle - Overflow: " << i << "\n"; // edited by kurt
		};

	}

//  ########################################
//  Part C
//  ########################################

	cout << "\n\nRemoves:\n";
	uniform_int_distribution<> distr(0, MAX_ITEMS);
	cout << "\n\nOrderedList\n";
    i = 0;
	while (!front->isEmpty() && i < 25)
	{

		try
		{
			front->removeItem(distr(eng));
		}
		catch (OrderedList<int>::NoListException err)
		{
			cout << "Remove Front: Out of Bounds" << endl;
		};
        i++;
	}

	cout << "\n\nDerivedOrderedList\n";
    i = 0;
	while (!back->isEmpty() && i < 25)
	{

		try
		{
			back->removeItem(distr(eng));
		}
		catch (DerivedOrderedList<int>::NoListException err)
		{
			cout << "Remove Back: No List" << endl;
		};
        i++;
	}


	cout << "\n\nMiddleDerived\n";
    i = 0;
	while (!middle->isEmpty() && i < 25)
	{
		try
		{
			middle->removeItem(distr(eng));
		}
		catch (MiddleDerived<int>::NoListException err)
		{
			cout << "Remove Middle: No List" << endl;
		};
        i++;
	}

    front->printResults();
	back->printResults();
	middle->printResults();
//  ##############################################
//  Part D
//  ##############################################

    Task4_part1(front, back, middle);
    front->printResults();
	back->printResults();
	middle->printResults();

//  ################################################
//  Part 2
//  ################################################

    front->resetCount();
    back->resetCount();
    middle->resetCount();

    for (int i = 0; i < 100; i++)
    {
        Task4_part1(front, back, middle);
    }

    cout << "\nCounts after 100 Runs: (Array size 20)\n";
    front->printResults();
	back->printResults();
	middle->printResults();
}
