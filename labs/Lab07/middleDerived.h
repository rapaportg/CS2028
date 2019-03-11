#ifndef MIDDLEDERIVED_H
#define MIDDLEDERIVED_H
#include "orderedList.h"

template<class T>
class MiddleDerived : OrderedList<T>
{
public:
	class   NoListException {};
	class   OutOfBoundException {};
	class   FullListException {};

	void    addItem(T *item);
	void    removeItem(int index);
	void    printResults();
	void    printList();
    void    makeEmpty();
    void    resetCount();
	bool    isEmpty();
};

#endif

template<class T>
void MiddleDerived<T>::addItem(T *item)
{
	int middle = MAX_ITEMS / 2;
	int pos = middle-1; // by 1st check we know array[middle] is full
	//printList();
	if (this->array[middle] == nullptr) // fills first spot
	{
		this->countAdd++;
		this->array[middle] = item;
		return;
	}
	else if (this->array[middle] != nullptr)
	{
		while (this->array[pos] != nullptr) // finds next open spot
		{
			if (pos<middle) // before we loop
			{
				pos--;
				this->countAdd++;
			}
			if (pos == -1)// circles to 19 pos
			{
				pos = MAX_ITEMS;
				this->countAdd++;
			}
			if (middle < pos )
			{
				pos--;
				this->countAdd++;
			}
			if (pos == middle) // we have checked every place in the aray and it is full
			{
				throw FullListException();
			}
		}
		while (pos != middle) // now we unravel
		{
			if (pos == MAX_ITEMS) // will circle to the front
			{
				pos = 0;
			}
			this->array[pos % MAX_ITEMS] = this->array[(pos + 1) % MAX_ITEMS];// shifts everything accordingly
			pos++;
			this->countAdd++;
			this->countAdd++;

		}
		this->array[middle] = item;
		this->countAdd++;
	}
}

template<class T>
void MiddleDerived<T>::removeItem(int index)
{
	std::cout << "\nIndex: " << index << endl;
	printList();
	if (index >= MAX_ITEMS)
	{
		std::cout << "Out of Bounds\n";
		return;
	}
	//T *tmp;

	//tmp = this->array[index];
	this->countRemove++;
	delete this->array[index];
    this->countRemove++;
    this->array[index] = nullptr;
    printList();
}

template<class T>
void MiddleDerived<T>::printResults()
{
	std::cout << "\nDerived Class 2" << std::endl;
	std::cout << "Operation Add Count: " << this->countAdd << std::endl;
	std::cout << "Operation Remove Count: " << this->countRemove << std::endl;
    std::cout << "Total Operation Preformed: " << this->countAdd + this->countRemove << std::endl;
}

template<class T>
bool MiddleDerived<T>::isEmpty()
{
	return this->array[MAX_ITEMS / 2] == nullptr;
}

template<class T>
void MiddleDerived<T>::printList()
{
	for (int j = 0; j < MAX_ITEMS; j++) {
		if (this->array[j] == nullptr)
            cout  << j << ": _ | ";
		else {
			cout << j << ": " << *this->array[j] << " | ";
		}
	}
	std::cout << std::endl;
}

template<class T>
void MiddleDerived<T>::makeEmpty()
{
    int pos = 0;
    while (pos < MAX_ITEMS)
    {
        delete this->array[pos];
        this->array[pos++] = nullptr;
        //this->countAdd = 0;
        //this->countRemove = 0;
    }
}

template<class T>
void MiddleDerived<T>::resetCount()
{
    this->countAdd = 0;
    this->countRemove = 0;
}