
//#include "pch.h"	//INCLUDE IF RUNNING IS VISUAL STUDIOS
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
	int                     *tmp2;
	int                     *tmp3;
	random_device           rd;

	mt19937 eng(rd());

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
			cout << "\tBack - Overflow: " << i << "\n"; // edited by kurt
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


	cout << "\n\nRemoves:\n";
	uniform_int_distribution<> distr(0, 25);
	cout << "\n\nOrderedList\n";
	while (!front->isEmpty())
	{

		try
		{
			front->removeItem(distr(eng));
		}
		catch (OrderedList<int>::NoListException err)
		{
			cout << "Remove Front: Out of Bounds" << endl;
		};
	}



	cout << "\n\nDerivedOrderedList\n";
	while (!back->isEmpty())
	{

		try
		{
			back->removeItem(distr(eng));
		}
		catch (DerivedOrderedList<int>::NoListException err)
		{
			cout << "Remove Back: No List" << endl;
		};
	}


	cout << "\n\nMiddleDerived\n";
	while (!middle->isEmpty())
	{
		try
		{
			middle->removeItem(distr(eng));
		}
		catch (MiddleDerived<int>::NoListException err)
		{
			cout << "Remove Middle: No List" << endl;
		};
	}

	front->printResults();
	back->printResults();
	middle->printResults();
}
