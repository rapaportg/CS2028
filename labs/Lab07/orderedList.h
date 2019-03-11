#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#define MAX_ITEMS 20
#include <iostream>

using namespace std;

template<class T>
class OrderedList
{
protected:
	T       **array = nullptr; // with be intialized as an array if pointers at runtime
	int     countAdd = 0;
	int     countRemove = 0;

public:

	class   NoListException {};
	class   OutOfBoundException {};
	class   FullListException {};

	OrderedList();

	virtual void    addItem(T *item);
	virtual void    removeItem(int index);
	virtual void    makeEmpty();
	void            printResults();
	void            printList();
	virtual bool    isEmpty();
	virtual bool    isFull();
	int             getItem(int i);
};

template<class T>
OrderedList<T>::OrderedList()
{
	array = new T*[MAX_ITEMS]();
}

template<class T>
void OrderedList<T>::addItem(T *item)
{
	int pos = 0;

	if (array == nullptr)
	{
		throw NoListException();
	}
	else
	{
		while (array[pos] != nullptr && pos < MAX_ITEMS)
		{
			pos++;
			countAdd++;
		}
		if (pos >= MAX_ITEMS)
		{
			countAdd++;
			throw FullListException();
		}
		else
		{
			array[pos] = item;
			countAdd++;
		}
	}
}

template<class T>
void OrderedList<T>::removeItem(int index)
{
	std::cout << "\nindex: " << index << std::endl;
	if (index < MAX_ITEMS - 1)
	{
		printList();
		delete array[index];
		countRemove++;

		while (array[index + 1] != nullptr && index < MAX_ITEMS - 1)
		{
			array[index] = array[index + 1];
			countRemove++;
			index++;
		}
		array[index] = nullptr;
		countRemove++;
		std::cout << "\n";
	}
	else
	{
		std::cout << "Out of Bounds\n";
	}
}

template<class T>
void OrderedList<T>::makeEmpty()
{
	int pos = 0;
	while (pos < MAX_ITEMS)
	{
		delete array[pos];
		countRemove++;
	}
}
template<class T>
void OrderedList<T>::printResults()
{
	std::cout << "Operation Add Count: " << countAdd << std::endl;
	std::cout << "Operation Remove Count: " << countRemove << std::endl;
}

template<class T>
bool OrderedList<T>::isEmpty()
{
	return array[0] == nullptr;
}

template<class T>
bool OrderedList<T>::isFull()
{
	return array[MAX_ITEMS - 1] != nullptr;
}

template<class T>
int OrderedList<T>::getItem(int i)
{
	return *array[i];
}

template<class T>
void OrderedList<T>::printList()
{
	int i = 0;
	if (array[i] == nullptr)
	{
		std::cout << "EMPTY LIST\n";
		return;
	}
	while (array[i] != nullptr && i < 20)
	{
		std::cout << i << ": " << *array[i] << " | ";
		i++;
	}
	std::cout << std::endl;
}
#endif
