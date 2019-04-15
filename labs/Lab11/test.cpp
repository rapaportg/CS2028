#include "sort.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int arr[100];

    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 100;
    }

    Sort<int> *tmp;
    tmp = new Sort<int>(arr, 100);

    cout << tmp->getLength() << endl;
    tmp->print();
    cout << endl;
    //tmp->bubbleSort();
    //tmp->insertionSort();
    //tmp->mergeSort();
    tmp->quickSort();
    tmp->print();
    return 0;
}
