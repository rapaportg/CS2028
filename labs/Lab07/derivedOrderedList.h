#ifndef DERIVEDORDEREDLIST_H
#define DERIVEDORDEREDLIST_H
#define MAX_ITEMS 20
#include "orderedList.h"

template<class T>
class DerivedOrderedList :OrderedList<T>
{
public:
	class   NoListException {};
	class   OutOfBoundsException {};
	class   FullListException {};

	// DerivedOrderedList();
	void    addItem(T *item);
	void    removeItem(int index);
	void    printResults();
	void    printList();
	bool    isEmpty();
};
#endif

template<class T>
void DerivedOrderedList<T>::addItem(T *item)
{
	int pos = 1;
	if (this->array == nullptr)
	{
		throw NoListException();
	}

	if (this->array[MAX_ITEMS - 1] == nullptr)
	{
		this->array[MAX_ITEMS - 1] = item;
		return;
	}

	while (this->array[MAX_ITEMS - pos] != nullptr && pos <= MAX_ITEMS)
	{
		pos++;
		this->countAdd++;
	}
	this->countAdd++;
	if (this->array[0] != nullptr)
	{
		throw FullListException();
	}
	this->array[MAX_ITEMS - pos] = item;
 	this->countAdd++;
}

template<class T>
void DerivedOrderedList<T>::removeItem(int index)
{

	std::cout << "Index: " << index << '\t' << std::endl;
	printList();
	if (index >= MAX_ITEMS || index < 0)
	{
		//throw OutOfBoundsException();
		std::cout << "Out of Bounds\n\n";
		return;
	}
	else if (this->array == nullptr)
	{
		throw NoListException();
	}
	else if (this->array[index] != nullptr)
	{
		delete this->array[index];
		//this->array[index] = nullptr;
		this->countRemove++;
	}
	while (index > 0 && this->array[index - 1] != nullptr)
	{
		this->array[index] = this->array[index - 1];
		index--;
		this->countRemove++;
	}

	this->array[index] = nullptr;
	this->countRemove++;
	printList();
	std::cout << std::endl;
}

template<class T>
bool DerivedOrderedList<T>::isEmpty()
{
	return this->array[MAX_ITEMS - 1] == nullptr;
}

template<class T>
void DerivedOrderedList<T>::printResults()
{
	std::cout << "\nAdd to Back: \n";
	std::cout << "Operation Add Count: " << this->countAdd << std::endl;
	std::cout << "Operation Remove Count: " << this->countRemove << std::endl;
}

template<class T>
void DerivedOrderedList<T>::printList()
{
	int i = 19;
	if (this->array[i] == nullptr)
	{
		std::cout << "EMPTY LIST\n";
		return;
	}
	while (this->array[i] != nullptr && i >= 0)
	{
		std::cout << i << ": " << this->getItem(i) << " | ";
		i--;
	}

	std::cout << std::endl;
}
