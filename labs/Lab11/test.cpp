#include "sort.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

int main()
{
    int size = 200;
    int arr[size];


    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size;
    }

    Sort<int> *tmp;
    tmp = new Sort<int>(arr, size);

    cout << tmp->getLength() << endl;
    tmp->print();
    cout << endl;
    //tmp->bubbleSort();
    //tmp->insertionSort();
    //tmp->mergeSort();
    //tmp->quickSort();
    tmp->countingSort();
    tmp->print();
    return 0;
}
