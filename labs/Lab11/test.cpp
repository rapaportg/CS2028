#include "sort.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

int main()
{
    int size = 10;
    string  arrRadix[] = {"12304", "34204", "01203", "54203","64603", "00001", "66605",
                    "86704", "47605", "45607"};

    int     arr[size];

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size;
    }

    Sort<int> *tmp;
    tmp = new Sort<int>(arr, size);

    Sort<string> *tmpRadix;
    tmpRadix = new Sort<string>(arrRadix, 10);

    cout << tmp->getLength() << endl;
    tmp->print();
    cout << endl;
    //tmp->bubbleSort();
    //tmp->insertionSort();
    //tmp->mergeSort();
    //tmp->quickSort();
    tmp->countingSort();
    //tmpRadix->print();
    //tmpRadix->radixSort();
    //tmpRadix->print();
    tmp->print();
    return 0;
}
